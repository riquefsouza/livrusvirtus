#include "resource.h"
#include "Consultas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConEditoras.h"

BEGIN_EVENT_TABLE(CfrmConEditoras, CfrmConsultas)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, CfrmConEditoras::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, CfrmConEditoras::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, CfrmConEditoras::OnBtnFechar)
  EVT_CLOSE(CfrmConEditoras::OnClose)
  EVT_GRID_SELECT_CELL(CfrmConEditoras::OnGridSelectCell)
  EVT_GRID_LABEL_LEFT_CLICK(CfrmConEditoras::OnGridLabelLeftClick)
END_EVENT_TABLE()

CfrmConEditoras::CfrmConEditoras(wxWindow *parent)
       : CfrmConsultas(parent) {
	IniciaControles();
}

CfrmConEditoras::~CfrmConEditoras() { }

void CfrmConEditoras::IniciaControles() {
 this->SetTitle(STR_CONEDITORA);
 this->labDescricao->SetLabel(wxT("Editora:  "));
 this->gridConsulta->SetColLabelValue(1, wxT("Editora"));
}

void CfrmConEditoras::OnClose(wxCloseEvent& event) {
  Fecha(MNU_CON_EDITORAS);
  event.Skip();
}

void CfrmConEditoras::OnBtnFechar(wxCommandEvent& event) {  
  Fecha(0);
  event.Skip();
}

void CfrmConEditoras::OnBtnLimpar(wxCommandEvent& event) {
  LimparDados();
  event.Skip();
}

void CfrmConEditoras::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Editora('S',wxT(""), edtDescricao->GetValue()), STR_EDTNENC, 2);
  event.Skip();
}

void CfrmConEditoras::OnGridSelectCell(wxGridEvent& event) {
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConEditoras::OnGridLabelLeftClick(wxGridEvent& event){
  setLabRegistros(event.GetRow());
  event.Skip();
}

