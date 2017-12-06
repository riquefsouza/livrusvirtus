#include "resource.h"
#include "Cadastros.h"
#include "CadEditoras.h"
#include "Principal.h"
#include "ConsultasSQL.h"

BEGIN_EVENT_TABLE(CfrmCadEditoras, CfrmCadastros)
  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, CfrmCadEditoras::OnBtnNovo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, CfrmCadEditoras::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, CfrmCadEditoras::OnBtnAnterior)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, CfrmCadEditoras::OnBtnProximo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, CfrmCadEditoras::OnBtnSalvar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, CfrmCadEditoras::OnBtnExcluir)
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, CfrmCadEditoras::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, CfrmCadEditoras::OnBtnFechar)
  EVT_CLOSE(CfrmCadEditoras::OnClose)
END_EVENT_TABLE()

CfrmCadEditoras::CfrmCadEditoras(wxWindow *parent)
       : CfrmCadastros(parent, wxFILTER_NUMERIC, true) {
  CfrmCadEditoras::IniciaControles();
}

void CfrmCadEditoras::IniciaControles() {
 this->labDescricao->SetLabel(wxT("Editora: "));
}

CfrmCadEditoras::~CfrmCadEditoras() { }

bool CfrmCadEditoras::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->GetValue(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->GetValue(), STR_EDTNINF))
  		return false;
  	}
  	return true;
}

void CfrmCadEditoras::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmCadEditoras::OnBtnNovo(wxCommandEvent& event) {
  btnNovoClick();
  NovoDado(ConsSQL->Editora('N', edtCodigo->GetValue(),""));	
  event.Skip();
}

void CfrmCadEditoras::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Editora('S', edtCodigo->GetValue(),""), STR_EDTNENC, 2);
  event.Skip();
}

void CfrmCadEditoras::OnBtnAnterior(wxCommandEvent& event) {
  registroAnterior();	
  event.Skip();
}

void CfrmCadEditoras::OnBtnProximo(wxCommandEvent& event) {
  registroProximo();		
  event.Skip();
}

void CfrmCadEditoras::OnBtnSalvar(wxCommandEvent& event) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Editora('S', edtCodigo->GetValue(),""),
    ConsSQL->Editora('U', edtCodigo->GetValue(), edtDescricao->GetValue()),
    ConsSQL->Editora('I', edtCodigo->GetValue(), edtDescricao->GetValue()), 
    true);
  event.Skip();
}

void CfrmCadEditoras::OnBtnExcluir(wxCommandEvent& event) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Editora('D', edtCodigo->GetValue(),""));
  event.Skip();
}

void CfrmCadEditoras::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmCadEditoras::OnBtnLimpar(wxCommandEvent& event) {
  btnLimparClick();
  event.Skip();
}

