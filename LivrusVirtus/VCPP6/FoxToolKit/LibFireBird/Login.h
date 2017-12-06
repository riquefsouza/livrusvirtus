#ifndef LOGIN_H
#define LOGIN_H

class CfrmLogin : public FXDialogBox {
  FXDECLARE(CfrmLogin)

public:
  enum { ID_FRMLOGIN_BTNLOGIN = FXMainWindow::ID_LAST,
  ID_FRMLOGIN_BTNCANCELAR };

  CfrmLogin(FXApp* owner);
  virtual void create();
  virtual ~CfrmLogin();
  long onBtnLogin(FXObject*,FXSelector,void*);
  long onBtnCancelar(FXObject*,FXSelector,void*);
  long onClose(FXObject*,FXSelector,void*);

protected:
  FXHorizontalFrame *frame1;
  FXHorizontalFrame *frameBotoes;
  FXHorizontalFrame *frame2;
  FXVerticalFrame *frame3;
  FXIcon   *bmpLoginIcon;
  FXLabel  *bmpLogin;
  FXLabel  *labLogin;
  FXTextField *edtLogin;
  FXLabel *labSenha;
  FXTextField *edtSenha;
  FXButton *btnLogin;
  FXButton *btnCancelar;

private:
	FXbool bFechar;
  CfrmLogin(){}

  void IniciaControles();
};

extern CfrmLogin *frmLogin;

#endif
