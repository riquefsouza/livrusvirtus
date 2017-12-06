#ifndef CADENDERECOS_H
#define CADENDERECOS_H

#include "Cadastros.h"

class CfrmCadEnderecos : public CfrmCadastros {
  FXDECLARE(CfrmCadEnderecos)

public:
  CfrmCadEnderecos(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmCadEnderecos();
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
  FXVerticalFrame *frame9;
  FXHorizontalFrame *frame10;
  FXVerticalFrame *frame11;
  FXVerticalFrame *frame12;
  FXVerticalFrame *frame13;
  FXLabel *labBairro;
  FXTextField *edtBairro;
  FXLabel *labCEP;
  FXTextField *edtCEP;
  FXLabel *labCidade;
  FXTextField *edtCidade;
  FXLabel *labEstado;
  FXComboBox *cmbEstado;

private:
  CfrmCadEnderecos(){}
  void IniciaControles();
  FXbool ValidaDados(FXbool bTodosDados);
  void InformaLimpaDados(FXbool bInformar);
  void HabilitaDados(FXbool bHabilita);
  void AdicionaCombo();
};

extern CfrmCadEnderecos *frmCadEnderecos;

#endif
