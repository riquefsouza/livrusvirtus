#ifndef CADPAISES_H
  #define CADPAISES_H

  #include "resource.h"
  #include "Cadastros.h"

  class CfrmCadPaises : public CfrmCadastros {
  public:
    CfrmCadPaises();
    ~CfrmCadPaises();
  private:
    bool ValidaDados(bool bTodosDados);
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

  extern CfrmCadPaises * frmCadPaises;

#endif
