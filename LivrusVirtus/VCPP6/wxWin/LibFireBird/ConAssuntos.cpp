#include "resource.h"
#include "Consultas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConAssuntos.h"

BEGIN_EVENT_TABLE(CfrmConAssuntos, CfrmConsultas)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, CfrmConAssuntos::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, CfrmConAssuntos::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, CfrmConAssuntos::OnBtnFechar)
  EVT_CLOSE(CfrmConAssuntos::OnClose)
  EVT_GRID_SELECT_CELL(CfrmConAssuntos::OnGridSelectCell)
  EVT_GRID_LABEL_LEFT_CLICK(CfrmConAssuntos::OnGridLabelLeftClick)
END_EVENT_TABLE()

CfrmConAssuntos::CfrmConAssuntos(wxWindow *parent)
       : CfrmConsultas(parent) {
	IniciaControles();
}

CfrmConAssuntos::~CfrmConAssuntos() { }

void CfrmConAssuntos::IniciaControles() {
 this->SetTitle(STR_CONASSUNTO);
 this->labDescricao->SetLabel(wxT("Assunto:  "));
 this->gridConsulta->SetColLabelValue(1, wxT("Assunto"));
}

void CfrmConAssuntos::OnClose(wxCloseEvent& event) {
  Fecha(MNU_CON_ASSUNTOS);
  event.Skip();
}

void CfrmConAssuntos::OnBtnFechar(wxCommandEvent& event) {  
  Fecha(0);
  event.Skip();
}

void CfrmConAssuntos::OnBtnLimpar(wxCommandEvent& event) {
  LimparDados();
  event.Skip();
}

void CfrmConAssuntos::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Assunto('S',wxT(""), edtDescricao->GetValue()), STR_ASSNENC, 2);
  event.Skip();
}

void CfrmConAssuntos::OnGridSelectCell(wxGridEvent& event) {
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConAssuntos::OnGridLabelLeftClick(wxGridEvent& event){
  setLabRegistros(event.GetRow());
  event.Skip();
}

