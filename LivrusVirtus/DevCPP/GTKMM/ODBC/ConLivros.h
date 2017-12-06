#ifndef CONLIVROS_H
  #define CONLIVROS_H

  #include "resource.h"
  #include "Consultas.h"

  class CfrmConLivros : public CfrmConsultas {
  public:
    CfrmConLivros();
    ~CfrmConLivros();
  private:
    void on_gridConsulta_selection_changed();
    void on_btnPesquisar_clicked();
    void on_btnLimpar_clicked();
    void on_btnFechar_clicked();
  };

  extern CfrmConLivros * frmConLivros;

#endif
