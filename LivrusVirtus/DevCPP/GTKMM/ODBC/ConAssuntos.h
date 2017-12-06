#ifndef CONASSUNTOS_H
  #define CONASSUNTOS_H

  #include "resource.h"
  #include "Consultas.h"

  class CfrmConAssuntos : public CfrmConsultas {
  public:
    CfrmConAssuntos();
    ~CfrmConAssuntos();
  private:
    void on_gridConsulta_selection_changed();
    void on_btnPesquisar_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
  };

  extern CfrmConAssuntos * frmConAssuntos;

#endif
