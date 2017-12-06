#include "resource.h"
#include "Cadastros.h"
#include "CadIdiomas.h"
#include "Principal.h"
#include "ConsultasSQL.h"

BEGIN_EVENT_TABLE(CfrmCadIdiomas, CfrmCadastros)
  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, CfrmCadIdiomas::OnBtnNovo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, CfrmCadIdiomas::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, CfrmCadIdiomas::OnBtnAnterior)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, CfrmCadIdiomas::OnBtnProximo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, CfrmCadIdiomas::OnBtnSalvar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, CfrmCadIdiomas::OnBtnExcluir)
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, CfrmCadIdiomas::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, CfrmCadIdiomas::OnBtnFechar)
  EVT_CLOSE(CfrmCadIdiomas::OnClose)
END_EVENT_TABLE()

CfrmCadIdiomas::CfrmCadIdiomas(wxWindow *parent)
       : CfrmCadastros(parent, wxFILTER_NUMERIC, true) {
  CfrmCadIdiomas::IniciaControles();
}

void CfrmCadIdiomas::IniciaControles() {
 this->labDescricao->SetLabel(wxT("Idioma: "));
}

CfrmCadIdiomas::~CfrmCadIdiomas() { }

bool CfrmCadIdiomas::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->GetValue(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->GetValue(), STR_IDININF))
  		return false;
  	}
  	return true;
}

void CfrmCadIdiomas::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmCadIdiomas::OnBtnNovo(wxCommandEvent& event) {
  btnNovoClick();
  event.Skip();
}

void CfrmCadIdiomas::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Idioma('S', edtCodigo->GetValue(),""), STR_IDINENC, 2);
  event.Skip();
}

void CfrmCadIdiomas::OnBtnAnterior(wxCommandEvent& event) {
  registroAnterior();	
  event.Skip();
}

void CfrmCadIdiomas::OnBtnProximo(wxCommandEvent& event) {
  registroProximo();		
  event.Skip();
}

void CfrmCadIdiomas::OnBtnSalvar(wxCommandEvent& event) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Idioma('S', edtCodigo->GetValue(),""),
    ConsSQL->Idioma('U', edtCodigo->GetValue(), edtDescricao->GetValue()),
    ConsSQL->Idioma('I', edtCodigo->GetValue(), edtDescricao->GetValue()), 
    true);
  event.Skip();
}

void CfrmCadIdiomas::OnBtnExcluir(wxCommandEvent& event) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Idioma('D', edtCodigo->GetValue(),""));
  event.Skip();
}

void CfrmCadIdiomas::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmCadIdiomas::OnBtnLimpar(wxCommandEvent& event) {
  btnLimparClick();
  event.Skip();
}

