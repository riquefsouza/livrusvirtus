#ifndef CONLIVROS_H
#define CONLIVROS_H

#include "resource.h"
#include "Consultas.h"

class CfrmConLivros: public CfrmConsultas {
public:
  CfrmConLivros(int nRetSelecionado = 0);
  ~CfrmConLivros();

protected:   

private:
  int nSelecionado;
  void IniciaControles();
  int handle(int event);
  void setSelecionado();
};

extern CfrmConLivros *frmConLivros;

#endif
