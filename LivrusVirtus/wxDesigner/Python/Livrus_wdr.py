# -*- coding: iso-8859-1 -*-

#-----------------------------------------------------------------------------
# Python source generated by wxDesigner from file: Livrus.wdr
# Do not modify this file, all changes will be lost!
#-----------------------------------------------------------------------------

# Include wxWindows' modules
from wxPython.wx import *
from wxPython.grid import *

# Window functions

LAB_CODIGO = 10000
EDT_CODIGO = 10001
LAB_DESCRICAO = 10002
EDT_DESCRICAO = 10003
BTN_PESQUISAR = 10004
BTN_ANTERIOR = 10005
BTN_PROXIMO = 10006
BTN_SALVAR = 10007
BTN_EXCLUIR = 10008
BTN_LIMPAR = 10009
BTN_FECHAR = 10010

def frmCadAssuntos( parent, call_fit = True, set_sizer = True ):
    item0 = wxBoxSizer( wxVERTICAL )
    
    item1 = wxFlexGridSizer( 0, 2, 0, 0 )
    item1.AddGrowableCol( 0 )
    
    item2 = wxFlexGridSizer( 0, 1, 0, 0 )
    item2.AddGrowableRow( 0 )
    item2.AddGrowableRow( 1 )
    
    item3 = wxBoxSizer( wxVERTICAL )
    
    item4 = wxStaticText( parent, LAB_CODIGO, "C�digo:", wxDefaultPosition, wxDefaultSize, 0 )
    item4.SetName( "labCodigo" )
    item3.AddWindow( item4, 5, wxALIGN_CENTER_VERTICAL, 0 )

    item5 = wxTextCtrl( parent, EDT_CODIGO, "", wxDefaultPosition, wxSize(80,-1), 0 )
    item5.SetName( "edtCodigo" )
    item3.AddWindow( item5, 0, wxALIGN_CENTER, 0 )

    item2.AddSizer( item3, 0, wxALIGN_CENTER_VERTICAL, 0 )

    item6 = wxBoxSizer( wxVERTICAL )
    
    item7 = wxStaticText( parent, LAB_DESCRICAO, "Assunto:", wxDefaultPosition, wxDefaultSize, 0 )
    item7.SetName( "labDescricao" )
    item6.AddWindow( item7, 5, wxALIGN_CENTER_VERTICAL, 0 )

    item8 = wxTextCtrl( parent, EDT_DESCRICAO, "", wxDefaultPosition, wxSize(200,-1), 0 )
    item8.SetName( "edtDescricao" )
    item6.AddWindow( item8, 0, wxALIGN_CENTER, 0 )

    item2.AddSizer( item6, 0, wxALIGN_CENTER, 0 )

    item1.AddSizer( item2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 )

    item9 = wxBoxSizer( wxVERTICAL )
    
    item10 = wxButton( parent, BTN_PESQUISAR, "Pesquisar", wxDefaultPosition, wxDefaultSize, 0 )
    item10.SetDefault()
    item10.SetName( "btnPesquisar" )
    item9.AddWindow( item10, 0, wxALIGN_CENTER|wxALL, 0 )

    item11 = wxButton( parent, BTN_ANTERIOR, "Anterior", wxDefaultPosition, wxDefaultSize, 0 )
    item11.SetName( "btnAnterior" )
    item11.Enable(False)
    item9.AddWindow( item11, 0, wxALIGN_CENTER|wxALL, 5 )

    item12 = wxButton( parent, BTN_PROXIMO, "Pr�ximo", wxDefaultPosition, wxDefaultSize, 0 )
    item12.SetName( "btnProximo" )
    item12.Enable(False)
    item9.AddWindow( item12, 0, wxALIGN_CENTER|wxALL, 0 )

    item1.AddSizer( item9, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 )

    item0.AddSizer( item1, 0, wxGROW|wxALIGN_CENTER_VERTICAL, 0 )

    item13 = wxBoxSizer( wxHORIZONTAL )
    
    item14 = wxButton( parent, BTN_SALVAR, "Salvar", wxDefaultPosition, wxDefaultSize, 0 )
    item14.SetName( "btnSalvar" )
    item14.Enable(False)
    item13.AddWindow( item14, 0, wxALIGN_CENTER|wxALL, 5 )

    item15 = wxButton( parent, BTN_EXCLUIR, "Excluir", wxDefaultPosition, wxDefaultSize, 0 )
    item15.SetName( "btnExcluir" )
    item15.Enable(False)
    item13.AddWindow( item15, 0, wxALIGN_CENTER|wxALL, 5 )

    item16 = wxButton( parent, BTN_LIMPAR, "Limpar", wxDefaultPosition, wxDefaultSize, 0 )
    item16.SetName( "btnLimpar" )
    item13.AddWindow( item16, 0, wxALIGN_CENTER|wxALL, 5 )

    item17 = wxButton( parent, BTN_FECHAR, "Fechar", wxDefaultPosition, wxDefaultSize, 0 )
    item17.SetName( "btnFechar" )
    item13.AddWindow( item17, 0, wxALIGN_CENTER|wxALL, 5 )

    item0.AddSizer( item13, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 )

    if set_sizer == True:
        parent.SetAutoLayout( True )
        parent.SetSizer( item0 )
        if call_fit == True:
            item0.Fit( parent )
            item0.SetSizeHints( parent )
    
    return item0


