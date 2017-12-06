#include "ConClientes.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmConClientes * frmConClientes = (CfrmConClientes *) NULL;

CfrmConClientes::CfrmConClientes() : CfrmConsultas(STR_CONCLIENTE) {
  labDescricao->set_text("Cliente: ");

  int nLargura[] = { 80, 180, 180, 80, 40, 80, 120, 80, 
    220, 150, 80, 100, 100, 80, 180, 80, 100 };

  Glib::ustring sRotulos[] = { "CPF", "Nome" , "Email", "Identidade",
    "Sexo", "Telefone", "DtNascimento", Rotinas->retUTF8("CodEndereço"),
    "Logradouro", "Bairro", "CEP", "Cidade", "Estado",
    Rotinas->retUTF8("CodPaís"), Rotinas->retUTF8("País"),
    Rotinas->retUTF8("CodProfissão"), Rotinas->retUTF8("Profissão") };

  Rotinas->AdicionaColunasGrid(gridConsulta, 0, 17, nLargura, sRotulos);

  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConClientes::on_btnPesquisar_clicked));
  selection->signal_changed().connect(SigC::slot(* this,
   & CfrmConClientes::on_gridConsulta_selection_changed));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConClientes::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConClientes::on_btnFechar_clicked));
}

CfrmConClientes::~CfrmConClientes() { }

void CfrmConClientes::on_gridConsulta_selection_changed() {
  setSelecionado();
}

void CfrmConClientes::on_btnPesquisar_clicked() {
  PesquisarDados(ConsSQL->Cliente('S', "", edtDescricao->get_text(),
    "","","","","","","",""), STR_CLINENC, 17);
}

void CfrmConClientes::on_btnLimpar_clicked() {
	LimparDados();
}

void CfrmConClientes::on_btnFechar_clicked() {
  Fecha();
}
