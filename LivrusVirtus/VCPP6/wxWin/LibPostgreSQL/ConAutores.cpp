#include "resource.h"
#include "Consultas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConAutores.h"

BEGIN_EVENT_TABLE(CfrmConAutores, CfrmConsultas)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, CfrmConAutores::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, CfrmConAutores::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, CfrmConAutores::OnBtnFechar)
  EVT_CLOSE(CfrmConAutores::OnClose)
  EVT_GRID_SELECT_CELL(CfrmConAutores::OnGridSelectCell)
  EVT_GRID_LABEL_LEFT_CLICK(CfrmConAutores::OnGridLabelLeftClick)
END_EVENT_TABLE()

CfrmConAutores::CfrmConAutores(wxWindow *parent)
       : CfrmConsultas(parent) {
	IniciaControles();
}

CfrmConAutores::~CfrmConAutores() { }

void CfrmConAutores::IniciaControles() {
 this->SetTitle(STR_CONAUTOR);
 this->labDescricao->SetLabel(wxT("Autor:  "));
 this->gridConsulta->SetColLabelValue(1, wxT("Autor"));
}

void CfrmConAutores::OnClose(wxCloseEvent& event) {
  Fecha(MNU_CON_AUTORES);
  event.Skip();
}

void CfrmConAutores::OnBtnFechar(wxCommandEvent& event) {  
  Fecha(0);
  event.Skip();
}

void CfrmConAutores::OnBtnLimpar(wxCommandEvent& event) {
  LimparDados();
  event.Skip();
}

void CfrmConAutores::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Autor('S',wxT(""), edtDescricao->GetValue()), STR_AUTNENC, 2);
  event.Skip();
}

void CfrmConAutores::OnGridSelectCell(wxGridEvent& event) {
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConAutores::OnGridLabelLeftClick(wxGridEvent& event){
  setLabRegistros(event.GetRow());
  event.Skip();
}

