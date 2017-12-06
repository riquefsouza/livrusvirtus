#ifndef CONPAISES_H
  #define CONPAISES_H

  #include "resource.h"
  #include "Consultas.h"

  class CfrmConPaises : public CfrmConsultas {
  public:
    CfrmConPaises();
    ~CfrmConPaises();
  private:
    void on_gridConsulta_selection_changed();
    void on_btnPesquisar_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
  };

  extern CfrmConPaises * frmConPaises;

#endif
