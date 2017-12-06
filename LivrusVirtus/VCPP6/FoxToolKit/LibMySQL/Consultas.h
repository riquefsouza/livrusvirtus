#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "RotinasGlobais.h"

class CfrmConsultas : public FXDialogBox {
  FXDECLARE(CfrmConsultas)

public:
  enum { ID_FRMCONSULTAS_BTNFECHAR = FXDialogBox::ID_LAST,
   ID_FRMCONSULTAS_BTNLIMPAR, ID_FRMCONSULTAS_BTNPESQUISAR, 
   ID_FRMCONSULTAS_GRIDCONSULTA };

  CfrmConsultas(FXWindow* owner, FXString sTitulo);
  virtual void create();
  virtual ~CfrmConsultas();

protected:
  FXVerticalFrame *frame;
  FXHorizontalFrame *frameBotoesH;
  FXVerticalFrame *frame1;
  FXHorizontalFrame *frame2;
  FXVerticalFrame *frame3;
  FXVerticalFrame *frame4;

  FXLabel *labDescricao;
  FXTextField *edtDescricao;
  FXButton *btnPesquisar;
  FXLabel *labRegistro;
  FXTable *gridConsulta;
  FXButton *btnFechar;
  FXButton *btnLimpar;

  CfrmConsultas(){}
  void LimparDados();
  void PesquisarDados(FXString sTextoSql, FXString sMensagemErro, 
    FXint nQtdCol);
  void setLabRegistros(FXint nLinha);

private:
  LISTAMSTR lstLinhas;
  FXString sSelecionado;
  int nRegistro;

  void IniciaControles();
};

#endif
