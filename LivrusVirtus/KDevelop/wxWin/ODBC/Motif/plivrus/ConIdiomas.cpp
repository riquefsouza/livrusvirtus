#include "resource.h"
#include "Consultas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConIdiomas.h"

BEGIN_EVENT_TABLE(CfrmConIdiomas, CfrmConsultas)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, CfrmConIdiomas::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, CfrmConIdiomas::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, CfrmConIdiomas::OnBtnFechar)
  EVT_CLOSE(CfrmConIdiomas::OnClose)
  EVT_GRID_SELECT_CELL(CfrmConIdiomas::OnGridSelectCell)
  EVT_GRID_LABEL_LEFT_CLICK(CfrmConIdiomas::OnGridLabelLeftClick)
END_EVENT_TABLE()

CfrmConIdiomas::CfrmConIdiomas(wxWindow *parent)
       : CfrmConsultas(parent) {
	IniciaControles();
}

CfrmConIdiomas::~CfrmConIdiomas() { }

void CfrmConIdiomas::IniciaControles() {
 this->SetTitle(STR_CONIDIOMA);
 this->labDescricao->SetLabel(wxT("Idioma:  "));
 this->gridConsulta->SetColLabelValue(1, wxT("Idioma"));
}

void CfrmConIdiomas::OnClose(wxCloseEvent& event) {
  Fecha(MNU_CON_IDIOMAS);
  event.Skip();
}

void CfrmConIdiomas::OnBtnFechar(wxCommandEvent& event) {  
  Fecha(0);
  event.Skip();
}

void CfrmConIdiomas::OnBtnLimpar(wxCommandEvent& event) {
  LimparDados();
  event.Skip();
}

void CfrmConIdiomas::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Idioma('S',wxT(""), edtDescricao->GetValue()), STR_IDINENC, 2);
  event.Skip();
}

void CfrmConIdiomas::OnGridSelectCell(wxGridEvent& event) {
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConIdiomas::OnGridLabelLeftClick(wxGridEvent& event){
  setLabRegistros(event.GetRow());
  event.Skip();
}

