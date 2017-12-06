#ifndef CONAUTORES_H
#define CONAUTORES_H

#include "Consultas.h"

class CfrmConAutores : public CfrmConsultas {
  FXDECLARE(CfrmConAutores)

public:
  CfrmConAutores(FXWindow* owner);
  virtual void create();
  virtual ~CfrmConAutores();
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onGridSelected(FXObject*,FXSelector,void* ptr);
  long onGridChanged(FXObject*,FXSelector,void* ptr);

protected:
  CfrmConAutores(){}

private:
  void IniciaControles();
};

extern CfrmConAutores *frmConAutores;

#endif
