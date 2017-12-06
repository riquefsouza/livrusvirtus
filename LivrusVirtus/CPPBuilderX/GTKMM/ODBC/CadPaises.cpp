#include "CadPaises.h"
#include "Principal.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadPaises * frmCadPaises = (CfrmCadPaises *) NULL;

CfrmCadPaises::CfrmCadPaises()
  : CfrmCadastros(true, STR_CADPAIS) {

  labDescricao->set_text(Rotinas->retUTF8("País: "));

  btnNovo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadPaises::on_btnNovo_clicked));
  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadPaises::on_btnPesquisar_clicked));
  btnAnterior->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadPaises::on_btnAnterior_clicked));
  btnProximo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadPaises::on_btnProximo_clicked));
  btnSalvar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadPaises::on_btnSalvar_clicked));
  btnExcluir->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadPaises::on_btnExcluir_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadPaises::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadPaises::on_btnFechar_clicked));
}

CfrmCadPaises::~CfrmCadPaises() {}

bool CfrmCadPaises::ValidaDados(bool bTodosDados)
{
  if (Rotinas->ValidaCampo(edtCodigo->get_text(), STR_CODNINF))
 	  return false;
	if (bTodosDados) {
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_PAISNINF))
  		return false;
	}
	return true;
}

void CfrmCadPaises::on_btnNovo_clicked(){
  btnNovoClick();
}

void CfrmCadPaises::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Pais('S', edtCodigo->get_text(),""), STR_PAISNENC);
}

void CfrmCadPaises::on_btnAnterior_clicked() {
  registroAnterior();
}

void CfrmCadPaises::on_btnProximo_clicked() {
  registroProximo();
}

void CfrmCadPaises::on_btnSalvar_clicked() {
  SalvarDados(ValidaDados(true),
    ConsSQL->Pais('S', edtCodigo->get_text(), ""),
    ConsSQL->Pais('U', edtCodigo->get_text(), edtDescricao->get_text()),
    ConsSQL->Pais('I', edtCodigo->get_text(), edtDescricao->get_text()),
    true);
}

void CfrmCadPaises::on_btnExcluir_clicked() {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Pais('D', edtCodigo->get_text(),""));
}

void CfrmCadPaises::on_btnLimpar_clicked() {
  btnLimparClick();
}

void CfrmCadPaises::destroy_() {
  frmPrincipal->mnuCadPaises->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmCadPaises::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}
