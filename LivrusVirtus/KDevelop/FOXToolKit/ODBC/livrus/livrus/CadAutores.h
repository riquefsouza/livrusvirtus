#ifndef CADAUTORES_H
#define CADAUTORES_H

#include "Cadastros.h"

class CfrmCadAutores : public CfrmCadastros {
  FXDECLARE(CfrmCadAutores)

public:
  CfrmCadAutores(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmCadAutores();
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
  CfrmCadAutores(){}
  void IniciaControles();
  FXbool ValidaDados(FXbool bTodosDados);
};

extern CfrmCadAutores *frmCadAutores;

#endif
