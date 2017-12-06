#ifndef CADLIVROS_H
#define CADLIVROS_H

#include "Cadastros.h"
#include "RotinasGlobais.h"

class CfrmCadLivros : public CfrmCadastros {
  FXDECLARE(CfrmCadLivros)

public:
  enum { ID_FRMCADLIVROS_BTNADASSUNTOS = 2000, ID_FRMCADLIVROS_BTNADAUTORES, 
    ID_FRMCADLIVROS_BTNPASSUNTO, ID_FRMCADLIVROS_BTNPAUTOR, 
    ID_FRMCADLIVROS_BTNPEDITORA, ID_FRMCADLIVROS_LSTASSUNTOS, 
    ID_FRMCADLIVROS_LSTAUTORES, ID_FRMCADLIVROS_EDTCODASSUNTO, 
    ID_FRMCADLIVROS_EDTCODAUTOR, ID_FRMCADLIVROS_EDTCODEDITORA };

  CfrmCadLivros(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmCadLivros();
  long onBtnNovo(FXObject*,FXSelector,void*);
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnAnterior(FXObject*,FXSelector,void*);
  long onBtnProximo(FXObject*,FXSelector,void*);
  long onBtnSalvar(FXObject*,FXSelector,void*);
  long onBtnExcluir(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onBtnFechar(FXObject*,FXSelector,void*);
  long onClose(FXObject*,FXSelector,void*);

  long onEdtCodigo_Killfocus(FXObject*,FXSelector,void*);
  long onEdtCodEditora_Killfocus(FXObject*,FXSelector,void*);
  long onEdtCodAssunto_Killfocus(FXObject*,FXSelector,void*);
  long onEdtCodAutor_Killfocus(FXObject*,FXSelector,void*);
  long onBtnPEditora(FXObject*,FXSelector,void*);
  long onBtnPAssunto(FXObject*,FXSelector,void*);
  long onBtnAdAssuntos(FXObject*,FXSelector,void*);
  long onBtnPAutor(FXObject*,FXSelector,void*);
  long onBtnAdAutores(FXObject*,FXSelector,void*);
  long onLstAssuntos_Dblclk(FXObject*,FXSelector,void*);
  long onLstAutores_Dblclk(FXObject*,FXSelector,void*);

protected:
  FXVerticalFrame *frame10;
  FXHorizontalFrame *frame11;
  FXVerticalFrame *frame12;
  FXHorizontalFrame *frame13;
  FXVerticalFrame *frame14;

  FXHorizontalFrame *frame15;
  FXVerticalFrame *frame16;
  FXVerticalFrame *frame17;

  FXHorizontalFrame *frame18;
  FXVerticalFrame *frame19;
  FXHorizontalFrame *frame20;
  FXVerticalFrame *frame21;

  FXHorizontalFrame *frame22;
  FXVerticalFrame *frame23;
  FXHorizontalFrame *frame24;

  FXHorizontalFrame *frame25;
  FXVerticalFrame *frame26;
  FXHorizontalFrame *frame27;
  FXVerticalFrame *frame28;
  FXHorizontalFrame *frame29;

  LISTASTR slAssuntos, slAutores, slIdiomas;
  FXLabel *labEdicao;
  FXSpinner *edtEdicao;
  FXLabel *labAnoPubli;
  FXSpinner *edtAnoPubli;
  FXLabel *labEditora;  
  FXTextField *edtCodEditora;
  FXTextField *edtEditora;
  FXButton *btnPEditora;
  FXLabel *labVolume;
  FXSpinner *edtVolume;
  FXLabel *labIdioma;
  FXComboBox *cmbIdioma;
  FXLabel *labNPaginas;
  FXSpinner *edtNPaginas;
  FXLabel *labAssunto;
  FXTextField *edtCodAssunto;
  FXTextField *edtAssunto;
  FXButton *btnAdAssuntos;
  FXButton *btnPAssunto;
  FXList *lstAssuntos;
  FXLabel *labPreco;
  FXTextField *edtPreco;
  FXLabel *labQtdEstoque;
  FXSpinner *edtQtdEstoque;
  FXLabel *labAutor;
  FXTextField *edtCodAutor;
  FXTextField *edtAutor;
  FXButton *btnAdAutores;
  FXButton *btnPAutor;
  FXList *lstAutores;

private:
  CfrmCadLivros(){}
  void IniciaControles();
  FXbool ValidaDados(FXbool bTodosDados);
  void InformaLimpaDados(FXbool bInformar);
  void HabilitaDados(FXbool bHabilita);
  void AdicionaCombo();
  void SalvaLista(FXchar sOpcao);

};

extern CfrmCadLivros *frmCadLivros;

#endif
