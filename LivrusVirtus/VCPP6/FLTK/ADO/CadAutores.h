#ifndef CADAUTORES_H
#define CADAUTORES_H

#include "resource.h"
#include "Cadastros.h"

class CfrmCadAutores: public CfrmCadastros {
public:
  CfrmCadAutores();
  ~CfrmCadAutores();
  bool ValidaDados(bool bTodosDados);

private:
  void IniciaControles();
  int handle(int event);

};

extern CfrmCadAutores *frmCadAutores;

#endif
