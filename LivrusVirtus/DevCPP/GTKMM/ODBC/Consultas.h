#ifndef CONSULTAS_H
  #define CONSULTAS_H

  #include "resource.h"
  #include "RotinasGlobais.h"

  class CfrmConsultas : public Gtk::Dialog {
  public:
    CfrmConsultas(Glib::ustring sTitulo);
    ~CfrmConsultas();
  protected:
    Gtk::Label * labDescricao;
    Gtk::Entry * edtDescricao;
    Gtk::Button * btnPesquisar;
    Gtk::TreeView * gridConsulta;
    Glib::RefPtr<Gtk::TreeSelection> selection;
    Glib::RefPtr<Gtk::ListStore> gListaGrid;
    Gtk::Label * labRegistros;
    Gtk::Button * btnLimpar;
    Gtk::Button * btnFechar;

    LISTAMSTR lstLinhas;
    int nRegistro;

    void Fecha();
    void LimparDados();
    void PesquisarDados(Glib::ustring sTextoSql,
      Glib::ustring sMensagemErro, int nQtdCols);
    void setLabRegistros(int nLinha);
    void setSelecionado();
  private:
    Gtk::VBox *vbox1;
    Gtk::Fixed *fixed1;
    Gtk::ScrolledWindow *scrolledwindow1;
    Gtk::HBox *hbox1;
    Gtk::Fixed *fixed3;
    Gtk::VBox *vbox2;
    Gtk::Fixed *fixed4;
    Gtk::HButtonBox *hbuttonbox1;
    Glib::ustring sSelecionado;
  };

  extern CfrmConsultas * frmConsultas;

#endif
