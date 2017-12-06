#ifndef CADASTROS_H
#define CADASTROS_H

#include "RotinasGlobais.h"

class CfrmCadastros: public wxPanel {
public:
  CfrmCadastros(wxWindow *parent, long nFiltroCodigo, bool bIniciaBotoes);
  ~CfrmCadastros();

protected:   
  wxButton *btnPesquisar;
  wxButton *btnAnterior;
  wxButton *btnProximo;
  wxButton *btnFechar;
  wxButton *btnLimpar;
  wxButton *btnExcluir;
  wxButton *btnSalvar;
  wxStaticText *labCodigo;
  wxTextCtrl *edtCodigo;
  wxStaticText *labDescricao;
  wxTextCtrl *edtDescricao;
  wxButton *btnNovo;

  LISTAMSTR lstRegistros;
  unsigned int nLinhaRegistro;

  void IniciaBotoes();
  void btnNovoClick();
  void NovoDado(wxString sTextoSql);
  void btnLimparClick();
  bool ExcluirDados(bool bValidaDados, wxString sTextoSql);
  bool PesquisarDados(wxString sTextoSql, wxString sMensagemErro,
                                   unsigned long nQtdCol);
  bool registroAnterior();
  bool registroProximo();
  bool SalvarDados(bool bValidaDados, wxString sTextoSql, 
    wxString sTextoUpdate, wxString sTextoInsert, bool bLimparDados);

private:
  void IniciaControles(long nFiltroCodigo, bool bIniciaBotoes);
  void FazLayout();
  void InformaLimpaDados(bool bInformar);
  void HabilitaDados(bool bHabilita);

};

enum {
   ID_FRMCADASTROS_BTNANTERIOR = 400, ID_FRMCADASTROS_BTNEXCLUIR, 
   ID_FRMCADASTROS_BTNFECHAR, ID_FRMCADASTROS_BTNLIMPAR, 
   ID_FRMCADASTROS_BTNNOVO, ID_FRMCADASTROS_BTNPESQUISAR, 
   ID_FRMCADASTROS_BTNPROXIMO, ID_FRMCADASTROS_BTNSALVAR, 
   ID_FRMCADASTROS_EDTCODIGO, ID_FRMCADASTROS_EDTDESCRICAO, 
   ID_FRMCADASTROS_LABCODIGO, ID_FRMCADASTROS_LABDESCRICAO
  };

#endif


