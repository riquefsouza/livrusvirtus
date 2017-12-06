#ifndef VENDERLIVROS_H
  #define VENDERLIVROS_H

  #include "resource.h"
  #include "RotinasGlobais.h"

  class CfrmVenderLivros : public Gtk::Window {
  public:
    CfrmVenderLivros();
    ~CfrmVenderLivros();
  private:
    Gtk::Entry * edtDtHrVenda;
    Gtk::Entry * edtCPF;
    Gtk::Entry * edtISBN;
    Gtk::Entry * edtCliente;
    Gtk::Button * btnPCliente;
    Gtk::Entry * edtLivro;
    Gtk::Button * btnPLivro;
    Gtk::Button * btnAdLivros;
    Gtk::TreeView * lstLivros;
    Glib::RefPtr<Gtk::ListStore> LSLivros;
    Gtk::Entry * edtPrecoTotal;
    Gtk::Fixed * fixed1;
    Gtk::Label * labCPF;
    Gtk::Label * labISBN;
    Gtk::Label * labCliente;
    Gtk::Label * labLivro;
    Gtk::Label * labLivros;
    Gtk::ScrolledWindow * scrolledwindow1;
    Glib::RefPtr<Gtk::TreeSelection> selection;
    Gtk::Label * labPrecoTotal;
    Gtk::HButtonBox *hbuttonbox1;
    Gtk::Button * btnVender;
    Gtk::Button * btnLimpar;
    Gtk::Button * btnFechar;
    Gtk::Label * labDtHrVenda;
    gdouble nPrecoTotal;

    bool on_edtCodigo_focus_out_event(GdkEventFocus* event);
    void on_btnVender_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
    void destroy_();
    void LimpaDados();
    bool ValidaDados();
    bool SalvaLista();
    bool on_edtCPF_focus_out_event(GdkEventFocus *event);
    bool on_edtISBN_focus_out_event(GdkEventFocus *event);
    bool on_lstLivros_button_press_event(GdkEventButton *event);
    void on_btnPCliente_clicked();
    void on_btnAdLivros_clicked();
    void on_btnPLivro_clicked();
  };

  extern CfrmVenderLivros * frmVenderLivros;

#endif
