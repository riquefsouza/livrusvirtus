/****************************************************************************
** Form implementation generated from reading ui file 'Principal.ui'
**
** Created: sáb 20. nov 20:10:04 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Principal.h"

#include <qvariant.h>
#include <qtoolbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qtoolbar.h>
#include <qimage.h>
#include <qpixmap.h>

#include "Principal.ui.h"
/*
 *  Constructs a frmPrincipal as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
frmPrincipal::frmPrincipal( QWidget* parent, const char* name, WFlags fl )
    : QMainWindow( parent, name, fl )
{
    (void)statusBar();
    if ( !name )
	setName( "frmPrincipal" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );

    // actions
    cadastrosAssuntosAction = new QAction( this, "cadastrosAssuntosAction" );
    cadastrosAutoresAction = new QAction( this, "cadastrosAutoresAction" );
    cadastrosEditorasAction = new QAction( this, "cadastrosEditorasAction" );
    cadastrosEnderecosAction = new QAction( this, "cadastrosEnderecosAction" );
    cadastrosIdiomasAction = new QAction( this, "cadastrosIdiomasAction" );
    cadastrosPaisesAction = new QAction( this, "cadastrosPaisesAction" );
    cadastrosProfissoesAction = new QAction( this, "cadastrosProfissoesAction" );
    cadastrosClientesAction = new QAction( this, "cadastrosClientesAction" );
    cadastrosLivrosAction = new QAction( this, "cadastrosLivrosAction" );
    pesquisasAssuntosAction = new QAction( this, "pesquisasAssuntosAction" );
    pesquisasAutoresAction = new QAction( this, "pesquisasAutoresAction" );
    pesquisasEditorasAction = new QAction( this, "pesquisasEditorasAction" );
    pesquisasEnderecosAction = new QAction( this, "pesquisasEnderecosAction" );
    pesquisasIdiomasAction = new QAction( this, "pesquisasIdiomasAction" );
    pesquisasPaisesAction = new QAction( this, "pesquisasPaisesAction" );
    pesquisasProfissoesAction = new QAction( this, "pesquisasProfissoesAction" );
    pesquisasClientesAction = new QAction( this, "pesquisasClientesAction" );
    pesquisasLivrosAction = new QAction( this, "pesquisasLivrosAction" );
    vendasVenderLivrosAction = new QAction( this, "vendasVenderLivrosAction" );
    vendasVendas_RealizadasAction = new QAction( this, "vendasVendas_RealizadasAction" );
    janelasLadoaladohorizontalAction = new QAction( this, "janelasLadoaladohorizontalAction" );
    janelasLadoaladoverticalAction = new QAction( this, "janelasLadoaladoverticalAction" );
    janelasEmcascataAction = new QAction( this, "janelasEmcascataAction" );
    opcoesAlterarSenhaAction = new QAction( this, "opcoesAlterarSenhaAction" );
    opcoesSobreAction = new QAction( this, "opcoesSobreAction" );
    opcoesSairAction = new QAction( this, "opcoesSairAction" );
    janelasOrganizarIconesAction = new QAction( this, "janelasOrganizarIconesAction" );


    // toolbars
    toolBar = new QToolBar( QString(""), this, DockTop ); 


    tbClientes = new QToolButton( toolBar, "tbClientes" );
    tbClientes->setIconSet( QIconSet( QPixmap::fromMimeSource( "cliente.xpm" ) ) );

    tbLivros = new QToolButton( toolBar, "tbLivros" );
    tbLivros->setIconSet( QIconSet( QPixmap::fromMimeSource( "Livro.xpm" ) ) );

    tbVender = new QToolButton( toolBar, "tbVender" );
    tbVender->setIconSet( QIconSet( QPixmap::fromMimeSource( "Livros.xpm" ) ) );
    toolBar->addSeparator();

    tbSobre = new QToolButton( toolBar, "tbSobre" );
    tbSobre->setIconSet( QIconSet( QPixmap::fromMimeSource( "Sobre.xpm" ) ) );

    tbSair = new QToolButton( toolBar, "tbSair" );
    tbSair->setIconSet( QIconSet( QPixmap::fromMimeSource( "Sair.xpm" ) ) );


    // menubar
    MenuBar = new QMenuBar( this, "MenuBar" );


    Cadastros = new QPopupMenu( this );
    cadastrosAssuntosAction->addTo( Cadastros );
    cadastrosAutoresAction->addTo( Cadastros );
    cadastrosEditorasAction->addTo( Cadastros );
    cadastrosEnderecosAction->addTo( Cadastros );
    cadastrosIdiomasAction->addTo( Cadastros );
    cadastrosPaisesAction->addTo( Cadastros );
    cadastrosProfissoesAction->addTo( Cadastros );
    Cadastros->insertSeparator();
    cadastrosClientesAction->addTo( Cadastros );
    cadastrosLivrosAction->addTo( Cadastros );
    MenuBar->insertItem( QString(""), Cadastros, 1 );

    Pesquisas = new QPopupMenu( this );
    pesquisasAssuntosAction->addTo( Pesquisas );
    pesquisasAutoresAction->addTo( Pesquisas );
    pesquisasEditorasAction->addTo( Pesquisas );
    pesquisasEnderecosAction->addTo( Pesquisas );
    pesquisasIdiomasAction->addTo( Pesquisas );
    pesquisasPaisesAction->addTo( Pesquisas );
    pesquisasProfissoesAction->addTo( Pesquisas );
    Pesquisas->insertSeparator();
    pesquisasClientesAction->addTo( Pesquisas );
    pesquisasLivrosAction->addTo( Pesquisas );
    MenuBar->insertItem( QString(""), Pesquisas, 2 );

    Vendas = new QPopupMenu( this );
    vendasVenderLivrosAction->addTo( Vendas );
    vendasVendas_RealizadasAction->addTo( Vendas );
    MenuBar->insertItem( QString(""), Vendas, 3 );

    Janelas = new QPopupMenu( this );
    janelasLadoaladohorizontalAction->addTo( Janelas );
    janelasLadoaladoverticalAction->addTo( Janelas );
    janelasEmcascataAction->addTo( Janelas );
    janelasOrganizarIconesAction->addTo( Janelas );
    MenuBar->insertItem( QString(""), Janelas, 4 );

    Opes = new QPopupMenu( this );
    opcoesAlterarSenhaAction->addTo( Opes );
    opcoesSobreAction->addTo( Opes );
    opcoesSairAction->addTo( Opes );
    MenuBar->insertItem( QString(""), Opes, 5 );

    languageChange();
    resize( QSize(621, 423).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( cadastrosAssuntosAction, SIGNAL( activated() ), this, SLOT( cadastrosAssuntosAction_activated() ) );
    connect( cadastrosAutoresAction, SIGNAL( activated() ), this, SLOT( cadastrosAutoresAction_activated() ) );
    connect( cadastrosEditorasAction, SIGNAL( activated() ), this, SLOT( cadastrosEditorasAction_activated() ) );
    connect( cadastrosEnderecosAction, SIGNAL( activated() ), this, SLOT( cadastrosEnderecosAction_activated() ) );
    connect( cadastrosIdiomasAction, SIGNAL( activated() ), this, SLOT( cadastrosIdiomasAction_activated() ) );
    connect( cadastrosPaisesAction, SIGNAL( activated() ), this, SLOT( cadastrosPaisesAction_activated() ) );
    connect( cadastrosProfissoesAction, SIGNAL( activated() ), this, SLOT( cadastrosProfissoesAction_activated() ) );
    connect( cadastrosClientesAction, SIGNAL( activated() ), this, SLOT( cadastrosClientesAction_activated() ) );
    connect( cadastrosLivrosAction, SIGNAL( activated() ), this, SLOT( cadastrosLivrosAction_activated() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmPrincipal::~frmPrincipal()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmPrincipal::languageChange()
{
    setCaption( tr( "Livrus Virtus" ) );
    cadastrosAssuntosAction->setText( tr( "&Assuntos" ) );
    cadastrosAssuntosAction->setMenuText( tr( "&Assuntos" ) );
    cadastrosAssuntosAction->setToolTip( tr( "Cadastro de Assuntos." ) );
    cadastrosAutoresAction->setText( tr( "Au&tores" ) );
    cadastrosAutoresAction->setMenuText( tr( "Au&tores" ) );
    cadastrosAutoresAction->setToolTip( tr( "Cadastro de Autores." ) );
    cadastrosEditorasAction->setText( tr( "&Editoras" ) );
    cadastrosEditorasAction->setMenuText( tr( "&Editoras" ) );
    cadastrosEditorasAction->setToolTip( tr( "Cadastro de Editoras." ) );
    cadastrosEnderecosAction->setText( trUtf8( "\x45\x26\x6e\x64\x65\x72\x65\xc3\xa7\x6f\x73" ) );
    cadastrosEnderecosAction->setMenuText( trUtf8( "\x45\x26\x6e\x64\x65\x72\x65\xc3\xa7\x6f\x73" ) );
    cadastrosEnderecosAction->setToolTip( trUtf8( "\x43\x61\x64\x61\x73\x74\x72\x6f\x20\x64\x65\x20\x45\x6e\x64\x65\x72\x65\xc3\xa7\x6f\x73\x2e" ) );
    cadastrosIdiomasAction->setText( tr( "&Idiomas" ) );
    cadastrosIdiomasAction->setMenuText( tr( "&Idiomas" ) );
    cadastrosIdiomasAction->setToolTip( tr( "Cadastro de Idiomas." ) );
    cadastrosPaisesAction->setText( trUtf8( "\x26\x50\x61\xc3\xad\x73\x65\x73" ) );
    cadastrosPaisesAction->setMenuText( trUtf8( "\x26\x50\x61\xc3\xad\x73\x65\x73" ) );
    cadastrosPaisesAction->setToolTip( trUtf8( "\x43\x61\x64\x61\x73\x74\x72\x6f\x20\x64\x65\x20\x50\x61\xc3\xad\x73\x65\x73\x2e" ) );
    cadastrosProfissoesAction->setText( trUtf8( "\x50\x26\x72\x6f\x66\x69\x73\x73\xc3\xb5\x65\x73" ) );
    cadastrosProfissoesAction->setMenuText( trUtf8( "\x50\x26\x72\x6f\x66\x69\x73\x73\xc3\xb5\x65\x73" ) );
    cadastrosProfissoesAction->setToolTip( trUtf8( "\x43\x61\x64\x61\x73\x74\x72\x6f\x20\x64\x65\x20\x50\x72\x6f\x66\x69\x73\x73\xc3\xb5\x65\x73\x2e" ) );
    cadastrosClientesAction->setText( tr( "&Clientes" ) );
    cadastrosClientesAction->setMenuText( tr( "&Clientes" ) );
    cadastrosClientesAction->setToolTip( tr( "Cadastro de Clientes." ) );
    cadastrosLivrosAction->setText( tr( "&Livros" ) );
    cadastrosLivrosAction->setMenuText( tr( "&Livros" ) );
    cadastrosLivrosAction->setToolTip( tr( "Cadastro de Livros." ) );
    pesquisasAssuntosAction->setText( tr( "&Assuntos" ) );
    pesquisasAssuntosAction->setMenuText( tr( "&Assuntos" ) );
    pesquisasAssuntosAction->setToolTip( tr( "Consulta de Assuntos." ) );
    pesquisasAutoresAction->setText( tr( "Au&tores" ) );
    pesquisasAutoresAction->setMenuText( tr( "Au&tores" ) );
    pesquisasAutoresAction->setToolTip( tr( "Consulta de Autores." ) );
    pesquisasEditorasAction->setText( tr( "&Editoras" ) );
    pesquisasEditorasAction->setMenuText( tr( "&Editoras" ) );
    pesquisasEditorasAction->setToolTip( tr( "Consulta de Editoras." ) );
    pesquisasEnderecosAction->setText( trUtf8( "\x45\x26\x6e\x64\x65\x72\x65\xc3\xa7\x6f\x73" ) );
    pesquisasEnderecosAction->setMenuText( trUtf8( "\x45\x26\x6e\x64\x65\x72\x65\xc3\xa7\x6f\x73" ) );
    pesquisasEnderecosAction->setToolTip( trUtf8( "\x43\x6f\x6e\x73\x75\x6c\x74\x61\x20\x64\x65\x20\x45\x6e\x64\x65\x72\x65\xc3\xa7\x6f\x73\x2e" ) );
    pesquisasIdiomasAction->setText( tr( "&Idiomas" ) );
    pesquisasIdiomasAction->setMenuText( tr( "&Idiomas" ) );
    pesquisasIdiomasAction->setToolTip( tr( "Consulta de Idiomas." ) );
    pesquisasPaisesAction->setText( trUtf8( "\x26\x50\x61\xc3\xad\x73\x65\x73" ) );
    pesquisasPaisesAction->setMenuText( trUtf8( "\x26\x50\x61\xc3\xad\x73\x65\x73" ) );
    pesquisasPaisesAction->setToolTip( trUtf8( "\x43\x6f\x6e\x73\x75\x6c\x74\x61\x20\x64\x65\x20\x50\x61\xc3\xad\x73\x65\x73\x2e" ) );
    pesquisasProfissoesAction->setText( trUtf8( "\x50\x26\x72\x6f\x66\x69\x73\x73\xc3\xb5\x65\x73" ) );
    pesquisasProfissoesAction->setMenuText( trUtf8( "\x50\x26\x72\x6f\x66\x69\x73\x73\xc3\xb5\x65\x73" ) );
    pesquisasProfissoesAction->setToolTip( trUtf8( "\x43\x6f\x6e\x73\x75\x6c\x74\x61\x20\x64\x65\x20\x50\x72\x6f\x66\x69\x73\x73\xc3\xb5\x65\x73\x2e" ) );
    pesquisasClientesAction->setText( tr( "&Clientes" ) );
    pesquisasClientesAction->setMenuText( tr( "&Clientes" ) );
    pesquisasClientesAction->setToolTip( tr( "Consulta de Clientes." ) );
    pesquisasLivrosAction->setText( tr( "&Livros" ) );
    pesquisasLivrosAction->setMenuText( tr( "&Livros" ) );
    pesquisasLivrosAction->setToolTip( tr( "Consulta de Livros." ) );
    vendasVenderLivrosAction->setText( tr( "&Vender Livros" ) );
    vendasVenderLivrosAction->setMenuText( tr( "&Vender Livros" ) );
    vendasVenderLivrosAction->setToolTip( tr( "Vender Livros." ) );
    vendasVendas_RealizadasAction->setText( tr( "Vendas &Realizadas" ) );
    vendasVendas_RealizadasAction->setMenuText( tr( "Vendas &Realizadas" ) );
    vendasVendas_RealizadasAction->setToolTip( tr( "Vendas Realizadas." ) );
    janelasLadoaladohorizontalAction->setText( tr( "Lado a lado &horizontal" ) );
    janelasLadoaladohorizontalAction->setMenuText( tr( "Lado a lado &horizontal" ) );
    janelasLadoaladohorizontalAction->setToolTip( tr( "Lado a lado horizontal." ) );
    janelasLadoaladoverticalAction->setText( tr( "Lado a lado &vertical" ) );
    janelasLadoaladoverticalAction->setMenuText( tr( "Lado a lado &vertical" ) );
    janelasLadoaladoverticalAction->setToolTip( tr( "Lado a lado vertical." ) );
    janelasEmcascataAction->setText( tr( "Em &cascata" ) );
    janelasEmcascataAction->setMenuText( tr( "Em &cascata" ) );
    janelasEmcascataAction->setToolTip( tr( "Em cascata." ) );
    opcoesAlterarSenhaAction->setText( tr( "&Alterar Senha" ) );
    opcoesAlterarSenhaAction->setMenuText( tr( "&Alterar Senha" ) );
    opcoesAlterarSenhaAction->setToolTip( trUtf8( "\x41\x6c\x74\x65\x72\x61\xc3\xa7\xc3\xa3\x6f\x20\x64\x65\x20\x53\x65\x6e\x68\x61\x2e" ) );
    opcoesSobreAction->setText( tr( "&Sobre" ) );
    opcoesSobreAction->setMenuText( tr( "&Sobre" ) );
    opcoesSobreAction->setToolTip( tr( "Sobre o Sistema." ) );
    opcoesSairAction->setText( tr( "Sa&ir" ) );
    opcoesSairAction->setMenuText( tr( "Sa&ir" ) );
    opcoesSairAction->setToolTip( tr( "Sair do sistema." ) );
    janelasOrganizarIconesAction->setText( trUtf8( "\x26\x4f\x72\x67\x61\x6e\x69\x7a\x61\x72\x20\xc3\xad\x63\x6f\x6e\x65\x73" ) );
    janelasOrganizarIconesAction->setMenuText( trUtf8( "\x26\x4f\x72\x67\x61\x6e\x69\x7a\x61\x72\x20\xc3\xad\x63\x6f\x6e\x65\x73" ) );
    janelasOrganizarIconesAction->setToolTip( trUtf8( "\x4f\x72\x67\x61\x6e\x69\x7a\x61\x72\x20\xc3\xad\x63\x6f\x6e\x65\x73\x2e" ) );
    toolBar->setLabel( tr( "Tools" ) );
    tbClientes->setText( QString::null );
    tbLivros->setText( QString::null );
    tbVender->setText( QString::null );
    tbSobre->setText( QString::null );
    tbSair->setText( QString::null );
    if (MenuBar->findItem(1))
        MenuBar->findItem(1)->setText( tr( "&Cadastros" ) );
    if (MenuBar->findItem(2))
        MenuBar->findItem(2)->setText( tr( "&Pesquisas" ) );
    if (MenuBar->findItem(3))
        MenuBar->findItem(3)->setText( tr( "&Vendas" ) );
    if (MenuBar->findItem(4))
        MenuBar->findItem(4)->setText( tr( "&Janelas" ) );
    if (MenuBar->findItem(5))
        MenuBar->findItem(5)->setText( trUtf8( "\x26\x4f\x70\xc3\xa7\xc3\xb5\x65\x73" ) );
}

