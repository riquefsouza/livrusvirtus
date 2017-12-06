#ifndef CADASTROS_H
  #define CADASTROS_H

  #include "resource.h"
  #include "RotinasGlobais.h"

  class CfrmCadastros : public Gtk::Window {
  public:
    CfrmCadastros(bool bIniciaBotoes, Glib::ustring sTitulo);
    ~CfrmCadastros();
  protected:
    Gtk::Fixed * fixed1;
    Gtk::Label * labCodigo;
    Gtk::Entry * edtCodigo;
    Gtk::Button * btnNovo;
    Gtk::Label * labDescricao;
    Gtk::Entry * edtDescricao;
    Gtk::Button * btnPesquisar;
    Gtk::Button * btnAnterior;
    Gtk::Button * btnProximo;
    Gtk::Button * btnSalvar;
    Gtk::Button * btnExcluir;
    Gtk::Button * btnLimpar;
    Gtk::Button * btnFechar;

    LISTAMSTR lstRegistros;
    int nLinhaRegistro;

    void IniciaBotoes(int nX1, int nY1, int nX2, int nY2);
    void btnNovoClick();
    void NovoDado(Glib::ustring sTextoSql);
    void btnLimparClick();
    bool ExcluirDados(bool bValidaDados, Glib::ustring sTextoSql);
    bool PesquisarDados(Glib::ustring sTextoSql, Glib::ustring sMensagemErro);
    bool registroAnterior();
    bool registroProximo();
    bool SalvarDados(bool bValidaDados, Glib::ustring sTextoSql,
      Glib::ustring sTextoUpdate, Glib::ustring sTextoInsert,
      bool bLimparDados);
    void ValidaCodigo();
  private:
    void InformaLimpaDados(bool bInformar);
    void HabilitaDados(bool bHabilita);
  };

  extern CfrmCadastros * frmCadastros;

#endif
