#ifndef CONIDIOMAS_H
#define CONIDIOMAS_H

#include "resource.h"
#include "Consultas.h"

class CfrmConIdiomas: public CfrmConsultas {
public:
  CfrmConIdiomas();
  ~CfrmConIdiomas();

protected:   

private:
  void IniciaControles();
  int handle(int event);
};

extern CfrmConIdiomas *frmConIdiomas;

#endif
