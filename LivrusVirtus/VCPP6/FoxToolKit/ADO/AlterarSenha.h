#ifndef ALTERARSENHA_H
#define ALTERARSENHA_H

class CfrmAlterarSenha : public FXMDIChild {
  FXDECLARE(CfrmAlterarSenha)

public:
  enum { ID_FRMALTERARSENHA_BTNSALVAR = FXMDIChild::ID_LAST,
   ID_FRMALTERARSENHA_BTNFECHAR, ID_FRMALTERARSENHA_BTNLIMPAR };

  CfrmAlterarSenha(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmAlterarSenha();
  long onBtnSalvar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onBtnFechar(FXObject*,FXSelector,void*);
  long onClose(FXObject*,FXSelector,void*);

protected:
  FXVerticalFrame *frame;
  FXHorizontalFrame *frameBotoes;

  FXVerticalFrame *frame1;
  FXHorizontalFrame *frame2;
  FXHorizontalFrame *frame3;
  FXVerticalFrame *frame4;
  FXVerticalFrame *frame5;
  FXVerticalFrame *frame6;
  FXVerticalFrame *frame7;

  FXLabel  *labLogin;
  FXLabel  *labNovaSenha;
  FXLabel  *labSenhaAtual;
  FXLabel  *labConfirmarSenha;
  FXTextField *edtLogin;
  FXTextField *edtNovaSenha;
  FXTextField *edtSenhaAtual;
  FXTextField *edtConfirmaSenha;
  FXButton *btnSalvar;
  FXButton *btnLimpar;
  FXButton *btnFechar;

private:
	FXbool bFechar;
  CfrmAlterarSenha(){}
  void IniciaControles();
  FXbool ValidaDados();
};

extern CfrmAlterarSenha *frmAlterarSenha;

#endif
