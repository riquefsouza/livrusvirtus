/****************************************************************************
** Form implementation generated from reading ui file 'Cadastros.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Cadastros.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "Cadastros.ui.h"
/*
 *  Constructs a frmCadastros as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
frmCadastros::frmCadastros( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "frmCadastros" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );

    labCodigo = new QLabel( this, "labCodigo" );
    labCodigo->setGeometry( QRect( 8, 3, 55, 20 ) );

    labDescricao = new QLabel( this, "labDescricao" );
    labDescricao->setGeometry( QRect( 8, 49, 60, 20 ) );

    btnNovo = new QPushButton( this, "btnNovo" );
    btnNovo->setGeometry( QRect( 150, 20, 75, 25 ) );

    btnPesquisar = new QPushButton( this, "btnPesquisar" );
    btnPesquisar->setGeometry( QRect( 250, 13, 75, 25 ) );

    btnLimpar = new QPushButton( this, "btnLimpar" );
    btnLimpar->setGeometry( QRect( 170, 110, 75, 25 ) );

    btnFechar = new QPushButton( this, "btnFechar" );
    btnFechar->setGeometry( QRect( 250, 110, 75, 25 ) );

    edtCodigo = new QLineEdit( this, "edtCodigo" );
    edtCodigo->setGeometry( QRect( 8, 23, 121, 20 ) );
    edtCodigo->setMaxLength( 10 );

    edtDescricao = new QLineEdit( this, "edtDescricao" );
    edtDescricao->setEnabled( FALSE );
    edtDescricao->setGeometry( QRect( 8, 70, 217, 20 ) );
    edtDescricao->setMaxLength( 50 );

    btnAnterior = new QPushButton( this, "btnAnterior" );
    btnAnterior->setEnabled( FALSE );
    btnAnterior->setGeometry( QRect( 250, 45, 75, 25 ) );

    btnProximo = new QPushButton( this, "btnProximo" );
    btnProximo->setEnabled( FALSE );
    btnProximo->setGeometry( QRect( 250, 77, 75, 25 ) );

    btnExcluir = new QPushButton( this, "btnExcluir" );
    btnExcluir->setEnabled( FALSE );
    btnExcluir->setGeometry( QRect( 90, 110, 75, 25 ) );

    btnSalvar = new QPushButton( this, "btnSalvar" );
    btnSalvar->setEnabled( FALSE );
    btnSalvar->setGeometry( QRect( 10, 110, 75, 25 ) );
    languageChange();
    resize( QSize(333, 144).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( btnNovo, SIGNAL( clicked() ), this, SLOT( btnNovo_clicked() ) );
    connect( btnPesquisar, SIGNAL( clicked() ), this, SLOT( btnPesquisar_clicked() ) );
    connect( btnAnterior, SIGNAL( clicked() ), this, SLOT( btnAnterior_clicked() ) );
    connect( btnProximo, SIGNAL( clicked() ), this, SLOT( btnProximo_clicked() ) );
    connect( btnSalvar, SIGNAL( clicked() ), this, SLOT( btnSalvar_clicked() ) );
    connect( btnExcluir, SIGNAL( clicked() ), this, SLOT( btnExcluir_clicked() ) );
    connect( btnLimpar, SIGNAL( clicked() ), this, SLOT( btnLimpar_clicked() ) );
    connect( btnFechar, SIGNAL( clicked() ), this, SLOT( btnFechar_clicked() ) );
    connect( edtCodigo, SIGNAL( lostFocus() ), this, SLOT( edtCodigo_lostFocus() ) );
    connect( this, SIGNAL( destroyed(QObject*) ), this, SLOT( frmCadastros_destroyed(QObject*) ) );

    // tab order
    setTabOrder( edtCodigo, btnNovo );
    setTabOrder( btnNovo, edtDescricao );
    setTabOrder( edtDescricao, btnPesquisar );
    setTabOrder( btnPesquisar, btnAnterior );
    setTabOrder( btnAnterior, btnProximo );
    setTabOrder( btnProximo, btnSalvar );
    setTabOrder( btnSalvar, btnExcluir );
    setTabOrder( btnExcluir, btnLimpar );
    setTabOrder( btnLimpar, btnFechar );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmCadastros::~frmCadastros()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmCadastros::languageChange()
{
    setCaption( tr( "Cadastro de " ) );
    labCodigo->setText( trUtf8( "\x43\xc3\xb3\x64\x69\x67\x6f\x3a" ) );
    labDescricao->setText( trUtf8( "\x44\x65\x73\x63\x72\x69\xc3\xa7\xc3\xa3\x6f\x3a" ) );
    btnNovo->setText( tr( "&Novo" ) );
    btnNovo->setAccel( QKeySequence( tr( "Alt+N" ) ) );
    btnPesquisar->setText( tr( "&Pesquisar" ) );
    btnPesquisar->setAccel( QKeySequence( tr( "Alt+P" ) ) );
    btnLimpar->setText( tr( "&Limpar" ) );
    btnLimpar->setAccel( QKeySequence( tr( "Alt+L" ) ) );
    btnFechar->setText( tr( "&Fechar" ) );
    btnFechar->setAccel( QKeySequence( tr( "Alt+F" ) ) );
    btnAnterior->setText( tr( "&Anterior" ) );
    btnAnterior->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    btnProximo->setText( trUtf8( "\x50\x72\xc3\xb3\x78\x69\x26\x6d\x6f" ) );
    btnProximo->setAccel( QKeySequence( tr( "Alt+M" ) ) );
    btnExcluir->setText( tr( "&Excluir" ) );
    btnExcluir->setAccel( QKeySequence( tr( "Alt+E" ) ) );
    btnSalvar->setText( tr( "&Salvar" ) );
    btnSalvar->setAccel( QKeySequence( tr( "Alt+S" ) ) );
}

