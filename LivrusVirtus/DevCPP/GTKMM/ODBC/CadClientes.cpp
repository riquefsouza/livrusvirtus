#include "CadClientes.h"
#include "Principal.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConEnderecos.h"
#include "ConPaises.h"
#include "ConProfissoes.h"

CfrmCadClientes * frmCadClientes = (CfrmCadClientes *) NULL;

CfrmCadClientes::CfrmCadClientes()
  : CfrmCadastros(false, STR_CADCLIENTE) {

  this->set_default_size(560, 465);

  labCodigo->set_label("CPF: ");
  labCodigo->set_alignment(0, 0.5);
  edtCodigo->set_max_length(14);

  labDescricao->set_label("Nome: ");
  labDescricao->set_alignment(0, 0.5);
  edtDescricao->set_size_request(320, 24);
  edtDescricao->set_max_length(30);

  edtIdentidade = manage(new class Gtk::Entry());
  fixed1->put(*edtIdentidade, 336, 112);
  edtIdentidade->set_size_request(126, 24);
  edtIdentidade->set_max_length(10);
  edtIdentidade->set_sensitive(false);

  edtEmail = manage(new class Gtk::Entry());
  fixed1->put(*edtEmail, 8, 112);
  edtEmail->set_size_request(320, 24);
  edtEmail->set_sensitive(false);
  edtEmail->set_max_length(30);

  edtTelefone = manage(new class Gtk::Entry());
  fixed1->put(*edtTelefone, 200, 160);
  edtTelefone->set_size_request(128, 24);
  edtTelefone->set_max_length(17);
  edtTelefone->set_sensitive(false);

  labEmail = manage(new class Gtk::Label("E-mail:"));
  fixed1->put(*labEmail, 8, 96);
  labEmail->set_alignment(0, 0.5);
  labEmail->set_size_request(55, 16);

  labIdentidade = manage(new class Gtk::Label("Identidade:"));
  fixed1->put(*labIdentidade, 336, 96);
  labIdentidade->set_size_request(100, 16);
  labIdentidade->set_alignment(0, 0);

  labTelefone = manage(new class Gtk::Label("Telefone:"));
  fixed1->put(*labTelefone, 200, 144);
  labTelefone->set_size_request(55, 16);

  edtDtNasc = manage(new class Gtk::Entry());
  fixed1->put(*edtDtNasc, 336, 160);
  edtDtNasc->set_size_request(128, 24);
  edtDtNasc->set_sensitive(false);
  edtDtNasc->set_max_length(10);

  labDtNascimento = manage(new class Gtk::Label("Dt. Nascimento:"));
  fixed1->put(*labDtNascimento, 336, 144);
  labDtNascimento->set_size_request(110, 16);
  labDtNascimento->set_alignment(0, 0.5);

  grpSexo = manage(new class Gtk::Frame());
  fixed1->put(*grpSexo, 8, 144);
  grpSexo->set_size_request(190, 44);
  grpSexo->set_sensitive(false);

  fixed2 = manage(new class Gtk::Fixed());
  grpSexo->add(*fixed2);
  fixed2->set_border_width(1);

  rbMasculino = manage(new class Gtk::RadioButton("Masculino"));
  fixed2->put(*rbMasculino, 8, 0);
  rbMasculino->set_size_request(87, 22);

  rbGrupo = rbMasculino->get_group();

  rbFeminino = manage(new class Gtk::RadioButton("Feminino"));
  fixed2->put(*rbFeminino, 96, 0);
  rbFeminino->set_size_request(87, 21);
  rbFeminino->set_group(rbGrupo);

  labSexo = manage(new class Gtk::Label("Sexo"));
  grpSexo->set_label_widget(*labSexo);
  labSexo->set_use_markup(true);
  labSexo->set_alignment(0.5, 0);
  labSexo->set_padding(1, 0);

  edtCodPais = manage(new class Gtk::Entry());
  fixed1->put(*edtCodPais, 8, 352);
  edtCodPais->set_size_request(96, 24);
  edtCodPais->set_max_length(10);
  edtCodPais->set_sensitive(false);

  edtPais = manage(new class Gtk::Entry());
  fixed1->put(*edtPais, 112, 352);
  edtPais->set_size_request(232, 24);
  #ifdef G_OS_WIN32
    edtPais->set_sensitive(false);
  #else
    edtPais->unset_flags(Gtk::CAN_FOCUS);
  #endif

  edtCodProfissao = manage(new class Gtk::Entry());
  fixed1->put(*edtCodProfissao, 8, 392);
  edtCodProfissao->set_size_request(96, 24);
  edtCodProfissao->set_max_length(10);
  edtCodProfissao->set_sensitive(false);

  edtProfissao = manage(new class Gtk::Entry());
  fixed1->put(*edtProfissao, 112, 392);
  edtProfissao->set_size_request(232, 24);
  #ifdef G_OS_WIN32
    edtProfissao->set_sensitive(false);
  #else
    edtProfissao->unset_flags(Gtk::CAN_FOCUS);
  #endif

  labProfissao = manage(new class Gtk::Label(Rotinas->retUTF8("Profissão:")));
  fixed1->put(*labProfissao, 8, 376);
  labProfissao->set_size_request(100, 16);
  labProfissao->set_alignment(0, 0);

  labPais = manage(new class Gtk::Label(Rotinas->retUTF8("País de origem:")));
  fixed1->put(*labPais, 8, 336);
  labPais->set_size_request(100, 16);
  labPais->set_alignment(0, 0);

  btnPPais = manage(new class Gtk::Button("..."));
  fixed1->put(*btnPPais, 344, 352);
  btnPPais->set_size_request(25, 25);
  btnPPais->set_sensitive(false);

  btnPProfissao = manage(new class Gtk::Button("..."));
  fixed1->put(*btnPProfissao, 344, 392);
  btnPProfissao->set_size_request(25, 25);
  btnPProfissao->set_sensitive(false);

  grpEndereco = manage(new class Gtk::Frame());
  fixed1->put(*grpEndereco, 8, 192);
  grpEndereco->set_size_request(480, 135);
  grpEndereco->set_sensitive(false);

  fixed3 = manage(new class Gtk::Fixed());
  grpEndereco->add(*fixed3);

  edtCodEndereco = manage(new class Gtk::Entry());
  fixed3->put(*edtCodEndereco, 8, 8);
  edtCodEndereco->set_size_request(112, 24);
  edtCodEndereco->set_max_length(10);

  edtLogradouro = manage(new class Gtk::Entry());
  fixed3->put(*edtLogradouro, 8, 48);
  edtLogradouro->set_size_request(288, 24);
  edtLogradouro->set_max_length(50);
  #ifdef G_OS_WIN32
    edtLogradouro->set_sensitive(false);
  #else
    edtLogradouro->unset_flags(Gtk::CAN_FOCUS);
  #endif

  edtBairro = manage(new class Gtk::Entry());
  fixed3->put(*edtBairro, 304, 48);
  edtBairro->set_size_request(158, 24);
  edtBairro->set_max_length(30);
  #ifdef G_OS_WIN32
    edtBairro->set_sensitive(false);
  #else
    edtBairro->unset_flags(Gtk::CAN_FOCUS);
  #endif

  edtCep = manage(new class Gtk::Entry());
  fixed3->put(*edtCep, 8, 88);
  edtCep->set_size_request(88, 24);
  #ifdef G_OS_WIN32
    edtCep->set_sensitive(false);
  #else
    edtCep->unset_flags(Gtk::CAN_FOCUS);
  #endif

  edtCidade = manage(new class Gtk::Entry());
  fixed3->put(*edtCidade, 104, 88);
  edtCidade->set_size_request(192, 24);
  #ifdef G_OS_WIN32
    edtCidade->set_sensitive(false);
  #else
    edtCidade->unset_flags(Gtk::CAN_FOCUS);
  #endif

  edtEstado = manage(new class Gtk::Entry());
  fixed3->put(*edtEstado, 304, 88);
  edtEstado->set_size_request(158, 24);
  #ifdef G_OS_WIN32
    edtEstado->set_sensitive(false);
  #else
    edtEstado->unset_flags(Gtk::CAN_FOCUS);
  #endif

  labLogradouro = manage(new class Gtk::Label("Logradouro:"));
  fixed3->put(*labLogradouro, 8, 32);
  labLogradouro->set_size_request(80, 16);
  labLogradouro->set_alignment(0, 0.5);

  labBairro = manage(new class Gtk::Label("Bairro:"));
  fixed3->put(*labBairro, 304, 32);
  labBairro->set_size_request(45, 16);
  labBairro->set_alignment(0, 0);

  labCep = manage(new class Gtk::Label("CEP:"));
  fixed3->put(*labCep, 8, 72);
  labCep->set_size_request(38, 16);

  labCidade = manage(new class Gtk::Label("Cidade:"));
  fixed3->put(*labCidade, 104, 72);
  labCidade->set_size_request(55, 16);

  labEstado = manage(new class Gtk::Label("Estado:"));
  fixed3->put(*labEstado, 304, 72);
  labEstado->set_size_request(55, 16);
  labEstado->set_alignment(0, 0);

  btnPEndereco = manage(new class Gtk::Button("..."));
  fixed3->put(*btnPEndereco, 120, 8);
  btnPEndereco->set_size_request(25, 25);

  labEndereco = manage(new class Gtk::Label(Rotinas->retUTF8("Endereço:")));
  grpEndereco->set_label_widget(*labEndereco);
  labEndereco->set_use_markup(true);

  IniciaBotoes(464, 10, 197, 430);

  show_all_children();

  edtCodigo->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadClientes::on_edtCodigo_focus_out_event));
  btnNovo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnNovo_clicked));
  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnPesquisar_clicked));
  btnAnterior->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnAnterior_clicked));
  btnProximo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnProximo_clicked));
  btnSalvar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnSalvar_clicked));
  btnExcluir->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnExcluir_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnFechar_clicked));

  edtDtNasc->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadClientes::on_edtDtNasc_focus_out_event));
  edtCodEndereco->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadClientes::on_edtCodEndereco_focus_out_event));
  edtCodPais->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadClientes::on_edtCodPais_focus_out_event));
  edtCodProfissao->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadClientes::on_edtCodProfissao_focus_out_event));
  btnPEndereco->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnPEndereco_clicked));
  btnPPais->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnPPais_clicked));
  btnPProfissao->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadClientes::on_btnPProfissao_clicked));
}

