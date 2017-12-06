#ifndef CONPROFISSOES_H
#define CONPROFISSOES_H

#include "Consultas.h"

class CfrmConProfissoes : public CfrmConsultas {
  FXDECLARE(CfrmConProfissoes)

public:
  CfrmConProfissoes(FXWindow* owner);
  virtual void create();
  virtual ~CfrmConProfissoes();
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onGridSelected(FXObject*,FXSelector,void* ptr);
  long onGridChanged(FXObject*,FXSelector,void* ptr);

protected:
  CfrmConProfissoes(){}

private:
  void IniciaControles();
};

extern CfrmConProfissoes *frmConProfissoes;

#endif
