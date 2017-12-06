#ifndef CONPROFISSOES_H
#define CONPROFISSOES_H

#include "resource.h"
#include "Consultas.h"

class CfrmConProfissoes: public CfrmConsultas {
public:
  CfrmConProfissoes(bool bRetSelecionado = false);
  ~CfrmConProfissoes();

protected:   

private:
  void IniciaControles();
  int handle(int event);
  void setSelecionado();
};

extern CfrmConProfissoes *frmConProfissoes;

#endif
