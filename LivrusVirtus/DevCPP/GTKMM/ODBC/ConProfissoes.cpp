#include "ConProfissoes.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmConProfissoes * frmConProfissoes = (CfrmConProfissoes *) NULL;

CfrmConProfissoes::CfrmConProfissoes() : CfrmConsultas(STR_CONPROFISS) {
  labDescricao->set_text(Rotinas->retUTF8("Profissão: "));

  int nLargura[] = { 80, 180 };
  Glib::ustring sRotulos[] = { Rotinas->retUTF8("Código") ,
    Rotinas->retUTF8("Profissão") };

  Rotinas->AdicionaColunasGrid(gridConsulta, 0, 2, nLargura, sRotulos);

  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConProfissoes::on_btnPesquisar_clicked));
  selection->signal_changed().connect(SigC::slot(* this,
   & CfrmConProfissoes::on_gridConsulta_selection_changed));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConProfissoes::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConProfissoes::on_btnFechar_clicked));
}

CfrmConProfissoes::~CfrmConProfissoes() { }

void CfrmConProfissoes::on_gridConsulta_selection_changed() {
  setSelecionado();
}

void CfrmConProfissoes::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Profissao('S', "", edtDescricao->get_text()),
    STR_PROFNENC, 2);
}

void CfrmConProfissoes::on_btnLimpar_clicked() {
	LimparDados();
}

void CfrmConProfissoes::on_btnFechar_clicked() {
  Fecha();
}
