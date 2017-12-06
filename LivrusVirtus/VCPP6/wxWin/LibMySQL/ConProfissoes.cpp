#include "resource.h"
#include "Consultas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConProfissoes.h"

BEGIN_EVENT_TABLE(CfrmConProfissoes, CfrmConsultas)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, CfrmConProfissoes::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, CfrmConProfissoes::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, CfrmConProfissoes::OnBtnFechar)
  EVT_CLOSE(CfrmConProfissoes::OnClose)
  EVT_GRID_SELECT_CELL(CfrmConProfissoes::OnGridSelectCell)
  EVT_GRID_LABEL_LEFT_CLICK(CfrmConProfissoes::OnGridLabelLeftClick)
END_EVENT_TABLE()

CfrmConProfissoes::CfrmConProfissoes(wxWindow *parent)
       : CfrmConsultas(parent) {
	IniciaControles();
}

CfrmConProfissoes::~CfrmConProfissoes() { }

void CfrmConProfissoes::IniciaControles() {
 this->SetTitle(STR_CONPROFISS);
 this->labDescricao->SetLabel(wxT("Profissão:  "));
 this->gridConsulta->SetColLabelValue(1, wxT("Profissão"));
}

void CfrmConProfissoes::OnClose(wxCloseEvent& event) {
  Fecha(MNU_CON_PROFISSOES);
  event.Skip();
}

void CfrmConProfissoes::OnBtnFechar(wxCommandEvent& event) {  
  Fecha(0);
  event.Skip();
}

void CfrmConProfissoes::OnBtnLimpar(wxCommandEvent& event) {
  LimparDados();
  event.Skip();
}

void CfrmConProfissoes::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Profissao('S',wxT(""), edtDescricao->GetValue()), STR_PROFNENC, 2);
  event.Skip();
}

void CfrmConProfissoes::OnGridSelectCell(wxGridEvent& event) {
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConProfissoes::OnGridLabelLeftClick(wxGridEvent& event){
  setLabRegistros(event.GetRow());
  event.Skip();
}

