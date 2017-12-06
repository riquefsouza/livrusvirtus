#include "Sobre.h"
#include "RotinasGlobais.h"
#include "xpms/livrusvirtus.xpm"
#include "xpms/livrus.xpm"

CfrmSobre * frmSobre = (CfrmSobre *) NULL;

CfrmSobre::CfrmSobre() : Gtk::Dialog() {
  this->set_title("Sobre o Sistema");
  this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  this->set_modal(true);
  this->set_resizable(false);
  this->set_icon(Gdk::Pixbuf::create_from_xpm_data(Livrus_xpm));
  this->set_type_hint(Gdk::WINDOW_TYPE_HINT_DIALOG);

  vbox1 = this->get_vbox();

  frame1 = manage(new class Gtk::Frame());
  vbox1->pack_start(*frame1, true, true, 0);
  frame1->set_border_width(8);
  frame1->set_label_align(0, 0);

  alignment1 = manage(new class Gtk::Alignment(0.5, 0.5, 1, 1));
  frame1->add(*alignment1);

  vbox3 = manage(new class Gtk::VBox(false, 0));
  alignment1->add(*vbox3);

  image1 = new Gtk::Image(Gdk::Pixbuf::create_from_xpm_data(livrusvirtus_xpm));
  vbox3->pack_start(*image1, true, true, 0);

  label2 = manage(new class Gtk::Label(Rotinas->retUTF8("Versão 1.0.0")));
  vbox3->pack_start(*label2, false, false, 2);
  label2->set_justify(Gtk::JUSTIFY_RIGHT);
  label2->set_alignment(1, 0.5);

  label2 = manage(new class Gtk::Label(Rotinas->retUTF8("Versão 1.0.0")));

  label3 = manage(new class Gtk::Label(
    Rotinas->retUTF8("Todos os direitos reservados para\n" \
    "Henrique F. de Souza\n" \
    "Versão Programada no C++BuilderX /\n" \
    "Glade 2 usando GTKMM")));

  vbox3->pack_start(*label3, false, false, 0);
  label3->set_justify(Gtk::JUSTIFY_CENTER);
  label3->set_line_wrap(true);

  this->get_action_area()->set_layout(Gtk::BUTTONBOX_SPREAD);

  btnOk = manage(new class Gtk::Button(Gtk::StockID("gtk-ok")));
  this->add_action_widget(*btnOk, Gtk::RESPONSE_OK);
  btnOk->set_flags(Gtk::CAN_DEFAULT);

  show_all_children();
}

CfrmSobre::~CfrmSobre() { }
