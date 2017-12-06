#include "resource.h"
#include "Splash.h"
#include "Login.h"
#include "Principal.h"

#include "xpms/livrusvirtus.xpm"

BEGIN_EVENT_TABLE(CfrmSplash, wxSplashScreen)
    EVT_CLOSE(CfrmSplash::OnClose)
END_EVENT_TABLE()

CfrmSplash::CfrmSplash(wxWindow *parent) 
    : wxSplashScreen(//wxBitmap(BMP_LIVRUSVIRTUS, wxBITMAP_TYPE_BMP),
          wxBitmap(livrusvirtus_xpm),
          wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
          3000, parent, -1, wxDefaultPosition, wxDefaultSize,
          wxSTAY_ON_TOP)
{ }

CfrmSplash::~CfrmSplash() { }

void CfrmSplash::OnClose(wxCloseEvent& event){      
	frmLogin = new CfrmLogin((wxWindow *)NULL);
	frmLogin->Show(true);
	event.Skip();   
}