def frmCadAutores( parent, call_fit = True, set_sizer = True ):
    item0 = wxBoxSizer( wxVERTICAL )
    
    item1 = wxFlexGridSizer( 0, 2, 0, 0 )
    item1.AddGrowableCol( 0 )
    
    item2 = wxFlexGridSizer( 0, 1, 0, 0 )
    item2.AddGrowableRow( 0 )
    item2.AddGrowableRow( 1 )
    
    item3 = wxBoxSizer( wxVERTICAL )
    
    item4 = wxStaticText( parent, LAB_CODIGO, "C�digo:", wxDefaultPosition, wxDefaultSize, 0 )
    item4.SetName( "labCodigo" )
    item3.AddWindow( item4, 5, wxALIGN_CENTER_VERTICAL, 5 )

    item5 = wxTextCtrl( parent, EDT_CODIGO, "", wxDefaultPosition, wxSize(80,-1), 0 )
    item5.SetName( "edtCodigo" )
    item3.AddWindow( item5, 0, wxALIGN_CENTER|wxALL, 0 )

    item2.AddSizer( item3, 0, wxALIGN_CENTER_VERTICAL, 0 )

    item6 = wxBoxSizer( wxVERTICAL )
    
    item7 = wxStaticText( parent, LAB_DESCRICAO, "Autor:", wxDefaultPosition, wxSize(100,-1), 0 )
    item7.SetName( "labDescricao" )
    item6.AddWindow( item7, 5, wxALIGN_CENTER_VERTICAL, 5 )

    item8 = wxTextCtrl( parent, EDT_DESCRICAO, "", wxDefaultPosition, wxSize(200,-1), 0 )
    item8.SetName( "edtDescricao" )
    item6.AddWindow( item8, 0, wxALIGN_CENTER|wxALL, 0 )

    item2.AddSizer( item6, 0, wxALIGN_CENTER, 0 )

    item1.AddSizer( item2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 )

    item9 = wxBoxSizer( wxVERTICAL )
    
    item10 = wxButton( parent, BTN_PESQUISAR, "Pesquisar", wxDefaultPosition, wxDefaultSize, 0 )
    item10.SetDefault()
    item10.SetName( "btnPesquisar" )
    item9.AddWindow( item10, 0, wxALIGN_CENTER|wxALL, 0 )

    item11 = wxButton( parent, BTN_ANTERIOR, "Anterior", wxDefaultPosition, wxDefaultSize, 0 )
    item11.SetName( "btnAnterior" )
    item11.Enable(False)
    item9.AddWindow( item11, 0, wxALIGN_CENTER|wxALL, 5 )

    item12 = wxButton( parent, BTN_PROXIMO, "Pr�ximo", wxDefaultPosition, wxDefaultSize, 0 )
    item12.SetName( "btnProximo" )
    item12.Enable(False)
    item9.AddWindow( item12, 0, wxALIGN_CENTER|wxALL, 0 )

    item1.AddSizer( item9, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 )

    item0.AddSizer( item1, 0, wxGROW|wxALIGN_CENTER_VERTICAL, 0 )

    item13 = wxBoxSizer( wxHORIZONTAL )
    
    item14 = wxButton( parent, BTN_SALVAR, "Salvar", wxDefaultPosition, wxDefaultSize, 0 )
    item14.SetName( "btnSalvar" )
    item14.Enable(False)
    item13.AddWindow( item14, 0, wxALIGN_CENTER|wxALL, 5 )

    item15 = wxButton( parent, BTN_EXCLUIR, "Excluir", wxDefaultPosition, wxDefaultSize, 0 )
    item15.SetName( "btnExcluir" )
    item15.Enable(False)
    item13.AddWindow( item15, 0, wxALIGN_CENTER|wxALL, 5 )

    item16 = wxButton( parent, BTN_LIMPAR, "Limpar", wxDefaultPosition, wxDefaultSize, 0 )
    item16.SetName( "btnLimpar" )
    item13.AddWindow( item16, 0, wxALIGN_CENTER|wxALL, 5 )

    item17 = wxButton( parent, BTN_FECHAR, "Fechar", wxDefaultPosition, wxDefaultSize, 0 )
    item17.SetName( "btnFechar" )
    item13.AddWindow( item17, 0, wxALIGN_CENTER|wxALL, 5 )

    item0.AddSizer( item13, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 )

    if set_sizer == True:
        parent.SetAutoLayout( True )
        parent.SetSizer( item0 )
        if call_fit == True:
            item0.Fit( parent )
            item0.SetSizeHints( parent )
    
    return item0

