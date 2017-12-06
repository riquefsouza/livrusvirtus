
/*** plivrusgn */

#include <config.h>
#include <gnome.h>

#include "app.h"


static gint session_die(GnomeClient* client, gpointer client_data);

static gint save_session(GnomeClient *client, gint phase, 
                         GnomeSaveStyle save_style,
                         gint is_shutdown, GnomeInteractStyle interact_style,
                         gint is_fast, gpointer client_data);


/*** plivrusgn-popttable */
static int greet_mode = FALSE;
static char* message  = NULL;
static char* geometry = NULL;

struct poptOption options[] = {
  {
    "greet",
    'g',
    POPT_ARG_NONE,
    &greet_mode,
    0,
    N_("Say hello to specific people listed on the command line"),
    NULL
  },
  { 
    "message",
    'm',
    POPT_ARG_STRING,
    &message,
    0,
    N_("Specify a message other than \"Hello, World!\""),
    N_("MESSAGE")
  },
  { 
    "geometry",
    '\0',
    POPT_ARG_STRING,
    &geometry,
    0,
    N_("Specify the geometry of the main window"),
    N_("GEOMETRY")
  },
  {
    NULL,
    '\0',
    0,
    NULL,
    0,
    NULL,
    NULL
  }
};
/* plivrusgn-popttable ***/

int 
main(int argc, char* argv[])
{
  /*** plivrusgn-parsing */
  GtkWidget* app;
  
  poptContext pctx;

  char** args;
  int i;

  GSList* greet = NULL;

  GnomeClient* client;

  bindtextdomain(PACKAGE, GNOMELOCALEDIR);  
  textdomain(PACKAGE);

  gnome_init_with_popt_table(PACKAGE, VERSION, argc, argv, 
                             options, 0, &pctx);  

  /* Argument parsing */

  args = poptGetArgs(pctx);

  if (greet_mode && args)
    {
      i = 0;
      while (args[i] != NULL) 
        {
          greet = g_slist_prepend(greet, args[i]);
          ++i;
        }
      /* Put them in order */
      greet = g_slist_reverse(greet); 
    }
  else if (greet_mode && args == NULL)
    {
      g_error(_("You must specify someone to greet."));
    }
  else if (args != NULL)
    {
      g_error(_("Command line arguments are only allowed with --greet."));
    }
  else
    { 
      g_assert(!greet_mode && args == NULL);
    }

  poptFreeContext(pctx);
  /* plivrusgn-parsing ***/

  /* Session Management */
  
  /*** plivrusgn-client */
  client = gnome_master_client ();
  gtk_signal_connect (GTK_OBJECT (client), "save_yourself",
                      GTK_SIGNAL_FUNC (save_session), argv[0]);
  gtk_signal_connect (GTK_OBJECT (client), "die",
                      GTK_SIGNAL_FUNC (session_die), NULL);
  /* plivrusgn-client ***/

  
  /* Main app */

  app = plivrusgn_app_new(message, geometry, greet);

  g_slist_free(greet);

  /*** plivrusgn-main */
  gtk_widget_show_all(app);

  gtk_main();

  return 0;
  /* plivrusgn-main ***/
}

/*** plivrusgn-save-session */
static gint
save_session (GnomeClient *client, gint phase, GnomeSaveStyle save_style,
              gint is_shutdown, GnomeInteractStyle interact_style,
              gint is_fast, gpointer client_data)
{
  gchar** argv;
  guint argc;

  /* allocate 0-filled, so it will be NULL-terminated */
  argv = g_malloc0(sizeof(gchar*)*4);
  argc = 1;

  argv[0] = client_data;

  if (message)
    {
      argv[1] = "--message";
      argv[2] = message;
      argc = 3;
    }
  
  gnome_client_set_clone_command (client, argc, argv);
  gnome_client_set_restart_command (client, argc, argv);

  return TRUE;
}
/* plivrusgn-save-session ***/

/*** plivrusgn-session-die */
static gint 
session_die(GnomeClient* client, gpointer client_data)
{
  gtk_main_quit ();
  return TRUE;
}
/* plivrusgn-session-die ***/

/* plivrusgn ***/
