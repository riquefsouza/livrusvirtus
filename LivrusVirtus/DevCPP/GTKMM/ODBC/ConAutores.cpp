#include "ConAutores.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmConAutores * frmConAutores = (CfrmConAutores *) NULL;

CfrmConAutores::CfrmConAutores() : CfrmConsultas(STR_CONAUTOR) {
  labDescricao->set_text("Autor: ");

  int nLargura[] = { 80, 180 };
  Glib::ustring sRotulos[] = { Rotinas->retUTF8("Código") , "Autor" };

  Rotinas->AdicionaColunasGrid(gridConsulta, 0, 2, nLargura, sRotulos);

  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConAutores::on_btnPesquisar_clicked));
  selection->signal_changed().connect(SigC::slot(* this,
   & CfrmConAutores::on_gridConsulta_selection_changed));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConAutores::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConAutores::on_btnFechar_clicked));
}

CfrmConAutores::~CfrmConAutores() { }

void CfrmConAutores::on_gridConsulta_selection_changed() {
  setSelecionado();
}

void CfrmConAutores::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Autor('S', "", edtDescricao->get_text()),
    STR_AUTNENC, 2);
}

void CfrmConAutores::on_btnLimpar_clicked() {
	LimparDados();
}

void CfrmConAutores::on_btnFechar_clicked() {
  Fecha();
}
