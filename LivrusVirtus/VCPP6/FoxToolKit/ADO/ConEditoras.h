#ifndef CONEDITORAS_H
#define CONEDITORAS_H

#include "Consultas.h"

class CfrmConEditoras : public CfrmConsultas {
  FXDECLARE(CfrmConEditoras)

public:
  CfrmConEditoras(FXWindow* owner);
  virtual void create();
  virtual ~CfrmConEditoras();
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onGridSelected(FXObject*,FXSelector,void* ptr);
  long onGridChanged(FXObject*,FXSelector,void* ptr);

protected:
  CfrmConEditoras(){}

private:
  void IniciaControles();
};

extern CfrmConEditoras *frmConEditoras;

#endif
