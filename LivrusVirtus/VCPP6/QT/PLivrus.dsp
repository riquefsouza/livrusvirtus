# Microsoft Developer Studio Project File - Name="PLivrus" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=PLivrus - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PLivrus.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PLivrus - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "tmp\obj\release_mt_shared"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "tmp\obj\release_mt_shared"
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GX /O1 /I "$(QTDIR)\include" /I "C:\Qt\3.3.3Evaluation\examples\mdi" /I "tmp\moc\release_mt_shared" /I "C:\Qt\3.3.3Evaluation\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "UNICODE" /D "QT_TRIAL" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /D "QT_ACCESSIBILITY_SUPPORT" /D "QT_TABLET_SUPPORT" /D "QT_NO_DEBUG" /FD -Zm200 /c
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x416
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "qt-mteval333.lib" "qtmain.lib" "opengl32.lib" "glu32.lib" "delayimp.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" delayimp.lib /nologo /subsystem:windows /machine:IX86 /libpath:"$(QTDIR)\lib" /DELAYLOAD:opengl32.dll /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll

!ELSEIF  "$(CFG)" == "PLivrus - Win32 Debug"

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
# ADD CPP /nologo /MD /W3 /GX /O1 /I "C:\Qt\3.3.3Evaluation\include" /I "C:\Qt\3.3.3Evaluation\mkspecs\win32-msvc" /D "UNICODE" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /D "QT_NO_DEBUG" /Zm200
# ADD BASE RSC /l 0x416
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 qt-mteval333.lib qtmain.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib imm32.lib winmm.lib wsock32.lib winspool.lib opengl32.lib glu32.lib delayimp.lib delayimp.lib /nologo /subsystem:windows /machine:IX86 /libpath:"C:\Qt\3.3.3Evaluation\lib" /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "PLivrus - Win32 Release"
# Name "PLivrus - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AlterarSenha.cpp
DEP_CPP_ALTER=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlineedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpushbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\AlterarSenha.h"\
	".\AlterarSenha.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\Cadastros.cpp
DEP_CPP_CADAS=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlineedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpushbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Cadastros.h"\
	".\Cadastros.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\CadClientes.cpp
DEP_CPP_CADCL=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbuttongroup.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatetime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatetimeedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgroupbox.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlineedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpushbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qradiobutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\CadClientes.h"\
	".\CadClientes.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\CadEnderecos.cpp
DEP_CPP_CADEN=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcombobox.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlineedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpushbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\CadEnderecos.h"\
	".\CadEnderecos.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\CadLivros.cpp
DEP_CPP_CADLI=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcombobox.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlineedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlistbox.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpushbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrangecontrol.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qscrollbar.h"\
	"..\..\..\qt\3.3.3evaluation\include\qscrollview.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qspinbox.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\CadLivros.h"\
	".\CadLivros.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\Consultas.cpp
DEP_CPP_CONSU=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qguardedptr.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgvector.h"\
	"..\..\..\qt\3.3.3evaluation\include\qheader.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qintdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlineedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrvector.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpushbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrangecontrol.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qscrollbar.h"\
	"..\..\..\qt\3.3.3evaluation\include\qscrollview.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtable.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Consultas.h"\
	".\Consultas.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\ConVendas.cpp
DEP_CPP_CONVE=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatetime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatetimeedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qguardedptr.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgvector.h"\
	"..\..\..\qt\3.3.3evaluation\include\qheader.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qintdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlineedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrvector.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpushbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrangecontrol.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qscrollbar.h"\
	"..\..\..\qt\3.3.3evaluation\include\qscrollview.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtable.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\ConVendas.h"\
	".\ConVendas.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\Livrus.cpp
DEP_CPP_LIVRU=\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdockwindow.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmainwindow.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtoolbar.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Principal.h"\
	
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
DEP_CPP_LOGIN=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdialog.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlineedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpushbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Login.h"\
	".\Login.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_AlterarSenha.cpp
DEP_CPP_MOC_A=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\AlterarSenha.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_Cadastros.cpp
DEP_CPP_MOC_C=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Cadastros.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_CadClientes.cpp
DEP_CPP_MOC_CA=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\CadClientes.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_CadEnderecos.cpp
DEP_CPP_MOC_CAD=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\CadEnderecos.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_CadLivros.cpp
DEP_CPP_MOC_CADL=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\CadLivros.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_Consultas.cpp
DEP_CPP_MOC_CO=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Consultas.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_ConVendas.cpp
DEP_CPP_MOC_CON=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\ConVendas.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_Login.cpp
DEP_CPP_MOC_L=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdialog.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Login.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_Principal.cpp
DEP_CPP_MOC_P=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdockwindow.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmainwindow.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtoolbar.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Principal.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_Sobre.cpp
DEP_CPP_MOC_S=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdialog.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Sobre.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_Splash.cpp
DEP_CPP_MOC_SP=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdialog.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Splash.h"\
	
# End Source File
# Begin Source File

SOURCE=.\moc_VenderLivros.cpp
DEP_CPP_MOC_V=\
	"..\..\..\qt\3.3.3evaluation\include\private\qucom_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\private\qucomextra_p.h"\
	"..\..\..\qt\3.3.3evaluation\include\qapplication.h"\
	"..\..\..\qt\3.3.3evaluation\include\qasciidict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconnection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdesktopwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmetaobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtranslator.h"\
	"..\..\..\qt\3.3.3evaluation\include\quuid.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\VenderLivros.h"\
	
