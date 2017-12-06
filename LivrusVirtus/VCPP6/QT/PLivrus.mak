# Microsoft Developer Studio Generated NMAKE File, Based on PLivrus.dsp
!IF "$(CFG)" == ""
CFG=PLivrus - Win32 Release
!MESSAGE No configuration specified. Defaulting to PLivrus - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "PLivrus - Win32 Release" && "$(CFG)" != "PLivrus - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PLivrus.mak" CFG="PLivrus - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PLivrus - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PLivrus - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PLivrus - Win32 Release"

OUTDIR=.\Release
INTDIR=.\tmp\obj\release_mt_shared
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\PLivrus.exe"


CLEAN :
	-@erase "$(INTDIR)\AlterarSenha.obj"
	-@erase "$(INTDIR)\Cadastros.obj"
	-@erase "$(INTDIR)\CadClientes.obj"
	-@erase "$(INTDIR)\CadEnderecos.obj"
	-@erase "$(INTDIR)\CadLivros.obj"
	-@erase "$(INTDIR)\Consultas.obj"
	-@erase "$(INTDIR)\ConVendas.obj"
	-@erase "$(INTDIR)\Livrus.obj"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\moc_AlterarSenha.obj"
	-@erase "$(INTDIR)\moc_Cadastros.obj"
	-@erase "$(INTDIR)\moc_CadClientes.obj"
	-@erase "$(INTDIR)\moc_CadEnderecos.obj"
	-@erase "$(INTDIR)\moc_CadLivros.obj"
	-@erase "$(INTDIR)\moc_Consultas.obj"
	-@erase "$(INTDIR)\moc_ConVendas.obj"
	-@erase "$(INTDIR)\moc_Login.obj"
	-@erase "$(INTDIR)\moc_Principal.obj"
	-@erase "$(INTDIR)\moc_Sobre.obj"
	-@erase "$(INTDIR)\moc_Splash.obj"
	-@erase "$(INTDIR)\moc_VenderLivros.obj"
	-@erase "$(INTDIR)\Principal.obj"
	-@erase "$(INTDIR)\qmake_image_collection.obj"
	-@erase "$(INTDIR)\Sobre.obj"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\VenderLivros.obj"
	-@erase "$(OUTDIR)\PLivrus.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O1 /I "$(QTDIR)\include" /I "C:\Qt\3.3.3Evaluation\examples\mdi" /I "tmp\moc\release_mt_shared" /I "C:\Qt\3.3.3Evaluation\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "UNICODE" /D "QT_TRIAL" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /D "QT_ACCESSIBILITY_SUPPORT" /D "QT_TABLET_SUPPORT" /D "QT_NO_DEBUG" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD -Zm200 /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PLivrus.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS="qt-mteval333.lib" "qtmain.lib" "opengl32.lib" "glu32.lib" "delayimp.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" delayimp.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\PLivrus.pdb" /machine:IX86 /out:"$(OUTDIR)\PLivrus.exe" /libpath:"$(QTDIR)\lib" /DELAYLOAD:opengl32.dll /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll 
LINK32_OBJS= \
	"$(INTDIR)\AlterarSenha.obj" \
	"$(INTDIR)\Cadastros.obj" \
	"$(INTDIR)\CadClientes.obj" \
	"$(INTDIR)\CadEnderecos.obj" \
	"$(INTDIR)\CadLivros.obj" \
	"$(INTDIR)\Consultas.obj" \
	"$(INTDIR)\ConVendas.obj" \
	"$(INTDIR)\Livrus.obj" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\Principal.obj" \
	"$(INTDIR)\Sobre.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\VenderLivros.obj" \
	"$(INTDIR)\qmake_image_collection.obj" \
	"$(INTDIR)\moc_Cadastros.obj" \
	"$(INTDIR)\moc_CadClientes.obj" \
	"$(INTDIR)\moc_CadEnderecos.obj" \
	"$(INTDIR)\moc_CadLivros.obj" \
	"$(INTDIR)\moc_Consultas.obj" \
	"$(INTDIR)\moc_ConVendas.obj" \
	"$(INTDIR)\moc_Login.obj" \
	"$(INTDIR)\moc_Principal.obj" \
	"$(INTDIR)\moc_Sobre.obj" \
	"$(INTDIR)\moc_Splash.obj" \
	"$(INTDIR)\moc_VenderLivros.obj" \
	"$(INTDIR)\moc_AlterarSenha.obj"

"$(OUTDIR)\PLivrus.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PLivrus - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\PLivrus.exe"


