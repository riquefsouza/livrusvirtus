#ifndef VENDERLIVROS_H
#define VENDERLIVROS_H

#include "Cadastros.h"
#include "RotinasGlobais.h"

class CfrmVenderLivros: public CfrmCadastros {
public:
  CfrmVenderLivros(wxWindow *parent);
  ~CfrmVenderLivros();

protected:  
  void OnClose(wxCloseEvent& event);
  void OnBtnVender(wxCommandEvent& event);
  void OnBtnLimpar(wxCommandEvent& event);
  void OnBtnFechar(wxCommandEvent& event);	
  void OnBtnPCliente(wxCommandEvent& event);
  void OnBtnPLivro(wxCommandEvent& event);	
  void OnEdtCodigo_Killfocus();
  void OnEdtISBN_Killfocus();
  void OnBtnAdLivros(wxCommandEvent& event); 
  void OnLstLivros_Dblclk(wxCommandEvent& event);

private:
  LISTASTR slPrecos, slISBNs, slQtdEstoque;
  double nPrecoTotal;
  wxStaticText *labDtHrVenda;
  wxTextCtrl *edtDtHrVenda;
  wxButton *btnPCliente;
  wxStaticText *labISBN;
  wxTextCtrl *edtISBN;
  wxStaticText *labLivro;
  wxTextCtrl *edtLivro;
  wxButton *btnAdLivros;
  wxButton *btnPLivro;
  wxStaticText *labLivros;
  wxListBox *lstLivros;
  wxStaticText *labPrecoTotal;
  wxTextCtrl *edtPrecoTotal;
  wxButton *btnVender;
  wxButton *btnLimpar;
  wxButton *btnFechar;

  void IniciaControles();
  void FazLayout();
  void LimpaDados();
  bool ValidaDados();
  bool SalvaLista();

  DECLARE_EVENT_TABLE();
};

enum {
  ID_FRMVENDERLIVROS_BTNVENDER = 1000, ID_FRMVENDERLIVROS_BTNLIMPAR, 
  ID_FRMVENDERLIVROS_BTNFECHAR, ID_FRMVENDERLIVROS_BTNPCLIENTE,
  ID_FRMVENDERLIVROS_BTNPLIVRO, ID_FRMVENDERLIVROS_LSTLIVROS,
  ID_FRMVENDERLIVROS_EDTDTHRVENDA, ID_FRMVENDERLIVROS_EDTISBN, 
  ID_FRMVENDERLIVROS_EDTLIVRO, ID_FRMVENDERLIVROS_EDTPRECOTOTAL, 
  ID_FRMVENDERLIVROS_LABDTHRVENDA, ID_FRMVENDERLIVROS_LABISBN, 
  ID_FRMVENDERLIVROS_LABLIVRO, ID_FRMVENDERLIVROS_LABLIVROS, 
  ID_FRMVENDERLIVROS_LABPRECOTOTAL, ID_FRMVENDERLIVROS_BTNADLIVROS
};

#endif


