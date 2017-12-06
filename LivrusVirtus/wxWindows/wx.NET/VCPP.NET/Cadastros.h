#pragma once

#include "TextValidatorCtrl.h"

namespace Livrus
{
	public __gc class frmCadastros : public wx::Panel
	{
    private:
      Void FazLayout();
    protected:
      __value enum idt { 
       ID_FRMCADASTROS_BTNANTERIOR = 400, ID_FRMCADASTROS_BTNEXCLUIR, 
       ID_FRMCADASTROS_BTNFECHAR, ID_FRMCADASTROS_BTNLIMPAR, 
       ID_FRMCADASTROS_BTNNOVO, ID_FRMCADASTROS_BTNPESQUISAR, 
       ID_FRMCADASTROS_BTNPROXIMO, ID_FRMCADASTROS_BTNSALVAR, 
       ID_FRMCADASTROS_EDTCODIGO, ID_FRMCADASTROS_EDTDESCRICAO, 
       ID_FRMCADASTROS_LABCODIGO, ID_FRMCADASTROS_LABDESCRICAO };

		  ArrayList *Registros, *Campos;
		  int nLinhaRegistro;

		  wx::StaticText* labCodigo;
		  TextValidatorCtrl* edtCodigo;
		  wx::StaticText* labDescricao;
		  wx::TextCtrl* edtDescricao;
		  wx::Button* btnNovo;
		  wx::Button* btnPesquisar;
		  wx::Button* btnAnterior;
		  wx::Button* btnProximo;
		  wx::Button* btnFechar;
		  wx::Button* btnLimpar;
		  wx::Button* btnExcluir;
		  wx::Button* btnSalvar;
		  OleDbCommand* Arquiva;

      Void IniciaBotoes();
      Void InformaLimpaDados(Boolean bInformar);
      Void HabilitaDados(Boolean bHabilita);
      Void btnNovoClick();
      Void NovoDado(String* sTextoSql);
      Void btnLimparClick();
      Boolean ExcluirDados(Boolean bValidaDados, String* sTextoSql);
      Boolean PesquisarDados(String* sTextoSql, String* sMensagemErro);
      Boolean registroAnterior();
      Boolean registroProximo();
      Boolean SalvarDados(Boolean bValidaDados, String* sTextoSql,
        String* sTextoUpdate, String* sTextoInsert, Boolean bLimparDados);
  	public:
      frmCadastros( wx::Window* parent, int nFiltroCodigo, 
        Boolean bIniciaBotoes );
  };
}
