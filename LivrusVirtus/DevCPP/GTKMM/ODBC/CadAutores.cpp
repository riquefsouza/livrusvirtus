#include "CadAutores.h"
#include "Principal.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadAutores * frmCadAutores = (CfrmCadAutores *) NULL;

CfrmCadAutores::CfrmCadAutores()
  : CfrmCadastros(true, STR_CADAUTOR) {

  labDescricao->set_text("Autor: ");

  edtCodigo->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadAutores::on_edtCodigo_focus_out_event));
  btnNovo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAutores::on_btnNovo_clicked));
  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAutores::on_btnPesquisar_clicked));
  btnAnterior->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAutores::on_btnAnterior_clicked));
  btnProximo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAutores::on_btnProximo_clicked));
  btnSalvar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAutores::on_btnSalvar_clicked));
  btnExcluir->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAutores::on_btnExcluir_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAutores::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAutores::on_btnFechar_clicked));
}

CfrmCadAutores::~CfrmCadAutores() {}

bool CfrmCadAutores::ValidaDados(bool bTodosDados)
{
  if (Rotinas->ValidaCampo(edtCodigo->get_text(), STR_CODNINF))
 	  return false;
	if (bTodosDados) {
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_AUTNINF))
  		return false;
	}
	return true;
}

bool CfrmCadAutores::on_edtCodigo_focus_out_event(GdkEventFocus* event) {
  ValidaCodigo();
  return false;
}

void CfrmCadAutores::on_btnNovo_clicked(){
  btnNovoClick();
  NovoDado(ConsSQL->Autor('N', edtCodigo->get_text(),""));
}

void CfrmCadAutores::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Autor('S', edtCodigo->get_text(),""), STR_AUTNENC);
}

void CfrmCadAutores::on_btnAnterior_clicked() {
  registroAnterior();
}

void CfrmCadAutores::on_btnProximo_clicked() {
  registroProximo();
}

void CfrmCadAutores::on_btnSalvar_clicked() {
  SalvarDados(ValidaDados(true),
    ConsSQL->Autor('S', edtCodigo->get_text(), ""),
    ConsSQL->Autor('U', edtCodigo->get_text(), edtDescricao->get_text()),
    ConsSQL->Autor('I', edtCodigo->get_text(), edtDescricao->get_text()),
    true);
}

void CfrmCadAutores::on_btnExcluir_clicked() {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Autor('D', edtCodigo->get_text(),""));
}

void CfrmCadAutores::on_btnLimpar_clicked() {
  btnLimparClick();
}

void CfrmCadAutores::destroy_() {
  frmPrincipal->mnuCadAutores->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmCadAutores::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}
