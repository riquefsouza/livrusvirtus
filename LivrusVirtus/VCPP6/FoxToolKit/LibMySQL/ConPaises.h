#ifndef CONPAISES_H
#define CONPAISES_H

#include "Consultas.h"

class CfrmConPaises : public CfrmConsultas {
  FXDECLARE(CfrmConPaises)

public:
  CfrmConPaises(FXWindow* owner);
  virtual void create();
  virtual ~CfrmConPaises();
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onGridSelected(FXObject*,FXSelector,void* ptr);
  long onGridChanged(FXObject*,FXSelector,void* ptr);

protected:
  CfrmConPaises(){}

private:
  void IniciaControles();
};

extern CfrmConPaises *frmConPaises;

#endif
