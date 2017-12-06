#include "Login.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

GtkWidget *frmLogin_Criar()
{
  GdkPixbuf *frmLogin_icon_pixbuf;
  GtkWidget *dialog_vbox1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *table1;
  GtkWidget *labLogin;
  GtkWidget *labSenha;
  GtkWidget *hbuttonbox1;
  GtkWidget *btnLogin;
  GtkWidget *btnCancelar;

  frmLogin = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (frmLogin), _("Login do Sistema"));
  gtk_window_set_position (GTK_WINDOW (frmLogin), GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_modal (GTK_WINDOW (frmLogin), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (frmLogin), FALSE);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (frmLogin), TRUE);
  frmLogin_icon_pixbuf = gdk_pixbuf_new_from_file ("xpms/livrus.xpm", NULL);
  if (frmLogin_icon_pixbuf){
    gtk_window_set_icon (GTK_WINDOW (frmLogin), frmLogin_icon_pixbuf);
    gdk_pixbuf_unref (frmLogin_icon_pixbuf);
  }
  gtk_dialog_set_has_separator(GTK_DIALOG(frmLogin), FALSE); 
  gtk_window_set_type_hint (GTK_WINDOW (frmLogin), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox1 = GTK_DIALOG (frmLogin)->vbox;
  gtk_widget_show (dialog_vbox1);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), hbox1, TRUE, TRUE, 0);

  image1 = gtk_image_new_from_file("xpms/login.xpm");
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, TRUE, TRUE, 0);
  gtk_widget_set_size_request (image1, 100, 100);

  table1 = gtk_table_new (4, 1, FALSE);
  gtk_widget_show (table1);
  gtk_box_pack_start (GTK_BOX (hbox1), table1, TRUE, TRUE, 0);

  labLogin = gtk_label_new (_("Login:"));
  gtk_widget_show (labLogin);
  gtk_table_attach (GTK_TABLE (table1), labLogin, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (labLogin), 0, 0.5);

  labSenha = gtk_label_new (_("Senha:"));
  gtk_widget_show (labSenha);
  gtk_table_attach (GTK_TABLE (table1), labSenha, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (labSenha), 0, 0.5);

  frmLogin_edtLogin = gtk_entry_new ();
  gtk_widget_show (frmLogin_edtLogin);
  gtk_table_attach (GTK_TABLE (table1), frmLogin_edtLogin, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_SHRINK),
                    (GtkAttachOptions) (GTK_SHRINK), 0, 4);
  gtk_widget_set_size_request (frmLogin_edtLogin, 100, 21);
  gtk_entry_set_max_length (GTK_ENTRY (frmLogin_edtLogin), 10);

  frmLogin_edtSenha = gtk_entry_new ();
  gtk_widget_show (frmLogin_edtSenha);
  gtk_table_attach (GTK_TABLE (table1), frmLogin_edtSenha, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_SHRINK),
                    (GtkAttachOptions) (GTK_SHRINK), 0, 4);
  gtk_widget_set_size_request (frmLogin_edtSenha, 100, 21);
  gtk_entry_set_max_length (GTK_ENTRY (frmLogin_edtSenha), 10);
  gtk_entry_set_visibility (GTK_ENTRY (frmLogin_edtSenha), FALSE);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox1);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), hbuttonbox1, TRUE, TRUE, 0);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox1), GTK_BUTTONBOX_SPREAD);

  btnLogin = gtk_button_new_with_mnemonic (_("_Login"));
  gtk_widget_show (btnLogin);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), btnLogin);
  GTK_WIDGET_SET_FLAGS (btnLogin, GTK_CAN_DEFAULT);

  btnCancelar = gtk_button_new_with_mnemonic (_("_Cancelar"));
  gtk_widget_show (btnCancelar);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), btnCancelar);
  GTK_WIDGET_SET_FLAGS (btnCancelar, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) btnLogin, "clicked",
    G_CALLBACK (on_frmLogin_btnLogin_clicked), NULL);
  g_signal_connect ((gpointer) btnCancelar, "clicked",
    G_CALLBACK (on_frmLogin_btnCancelar_clicked), NULL);

  return frmLogin;
}

void on_frmLogin_btnLogin_clicked(GtkButton *button, gpointer user_data)
{
  if (Rotinas_ConsultaDados(gConexao, 
      ConsSQL_Usuario('S', Rotinas_retTexto(frmLogin_edtLogin), 
      Rotinas_retTexto(frmLogin_edtSenha))) ) {

     Rotinas_sUsuarioLogin = g_string_new("");
     Rotinas_sUsuarioSenha = g_string_new("");
     g_string_assign(Rotinas_sUsuarioLogin, 
       Rotinas_retTexto(frmLogin_edtLogin));
     g_string_assign(Rotinas_sUsuarioSenha, 
       Rotinas_retTexto(frmLogin_edtSenha));
     
     gtk_dialog_response(GTK_DIALOG(frmLogin), GTK_RESPONSE_YES);     
  } else
     Rotinas_MsgDlg(STR_LOGSENINC, GTK_MESSAGE_ERROR);
}

void on_frmLogin_btnCancelar_clicked(GtkButton *button, gpointer user_data)
{
  gtk_dialog_response(GTK_DIALOG(frmLogin), GTK_RESPONSE_NO);
}

