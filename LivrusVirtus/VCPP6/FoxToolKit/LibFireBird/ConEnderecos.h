#ifndef CONENDERECOS_H
#define CONENDERECOS_H

#include "Consultas.h"

class CfrmConEnderecos : public CfrmConsultas {
  FXDECLARE(CfrmConEnderecos)

public:
  CfrmConEnderecos(FXWindow* owner);
  virtual void create();
  virtual ~CfrmConEnderecos();
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onGridSelected(FXObject*,FXSelector,void* ptr);
  long onGridChanged(FXObject*,FXSelector,void* ptr);

protected:
  CfrmConEnderecos(){}

private:
  void IniciaControles();
};

extern CfrmConEnderecos *frmConEnderecos;

#endif