CfrmCadClientes::~CfrmCadClientes() {}

bool CfrmCadClientes::ValidaDados(bool bTodosDados)
{
  if (Rotinas->ValidaCampo(edtCodigo->get_text(), STR_CPFNINF))
 	  return false;
	if (bTodosDados) {
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_CLININF))
  		return false;
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_EMAILNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_TELNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_ENDNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_PAISNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_PROFNINF))
  		return false;
	}
	return true;
}

bool CfrmCadClientes::on_edtCodigo_focus_out_event(GdkEventFocus* event) {
  if (edtCodigo->get_text().length() > 0) {
  	if (Rotinas->ValidaCPF(edtCodigo->get_text())==false) {
      Rotinas->MsgDlg(STR_CPFINV, Gtk::MESSAGE_ERROR);
      edtCodigo->set_text("");
      edtCodigo->grab_focus();
  	}
  }
  return false;
}

void CfrmCadClientes::on_btnNovo_clicked(){
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);
}

void CfrmCadClientes::on_btnPesquisar_clicked() {
  if (PesquisarDados(ConsSQL->Cliente('S', edtCodigo->get_text(),
    "","","","","","","","",""), STR_CLINENC)) {
    InformaLimpaDados(true);
    HabilitaDados(true);
  }
}

void CfrmCadClientes::on_btnAnterior_clicked() {
  if (registroAnterior())
    InformaLimpaDados(true);
}

