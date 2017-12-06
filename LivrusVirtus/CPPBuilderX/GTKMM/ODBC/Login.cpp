#include "Login.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "xpms/login.xpm"
#include "xpms/livrus.xpm"

CfrmLogin * frmLogin = (CfrmLogin *) NULL;

CfrmLogin::CfrmLogin() : Gtk::Dialog() {

  this->set_title("Login do Sistema");
  this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  this->set_modal(true);
  this->set_resizable(false);
  this->property_destroy_with_parent()=true;
  this->set_icon(Gdk::Pixbuf::create_from_xpm_data(Livrus_xpm));
  this->set_has_separator(false);
  this->set_type_hint(Gdk::WINDOW_TYPE_HINT_DIALOG);

  vbox1 = this->get_vbox();

  hbox1 = manage(new class Gtk::HBox(false, 0));
  vbox1->pack_start(*hbox1, true, true, 0);

  image1 = new Gtk::Image(Gdk::Pixbuf::create_from_xpm_data(login_xpm));
  hbox1->pack_start(*image1, true, true, 0);
  image1->set_size_request(100, 100);

  table1 = manage(new class Gtk::Table(4, 1, false));
  hbox1->pack_start(*table1, true, true, 0);

  labLogin = manage(new class Gtk::Label("Login:"));
  table1->attach(*labLogin, 0, 1, 0, 1, (Gtk::AttachOptions) (Gtk::FILL),
    (Gtk::AttachOptions) (0), 0, 0);
  labLogin->set_alignment(0, 0.5);

  labSenha = manage(new class Gtk::Label("Senha:"));
  table1->attach(*labSenha, 0, 1, 2, 3, (Gtk::AttachOptions) (Gtk::FILL),
    (Gtk::AttachOptions) (0), 0, 0);
  labSenha->set_alignment(0, 0.5);

  edtLogin = manage(new class Gtk::Entry());
  table1->attach (*edtLogin, 0, 1, 1, 2, (Gtk::AttachOptions) (Gtk::SHRINK),
    (Gtk::AttachOptions) (Gtk::SHRINK), 0, 4);
  edtLogin->set_size_request(100, 21);
  edtLogin->set_max_length(10);

  edtSenha = manage(new class Gtk::Entry());
  table1->attach (*edtSenha, 0, 1, 3, 4, (Gtk::AttachOptions) (Gtk::SHRINK),
    (Gtk::AttachOptions) (Gtk::SHRINK), 0, 4);
  edtSenha->set_size_request(100, 21);
  edtSenha->set_max_length(10);
  edtSenha->set_visibility(false);

  hbuttonbox1 = manage(new class Gtk::HButtonBox());
  vbox1->pack_start(*hbuttonbox1, true, true, 0);
  hbuttonbox1->set_layout(Gtk::BUTTONBOX_SPREAD);

  btnLogin = manage(new class Gtk::Button("_Login", true));
  hbuttonbox1->add(*btnLogin);
  btnLogin->set_flags(Gtk::CAN_DEFAULT);

  btnCancelar = manage(new class Gtk::Button("_Cancelar", true));
  hbuttonbox1->add(*btnCancelar);
  btnCancelar->set_flags(Gtk::CAN_DEFAULT);

  show_all_children();
  btnLogin->signal_clicked().connect(SigC::slot(* this,
   & CfrmLogin::on_btnLogin_clicked));
  btnCancelar->signal_clicked().connect(SigC::slot(* this,
   & CfrmLogin::on_btnCancelar_clicked));
}

CfrmLogin::~CfrmLogin() { }

void CfrmLogin::on_btnLogin_clicked() {

  if (Rotinas->ConsultaDados(gConexao,
    ConsSQL->Usuario('S', edtLogin->get_text(), edtSenha->get_text())) ) {

   Rotinas_sUsuarioLogin = edtLogin->get_text();
   Rotinas_sUsuarioSenha = edtSenha->get_text();

   response(Gtk::RESPONSE_YES);
  } else
   Rotinas->MsgDlg(STR_LOGSENINC, Gtk::MESSAGE_ERROR);
}

void CfrmLogin::on_btnCancelar_clicked() {
  response(Gtk::RESPONSE_NO);
}
