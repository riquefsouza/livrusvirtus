#ifndef CADPROFISSOES_H
#define CADPROFISSOES_H

#include "resource.h"
#include "Cadastros.h"

class CfrmCadProfissoes: public CfrmCadastros {
public:
  CfrmCadProfissoes();
  ~CfrmCadProfissoes();
  bool ValidaDados(bool bTodosDados);

private:
  void IniciaControles();
  int handle(int event);

};

extern CfrmCadProfissoes *frmCadProfissoes;

#endif
