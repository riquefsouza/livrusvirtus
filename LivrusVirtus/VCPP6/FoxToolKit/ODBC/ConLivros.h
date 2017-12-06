#ifndef CONLIVROS_H
#define CONLIVROS_H

#include "Consultas.h"

class CfrmConLivros : public CfrmConsultas {
  FXDECLARE(CfrmConLivros)

public:
  CfrmConLivros(FXWindow* owner);
  virtual void create();
  virtual ~CfrmConLivros();
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onGridSelected(FXObject*,FXSelector,void* ptr);
  long onGridChanged(FXObject*,FXSelector,void* ptr);

protected:
  CfrmConLivros(){}

private:
  void IniciaControles();
};

extern CfrmConLivros *frmConLivros;

#endif
