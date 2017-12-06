#ifndef CONVENDAS_H
#define CONVENDAS_H

#include "RotinasGlobais.h"

class CfrmConVendas: public wxPanel {
public:
  CfrmConVendas(wxWindow *parent);
  ~CfrmConVendas();

protected:  
  void OnClose(wxCloseEvent& event);
  void OnBtnPesquisar(wxCommandEvent& event);
  void OnBtnLimpar(wxCommandEvent& event);
  void OnBtnFechar(wxCommandEvent& event);	
  void OnBtnPCliente(wxCommandEvent& event);
  void OnBtnPLivro(wxCommandEvent& event);	
  void OnEdtCPF_Killfocus();
  void OnEdtISBN_Killfocus();
  void OnGridSelectCell(wxGridEvent& event);
  void OnGridLabelLeftClick(wxGridEvent& event);
  void OnEdtDtHrVenda_Killfocus(wxFocusEvent& event);

private:
  LISTAMSTR lstLinhas;
  wxStaticText *labDtHrVenda;
  wxTextCtrl *edtDtHrVenda;
  wxStaticText *labCPF;
  wxTextCtrl *edtCPF;
  wxStaticText *labCliente;
  wxTextCtrl *edtCliente;
  wxButton *btnPCliente;
  wxStaticText *labISBN;
  wxTextCtrl *edtISBN;
  wxStaticText *labLivro;
  wxTextCtrl *edtLivro;
  wxButton *btnPLivro;
  wxStaticText *labRegistro;
  wxGrid *gridVendas;
  wxStaticText *labPrecoTotal;
  wxTextCtrl *edtPrecoTotal;
  wxButton *btnPesquisar;
  wxButton *btnLimpar;
  wxButton *btnFechar;

  void IniciaControles();
  void FazLayout();
  wxString ConsVenda(wxChar sOpcao);
  void setLabRegistros(int nLinha);

  DECLARE_EVENT_TABLE();
};

enum {
  ID_FRMCONVENDAS_BTNPESQUISAR = 1100, ID_FRMCONVENDAS_BTNLIMPAR, 
  ID_FRMCONVENDAS_BTNFECHAR, ID_FRMCONVENDAS_BTNPCLIENTE,
  ID_FRMCONVENDAS_BTNPLIVRO, ID_FRMCONVENDAS_GRIDVENDAS,
  ID_FRMCONVENDAS_EDTDTHRVENDA, ID_FRMCONVENDAS_EDTISBN, 
  ID_FRMCONVENDAS_EDTLIVRO, ID_FRMCONVENDAS_EDTPRECOTOTAL, 
  ID_FRMCONVENDAS_LABDTHRVENDA, ID_FRMCONVENDAS_LABISBN, 
  ID_FRMCONVENDAS_LABLIVRO, ID_FRMCONVENDAS_LABPRECOTOTAL,
  ID_FRMCONVENDAS_LABCPF, ID_FRMCONVENDAS_EDTCPF, 
  ID_FRMCONVENDAS_LABCLIENTE, ID_FRMCONVENDAS_EDTCLIENTE, 
  ID_FRMCONVENDAS_LABREGISTRO
};

#endif


