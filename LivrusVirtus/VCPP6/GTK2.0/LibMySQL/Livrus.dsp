# Microsoft Developer Studio Project File - Name="Livrus" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Livrus - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Livrus.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Livrus.mak" CFG="Livrus - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Livrus - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Livrus - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Livrus - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "C:\GTK\bin"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "c:\gtk\include" /I "c:\gtk\include\gtk-2.0" /I "c:\gtk\include\glib-2.0" /I "c:\gtk\include\pango-1.0" /I "c:\gtk\include\atk-1.0" /I "c:\gtk\include\gtkglext-1.0" /I "c:\gtk\lib\gtk-2.0\include" /I "c:\gtk\lib\glib-2.0\include" /I "c:\gtk\lib\gtkglext-1.0\include" /I "c:\gtk\include\libglade-2.0" /I "c:\gtk\include\libxml2" /I "C:\mysql\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "HAVE_CONFIG_H" /D "__LCC__" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x416 /d "NDEBUG"
# ADD RSC /l 0x416 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 libmySQL.lib art_lgpl_2.lib asprintf.lib atk-1.0.lib charset.lib fontconfig.lib gdk-win32-2.0.lib gdkglext-win32-1.0.lib gdk_pixbuf-2.0.lib glib-2.0.lib gmodule-2.0.lib gobject-2.0.lib gthread-2.0.lib gtk-win32-2.0.lib gtkglext-win32-1.0.lib iconv.lib intl.lib libbz2.lib libfreetype.lib libglade-2.0.lib libiconv.lib libindent.lib libindent_d.lib libintl.lib libjpeg.lib libpng.lib libtiff.lib libxml2.lib libz.lib pango-1.0.lib pangoft2-1.0.lib pangowin32-1.0.lib /nologo /subsystem:console /machine:I386 /libpath:"C:\GTK\Lib" /libpath:"C:\mysql\lib\opt"

!ELSEIF  "$(CFG)" == "Livrus - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "C:\GTK\bin"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "c:\gtk\include" /I "c:\gtk\include\gtk-2.0" /I "c:\gtk\include\glib-2.0" /I "c:\gtk\include\pango-1.0" /I "c:\gtk\include\atk-1.0" /I "c:\gtk\include\gtkglext-1.0" /I "c:\gtk\lib\gtk-2.0\include" /I "c:\gtk\lib\glib-2.0\include" /I "c:\gtk\lib\gtkglext-1.0\include" /I "c:\gtk\include\libglade-2.0" /I "c:\gtk\include\libxml2" /I "C:\mysql\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "HAVE_CONFIG_H" /D "__LCC__" /FD /D /GZ /c
# ADD BASE RSC /l 0x416 /d "_DEBUG"
# ADD RSC /l 0x416 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libmySQL.lib art_lgpl_2.lib asprintf.lib atk-1.0.lib charset.lib fontconfig.lib gdk-win32-2.0.lib gdkglext-win32-1.0.lib gdk_pixbuf-2.0.lib glib-2.0.lib gmodule-2.0.lib gobject-2.0.lib gthread-2.0.lib gtk-win32-2.0.lib gtkglext-win32-1.0.lib iconv.lib intl.lib libbz2.lib libfreetype.lib libglade-2.0.lib libiconv.lib libindent.lib libindent_d.lib libintl.lib libjpeg.lib libpng.lib libtiff.lib libxml2.lib libz.lib pango-1.0.lib pangoft2-1.0.lib pangowin32-1.0.lib /nologo /debug /machine:I386 /pdbtype:sept /libpath:"C:\GTK\Lib" /libpath:"C:\mysql\lib\debug"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "Livrus - Win32 Release"
# Name "Livrus - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AlterarSenha.c
# End Source File
# Begin Source File

SOURCE=.\CadAssuntos.c
# End Source File
# Begin Source File

SOURCE=.\Cadastros.c
# End Source File
# Begin Source File

SOURCE=.\CadAutores.c
# End Source File
# Begin Source File

SOURCE=.\CadClientes.c
# End Source File
# Begin Source File

SOURCE=.\CadEditoras.c
# End Source File
# Begin Source File

