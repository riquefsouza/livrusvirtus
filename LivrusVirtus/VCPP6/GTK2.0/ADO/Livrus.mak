# Microsoft Developer Studio Generated NMAKE File, Based on Livrus.dsp
!IF "$(CFG)" == ""
CFG=Livrus - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Livrus - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Livrus - Win32 Release" && "$(CFG)" != "Livrus - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Livrus - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Livrus.exe"


CLEAN :
	-@erase "$(INTDIR)\AlterarSenha.obj"
	-@erase "$(INTDIR)\CadAssuntos.obj"
	-@erase "$(INTDIR)\CadClientes.obj"
	-@erase "$(INTDIR)\CadEnderecos.obj"
	-@erase "$(INTDIR)\CadLivros.obj"
	-@erase "$(INTDIR)\ConAssuntos.obj"
	-@erase "$(INTDIR)\ConsultasSQL.obj"
	-@erase "$(INTDIR)\Livrus.obj"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Principal.obj"
	-@erase "$(INTDIR)\RotinasGlobais.obj"
	-@erase "$(INTDIR)\Sobre.obj"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\support.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Livrus.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\Livrus.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Livrus.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\Livrus.pdb" /machine:I386 /out:"$(OUTDIR)\Livrus.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AlterarSenha.obj" \
	"$(INTDIR)\CadAssuntos.obj" \
	"$(INTDIR)\CadClientes.obj" \
	"$(INTDIR)\CadEnderecos.obj" \
	"$(INTDIR)\CadLivros.obj" \
	"$(INTDIR)\ConAssuntos.obj" \
	"$(INTDIR)\ConsultasSQL.obj" \
	"$(INTDIR)\Livrus.obj" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\Principal.obj" \
	"$(INTDIR)\RotinasGlobais.obj" \
	"$(INTDIR)\Sobre.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\support.obj"

"$(OUTDIR)\Livrus.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Livrus - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Livrus.exe"


CLEAN :
	-@erase "$(INTDIR)\AlterarSenha.obj"
	-@erase "$(INTDIR)\CadAssuntos.obj"
	-@erase "$(INTDIR)\CadClientes.obj"
	-@erase "$(INTDIR)\CadEnderecos.obj"
	-@erase "$(INTDIR)\CadLivros.obj"
	-@erase "$(INTDIR)\ConAssuntos.obj"
	-@erase "$(INTDIR)\ConsultasSQL.obj"
	-@erase "$(INTDIR)\Livrus.obj"
	-@erase "$(INTDIR)\Login.obj"
	-@erase "$(INTDIR)\Principal.obj"
	-@erase "$(INTDIR)\RotinasGlobais.obj"
	-@erase "$(INTDIR)\Sobre.obj"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\support.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Livrus.exe"
	-@erase "$(OUTDIR)\Livrus.ilk"
	-@erase "$(OUTDIR)\Livrus.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "HAVE_CONFIG_H" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Livrus.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=art_lgpl_2.lib asprintf.lib atk-1.0.lib charset.lib fontconfig.lib gdk-win32-2.0.lib gdkglext-win32-1.0.lib gdk_pixbuf-2.0.lib glib-2.0.lib gmodule-2.0.lib gobject-2.0.lib gthread-2.0.lib gtk-win32-2.0.lib gtkglext-win32-1.0.lib iconv.lib intl.lib libbz2.lib libfreetype.lib libglade-2.0.lib libiconv.lib libindent.lib libindent_d.lib libintl.lib libjpeg.lib libpng.lib libtiff.lib libxml2.lib libz.lib pango-1.0.lib pangoft2-1.0.lib pangowin32-1.0.lib /nologo /incremental:yes /pdb:"$(OUTDIR)\Livrus.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Livrus.exe" /pdbtype:sept /libpath:"C:\GTK\Lib" 
LINK32_OBJS= \
	"$(INTDIR)\AlterarSenha.obj" \
	"$(INTDIR)\CadAssuntos.obj" \
	"$(INTDIR)\CadClientes.obj" \
	"$(INTDIR)\CadEnderecos.obj" \
	"$(INTDIR)\CadLivros.obj" \
	"$(INTDIR)\ConAssuntos.obj" \
	"$(INTDIR)\ConsultasSQL.obj" \
	"$(INTDIR)\Livrus.obj" \
	"$(INTDIR)\Login.obj" \
	"$(INTDIR)\Principal.obj" \
	"$(INTDIR)\RotinasGlobais.obj" \
	"$(INTDIR)\Sobre.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\support.obj"

"$(OUTDIR)\Livrus.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Livrus.dep")
!INCLUDE "Livrus.dep"
!ELSE 
!MESSAGE Warning: cannot find "Livrus.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Livrus - Win32 Release" || "$(CFG)" == "Livrus - Win32 Debug"
SOURCE=.\AlterarSenha.c

"$(INTDIR)\AlterarSenha.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\CadAssuntos.c

"$(INTDIR)\CadAssuntos.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\CadClientes.c

"$(INTDIR)\CadClientes.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\CadEnderecos.c

"$(INTDIR)\CadEnderecos.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\CadLivros.c

"$(INTDIR)\CadLivros.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\ConAssuntos.c

"$(INTDIR)\ConAssuntos.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\ConsultasSQL.c

"$(INTDIR)\ConsultasSQL.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\Livrus.c

"$(INTDIR)\Livrus.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\Login.c

"$(INTDIR)\Login.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\Principal.c

"$(INTDIR)\Principal.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\RotinasGlobais.c

"$(INTDIR)\RotinasGlobais.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\Sobre.c

"$(INTDIR)\Sobre.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\Splash.c

"$(INTDIR)\Splash.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"


SOURCE=.\support.c

"$(INTDIR)\support.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Livrus.pch"



!ENDIF 

