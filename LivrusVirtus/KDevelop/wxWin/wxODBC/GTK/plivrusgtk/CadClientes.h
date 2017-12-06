#ifndef CADCLIENTES_H
#define CADCLIENTES_H

#include "Cadastros.h"
#include "DateCtrl.h"

class CfrmCadClientes: public CfrmCadastros {
public:
  CfrmCadClientes(wxWindow *parent);
  ~CfrmCadClientes();

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
  void OnEdtCodEndereco_Killfocus();
  void OnEdtCodPais_Killfocus();
  void OnEdtCodProfissao_Killfocus();
  void OnBtnPEndereco(wxCommandEvent& event);
  void OnBtnPPais(wxCommandEvent& event);
  void OnBtnPProfissao(wxCommandEvent& event);

private:
  wxStaticText *labEmail;
  wxTextCtrl *edtEmail;
  wxStaticText *labIdentidade;
  wxTextCtrl *edtIdentidade;
  wxRadioBox *rbSexo;
  wxStaticText *labTelefone;
  wxTextCtrl *edtTelefone;
  wxStaticText *labDtNasc;
//  CDateCtrl *edtDtNasc;
  wxTextCtrl *edtDtNasc;
  wxTextCtrl *edtCodEndereco;
  wxButton *btnPEndereco;
  wxStaticText *labLogradouro;
  wxTextCtrl *edtLogradouro;
  wxStaticText *labBairro;
  wxTextCtrl *edtBairro;
  wxStaticText *labCEP;
  wxTextCtrl *edtCEP;
  wxStaticText *labCidade;
  wxTextCtrl *edtCidade;
  wxStaticText *labEstado;
  wxTextCtrl *edtEstado;
  wxStaticText *labPais;
  wxTextCtrl *edtCodPais;
  wxTextCtrl *edtPais;
  wxButton *btnPPais;
  wxStaticText *labProfissao;
  wxTextCtrl *edtCodProfissao;
  wxTextCtrl *edtProfissao;
  wxButton *btnPProfissao;

  void IniciaControles();
  void FazLayout();
  bool ValidaDados(bool bTodosDados);
  void InformaLimpaDados(bool bInformar);
  void HabilitaDados(bool bHabilita);

  DECLARE_EVENT_TABLE();
};

enum {
 ID_FRMCADCLIENTES_BTNPENDERECO = 800, 
 ID_FRMCADCLIENTES_BTNPPAIS, ID_FRMCADCLIENTES_BTNPPROFISSAO, 
 ID_FRMCADCLIENTES_EDTBAIRRO, ID_FRMCADCLIENTES_EDTCEP, 
 ID_FRMCADCLIENTES_EDTCIDADE, ID_FRMCADCLIENTES_EDTCODENDERECO, 
 ID_FRMCADCLIENTES_EDTCODPAIS, ID_FRMCADCLIENTES_EDTCODPROFISSAO, 
 ID_FRMCADCLIENTES_EDTDTNASC, ID_FRMCADCLIENTES_EDTEMAIL, 
 ID_FRMCADCLIENTES_EDTESTADO, ID_FRMCADCLIENTES_EDTIDENTIDADE, 
 ID_FRMCADCLIENTES_EDTLOGRADOURO, ID_FRMCADCLIENTES_EDTPAIS, 
 ID_FRMCADCLIENTES_EDTPROFISSAO, ID_FRMCADCLIENTES_EDTTELEFONE, 
 ID_FRMCADCLIENTES_LABBAIRRO, ID_FRMCADCLIENTES_LABCEP, 
 ID_FRMCADCLIENTES_LABCIDADE, ID_FRMCADCLIENTES_LABDTNASC, 
 ID_FRMCADCLIENTES_LABEMAIL, ID_FRMCADCLIENTES_LABESTADO, 
 ID_FRMCADCLIENTES_LABIDENTIDADE, ID_FRMCADCLIENTES_LABLOGRADOURO, 
 ID_FRMCADCLIENTES_LABPAIS, ID_FRMCADCLIENTES_LABPROFISSAO, 
 ID_FRMCADCLIENTES_LABTELEFONE, ID_FRMCADCLIENTES_RBSEXO
};

#endif


