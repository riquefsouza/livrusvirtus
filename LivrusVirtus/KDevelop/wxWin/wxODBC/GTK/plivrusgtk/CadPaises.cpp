#include "resource.h"
#include "Cadastros.h"
#include "CadPaises.h"
#include "Principal.h"
#include "ConsultasSQL.h"

BEGIN_EVENT_TABLE(CfrmCadPaises, CfrmCadastros)
  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, CfrmCadPaises::OnBtnNovo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, CfrmCadPaises::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, CfrmCadPaises::OnBtnAnterior)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, CfrmCadPaises::OnBtnProximo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, CfrmCadPaises::OnBtnSalvar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, CfrmCadPaises::OnBtnExcluir)
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, CfrmCadPaises::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, CfrmCadPaises::OnBtnFechar)
  EVT_CLOSE(CfrmCadPaises::OnClose)
END_EVENT_TABLE()

CfrmCadPaises::CfrmCadPaises(wxWindow *parent)
       : CfrmCadastros(parent, wxFILTER_ALPHA, true) {
  CfrmCadPaises::IniciaControles();
}

void CfrmCadPaises::IniciaControles() {
 this->edtCodigo->SetMaxLength(3);
 this->labDescricao->SetLabel(wxT("País: "));
 InformaLimpaDados(false);
}

CfrmCadPaises::~CfrmCadPaises() { }

bool CfrmCadPaises::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->GetValue(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->GetValue(), STR_PAISNINF))
  		return false;
  	}
  	return true;
}

void CfrmCadPaises::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmCadPaises::InformaLimpaDados(bool bInformar)
{
  if (bInformar) {
    edtCodigo->SetValue(lstRegistros.col[0].Item(nLinhaRegistro));
  } else {
    edtCodigo->Clear();
    edtCodigo->Enable(true);
    edtCodigo->SetFocus();
  }
} 

void CfrmCadPaises::OnBtnNovo(wxCommandEvent& event) {
  btnNovoClick();
  InformaLimpaDados(false);
  event.Skip();
}

void CfrmCadPaises::OnBtnPesquisar(wxCommandEvent& event) {
  if (PesquisarDados(
    ConsSQL->Pais('S', edtCodigo->GetValue(),""), STR_PAISNENC, 2))
    InformaLimpaDados(true);
  event.Skip();
}

void CfrmCadPaises::OnBtnAnterior(wxCommandEvent& event) {
  if (registroAnterior())
    InformaLimpaDados(true);
  event.Skip();
}

void CfrmCadPaises::OnBtnProximo(wxCommandEvent& event) {
  if (registroProximo())
    InformaLimpaDados(true);
  event.Skip();
}

void CfrmCadPaises::OnBtnSalvar(wxCommandEvent& event) {
  if (SalvarDados(ValidaDados(true),
    ConsSQL->Pais('S', edtCodigo->GetValue(),""),
    ConsSQL->Pais('U', edtCodigo->GetValue(), edtDescricao->GetValue()),
    ConsSQL->Pais('I', edtCodigo->GetValue(), edtDescricao->GetValue()), 
    true))
    InformaLimpaDados(false);
  event.Skip();
}

void CfrmCadPaises::OnBtnExcluir(wxCommandEvent& event) {
  if (ExcluirDados(ValidaDados(false),
    ConsSQL->Pais('D', edtCodigo->GetValue(),"")))
    InformaLimpaDados(false);
  event.Skip();
}

void CfrmCadPaises::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmCadPaises::OnBtnLimpar(wxCommandEvent& event) {
  btnLimparClick();
  InformaLimpaDados(false);
  event.Skip();
}

