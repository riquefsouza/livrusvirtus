#include "Splash.h"

GtkWidget *frmSplash_Criar()
{
  GtkWidget *frmSplash_image1;
  GtkWidget *dialog_vbox1;
  GtkWidget *frame1;

  frmSplash = gtk_dialog_new ();
  gtk_widget_set_size_request (frmSplash, -1, 60);
  gtk_container_set_border_width (GTK_CONTAINER (frmSplash), 1);
  gtk_window_set_position (GTK_WINDOW (frmSplash), GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_modal (GTK_WINDOW (frmSplash), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (frmSplash), FALSE);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (frmSplash), TRUE);
  gtk_window_set_decorated (GTK_WINDOW (frmSplash), FALSE);
  gtk_window_set_type_hint (GTK_WINDOW (frmSplash), GDK_WINDOW_TYPE_HINT_DIALOG);
  gtk_dialog_set_has_separator (GTK_DIALOG (frmSplash), FALSE);

  dialog_vbox1 = GTK_DIALOG (frmSplash)->vbox;
  gtk_widget_show (dialog_vbox1);

  frame1 = gtk_frame_new (NULL);
  gtk_widget_show (frame1);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), frame1, TRUE, TRUE, 0);
  gtk_frame_set_label_align (GTK_FRAME (frame1), 0, 0);

  frmSplash_image1 = gtk_image_new_from_file("xpms/livrusvirtus.xpm");
  gtk_widget_show (frmSplash_image1);
  gtk_container_add (GTK_CONTAINER (frame1), frmSplash_image1);

  return frmSplash;
}

void frmSplash_esperaSegundos(gint nSegs) {
GTimer *gTimer;
gulong nMicroSegundos = nSegs * 1000;
gdouble nSegundos;

  gTimer = g_timer_new();
  g_timer_start(gTimer);

  while (TRUE) {
    nSegundos = g_timer_elapsed(gTimer, &nMicroSegundos);
    //g_print("segs = %f\n", nSegundos);
    if (nSegundos > nSegs) {
      g_timer_stop(gTimer);
      g_timer_destroy(gTimer);
      break;
    }
  }
}
