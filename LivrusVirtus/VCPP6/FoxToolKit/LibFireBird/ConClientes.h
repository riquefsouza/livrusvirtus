#ifndef CONCLIENTES_H
#define CONCLIENTES_H

#include "Consultas.h"

class CfrmConClientes : public CfrmConsultas {
  FXDECLARE(CfrmConClientes)

public:
  CfrmConClientes(FXWindow* owner);
  virtual void create();
  virtual ~CfrmConClientes();
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onGridSelected(FXObject*,FXSelector,void* ptr);
  long onGridChanged(FXObject*,FXSelector,void* ptr);

protected:
  CfrmConClientes(){}

private:
  void IniciaControles();
};

extern CfrmConClientes *frmConClientes;

#endif
