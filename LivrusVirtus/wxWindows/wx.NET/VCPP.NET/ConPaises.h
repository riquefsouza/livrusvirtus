#pragma once

#include "Consultas.h"

namespace Livrus
{
	public __gc class frmConPaises : public frmConsultas
	{
  	public:
  		static frmConPaises* fConPaises;

      frmConPaises( wx::Window* parent );
      Void OnClose( System::Object* sender, wx::Event* e );
      Void OnBtnFechar( System::Object* sender, wx::Event* e );
      Void OnBtnLimpar( System::Object* sender, wx::Event* e );
      Void OnBtnPesquisar( System::Object* sender, wx::Event* e );
      Void OnGridSelectCell( System::Object* sender, wx::Event* e );
      Void OnGridLabelLeftClick( System::Object* sender, wx::Event* e );
  };
}
