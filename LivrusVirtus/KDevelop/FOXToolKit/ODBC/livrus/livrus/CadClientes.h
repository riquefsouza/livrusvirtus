#ifndef CADCLIENTES_H
#define CADCLIENTES_H

#include "Cadastros.h"

class CfrmCadClientes : public CfrmCadastros {
  FXDECLARE(CfrmCadClientes)

public:
  enum { ID_FRMCADCLIENTES_BTNPENDERECO = 1000,
   ID_FRMCADCLIENTES_BTNPPROFISSAO, ID_FRMCADCLIENTES_BTNPPAIS,
   ID_FRMCADCLIENTES_EDTCODENDERECO, ID_FRMCADCLIENTES_EDTCODPAIS, 
   ID_FRMCADCLIENTES_EDTCODPROFISSAO, ID_FRMCADCLIENTES_EDTDTNASC,
   ID_FRMCADCLIENTES_RBMASCULINO, ID_FRMCADCLIENTES_RBFEMININO };

  CfrmCadClientes(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
    FXMDIMenu *menuMDI);
  virtual ~CfrmCadClientes();
  long onBtnNovo(FXObject*,FXSelector,void*);
  long onBtnPesquisar(FXObject*,FXSelector,void*);
  long onBtnAnterior(FXObject*,FXSelector,void*);
  long onBtnProximo(FXObject*,FXSelector,void*);
  long onBtnSalvar(FXObject*,FXSelector,void*);
  long onBtnExcluir(FXObject*,FXSelector,void*);
  long onBtnLimpar(FXObject*,FXSelector,void*);
  long onBtnFechar(FXObject*,FXSelector,void*);
  long onClose(FXObject*,FXSelector,void*);
  long onCmdSexo(FXObject*,FXSelector sel,void*);
  long onUpdSexo(FXObject* obj,FXSelector sel,void*);
  long onEdtCodigo_Killfocus(FXObject*,FXSelector,void*);
  long onEdtDtNasc_Killfocus(FXObject*,FXSelector,void*);
  long onEdtCodEndereco_Killfocus(FXObject*,FXSelector,void*);
  long onEdtCodPais_Killfocus(FXObject*,FXSelector,void*);
  long onEdtCodProfissao_Killfocus(FXObject*,FXSelector,void*);
  long onBtnPEndereco(FXObject*,FXSelector,void*);
  long onBtnPPais(FXObject*,FXSelector,void*);
  long onBtnPProfissao(FXObject*,FXSelector,void*);

protected:
  FXHorizontalFrame *frameSexo;
  FXHorizontalFrame *frame10;
  FXVerticalFrame *frame11;
  FXVerticalFrame *frame12;
  FXHorizontalFrame *frame13;
  FXVerticalFrame *frame14;
  FXVerticalFrame *frame15;
  FXVerticalFrame *frame16;
  FXHorizontalFrame *frame17;
  FXHorizontalFrame *frame18;
  FXVerticalFrame *frame19;
  FXVerticalFrame *frame20;
  FXHorizontalFrame *frame21;
  FXVerticalFrame *frame22;
  FXVerticalFrame *frame23;
  FXVerticalFrame *frame24;
  FXHorizontalFrame *frame25;
  FXVerticalFrame *frame26;
  FXHorizontalFrame *frame27;
  FXVerticalFrame *frame28;

  FXLabel *labEmail;
  FXTextField *edtEmail;
  FXLabel *labIdentidade;
  FXTextField *edtIdentidade;
  FXGroupBox *gpSexo;
  FXRadioButton *rbMasculino;
  FXRadioButton *rbFeminino;
  FXDataTarget *rbSexoAlvo;
  FXuint  nSexoEscolha;
  FXLabel *labTelefone;
  FXTextField *edtTelefone;
  FXLabel *labDtNasc;
  FXTextField *edtDtNasc;
  FXGroupBox *gpEndereco;
  FXTextField *edtCodEndereco;
  FXButton *btnPEndereco;
  FXLabel *labLogradouro;
  FXLabel *labBairro;
  FXLabel *labCEP;
  FXLabel *labCidade;
  FXLabel *labEstado;
  FXTextField *edtLogradouro;
  FXTextField *edtBairro;
  FXTextField *edtCEP;
  FXTextField *edtCidade;
  FXTextField *edtEstado;
  FXLabel *labPais;  
  FXTextField *edtCodPais;
  FXTextField *edtPais;
  FXButton *btnPPais;
  FXLabel *labProfissao;
  FXTextField *edtCodProfissao;
  FXTextField *edtProfissao;
  FXButton *btnPProfissao;

private:
  CfrmCadClientes(){}
  void IniciaControles();
  FXbool ValidaDados(FXbool bTodosDados);
  void InformaLimpaDados(FXbool bInformar);
  void HabilitaDados(FXbool bHabilita);
};

extern CfrmCadClientes *frmCadClientes;

#endif
