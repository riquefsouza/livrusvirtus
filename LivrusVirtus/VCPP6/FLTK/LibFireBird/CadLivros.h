#ifndef CADLIVROS_H
#define CADLIVROS_H

#include "resource.h"
#include "Cadastros.h"

class CfrmCadLivros: public CfrmCadastros {
public:    
  Fl_Value_Input *edtEdicao;
  Fl_Value_Input *edtAnoPubli;
  Fl_Input *edtCodEditora;
  Fl_Input *edtEditora;
  Fl_Button *btnPEditora;
  Fl_Value_Input *edtVolume;
  Fl_Choice *cmbIdioma;
  Fl_Value_Input *edtNPaginas;
  Fl_Input *edtCodAssunto;
  Fl_Input *edtAssunto;
  Fl_Button *btnAdAssuntos;
  Fl_Button *btnPAssunto;
  Fl_Input *edtPreco;
  Fl_Select_Browser *lstAssuntos;
  Fl_Value_Input *edtQtdEstoque;
  Fl_Input *edtCodAutor;
  Fl_Input *edtAutor;
  Fl_Button *btnAdAutores;
  Fl_Button *btnPAutor;
  Fl_Select_Browser *lstAutores;

  CfrmCadLivros();
  ~CfrmCadLivros();
  bool ValidaDados(bool bTodosDados);
  void InformaLimpaDados(bool bInformar);
  void HabilitaDados(bool bHabilita);
  void SalvaLista(char sOpcao);

protected:

private:
  void IniciaControles();
  int handle(int event);
  void AdicionaCombo();
};

extern CfrmCadLivros *frmCadLivros;
void frmCadLivros_edtCodEditoraKillFocus_cb(Fl_Input* i, void* v);
void frmCadLivros_edtCodAssuntoKillFocus_cb(Fl_Input* i, void* v);
void frmCadLivros_edtCodAutorKillFocus_cb(Fl_Input* i, void* v);

#endif