GRID_CONSULTA = 10011
LAB_REGISTROS = 10012
LAB_LIMPAR = 10013

def frmConAssuntos( parent, call_fit = True, set_sizer = True ):
    item0 = wxFlexGridSizer( 0, 1, 0, 0 )
    item0.AddGrowableRow( 1 )
    
    item1 = wxBoxSizer( wxHORIZONTAL )
    
    item2 = wxBoxSizer( wxVERTICAL )
    
    item3 = wxStaticText( parent, LAB_DESCRICAO, "Assunto:", wxDefaultPosition, wxSize(40,-1), 0 )
    item3.SetName( "labDescricao" )
    item2.AddWindow( item3, 5, wxALIGN_CENTER_VERTICAL, 5 )

    item4 = wxTextCtrl( parent, EDT_DESCRICAO, "", wxDefaultPosition, wxSize(250,-1), 0 )
    item4.SetName( "edtDescricao" )
    item2.AddWindow( item4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0 )

    item1.AddSizer( item2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 )

    item5 = wxButton( parent, BTN_PESQUISAR, "Pesquisar", wxDefaultPosition, wxDefaultSize, 0 )
    item5.SetName( "btnPesquisar" )
    item1.AddWindow( item5, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 )

    item0.AddSizer( item1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 )

    item6 = wxGrid( parent, GRID_CONSULTA, wxDefaultPosition, wxSize(300,150), wxWANTS_CHARS )
    item6.CreateGrid( 2, 2, wxGrid.wxGridSelectCells )
    item6.SetName( "gridConsulta" )
    item0.AddWindow( item6, 0, wxGROW, 0 )

    item7 = wxFlexGridSizer( 0, 2, 0, 0 )
    item7.AddGrowableCol( 0 )
    
    item8 = wxBoxSizer( wxHORIZONTAL )
    
    item9 = wxStaticText( parent, LAB_REGISTROS, "Registro: 0 de 0", wxDefaultPosition, wxDefaultSize, 0 )
    item9.SetName( "labRegistros" )
    item8.AddWindow( item9, 0, wxALIGN_CENTER|wxALL, 5 )

    item7.AddSizer( item8, 0, wxALIGN_BOTTOM|wxALL, 5 )

    item10 = wxBoxSizer( wxHORIZONTAL )
    
    item11 = wxButton( parent, LAB_LIMPAR, "Limpar", wxDefaultPosition, wxDefaultSize, 0 )
    item11.SetName( "btnLimpar" )
    item10.AddWindow( item11, 0, wxALIGN_CENTER|wxALL, 5 )

    item12 = wxButton( parent, BTN_FECHAR, "Fechar", wxDefaultPosition, wxDefaultSize, 0 )
    item12.SetName( "btnFechar" )
    item10.AddWindow( item12, 0, wxALIGN_CENTER|wxALL, 5 )

    item7.AddSizer( item10, 0, wxGROW|wxALIGN_BOTTOM|wxALL, 5 )

    item0.AddSizer( item7, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5 )

    if set_sizer == True:
        parent.SetAutoLayout( True )
        parent.SetSizer( item0 )
        if call_fit == True:
            item0.Fit( parent )
            item0.SetSizeHints( parent )
    
    return item0

