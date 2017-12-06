#include "CadAssuntos.h"
#include "Principal.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadAssuntos * frmCadAssuntos = (CfrmCadAssuntos *) NULL;

CfrmCadAssuntos::CfrmCadAssuntos()
  : CfrmCadastros(true, STR_CADASSUNTO) {

  labDescricao->set_text("Assunto: ");

  edtCodigo->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadAssuntos::on_edtCodigo_focus_out_event));
  btnNovo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAssuntos::on_btnNovo_clicked));
  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAssuntos::on_btnPesquisar_clicked));
  btnAnterior->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAssuntos::on_btnAnterior_clicked));
  btnProximo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAssuntos::on_btnProximo_clicked));
  btnSalvar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAssuntos::on_btnSalvar_clicked));
  btnExcluir->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAssuntos::on_btnExcluir_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAssuntos::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadAssuntos::on_btnFechar_clicked));
}

CfrmCadAssuntos::~CfrmCadAssuntos() {}

bool CfrmCadAssuntos::ValidaDados(bool bTodosDados)
{
  if (Rotinas->ValidaCampo(edtCodigo->get_text(), STR_CODNINF))
 	  return false;
	if (bTodosDados) {
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_ASSNINF))
  		return false;
	}
	return true;
}

bool CfrmCadAssuntos::on_edtCodigo_focus_out_event(GdkEventFocus* event) {
  ValidaCodigo();
  return false;
}

void CfrmCadAssuntos::on_btnNovo_clicked(){
  btnNovoClick();
  NovoDado(ConsSQL->Assunto('N', edtCodigo->get_text(),""));
}

void CfrmCadAssuntos::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Assunto('S', edtCodigo->get_text(),""), STR_ASSNENC);
}

void CfrmCadAssuntos::on_btnAnterior_clicked() {
  registroAnterior();
}

void CfrmCadAssuntos::on_btnProximo_clicked() {
  registroProximo();
}

void CfrmCadAssuntos::on_btnSalvar_clicked() {
  SalvarDados(ValidaDados(true),
    ConsSQL->Assunto('S', edtCodigo->get_text(), ""),
    ConsSQL->Assunto('U', edtCodigo->get_text(), edtDescricao->get_text()),
    ConsSQL->Assunto('I', edtCodigo->get_text(), edtDescricao->get_text()),
    true);
}

void CfrmCadAssuntos::on_btnExcluir_clicked() {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Assunto('D', edtCodigo->get_text(),""));
}

void CfrmCadAssuntos::on_btnLimpar_clicked() {
  btnLimparClick();
}

void CfrmCadAssuntos::destroy_() {
  frmPrincipal->mnuCadAssuntos->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmCadAssuntos::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}
