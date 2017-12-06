#ifndef CONCLIENTES_H
#define CONCLIENTES_H

#include "Consultas.h"

class CfrmConClientes: public CfrmConsultas {
public:
  CfrmConClientes(wxWindow *parent);
  ~CfrmConClientes();

protected:
	void OnBtnPesquisar(wxCommandEvent& event);
  void OnBtnLimpar(wxCommandEvent& event);
  void OnBtnFechar(wxCommandEvent& event);
  void OnClose(wxCloseEvent& event);
  void OnGridSelectCell(wxGridEvent& event);
  void OnGridLabelLeftClick(wxGridEvent& event);

private:
  void IniciaControles();
  void InformaLimpaDados(bool bInformar);
  void HabilitaDados(bool bHabilita);

  DECLARE_EVENT_TABLE();	
};

#endif


