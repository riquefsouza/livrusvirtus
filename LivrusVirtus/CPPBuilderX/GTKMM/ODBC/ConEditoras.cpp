#include "ConEditoras.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmConEditoras * frmConEditoras = (CfrmConEditoras *) NULL;

CfrmConEditoras::CfrmConEditoras() : CfrmConsultas(STR_CONEDITORA) {
  labDescricao->set_text("Editora: ");

  int nLargura[] = { 80, 180 };
  Glib::ustring sRotulos[] = { Rotinas->retUTF8("Código") , "Editora" };

  Rotinas->AdicionaColunasGrid(gridConsulta, 0, 2, nLargura, sRotulos);

  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConEditoras::on_btnPesquisar_clicked));
  selection->signal_changed().connect(SigC::slot(* this,
   & CfrmConEditoras::on_gridConsulta_selection_changed));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConEditoras::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConEditoras::on_btnFechar_clicked));
}

CfrmConEditoras::~CfrmConEditoras() { }

void CfrmConEditoras::on_gridConsulta_selection_changed() {
  setSelecionado();
}

void CfrmConEditoras::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Editora('S', "", edtDescricao->get_text()),
    STR_EDTNENC, 2);
}

void CfrmConEditoras::on_btnLimpar_clicked() {
	LimparDados();
}

void CfrmConEditoras::on_btnFechar_clicked() {
  Fecha();
}
