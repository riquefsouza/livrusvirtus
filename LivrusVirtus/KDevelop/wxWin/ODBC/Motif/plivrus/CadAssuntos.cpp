#include "resource.h"
#include "Cadastros.h"
#include "CadAssuntos.h"
#include "Principal.h"
#include "ConsultasSQL.h"

BEGIN_EVENT_TABLE(CfrmCadAssuntos, CfrmCadastros)
  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, CfrmCadAssuntos::OnBtnNovo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, CfrmCadAssuntos::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, CfrmCadAssuntos::OnBtnAnterior)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, CfrmCadAssuntos::OnBtnProximo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, CfrmCadAssuntos::OnBtnSalvar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, CfrmCadAssuntos::OnBtnExcluir)
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, CfrmCadAssuntos::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, CfrmCadAssuntos::OnBtnFechar)
  EVT_CLOSE(CfrmCadAssuntos::OnClose)
END_EVENT_TABLE()

CfrmCadAssuntos::CfrmCadAssuntos(wxWindow *parent)
       : CfrmCadastros(parent, wxFILTER_NUMERIC, true) {
  CfrmCadAssuntos::IniciaControles();
}

void CfrmCadAssuntos::IniciaControles() {
 this->labDescricao->SetLabel(wxT("Assunto: "));
}

CfrmCadAssuntos::~CfrmCadAssuntos() { }

bool CfrmCadAssuntos::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->GetValue(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->GetValue(), STR_ASSNINF))
  		return false;
  	}
  	return true;
}

void CfrmCadAssuntos::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmCadAssuntos::OnBtnNovo(wxCommandEvent& event) {
  btnNovoClick();
  NovoDado(ConsSQL->Assunto('N', edtCodigo->GetValue(),""));	
  event.Skip();
}

void CfrmCadAssuntos::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Assunto('S', edtCodigo->GetValue(),""), STR_ASSNENC);
  event.Skip();
}

void CfrmCadAssuntos::OnBtnAnterior(wxCommandEvent& event) {
  registroAnterior();	
  event.Skip();
}

void CfrmCadAssuntos::OnBtnProximo(wxCommandEvent& event) {
  registroProximo();		
  event.Skip();
}

void CfrmCadAssuntos::OnBtnSalvar(wxCommandEvent& event) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Assunto('S', edtCodigo->GetValue(),""),
    ConsSQL->Assunto('U', edtCodigo->GetValue(), edtDescricao->GetValue()),
    ConsSQL->Assunto('I', edtCodigo->GetValue(), edtDescricao->GetValue()), 
    true);
  event.Skip();
}

void CfrmCadAssuntos::OnBtnExcluir(wxCommandEvent& event) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Assunto('D', edtCodigo->GetValue(),""));
  event.Skip();
}

void CfrmCadAssuntos::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmCadAssuntos::OnBtnLimpar(wxCommandEvent& event) {
  btnLimparClick();
  event.Skip();
}

