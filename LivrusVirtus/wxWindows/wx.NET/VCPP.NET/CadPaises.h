#pragma once

#include "Cadastros.h"

namespace Livrus
{
	public __gc class frmCadPaises : public frmCadastros
	{
    private:
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
  	public:
      frmCadPaises( wx::Window* parent );
  };
}
