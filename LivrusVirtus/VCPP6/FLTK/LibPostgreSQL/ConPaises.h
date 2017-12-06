#ifndef CONPAISES_H
#define CONPAISES_H

#include "resource.h"
#include "Consultas.h"

class CfrmConPaises: public CfrmConsultas {
public:
  CfrmConPaises(bool bRetSelecionado = false);
  ~CfrmConPaises();

protected:   

private:
  void IniciaControles();
  int handle(int event);
  void setSelecionado();
};

extern CfrmConPaises *frmConPaises;

#endif
