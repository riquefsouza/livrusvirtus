#ifndef CONPROFISSOES_H
#define CONPROFISSOES_H

#include "Consultas.h"

class CfrmConProfissoes: public CfrmConsultas {
public:
  CfrmConProfissoes(wxWindow *parent);
  ~CfrmConProfissoes();

protected:
	void OnBtnPesquisar(wxCommandEvent& event);
  void OnBtnLimpar(wxCommandEvent& event);
  void OnBtnFechar(wxCommandEvent& event);
  void OnClose(wxCloseEvent& event);
  void OnGridSelectCell(wxGridEvent& event);
  void OnGridLabelLeftClick(wxGridEvent& event);

private:
  void IniciaControles();

  DECLARE_EVENT_TABLE();	
};

#endif


