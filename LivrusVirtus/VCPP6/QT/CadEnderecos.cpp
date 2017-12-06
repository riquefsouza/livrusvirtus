/****************************************************************************
** Form implementation generated from reading ui file 'CadEnderecos.ui'
**
** Created: sáb 20. nov 20:10:03 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CadEnderecos.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "CadEnderecos.ui.h"
/*
 *  Constructs a frmCadEnderecos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
frmCadEnderecos::frmCadEnderecos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "frmCadEnderecos" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );

    labCodigo = new QLabel( this, "labCodigo" );
    labCodigo->setGeometry( QRect( 10, 5, 55, 20 ) );

    labEstado = new QLabel( this, "labEstado" );
    labEstado->setGeometry( QRect( 283, 95, 55, 20 ) );

    edtCodigo = new QLineEdit( this, "edtCodigo" );
    edtCodigo->setGeometry( QRect( 10, 25, 121, 20 ) );
    edtCodigo->setFrameShape( QLineEdit::LineEditPanel );
    edtCodigo->setFrameShadow( QLineEdit::Sunken );
    edtCodigo->setMaxLength( 10 );

    btnPesquisar = new QPushButton( this, "btnPesquisar" );
    btnPesquisar->setGeometry( QRect( 449, 10, 75, 25 ) );

    btnLimpar = new QPushButton( this, "btnLimpar" );
    btnLimpar->setGeometry( QRect( 369, 148, 75, 25 ) );

    btnFechar = new QPushButton( this, "btnFechar" );
    btnFechar->setGeometry( QRect( 449, 148, 75, 25 ) );

    btnNovo = new QPushButton( this, "btnNovo" );
    btnNovo->setGeometry( QRect( 152, 22, 75, 25 ) );

    btnAnterior = new QPushButton( this, "btnAnterior" );
    btnAnterior->setEnabled( FALSE );
    btnAnterior->setGeometry( QRect( 449, 42, 75, 25 ) );

    btnProximo = new QPushButton( this, "btnProximo" );
    btnProximo->setEnabled( FALSE );
    btnProximo->setGeometry( QRect( 449, 74, 75, 25 ) );

    btnExcluir = new QPushButton( this, "btnExcluir" );
    btnExcluir->setEnabled( FALSE );
    btnExcluir->setGeometry( QRect( 289, 148, 75, 25 ) );

    btnSalvar = new QPushButton( this, "btnSalvar" );
    btnSalvar->setEnabled( FALSE );
    btnSalvar->setGeometry( QRect( 209, 148, 75, 25 ) );

    edtLogradouro = new QLineEdit( this, "edtLogradouro" );
    edtLogradouro->setEnabled( FALSE );
    edtLogradouro->setGeometry( QRect( 10, 72, 265, 20 ) );
    edtLogradouro->setFrameShape( QLineEdit::LineEditPanel );
    edtLogradouro->setFrameShadow( QLineEdit::Sunken );
    edtLogradouro->setMaxLength( 50 );

    edtBairro = new QLineEdit( this, "edtBairro" );
    edtBairro->setEnabled( FALSE );
    edtBairro->setGeometry( QRect( 283, 72, 153, 20 ) );
    edtBairro->setMaxLength( 14 );

    labCEP = new QLabel( this, "labCEP" );
    labCEP->setGeometry( QRect( 10, 95, 55, 20 ) );

    edtCEP = new QLineEdit( this, "edtCEP" );
    edtCEP->setEnabled( FALSE );
    edtCEP->setGeometry( QRect( 10, 115, 65, 20 ) );

    edtCidade = new QLineEdit( this, "edtCidade" );
    edtCidade->setEnabled( FALSE );
    edtCidade->setGeometry( QRect( 82, 115, 193, 20 ) );
    edtCidade->setMaxLength( 30 );

    labCidade = new QLabel( this, "labCidade" );
    labCidade->setGeometry( QRect( 82, 95, 55, 20 ) );

    labLogradouro = new QLabel( this, "labLogradouro" );
    labLogradouro->setGeometry( QRect( 10, 51, 60, 20 ) );

    labBairro = new QLabel( this, "labBairro" );
    labBairro->setGeometry( QRect( 283, 51, 55, 20 ) );

    cmbEstado = new QComboBox( FALSE, this, "cmbEstado" );
    cmbEstado->setEnabled( FALSE );
    cmbEstado->setGeometry( QRect( 283, 115, 153, 20 ) );
    languageChange();
    resize( QSize(531, 180).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( edtCodigo, SIGNAL( lostFocus() ), this, SLOT( edtCodigo_lostFocus() ) );
    connect( btnNovo, SIGNAL( clicked() ), this, SLOT( btnNovo_clicked() ) );
    connect( btnPesquisar, SIGNAL( clicked() ), this, SLOT( btnPesquisar_clicked() ) );
    connect( btnAnterior, SIGNAL( clicked() ), this, SLOT( btnAnterior_clicked() ) );
    connect( btnProximo, SIGNAL( clicked() ), this, SLOT( btnProximo_clicked() ) );
    connect( btnSalvar, SIGNAL( clicked() ), this, SLOT( btnSalvar_clicked() ) );
    connect( btnExcluir, SIGNAL( clicked() ), this, SLOT( btnExcluir_clicked() ) );
    connect( btnLimpar, SIGNAL( clicked() ), this, SLOT( btnLimpar_clicked() ) );
    connect( btnFechar, SIGNAL( clicked() ), this, SLOT( btnFechar_clicked() ) );
    connect( this, SIGNAL( destroyed(QObject*) ), this, SLOT( frmCadEnderecos_destroyed(QObject*) ) );

    // tab order
    setTabOrder( edtCodigo, btnNovo );
    setTabOrder( btnNovo, edtLogradouro );
    setTabOrder( edtLogradouro, edtBairro );
    setTabOrder( edtBairro, edtCEP );
    setTabOrder( edtCEP, edtCidade );
    setTabOrder( edtCidade, cmbEstado );
    setTabOrder( cmbEstado, btnPesquisar );
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
frmCadEnderecos::~frmCadEnderecos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmCadEnderecos::languageChange()
{
    setCaption( trUtf8( "\x43\x61\x64\x61\x73\x74\x72\x6f\x20\x64\x65\x20\x45\x6e\x64\x65\x72\x65\xc3\xa7\x6f\x73" ) );
    labCodigo->setText( trUtf8( "\x43\xc3\xb3\x64\x69\x67\x6f\x3a" ) );
    labEstado->setText( tr( "Estado:" ) );
    btnPesquisar->setText( tr( "&Pesquisar" ) );
    btnPesquisar->setAccel( QKeySequence( tr( "Alt+P" ) ) );
    btnLimpar->setText( tr( "&Limpar" ) );
    btnLimpar->setAccel( QKeySequence( tr( "Alt+L" ) ) );
    btnFechar->setText( tr( "&Fechar" ) );
    btnFechar->setAccel( QKeySequence( tr( "Alt+F" ) ) );
    btnNovo->setText( tr( "&Novo" ) );
    btnNovo->setAccel( QKeySequence( tr( "Alt+N" ) ) );
    btnAnterior->setText( tr( "&Anterior" ) );
    btnAnterior->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    btnProximo->setText( trUtf8( "\x50\x72\xc3\xb3\x78\x69\x26\x6d\x6f" ) );
    btnProximo->setAccel( QKeySequence( tr( "Alt+M" ) ) );
    btnExcluir->setText( tr( "&Excluir" ) );
    btnExcluir->setAccel( QKeySequence( tr( "Alt+E" ) ) );
    btnSalvar->setText( tr( "&Salvar" ) );
    btnSalvar->setAccel( QKeySequence( tr( "Alt+S" ) ) );
    labCEP->setText( tr( "CEP:" ) );
    labCidade->setText( tr( "Cidade:" ) );
    labLogradouro->setText( tr( "Logradouro:" ) );
    labBairro->setText( tr( "Bairro:" ) );
    cmbEstado->clear();
    cmbEstado->insertItem( tr( "Pernambuco" ) );
    cmbEstado->insertItem( tr( "Acre" ) );
    cmbEstado->insertItem( tr( "Alagoas" ) );
    cmbEstado->insertItem( trUtf8( "\x41\x6d\x61\x70\xc3\xa1" ) );
    cmbEstado->insertItem( tr( "Amazonas" ) );
    cmbEstado->insertItem( tr( "Bahia" ) );
    cmbEstado->insertItem( trUtf8( "\x42\x72\x61\x73\xc3\xad\x6c\x69\x61" ) );
    cmbEstado->insertItem( trUtf8( "\x43\x65\x61\x72\xc3\xa1" ) );
    cmbEstado->insertItem( tr( "Distrito Federal" ) );
    cmbEstado->insertItem( trUtf8( "\x45\x73\x70\xc3\xad\x72\x69\x74\x6f\x20\x53\x61\x6e\x74\x6f" ) );
    cmbEstado->insertItem( trUtf8( "\x47\x6f\x69\xc3\xa1\x73" ) );
    cmbEstado->insertItem( tr( "Mato Grosso" ) );
    cmbEstado->insertItem( tr( "Mato Grosso do Sul" ) );
    cmbEstado->insertItem( tr( "Minas Gerais" ) );
    cmbEstado->insertItem( trUtf8( "\x50\x61\x72\xc3\xa1" ) );
    cmbEstado->insertItem( trUtf8( "\x50\x61\x72\x61\xc3\xad\x62\x61" ) );
    cmbEstado->insertItem( trUtf8( "\x50\x61\x72\x61\x6e\xc3\xa1" ) );
    cmbEstado->insertItem( tr( "Santa Catarina" ) );
    cmbEstado->insertItem( tr( "Rio Grande do Norte" ) );
    cmbEstado->insertItem( tr( "Rio Grande do Sul" ) );
    cmbEstado->insertItem( tr( "Rio de Janeiro" ) );
    cmbEstado->insertItem( trUtf8( "\x52\x6f\x6e\x64\xc3\xb4\x6e\x69\x61" ) );
    cmbEstado->insertItem( tr( "Roraima" ) );
    cmbEstado->insertItem( trUtf8( "\x53\xc3\xa3\x6f\x20\x50\x61\x75\x6c\x6f" ) );
    cmbEstado->insertItem( tr( "Sergipe" ) );
    cmbEstado->insertItem( tr( "Tocantins" ) );
}

