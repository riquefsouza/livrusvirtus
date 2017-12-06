#include "ConIdiomas.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmConIdiomas * frmConIdiomas = (CfrmConIdiomas *) NULL;

CfrmConIdiomas::CfrmConIdiomas() : CfrmConsultas(STR_CONIDIOMA) {
  labDescricao->set_text("Idioma: ");

  int nLargura[] = { 80, 180 };
  Glib::ustring sRotulos[] = { Rotinas->retUTF8("Código") , "Idioma" };

  Rotinas->AdicionaColunasGrid(gridConsulta, 0, 2, nLargura, sRotulos);

  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConIdiomas::on_btnPesquisar_clicked));
  selection->signal_changed().connect(SigC::slot(* this,
   & CfrmConIdiomas::on_gridConsulta_selection_changed));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConIdiomas::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConIdiomas::on_btnFechar_clicked));
}

CfrmConIdiomas::~CfrmConIdiomas() { }

void CfrmConIdiomas::on_gridConsulta_selection_changed() {
  setSelecionado();
}

void CfrmConIdiomas::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Idioma('S', "", edtDescricao->get_text()),
    STR_IDINENC, 2);
}

void CfrmConIdiomas::on_btnLimpar_clicked() {
	LimparDados();
}

void CfrmConIdiomas::on_btnFechar_clicked() {
  Fecha();
}
