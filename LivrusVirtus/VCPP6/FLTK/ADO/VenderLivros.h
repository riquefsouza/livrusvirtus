#ifndef VENDERLIVROS_H
#define VENDERLIVROS_H

#include "resource.h"
#include "ListaStr.h"

class CfrmVenderLivros: public Fl_Double_Window {
public:
  double nPrecoTotal;
  Fl_Output *edtDtHrVenda;
  Fl_Input *edtCPF;
  Fl_Output *edtCliente;
  Fl_Input *edtISBN;
  Fl_Output *edtLivro;
  Fl_Browser *lstLivros;
  Fl_Output *edtPrecoTotal;

  CfrmVenderLivros();
  ~CfrmVenderLivros();
  void LimpaDados();
  bool ValidaDados();
  bool SalvaLista();

protected:
  Fl_Button *btnPCliente;
  Fl_Button *btnAdLivros;
  Fl_Button *btnPLivro;
  Fl_Button *btnVender;
  Fl_Button *btnLimpar;
  Fl_Button *btnFechar;

private:
  void IniciaControles();
  int handle(int event);
};

extern CfrmVenderLivros *frmVenderLivros;
void frmVenderLivros_edtCPFKillFocus_cb(Fl_Input* i, void* v);
void frmVenderLivros_edtISBNKillFocus_cb(Fl_Input* i, void* v);

#endif
