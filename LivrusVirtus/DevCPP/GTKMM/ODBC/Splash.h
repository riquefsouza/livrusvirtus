#ifndef SPLASH_H
  #define SPLASH_H

  #include "resource.h"

  class CfrmSplash : public Gtk::Dialog {
  public:
    CfrmSplash();
    ~CfrmSplash();
  private:
    Gtk::VBox * dialog_vbox1;
    Gtk::Frame * frame1;
    Gtk::Image * xpm_lvirtus;
    void esperaSegundos(gint nSegs);
  };

  extern CfrmSplash * frmSplash;

#endif
