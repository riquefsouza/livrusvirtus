#ifndef CADPAISES_H
#define CADPAISES_H

#include "Cadastros.h"

class CfrmCadPaises : public CfrmCadastros {
  FXDECLARE(CfrmCadPaises)

public:
  CfrmCadPaises(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmCadPaises();
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
  CfrmCadPaises(){}
  void IniciaControles();
  FXbool ValidaDados(FXbool bTodosDados);
};

extern CfrmCadPaises *frmCadPaises;

#endif
