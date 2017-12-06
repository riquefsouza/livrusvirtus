#ifndef CADEDITORAS_H
#define CADEDITORAS_H

#include "resource.h"
#include "Cadastros.h"

class CfrmCadEditoras: public CfrmCadastros {
public:
  CfrmCadEditoras();
  ~CfrmCadEditoras();
  bool ValidaDados(bool bTodosDados);

private:
  void IniciaControles();
  int handle(int event);

};

extern CfrmCadEditoras *frmCadEditoras;

#endif
