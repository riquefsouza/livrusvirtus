#include "CadIdiomas.h"
#include "Principal.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadIdiomas * frmCadIdiomas = (CfrmCadIdiomas *) NULL;

CfrmCadIdiomas::CfrmCadIdiomas()
  : CfrmCadastros(true, STR_CADIDIOMA) {

  labDescricao->set_text("Idioma: ");

  edtCodigo->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadIdiomas::on_edtCodigo_focus_out_event));
  btnNovo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadIdiomas::on_btnNovo_clicked));
  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadIdiomas::on_btnPesquisar_clicked));
  btnAnterior->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadIdiomas::on_btnAnterior_clicked));
  btnProximo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadIdiomas::on_btnProximo_clicked));
  btnSalvar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadIdiomas::on_btnSalvar_clicked));
  btnExcluir->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadIdiomas::on_btnExcluir_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadIdiomas::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadIdiomas::on_btnFechar_clicked));
}

CfrmCadIdiomas::~CfrmCadIdiomas() {}

bool CfrmCadIdiomas::ValidaDados(bool bTodosDados)
{
  if (Rotinas->ValidaCampo(edtCodigo->get_text(), STR_CODNINF))
 	  return false;
	if (bTodosDados) {
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_IDININF))
  		return false;
	}
	return true;
}

bool CfrmCadIdiomas::on_edtCodigo_focus_out_event(GdkEventFocus* event) {
  ValidaCodigo();
  return false;
}

void CfrmCadIdiomas::on_btnNovo_clicked(){
  btnNovoClick();
  NovoDado(ConsSQL->Idioma('N', edtCodigo->get_text(),""));
}

void CfrmCadIdiomas::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Idioma('S', edtCodigo->get_text(),""), STR_IDINENC);
}

void CfrmCadIdiomas::on_btnAnterior_clicked() {
  registroAnterior();
}

void CfrmCadIdiomas::on_btnProximo_clicked() {
  registroProximo();
}

void CfrmCadIdiomas::on_btnSalvar_clicked() {
  SalvarDados(ValidaDados(true),
    ConsSQL->Idioma('S', edtCodigo->get_text(), ""),
    ConsSQL->Idioma('U', edtCodigo->get_text(), edtDescricao->get_text()),
    ConsSQL->Idioma('I', edtCodigo->get_text(), edtDescricao->get_text()),
    true);
}

void CfrmCadIdiomas::on_btnExcluir_clicked() {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Idioma('D', edtCodigo->get_text(),""));
}

void CfrmCadIdiomas::on_btnLimpar_clicked() {
  btnLimparClick();
}

void CfrmCadIdiomas::destroy_() {
  frmPrincipal->mnuCadIdiomas->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmCadIdiomas::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}
