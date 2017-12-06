#ifndef LOGIN_H
  #define LOGIN_H

  #include "resource.h"

  class CfrmLogin : public Gtk::Dialog {
  public:
    CfrmLogin();
    ~CfrmLogin();
  private:
    Gtk::Button * btnLogin;
    Gtk::Button * btnCancelar;
    Gtk::Image * image1;
    Gtk::Label * labLogin;
    Gtk::Entry * edtLogin;
    Gtk::Label * labSenha;
    Gtk::Entry * edtSenha;
    Gtk::VBox * vbox1;
    Gtk::HBox * hbox1;
    Gtk::Table * table1;
    Gtk::HButtonBox *hbuttonbox1;

    void on_btnLogin_clicked();
    void on_btnCancelar_clicked();
  };

  extern CfrmLogin * frmLogin;
#endif
