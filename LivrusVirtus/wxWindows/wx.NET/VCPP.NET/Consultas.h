#pragma once

namespace Livrus
{
	public __gc class frmConsultas : public wx::Dialog
	{
    private:
      String* sSelecionado;
      Void FazLayout();
    protected:
      __value enum idt { 
      ID_FRMCONSULTAS_BTNFECHAR = 500, ID_FRMCONSULTAS_BTNLIMPAR, 
      ID_FRMCONSULTAS_BTNPESQUISAR, ID_FRMCONSULTAS_EDTDESCRICAO, 
      ID_FRMCONSULTAS_GRIDCONSULTA, ID_FRMCONSULTAS_LABDESCRICAO, 
      ID_FRMCONSULTAS_LABREGISTRO };

		  ArrayList *Registros, *Campos;

		  wx::StaticText* labDescricao;
		  wx::TextCtrl* edtDescricao;
		  wx::Button* btnPesquisar;
		  wx::StaticText* labRegistro;
		  wx::Grid* gridConsulta;
		  wx::Button* btnFechar;
		  wx::Button* btnLimpar;

      Void Fecha(int nIndMenu);
      Void LimparDados();
      Void PesquisarDados(String* sTextoSql, String* sMensagemErro, 
        int nQtdCol);
      Void setLabRegistros(int nLinha);
  	public:
      frmConsultas( wx::Window* parent );
  };
}
