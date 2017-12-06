#ifndef CADASTROS_H
#define CADASTROS_H

#include "resource.h"
#include "ListaStr.h"

class CfrmCadastros: public Fl_Double_Window {
public:
  Fl_Input *edtCodigo;
  Fl_Input *edtDescricao;
  LISTAMSTR lstRegistros;
  unsigned int nLinhaRegistro;

  CfrmCadastros(bool bIniciaBotoes, char* sTitulo);
  ~CfrmCadastros();
  void IniciaBotoes(int nX1, int nY1, int nX2, int nY2);
  void btnNovoClick();
  void NovoDado(string sTextoSql);
  void btnLimparClick();
  bool ExcluirDados(bool bValidaDados, string sTextoSql);
  bool PesquisarDados(string sTextoSql, string sMensagemErro);
  bool registroAnterior();
  bool registroProximo();
  bool SalvarDados(bool bValidaDados, string sTextoSql, 
    string sTextoUpdate, string sTextoInsert, bool bLimparDados);

protected:   
  Fl_Button *btnNovo;
  Fl_Button *btnPesquisar;
  Fl_Button *btnAnterior;
  Fl_Button *btnProximo;
  Fl_Button *btnFechar;
  Fl_Button *btnLimpar;
  Fl_Button *btnExcluir;
  Fl_Button *btnSalvar;

private:
  void IniciaControles(bool bIniciaBotoes);
  void InformaLimpaDados(bool bInformar);
  void HabilitaDados(bool bHabilita);

};

extern CfrmCadastros *frmCadastros;

#endif