CLEAN :
	-@erase "$(INTDIR)\AlterarSenha.obj"
	-@erase "$(INTDIR)\Cadastros.obj"
	-@erase "$(INTDIR)\CadClientes.obj"
	-@erase "$(INTDIR)\CadEnderecos.obj"
	-@erase "$(INTDIR)\CadLivros.obj"
	-@erase "$(INTDIR)\Consultas.obj"
	-@erase "$(INTDIR)\ConVendas.obj"
	-@erase "$(INTDIR)\Livrus.obj"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\moc_AlterarSenha.obj"
	-@erase "$(INTDIR)\moc_Cadastros.obj"
	-@erase "$(INTDIR)\moc_CadClientes.obj"
	-@erase "$(INTDIR)\moc_CadEnderecos.obj"
	-@erase "$(INTDIR)\moc_CadLivros.obj"
	-@erase "$(INTDIR)\moc_Consultas.obj"
	-@erase "$(INTDIR)\moc_ConVendas.obj"
	-@erase "$(INTDIR)\moc_Login.obj"
	-@erase "$(INTDIR)\moc_Principal.obj"
	-@erase "$(INTDIR)\moc_Sobre.obj"
	-@erase "$(INTDIR)\moc_Splash.obj"
	-@erase "$(INTDIR)\moc_VenderLivros.obj"
	-@erase "$(INTDIR)\Principal.obj"
	-@erase "$(INTDIR)\qmake_image_collection.obj"
	-@erase "$(INTDIR)\Sobre.obj"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\VenderLivros.obj"
	-@erase "$(OUTDIR)\PLivrus.exe"
	-@erase "$(OUTDIR)\PLivrus.ilk"
	-@erase "$(OUTDIR)\PLivrus.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /GX /Zi /O1 /I "$(QTDIR)\include" /I "C:\LivrusVirtus\QT" /I "C:\Qt\3.3.3Evaluation\mkspecs\win32-msvc" /D "UNICODE" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /D "QT_NO_DEBUG" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD -Zm200 /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PLivrus.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=qt-mteval333.lib qtmain.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib imm32.lib winmm.lib wsock32.lib winspool.lib opengl32.lib glu32.lib delayimp.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\PLivrus.pdb" /debug /machine:IX86 /nodefaultlib /out:"$(OUTDIR)\PLivrus.exe" /pdbtype:sept /libpath:"$(QTDIR)\lib" /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll 
LINK32_OBJS= \
	"$(INTDIR)\AlterarSenha.obj" \
	"$(INTDIR)\Cadastros.obj" \
	"$(INTDIR)\CadClientes.obj" \
	"$(INTDIR)\CadEnderecos.obj" \
	"$(INTDIR)\CadLivros.obj" \
	"$(INTDIR)\Consultas.obj" \
	"$(INTDIR)\ConVendas.obj" \
	"$(INTDIR)\Livrus.obj" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\Principal.obj" \
	"$(INTDIR)\Sobre.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\VenderLivros.obj" \
	"$(INTDIR)\qmake_image_collection.obj" \
	"$(INTDIR)\moc_Cadastros.obj" \
	"$(INTDIR)\moc_CadClientes.obj" \
	"$(INTDIR)\moc_CadEnderecos.obj" \
	"$(INTDIR)\moc_CadLivros.obj" \
	"$(INTDIR)\moc_Consultas.obj" \
	"$(INTDIR)\moc_ConVendas.obj" \
	"$(INTDIR)\moc_Login.obj" \
	"$(INTDIR)\moc_Principal.obj" \
	"$(INTDIR)\moc_Sobre.obj" \
	"$(INTDIR)\moc_Splash.obj" \
	"$(INTDIR)\moc_VenderLivros.obj" \
	"$(INTDIR)\moc_AlterarSenha.obj"

"$(OUTDIR)\PLivrus.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("PLivrus.dep")
!INCLUDE "PLivrus.dep"
!ELSE 
!MESSAGE Warning: cannot find "PLivrus.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "PLivrus - Win32 Release" || "$(CFG)" == "PLivrus - Win32 Debug"
SOURCE=.\AlterarSenha.cpp

"$(INTDIR)\AlterarSenha.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Cadastros.cpp

"$(INTDIR)\Cadastros.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\CadClientes.cpp

"$(INTDIR)\CadClientes.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\CadEnderecos.cpp

"$(INTDIR)\CadEnderecos.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\CadLivros.cpp

"$(INTDIR)\CadLivros.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Consultas.cpp

"$(INTDIR)\Consultas.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ConVendas.cpp

"$(INTDIR)\ConVendas.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Livrus.cpp

"$(INTDIR)\Livrus.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Login.cpp

"$(INTDIR)\Login.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_AlterarSenha.cpp

"$(INTDIR)\moc_AlterarSenha.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_Cadastros.cpp

"$(INTDIR)\moc_Cadastros.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_CadClientes.cpp

"$(INTDIR)\moc_CadClientes.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_CadEnderecos.cpp

"$(INTDIR)\moc_CadEnderecos.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_CadLivros.cpp

"$(INTDIR)\moc_CadLivros.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_Consultas.cpp

"$(INTDIR)\moc_Consultas.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_ConVendas.cpp

"$(INTDIR)\moc_ConVendas.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_Login.cpp

"$(INTDIR)\moc_Login.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_Principal.cpp

"$(INTDIR)\moc_Principal.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_Sobre.cpp

"$(INTDIR)\moc_Sobre.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_Splash.cpp

"$(INTDIR)\moc_Splash.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\moc_VenderLivros.cpp

"$(INTDIR)\moc_VenderLivros.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Principal.cpp

"$(INTDIR)\Principal.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\qmake_image_collection.cpp

"$(INTDIR)\qmake_image_collection.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Sobre.cpp

"$(INTDIR)\Sobre.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Splash.cpp

"$(INTDIR)\Splash.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\VenderLivros.cpp

"$(INTDIR)\VenderLivros.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

