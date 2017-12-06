#ifndef CONAUTORES_H
  #define CONAUTORES_H

  #include "resource.h"
  #include "Consultas.h"

  class CfrmConAutores : public CfrmConsultas {
  public:
    CfrmConAutores();
    ~CfrmConAutores();
  private:
    void on_gridConsulta_selection_changed();
    void on_btnPesquisar_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
  };

  extern CfrmConAutores * frmConAutores;

#endif
