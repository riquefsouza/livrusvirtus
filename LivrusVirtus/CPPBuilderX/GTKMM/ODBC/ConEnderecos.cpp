#include "ConEnderecos.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmConEnderecos * frmConEnderecos = (CfrmConEnderecos *) NULL;

CfrmConEnderecos::CfrmConEnderecos() : CfrmConsultas(STR_CONENDERECO) {
  labDescricao->set_text(Rotinas->retUTF8("Endereço: "));

  int nLargura[] = { 80, 180, 150, 80, 100, 80 };
  Glib::ustring sRotulos[] = { Rotinas->retUTF8("Código") , "Logradouro",
    "Bairro", "CEP", "Cidade", "Estado" };

  Rotinas->AdicionaColunasGrid(gridConsulta, 0, 6, nLargura, sRotulos);

  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConEnderecos::on_btnPesquisar_clicked));
  selection->signal_changed().connect(SigC::slot(* this,
   & CfrmConEnderecos::on_gridConsulta_selection_changed));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConEnderecos::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConEnderecos::on_btnFechar_clicked));
}

CfrmConEnderecos::~CfrmConEnderecos() { }

void CfrmConEnderecos::on_gridConsulta_selection_changed() {
  setSelecionado();
}

void CfrmConEnderecos::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Endereco('S', "", edtDescricao->get_text(),
    "","","",""), STR_ENDNENC, 6);
}

void CfrmConEnderecos::on_btnLimpar_clicked() {
	LimparDados();
}

void CfrmConEnderecos::on_btnFechar_clicked() {
  Fecha();
}
