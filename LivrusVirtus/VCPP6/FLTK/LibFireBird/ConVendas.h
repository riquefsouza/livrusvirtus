#ifndef CONVENDAS_H
#define CONVENDAS_H

#include "resource.h"
#include "Cadastros.h"

class CfrmConVendas: public Fl_Double_Window {
public:
  LISTAMSTR lstLinhas;
  Fl_Input *edtDtHrVenda;
  Fl_Input *edtCPF;
  Fl_Output *edtCliente;
  Fl_Input *edtISBN;
  Fl_Output *edtLivro;
  Fl_Select_Browser *gridVendas;
  Fl_Box *labRegistros;
  Fl_Output *edtPrecoTotal;

  CfrmConVendas();
  ~CfrmConVendas();
  string ConsVenda(char sOpcao);
  void setLabRegistros(int nLinha);

protected:
  Fl_Group *grupo1;
  Fl_Button *btnPesquisar;
  Fl_Button *btnPCliente;
  Fl_Button *btnPLivro;
  Fl_Group *grupo2;
  Fl_Button *btnLimpar;
  Fl_Button *btnFechar;

private:
  void IniciaControles();
  int handle(int event);  
};

extern CfrmConVendas *frmConVendas;
void frmConVendas_edtCPFKillFocus_cb(Fl_Input* i, void* v);
void frmConVendas_edtISBNKillFocus_cb(Fl_Input* i, void* v);

#endif
