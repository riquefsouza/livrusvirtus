#include "Splash.h"
#include "xpms/livrusvirtus.xpm"

CfrmSplash * frmSplash = (CfrmSplash *) NULL;

CfrmSplash::CfrmSplash() : Gtk::Dialog() {
  set_size_request(-1, 60);
  set_border_width(1);
  set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  set_modal(true);
  set_resizable(false);
  set_decorated(false);
  set_type_hint(Gdk::WINDOW_TYPE_HINT_DIALOG);
  set_has_separator(false);

  dialog_vbox1 = this->get_vbox();
  dialog_vbox1->show();

  frame1 = NULL;
  frame1->show();
  dialog_vbox1->pack_start(* frame1, true, true, 0);
  frame1->set_label_align(0, 0);

  xpm_lvirtus = new
   Gtk::Image(Gdk::Pixbuf::create_from_xpm_data(livrusvirtus_xpm));
  add(* xpm_lvirtus);
  xpm_lvirtus->show();
}

CfrmSplash::~CfrmSplash() { }

void CfrmSplash::esperaSegundos(gint nSegs) {
  Glib::Timer * gTimer;
  gulong nMicroSegundos = nSegs * 1000;
  gdouble nSegundos;

  gTimer = new Glib::Timer();
  gTimer->start();

  while (true) {
    nSegundos = gTimer->elapsed(nMicroSegundos);
    //g_print("segs = %f\n", nSegundos);
    if (nSegundos > nSegs) {
      gTimer->stop();
      break;
    }
  }
}
