; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFrmFilha
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Livrus.h"
LastPage=0

ClassCount=29
Class1=CLivrusApp
Class3=CFrmPrincipal
Class4=CFrmFilha

ResourceCount=36
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_LIVRUSTYPE
Class2=CFrmCadastros
Class5=CFrmCadAssuntos
Resource4=IDR_MAINFRAME (English (U.S.))
Resource5=IDR_LIVRUSTYPE (English (U.S.))
Resource6=IDD_ABOUTBOX (English (U.S.))
Class6=CFrmCadAutores
Resource7=IDD_DIALOG1
Resource8=IDD_DIALOG2
Resource9=FRMCADPROFISSOES (English (U.S.))
Resource10=FRMCONIDIOMAS (English (U.S.))
Resource11=FRMSOBRE (English (U.S.))
Resource12=FRMCONCLIENTES (English (U.S.))
Resource13=FRMCADAUTORES (English (U.S.))
Resource14=FRMCONAUTORES (English (U.S.))
Resource15=FRMSPLASH (English (U.S.))
Resource16=ID_FRMPRINCIPAL (English (U.S.))
Resource17=FRMCADIDIOMAS (English (U.S.))
Resource18=FRMCADPAISES (English (U.S.))
Resource19=ID_ACELERADORES (English (U.S.))
Resource20=FRMCADEDITORAS (English (U.S.))
Resource21=FRMCADENDERECOS (English (U.S.))
Resource22=FRMCONPAISES (English (U.S.))
Resource23=FRMCADCLIENTES (English (U.S.))
Resource24=FRMCONEDITORAS (English (U.S.))
Resource25=FRMCONASSUNTOS (English (U.S.))
Resource26=ID_BMP_BARRAFERRAM (English (U.S.))
Resource27=PRINCIPAL (English (U.S.))
Resource28=FRMCONENDERECOS (English (U.S.))
Resource29=FRMCADLIVROS (English (U.S.))
Resource30=FRMCONLIVROS (English (U.S.))
Resource31=FRMLOGIN (English (U.S.))
Resource32=FRMCONVENDAS (English (U.S.))
Resource33=FRMCONPROFISSOES (English (U.S.))
Resource34=FRMALTERARSENHA (English (U.S.))
Resource35=FRMCADASSUNTOS (English (U.S.))
Class7=CFrmSplash
Class8=CFrmLogin
Class9=CFrmSobre
Class10=CFrmConAssuntos
Class11=CFrmAlterarSenha
Class12=CFrmCadClientes
Class13=CFrmCadEditoras
Class14=CFrmCadEnderecos
Class15=CFrmCadIdiomas
Class16=CFrmCadLivros
Class17=CFrmCadPaises
Class18=CFrmCadProfissoes
Class19=CFrmConAutores
Class20=CFrmConClientes
Class21=CFrmConEditoras
Class22=CFrmConEnderecos
Class23=CFrmConIdiomas
Class24=CFrmConLivros
Class25=CFrmConPaises
Class26=CFrmConProfissoes
Class27=CFrmConVendas
Class28=CFrmVenderLivros
Class29=CFrmConsultas
Resource36=FRMVENDERLIVROS (English (U.S.))

[CLS:CLivrusApp]
Type=0
HeaderFile=Livrus.h
ImplementationFile=Livrus.cpp
Filter=N
LastObject=CLivrusApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CFrmPrincipal]
Type=0
HeaderFile=Principal.h
ImplementationFile=Principal.cpp
Filter=T
BaseClass=CMDIFrameWnd
VirtualFilter=fWC
LastObject=CM_VEN_VENDASREALIZADAS


[CLS:CFrmFilha]
Type=0
HeaderFile=Filha.h
ImplementationFile=Filha.cpp
Filter=M
LastObject=CFrmFilha
BaseClass=CMDIChildWnd
VirtualFilter=mfWC


