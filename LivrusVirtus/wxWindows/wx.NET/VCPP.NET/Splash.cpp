#include "stdafx.h"
#include "Splash.h"
#include "Login.h"

namespace Livrus
{
  frmSplash::frmSplash( wx::Window* parent )
  	: wx::SplashScreen( new wx::Bitmap("xpms/LivrusVirtus.xpm", 
      wx::BitmapType::wxBITMAP_TYPE_XPM), 
      wx::SplashScreen::wxSPLASH_CENTRE_ON_SCREEN | wx::SplashScreen::wxSPLASH_TIMEOUT, 
      1000, parent, ID_FRMSPLASH, wxDefaultPosition, wxDefaultSize, 
      wxSIMPLE_BORDER | wxSTAY_ON_TOP )
  {
  	EVT_CLOSE( new wx::EventListener( this, OnClose ) );
  }

  System::Void frmSplash::OnClose( System::Object* sender, wx::Event* e )
  {
    frmLogin::fLogin = new frmLogin(0);
    frmLogin::fLogin->Show(true);
  	e->Skip();
  }
}
