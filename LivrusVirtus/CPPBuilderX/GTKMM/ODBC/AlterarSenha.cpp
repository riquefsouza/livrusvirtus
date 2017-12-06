#include "AlterarSenha.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "xpms/livrus.xpm"

CfrmAlterarSenha * frmAlterarSenha = (CfrmAlterarSenha *) NULL;

CfrmAlterarSenha::CfrmAlterarSenha() : Gtk::Window(Gtk::WINDOW_TOPLEVEL) {
  this->set_icon(Gdk::Pixbuf::create_from_xpm_data(Livrus_xpm));
  this->set_position(Gtk::WIN_POS_CENTER);
  this->set_title(Rotinas->retUTF8("Alteração de senha"));
  this->set_resizable(false);
  this->property_destroy_with_parent()=true;

  vbox1 = manage(new class Gtk::VBox(false, 0));
  this->add(*vbox1);

  fixed1 = manage(new class Gtk::Fixed());
  vbox1->pack_start(*fixed1, true, true, 0);
  fixed1->set_size_request(280, 105);

  edtLogin = manage(new class Gtk::Entry());
  fixed1->put(*edtLogin, 8, 24);
  edtLogin->set_size_request(100, 24);
  #ifdef G_OS_WIN32
    edtLogin->set_sensitive(false);
  #else
    edtLogin->unset_flags(Gtk::CAN_FOCUS);
  #endif

  labLogin = manage(new class Gtk::Label("Login:"));
  fixed1->put(*labLogin, 8, 8);
  labLogin->set_size_request(48, 16);
  labLogin->set_alignment(0, 0.5);

  edtSenhaAtual = manage(new class Gtk::Entry());
  fixed1->put(*edtSenhaAtual, 114, 24);
  edtSenhaAtual->set_size_request(100, 24);
  edtSenhaAtual->set_max_length(10);
  edtSenhaAtual->set_visibility(false);

  labSenhaAtual = manage(new class Gtk::Label("Senha atual:"));
  fixed1->put(*labSenhaAtual, 114, 8);
  labSenhaAtual->set_size_request(88, 16);
  labSenhaAtual->set_alignment(0, 0.5);

  edtNovaSenha = manage(new class Gtk::Entry());
  fixed1->put(*edtNovaSenha, 8, 72);
  edtNovaSenha->set_size_request(100, 24);
  edtNovaSenha->set_max_length (10);
  edtNovaSenha->set_visibility(false);

  edtConfirmaSenha = manage(new class Gtk::Entry());
  fixed1->put(*edtConfirmaSenha, 114, 72);
  edtConfirmaSenha->set_size_request (100, 24);
  edtConfirmaSenha->set_max_length(10);
  edtConfirmaSenha->set_visibility(false);

  labNovaSenha = manage(new class Gtk::Label("Nova senha:"));
  fixed1->put(*labNovaSenha, 8, 56);
  labNovaSenha->set_size_request(96, 16);
  labNovaSenha->set_alignment(0, 0.5);

  labConfirmaSenha = manage(new class Gtk::Label("Confirma senha:"));
  fixed1->put(*labConfirmaSenha, 114, 56);
  labConfirmaSenha->set_size_request(120, 16);
  labConfirmaSenha->set_alignment(0, 0.5);

  hbuttonbox1 = manage(new class Gtk::HButtonBox());
  vbox1->pack_start(*hbuttonbox1, false, true, 0);
  hbuttonbox1->set_border_width(4);
  hbuttonbox1->set_layout(Gtk::BUTTONBOX_SPREAD);

  btnSalvar = manage(new class Gtk::Button("_Salvar", true));
  hbuttonbox1->add(*btnSalvar);
  btnSalvar->set_flags(Gtk::CAN_DEFAULT);

  btnLimpar = manage(new class Gtk::Button("_Limpar", true));
  hbuttonbox1->add(*btnLimpar);
  btnLimpar->set_flags(Gtk::CAN_DEFAULT);

  btnFechar = manage(new class Gtk::Button("_Fechar", true));
  hbuttonbox1->add(*btnFechar);
  btnFechar->set_flags(Gtk::CAN_DEFAULT);

  show_all_children();

  btnSalvar->signal_clicked().connect(SigC::slot(* this,
   & CfrmAlterarSenha::on_btnSalvar_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmAlterarSenha::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmAlterarSenha::on_btnFechar_clicked));
}

CfrmAlterarSenha::~CfrmAlterarSenha() { }

void CfrmAlterarSenha::destroy_() {
  frmPrincipal->mnuAlterarsenha->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmAlterarSenha::on_btnSalvar_clicked() {
  if (ValidaDados()) {
    if (Rotinas->AtualizaDados(gConexao,
          ConsSQL->Usuario('U', edtLogin->get_text(),
          edtConfirmaSenha->get_text()))) {
      Rotinas->MsgDlg(STR_SENALTSUC, Gtk::MESSAGE_ERROR);
    }
  }
}

void CfrmAlterarSenha::on_btnLimpar_clicked() {
  edtSenhaAtual->set_text("");
  edtNovaSenha->set_text("");
  edtConfirmaSenha->set_text("");
  edtSenhaAtual->grab_focus();
}

void CfrmAlterarSenha::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}

bool CfrmAlterarSenha::ValidaDados() {
  if (edtSenhaAtual->get_text() != Rotinas_sUsuarioSenha) {
     Rotinas->MsgDlg(STR_SENNCSU, Gtk::MESSAGE_ERROR);
     return false;
  }
  if (Rotinas->ValidaCampo(edtNovaSenha->get_text(),STR_NSENNINF)) {
  	  return false;
  }
  if (edtNovaSenha->get_text() != edtConfirmaSenha->get_text()) {
   Rotinas->MsgDlg(STR_NSENNCCON, Gtk::MESSAGE_ERROR);
   return false;
  }
 return true;
}

