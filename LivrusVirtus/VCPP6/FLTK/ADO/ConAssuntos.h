#ifndef CONASSUNTOS_H
#define CONASSUNTOS_H

#include "resource.h"
#include "Consultas.h"

class CfrmConAssuntos: public CfrmConsultas {
public:
  CfrmConAssuntos(bool bRetSelecionado = false);
  ~CfrmConAssuntos();

protected:   

private:
  void IniciaControles();
  int handle(int event);
  void setSelecionado();
};

extern CfrmConAssuntos *frmConAssuntos;

#endif
