#include "AlterarSenha.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

GtkWidget *frmAlterarSenha_Criar(void)
{
  GtkWidget *frmAlterarSenha;
  GtkWidget *vbox1;
  GtkWidget *fixed1;
  GtkWidget *labLogin;
  GtkWidget *labSenhaAtual;
  GtkWidget *labNovaSenha;
  GtkWidget *labConfirmaSenha;
  GtkWidget *hbuttonbox1;
  GtkWidget *btnSalvar;
  GtkWidget *btnLimpar;
  GtkWidget *btnFechar;

  frmAlterarSenha = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (frmAlterarSenha, "frmAlterarSenha");
  gtk_window_set_position (GTK_WINDOW(frmAlterarSenha), GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (frmAlterarSenha),
			_("AlteraÃ\247Ã£o de senha"));
  gtk_window_set_resizable (GTK_WINDOW (frmAlterarSenha), FALSE);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (frmAlterarSenha), TRUE);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox1, "vbox1");
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (frmAlterarSenha), vbox1);

  fixed1 = gtk_fixed_new ();
  gtk_widget_set_name (fixed1, "fixed1");
  gtk_widget_show (fixed1);
  gtk_box_pack_start (GTK_BOX (vbox1), fixed1, TRUE, TRUE, 0);
  gtk_widget_set_size_request (fixed1, 280, 105);

  frmAlterarSenha_edtLogin = gtk_entry_new ();
  gtk_widget_set_name (frmAlterarSenha_edtLogin, "edtLogin");
  gtk_widget_show (frmAlterarSenha_edtLogin);
  gtk_fixed_put (GTK_FIXED (fixed1), frmAlterarSenha_edtLogin, 8, 24);
  gtk_widget_set_size_request (frmAlterarSenha_edtLogin, 100, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmAlterarSenha_edtLogin, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmAlterarSenha_edtLogin, GTK_CAN_FOCUS);
  #endif

  labLogin = gtk_label_new (_("Login:"));
  gtk_widget_set_name (labLogin, "labLogin");
  gtk_widget_show (labLogin);
  gtk_fixed_put (GTK_FIXED (fixed1), labLogin, 8, 8);
  gtk_widget_set_size_request (labLogin, 48, 16);
  gtk_misc_set_alignment (GTK_MISC (labLogin), 0, 0.5);

  frmAlterarSenha_edtSenhaAtual = gtk_entry_new ();
  gtk_widget_set_name (frmAlterarSenha_edtSenhaAtual, "edtSenhaAtual");
  gtk_widget_show (frmAlterarSenha_edtSenhaAtual);
  gtk_fixed_put (GTK_FIXED (fixed1), frmAlterarSenha_edtSenhaAtual, 114, 24);
  gtk_widget_set_size_request (frmAlterarSenha_edtSenhaAtual, 100, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmAlterarSenha_edtSenhaAtual), 10);
  gtk_entry_set_visibility (GTK_ENTRY (frmAlterarSenha_edtSenhaAtual), FALSE);

  labSenhaAtual = gtk_label_new (_("Senha atual:"));
  gtk_widget_set_name (labSenhaAtual, "labSenhaAtual");
  gtk_widget_show (labSenhaAtual);
  gtk_fixed_put (GTK_FIXED (fixed1), labSenhaAtual, 114, 8);
  gtk_widget_set_size_request (labSenhaAtual, 88, 16);
  gtk_misc_set_alignment (GTK_MISC (labSenhaAtual), 0, 0.5);

  frmAlterarSenha_edtNovaSenha = gtk_entry_new ();
  gtk_widget_set_name (frmAlterarSenha_edtNovaSenha, "edtNovaSenha");
  gtk_widget_show (frmAlterarSenha_edtNovaSenha);
  gtk_fixed_put (GTK_FIXED (fixed1), frmAlterarSenha_edtNovaSenha, 8, 72);
  gtk_widget_set_size_request (frmAlterarSenha_edtNovaSenha, 100, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmAlterarSenha_edtNovaSenha), 10);
  gtk_entry_set_visibility (GTK_ENTRY (frmAlterarSenha_edtNovaSenha), FALSE);

  frmAlterarSenha_edtConfirmaSenha = gtk_entry_new ();
  gtk_widget_set_name (frmAlterarSenha_edtConfirmaSenha, "edtConfirmaSenha");
  gtk_widget_show (frmAlterarSenha_edtConfirmaSenha);
  gtk_fixed_put (GTK_FIXED (fixed1), frmAlterarSenha_edtConfirmaSenha, 114, 72);
  gtk_widget_set_size_request (frmAlterarSenha_edtConfirmaSenha, 100, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmAlterarSenha_edtConfirmaSenha), 10);
  gtk_entry_set_visibility (GTK_ENTRY (frmAlterarSenha_edtConfirmaSenha), FALSE);

  labNovaSenha = gtk_label_new (_("Nova senha:"));
  gtk_widget_set_name (labNovaSenha, "labNovaSenha");
  gtk_widget_show (labNovaSenha);
  gtk_fixed_put (GTK_FIXED (fixed1), labNovaSenha, 8, 56);
  gtk_widget_set_size_request (labNovaSenha, 96, 16);
  gtk_misc_set_alignment (GTK_MISC (labNovaSenha), 0, 0.5);

  labConfirmaSenha = gtk_label_new (_("Confirma senha:"));
  gtk_widget_set_name (labConfirmaSenha, "labConfirmaSenha");
  gtk_widget_show (labConfirmaSenha);
  gtk_fixed_put (GTK_FIXED (fixed1), labConfirmaSenha, 114, 56);
  gtk_widget_set_size_request (labConfirmaSenha, 120, 16);
  gtk_misc_set_alignment (GTK_MISC (labConfirmaSenha), 0, 0.5);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_set_name (hbuttonbox1, "hbuttonbox1");
  gtk_widget_show (hbuttonbox1);
  gtk_box_pack_start (GTK_BOX (vbox1), hbuttonbox1, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbuttonbox1), 4);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox1), GTK_BUTTONBOX_SPREAD);

  btnSalvar = gtk_button_new_with_mnemonic (_("_Salvar"));
  gtk_widget_set_name (btnSalvar, "btnSalvar");
  gtk_widget_show (btnSalvar);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), btnSalvar);
  GTK_WIDGET_SET_FLAGS (btnSalvar, GTK_CAN_DEFAULT);

  btnLimpar = gtk_button_new_with_mnemonic (_("_Limpar"));
  gtk_widget_set_name (btnLimpar, "btnLimpar");
  gtk_widget_show (btnLimpar);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), btnLimpar);
  GTK_WIDGET_SET_FLAGS (btnLimpar, GTK_CAN_DEFAULT);

  btnFechar = gtk_button_new_with_mnemonic (_("_Fechar"));
  gtk_widget_set_name (btnFechar, "btnFechar");
  gtk_widget_show (btnFechar);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), btnFechar);
  GTK_WIDGET_SET_FLAGS (btnFechar, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) frmAlterarSenha, "destroy",
		    G_CALLBACK (on_frmAlterarSenha_destroy), NULL);
  g_signal_connect ((gpointer) btnSalvar, "clicked",
		    G_CALLBACK (on_frmAlterarSenha_btnSalvar_clicked), NULL);
  g_signal_connect ((gpointer) btnLimpar, "clicked",
		    G_CALLBACK (on_frmAlterarSenha_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) btnFechar, "clicked",
		    G_CALLBACK (on_frmAlterarSenha_btnFechar_clicked), NULL);

  gtk_entry_set_text(GTK_ENTRY(frmAlterarSenha_edtLogin), 
    Rotinas_sUsuarioLogin->str);

  return frmAlterarSenha;
}

