#ifndef CONENDERECOS_H
#define CONENDERECOS_H

#include "resource.h"
#include "Consultas.h"

class CfrmConEnderecos: public CfrmConsultas {
public:
  CfrmConEnderecos(bool bRetSelecionado = false);
  ~CfrmConEnderecos();

protected:   

private:
  void IniciaControles();
  int handle(int event);
  void setSelecionado();
};

extern CfrmConEnderecos *frmConEnderecos;

#endif
