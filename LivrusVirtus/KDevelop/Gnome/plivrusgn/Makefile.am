####### kdevelop will overwrite this part!!! (begin)##########

SUBDIRS = plivrusgn macros pixmaps 

EXTRA_DIST = plivrusgn.kdevprj AUTHORS COPYING ChangeLog INSTALL README TODO plivrusgn.desktop 

install-data-local:
	$(mkinstalldirs) $(datadir)/gnome/apps/Applications/
	$(INSTALL_DATA) $(srcdir)/plivrusgn.desktop $(datadir)/gnome/apps/Applications/

uninstall-local:
	-rm -f $(datadir)/gnome/apps/Applications/

####### kdevelop will overwrite this part!!! (end)############
AUTOMAKE_OPTIONS=foreign
