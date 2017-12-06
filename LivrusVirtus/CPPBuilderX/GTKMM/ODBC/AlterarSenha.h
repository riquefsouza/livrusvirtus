#ifndef ALTERARSENHA_H
  #define ALTERARSENHA_H

  #include "resource.h"

  class CfrmAlterarSenha : public Gtk::Window {
  public:
    CfrmAlterarSenha();
    ~CfrmAlterarSenha();
  private:
    Gtk::Entry  * edtLogin;
    Gtk::Entry  * edtSenhaAtual;
    Gtk::Entry  * edtNovaSenha;
    Gtk::Entry  * edtConfirmaSenha;

    Gtk::VBox * vbox1;
    Gtk::Fixed * fixed1;
    Gtk::Label * labLogin;
    Gtk::Label * labSenhaAtual;
    Gtk::Label * labNovaSenha;
    Gtk::Label * labConfirmaSenha;
    Gtk::HButtonBox * hbuttonbox1;
    Gtk::Button * btnSalvar;
    Gtk::Button * btnLimpar;
    Gtk::Button * btnFechar;

    void destroy_();
    void on_btnSalvar_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
    bool ValidaDados();
  };

  extern CfrmAlterarSenha * frmAlterarSenha;
#endif
