#ifndef ALTERARSENHA_H
#define ALTERARSENHA_H

#include "resource.h"

class CfrmAlterarSenha : public Fl_Double_Window {
public:
  Fl_Input *edtLogin;
  Fl_Input *edtSenhaAtual;
  Fl_Input *edtNovaSenha;
  Fl_Input *edtConfirmaSenha;

  CfrmAlterarSenha();
  ~CfrmAlterarSenha();
  bool ValidaDados();

protected:
  Fl_Button *btnSalvar;
  Fl_Button *btnLimpar;
  Fl_Button *btnFechar;

private:
  void IniciaControles();
  int handle(int event);
};

extern CfrmAlterarSenha *frmAlterarSenha;

#endif
