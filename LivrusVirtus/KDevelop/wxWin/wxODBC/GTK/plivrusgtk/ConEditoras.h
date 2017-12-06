#ifndef CONEDITORAS_H
#define CONEDITORAS_H

#include "Consultas.h"

class CfrmConEditoras: public CfrmConsultas {
public:
  CfrmConEditoras(wxWindow *parent);
  ~CfrmConEditoras();

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