ID_STATICBITMAP = 10014

def frmSplash( parent, call_fit = True, set_sizer = True ):
    item0 = wxBoxSizer( wxVERTICAL )
    
    item1 = wxStaticBitmap( parent, ID_STATICBITMAP, ListaBitmaps( 6 ), wxDefaultPosition, wxDefaultSize )
    item0.AddWindow( item1, 0, wxALIGN_CENTER|wxALL, 5 )

    if set_sizer == True:
        parent.SetAutoLayout( True )
        parent.SetSizer( item0 )
        if call_fit == True:
            item0.Fit( parent )
            item0.SetSizeHints( parent )
    
    return item0

LAB_LOGIN = 10015
EDT_LOGIN = 10016
LAB_SENHA = 10017
EDT_SENHA = 10018
BTN_LOGIN = 10019
BTN_CANCELAR = 10020

def frmLogin( parent, call_fit = True, set_sizer = True ):
    item0 = wxBoxSizer( wxVERTICAL )
    
    item1 = wxBoxSizer( wxHORIZONTAL )
    
    item2 = wxStaticBitmap( parent, ID_STATICBITMAP, ListaBitmaps( 5 ), wxDefaultPosition, wxDefaultSize )
    item1.AddWindow( item2, 0, wxALIGN_CENTER|wxALL, 0 )

    item3 = wxBoxSizer( wxVERTICAL )
    
    item4 = wxBoxSizer( wxVERTICAL )
    
    item5 = wxStaticText( parent, LAB_LOGIN, "Login:", wxDefaultPosition, wxDefaultSize, 0 )
    item5.SetName( "labLogin" )
    item4.AddWindow( item5, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxBOTTOM, 5 )

    item6 = wxTextCtrl( parent, EDT_LOGIN, "", wxDefaultPosition, wxSize(80,-1), 0 )
    item6.SetName( "edtLogin" )
    item4.AddWindow( item6, 0, wxALIGN_CENTER|wxALL, 0 )

    item3.AddSizer( item4, 0, wxALIGN_CENTER|wxALL, 5 )

    item7 = wxBoxSizer( wxVERTICAL )
    
    item8 = wxStaticText( parent, LAB_SENHA, "Senha:", wxDefaultPosition, wxDefaultSize, 0 )
    item8.SetName( "labSenha" )
    item7.AddWindow( item8, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxBOTTOM, 5 )

    item9 = wxTextCtrl( parent, EDT_SENHA, "", wxDefaultPosition, wxSize(80,-1), wxTE_PASSWORD )
    item9.SetName( "edtSenha" )
    item7.AddWindow( item9, 0, wxALIGN_CENTER|wxALL, 0 )

    item3.AddSizer( item7, 0, wxALIGN_CENTER|wxALL, 5 )

    item1.AddSizer( item3, 0, wxALIGN_CENTER|wxALL, 0 )

    item0.AddSizer( item1, 0, wxALIGN_CENTER|wxALL, 5 )

    item10 = wxBoxSizer( wxHORIZONTAL )
    
    item11 = wxButton( parent, BTN_LOGIN, "Login", wxDefaultPosition, wxDefaultSize, 0 )
    item11.SetDefault()
    item11.SetName( "btnLogin" )
    item10.AddWindow( item11, 0, wxALIGN_CENTER|wxALL, 5 )

    item12 = wxButton( parent, BTN_CANCELAR, "Cancelar", wxDefaultPosition, wxDefaultSize, 0 )
    item12.SetName( "btnCancelar" )
    item10.AddWindow( item12, 0, wxALIGN_CENTER|wxALL, 5 )

    item0.AddSizer( item10, 0, wxALIGN_CENTER|wxALL, 5 )

    if set_sizer == True:
        parent.SetAutoLayout( True )
        parent.SetSizer( item0 )
        if call_fit == True:
            item0.Fit( parent )
            item0.SetSizeHints( parent )
    
    return item0

ID_TEXT = 10021
BTN_OK = 10022

