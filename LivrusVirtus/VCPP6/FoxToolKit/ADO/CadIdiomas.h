#ifndef CADIDIOMAS_H
#define CADIDIOMAS_H

#include "Cadastros.h"

class CfrmCadIdiomas : public CfrmCadastros {
  FXDECLARE(CfrmCadIdiomas)

public:
  CfrmCadIdiomas(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmCadIdiomas();
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
  CfrmCadIdiomas(){}
  void IniciaControles();
  FXbool ValidaDados(FXbool bTodosDados);
};

extern CfrmCadIdiomas *frmCadIdiomas;

#endif
