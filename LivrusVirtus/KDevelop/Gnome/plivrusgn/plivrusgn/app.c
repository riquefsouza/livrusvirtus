
/*** plivrusgn-app */

#include <config.h>
#include "app.h"
#include "menus.h"

/* Keep a list of all open application windows */
static GSList* app_list = NULL;

static gint delete_event_cb(GtkWidget* w, GdkEventAny* e, gpointer data);
static void button_click_cb(GtkWidget* w, gpointer data);

GtkWidget* 
plivrusgn_app_new(const gchar* message, 
              const gchar* geometry,
              GSList* greet)
{
  GtkWidget* app;
  GtkWidget* button;
  GtkWidget* label;
  GtkWidget* status;
  GtkWidget* frame;

  /*** plivrusgn-widgets */
  app = gnome_app_new(PACKAGE, _("Plivrusgn"));

  frame = gtk_frame_new(NULL);

  button = gtk_button_new();

  label  = gtk_label_new(message ? message : _("Hello, World!"));

  gtk_window_set_policy(GTK_WINDOW(app), FALSE, TRUE, FALSE);
  gtk_window_set_default_size(GTK_WINDOW(app), 250, 350);
  gtk_window_set_wmclass(GTK_WINDOW(app), "hello", "Plivrusgn");

  gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);

  gtk_container_set_border_width(GTK_CONTAINER(button), 10);

  gtk_container_add(GTK_CONTAINER(button), label);

  gtk_container_add(GTK_CONTAINER(frame), button);

  gnome_app_set_contents(GNOME_APP(app), frame);

  status = gnome_appbar_new(FALSE, TRUE, GNOME_PREFERENCES_NEVER);

  gnome_app_set_statusbar(GNOME_APP(app), status);

  plivrusgn_install_menus_and_toolbar(app);

  /* plivrusgn-widgets ***/
  
  /*** plivrusgn-signals */
  gtk_signal_connect(GTK_OBJECT(app),
                     "delete_event",
                     GTK_SIGNAL_FUNC(delete_event_cb),
                     NULL);

  gtk_signal_connect(GTK_OBJECT(button),
                     "clicked",
                     GTK_SIGNAL_FUNC(button_click_cb),
                     label);
  /* plivrusgn-signals ***/

  /*** plivrusgn-geometry */
  if (geometry != NULL) 
    {
      gint x, y, w, h;
      if ( gnome_parse_geometry( geometry, 
                                 &x, &y, &w, &h ) ) 
        {
          if (x != -1)
            {
              gtk_widget_set_uposition(app, x, y);
            }

          if (w != -1) 
            {
              gtk_window_set_default_size(GTK_WINDOW(app), w, h);
            }
        }
      else 
        {
          g_error(_("Could not parse geometry string `%s'"), geometry);
        }
    }

  /* plivrusgn-geometry ***/

  if (greet != NULL)
    {
      GtkWidget* dialog;
      gchar* greetings = g_strdup(_("Special Greetings to:\n"));
      GSList* tmp = greet;

      while (tmp != NULL)
        {
          gchar* old = greetings;

          greetings = g_strconcat(old, 
                                  (gchar*) tmp->data,
                                  "\n",
                                  NULL);
          g_free(old);

          tmp = g_slist_next(tmp);
        }
      
      dialog = gnome_ok_dialog(greetings);

      g_free(greetings);

      gnome_dialog_set_parent(GNOME_DIALOG(dialog), GTK_WINDOW(app));
    }

  app_list = g_slist_prepend(app_list, app);

  return app;
}

void       
plivrusgn_app_close(GtkWidget* app)
{
  g_return_if_fail(GNOME_IS_APP(app));

  app_list = g_slist_remove(app_list, app);

  gtk_widget_destroy(app);

  if (app_list == NULL)
    {
      /* No windows remaining */
      gtk_main_quit();
    }
}

/*** plivrusgn-quit */
static gint 
delete_event_cb(GtkWidget* window, GdkEventAny* e, gpointer data)
{
  plivrusgn_app_close(window);

  /* Prevent the window's destruction, since we destroyed it 
   * ourselves with plivrusgn_app_close()
   */
  return TRUE;
}
/* plivrusgn-quit ***/

static void 
button_click_cb(GtkWidget* w, gpointer data)
{
  GtkWidget* label;
  gchar* text;
  gchar* tmp;

  label = GTK_WIDGET(data);

  gtk_label_get(GTK_LABEL(label), &text);

  tmp = g_strdup(text);

  g_strreverse(tmp);

  gtk_label_set_text(GTK_LABEL(label), tmp);

  g_free(tmp);
}

/* plivrusgn-app ***/
