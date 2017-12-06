#include "resource.h"
#include "Cadastros.h"
#include "CadProfissoes.h"
#include "Principal.h"
#include "ConsultasSQL.h"

BEGIN_EVENT_TABLE(CfrmCadProfissoes, CfrmCadastros)
  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, CfrmCadProfissoes::OnBtnNovo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, CfrmCadProfissoes::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, CfrmCadProfissoes::OnBtnAnterior)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, CfrmCadProfissoes::OnBtnProximo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, CfrmCadProfissoes::OnBtnSalvar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, CfrmCadProfissoes::OnBtnExcluir)
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, CfrmCadProfissoes::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, CfrmCadProfissoes::OnBtnFechar)
  EVT_CLOSE(CfrmCadProfissoes::OnClose)
END_EVENT_TABLE()

CfrmCadProfissoes::CfrmCadProfissoes(wxWindow *parent)
       : CfrmCadastros(parent, wxFILTER_NUMERIC, true) {
  CfrmCadProfissoes::IniciaControles();
}

void CfrmCadProfissoes::IniciaControles() {
 this->labDescricao->SetLabel(wxT("Profissao: "));
}

CfrmCadProfissoes::~CfrmCadProfissoes() { }

bool CfrmCadProfissoes::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->GetValue(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->GetValue(), STR_PROFNINF))
  		return false;
  	}
  	return true;
}

void CfrmCadProfissoes::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmCadProfissoes::OnBtnNovo(wxCommandEvent& event) {
  btnNovoClick();
  NovoDado(ConsSQL->Profissao('N', edtCodigo->GetValue(),""));	
  event.Skip();
}

void CfrmCadProfissoes::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Profissao('S', edtCodigo->GetValue(),""), STR_PROFNENC);
  event.Skip();
}

void CfrmCadProfissoes::OnBtnAnterior(wxCommandEvent& event) {
  registroAnterior();	
  event.Skip();
}

void CfrmCadProfissoes::OnBtnProximo(wxCommandEvent& event) {
  registroProximo();		
  event.Skip();
}

void CfrmCadProfissoes::OnBtnSalvar(wxCommandEvent& event) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Profissao('S', edtCodigo->GetValue(),""),
    ConsSQL->Profissao('U', edtCodigo->GetValue(), edtDescricao->GetValue()),
    ConsSQL->Profissao('I', edtCodigo->GetValue(), edtDescricao->GetValue()), 
    true);
  event.Skip();
}

void CfrmCadProfissoes::OnBtnExcluir(wxCommandEvent& event) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Profissao('D', edtCodigo->GetValue(),""));
  event.Skip();
}

void CfrmCadProfissoes::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmCadProfissoes::OnBtnLimpar(wxCommandEvent& event) {
  btnLimparClick();
  event.Skip();
}

