#ifndef CONASSUNTOS_H
#define CONASSUNTOS_H

#include "Consultas.h"

class CfrmConAssuntos : public CfrmConsultas {
  FXDECLARE(CfrmConAssuntos)

public:
  CfrmConAssuntos(FXWindow* owner);
  virtual void create();
  virtual ~CfrmConAssuntos();
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onGridSelected(FXObject*,FXSelector,void* ptr);
  long onGridChanged(FXObject*,FXSelector,void* ptr);

protected:
  CfrmConAssuntos(){}

private:
  void IniciaControles();
};

extern CfrmConAssuntos *frmConAssuntos;

#endif