void CfrmCadClientes::on_btnProximo_clicked() {
  if (registroProximo())
    InformaLimpaDados(true);
}

void CfrmCadClientes::on_btnSalvar_clicked() {
  Glib::ustring sSexo, sDtNasc, sSqlInsert, sSqlUpdate, sDTHR;

  sDTHR = edtDtNasc->get_text();
  sDtNasc = Rotinas->ConverteDataHoraStr(sDTHR, true, "%m/%d/%Y", "");

  if (rbMasculino->get_active())
     sSexo = "M";
  else
     sSexo = "F";

  sSqlUpdate = ConsSQL->Cliente('U', edtCodigo->get_text(),
    edtDescricao->get_text(), edtEmail->get_text(), edtIdentidade->get_text(),
    sSexo, edtTelefone->get_text(), sDtNasc, edtCodEndereco->get_text(),
    edtCodPais->get_text(), edtCodProfissao->get_text());

  sSqlInsert = ConsSQL->Cliente('I', edtCodigo->get_text(),
    edtDescricao->get_text(), edtEmail->get_text(), edtIdentidade->get_text(),
    sSexo, edtTelefone->get_text(), sDtNasc, edtCodEndereco->get_text(),
    edtCodPais->get_text(), edtCodProfissao->get_text());

  if (SalvarDados(ValidaDados(true),
    ConsSQL->Cliente('S', edtCodigo->get_text(),
    "","","","","","","","",""), sSqlUpdate, sSqlInsert, true)) {
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
}

void CfrmCadClientes::on_btnExcluir_clicked() {
  if (ExcluirDados(ValidaDados(false),
    ConsSQL->Cliente('D', edtCodigo->get_text(),
    "","","","","","","","",""))) {
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
}

void CfrmCadClientes::on_btnLimpar_clicked() {
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);
}

void CfrmCadClientes::destroy_() {
  frmPrincipal->tlbCliente->set_sensitive(true);
  frmPrincipal->mnuCadClientes->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmCadClientes::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}

void CfrmCadClientes::InformaLimpaDados(bool bInformar)
{
  if (bInformar) {
    edtEmail->set_text(lstRegistros.col[2][nLinhaRegistro]);
    edtIdentidade->set_text(lstRegistros.col[3][nLinhaRegistro]);
    if (lstRegistros.col[4][nLinhaRegistro] == "M")
      rbMasculino->set_active(true);
    else
      rbFeminino->set_active(true);
    edtTelefone->set_text(lstRegistros.col[5][nLinhaRegistro]);
    edtDtNasc->set_text(lstRegistros.col[6][nLinhaRegistro].substr(0, 10));
    edtCodEndereco->set_text(lstRegistros.col[7][nLinhaRegistro]);
    edtLogradouro->set_text(lstRegistros.col[8][nLinhaRegistro]);
    edtBairro->set_text(lstRegistros.col[9][nLinhaRegistro]);
    edtCep->set_text(lstRegistros.col[10][nLinhaRegistro]);
    edtCidade->set_text(lstRegistros.col[11][nLinhaRegistro]);
    edtEstado->set_text(lstRegistros.col[12][nLinhaRegistro]);
    edtCodPais->set_text(lstRegistros.col[13][nLinhaRegistro]);
    edtPais->set_text(lstRegistros.col[14][nLinhaRegistro]);
    edtCodProfissao->set_text(lstRegistros.col[15][nLinhaRegistro]);
    edtProfissao->set_text(lstRegistros.col[16][nLinhaRegistro]);
  } else {
    edtEmail->set_text("");
    edtIdentidade->set_text("");
    rbMasculino->set_active(true);
    edtTelefone->set_text("");
    edtDtNasc->set_text(Rotinas->retDataHoraStr(true, false));
    edtCodEndereco->set_text("");
    edtLogradouro->set_text("");
    edtBairro->set_text("");
    edtCep->set_text("");
    edtCidade->set_text("");
    edtEstado->set_text("");
    edtCodPais->set_text("");
    edtPais->set_text("");
    edtCodProfissao->set_text("");
    edtProfissao->set_text("");
  }
}

void CfrmCadClientes::HabilitaDados(bool bHabilita) {
  edtEmail->set_sensitive(bHabilita);
  edtIdentidade->set_sensitive(bHabilita);
  grpSexo->set_sensitive(bHabilita);
  edtTelefone->set_sensitive(bHabilita);
  edtDtNasc->set_sensitive(bHabilita);
  grpEndereco->set_sensitive(bHabilita);
  edtCodPais->set_sensitive(bHabilita);
  btnPPais->set_sensitive(bHabilita);
  edtCodProfissao->set_sensitive(bHabilita);
  btnPProfissao->set_sensitive(bHabilita);
}

bool CfrmCadClientes::on_edtDtNasc_focus_out_event(GdkEventFocus *event) {
  if (edtDtNasc->get_text().length() > 0) {
  	if (Rotinas->validaDataHora(edtDtNasc->get_text(), true)==false) {
      Rotinas->MsgDlg(STR_DATINV, Gtk::MESSAGE_ERROR);
      edtDtNasc->set_text(Rotinas->retDataHoraStr(true,false));
      edtDtNasc->grab_focus();
  	}
  }
  return false;
}

bool CfrmCadClientes::on_edtCodEndereco_focus_out_event(GdkEventFocus *event)
{
  Glib::ustring sLogradouro;
  LISTAMSTR ConsCampo;

  if (edtCodEndereco->get_text().length() > 0) {
    sLogradouro = Rotinas->ConsultaCampoDesc(&ConsCampo,
      edtCodEndereco->get_text(), true,
      ConsSQL->Endereco('S',edtCodEndereco->get_text(),
      "","","","",""),STR_ENDNENC);
    if (sLogradouro.length() > 0) {
      edtLogradouro->set_text(sLogradouro);
      edtBairro->set_text(ConsCampo.col[2][0]);
      edtCep->set_text(ConsCampo.col[3][0]);
      edtCidade->set_text(ConsCampo.col[4][0]);
      edtEstado->set_text(ConsCampo.col[5][0]);
    } else {
      edtLogradouro->set_text("");
      edtBairro->set_text("");
      edtCep->set_text("");
      edtCidade->set_text("");
      edtEstado->set_text("");
      edtCodEndereco->grab_focus();
    }
  } else {
    edtLogradouro->set_text("");
    edtBairro->set_text("");
    edtCep->set_text("");
    edtCidade->set_text("");
    edtEstado->set_text("");
  }
  return false;
}

void CfrmCadClientes::on_btnPEndereco_clicked() {
  frmConEnderecos = new CfrmConEnderecos();
	frmConEnderecos->run();
  delete frmConEnderecos;
  edtCodEndereco->set_text(Rotinas_sCodigoSelecionado);
  on_edtCodEndereco_focus_out_event(NULL);
}

bool CfrmCadClientes::on_edtCodPais_focus_out_event(GdkEventFocus *event) {
  Glib::ustring sPais;
  LISTAMSTR ConsCampo;

  if (edtCodPais->get_text().length() > 0) {
    sPais = Rotinas->ConsultaCampoDesc(&ConsCampo,
      edtCodPais->get_text(), false,
      ConsSQL->Pais('S',edtCodPais->get_text(),""),STR_PAISNENC);
    if (sPais.length() > 0)
      edtPais->set_text(sPais);
    else {
      edtCodPais->set_text("");
      edtCodPais->grab_focus();
    }
  } else
    edtPais->set_text("");

  return false;
}

void CfrmCadClientes::on_btnPPais_clicked() {
  frmConPaises = new CfrmConPaises();
	frmConPaises->run();
  delete frmConPaises;
  edtCodPais->set_text(Rotinas_sCodigoSelecionado);
  on_edtCodPais_focus_out_event(NULL);
}

bool CfrmCadClientes::on_edtCodProfissao_focus_out_event(
			      GdkEventFocus *event) {
  Glib::ustring sProfissao;
  LISTAMSTR ConsCampo;

  if (edtCodProfissao->get_text().length() > 0) {
    sProfissao = Rotinas->ConsultaCampoDesc(&ConsCampo,
      edtCodProfissao->get_text(), true,
      ConsSQL->Profissao('S',edtCodProfissao->get_text(),""),STR_PROFNENC);
    if (sProfissao.length() > 0)
      edtProfissao->set_text(sProfissao);
    else {
      edtCodProfissao->set_text("");
      edtCodProfissao->grab_focus();
    }
  } else
    edtProfissao->set_text("");

  return false;
}

void CfrmCadClientes::on_btnPProfissao_clicked() {
  frmConProfissoes = new CfrmConProfissoes();
	frmConProfissoes->run();
  delete frmConProfissoes;
  edtCodProfissao->set_text(Rotinas_sCodigoSelecionado);
  on_edtCodProfissao_focus_out_event(NULL);
}
