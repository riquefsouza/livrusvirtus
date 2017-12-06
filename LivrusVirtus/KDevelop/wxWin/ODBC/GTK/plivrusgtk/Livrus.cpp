#include "resource.h"
#include "Livrus.h"
#include "Splash.h"
#include "Login.h"
#include "Principal.h"
#include "RotinasGlobais.h"

IMPLEMENT_APP(CLivrusApp)

bool CLivrusApp::OnInit() {
    const wxString nomeApp = "livrus";
    checaInstanciaUnica = new wxSingleInstanceChecker(nomeApp);

    if ( checaInstanciaUnica->IsAnotherRunning() ) {
        wxLogError(STR_APPEXEC);
        return FALSE;
    }

	frmPrincipal = new CfrmPrincipal((wxFrame *)NULL);
	SetTopWindow(frmPrincipal);

  if (!Rotinas->ConectaBanco("pglivrus","hfs","")) {
   wxMessageBox(wxT(STR_NCONBANCO),wxT("Erro"), wxOK | wxICON_ERROR);
	 return FALSE;
  }

	CfrmSplash *frmSplash = new CfrmSplash((wxWindow *)NULL);
	frmSplash->Show();

	return TRUE;  
}

int CLivrusApp::OnExit() {
    delete checaInstanciaUnica;
    return 0;
}

