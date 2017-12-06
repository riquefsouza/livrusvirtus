#ifndef CONAUTORES_H
#define CONAUTORES_H

#include "resource.h"
#include "Consultas.h"

class CfrmConAutores: public CfrmConsultas {
public:
  CfrmConAutores(bool bRetSelecionado = false);
  ~CfrmConAutores();

protected:   

private:
  void IniciaControles();
  int handle(int event);
  void setSelecionado();
};

extern CfrmConAutores *frmConAutores;

#endif
