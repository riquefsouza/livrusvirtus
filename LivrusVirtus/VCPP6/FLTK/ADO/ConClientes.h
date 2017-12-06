#ifndef CONCLIENTES_H
#define CONCLIENTES_H

#include "resource.h"
#include "Consultas.h"

class CfrmConClientes: public CfrmConsultas {
public:
  CfrmConClientes(int nRetSelecionado = 0);
  ~CfrmConClientes();

protected:   

private:
  int nSelecionado;
  void IniciaControles();
  int handle(int event);
  void setSelecionado();
};

extern CfrmConClientes *frmConClientes;

#endif
