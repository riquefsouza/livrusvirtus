#ifndef CONPROFISSOES_H
  #define CONPROFISSOES_H

  #include "resource.h"
  #include "Consultas.h"

  class CfrmConProfissoes : public CfrmConsultas {
  public:
    CfrmConProfissoes();
    ~CfrmConProfissoes();
  private:
    void on_gridConsulta_selection_changed();
    void on_btnPesquisar_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
  };

  extern CfrmConProfissoes * frmConProfissoes;

#endif
