#pragma once

namespace Livrus
{
	public __gc class frmSplash : public wx::SplashScreen
	{
  	public:
		  static int ID_FRMSPLASH = 100;
  		static frmSplash* fSplash;

      frmSplash( wx::Window* parent );
      System::Void OnClose( System::Object* sender, wx::Event* e );
  };
}
