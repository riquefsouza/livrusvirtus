# Microsoft Developer Studio Project File - Name="Livrus" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Livrus - Win32 DebugDll
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Livrus.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Livrus.mak" CFG="Livrus - Win32 DebugDll"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Livrus - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Livrus - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Livrus - Win32 DebugDll" (based on "Win32 (x86) Application")
!MESSAGE "Livrus - Win32 ReleaseDll" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Livrus - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "C:\fox-1.2.13\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x416 /d "NDEBUG"
# ADD RSC /l 0x416 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 FOX-1.2.lib comctl32.lib wsock32.lib kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib mpr.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /nodefaultlib:"libcmt.lib" /libpath:"C:\fox-1.2.13\lib"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "C:\fox-1.2.13\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x416 /d "_DEBUG"
# ADD RSC /l 0x416 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 FOXD-1.2.lib comctl32.lib wsock32.lib ws2_32.lib kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib mpr.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /pdbtype:sept /libpath:"C:\fox-1.2.13\lib"

!ELSEIF  "$(CFG)" == "Livrus - Win32 DebugDll"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Livrus___Win32_DebugDll"
# PROP BASE Intermediate_Dir "Livrus___Win32_DebugDll"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDll"
# PROP Intermediate_Dir "DebugDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I "C:\fox-1.2.13\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FD /GZ /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "C:\fox-1.2.13\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "FOXDLL" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x416 /d "_DEBUG"
# ADD RSC /l 0x416 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FOXD-1.2.lib comctl32.lib wsock32.lib ws2_32.lib kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib mpr.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /pdbtype:sept /libpath:"C:\fox-1.2.13\lib"
# ADD LINK32 FOXDLLD-1.2.lib comctl32.lib wsock32.lib ws2_32.lib kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib mpr.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /pdbtype:sept /libpath:"C:\fox-1.2.13\lib"

!ELSEIF  "$(CFG)" == "Livrus - Win32 ReleaseDll"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Livrus___Win32_ReleaseDll"
# PROP BASE Intermediate_Dir "Livrus___Win32_ReleaseDll"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDll"
# PROP Intermediate_Dir "ReleaseDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "C:\fox-1.2.13\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /W3 /GX /O2 /I "C:\fox-1.2.13\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "FOXDLL" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x416 /d "NDEBUG"
# ADD RSC /l 0x416 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FOX-1.2.lib comctl32.lib wsock32.lib kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib mpr.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /nodefaultlib:"libcmt.lib" /libpath:"C:\fox-1.2.13\lib"
# ADD LINK32 FOXDLL-1.2.lib comctl32.lib wsock32.lib kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib mpr.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /nodefaultlib:"libcmt.lib" /libpath:"C:\fox-1.2.13\lib"

!ENDIF 

# Begin Target

# Name "Livrus - Win32 Release"
# Name "Livrus - Win32 Debug"
# Name "Livrus - Win32 DebugDll"
# Name "Livrus - Win32 ReleaseDll"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
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

SOURCE=.\Livrus.cpp
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\Principal.cpp
# End Source File
# Begin Source File

SOURCE=.\resource.cpp
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

SOURCE=.\Livrus.ico
# End Source File
# Begin Source File

SOURCE=.\Livrus.rc
# End Source File
# End Group
# End Target
# End Project
