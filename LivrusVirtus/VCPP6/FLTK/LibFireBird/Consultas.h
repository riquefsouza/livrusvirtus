#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "resource.h"
#include "ListaStr.h"

class CfrmConsultas: public Fl_Double_Window {
public:
  Fl_Input *edtDescricao;
  Fl_Select_Browser *gridConsulta;

  LISTAMSTR lstLinhas;
  string sSelecionado;
  int nRegistro;

  CfrmConsultas(char* sTitulo);
  ~CfrmConsultas();
  void Fecha();
  void LimparDados();
  void PesquisarDados(string sTextoSql, string sMensagemErro, 
    int nQtdCol, int nLarguras[], string sRotulos[]);
  void setLabRegistros(int nLinha);

protected:   
  bool bSelecionado;
  Fl_Group *grupo1;
  Fl_Button *btnPesquisar;
  Fl_Group *grupo2;
  Fl_Box *labRegistro;
  Fl_Button *btnLimpar;
  Fl_Button *btnFechar;

private:
  void IniciaControles();

};

extern CfrmConsultas *frmConsultas;

#endif