def frmSobre( parent, call_fit = True, set_sizer = True ):
    item0 = wxBoxSizer( wxVERTICAL )
    
    item2 = wxStaticBox( parent, -1, "" )
    item1 = wxStaticBoxSizer( item2, wxVERTICAL )
    
    item3 = wxStaticBitmap( parent, ID_STATICBITMAP, ListaBitmaps( 6 ), wxDefaultPosition, wxDefaultSize )
    item1.AddWindow( item3, 0, wxALIGN_CENTER|wxALL, 5 )

    item4 = wxStaticText( parent, ID_TEXT, "Vers�o: 1.0.0", wxDefaultPosition, wxDefaultSize, 0 )
    item1.AddWindow( item4, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 )

    item5 = wxStaticText( parent, ID_TEXT, "Todos os direitos reservados para: Henrique F. de Souza", wxDefaultPosition, wxDefaultSize, 0 )
    item1.AddWindow( item5, 0, wxALIGN_CENTER|wxALL, 5 )

    item6 = wxStaticText( parent, ID_TEXT, "Sistema integrante do projeto Livrus Virtus,", wxDefaultPosition, wxDefaultSize, 0 )
    item1.AddWindow( item6, 0, wxALIGN_CENTER|wxALL, 5 )

    item7 = wxStaticText( parent, ID_TEXT, "vers�o programado no wxDesigner.", wxDefaultPosition, wxDefaultSize, 0 )
    item1.AddWindow( item7, 0, wxALIGN_CENTER|wxALL, 5 )

    item0.AddSizer( item1, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5 )

    item8 = wxButton( parent, BTN_OK, "OK", wxDefaultPosition, wxDefaultSize, 0 )
    item8.SetName( "btnOk" )
    item0.AddWindow( item8, 0, wxALIGN_CENTER|wxALL, 5 )

    if set_sizer == True:
        parent.SetAutoLayout( True )
        parent.SetSizer( item0 )
        if call_fit == True:
            item0.Fit( parent )
            item0.SetSizeHints( parent )
    
    return item0

EDT_SENHAATUAL = 10023
EDT_NOVASENHA = 10024
EDT_CONFIRMSENHA = 10025

def frmAlterarSenha( parent, call_fit = True, set_sizer = True ):
    item0 = wxBoxSizer( wxVERTICAL )
    
    item1 = wxGridSizer( 0, 2, 0, 0 )
    
    item2 = wxBoxSizer( wxVERTICAL )
    
    item3 = wxStaticText( parent, ID_TEXT, "Login:", wxDefaultPosition, wxDefaultSize, 0 )
    item2.AddWindow( item3, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxBOTTOM, 5 )

    item4 = wxTextCtrl( parent, EDT_LOGIN, "", wxDefaultPosition, wxSize(100,-1), 0 )
    item4.SetName( "edtLogin" )
    item2.AddWindow( item4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0 )

    item1.AddSizer( item2, 0, wxALIGN_CENTER|wxALL, 5 )

    item5 = wxBoxSizer( wxVERTICAL )
    
    item6 = wxStaticText( parent, ID_TEXT, "Senha atual:", wxDefaultPosition, wxDefaultSize, 0 )
    item5.AddWindow( item6, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxBOTTOM, 5 )

    item7 = wxTextCtrl( parent, EDT_SENHAATUAL, "", wxDefaultPosition, wxSize(100,-1), 0 )
    item7.SetName( "edtSenhaAtual" )
    item5.AddWindow( item7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0 )

    item1.AddSizer( item5, 0, wxALIGN_CENTER|wxALL, 5 )

    item8 = wxBoxSizer( wxVERTICAL )
    
    item9 = wxStaticText( parent, ID_TEXT, "Nova senha:", wxDefaultPosition, wxDefaultSize, 0 )
    item8.AddWindow( item9, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxBOTTOM, 5 )

    item10 = wxTextCtrl( parent, EDT_NOVASENHA, "", wxDefaultPosition, wxSize(100,-1), 0 )
    item10.SetName( "edtNovaSenha" )
    item8.AddWindow( item10, 0, wxALIGN_CENTER|wxALL, 0 )

    item1.AddSizer( item8, 0, wxALIGN_CENTER|wxALL, 5 )

    item11 = wxBoxSizer( wxVERTICAL )
    
    item12 = wxStaticText( parent, ID_TEXT, "Confirmar senha:", wxDefaultPosition, wxDefaultSize, 0 )
    item11.AddWindow( item12, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxBOTTOM, 5 )

    item13 = wxTextCtrl( parent, EDT_CONFIRMSENHA, "", wxDefaultPosition, wxSize(100,-1), 0 )
    item13.SetName( "edtConfirmarSenha" )
    item11.AddWindow( item13, 0, wxALIGN_CENTER_VERTICAL, 5 )

    item1.AddSizer( item11, 0, wxALIGN_CENTER|wxALL, 5 )

    item0.AddSizer( item1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 )

    item14 = wxBoxSizer( wxHORIZONTAL )
    
    item15 = wxButton( parent, BTN_SALVAR, "Salvar", wxDefaultPosition, wxDefaultSize, 0 )
    item15.SetName( "btnSalvar" )
    item14.AddWindow( item15, 0, wxALIGN_CENTER|wxALL, 5 )

    item16 = wxButton( parent, BTN_LIMPAR, "Limpar", wxDefaultPosition, wxDefaultSize, 0 )
    item16.SetName( "btnLimpar" )
    item14.AddWindow( item16, 0, wxALIGN_CENTER|wxALL, 5 )

    item17 = wxButton( parent, BTN_FECHAR, "Fechar", wxDefaultPosition, wxDefaultSize, 0 )
    item17.SetName( "btnFechar" )
    item14.AddWindow( item17, 0, wxALIGN_CENTER|wxALL, 5 )

    item0.AddSizer( item14, 0, wxALIGN_CENTER|wxALL, 5 )

    if set_sizer == True:
        parent.SetAutoLayout( True )
        parent.SetSizer( item0 )
        if call_fit == True:
            item0.Fit( parent )
            item0.SetSizeHints( parent )
    
    return item0

