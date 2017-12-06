# Microsoft Developer Studio Project File - Name="Livrus" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Livrus - Win32 Release DLL
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Livrus.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Livrus.mak" CFG="Livrus - Win32 Release DLL"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Livrus - Win32 Release DLL" (based on "Win32 (x86) Application")
!MESSAGE "Livrus - Win32 Debug DLL" (based on "Win32 (x86) Application")
!MESSAGE "Livrus - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Livrus - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Livrus - Win32 Release DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseDll"
# PROP BASE Intermediate_Dir "ReleaseDll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDll"
# PROP Intermediate_Dir "ReleaseDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /YX /FD /c
# ADD CPP /nologo /MD /W4 /O2 /I "C:/wxWin/include" /I "C:/wxWin/lib/mswdll" /I "C:\Arquivos de programas\PostgreSQL\8.0.0-rc1\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /D "_MT" /D wxUSE_GUI=1 /D "WXUSINGDLL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "../../include" /d "NDEBUG"
# ADD RSC /l 0x409 /i "../../include" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib wxmsw24.lib libpq.lib /nologo /subsystem:windows /machine:I386 /libpath:"C:/wxWin/lib" /libpath:"C:\Arquivos de programas\PostgreSQL\8.0.0-rc1\lib\ms"

!ELSEIF  "$(CFG)" == "Livrus - Win32 Debug DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugDll"
# PROP BASE Intermediate_Dir "DebugDll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDll"
# PROP Intermediate_Dir "DebugDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /YX /FD /c
# ADD CPP /nologo /MDd /W4 /Zi /Od /I "C:/wxWin/include" /I "C:/wxWin/lib/mswdlld" /I "C:\Arquivos de programas\PostgreSQL\8.0.0-rc1\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /D "_MT" /D wxUSE_GUI=1 /D "__WXDEBUG__" /D WXDEBUG=1 /D "WXUSINGDLL" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "../../include" /d "_DEBUG"
# ADD RSC /l 0x409 /i "../../include" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib wxmsw24d.lib libpq.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"C:/wxWin/lib" /libpath:"C:\Arquivos de programas\PostgreSQL\8.0.0-rc1\lib\ms"

!ELSEIF  "$(CFG)" == "Livrus - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /YX /FD /c
# ADD CPP /nologo /MD /W4 /O2 /I "C:/wxWin/include" /I "C:/wxWin/lib/msw" /I "C:\Arquivos de programas\PostgreSQL\8.0.0-rc1\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /D "_MT" /D wxUSE_GUI=1 /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "../../include" /d "NDEBUG"
# ADD RSC /l 0x409 /i "C:/wxWin/include" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib zlib.lib regex.lib png.lib jpeg.lib tiff.lib wxmsw.lib libpq.lib /nologo /subsystem:windows /machine:I386 /libpath:"C:/wxWin/lib" /libpath:"C:\Arquivos de programas\PostgreSQL\8.0.0-rc1\lib\ms"

!ELSEIF  "$(CFG)" == "Livrus - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /YX /FD /c
# ADD CPP /nologo /MDd /W4 /Zi /Od /I "C:/wxWin/include" /I "C:/wxWin/lib/mswd" /I "C:\Arquivos de programas\PostgreSQL\8.0.0-rc1\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D WINVER=0x400 /D "_MT" /D wxUSE_GUI=1 /D "__WXDEBUG__" /D WXDEBUG=1 /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /i "../../include" /d "_DEBUG"
# ADD RSC /l 0x409 /i "C:/wxWin/include" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib wsock32.lib zlibd.lib regexd.lib pngd.lib jpegd.lib tiffd.lib wxmswd.lib libpq.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"C:/wxWin/lib" /libpath:"C:\Arquivos de programas\PostgreSQL\8.0.0-rc1\lib\ms"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "Livrus - Win32 Release DLL"
# Name "Livrus - Win32 Debug DLL"
# Name "Livrus - Win32 Release"
# Name "Livrus - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=.\AlterarSenha.cpp
# End Source File
# Begin Source File

SOURCE=.\CadAssuntos.cpp
# End Source File
# Begin Source File

SOURCE=.\Cadastros.cpp
# End Source File
# Begin Source File

SOURCE=.\CadAutores.cpp
# End Source File
# Begin Source File

SOURCE=.\CadClientes.cpp
# End Source File
# Begin Source File

SOURCE=.\CadEditoras.cpp
# End Source File
# Begin Source File

SOURCE=.\CadEnderecos.cpp
# End Source File
# Begin Source File

SOURCE=.\CadIdiomas.cpp
# End Source File
# Begin Source File

SOURCE=.\CadLivros.cpp
# End Source File
# Begin Source File

SOURCE=.\CadPaises.cpp
# End Source File
# Begin Source File

SOURCE=.\CadProfissoes.cpp
# End Source File
# Begin Source File

SOURCE=.\ConAssuntos.cpp
# End Source File
# Begin Source File

SOURCE=.\ConAutores.cpp
# End Source File
# Begin Source File

SOURCE=.\ConClientes.cpp
# End Source File
# Begin Source File

SOURCE=.\ConEditoras.cpp
# End Source File
# Begin Source File

SOURCE=.\ConEnderecos.cpp
# End Source File
# Begin Source File

SOURCE=.\ConIdiomas.cpp
# End Source File
# Begin Source File

SOURCE=.\ConLivros.cpp
# End Source File
# Begin Source File

SOURCE=.\ConPaises.cpp
# End Source File
# Begin Source File

SOURCE=.\ConProfissoes.cpp
# End Source File
# Begin Source File

SOURCE=.\Consultas.cpp
# End Source File
# Begin Source File

SOURCE=.\ConsultasSQL.cpp
# End Source File
# Begin Source File

SOURCE=.\ConVendas.cpp
# End Source File
# Begin Source File

SOURCE=.\DateCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\Filha.cpp
# End Source File
# Begin Source File

SOURCE=.\Livrus.cpp
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\Principal.cpp
# End Source File
# Begin Source File

SOURCE=.\RotinasGlobais.cpp
# End Source File
# Begin Source File

SOURCE=.\Sobre.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
# End Source File
# Begin Source File

SOURCE=.\VenderLivros.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h"
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

SOURCE=.\DateCtrl.h
# End Source File
# Begin Source File

SOURCE=.\Filha.h
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

# PROP Default_Filter "rc"
# Begin Source File

SOURCE=.\xpms\cliente.xpm
# End Source File
# Begin Source File

SOURCE=.\bmps\colours.bmp
# End Source File
# Begin Source File

SOURCE=.\xpms\dseta.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\livro.xpm
# End Source File
# Begin Source File

SOURCE=.\xpms\livros.xpm
# End Source File
# Begin Source File

SOURCE=.\Livrus.ico
# End Source File
# Begin Source File

SOURCE=.\Livrus.rc
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
# End Target
# End Project
