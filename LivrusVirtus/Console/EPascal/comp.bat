c:\comps\djgpp\bin\gpc -c %1.pas
c:\comps\djgpp\bin\gcc -o %1.exe %1.o -lgpc
del *.o
