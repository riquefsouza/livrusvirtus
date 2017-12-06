#ifndef CADCLIENTES_H
#define CADCLIENTES_H

#include "resource.h"
#include "Cadastros.h"

class CfrmCadClientes: public CfrmCadastros {
public:
  Fl_Input *edtEmail;
  Fl_Input *edtIdentidade;
  Fl_Group *grpSexo;
  Fl_Round_Button *rbMasculino;
  Fl_Round_Button *rbFeminino;
  Fl_Input *edtTelefone;
  Fl_Input *edtDtNasc;
  Fl_Group *grpEndereco;
  Fl_Input *edtCodEndereco;
  Fl_Input *edtLogradouro;
  Fl_Input *edtBairro;
  Fl_Input *edtCep;
  Fl_Input *edtCidade;
  Fl_Input *edtEstado;
  Fl_Input *edtCodPais;
  Fl_Input *edtPais;
  Fl_Button *btnPPais;
  Fl_Input *edtCodProfissao;
  Fl_Input *edtProfissao;
  Fl_Button *btnPProfissao;

  CfrmCadClientes();
  ~CfrmCadClientes();
  bool ValidaDados(bool bTodosDados);
  void InformaLimpaDados(bool bInformar);
  void HabilitaDados(bool bHabilita);

protected:
  Fl_Button *btnPEndereco;

private:
  void IniciaControles();  
  int handle(int event);
};

extern CfrmCadClientes *frmCadClientes;
void frmCadClientes_edtCodEnderecoKillFocus_cb(Fl_Input* i, void* v);
void frmCadClientes_edtCodPaisKillFocus_cb(Fl_Input* i, void* v);
void frmCadClientes_edtCodProfissaoKillFocus_cb(Fl_Input* i, void* v);

#endif
