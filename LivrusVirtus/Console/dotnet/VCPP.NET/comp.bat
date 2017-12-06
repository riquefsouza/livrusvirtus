cl.exe /Zi /clr /c /FeLivrus.exe %1.cpp
link.exe /OUT:Livrus.exe %1.obj
del *.obj