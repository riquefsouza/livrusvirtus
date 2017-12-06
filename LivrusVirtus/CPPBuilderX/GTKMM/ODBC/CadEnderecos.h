#ifndef CADENDERECOS_H
  #define CADENDERECOS_H

  #include "resource.h"
  #include "Cadastros.h"

  class CfrmCadEnderecos : public CfrmCadastros {
  public:
    CfrmCadEnderecos();
    ~CfrmCadEnderecos();
  private:
    Gtk::Label * labCidade;
    Gtk::Label * labCep;
    Gtk::Label * labBairro;
    Gtk::Label * labEstado;
    Gtk::Entry * edtBairro;
    Gtk::Entry * edtCep;
    Gtk::Entry * edtCidade;
    Gtk::Combo * cmbEstado;
    Gtk::Entry * cmbEstadoEntrada;
    std::vector<Glib::ustring> listCmbEstado;

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
    void AtribuiEstado(Glib::ustring sEstado);
  };

  extern CfrmCadEnderecos * frmCadEnderecos;

#endif
