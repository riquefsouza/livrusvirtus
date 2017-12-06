#ifndef CONEDITORAS_H
  #define CONEDITORAS_H

  #include "resource.h"
  #include "Consultas.h"

  class CfrmConEditoras : public CfrmConsultas {
  public:
    CfrmConEditoras();
    ~CfrmConEditoras();
  private:
    void on_gridConsulta_selection_changed();
    void on_btnPesquisar_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
  };

  extern CfrmConEditoras * frmConEditoras;

#endif
