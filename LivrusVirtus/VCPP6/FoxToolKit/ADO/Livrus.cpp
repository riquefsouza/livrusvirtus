#include "resource.h"
#include "Livrus.h"

int main(int argc,char *argv[]){

  FXApp CLivrusApp("Livrus", STR_TITULO);
  CLivrusApp.init(argc,argv); 

  Rotinas = new CRotinasGlobais(&CLivrusApp);
  frmPrincipal = new CfrmPrincipal(&CLivrusApp);
  frmLogin = new CfrmLogin(&CLivrusApp); 
  frmSplash = new CfrmSplash(&CLivrusApp);

  CLivrusApp.create();

  if (!Rotinas->ConectaBanco(
    "FILE NAME=C:\\LivrusVirtus\\Bancos\\access\\Access2k_Livrus.udl")) {
	  return FALSE;
  } else {
   frmSplash->iniciaTimer();
   frmSplash->show(PLACEMENT_SCREEN);
  }
  
  return CLivrusApp.run();
}
