#pragma once

#include "Cadastros.h"

namespace Livrus
{
	public __gc class frmCadEnderecos : public frmCadastros
	{
    private:
      __value enum idx { 
      ID_FRMCADENDERECOS_CMBESTADO = 700, ID_FRMCADENDERECOS_EDTBAIRRO, 
      ID_FRMCADENDERECOS_EDTCEP, ID_FRMCADENDERECOS_EDTCIDADE, 
      ID_FRMCADENDERECOS_LABBAIRRO, ID_FRMCADENDERECOS_LABCEP, 
      ID_FRMCADENDERECOS_LABCIDADE, ID_FRMCADENDERECOS_LABESTADO };

		  wx::StaticText* labBairro;
		  wx::TextCtrl* edtBairro;
		  wx::TextCtrl* edtCEP;
		  wx::StaticText* labCEP;
		  wx::TextCtrl* edtCidade;
		  wx::StaticText* labCidade;
		  wx::StaticText* labEstado;
		  wx::Choice* cmbEstado;
      String* vsEstados __gc[];

    	Boolean ValidaDados(Boolean bTodosDados);
      Void OnClose( System::Object* sender, wx::Event* e );
      Void OnBtnNovo( System::Object* sender, wx::Event* e );
      Void OnBtnPesquisar( System::Object* sender, wx::Event* e );
      Void OnBtnAnterior( System::Object* sender, wx::Event* e );
      Void OnBtnProximo( System::Object* sender, wx::Event* e );
      Void OnBtnSalvar( System::Object* sender, wx::Event* e );
      Void OnBtnExcluir( System::Object* sender, wx::Event* e );
      Void OnBtnLimpar( System::Object* sender, wx::Event* e );
      Void OnBtnFechar( System::Object* sender, wx::Event* e );
      Void FazLayout();
      Void InformaLimpaDados(Boolean bInformar);
      Void HabilitaDados(Boolean bHabilita);
      Void AdicionaCombo();
  	public:
      frmCadEnderecos( wx::Window* parent );
  };
}
