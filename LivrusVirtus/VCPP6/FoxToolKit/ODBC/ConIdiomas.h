#ifndef CONIDIOMAS_H
#define CONIDIOMAS_H

#include "Consultas.h"

class CfrmConIdiomas : public CfrmConsultas {
  FXDECLARE(CfrmConIdiomas)

public:
  CfrmConIdiomas(FXWindow* owner);
  virtual void create();
  virtual ~CfrmConIdiomas();
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onGridSelected(FXObject*,FXSelector,void* ptr);
  long onGridChanged(FXObject*,FXSelector,void* ptr);

protected:
  CfrmConIdiomas(){}

private:
  void IniciaControles();
};

extern CfrmConIdiomas *frmConIdiomas;

#endif