[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=?

[MNU:IDR_MAINFRAME]
Type=1
Class=CFrmPrincipal
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_APP_ABOUT
CommandCount=7
Command3=ID_FILE_MRU_FILE1

[TB:IDR_MAINFRAME]
Type=1
Class=CFrmPrincipal
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
CommandCount=8
Command8=ID_APP_ABOUT

[MNU:IDR_LIVRUSTYPE]
Type=1
Class=CLivrusView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_WINDOW_NEW
CommandCount=18
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_EDIT_UNDO
Command15=ID_WINDOW_CASCADE
Command16=ID_WINDOW_TILE_HORZ
Command17=ID_WINDOW_ARRANGE
Command18=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CFrmPrincipal
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=13
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE


[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_FILE_PRINT
Command6=ID_APP_ABOUT
CommandCount=6

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_APP_EXIT
Command3=ID_VIEW_TOOLBAR
Command4=ID_VIEW_STATUS_BAR
Command5=ID_APP_ABOUT
CommandCount=5

[MNU:IDR_LIVRUSTYPE (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_CLOSE
Command3=ID_APP_EXIT
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_VIEW_TOOLBAR
Command9=ID_VIEW_STATUS_BAR
Command10=ID_WINDOW_CASCADE
Command11=ID_WINDOW_TILE_HORZ
Command12=ID_WINDOW_ARRANGE
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_EDIT_PASTE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_NEXT_PANE
Command7=ID_PREV_PANE
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_CUT
Command11=ID_EDIT_UNDO
CommandCount=11

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG1]
Type=1
Class=CFrmCadAutores
ControlCount=2
Control1=IDOK,button,1342242817
Control2=D1_CANCEL,button,1342242816

[CLS:CFrmCadAutores]
Type=0
HeaderFile=CadAutores.h
ImplementationFile=CadAutores.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmCadAutores
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=CFrmCadAssuntos
ControlCount=2
Control1=IDOK,button,1342242817
Control2=D2_CANCEL,button,1342242816

[CLS:CFrmCadAssuntos]
Type=0
HeaderFile=CadAssuntos.h
ImplementationFile=CadAssuntos.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFrmCadAssuntos

[TB:ID_BMP_BARRAFERRAM (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_FILE_PRINT
Command5=ID_APP_ABOUT
CommandCount=5

[ACL:ID_ACELERADORES (English (U.S.))]
Type=1
Class=?
Command1=CM_OP_SAIR
Command2=ID_NEXT_PANE
Command3=ID_PREV_PANE
CommandCount=3

[DLG:FRMCADASSUNTOS (English (U.S.))]
Type=1
Class=?
ControlCount=12
Control1=ID_FRMCADASSUNTOS_LABCODIGO,static,1342177280
Control2=ID_FRMCADASSUNTOS_EDTCODIGO,edit,1350639618
Control3=ID_FRMCADASSUNTOS_BTNNOVO,button,1342242816
Control4=ID_FRMCADASSUNTOS_LABDESCRICAO,static,1342177280
Control5=ID_FRMCADASSUNTOS_EDTDESCRICAO,edit,1484849152
Control6=ID_FRMCADASSUNTOS_BTNPESQUISAR,button,1342242816
Control7=ID_FRMCADASSUNTOS_BTNANTERIOR,button,1476460544
Control8=ID_FRMCADASSUNTOS_BTNPROXIMO,button,1476460544
Control9=ID_FRMCADASSUNTOS_BTNSALVAR,button,1476460544
Control10=ID_FRMCADASSUNTOS_BTNEXCLUIR,button,1476460544
Control11=ID_FRMCADASSUNTOS_BTNLIMPAR,button,1342242816
Control12=ID_FRMCADASSUNTOS_BTNFECHAR,button,1342242816

[DLG:FRMCADAUTORES (English (U.S.))]
Type=1
Class=?
ControlCount=12
Control1=ID_FRMCADAUTORES_LABCODIGO,static,1342177280
Control2=ID_FRMCADAUTORES_EDTCODIGO,edit,1350639618
Control3=ID_FRMCADAUTORES_BTNNOVO,button,1342242816
Control4=ID_FRMCADAUTORES_LABDESCRICAO,static,1342177280
Control5=ID_FRMCADAUTORES_EDTDESCRICAO,edit,1484853248
Control6=ID_FRMCADAUTORES_BTNPESQUISAR,button,1342242816
Control7=ID_FRMCADAUTORES_BTNANTERIOR,button,1476460544
Control8=ID_FRMCADAUTORES_BTNPROXIMO,button,1476460544
Control9=ID_FRMCADAUTORES_BTNSALVAR,button,1476460544
Control10=ID_FRMCADAUTORES_BTNEXCLUIR,button,1476460544
Control11=ID_FRMCADAUTORES_BTNLIMPAR,button,1342242816
Control12=ID_FRMCADAUTORES_BTNFECHAR,button,1342242816

[MNU:PRINCIPAL (English (U.S.))]
Type=1
Class=?
Command1=CM_CAD_ASSUNTOS
Command2=CM_CAD_AUTORES
Command3=CM_CAD_EDITORAS
Command4=CM_CAD_ENDERECOS
Command5=CM_CAD_IDIOMAS
Command6=CM_CAD_PAISES
Command7=CM_CAD_PROFISSOES
Command8=CM_CAD_CLIENTES
Command9=CM_CAD_LIVROS
Command10=CM_CON_ASSUNTOS
Command11=CM_CON_AUTORES
Command12=CM_CON_EDITORAS
Command13=CM_CON_ENDERECOS
Command14=CM_CON_IDIOMAS
Command15=CM_CON_PAISES
Command16=CM_CON_PROFISSOES
Command17=CM_CON_CLIENTES
Command18=CM_CON_LIVROS
Command19=CM_VEN_VENDERLIVROS
Command20=CM_VEN_VENDASREALIZADAS
Command21=ID_WINDOW_TILE_HORZ
Command22=ID_WINDOW_TILE_VERT
Command23=ID_WINDOW_CASCADE
Command24=ID_WINDOW_ARRANGE
Command25=ID_VIEW_TOOLBAR
Command26=ID_VIEW_STATUS_BAR
Command27=CM_OP_ALTERARSENHA
Command28=CM_OP_SOBRE
Command29=CM_OP_SAIR
CommandCount=29

[DLG:FRMSOBRE (English (U.S.))]
Type=1
Class=CFrmSobre
ControlCount=6
Control1=ID_FRMSOBRE_BTNOK,button,1342242817
Control2=ID_FRMSOBRE_GRPSOBRE,button,1342177287
Control3=ID_FRMSOBRE_LABFIGURA,static,1342177294
Control4=ID_FRMSOBRE_LABDIREITOS,static,1342177280
Control5=ID_FRMSOBRE_LABVERSAO,static,1342177280
Control6=ID_FRMSOBRE_LABSISTEMA,static,1342177281

[TB:ID_FRMPRINCIPAL (English (U.S.))]
Type=1
Class=?
Command1=CM_CAD_CLIENTES
Command2=CM_CAD_LIVROS
Command3=CM_VEN_VENDERLIVROS
Command4=CM_OP_SOBRE
Command5=CM_OP_SAIR
CommandCount=5

[MNU:ID_FRMPRINCIPAL (English (U.S.))]
Type=1
Class=?
Command1=CM_CAD_ASSUNTOS
Command2=CM_CAD_AUTORES
Command3=CM_CAD_EDITORAS
Command4=CM_CAD_ENDERECOS
Command5=CM_CAD_IDIOMAS
Command6=CM_CAD_PAISES
Command7=CM_CAD_PROFISSOES
Command8=CM_CAD_CLIENTES
Command9=CM_CAD_LIVROS
Command10=CM_CON_ASSUNTOS
Command11=CM_CON_AUTORES
Command12=CM_CON_EDITORAS
Command13=CM_CON_ENDERECOS
Command14=CM_CON_IDIOMAS
Command15=CM_CON_PAISES
Command16=CM_CON_PROFISSOES
Command17=CM_CON_CLIENTES
Command18=CM_CON_LIVROS
Command19=CM_VEN_VENDERLIVROS
Command20=CM_VEN_VENDASREALIZADAS
Command21=ID_WINDOW_TILE_HORZ
Command22=ID_WINDOW_TILE_VERT
Command23=ID_WINDOW_CASCADE
Command24=ID_WINDOW_ARRANGE
Command25=ID_VIEW_TOOLBAR
Command26=ID_VIEW_STATUS_BAR
Command27=CM_OP_ALTERARSENHA
Command28=CM_OP_SOBRE
Command29=CM_OP_SAIR
CommandCount=29

[ACL:ID_FRMPRINCIPAL (English (U.S.))]
Type=1
Class=?
Command1=CM_OP_SAIR
Command2=ID_NEXT_PANE
Command3=ID_PREV_PANE
CommandCount=3

[DLG:FRMALTERARSENHA (English (U.S.))]
Type=1
Class=CFrmAlterarSenha
ControlCount=11
Control1=ID_FRMALTERARSENHA_LABLOGIN,static,1342177280
Control2=ID_FRMALTERARSENHA_EDTLOGIN,edit,1484849280
Control3=ID_FRMALTERARSENHA_LABSENHAATUAL,static,1342177280
Control4=ID_FRMALTERARSENHA_EDTSENHAATUAL,edit,1350631584
Control5=ID_FRMALTERARSENHA_LABNOVASENHA,static,1342177280
Control6=ID_FRMALTERARSENHA_EDTNOVASENHA,edit,1350631584
Control7=ID_FRMALTERARSENHA_LABCONFIRMASENHA,static,1342177280
Control8=ID_FRMALTERARSENHA_EDTCONFIRMASENHA,edit,1350631584
Control9=ID_FRMALTERARSENHA_BTNSALVAR,button,1342242816
Control10=ID_FRMALTERARSENHA_BTNLIMPAR,button,1342242816
Control11=ID_FRMALTERARSENHA_BTNFECHAR,button,1342242816

[DLG:FRMCADEDITORAS (English (U.S.))]
Type=1
Class=CFrmCadEditoras
ControlCount=12
Control1=ID_FRMCADEDITORAS_LABCODIGO,static,1342177280
Control2=ID_FRMCADEDITORAS_EDTCODIGO,edit,1350639618
Control3=ID_FRMCADEDITORAS_BTNNOVO,button,1342242816
Control4=ID_FRMCADEDITORAS_LABDESCRICAO,static,1342177280
Control5=ID_FRMCADEDITORAS_EDTDESCRICAO,edit,1484853248
Control6=ID_FRMCADEDITORAS_BTNPESQUISAR,button,1342242816
Control7=ID_FRMCADEDITORAS_BTNANTERIOR,button,1476460544
Control8=ID_FRMCADEDITORAS_BTNPROXIMO,button,1476460544
Control9=ID_FRMCADEDITORAS_BTNSALVAR,button,1476460544
Control10=ID_FRMCADEDITORAS_BTNEXCLUIR,button,1476460544
Control11=ID_FRMCADEDITORAS_BTNLIMPAR,button,1342242816
Control12=ID_FRMCADEDITORAS_BTNFECHAR,button,1342242816

[DLG:FRMCADENDERECOS (English (U.S.))]
Type=1
Class=CFrmCadEnderecos
ControlCount=20
Control1=ID_FRMCADENDERECOS_LABCODIGO,static,1342177280
Control2=ID_FRMCADENDERECOS_EDTCODIGO,edit,1350639618
Control3=ID_FRMCADENDERECOS_BTNNOVO,button,1342242816
Control4=ID_FRMCADENDERECOS_LABLOGRADOURO,static,1342177280
Control5=ID_FRMCADENDERECOS_EDTLOGRADOURO,edit,1484849280
Control6=ID_FRMCADENDERECOS_LABBAIRRO,static,1342177280
Control7=ID_FRMCADENDERECOS_EDTBAIRRO,edit,1484849280
Control8=ID_FRMCADENDERECOS_LABCEP,static,1342177280
Control9=ID_FRMCADENDERECOS_EDTCEP,edit,1484849280
Control10=ID_FRMCADENDERECOS_LABCIDADE,static,1342177280
Control11=ID_FRMCADENDERECOS_EDTCIDADE,edit,1484849280
Control12=ID_FRMCADENDERECOS_LABESTADO,static,1342177280
Control13=ID_FRMCADENDERECOS_CMBESTADO,combobox,1478558787
Control14=ID_FRMCADENDERECOS_BTNPESQUISAR,button,1342242816
Control15=ID_FRMCADENDERECOS_BTNANTERIOR,button,1476460544
Control16=ID_FRMCADENDERECOS_BTNPROXIMO,button,1476460544
Control17=ID_FRMCADENDERECOS_BTNSALVAR,button,1476460544
Control18=ID_FRMCADENDERECOS_BTNEXCLUIR,button,1476460544
Control19=ID_FRMCADENDERECOS_BTNLIMPAR,button,1342242816
Control20=ID_FRMCADENDERECOS_BTNFECHAR,button,1342242816

[DLG:FRMCADCLIENTES (English (U.S.))]
Type=1
Class=CFrmCadClientes
ControlCount=44
Control1=ID_FRMCADCLIENTES_LABCPF,static,1342177280
Control2=ID_FRMCADCLIENTES_EDTCPF,edit,1350631552
Control3=ID_FRMCADCLIENTES_BTNNOVO,button,1342242816
Control4=ID_FRMCADCLIENTES_LABNOME,static,1342177280
Control5=ID_FRMCADCLIENTES_EDTNOME,edit,1484849280
Control6=ID_FRMCADCLIENTES_LABEMAIL,static,1342177280
Control7=ID_FRMCADCLIENTES_EDTEMAIL,edit,1484849280
Control8=ID_FRMCADCLIENTES_LABIDENTIDADE,static,1342177280
Control9=ID_FRMCADCLIENTES_EDTIDENTIDADE,edit,1484857472
Control10=ID_FRMCADCLIENTES_GRPSEXO,button,1342177287
Control11=ID_FRMCADCLIENTES_RBMASCULINO,button,1476476937
Control12=ID_FRMCADCLIENTES_RBFEMININO,button,1476476937
Control13=ID_FRMCADCLIENTES_LABTELEFONE,static,1342177280
Control14=ID_FRMCADCLIENTES_EDTTELEFONE,edit,1484849280
Control15=ID_FRMCADCLIENTES_LABDTNASC,static,1342177280
Control16=ID_FRMCADCLIENTES_EDTDTNASC,SysDateTimePick32,1476460576
Control17=ID_FRMCADCLIENTES_GRPENDERECO,button,1342177287
Control18=ID_FRMCADCLIENTES_EDTCODENDERECO,edit,1484857472
Control19=ID_FRMCADCLIENTES_BTNPENDERECO,button,1476460544
Control20=ID_FRMCADCLIENTES_LABLOGRADOURO,static,1342177280
Control21=ID_FRMCADCLIENTES_EDTLOGRADOURO,edit,1484849280
Control22=ID_FRMCADCLIENTES_LABBAIRRO,static,1342177280
Control23=ID_FRMCADCLIENTES_EDTBAIRRO,edit,1484849280
Control24=ID_FRMCADCLIENTES_LABCEP,static,1342177280
Control25=ID_FRMCADCLIENTES_EDTCEP,edit,1484849280
Control26=ID_FRMCADCLIENTES_LABCIDADE,static,1342177280
Control27=ID_FRMCADCLIENTES_EDTCIDADE,edit,1484849280
Control28=ID_FRMCADCLIENTES_LABESTADO,static,1342177280
Control29=ID_FRMCADCLIENTES_EDTESTADO,edit,1484849280
Control30=ID_FRMCADCLIENTES_LABCODPAIS,static,1342177280
Control31=ID_FRMCADCLIENTES_EDTCODPAIS,edit,1484849288
Control32=ID_FRMCADCLIENTES_EDTPAIS,edit,1484849280
Control33=ID_FRMCADCLIENTES_BTNPPAIS,button,1476460544
Control34=ID_FRMCADCLIENTES_LABCODPROFISSAO,static,1342177280
Control35=ID_FRMCADCLIENTES_EDTCODPROFISSAO,edit,1484857472
Control36=ID_FRMCADCLIENTES_EDTPROFISSAO,edit,1484849280
Control37=ID_FRMCADCLIENTES_BTNPPROFISSAO,button,1476460544
Control38=ID_FRMCADCLIENTES_BTNPESQUISAR,button,1342242816
Control39=ID_FRMCADCLIENTES_BTNANTERIOR,button,1476460544
Control40=ID_FRMCADCLIENTES_BTNPROXIMO,button,1476460544
Control41=ID_FRMCADCLIENTES_BTNSALVAR,button,1476460544
Control42=ID_FRMCADCLIENTES_BTNEXCLUIR,button,1476460544
Control43=ID_FRMCADCLIENTES_BTNLIMPAR,button,1342242816
Control44=ID_FRMCADCLIENTES_BTNFECHAR,button,1342242816

[DLG:FRMSPLASH (English (U.S.))]
Type=1
Class=CFrmSplash
ControlCount=1
Control1=ID_FRMSPLASH_LABFIGURA,static,1342177294

[DLG:FRMLOGIN (English (U.S.))]
Type=1
Class=CFrmLogin
ControlCount=7
Control1=ID_FRMLOGIN_LABFIGURA,static,1342177294
Control2=ID_FRMLOGIN_LABLOGIN,static,1342177280
Control3=ID_FRMLOGIN_EDTLOGIN,edit,1350631424
Control4=ID_FRMLOGIN_LABSENHA,static,1342177280
Control5=ID_FRMLOGIN_EDTSENHA,edit,1350631456
Control6=ID_FRMLOGIN_BTNLOGIN,button,1342242817
Control7=ID_FRMLOGIN_BTNCANCELAR,button,1342242816

[DLG:FRMCONASSUNTOS (English (U.S.))]
Type=1
Class=CFrmConAssuntos
ControlCount=7
Control1=ID_FRMCONASSUNTOS_LABDESCRICAO,static,1342177280
Control2=ID_FRMCONASSUNTOS_EDTDESCRICAO,edit,1350631552
Control3=ID_FRMCONASSUNTOS_BTNPESQUISAR,button,1342242816
Control4=ID_FRMCONASSUNTOS_LISTCONSULTA,SysListView32,1350633485
Control5=ID_FRMCONASSUNTOS_LABREGISTROS,static,1342177280
Control6=ID_FRMCONASSUNTOS_BTNLIMPAR,button,1342242816
Control7=ID_FRMCONASSUNTOS_BTNFECHAR,button,1342242816

[DLG:FRMCONAUTORES (English (U.S.))]
Type=1
Class=CFrmConAutores
ControlCount=7
Control1=ID_FRMCONAUTORES_LABDESCRICAO,static,1342177280
Control2=ID_FRMCONAUTORES_EDTDESCRICAO,edit,1350631552
Control3=ID_FRMCONAUTORES_BTNPESQUISAR,button,1342242816
Control4=ID_FRMCONAUTORES_LISTCONSULTA,SysListView32,1350633485
Control5=ID_FRMCONAUTORES_LABREGISTROS,static,1342177280
Control6=ID_FRMCONAUTORES_BTNLIMPAR,button,1342242816
Control7=ID_FRMCONAUTORES_BTNFECHAR,button,1342242816

[DLG:FRMCONEDITORAS (English (U.S.))]
Type=1
Class=CFrmConEditoras
ControlCount=7
Control1=ID_FRMCONEDITORAS_LABDESCRICAO,static,1342177280
Control2=ID_FRMCONEDITORAS_EDTDESCRICAO,edit,1350631552
Control3=ID_FRMCONEDITORAS_BTNPESQUISAR,button,1342242816
Control4=ID_FRMCONEDITORAS_LISTCONSULTA,SysListView32,1350633485
Control5=ID_FRMCONEDITORAS_LABREGISTROS,static,1342177280
Control6=ID_FRMCONEDITORAS_BTNLIMPAR,button,1342242816
Control7=ID_FRMCONEDITORAS_BTNFECHAR,button,1342242816

[DLG:FRMCONENDERECOS (English (U.S.))]
Type=1
Class=CFrmConEnderecos
ControlCount=7
Control1=ID_FRMCONENDERECOS_LABDESCRICAO,static,1342177280
Control2=ID_FRMCONENDERECOS_EDTDESCRICAO,edit,1350631552
Control3=ID_FRMCONENDERECOS_BTNPESQUISAR,button,1342242816
Control4=ID_FRMCONENDERECOS_LISTCONSULTA,SysListView32,1350633485
Control5=ID_FRMCONENDERECOS_LABREGISTROS,static,1342177280
Control6=ID_FRMCONENDERECOS_BTNLIMPAR,button,1342242816
Control7=ID_FRMCONENDERECOS_BTNFECHAR,button,1342242816

[DLG:FRMCADIDIOMAS (English (U.S.))]
Type=1
Class=CFrmCadIdiomas
ControlCount=12
Control1=ID_FRMCADIDIOMAS_LABCODIGO,static,1342177280
Control2=ID_FRMCADIDIOMAS_EDTCODIGO,edit,1350639618
Control3=ID_FRMCADIDIOMAS_BTNNOVO,button,1342242816
Control4=ID_FRMCADIDIOMAS_LABDESCRICAO,static,1342177280
Control5=ID_FRMCADIDIOMAS_EDTDESCRICAO,edit,1484853248
Control6=ID_FRMCADIDIOMAS_BTNPESQUISAR,button,1342242816
Control7=ID_FRMCADIDIOMAS_BTNANTERIOR,button,1476460544
Control8=ID_FRMCADIDIOMAS_BTNPROXIMO,button,1476460544
Control9=ID_FRMCADIDIOMAS_BTNSALVAR,button,1476460544
Control10=ID_FRMCADIDIOMAS_BTNEXCLUIR,button,1476460544
Control11=ID_FRMCADIDIOMAS_BTNLIMPAR,button,1342242816
Control12=ID_FRMCADIDIOMAS_BTNFECHAR,button,1342242816

[DLG:FRMCONIDIOMAS (English (U.S.))]
Type=1
Class=CFrmConIdiomas
ControlCount=7
Control1=ID_FRMCONIDIOMAS_LABDESCRICAO,static,1342177280
Control2=ID_FRMCONIDIOMAS_EDTDESCRICAO,edit,1350631552
Control3=ID_FRMCONIDIOMAS_BTNPESQUISAR,button,1342242816
Control4=ID_FRMCONIDIOMAS_LISTCONSULTA,SysListView32,1350633485
Control5=ID_FRMCONIDIOMAS_LABREGISTROS,static,1342177280
Control6=ID_FRMCONIDIOMAS_BTNLIMPAR,button,1342242816
Control7=ID_FRMCONIDIOMAS_BTNFECHAR,button,1342242816

[DLG:FRMCADPAISES (English (U.S.))]
Type=1
Class=CFrmCadPaises
ControlCount=12
Control1=ID_FRMCADPAISES_LABCODIGO,static,1342177280
Control2=ID_FRMCADPAISES_EDTCODIGO,edit,1350631432
Control3=ID_FRMCADPAISES_BTNNOVO,button,1342242816
Control4=ID_FRMCADPAISES_LABDESCRICAO,static,1342177280
Control5=ID_FRMCADPAISES_EDTDESCRICAO,edit,1484853248
Control6=ID_FRMCADPAISES_BTNPESQUISAR,button,1342242816
Control7=ID_FRMCADPAISES_BTNANTERIOR,button,1476460544
Control8=ID_FRMCADPAISES_BTNPROXIMO,button,1476460544
Control9=ID_FRMCADPAISES_BTNSALVAR,button,1476460544
Control10=ID_FRMCADPAISES_BTNEXCLUIR,button,1476460544
Control11=ID_FRMCADPAISES_BTNLIMPAR,button,1342242816
Control12=ID_FRMCADPAISES_BTNFECHAR,button,1342242816

[DLG:FRMCONPAISES (English (U.S.))]
Type=1
Class=CFrmConPaises
ControlCount=7
Control1=ID_FRMCONPAISES_LABDESCRICAO,static,1342177280
Control2=ID_FRMCONPAISES_EDTDESCRICAO,edit,1350631552
Control3=ID_FRMCONPAISES_BTNPESQUISAR,button,1342242816
Control4=ID_FRMCONPAISES_LISTCONSULTA,SysListView32,1350633485
Control5=ID_FRMCONPAISES_LABREGISTROS,static,1342177280
Control6=ID_FRMCONPAISES_BTNLIMPAR,button,1342242816
Control7=ID_FRMCONPAISES_BTNFECHAR,button,1342242816

[DLG:FRMCADPROFISSOES (English (U.S.))]
Type=1
Class=CFrmCadProfissoes
ControlCount=12
Control1=ID_FRMCADPROFISSOES_LABCODIGO,static,1342177280
Control2=ID_FRMCADPROFISSOES_EDTCODIGO,edit,1350639618
Control3=ID_FRMCADPROFISSOES_BTNNOVO,button,1342242816
Control4=ID_FRMCADPROFISSOES_LABDESCRICAO,static,1342177280
Control5=ID_FRMCADPROFISSOES_EDTDESCRICAO,edit,1484853248
Control6=ID_FRMCADPROFISSOES_BTNPESQUISAR,button,1342242816
Control7=ID_FRMCADPROFISSOES_BTNANTERIOR,button,1476460544
Control8=ID_FRMCADPROFISSOES_BTNPROXIMO,button,1476460544
Control9=ID_FRMCADPROFISSOES_BTNSALVAR,button,1476460544
Control10=ID_FRMCADPROFISSOES_BTNEXCLUIR,button,1476460544
Control11=ID_FRMCADPROFISSOES_BTNLIMPAR,button,1342242816
Control12=ID_FRMCADPROFISSOES_BTNFECHAR,button,1342242816

[DLG:FRMCONPROFISSOES (English (U.S.))]
Type=1
Class=CFrmConProfissoes
ControlCount=7
Control1=ID_FRMCONPROFISSOES_LABDESCRICAO,static,1342177280
Control2=ID_FRMCONPROFISSOES_EDTDESCRICAO,edit,1350631552
Control3=ID_FRMCONPROFISSOES_BTNPESQUISAR,button,1342242816
Control4=ID_FRMCONPROFISSOES_LISTCONSULTA,SysListView32,1350633485
Control5=ID_FRMCONPROFISSOES_LABREGISTROS,static,1342177280
Control6=ID_FRMCONPROFISSOES_BTNLIMPAR,button,1342242816
Control7=ID_FRMCONPROFISSOES_BTNFECHAR,button,1342242816

[DLG:FRMCADLIVROS (English (U.S.))]
Type=1
Class=CFrmCadLivros
ControlCount=47
Control1=ID_FRMCADLIVROS_LABISBN,static,1342177280
Control2=ID_FRMCADLIVROS_EDTISBN,edit,1350631552
Control3=ID_FRMCADLIVROS_BTNNOVO,button,1342242816
Control4=ID_FRMCADLIVROS_LABTITULO,static,1342177280
Control5=ID_FRMCADLIVROS_EDTTITULO,edit,1484849280
Control6=ID_FRMCADLIVROS_LABEDICAO,static,1342177280
Control7=ID_FRMCADLIVROS_EDTEDICAO,edit,1484857472
Control8=ID_FRMCADLIVROS_SPINEDICAO,msctls_updown32,1476460726
Control9=ID_FRMCADLIVROS_LABANOPUBLI,static,1342177280
Control10=ID_FRMCADLIVROS_EDTANOPUBLI,edit,1484857472
Control11=ID_FRMCADLIVROS_SPINANOPUBLI,msctls_updown32,1476460726
Control12=ID_FRMCADLIVROS_LABCODEDITORA,static,1342177280
Control13=ID_FRMCADLIVROS_EDTCODEDITORA,edit,1484857472
Control14=ID_FRMCADLIVROS_EDTEDITORA,edit,1484849280
Control15=ID_FRMCADLIVROS_BTNPEDITORA,button,1476460544
Control16=ID_FRMCADLIVROS_LABVOLUME,static,1342177280
Control17=ID_FRMCADLIVROS_EDTVOLUME,edit,1484857472
Control18=ID_FRMCADLIVROS_SPINVOLUME,msctls_updown32,1476460726
Control19=ID_FRMCADLIVROS_LABIDIOMA,static,1342177280
Control20=ID_FRMCADLIVROS_CMBIDIOMA,combobox,1478558787
Control21=ID_FRMCADLIVROS_LABNPAGINAS,static,1342177280
Control22=ID_FRMCADLIVROS_EDTNPAGINAS,edit,1484857472
Control23=ID_FRMCADLIVROS_SPINNPAGINAS,msctls_updown32,1476460726
Control24=ID_FRMCADLIVROS_LABCODASSUNTO,static,1342177280
Control25=ID_FRMCADLIVROS_EDTCODASSUNTO,edit,1484857472
Control26=ID_FRMCADLIVROS_EDTASSUNTO,edit,1484849280
Control27=ID_FRMCADLIVROS_BTNADASSUNTOS,button,1476460544
Control28=ID_FRMCADLIVROS_BTNPASSUNTO,button,1476460544
Control29=ID_FRMCADLIVROS_LSTASSUNTOS,listbox,1486946561
Control30=ID_FRMCADLIVROS_LABPRECO,static,1342177280
Control31=ID_FRMCADLIVROS_EDTPRECO,edit,1484849280
Control32=ID_FRMCADLIVROS_LABQTDESTOQUE,static,1342177280
Control33=ID_FRMCADLIVROS_EDTQTDESTOQUE,edit,1484857472
Control34=ID_FRMCADLIVROS_SPINQTDESTOQUE,msctls_updown32,1476460726
Control35=ID_FRMCADLIVROS_LABCODAUTOR,static,1342177280
Control36=ID_FRMCADLIVROS_EDTCODAUTOR,edit,1484857472
Control37=ID_FRMCADLIVROS_EDTAUTOR,edit,1484849280
Control38=ID_FRMCADLIVROS_BTNADAUTORES,button,1476460544
Control39=ID_FRMCADLIVROS_BTNPAUTOR,button,1476460544
Control40=ID_FRMCADLIVROS_LSTAUTORES,listbox,1486946561
Control41=ID_FRMCADLIVROS_BTNPESQUISAR,button,1342242816
Control42=ID_FRMCADLIVROS_BTNANTERIOR,button,1476460544
Control43=ID_FRMCADLIVROS_BTNPROXIMO,button,1476460544
Control44=ID_FRMCADLIVROS_BTNSALVAR,button,1476460544
Control45=ID_FRMCADLIVROS_BTNEXCLUIR,button,1476460544
Control46=ID_FRMCADLIVROS_BTNLIMPAR,button,1342242816
Control47=ID_FRMCADLIVROS_BTNFECHAR,button,1342242816

[DLG:FRMCONLIVROS (English (U.S.))]
Type=1
Class=CFrmConLivros
ControlCount=7
Control1=ID_FRMCONLIVROS_LABDESCRICAO,static,1342177280
Control2=ID_FRMCONLIVROS_EDTDESCRICAO,edit,1350631552
Control3=ID_FRMCONLIVROS_BTNPESQUISAR,button,1342242816
Control4=ID_FRMCONLIVROS_LISTCONSULTA,SysListView32,1350633485
Control5=ID_FRMCONLIVROS_LABREGISTROS,static,1342177280
Control6=ID_FRMCONLIVROS_BTNLIMPAR,button,1342242816
Control7=ID_FRMCONLIVROS_BTNFECHAR,button,1342242816

[DLG:FRMCONCLIENTES (English (U.S.))]
Type=1
Class=CFrmConClientes
ControlCount=7
Control1=ID_FRMCONCLIENTES_LABDESCRICAO,static,1342177280
Control2=ID_FRMCONCLIENTES_EDTDESCRICAO,edit,1350631552
Control3=ID_FRMCONCLIENTES_BTNPESQUISAR,button,1342242816
Control4=ID_FRMCONCLIENTES_LISTCONSULTA,SysListView32,1350633485
Control5=ID_FRMCONCLIENTES_LABREGISTROS,static,1342177280
Control6=ID_FRMCONCLIENTES_BTNLIMPAR,button,1342242816
Control7=ID_FRMCONCLIENTES_BTNFECHAR,button,1342242816

[DLG:FRMCONVENDAS (English (U.S.))]
Type=1
Class=CFrmConVendas
ControlCount=20
Control1=ID_FRMCONVENDAS_LABDTHRVENDA,static,1342177280
Control2=ID_FRMCONVENDAS_EDTDTVENDA,SysDateTimePick32,1342242850
Control3=ID_FRMCONVENDAS_EDTHRVENDA,SysDateTimePick32,1342242859
Control4=ID_FRMCONVENDAS_BTNPESQUISAR,button,1342242816
Control5=ID_FRMCONVENDAS_LABCPF,static,1342177280
Control6=ID_FRMCONVENDAS_EDTCPF,edit,1350631552
Control7=ID_FRMCONVENDAS_LABCLIENTE,static,1342177280
Control8=ID_FRMCONVENDAS_EDTCLIENTE,edit,1484849280
Control9=ID_FRMCONVENDAS_BTNPCLIENTE,button,1342242816
Control10=ID_FRMCONVENDAS_LABISBN,static,1342177280
Control11=ID_FRMCONVENDAS_EDTISBN,edit,1350631552
Control12=ID_FRMCONVENDAS_LABLIVRO,static,1342177280
Control13=ID_FRMCONVENDAS_EDTLIVRO,edit,1484849280
Control14=ID_FRMCONVENDAS_BTNPLIVRO,button,1342242816
Control15=ID_FRMCONVENDAS_LISTCONSULTA,SysListView32,1350633485
Control16=ID_FRMCONVENDAS_LABREGISTROS,static,1342177280
Control17=ID_FRMCONVENDAS_LABPRECOTOTAL,static,1342177280
Control18=ID_FRMCONVENDAS_EDTPRECOTOTAL,edit,1484783616
Control19=ID_FRMCONVENDAS_BTNLIMPAR,button,1342242816
Control20=ID_FRMCONVENDAS_BTNFECHAR,button,1342242816

[DLG:FRMVENDERLIVROS (English (U.S.))]
Type=1
Class=CFrmVenderLivros
ControlCount=20
Control1=ID_FRMVENDERLIVROS_LABDTHRVENDA,static,1342177280
Control2=ID_FRMVENDERLIVROS_EDTDTHRVENDA,edit,1484849280
Control3=ID_FRMVENDERLIVROS_LABCPF,static,1342177280
Control4=ID_FRMVENDERLIVROS_EDTCPF,edit,1350631552
Control5=ID_FRMVENDERLIVROS_LABCLIENTE,static,1342177280
Control6=ID_FRMVENDERLIVROS_EDTCLIENTE,edit,1484783744
Control7=ID_FRMVENDERLIVROS_BTNPCLIENTE,button,1342242816
Control8=ID_FRMVENDERLIVROS_LABISBN,static,1342177280
Control9=ID_FRMVENDERLIVROS_EDTISBN,edit,1350631552
Control10=ID_FRMVENDERLIVROS_LABLIVRO,static,1342177280
Control11=ID_FRMVENDERLIVROS_EDTLIVRO,edit,1484783744
Control12=ID_FRMVENDERLIVROS_BTNADLIVROS,button,1342242816
Control13=ID_FRMVENDERLIVROS_BTNPLIVRO,button,1342242816
Control14=ID_FRMVENDERLIVROS_LABLIVROSVENDER,static,1342177280
Control15=ID_FRMVENDERLIVROS_LSTLIVROS,listbox,1350631681
Control16=ID_FRMVENDERLIVROS_LABPRECOTOTAL,static,1342177280
Control17=ID_FRMVENDERLIVROS_EDTPRECOTOTAL,edit,1484783744
Control18=ID_FRMVENDERLIVROS_BTNVENDER,button,1342242816
Control19=ID_FRMVENDERLIVROS_BTNLIMPAR,button,1342242816
Control20=ID_FRMVENDERLIVROS_BTNFECHAR,button,1342242816

[CLS:CFrmCadastros]
Type=0
HeaderFile=Cadastros.h
ImplementationFile=Cadastros.cpp
BaseClass=generic CWnd
Filter=W
LastObject=CFrmCadastros

[CLS:CFrmConsultas]
Type=0
HeaderFile=Consultas.h
ImplementationFile=Consultas.cpp
BaseClass=generic CWnd
Filter=W
LastObject=CFrmConsultas

[CLS:CFrmSplash]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFrmSplash

[CLS:CFrmLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFrmLogin

[CLS:CFrmSobre]
Type=0
HeaderFile=Sobre.h
ImplementationFile=Sobre.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFrmSobre

[CLS:CFrmConAssuntos]
Type=0
HeaderFile=ConAssuntos.h
ImplementationFile=ConAssuntos.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFrmConAssuntos

[CLS:CFrmAlterarSenha]
Type=0
HeaderFile=AlterarSenha.h
ImplementationFile=AlterarSenha.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmAlterarSenha
VirtualFilter=dWC

[CLS:CFrmCadClientes]
Type=0
HeaderFile=CadClientes.h
ImplementationFile=CadClientes.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_FRMCADCLIENTES_BTNPPROFISSAO
VirtualFilter=dWC

[CLS:CFrmCadEditoras]
Type=0
HeaderFile=CadEditoras.h
ImplementationFile=CadEditoras.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmCadEditoras

[CLS:CFrmCadEnderecos]
Type=0
HeaderFile=CadEnderecos.h
ImplementationFile=CadEnderecos.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmCadEnderecos
VirtualFilter=dWC

[CLS:CFrmCadIdiomas]
Type=0
HeaderFile=CadIdiomas.h
ImplementationFile=CadIdiomas.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmCadIdiomas

[CLS:CFrmCadLivros]
Type=0
HeaderFile=CadLivros.h
ImplementationFile=CadLivros.cpp
BaseClass=CFrmCadastros
Filter=D
LastObject=ID_FRMCADLIVROS_LSTAUTORES
VirtualFilter=dWC

[CLS:CFrmCadPaises]
Type=0
HeaderFile=CadPaises.h
ImplementationFile=CadPaises.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmCadPaises

[CLS:CFrmCadProfissoes]
Type=0
HeaderFile=CadProfissoes.h
ImplementationFile=CadProfissoes.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmCadProfissoes

[CLS:CFrmConAutores]
Type=0
HeaderFile=ConAutores.h
ImplementationFile=ConAutores.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmConAutores

[CLS:CFrmConClientes]
Type=0
HeaderFile=ConClientes.h
ImplementationFile=ConClientes.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmConClientes

[CLS:CFrmConEditoras]
Type=0
HeaderFile=ConEditoras.h
ImplementationFile=ConEditoras.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmConEditoras

[CLS:CFrmConEnderecos]
Type=0
HeaderFile=ConEnderecos.h
ImplementationFile=ConEnderecos.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmConEnderecos

[CLS:CFrmConIdiomas]
Type=0
HeaderFile=ConIdiomas.h
ImplementationFile=ConIdiomas.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmConIdiomas

[CLS:CFrmConLivros]
Type=0
HeaderFile=ConLivros.h
ImplementationFile=ConLivros.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmConLivros

[CLS:CFrmConPaises]
Type=0
HeaderFile=ConPaises.h
ImplementationFile=ConPaises.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmConPaises

[CLS:CFrmConProfissoes]
Type=0
HeaderFile=ConProfissoes.h
ImplementationFile=ConProfissoes.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmConProfissoes

[CLS:CFrmConVendas]
Type=0
HeaderFile=ConVendas.h
ImplementationFile=ConVendas.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmConVendas
VirtualFilter=dWC

[CLS:CFrmVenderLivros]
Type=0
HeaderFile=VenderLivros.h
ImplementationFile=VenderLivros.cpp
BaseClass=CDialog
Filter=D
LastObject=CFrmVenderLivros
VirtualFilter=dWC

