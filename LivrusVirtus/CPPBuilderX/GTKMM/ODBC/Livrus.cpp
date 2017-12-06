#include "resource.h"
#include "Livrus.h"

int main(int argc, char * argv[]) {
  Gtk::Main kit(argc, argv);

  Rotinas = new CRotinasGlobais();
  frmPrincipal = new CfrmPrincipal();

  if (!Rotinas->ConectaBanco("ACLivrus", "", "")) {
    Rotinas->MsgDlg(STR_NCONBANCO, Gtk::MESSAGE_ERROR);
    return 0;
  }
  /* frmSplash = frmSplash_Criar();
  gtk_widget_show(frmSplash);
  frmSplash_esperaSegundos(3);
  gtk_widget_destroy(frmSplash); */
  frmLogin = new CfrmLogin();
  if (frmLogin->run() == Gtk::RESPONSE_YES) {
    delete frmLogin;
    frmPrincipal->show();

    Rotinas_sBarraLogin = Rotinas->retUTF8(STR_USUARIO) + Rotinas_sUsuarioLogin;

    frmPrincipal->BarraStatus1->push(Rotinas_sBarraLogin,
      frmPrincipal->BarraStatus1->get_context_id("contexto1"));

  } else {
    delete frmLogin;
    return 0;
  }

  Gtk::Main::run(* frmPrincipal);

  return 0;
}
