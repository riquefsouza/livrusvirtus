#ifndef CADAUTORES_H
#define CADAUTORES_H

#include "Cadastros.h"

class CfrmCadAutores: public CfrmCadastros {
public:
  CfrmCadAutores(wxWindow *parent);
  ~CfrmCadAutores();

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


