#include "resource.h"
#include "Cadastros.h"
#include "CadAutores.h"
#include "Principal.h"
#include "ConsultasSQL.h"

BEGIN_EVENT_TABLE(CfrmCadAutores, CfrmCadastros)
  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, CfrmCadAutores::OnBtnNovo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, CfrmCadAutores::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, CfrmCadAutores::OnBtnAnterior)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, CfrmCadAutores::OnBtnProximo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, CfrmCadAutores::OnBtnSalvar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, CfrmCadAutores::OnBtnExcluir)
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, CfrmCadAutores::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, CfrmCadAutores::OnBtnFechar)
  EVT_CLOSE(CfrmCadAutores::OnClose)
END_EVENT_TABLE()

CfrmCadAutores::CfrmCadAutores(wxWindow *parent)
       : CfrmCadastros(parent, wxFILTER_NUMERIC, true) {
  CfrmCadAutores::IniciaControles();
}

void CfrmCadAutores::IniciaControles() {
 this->labDescricao->SetLabel(wxT("Autor: "));
}

CfrmCadAutores::~CfrmCadAutores() { }

bool CfrmCadAutores::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->GetValue(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->GetValue(), STR_AUTNINF))
  		return false;
  	}
  	return true;
}

void CfrmCadAutores::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmCadAutores::OnBtnNovo(wxCommandEvent& event) {
  btnNovoClick();
  NovoDado(ConsSQL->Autor('N', edtCodigo->GetValue(),""));	
  event.Skip();
}

void CfrmCadAutores::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Autor('S', edtCodigo->GetValue(),""), STR_AUTNENC, 2);
  event.Skip();
}

void CfrmCadAutores::OnBtnAnterior(wxCommandEvent& event) {
  registroAnterior();	
  event.Skip();
}

void CfrmCadAutores::OnBtnProximo(wxCommandEvent& event) {
  registroProximo();		
  event.Skip();
}

void CfrmCadAutores::OnBtnSalvar(wxCommandEvent& event) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Autor('S', edtCodigo->GetValue(),""),
    ConsSQL->Autor('U', edtCodigo->GetValue(), edtDescricao->GetValue()),
    ConsSQL->Autor('I', edtCodigo->GetValue(), edtDescricao->GetValue()), 
    true);
  event.Skip();
}

void CfrmCadAutores::OnBtnExcluir(wxCommandEvent& event) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Autor('D', edtCodigo->GetValue(),""));
  event.Skip();
}

void CfrmCadAutores::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmCadAutores::OnBtnLimpar(wxCommandEvent& event) {
  btnLimparClick();
  event.Skip();
}

