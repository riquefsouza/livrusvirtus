#ifndef CADENDERECOS_H
#define CADENDERECOS_H

#include "Cadastros.h"

class CfrmCadEnderecos: public CfrmCadastros {
public:
  CfrmCadEnderecos(wxWindow *parent);
  ~CfrmCadEnderecos();

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

private:
  wxStaticText *labBairro;
  wxTextCtrl *edtBairro;
  wxStaticText *labCEP;
  wxTextCtrl *edtCEP;
  wxStaticText *labCidade;
  wxTextCtrl *edtCidade;
  wxStaticText *labEstado;
  wxChoice *cmbEstado;
  void IniciaControles();
  void FazLayout();
  bool ValidaDados(bool bTodosDados);
  void InformaLimpaDados(bool bInformar);
  void HabilitaDados(bool bHabilita);
  void AdicionaCombo();

  DECLARE_EVENT_TABLE();
};

enum {
  ID_FRMCADENDERECOS_LABBAIRRO = 700, ID_FRMCADENDERECOS_EDTBAIRRO, ID_FRMCADENDERECOS_LABCEP, 
  ID_FRMCADENDERECOS_EDTCEP, ID_FRMCADENDERECOS_LABCIDADE, ID_FRMCADENDERECOS_EDTCIDADE, 
  ID_FRMCADENDERECOS_LABESTADO, ID_FRMCADENDERECOS_CMBESTADO
};

#endif


