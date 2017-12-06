#ifndef VENDERLIVROS_H
#define VENDERLIVROS_H

#include "Cadastros.h"
#include "RotinasGlobais.h"

class CfrmVenderLivros : public CfrmCadastros {
  FXDECLARE(CfrmVenderLivros)

public:
  enum {
    ID_FRMVENDERLIVROS_BTNVENDER = 3000, ID_FRMVENDERLIVROS_BTNLIMPAR, 
    ID_FRMVENDERLIVROS_BTNFECHAR, ID_FRMVENDERLIVROS_BTNPCLIENTE,
    ID_FRMVENDERLIVROS_BTNPLIVRO, ID_FRMVENDERLIVROS_LSTLIVROS,
    ID_FRMVENDERLIVROS_EDTISBN, ID_FRMVENDERLIVROS_BTNADLIVROS };

  CfrmVenderLivros(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmVenderLivros();
  long onBtnVender(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onBtnFechar(FXObject*,FXSelector,void*);
  long onClose(FXObject*,FXSelector,void*);
  long onBtnPCliente(FXObject*,FXSelector,void*);
  long onBtnPLivro(FXObject*,FXSelector,void*);
  long onEdtCodigo_Killfocus(FXObject*,FXSelector,void*);
  long onEdtISBN_Killfocus(FXObject*,FXSelector,void*);
  long onBtnAdLivros(FXObject*,FXSelector,void*);
  long onLstLivros_Dblclk(FXObject*,FXSelector,void*);

protected:
  FXHorizontalFrame  *frame10;
  FXVerticalFrame  *frame11;

  FXHorizontalFrame  *frame12;
  FXVerticalFrame  *frame13;
  FXVerticalFrame  *frame14;
  FXVerticalFrame  *frame15;

  FXHorizontalFrame  *frame16;
  FXVerticalFrame  *frame17;
  FXVerticalFrame  *frame18;
  FXHorizontalFrame  *frame19;

  FXVerticalFrame  *frame20;
  FXHorizontalFrame  *frame21;
  FXHorizontalFrame  *frame22;
  FXHorizontalFrame  *frame23;
  FXHorizontalFrame  *frame24;

  FXLabel *labDtHrVenda;
  FXTextField *edtDtHrVenda;
  FXButton *btnPCliente;
  FXLabel *labISBN;
  FXTextField *edtISBN;
  FXLabel *labLivro;
  FXTextField *edtLivro;
  FXButton *btnAdLivros;
  FXButton *btnPLivro;
  FXLabel *labLivros;
  FXList *lstLivros;
  FXLabel *labPrecoTotal;
  FXTextField *edtPrecoTotal;
  FXButton *btnVender;
  FXButton *btnLimpar;
  FXButton *btnFechar;

private:
  LISTASTR slPrecos, slISBNs, slQtdEstoque;
  FXdouble nPrecoTotal;

  CfrmVenderLivros(){}
  void IniciaControles();
  void LimpaDados();
  FXbool ValidaDados();
  FXbool SalvaLista();

};

extern CfrmVenderLivros *frmVenderLivros;

#endif
