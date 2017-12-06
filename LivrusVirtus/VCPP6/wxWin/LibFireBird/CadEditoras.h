#ifndef CADEDITORAS_H
#define CADEDITORAS_H

#include "Cadastros.h"

class CfrmCadEditoras: public CfrmCadastros {
public:
  CfrmCadEditoras(wxWindow *parent);
  ~CfrmCadEditoras();

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

  DECLARE_EVENT_TABLE();
};

#endif


