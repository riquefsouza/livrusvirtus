#include "Livrus.h"
#include "RotinasGlobais.h"
#include "Splash.h"
#include "Principal.h"
#include "Login.h"

int main(int argc, char *argv[]) {    

#ifdef G_OS_WIN32
    gchar *temp;

    package_prefix = g_win32_get_package_installation_directory(NULL, NULL);
  	package_datadir = g_strdup_printf("%s%s", package_prefix, "");
#endif

#ifdef ENABLE_NLS
#ifdef G_OS_WIN32
    temp = g_strdup_printf("%s%s", package_prefix, "/lib/locale");
    bindtextdomain(GETTEXT_PACKAGE, temp);
    g_free(temp);
#else
     //bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
     bindtextdomain (GETTEXT_PACKAGE, "/usr/local/share/locale");
#endif
    bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
    textdomain(GETTEXT_PACKAGE);
#endif

  gtk_set_locale();
  gtk_init(&argc, &argv);

  frmPrincipal = frmPrincipal_Criar();

  if (!Rotinas_ConectaBanco("Livrus", "postgres","temp")) {
    Rotinas_MsgDlg(STR_NCONBANCO, GTK_MESSAGE_ERROR);
	  exit(1);
  }

  frmSplash = frmSplash_Criar();
  //gtk_dialog_run(GTK_DIALOG(frmSplash));
  gtk_widget_show(frmSplash);
  frmSplash_esperaSegundos(3);
  gtk_widget_destroy(frmSplash);

	frmLogin = frmLogin_Criar();	
  if (gtk_dialog_run(GTK_DIALOG(frmLogin))==GTK_RESPONSE_YES) {
    gtk_widget_destroy(frmLogin);
    gtk_widget_show(frmPrincipal);

    Rotinas_sBarraLogin = g_string_new("");
    g_string_sprintf(Rotinas_sBarraLogin, "%s%s", Rotinas_retUTF8(STR_USUARIO), 
      Rotinas_sUsuarioLogin->str);
   
    gtk_statusbar_push(GTK_STATUSBAR(frmPrincipal_barraStatus1),
      gtk_statusbar_get_context_id(
      GTK_STATUSBAR(frmPrincipal_barraStatus1), "contexto1"), 
      Rotinas_sBarraLogin->str);

  } else {
    gtk_widget_destroy(frmLogin);
    exit(0);
  }

  gtk_widget_show(frmPrincipal);
  gtk_main();

#ifdef G_OS_WIN32
    g_free(package_prefix);
    g_free(package_datadir);
#endif
    return 0;
}


