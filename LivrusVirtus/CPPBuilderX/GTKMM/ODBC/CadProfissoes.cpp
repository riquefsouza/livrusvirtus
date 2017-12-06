#include "CadProfissoes.h"
#include "Principal.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadProfissoes * frmCadProfissoes = (CfrmCadProfissoes *) NULL;

CfrmCadProfissoes::CfrmCadProfissoes()
  : CfrmCadastros(true, STR_CADPROFISS) {

  labDescricao->set_text(Rotinas->retUTF8("Profissão: "));

  edtCodigo->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadProfissoes::on_edtCodigo_focus_out_event));
  btnNovo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadProfissoes::on_btnNovo_clicked));
  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadProfissoes::on_btnPesquisar_clicked));
  btnAnterior->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadProfissoes::on_btnAnterior_clicked));
  btnProximo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadProfissoes::on_btnProximo_clicked));
  btnSalvar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadProfissoes::on_btnSalvar_clicked));
  btnExcluir->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadProfissoes::on_btnExcluir_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadProfissoes::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadProfissoes::on_btnFechar_clicked));
}

CfrmCadProfissoes::~CfrmCadProfissoes() {}

bool CfrmCadProfissoes::ValidaDados(bool bTodosDados)
{
  if (Rotinas->ValidaCampo(edtCodigo->get_text(), STR_CODNINF))
 	  return false;
	if (bTodosDados) {
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_PROFNINF))
  		return false;
	}
	return true;
}

bool CfrmCadProfissoes::on_edtCodigo_focus_out_event(GdkEventFocus* event) {
  ValidaCodigo();
  return false;
}

void CfrmCadProfissoes::on_btnNovo_clicked(){
  btnNovoClick();
  NovoDado(ConsSQL->Profissao('N', edtCodigo->get_text(),""));
}

void CfrmCadProfissoes::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Profissao('S', edtCodigo->get_text(),""), STR_PROFNENC);
}

void CfrmCadProfissoes::on_btnAnterior_clicked() {
  registroAnterior();
}

void CfrmCadProfissoes::on_btnProximo_clicked() {
  registroProximo();
}

void CfrmCadProfissoes::on_btnSalvar_clicked() {
  SalvarDados(ValidaDados(true),
    ConsSQL->Profissao('S', edtCodigo->get_text(), ""),
    ConsSQL->Profissao('U', edtCodigo->get_text(), edtDescricao->get_text()),
    ConsSQL->Profissao('I', edtCodigo->get_text(), edtDescricao->get_text()),
    true);
}

void CfrmCadProfissoes::on_btnExcluir_clicked() {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Profissao('D', edtCodigo->get_text(),""));
}

void CfrmCadProfissoes::on_btnLimpar_clicked() {
  btnLimparClick();
}

void CfrmCadProfissoes::destroy_() {
  frmPrincipal->mnuCadProfissoes->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmCadProfissoes::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}
