#ifndef CADPAISES_H
#define CADPAISES_H

#include "Cadastros.h"

class CfrmCadPaises: public CfrmCadastros {
public:
  CfrmCadPaises(wxWindow *parent);
  ~CfrmCadPaises();

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
  void IniciaControles();
  bool ValidaDados(bool bTodosDados);
  void InformaLimpaDados(bool bInformar);

  DECLARE_EVENT_TABLE();
};

#endif


