
/*** plivrusgn-apph */

#ifndef PLIVRUSGN_APP_H
#define PLIVRUSGN_APP_H

#include <gnome.h>

GtkWidget* plivrusgn_app_new(const gchar* message, 
                         const gchar* geometry,
                         GSList* greet);

void       plivrusgn_app_close(GtkWidget* app);
                         
#endif

/* plivrusgn-apph ***/
