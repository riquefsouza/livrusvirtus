#ifndef LOGIN_H
#define LOGIN_H

#include "resource.h"

class CfrmLogin : public Fl_Double_Window {
public:
  CfrmLogin();
  ~CfrmLogin();
  Fl_Input *edtLogin;
  Fl_Input *edtSenha;

protected:
  Fl_Box *box1;
  Fl_Return_Button *btnLogin;
  Fl_Button *btnCancelar;

private:
  void IniciaControles();
};

extern CfrmLogin *frmLogin;

#endif
