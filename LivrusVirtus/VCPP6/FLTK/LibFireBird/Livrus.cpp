#include "Livrus.h"
#include "Splash.h"
#include "Login.h"
#include "Principal.h"
#include "RotinasGlobais.h"

int main(int argc, char *argv[])
{
  if (!Rotinas->ConectaBanco(
	"C:\\LivrusVirtus\\Bancos\\firebird\\Livrus.fdb", 
	"SYSDBA", "masterkey")) {
     fl_alert(STR_NCONBANCO);
	 return 0;
  }

/*
  frmSplash = new CfrmSplash();
  frmSplash->show(argc, argv);
*/
  frmLogin = new CfrmLogin();
  Fl::visual(FL_DOUBLE|FL_INDEX);
  frmLogin->show();

  return Fl::run();
}