SOURCE=.\CadEnderecos.c
# End Source File
# Begin Source File

SOURCE=.\CadIdiomas.c
# End Source File
# Begin Source File

SOURCE=.\CadLivros.c
# End Source File
# Begin Source File

SOURCE=.\CadPaises.c
# End Source File
# Begin Source File

SOURCE=.\CadProfissoes.c
# End Source File
# Begin Source File

SOURCE=.\ConAssuntos.c
# End Source File
# Begin Source File

SOURCE=.\ConAutores.c
# End Source File
# Begin Source File

SOURCE=.\ConClientes.c
# End Source File
# Begin Source File

SOURCE=.\ConEditoras.c
# End Source File
# Begin Source File

SOURCE=.\ConEnderecos.c
# End Source File
# Begin Source File

SOURCE=.\ConIdiomas.c
# End Source File
# Begin Source File

SOURCE=.\ConLivros.c
# End Source File
# Begin Source File

SOURCE=.\ConPaises.c
# End Source File
# Begin Source File

SOURCE=.\ConProfissoes.c
# End Source File
# Begin Source File

SOURCE=.\Consultas.c
# End Source File
# Begin Source File

SOURCE=.\ConsultasSQL.c
# End Source File
# Begin Source File

SOURCE=.\ConVendas.c
# End Source File
# Begin Source File

SOURCE=.\Livrus.c
# End Source File
# Begin Source File

SOURCE=.\Login.c
# End Source File
# Begin Source File

SOURCE=.\Principal.c
# End Source File
# Begin Source File

SOURCE=.\RotinasGlobais.c
# End Source File
# Begin Source File

SOURCE=.\Sobre.c
# End Source File
# Begin Source File

SOURCE=.\Splash.c
# End Source File
# Begin Source File

SOURCE=.\VenderLivros.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AlterarSenha.h
# End Source File
# Begin Source File

SOURCE=.\CadAssuntos.h
# End Source File
# Begin Source File

SOURCE=.\Cadastros.h
# End Source File
# Begin Source File

SOURCE=.\CadAutores.h
# End Source File
# Begin Source File

SOURCE=.\CadClientes.h
# End Source File
# Begin Source File

SOURCE=.\CadEditoras.h
# End Source File
# Begin Source File

SOURCE=.\CadEnderecos.h
# End Source File
# Begin Source File

SOURCE=.\CadIdiomas.h
# End Source File
# Begin Source File

SOURCE=.\CadLivros.h
# End Source File
# Begin Source File

SOURCE=.\CadPaises.h
# End Source File
# Begin Source File

SOURCE=.\CadProfissoes.h
# End Source File
# Begin Source File

SOURCE=.\ConAssuntos.h
# End Source File
# Begin Source File

SOURCE=.\ConAutores.h
# End Source File
# Begin Source File

SOURCE=.\ConClientes.h
# End Source File
# Begin Source File

SOURCE=.\ConEditoras.h
# End Source File
# Begin Source File

SOURCE=.\ConEnderecos.h
# End Source File
# Begin Source File

SOURCE=.\config.h
# End Source File
# Begin Source File

SOURCE=.\ConIdiomas.h
# End Source File
# Begin Source File

SOURCE=.\ConLivros.h
# End Source File
# Begin Source File

SOURCE=.\ConPaises.h
# End Source File
# Begin Source File

SOURCE=.\ConProfissoes.h
# End Source File
# Begin Source File

SOURCE=.\Consultas.h
# End Source File
# Begin Source File

SOURCE=.\ConsultasSQL.h
# End Source File
# Begin Source File

SOURCE=.\ConVendas.h
# End Source File
# Begin Source File

SOURCE=.\Livrus.h
# End Source File
# Begin Source File

SOURCE=.\Login.h
# End Source File
# Begin Source File

SOURCE=.\Principal.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\RotinasGlobais.h
# End Source File
# Begin Source File

SOURCE=.\Sobre.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\VenderLivros.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\xpms\cliente.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\dcliente.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\dlivro.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\dlivros.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\dsair.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\dseta.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\dsobre.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\livro.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\livros.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\livrus.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\livrusvirtus.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\login.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\sair.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\seta.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\sobre.xpm
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