void on_frmAlterarSenha_destroy(GtkObject * object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_mnuAlterarsenha, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmAlterarSenha_btnSalvar_clicked(GtkButton * button, 
                                          gpointer user_data) {
  if (frmAlterarSenha_ValidaDados()) {
    if (Rotinas_AtualizaDados(gConexao, 
          ConsSQL_Usuario('U', Rotinas_retTexto(frmAlterarSenha_edtLogin),
          Rotinas_retTexto(frmAlterarSenha_edtConfirmaSenha)))) {
      Rotinas_MsgDlg(STR_SENALTSUC, GTK_MESSAGE_ERROR);
    }         
  }	

}

void on_frmAlterarSenha_btnLimpar_clicked (GtkButton * button, gpointer user_data) {
  gtk_entry_set_text(GTK_ENTRY(frmAlterarSenha_edtSenhaAtual), "");
  gtk_entry_set_text(GTK_ENTRY(frmAlterarSenha_edtNovaSenha), "");
  gtk_entry_set_text(GTK_ENTRY(frmAlterarSenha_edtConfirmaSenha), "");
  gtk_widget_grab_focus(frmAlterarSenha_edtSenhaAtual);
}

void on_frmAlterarSenha_btnFechar_clicked (GtkButton * button, gpointer user_data)
{
  gtk_widget_destroy(frmAlterarSenha);
}

gboolean frmAlterarSenha_ValidaDados() {
  if (strcmp(Rotinas_retTexto(frmAlterarSenha_edtSenhaAtual), 
      Rotinas_sUsuarioSenha->str)!=0) {
     Rotinas_MsgDlg(STR_SENNCSU, GTK_MESSAGE_ERROR);
     return FALSE;
  }
  if (Rotinas_ValidaCampo(
      Rotinas_retTexto(frmAlterarSenha_edtNovaSenha),STR_NSENNINF)) {
  	  return FALSE;
  }
  if (strcmp(Rotinas_retTexto(frmAlterarSenha_edtNovaSenha), 
             Rotinas_retTexto(frmAlterarSenha_edtConfirmaSenha))!=0) {
   Rotinas_MsgDlg(STR_NSENNCCON, GTK_MESSAGE_ERROR);
   return FALSE;
  } 
 return TRUE;
}

