#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "RotinasGlobais.h"

class CfrmConsultas: public wxDialog {
public:
  CfrmConsultas(wxWindow *parent);
  ~CfrmConsultas();

protected:  
  wxStaticText *labDescricao;
  wxTextCtrl *edtDescricao;
  wxButton *btnPesquisar;
  wxStaticText *labRegistro;
  wxGrid *gridConsulta;
  wxButton *btnFechar;
  wxButton *btnLimpar;

  void Fecha(int nIndMenu);
  void LimparDados();
  void PesquisarDados(wxString sTextoSql, wxString sMensagemErro, 
    unsigned long nQtdCol);
  void setLabRegistros(int nLinha);

private:
  LISTAMSTR lstLinhas;
  wxString sSelecionado;
  int nRegistro;

  void IniciaControles();
  void FazLayout();

};

enum {
 ID_FRMCONSULTAS_BTNFECHAR = 500, ID_FRMCONSULTAS_BTNLIMPAR, 
 ID_FRMCONSULTAS_BTNPESQUISAR, ID_FRMCONSULTAS_EDTDESCRICAO, 
 ID_FRMCONSULTAS_GRIDCONSULTA, ID_FRMCONSULTAS_LABDESCRICAO, 
 ID_FRMCONSULTAS_LABREGISTRO 
};

#endif


