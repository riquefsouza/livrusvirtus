#ifndef CONIDIOMAS_H
#define CONIDIOMAS_H

#include "Consultas.h"

class CfrmConIdiomas: public CfrmConsultas {
public:
  CfrmConIdiomas(wxWindow *parent);
  ~CfrmConIdiomas();

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


