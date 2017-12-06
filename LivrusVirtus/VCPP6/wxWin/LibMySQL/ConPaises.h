#ifndef CONPAISES_H
#define CONPAISES_H

#include "Consultas.h"

class CfrmConPaises: public CfrmConsultas {
public:
  CfrmConPaises(wxWindow *parent);
  ~CfrmConPaises();

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


