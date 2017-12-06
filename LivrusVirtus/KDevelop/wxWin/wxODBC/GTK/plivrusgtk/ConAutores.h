#ifndef CONAUTORES_H
#define CONAUTORES_H

#include "Consultas.h"

class CfrmConAutores: public CfrmConsultas {
public:
  CfrmConAutores(wxWindow *parent);
  ~CfrmConAutores();

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