# Menubar functions

MNU_CADASSUNTOS = 11
MNU_CADAUTORES = 12
MNU_CADENDERECOS = 13
MNU_CADIDIOMAS = 14
MNU_CADPAISES = 15
MNU_CADPROFISSOES = 16
ID_MENU = 10026
MNU_CADCLIENTES = 17
MNU_CADLIVROS = 18
MNU_CADASTROS = 10
MNU_CONASSUNTOS = 21
MNU_CONAUTORES = 22
MNU_CONENDERECOS = 23
MNU_CONIDIOMAS = 24
MNU_CONPAISES = 25
MNU_CONPROFISSOES = 26
MNU_CONCLIENTES = 27
MNU_CONLIVROS = 28
MNU_PESQUISAS = 20
MNU_VENDER = 31
MNU_VENDASREALIZADAS = 32
MNU_VENDAS = 30
MNU_LADOALADOHORIZONTAL = 41
MNU_LADOALADOVERTICAL = 42
MNU_EMCASCATA = 43
MNU_ORGANIZARICONES = 44
MNU_JANELAS = 40
MNU_ALTERARSENHA = 51
MNU_SOBRE = 52
MNU_SAIR = 53
MNU_OPCOES = 50

def MontaBarraDeMenu():
    item0 = wxMenuBar()
    
    item1 = wxMenu()
    item1.Append( MNU_CADASSUNTOS, "Assuntos", "" )
    item1.Append( MNU_CADAUTORES, "Autores", "" )
    item1.Append( MNU_CADENDERECOS, "Endere�os", "" )
    item1.Append( MNU_CADIDIOMAS, "Idiomas", "" )
    item1.Append( MNU_CADPAISES, "Pa�ses", "" )
    item1.Append( MNU_CADPROFISSOES, "Profiss�es", "" )
    item1.AppendSeparator()
    item1.Append( MNU_CADCLIENTES, "Clientes", "" )
    item1.Append( MNU_CADLIVROS, "Livros", "" )
    item0.Append( item1, "Cadastros" )
    
    item2 = wxMenu()
    item2.Append( MNU_CONASSUNTOS, "Assuntos", "" )
    item2.Append( MNU_CONAUTORES, "Autores", "" )
    item2.Append( MNU_CONENDERECOS, "Endere�os", "" )
    item2.Append( MNU_CONIDIOMAS, "Idiomas", "" )
    item2.Append( MNU_CONPAISES, "Pa�ses", "" )
    item2.Append( MNU_CONPROFISSOES, "Profiss�es", "" )
    item2.AppendSeparator()
    item2.Append( MNU_CONCLIENTES, "Clientes", "" )
    item2.Append( MNU_CONLIVROS, "Livros", "" )
    item0.Append( item2, "Pesquisas" )
    
    item3 = wxMenu()
    item3.Append( MNU_VENDER, "Vender", "" )
    item3.Append( MNU_VENDASREALIZADAS, "Vendas Realizadas", "" )
    item0.Append( item3, "Vendas" )
    
    item4 = wxMenu()
    item4.Append( MNU_LADOALADOHORIZONTAL, "Lado a lado horizontal", "" )
    item4.Append( MNU_LADOALADOVERTICAL, "Lado a lado vertical", "" )
    item4.Append( MNU_EMCASCATA, "Em cascata", "" )
    item4.Append( MNU_ORGANIZARICONES, "Organizar �cones", "" )
    item0.Append( item4, "Janelas" )
    
    item5 = wxMenu()
    item5.Append( MNU_ALTERARSENHA, "Alterar Senha", "" )
    item5.AppendSeparator()
    item5.Append( MNU_SOBRE, "Sobre", "" )
    item5.Append( MNU_SAIR, "Sair", "" )
    item0.Append( item5, "Op��es" )
    
    return item0

