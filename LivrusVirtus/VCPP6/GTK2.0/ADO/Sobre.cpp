#include "Sobre.h"

GtkWidget *frmSobre;

GtkWidget *frmSobre_Criar()
{
  GdkPixbuf *frmSobre_icon_pixbuf;
  GtkWidget *dialog_vbox1;
  GtkWidget *frame1;
  GtkWidget *alignment1;
  GtkWidget *vbox3;
  GtkWidget *image1;
  GtkWidget *label2;
  GtkWidget *label3;
  GtkWidget *dialog_action_area1;
  GtkWidget *btnOk;

  frmSobre = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (frmSobre), _("Sobre o sistema"));
  gtk_window_set_position (GTK_WINDOW (frmSobre), GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_modal (GTK_WINDOW (frmSobre), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (frmSobre), FALSE);
  frmSobre_icon_pixbuf = gdk_pixbuf_new_from_file ("xpms/livrus.xpm", NULL);
  if (frmSobre_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (frmSobre), frmSobre_icon_pixbuf);
      gdk_pixbuf_unref (frmSobre_icon_pixbuf);
    }
  gtk_window_set_type_hint (GTK_WINDOW (frmSobre), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox1 = GTK_DIALOG (frmSobre)->vbox;

  frame1 = gtk_frame_new (NULL);
  gtk_widget_show (frame1);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), frame1, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame1), 8);
  gtk_frame_set_label_align (GTK_FRAME (frame1), 0, 0);

  alignment1 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (frame1), alignment1);

  vbox3 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox3);
  gtk_container_add (GTK_CONTAINER (alignment1), vbox3);

  image1 = gtk_image_new_from_file("xpms/livrusvirtus.xpm");
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (vbox3), image1, TRUE, TRUE, 0);

  label2 = gtk_label_new (Rotinas_retUTF8("Versão 1.0.0"));
  gtk_widget_show (label2);
  gtk_box_pack_start (GTK_BOX (vbox3), label2, FALSE, FALSE, 2);
  gtk_label_set_justify (GTK_LABEL (label2), GTK_JUSTIFY_RIGHT);
  gtk_misc_set_alignment (GTK_MISC (label2), 1, 0.5);

  label3 = gtk_label_new(
    Rotinas_retUTF8("Todos os direitos reservados para\n" \
    "Henrique F. de Souza\n" \
    "Versão Programada no Visual C++ 6.0 /\n" \
    "Glade 2 usando GTK+"));
  gtk_widget_show (label3);
  gtk_box_pack_start (GTK_BOX (vbox3), label3, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label3), GTK_JUSTIFY_CENTER);
  gtk_label_set_line_wrap (GTK_LABEL (label3), TRUE);

  dialog_action_area1 = GTK_DIALOG (frmSobre)->action_area;
  gtk_widget_show (dialog_action_area1);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area1), GTK_BUTTONBOX_SPREAD);

  btnOk = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (btnOk);
  gtk_dialog_add_action_widget (GTK_DIALOG (frmSobre), btnOk, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (btnOk, GTK_CAN_DEFAULT);

  return frmSobre;
}

