#ifndef CADCLIENTES_H
  #define CADCLIENTES_H

  #include "resource.h"
  #include "Cadastros.h"

  class CfrmCadClientes : public CfrmCadastros {
  public:
    CfrmCadClientes();
    ~CfrmCadClientes();
  private:
    Gtk::Label * labEmail;
    Gtk::Label * labIdentidade;
    Gtk::Label * labTelefone;
    Gtk::Label * labDtNascimento;
    Gtk::Fixed * fixed2;
    Gtk::Label * labSexo;
    Gtk::Label * labProfissao;
    Gtk::Label * labPais;
    Gtk::Fixed * fixed3;
    Gtk::Label * labLogradouro;
    Gtk::Label * labBairro;
    Gtk::Label * labCep;
    Gtk::Label * labCidade;
    Gtk::Label * labEstado;
    Gtk::Label * labEndereco;
    Gtk::Entry * edtIdentidade;
    Gtk::Entry * edtEmail;
    Gtk::Entry * edtTelefone;
    Gtk::Entry * edtDtNasc;
    Gtk::Frame * grpSexo;
    Gtk::RadioButton * rbMasculino;
    Gtk::RadioButton * rbFeminino;
    Gtk::RadioButton::Group rbGrupo;
    Gtk::Entry * edtCodPais;
    Gtk::Entry * edtPais;
    Gtk::Entry * edtCodProfissao;
    Gtk::Entry * edtProfissao;
    Gtk::Entry * edtCodEndereco;
    Gtk::Entry * edtLogradouro;
    Gtk::Entry * edtBairro;
    Gtk::Entry * edtCep;
    Gtk::Entry * edtCidade;
    Gtk::Entry * edtEstado;
    Gtk::Frame * grpEndereco;
    Gtk::Button * btnPEndereco;
    Gtk::Button * btnPPais;
    Gtk::Button * btnPProfissao;

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
    bool on_edtDtNasc_focus_out_event(GdkEventFocus *event);
    bool on_edtCodEndereco_focus_out_event(GdkEventFocus *event);
    void on_btnPEndereco_clicked();
    bool on_edtCodPais_focus_out_event(GdkEventFocus *event);
    void on_btnPPais_clicked();
    bool on_edtCodProfissao_focus_out_event(GdkEventFocus *event);
    void on_btnPProfissao_clicked();
  };

  extern CfrmCadClientes * frmCadClientes;

#endif
