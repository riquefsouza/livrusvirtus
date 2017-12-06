/*
 * NÃO EDITAR ESTE ARQUIVO - é gerado pelo Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

GtkWidget*
create_frmPrincipal (void)
{
  GtkWidget *frmPrincipal;
  GtkWidget *vbox1;
  GtkWidget *menubar1;
  guint tmp_key;
  GtkWidget *mnuCadastros;
  GtkWidget *mnuCadastros_menu;
  GtkAccelGroup *mnuCadastros_menu_accels;
  GtkWidget *mnuCadAssuntos;
  GtkWidget *toolbar1;
  GtkWidget *tmp_toolbar_icon;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;
  GtkWidget *vseparator1;
  GtkWidget *button4;
  GtkWidget *button5;
  GtkWidget *fixed1;
  GtkWidget *hbox1;
  GtkWidget *statusbar1;
  GtkWidget *statusbar2;
  GtkAccelGroup *accel_group;

  accel_group = gtk_accel_group_new ();

  frmPrincipal = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_object_set_data (GTK_OBJECT (frmPrincipal), "frmPrincipal", frmPrincipal);
  gtk_widget_set_usize (frmPrincipal, 400, 300);
  gtk_window_set_title (GTK_WINDOW (frmPrincipal), _("Livrus Virtus"));
  gtk_window_set_position (GTK_WINDOW (frmPrincipal), GTK_WIN_POS_CENTER);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_ref (vbox1);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "vbox1", vbox1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (frmPrincipal), vbox1);

  menubar1 = gtk_menu_bar_new ();
  gtk_widget_ref (menubar1);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "menubar1", menubar1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (menubar1);
  gtk_box_pack_start (GTK_BOX (vbox1), menubar1, FALSE, FALSE, 0);

  mnuCadastros = gtk_menu_item_new_with_label ("");
  tmp_key = gtk_label_parse_uline (GTK_LABEL (GTK_BIN (mnuCadastros)->child),
                                   _("_Cadastros"));
  gtk_widget_add_accelerator (mnuCadastros, "activate_item", accel_group,
                              tmp_key, GDK_MOD1_MASK, (GtkAccelFlags) 0);
  gtk_widget_ref (mnuCadastros);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "mnuCadastros", mnuCadastros,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (mnuCadastros);
  gtk_container_add (GTK_CONTAINER (menubar1), mnuCadastros);

  mnuCadastros_menu = gtk_menu_new ();
  gtk_widget_ref (mnuCadastros_menu);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "mnuCadastros_menu", mnuCadastros_menu,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mnuCadastros), mnuCadastros_menu);
  mnuCadastros_menu_accels = gtk_menu_ensure_uline_accel_group (GTK_MENU (mnuCadastros_menu));

  mnuCadAssuntos = gtk_menu_item_new_with_label (_("Assuntos"));
  gtk_widget_ref (mnuCadAssuntos);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "mnuCadAssuntos", mnuCadAssuntos,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (mnuCadAssuntos);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), mnuCadAssuntos);

  toolbar1 = gtk_toolbar_new (GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_ICONS);
  gtk_widget_ref (toolbar1);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "toolbar1", toolbar1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (toolbar1);
  gtk_box_pack_start (GTK_BOX (vbox1), toolbar1, FALSE, FALSE, 0);

  tmp_toolbar_icon = create_pixmap (frmPrincipal, "cliente.xpm");
  button1 = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
                                GTK_TOOLBAR_CHILD_BUTTON,
                                NULL,
                                "",
                                NULL, NULL,
                                tmp_toolbar_icon, NULL, NULL);
  gtk_widget_ref (button1);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "button1", button1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button1);

  tmp_toolbar_icon = create_pixmap (frmPrincipal, "livro.xpm");
  button2 = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
                                GTK_TOOLBAR_CHILD_BUTTON,
                                NULL,
                                "",
                                NULL, NULL,
                                tmp_toolbar_icon, NULL, NULL);
  gtk_widget_ref (button2);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "button2", button2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button2);

  tmp_toolbar_icon = create_pixmap (frmPrincipal, "livros.xpm");
  button3 = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
                                GTK_TOOLBAR_CHILD_BUTTON,
                                NULL,
                                "",
                                NULL, NULL,
                                tmp_toolbar_icon, NULL, NULL);
  gtk_widget_ref (button3);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "button3", button3,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button3);

  vseparator1 = gtk_vseparator_new ();
  gtk_widget_ref (vseparator1);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "vseparator1", vseparator1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (vseparator1);
  gtk_toolbar_append_widget (GTK_TOOLBAR (toolbar1), vseparator1, NULL, NULL);

  tmp_toolbar_icon = create_pixmap (frmPrincipal, "sobre.xpm");
  button4 = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
                                GTK_TOOLBAR_CHILD_BUTTON,
                                NULL,
                                "",
                                NULL, NULL,
                                tmp_toolbar_icon, NULL, NULL);
  gtk_widget_ref (button4);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "button4", button4,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button4);

  tmp_toolbar_icon = create_pixmap (frmPrincipal, "sair.xpm");
  button5 = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
                                GTK_TOOLBAR_CHILD_BUTTON,
                                NULL,
                                "",
                                NULL, NULL,
                                tmp_toolbar_icon, NULL, NULL);
  gtk_widget_ref (button5);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "button5", button5,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (button5);

  fixed1 = gtk_fixed_new ();
  gtk_widget_ref (fixed1);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "fixed1", fixed1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (fixed1);
  gtk_box_pack_start (GTK_BOX (vbox1), fixed1, TRUE, TRUE, 0);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (hbox1);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "hbox1", hbox1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox1, FALSE, TRUE, 0);

  statusbar1 = gtk_statusbar_new ();
  gtk_widget_ref (statusbar1);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "statusbar1", statusbar1,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (statusbar1);
  gtk_box_pack_start (GTK_BOX (hbox1), statusbar1, FALSE, FALSE, 0);
  gtk_widget_set_usize (statusbar1, 120, 21);

  statusbar2 = gtk_statusbar_new ();
  gtk_widget_ref (statusbar2);
  gtk_object_set_data_full (GTK_OBJECT (frmPrincipal), "statusbar2", statusbar2,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (statusbar2);
  gtk_box_pack_start (GTK_BOX (hbox1), statusbar2, TRUE, TRUE, 0);
  gtk_widget_set_usize (statusbar2, -2, 21);

  gtk_signal_connect (GTK_OBJECT (mnuCadastros), "activate",
                      GTK_SIGNAL_FUNC (on_mnuCadastros_activate),
                      NULL);
  gtk_signal_connect (GTK_OBJECT (mnuCadAssuntos), "activate",
                      GTK_SIGNAL_FUNC (on_mnuCadAssuntos_activate),
                      NULL);

  gtk_window_add_accel_group (GTK_WINDOW (frmPrincipal), accel_group);

  return frmPrincipal;
}

