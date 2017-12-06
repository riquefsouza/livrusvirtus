#ifndef CONENDERECOS_H
#define CONENDERECOS_H

#include "Consultas.h"

class CfrmConEnderecos: public CfrmConsultas {
public:
  CfrmConEnderecos(wxWindow *parent);
  ~CfrmConEnderecos();

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


