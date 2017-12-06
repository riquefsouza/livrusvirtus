#ifndef CONEDITORAS_H
#define CONEDITORAS_H

#include "resource.h"
#include "Consultas.h"

class CfrmConEditoras: public CfrmConsultas {
public:
  CfrmConEditoras(bool bRetSelecionado = false);
  ~CfrmConEditoras();

protected:   

private:
  void IniciaControles();
  int handle(int event);
  void setSelecionado();
};

extern CfrmConEditoras *frmConEditoras;

#endif
