####### kdevelop will overwrite this part!!! (begin)##########
bin_PROGRAMS = plivrusqt

## INCLUDES were found outside kdevelop specific part

plivrusqt_SOURCES = plivrusqtview.cpp plivrusqtdoc.cpp plivrusqt.cpp main.cpp 
SOURCES = plivrusqtview.cpp plivrusqtdoc.cpp plivrusqt.cpp main.cpp 
INTERFACES = 
TRANSLATIONS = 
KDE_OPTIONS = qtonly
plivrusqt_LDADD   =  $(LIB_QPE) $(LIB_QT) $(LIBSOCKET)


EXTRA_DIST = main.cpp plivrusqt.cpp plivrusqt.h plivrusqtdoc.cpp plivrusqtdoc.h plivrusqtview.cpp plivrusqtview.h lo32-app-plivrusqt.png lo16-app-plivrusqt.png filenew.xpm filesave.xpm fileopen.xpm 

####### kdevelop will overwrite this part!!! (end)############


# set the include path for X, qt and KDE
INCLUDES= $(all_includes)

plivrusqt_METASOURCES = AUTO

# the library search path. 
plivrusqt_LDFLAGS = $(all_libraries) 

# them while "make clean", use CLEANFILES
DISTCLEANFILES = $(plivrusqt_METASOURCES)

