#include "resource.h"
#include "Consultas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConPaises.h"

BEGIN_EVENT_TABLE(CfrmConPaises, CfrmConsultas)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, CfrmConPaises::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, CfrmConPaises::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, CfrmConPaises::OnBtnFechar)
  EVT_CLOSE(CfrmConPaises::OnClose)
  EVT_GRID_SELECT_CELL(CfrmConPaises::OnGridSelectCell)
  EVT_GRID_LABEL_LEFT_CLICK(CfrmConPaises::OnGridLabelLeftClick)
END_EVENT_TABLE()

CfrmConPaises::CfrmConPaises(wxWindow *parent)
       : CfrmConsultas(parent) {
	IniciaControles();
}

CfrmConPaises::~CfrmConPaises() { }

void CfrmConPaises::IniciaControles() {
 this->SetTitle(STR_CONPAIS);
 this->labDescricao->SetLabel(wxT("País:  "));
 this->gridConsulta->SetColLabelValue(1, wxT("País"));
}

void CfrmConPaises::OnClose(wxCloseEvent& event) {
  Fecha(MNU_CON_PAISES);
  event.Skip();
}

void CfrmConPaises::OnBtnFechar(wxCommandEvent& event) {  
  Fecha(0);
  event.Skip();
}

void CfrmConPaises::OnBtnLimpar(wxCommandEvent& event) {
  LimparDados();
  event.Skip();
}

void CfrmConPaises::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Pais('S',wxT(""), edtDescricao->GetValue()), STR_PAISNENC, 2);
  event.Skip();
}

void CfrmConPaises::OnGridSelectCell(wxGridEvent& event) {
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConPaises::OnGridLabelLeftClick(wxGridEvent& event){
  setLabRegistros(event.GetRow());
  event.Skip();
}

