#ifndef CONVENDAS_H
#define CONVENDAS_H

#include "Cadastros.h"
#include "RotinasGlobais.h"

class CfrmConVendas : public CfrmCadastros {
  FXDECLARE(CfrmConVendas)

public:
  enum { ID_FRMCONVENDAS_BTNPESQUISAR = 4000, ID_FRMCONVENDAS_BTNLIMPAR, 
    ID_FRMCONVENDAS_BTNFECHAR, ID_FRMCONVENDAS_BTNPCLIENTE,
    ID_FRMCONVENDAS_BTNPLIVRO, ID_FRMCONVENDAS_GRIDVENDAS,
    ID_FRMCONVENDAS_EDTDTHRVENDA, ID_FRMCONVENDAS_EDTISBN, 
    ID_FRMCONVENDAS_EDTCPF };

  CfrmConVendas(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmConVendas();
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onBtnFechar(FXObject*,FXSelector,void*);
  long onClose(FXObject*,FXSelector,void*);
  long onBtnPCliente(FXObject*,FXSelector,void*);
  long onBtnPLivro(FXObject*,FXSelector,void*);  
  long onEdtCPF_Killfocus(FXObject*,FXSelector,void*);
  long onEdtISBN_Killfocus(FXObject*,FXSelector,void*);
  long onGridSelected(FXObject*,FXSelector,void* ptr);
  long onGridChanged(FXObject*,FXSelector,void* ptr);
  long onEdtDtHrVenda_Killfocus(FXObject*,FXSelector,void*);

protected:
  FXHorizontalFrame  *frame10;
  FXVerticalFrame  *frame11;
  FXVerticalFrame  *frame12;

  FXHorizontalFrame  *frame13;
  FXVerticalFrame  *frame14;
  FXVerticalFrame  *frame15;
  FXVerticalFrame  *frame16;

  FXHorizontalFrame  *frame17;
  FXVerticalFrame  *frame18;
  FXVerticalFrame  *frame19;
  FXHorizontalFrame  *frame20;

  FXVerticalFrame  *frame21;
  FXHorizontalFrame  *frame22;
  FXHorizontalFrame  *frame23;
  FXHorizontalFrame  *frame24;
  FXHorizontalFrame  *frame25;

  LISTAMSTR lstLinhas;
  FXLabel *labDtHrVenda;
  FXTextField *edtDtHrVenda;
  FXLabel *labCPF;
  FXTextField *edtCPF;
  FXLabel *labCliente;
  FXTextField *edtCliente;
  FXButton *btnPCliente;
  FXLabel *labISBN;
  FXTextField *edtISBN;
  FXLabel *labLivro;
  FXTextField *edtLivro;
  FXButton *btnPLivro;
  FXLabel *labRegistro;
  FXTable *gridVendas;
  FXLabel *labPrecoTotal;
  FXTextField *edtPrecoTotal;
  FXButton *btnPesquisar;
  FXButton *btnLimpar;
  FXButton *btnFechar;

private:
  CfrmConVendas(){}
  void IniciaControles();
  FXString ConsVenda(FXchar sOpcao);
  void setLabRegistros(FXint nLinha);
};

extern CfrmConVendas *frmConVendas;

#endif
