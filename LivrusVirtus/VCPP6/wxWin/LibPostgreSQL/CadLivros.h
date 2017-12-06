#ifndef CADLIVROS_H
#define CADLIVROS_H

#include "Cadastros.h"
#include "RotinasGlobais.h"

class CfrmCadLivros: public CfrmCadastros {
public:
  CfrmCadLivros(wxWindow *parent);
  ~CfrmCadLivros();

protected:  
  void OnClose(wxCloseEvent& event);
  void OnBtnNovo(wxCommandEvent& event);
  void OnBtnPesquisar(wxCommandEvent& event);
  void OnBtnAnterior(wxCommandEvent& event);
  void OnBtnProximo(wxCommandEvent& event);
  void OnBtnSalvar(wxCommandEvent& event);
  void OnBtnExcluir(wxCommandEvent& event);
  void OnBtnLimpar(wxCommandEvent& event);
  void OnBtnFechar(wxCommandEvent& event);	
  void OnEdtCodigo_Killfocus(wxFocusEvent& event);
  void OnEdtCodEditora_Killfocus();
  void OnEdtCodAssunto_Killfocus();
  void OnEdtCodAutor_Killfocus();
  void OnBtnPEditora(wxCommandEvent& event);
  void OnEdtPreco_Killfocus(wxFocusEvent& event);
  void OnBtnPAssunto(wxCommandEvent& event);
  void OnBtnAdAssuntos(wxCommandEvent& event);
  void OnBtnPAutor(wxCommandEvent& event);
  void OnBtnAdAutores(wxCommandEvent& event);
  void OnLstAssuntos_Dblclk(wxCommandEvent& event);
  void OnLstAutores_Dblclk(wxCommandEvent& event);

private:
  LISTASTR slAssuntos, slAutores, slIdiomas;
  wxStaticText *labEdicao;
  wxSpinCtrl *edtEdicao;
  wxStaticText *labAnoPubli;
  wxSpinCtrl *edtAnoPubli;
  wxStaticText *labEditora;
  wxTextCtrl *edtCodEditora;
  wxTextCtrl *edtEditora;
  wxButton *btnPEditora;
  wxStaticText *labVolume;
  wxSpinCtrl *edtVolume;
  wxStaticText *labIdioma;
  wxChoice *cmbIdioma;
  wxStaticText *labNPaginas;
  wxSpinCtrl *edtNPaginas;
  wxStaticText *labAssunto;
  wxTextCtrl *edtCodAssunto;
  wxTextCtrl *edtAssunto;
  wxButton *btnAdAssuntos;
  wxButton *btnPAssunto;
  wxListBox *lstAssuntos;
  wxStaticText *labPreco;
  wxTextCtrl *edtPreco;
  wxStaticText *labQtdEstoque;
  wxSpinCtrl *edtQtdEstoque;
  wxStaticText *labAutor;
  wxTextCtrl *edtCodAutor;
  wxTextCtrl *edtAutor;
  wxButton *btnAdAutores;
  wxButton *btnPAutor;
  wxListBox *lstAutores;

  void IniciaControles();
  void FazLayout();
  bool ValidaDados(bool bTodosDados);
  void InformaLimpaDados(bool bInformar);
  void HabilitaDados(bool bHabilita);
  void AdicionaCombo();
  void SalvaLista(wxChar sOpcao);

  DECLARE_EVENT_TABLE();
};

enum {
 ID_FRMCADLIVROS_BTNADASSUNTOS = 900, ID_FRMCADLIVROS_BTNADAUTORES, 
 ID_FRMCADLIVROS_BTNPASSUNTO, ID_FRMCADLIVROS_BTNPAUTOR, 
 ID_FRMCADLIVROS_BTNPEDITORA, ID_FRMCADLIVROS_CMBIDIOMA, 
 ID_FRMCADLIVROS_EDTANOPUBLI, ID_FRMCADLIVROS_EDTASSUNTO, 
 ID_FRMCADLIVROS_EDTAUTOR, ID_FRMCADLIVROS_EDTCODASSUNTO, 
 ID_FRMCADLIVROS_EDTCODAUTOR, ID_FRMCADLIVROS_EDTCODEDITORA, 
 ID_FRMCADLIVROS_EDTEDICAO, ID_FRMCADLIVROS_EDTEDITORA, 
 ID_FRMCADLIVROS_EDTNPAGINAS, ID_FRMCADLIVROS_EDTPRECO, 
 ID_FRMCADLIVROS_EDTQTDESTOQUE, ID_FRMCADLIVROS_EDTVOLUME, 
 ID_FRMCADLIVROS_LABANOPUBLI, ID_FRMCADLIVROS_LABASSUNTO, 
 ID_FRMCADLIVROS_LABAUTOR, ID_FRMCADLIVROS_LABEDICAO, 
 ID_FRMCADLIVROS_LABEDITORA, ID_FRMCADLIVROS_LABIDIOMA, 
 ID_FRMCADLIVROS_LABNPAGINAS, ID_FRMCADLIVROS_LABPRECO, 
 ID_FRMCADLIVROS_LABQTDESTOQUE, ID_FRMCADLIVROS_LABVOLUME, 
 ID_FRMCADLIVROS_LSTASSUNTOS, ID_FRMCADLIVROS_LSTAUTORES
};

#endif


