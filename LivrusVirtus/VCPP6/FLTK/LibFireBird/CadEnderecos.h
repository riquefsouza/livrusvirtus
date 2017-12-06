#ifndef CADENDERECOS_H
#define CADENDERECOS_H

#include "resource.h"
#include "Cadastros.h"

class CfrmCadEnderecos: public CfrmCadastros {
public:
  Fl_Input *edtBairro;
  Fl_Input *edtCep;
  Fl_Input *edtCidade;
  Fl_Choice *cmbEstado;

  CfrmCadEnderecos();
  ~CfrmCadEnderecos();
  bool ValidaDados(bool bTodosDados);
  void InformaLimpaDados(bool bInformar);
  void HabilitaDados(bool bHabilita);

protected:

private:
  void IniciaControles();
  int handle(int event);
  void AdicionaCombo();
};

extern CfrmCadEnderecos *frmCadEnderecos;

#endif
