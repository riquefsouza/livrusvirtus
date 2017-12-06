#ifndef CONLIVROS_H
#define CONLIVROS_H

#include "Consultas.h"

class CfrmConLivros: public CfrmConsultas {
public:
  CfrmConLivros(wxWindow *parent);
  ~CfrmConLivros();

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