# Toolbar functions

TLB_CLIENTE = 0
TLB_LIVRO = 1
TLB_VENDAS = 2
TLB_SOBRE = 3
TLB_SAIR = 4

def MontaBarraDeFerramentas( parent ):
    parent.SetMargins( [2,2] )
    
    parent.AddLabelTool( TLB_CLIENTE, "", ListaBitmaps( 0 ), wxNullBitmap, wxITEM_NORMAL, "" )
    parent.AddLabelTool( TLB_LIVRO, "", ListaBitmaps( 1 ), wxNullBitmap, wxITEM_NORMAL, "" )
    parent.AddLabelTool( TLB_VENDAS, "", ListaBitmaps( 2 ), wxNullBitmap, wxITEM_NORMAL, "" )
    parent.AddSeparator()
    parent.AddLabelTool( TLB_SOBRE, "", ListaBitmaps( 3 ), wxNullBitmap, wxITEM_NORMAL, "" )
    parent.AddLabelTool( TLB_SAIR, "", ListaBitmaps( 4 ), wxNullBitmap, wxITEM_NORMAL, "" )
    
    parent.Realize()

# Bitmap functions

BMP_CLIENTE = 0
BMP_LIVRO = 1
BMP_LIVROS = 2
BMP_SOBRE = 3
BMP_SAIR = 4
BMP_LOGIN = 5
BMP_SPLASH = 6
BMP_LIVRUSVIRTUS = 7

def ListaBitmaps( index ):
    if (index == 0) or (index == BMP_CLIENTE):
        return wxImage( "Livrus_wdr/ListaBitmaps_0.png", wxBITMAP_TYPE_PNG ).ConvertToBitmap()
    if (index == 1) or (index == BMP_LIVRO):
        return wxImage( "Livrus_wdr/ListaBitmaps_1.png", wxBITMAP_TYPE_PNG ).ConvertToBitmap()
    if (index == 2) or (index == BMP_LIVROS):
        return wxImage( "Livrus_wdr/ListaBitmaps_2.png", wxBITMAP_TYPE_PNG ).ConvertToBitmap()
    if (index == 3) or (index == BMP_SOBRE):
        return wxImage( "Livrus_wdr/ListaBitmaps_3.png", wxBITMAP_TYPE_PNG ).ConvertToBitmap()
    if (index == 4) or (index == BMP_SAIR):
        return wxImage( "Livrus_wdr/ListaBitmaps_4.png", wxBITMAP_TYPE_PNG ).ConvertToBitmap()
    if (index == 5) or (index == BMP_LOGIN):
        return wxImage( "Livrus_wdr/ListaBitmaps_5.png", wxBITMAP_TYPE_PNG ).ConvertToBitmap()
    if (index == 6) or (index == BMP_SPLASH):
        return wxImage( "Livrus_wdr/ListaBitmaps_6.png", wxBITMAP_TYPE_PNG ).ConvertToBitmap()
    if (index == 7) or (index == BMP_LIVRUSVIRTUS):
        return wxImage( "Livrus_wdr/ListaBitmaps_7.png", wxBITMAP_TYPE_PNG ).ConvertToBitmap()
    return wxNullBitmap

# End of generated file
