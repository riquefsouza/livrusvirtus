#include "ConPaises.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmConPaises * frmConPaises = (CfrmConPaises *) NULL;

CfrmConPaises::CfrmConPaises() : CfrmConsultas(STR_CONPAIS) {
  labDescricao->set_text(Rotinas->retUTF8("País: "));

  int nLargura[] = { 80, 180 };
  Glib::ustring sRotulos[] = { Rotinas->retUTF8("Código") , 
    Rotinas->retUTF8("País") };

  Rotinas->AdicionaColunasGrid(gridConsulta, 0, 2, nLargura, sRotulos);

  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConPaises::on_btnPesquisar_clicked));
  selection->signal_changed().connect(SigC::slot(* this,
   & CfrmConPaises::on_gridConsulta_selection_changed));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConPaises::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConPaises::on_btnFechar_clicked));
}

CfrmConPaises::~CfrmConPaises() { }

void CfrmConPaises::on_gridConsulta_selection_changed() {
  setSelecionado();
}

void CfrmConPaises::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Pais('S', "", edtDescricao->get_text()),
    STR_PAISNENC, 2);
}

void CfrmConPaises::on_btnLimpar_clicked() {
	LimparDados();
}

void CfrmConPaises::on_btnFechar_clicked() {
  Fecha();
}
