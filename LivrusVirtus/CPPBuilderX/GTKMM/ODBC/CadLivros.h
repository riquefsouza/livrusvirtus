#ifndef CADLIVROS_H
  #define CADLIVROS_H

  #include "resource.h"
  #include "Cadastros.h"
  #include "RotinasGlobais.h"

  class CfrmCadLivros : public CfrmCadastros {
  public:
    CfrmCadLivros();
    ~CfrmCadLivros();
  private:
    Gtk::Entry * edtCodEditora;
    Gtk::Entry * edtEditora;
    Gtk::SpinButton * edtEdicao;
    Gtk::Button * btnPEditora;
    Gtk::SpinButton * edtAnoPubli;
    Gtk::SpinButton * edtVolume;
    Gtk::SpinButton * edtNPaginas;
    Gtk::SpinButton * edtQtdEstoque;
    Gtk::Entry * edtCodAssunto;
    Gtk::Entry * edtAssunto;
    Gtk::Button * btnPAssunto;
    Gtk::Button * btnAdAssuntos;
    Gtk::Entry * edtPreco;
    Gtk::Entry * edtCodAutor;
    Gtk::Entry * edtAutor;
    Gtk::Button * btnPAutor;
    Gtk::Button * btnAdAutores;
    Gtk::TreeView * lstAssuntos;
    Glib::RefPtr<Gtk::ListStore> LSAssuntos;
    Gtk::TreeView * lstAutores;
    Glib::RefPtr<Gtk::ListStore> LSAutores;
    Gtk::Combo * cmbIdioma;
    Gtk::Entry * cmbIdiomaEntrada;
    std::vector<Glib::ustring> listCmbIdioma;
    Gtk::Adjustment * edtEdicao_adj;
    Gtk::Label * labEdicao;
    Gtk::Label * labEditora;
    Gtk::Adjustment * edtAnoPubli_adj;
    Gtk::Label * labIdioma;
    Gtk::Label * labAnoPubli;
    Gtk::Adjustment * edtVolume_adj;
    Gtk::Label * labVolume;
    Gtk::Label * labNPaginas;
    Gtk::Adjustment * edtNPaginas_adj;
    Gtk::Label * labAssunto;
    Gtk::Label * labPreco;
    Gtk::Label * labQtdEstoque;
    Gtk::Adjustment * edtQtdEstoque_adj;
    Gtk::Label * labAutor;
    Gtk::ScrolledWindow * scrolledwindow1;
    Gtk::ScrolledWindow * scrolledwindow2;
    Glib::RefPtr<Gtk::TreeSelection> selection;
    LISTASTR slIdiomas;

    bool ValidaDados(bool bTodosDados);
    bool on_edtCodigo_focus_out_event(GdkEventFocus* event);
    void on_btnNovo_clicked();
    void on_btnPesquisar_clicked();
    void on_btnAnterior_clicked();
    void on_btnProximo_clicked();
    void on_btnSalvar_clicked();
    void on_btnExcluir_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
    void destroy_();
    void InformaLimpaDados(bool bInformar);
    void HabilitaDados(bool bHabilita);
    void AdicionaCombo();
    void SalvaLista(char sOpcao);
    void on_btnPEditora_clicked();
    void on_btnPAssunto_clicked();
    void on_btnAdAssuntos_clicked();
    void on_btnPAutor_clicked();
    void on_btnAdAutores_clicked();
    bool on_edtCodEditora_focus_out_event(GdkEventFocus *event);
    bool on_edtPreco_focus_out_event(GdkEventFocus *event);
    bool on_edtCodAssunto_focus_out_event(GdkEventFocus *event);
    bool on_edtCodAutor_focus_out_event(GdkEventFocus *event);
    void AtribuiIdioma(Glib::ustring sIdioma);
    int retIdioma(Glib::ustring sIdioma);
    bool on_lstAssuntos_button_press_event(GdkEventButton *event);
    bool on_lstAutores_button_press_event(GdkEventButton *event);

  };

  extern CfrmCadLivros * frmCadLivros;

#endif
