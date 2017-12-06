#ifndef CONCLIENTES_H
  #define CONCLIENTES_H

  #include "resource.h"
  #include "Consultas.h"

  class CfrmConClientes : public CfrmConsultas {
  public:
    CfrmConClientes();
    ~CfrmConClientes();
  private:
    void on_gridConsulta_selection_changed();
    void on_btnPesquisar_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
  };

  extern CfrmConClientes * frmConClientes;

#endif
