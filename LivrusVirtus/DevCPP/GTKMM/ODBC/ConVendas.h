#ifndef CONVENDAS_H
  #define CONVENDAS_H

  #include "resource.h"
  #include "RotinasGlobais.h"

  class CfrmConVendas : public Gtk::Window {
  public:
    CfrmConVendas();
    ~CfrmConVendas();
  private:
    Gtk::Entry * edtDtHrVenda;
    Gtk::Entry * edtCPF;
    Gtk::Entry * edtCliente;
    Gtk::Entry * edtISBN;
    Gtk::Entry * edtLivro;
    Gtk::TreeView * gridConsulta;
    Glib::RefPtr<Gtk::ListStore> LSVendas;
    Gtk::Label * labRegistros;
    Gtk::Entry * edtPrecoTotal;
    Gtk::VBox * vbox1;
    Gtk::Fixed * fixed1;
    Gtk::Label * labDtHrVenda;
    Gtk::Button * btnPesquisar;
    Gtk::Label * labCPF;
    Gtk::Label * labCliente;
    Gtk::Button * btnPCliente;
    Gtk::Label * labISBN;
    Gtk::Label * labLivro;
    Gtk::Button * btnPLivro;
    Gtk::ScrolledWindow * scrolledwindow1;
    Glib::RefPtr<Gtk::TreeSelection> selection;
    Gtk::HBox *hbox1;
    Gtk::VBox *vbox5;
    Gtk::Fixed * fixed4;
    Gtk::Fixed * fixed5;
    Gtk::VBox *vbox2;
    Gtk::Fixed * fixed3;
    Gtk::Label * labPrecoTotal;
    Gtk::HButtonBox *hbuttonbox1;
    Gtk::Button * btnLimpar;
    Gtk::Button * btnFechar;
    LISTAMSTR lstLinVendas;

    bool on_edtDtHrVenda_focus_out_event(GdkEventFocus* event);
    bool on_edtCPF_focus_out_event(GdkEventFocus* event);
    bool on_edtISBN_focus_out_event(GdkEventFocus* event);
    void on_btnPesquisar_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
    void destroy_();
    Glib::ustring ConsVenda(char sOpcao);
    void on_btnPCliente_clicked();
    void on_btnPLivro_clicked();
    void setLabRegistros(int nLinha);
    void on_gridConsulta_selection_changed();
  };

  extern CfrmConVendas * frmConVendas;

#endif
