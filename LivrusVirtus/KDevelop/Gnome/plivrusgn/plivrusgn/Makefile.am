####### kdevelop will overwrite this part!!! (begin)##########
bin_PROGRAMS = plivrusgn

## INCLUDES were found outside kdevelop specific part

plivrusgn_SOURCES = menus.c app.c main.c 
plivrusgn_LDADD   =  $(GNOMEUI_LIBS) $(GNOME_LIBDIR)


EXTRA_DIST = main.c main.h app.c app.h menus.c menus.h 

####### kdevelop will overwrite this part!!! (end)############

INCLUDES = -I$(top_srcdir) -I$(includedir) $(GNOME_INCLUDEDIR) \
         -DG_LOG_DOMAIN=\"Plivrusgn\" -DGNOMELOCALEDIR=\""$(datadir)/locale"\" 

