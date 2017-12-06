#ifndef CONENDERECOS_H
  #define CONENDERECOS_H

  #include "resource.h"
  #include "Consultas.h"

  class CfrmConEnderecos : public CfrmConsultas {
  public:
    CfrmConEnderecos();
    ~CfrmConEnderecos();
  private:
    void on_gridConsulta_selection_changed();
    void on_btnPesquisar_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
  };

  extern CfrmConEnderecos * frmConEnderecos;

#endif
