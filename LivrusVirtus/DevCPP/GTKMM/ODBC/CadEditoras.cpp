#include "CadEditoras.h"
#include "Principal.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadEditoras * frmCadEditoras = (CfrmCadEditoras *) NULL;

CfrmCadEditoras::CfrmCadEditoras()
  : CfrmCadastros(true, STR_CADEDITORA) {

  labDescricao->set_text("Editora: ");

  edtCodigo->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadEditoras::on_edtCodigo_focus_out_event));
  btnNovo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEditoras::on_btnNovo_clicked));
  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEditoras::on_btnPesquisar_clicked));
  btnAnterior->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEditoras::on_btnAnterior_clicked));
  btnProximo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEditoras::on_btnProximo_clicked));
  btnSalvar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEditoras::on_btnSalvar_clicked));
  btnExcluir->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEditoras::on_btnExcluir_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEditoras::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEditoras::on_btnFechar_clicked));
}

CfrmCadEditoras::~CfrmCadEditoras() {}

bool CfrmCadEditoras::ValidaDados(bool bTodosDados)
{
  if (Rotinas->ValidaCampo(edtCodigo->get_text(), STR_CODNINF))
 	  return false;
	if (bTodosDados) {
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_EDTNINF))
  		return false;
	}
	return true;
}

bool CfrmCadEditoras::on_edtCodigo_focus_out_event(GdkEventFocus* event) {
  ValidaCodigo();
  return false;
}

void CfrmCadEditoras::on_btnNovo_clicked(){
  btnNovoClick();
  NovoDado(ConsSQL->Editora('N', edtCodigo->get_text(),""));
}

void CfrmCadEditoras::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Editora('S', edtCodigo->get_text(),""), STR_EDTNENC);
}

void CfrmCadEditoras::on_btnAnterior_clicked() {
  registroAnterior();
}

void CfrmCadEditoras::on_btnProximo_clicked() {
  registroProximo();
}

void CfrmCadEditoras::on_btnSalvar_clicked() {
  SalvarDados(ValidaDados(true),
    ConsSQL->Editora('S', edtCodigo->get_text(), ""),
    ConsSQL->Editora('U', edtCodigo->get_text(), edtDescricao->get_text()),
    ConsSQL->Editora('I', edtCodigo->get_text(), edtDescricao->get_text()),
    true);
}

void CfrmCadEditoras::on_btnExcluir_clicked() {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Editora('D', edtCodigo->get_text(),""));
}

void CfrmCadEditoras::on_btnLimpar_clicked() {
  btnLimparClick();
}

void CfrmCadEditoras::destroy_() {
  frmPrincipal->mnuCadEditoras->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmCadEditoras::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}
