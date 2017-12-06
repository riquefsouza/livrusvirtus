#ifndef CONASSUNTOS_H
#define CONASSUNTOS_H

#include "Consultas.h"

class CfrmConAssuntos: public CfrmConsultas {
public:
  CfrmConAssuntos(wxWindow *parent);
  ~CfrmConAssuntos();

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


