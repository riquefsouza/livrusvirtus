#ifndef CADEDITORAS_H
#define CADEDITORAS_H

#include "Cadastros.h"

class CfrmCadEditoras : public CfrmCadastros {
  FXDECLARE(CfrmCadEditoras)

public:
  CfrmCadEditoras(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmCadEditoras();
  long onBtnNovo(FXObject*,FXSelector,void*);
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnAnterior(FXObject*,FXSelector,void*);
  long onBtnProximo(FXObject*,FXSelector,void*);
  long onBtnSalvar(FXObject*,FXSelector,void*);
  long onBtnExcluir(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onBtnFechar(FXObject*,FXSelector,void*);
  long onClose(FXObject*,FXSelector,void*);

protected:

private:
  CfrmCadEditoras(){}
  void IniciaControles();
  FXbool ValidaDados(FXbool bTodosDados);
};

extern CfrmCadEditoras *frmCadEditoras;

#endif
