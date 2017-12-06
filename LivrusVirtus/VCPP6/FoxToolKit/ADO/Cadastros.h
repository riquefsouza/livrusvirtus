#ifndef CADASTROS_H
#define CADASTROS_H

#include "RotinasGlobais.h"

class CfrmCadastros : public FXMDIChild {
  FXDECLARE(CfrmCadastros)

public:
  enum { ID_FRMCADASTROS_BTNNOVO = FXMDIChild::ID_LAST,
   ID_FRMCADASTROS_BTNANTERIOR, ID_FRMCADASTROS_BTNEXCLUIR, 
   ID_FRMCADASTROS_BTNFECHAR, ID_FRMCADASTROS_BTNLIMPAR, 
   ID_FRMCADASTROS_BTNPESQUISAR, ID_FRMCADASTROS_BTNPROXIMO, 
   ID_FRMCADASTROS_BTNSALVAR, ID_FRMCADASTROS_EDTCODIGO };

  CfrmCadastros(FXMDIClient *clienteMDI, FXString sTitulo, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI, FXint nFiltroCodigo, FXbool bIniciaBotoes);
  virtual ~CfrmCadastros();

protected:
  FXVerticalFrame *frame;
  FXHorizontalFrame *frameBotoesH;
  FXVerticalFrame *frameBotoesV;

  FXVerticalFrame *frame1;
  FXHorizontalFrame *frame2;
  FXVerticalFrame *frame3;
  FXHorizontalFrame *frame4;
  FXVerticalFrame *frame5;
  FXVerticalFrame *frame6;
  FXHorizontalFrame *frame7;
  FXVerticalFrame *frame8;

  FXLabel  *labCodigo;
  FXTextField *edtCodigo;
  FXLabel  *labDescricao;
  FXTextField *edtDescricao;
  FXButton *btnNovo;
  FXButton *btnPesquisar;
  FXButton *btnAnterior;
  FXButton *btnProximo;
  FXButton *btnSalvar;
  FXButton *btnExcluir;
  FXButton *btnLimpar;
  FXButton *btnFechar;

  LISTAMSTR lstRegistros;
  FXint nLinhaRegistro;

  CfrmCadastros(){}
  void IniciaBotoes();
  void btnNovoClick();
  void NovoDado(FXString sTextoSql);
  void btnLimparClick();
  FXbool ExcluirDados(FXbool bValidaDados, FXString sTextoSql);
  FXbool PesquisarDados(FXString sTextoSql, FXString sMensagemErro);
  FXbool registroAnterior();
  FXbool registroProximo();
  FXbool SalvarDados(FXbool bValidaDados, FXString sTextoSql, 
    FXString sTextoUpdate, FXString sTextoInsert, FXbool bLimparDados);
  
private:
  void IniciaControles(FXint nFiltroCodigo, FXbool bIniciaBotoes);
  void InformaLimpaDados(FXbool bInformar);
  void HabilitaDados(FXbool bHabilita);
};

#endif
