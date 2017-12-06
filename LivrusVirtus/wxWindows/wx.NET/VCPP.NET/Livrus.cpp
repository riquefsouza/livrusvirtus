#include "stdafx.h"
#include "Livrus.h"
#include "Principal.h"
#include "Splash.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

using namespace Livrus;

Boolean LivrusApp::OnInit(){
  RotinasGlobais::Rotinas = new RotinasGlobais();
  ConsultasSQL::ConsSQL = new ConsultasSQL();
	frmPrincipal::fPrincipal = new frmPrincipal();

  if (RotinasGlobais::Rotinas->ConectaBanco(
    "File Name=C:\\LivrusVirtus\\bancos\\access\\Access2k_Livrus.udl")==false)
    return false;

  frmSplash::fSplash = new frmSplash(0);
  frmSplash::fSplash->Show(true);
	return true;
}    

void __stdcall WinMain()
{
	System::Threading::Thread::CurrentThread->ApartmentState = System::Threading::ApartmentState::STA;

	LivrusApp *aplicativo = new LivrusApp();
	aplicativo->Run();

}
