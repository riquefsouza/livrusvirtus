#pragma once

#include "Consultas.h"

namespace Livrus
{
	public __gc class frmConAssuntos : public frmConsultas
	{
  	public:
  		static frmConAssuntos* fConAssuntos;

      frmConAssuntos( wx::Window* parent );
      Void OnClose( System::Object* sender, wx::Event* e );
      Void OnBtnFechar( System::Object* sender, wx::Event* e );
      Void OnBtnLimpar( System::Object* sender, wx::Event* e );
      Void OnBtnPesquisar( System::Object* sender, wx::Event* e );
      Void OnGridSelectCell( System::Object* sender, wx::Event* e );
      Void OnGridLabelLeftClick( System::Object* sender, wx::Event* e );
  };
}
