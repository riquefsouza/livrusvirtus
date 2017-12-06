#include "ConAssuntos.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmConAssuntos * frmConAssuntos = (CfrmConAssuntos *) NULL;

CfrmConAssuntos::CfrmConAssuntos() : CfrmConsultas(STR_CONASSUNTO) {
  labDescricao->set_text("Assunto: ");

  int nLargura[] = { 80, 180 };
  Glib::ustring sRotulos[] = { Rotinas->retUTF8("Código") , "Assunto" };

  Rotinas->AdicionaColunasGrid(gridConsulta, 0, 2, nLargura, sRotulos);

  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConAssuntos::on_btnPesquisar_clicked));
  selection->signal_changed().connect(SigC::slot(* this,
   & CfrmConAssuntos::on_gridConsulta_selection_changed));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConAssuntos::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConAssuntos::on_btnFechar_clicked));
}

CfrmConAssuntos::~CfrmConAssuntos() { }

void CfrmConAssuntos::on_gridConsulta_selection_changed() {
  setSelecionado();
}

void CfrmConAssuntos::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Assunto('S', "", edtDescricao->get_text()),
    STR_ASSNENC, 2);
}

void CfrmConAssuntos::on_btnLimpar_clicked() {
	LimparDados();
}

void CfrmConAssuntos::on_btnFechar_clicked() {
  Fecha();
}
