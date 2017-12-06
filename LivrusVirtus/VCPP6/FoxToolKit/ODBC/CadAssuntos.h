#ifndef CADASSUNTOS_H
#define CADASSUNTOS_H

#include "Cadastros.h"

class CfrmCadAssuntos : public CfrmCadastros {
  FXDECLARE(CfrmCadAssuntos)

public:
  CfrmCadAssuntos(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmCadAssuntos();
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
  CfrmCadAssuntos(){}
  void IniciaControles();
  FXbool ValidaDados(FXbool bTodosDados);
};

extern CfrmCadAssuntos *frmCadAssuntos;

#endif
