#ifndef SOBRE_H
  #define SOBRE_H

  #include "resource.h"

  class CfrmSobre : public Gtk::Dialog {
  public:
    CfrmSobre();
    ~CfrmSobre();
  private:
    Gtk::Button * btnOk;
    Gtk::Image * image1;
    Gtk::Label * label3;
    Gtk::VBox * vbox1;
    Gtk::VBox * vbox3;
    Gtk::Label * label2;
    Gtk::Frame * frame1;
    Gtk::Alignment * alignment1;
  };

  extern CfrmSobre * frmSobre;

#endif
