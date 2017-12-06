#include "ConLivros.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmConLivros * frmConLivros = (CfrmConLivros *) NULL;

CfrmConLivros::CfrmConLivros() : CfrmConsultas(STR_CONLIVRO) {
  labDescricao->set_text("Livro: ");

  int nLargura[] = { 80, 180, 80, 90, 80, 80, 100, 80, 100, 80, 80, 80 };
  Glib::ustring sRotulos[] = { "ISBN", Rotinas->retUTF8("Título"), 
    Rotinas->retUTF8("Edição"), Rotinas->retUTF8("AnoPublicação"), 
    "Volume", "CodEditora", "Editora", "CodIdioma", "Idioma", 
    Rotinas->retUTF8("NumPáginas"), Rotinas->retUTF8("Preço"), "Estoque" };

  Rotinas->AdicionaColunasGrid(gridConsulta, 0, 12, nLargura, sRotulos);

  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConLivros::on_btnPesquisar_clicked));
  selection->signal_changed().connect(SigC::slot(* this,
   & CfrmConLivros::on_gridConsulta_selection_changed));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConLivros::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConLivros::on_btnFechar_clicked));
}

CfrmConLivros::~CfrmConLivros() { }

void CfrmConLivros::on_gridConsulta_selection_changed() {
  setSelecionado();
}

void CfrmConLivros::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Livro('S', "", edtDescricao->get_text(),
    "","","","","","","",""), STR_LIVNENC, 12);
}

void CfrmConLivros::on_btnLimpar_clicked() {
	LimparDados();
}

void CfrmConLivros::on_btnFechar_clicked() {
  Fecha();
}