# End Source File
# Begin Source File

SOURCE=.\Principal.cpp
DEP_CPP_PRINC=\
	"..\..\..\qt\3.3.3evaluation\include\qaction.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdockwindow.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmainwindow.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmenubar.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmenudata.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpopupmenu.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsignal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtoolbar.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtoolbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Principal.h"\
	".\Principal.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\qmake_image_collection.cpp
DEP_CPP_QMAKE=\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdragobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgdict.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	
# End Source File
# Begin Source File

SOURCE=.\Sobre.cpp
DEP_CPP_SOBRE=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdialog.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgroupbox.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpushbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Sobre.h"\
	".\Sobre.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
DEP_CPP_SPLAS=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdialog.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\Splash.h"\
	".\Splash.ui.h"\
	
# End Source File
# Begin Source File

SOURCE=.\VenderLivros.cpp
DEP_CPP_VENDE=\
	"..\..\..\qt\3.3.3evaluation\include\qbrush.h"\
	"..\..\..\qt\3.3.3evaluation\include\qbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcolor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qconfig.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qcursor.h"\
	"..\..\..\qt\3.3.3evaluation\include\qdatastream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qevent.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfeatures.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfont.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontinfo.h"\
	"..\..\..\qt\3.3.3evaluation\include\qfontmetrics.h"\
	"..\..\..\qt\3.3.3evaluation\include\qframe.h"\
	"..\..\..\qt\3.3.3evaluation\include\qgarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qglobal.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiconset.h"\
	"..\..\..\qt\3.3.3evaluation\include\qimage.h"\
	"..\..\..\qt\3.3.3evaluation\include\qiodevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qkeysequence.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlabel.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlayout.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlineedit.h"\
	"..\..\..\qt\3.3.3evaluation\include\qlistbox.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmemarray.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmime.h"\
	"..\..\..\qt\3.3.3evaluation\include\qmodules.h"\
	"..\..\..\qt\3.3.3evaluation\include\qnamespace.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobject.h"\
	"..\..\..\qt\3.3.3evaluation\include\qobjectdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpaintdevice.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpair.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpalette.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpixmap.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpoint.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrcollection.h"\
	"..\..\..\qt\3.3.3evaluation\include\qptrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qpushbutton.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrangecontrol.h"\
	"..\..\..\qt\3.3.3evaluation\include\qrect.h"\
	"..\..\..\qt\3.3.3evaluation\include\qregion.h"\
	"..\..\..\qt\3.3.3evaluation\include\qscrollbar.h"\
	"..\..\..\qt\3.3.3evaluation\include\qscrollview.h"\
	"..\..\..\qt\3.3.3evaluation\include\qshared.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsize.h"\
	"..\..\..\qt\3.3.3evaluation\include\qsizepolicy.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstring.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstringlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qstrlist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtextstream.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtl.h"\
	"..\..\..\qt\3.3.3evaluation\include\qtooltip.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvaluelist.h"\
	"..\..\..\qt\3.3.3evaluation\include\qvariant.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwhatsthis.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwidget.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwindowdefs_win.h"\
	"..\..\..\qt\3.3.3evaluation\include\qwinexport.h"\
	".\VenderLivros.h"\
	".\VenderLivros.ui.h"\
	
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AlterarSenha.h
# End Source File
# Begin Source File

SOURCE=.\AlterarSenha.ui.h
# End Source File
# Begin Source File

SOURCE=.\Cadastros.h
# End Source File
# Begin Source File

SOURCE=.\Cadastros.ui.h
# End Source File
# Begin Source File

SOURCE=.\CadClientes.h
# End Source File
# Begin Source File

SOURCE=.\CadClientes.ui.h
# End Source File
# Begin Source File

SOURCE=.\CadEnderecos.h
# End Source File
# Begin Source File

SOURCE=.\CadEnderecos.ui.h
# End Source File
# Begin Source File

SOURCE=.\CadLivros.h
# End Source File
# Begin Source File

SOURCE=.\CadLivros.ui.h
# End Source File
# Begin Source File

SOURCE=.\Consultas.h
# End Source File
# Begin Source File

SOURCE=.\Consultas.ui.h
# End Source File
# Begin Source File

SOURCE=.\ConVendas.h
# End Source File
# Begin Source File

SOURCE=.\ConVendas.ui.h
# End Source File
# Begin Source File

SOURCE=.\Login.h
# End Source File
# Begin Source File

SOURCE=.\Login.ui.h
# End Source File
# Begin Source File

SOURCE=.\Principal.h
# End Source File
# Begin Source File

SOURCE=.\Principal.ui.h
# End Source File
# Begin Source File

SOURCE=.\Sobre.h
# End Source File
# Begin Source File

SOURCE=.\Sobre.ui.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\Splash.ui.h
# End Source File
# Begin Source File

SOURCE=.\VenderLivros.h
# End Source File
# Begin Source File

SOURCE=.\VenderLivros.ui.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Generated"

# PROP Default_Filter ""
# End Group
# End Target
# End Project
