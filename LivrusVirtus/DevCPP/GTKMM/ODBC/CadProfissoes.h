#ifndef CADPROFISSOES_H
  #define CADPROFISSOES_H

  #include "resource.h"
  #include "Cadastros.h"

  class CfrmCadProfissoes : public CfrmCadastros {
  public:
    CfrmCadProfissoes();
    ~CfrmCadProfissoes();
  private:
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
  };

  extern CfrmCadProfissoes * frmCadProfissoes;

#endif
