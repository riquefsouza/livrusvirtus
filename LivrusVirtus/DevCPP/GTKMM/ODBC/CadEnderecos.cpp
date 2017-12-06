#include "CadEnderecos.h"
#include "Principal.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadEnderecos * frmCadEnderecos = (CfrmCadEnderecos *) NULL;

CfrmCadEnderecos::CfrmCadEnderecos()
  : CfrmCadastros(false, STR_CADENDERECO) {

  this->set_default_size(560, 190);

  labDescricao->set_label("Logradouro: ");
  edtDescricao->set_size_request(288, 24);
  edtDescricao->set_max_length(50);

  edtBairro = manage(new class Gtk::Entry());
  fixed1->put(*edtBairro, 305, 72);
  edtBairro->set_size_request(158, 24);
  edtBairro->set_max_length(30);
  edtBairro->set_sensitive(false);

  edtCep = manage(new class Gtk::Entry());
  fixed1->put(*edtCep, 8, 112);
  edtCep->set_size_request(88, 24);
  edtCep->set_sensitive(false);

  edtCidade = manage(new class Gtk::Entry());
  fixed1->put(*edtCidade, 104, 112);
  edtCidade->set_size_request(192, 24);
  edtCidade->set_sensitive(false);

  labCidade = manage(new class Gtk::Label("Cidade:"));
  fixed1->put(*labCidade, 104, 96);
  labCidade->set_size_request(55, 16);

  labCep = manage(new class Gtk::Label("CEP:"));
  fixed1->put(*labCep, 8, 96);
  labCep->set_size_request(38, 16);

  labBairro = manage(new class Gtk::Label("Bairro:"));
  fixed1->put(*labBairro, 305, 56);
  labBairro->set_size_request(45, 16);
  labBairro->set_alignment(0, 0);

  labEstado = manage(new class Gtk::Label("Estado:"));
  fixed1->put(*labEstado, 305, 96);
  labEstado->set_size_request(55, 16);

  cmbEstado = manage(new class Gtk::Combo());
  fixed1->put(*cmbEstado, 305, 112);
  cmbEstado->set_size_request(160, 26);
  cmbEstado->set_sensitive(false);

  cmbEstadoEntrada = cmbEstado->get_entry();
  cmbEstadoEntrada->set_editable(false);

  IniciaBotoes(464, 10, 197, 152);

  show_all_children();

  edtCodigo->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadEnderecos::on_edtCodigo_focus_out_event));
  btnNovo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEnderecos::on_btnNovo_clicked));
  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEnderecos::on_btnPesquisar_clicked));
  btnAnterior->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEnderecos::on_btnAnterior_clicked));
  btnProximo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEnderecos::on_btnProximo_clicked));
  btnSalvar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEnderecos::on_btnSalvar_clicked));
  btnExcluir->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEnderecos::on_btnExcluir_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEnderecos::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadEnderecos::on_btnFechar_clicked));

  AdicionaCombo();
}

CfrmCadEnderecos::~CfrmCadEnderecos() {}

bool CfrmCadEnderecos::ValidaDados(bool bTodosDados)
{
  if (Rotinas->ValidaCampo(edtCodigo->get_text(), STR_CODNINF))
 	  return false;
	if (bTodosDados) {
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_ENDNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtBairro->get_text(), STR_BAIRRONINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtCep->get_text(), STR_CEPNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtCidade->get_text(), STR_CIDADENINF))
  		return false;
	}
	return true;
}

bool CfrmCadEnderecos::on_edtCodigo_focus_out_event(GdkEventFocus* event) {
  ValidaCodigo();
  return false;
}

void CfrmCadEnderecos::on_btnNovo_clicked(){
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);
  NovoDado(ConsSQL->Endereco('N', edtCodigo->get_text(),"","","","",""));
}

void CfrmCadEnderecos::on_btnPesquisar_clicked() {
  if (PesquisarDados(ConsSQL->Endereco('S', edtCodigo->get_text(),
    "","","","",""), STR_ENDNENC)) {
    InformaLimpaDados(true);
    HabilitaDados(true);
  }
}

void CfrmCadEnderecos::on_btnAnterior_clicked() {
 if (registroAnterior())
    InformaLimpaDados(true);
}

void CfrmCadEnderecos::on_btnProximo_clicked() {
 if (registroProximo())
    InformaLimpaDados(true);
}

void CfrmCadEnderecos::on_btnSalvar_clicked() {
  if (SalvarDados(ValidaDados(true),
    ConsSQL->Endereco('S', edtCodigo->get_text(), "","","","",""),
    ConsSQL->Endereco('U', edtCodigo->get_text(), edtDescricao->get_text(),
      edtBairro->get_text(), edtCep->get_text(), edtCidade->get_text(),
      cmbEstadoEntrada->get_text()),
    ConsSQL->Endereco('I', edtCodigo->get_text(), edtDescricao->get_text(),
      edtBairro->get_text(), edtCep->get_text(), edtCidade->get_text(),
      cmbEstadoEntrada->get_text()), true)) {
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
}

void CfrmCadEnderecos::on_btnExcluir_clicked() {
  if (ExcluirDados(ValidaDados(false),
    ConsSQL->Endereco('D', edtCodigo->get_text(),
    "","","","",""))) {
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
}

void CfrmCadEnderecos::on_btnLimpar_clicked() {
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);
}

void CfrmCadEnderecos::destroy_() {
  frmPrincipal->mnuCadEnderecos->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmCadEnderecos::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}

void CfrmCadEnderecos::InformaLimpaDados(bool bInformar)
{
  if (bInformar) {
    edtBairro->set_text(lstRegistros.col[2][nLinhaRegistro]);
    edtCep->set_text(lstRegistros.col[3][nLinhaRegistro]);
    edtCidade->set_text(lstRegistros.col[4][nLinhaRegistro]);
    AtribuiEstado(lstRegistros.col[5][nLinhaRegistro]);
  } else {
    edtBairro->set_text("");
    edtCep->set_text("");
    edtCidade->set_text("");
    cmbEstadoEntrada->set_text(listCmbEstado[0]);
  }

}

void CfrmCadEnderecos::HabilitaDados(bool bHabilita) {
  edtBairro->set_sensitive(bHabilita);
  edtCep->set_sensitive(bHabilita);
  edtCidade->set_sensitive(bHabilita);
  cmbEstado->set_sensitive(bHabilita);
}

void CfrmCadEnderecos::AdicionaCombo()
{
  listCmbEstado.push_back(Rotinas->retUTF8(STR_PE));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_AC));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_AL));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_AP));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_AM));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_BA));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_BR));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_CE));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_DF));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_ES));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_GO));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_MT));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_MS));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_MG));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_PA));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_PB));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_PR));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_SC));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_RN));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_RS));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_RJ));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_RO));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_RR));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_SP));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_SE));
  listCmbEstado.push_back(Rotinas->retUTF8(STR_TO));

  cmbEstado->set_popdown_strings(listCmbEstado);
}

void CfrmCadEnderecos::AtribuiEstado(Glib::ustring sEstado) {
int nCont;

 for (nCont=0; nCont < 26; nCont++) {
    if (listCmbEstado[nCont] == sEstado) {
       cmbEstadoEntrada->set_text(listCmbEstado[nCont]);
       break;
    }
 }
}

