#ifndef CADASSUNTOS_H
#define CADASSUNTOS_H

#include "resource.h"
#include "Cadastros.h"

class CfrmCadAssuntos: public CfrmCadastros {
public:
  CfrmCadAssuntos();
  ~CfrmCadAssuntos();
  bool ValidaDados(bool bTodosDados);

private:
  void IniciaControles();
  int handle(int event);

};

extern CfrmCadAssuntos *frmCadAssuntos;

#endif
