C:\Comps\tc\tcc -IC:\Comps\tc\INCLUDE -LC:\Comps\tc\LIB -c %1.c
C:\Comps\tc\tlink %1.obj
del *.obj
del *.map
