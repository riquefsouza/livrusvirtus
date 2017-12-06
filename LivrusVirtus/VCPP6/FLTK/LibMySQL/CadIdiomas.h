#ifndef CADIDIOMAS_H
#define CADIDIOMAS_H

#include "resource.h"
#include "Cadastros.h"

class CfrmCadIdiomas: public CfrmCadastros {
public:
  CfrmCadIdiomas();
  ~CfrmCadIdiomas();
  bool ValidaDados(bool bTodosDados);

private:
  void IniciaControles();
  int handle(int event);

};

extern CfrmCadIdiomas *frmCadIdiomas;

#endif
