#ifndef CADPAISES_H
#define CADPAISES_H

#include "resource.h"
#include "Cadastros.h"

class CfrmCadPaises: public CfrmCadastros {
public:
  CfrmCadPaises();
  ~CfrmCadPaises();
  bool ValidaDados(bool bTodosDados);

private:
  void IniciaControles();
  int handle(int event);

};

extern CfrmCadPaises *frmCadPaises;

#endif
