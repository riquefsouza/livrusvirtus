/****************************************************************************
** Form implementation generated from reading ui file 'CadLivros.ui'
**
** Created: sáb 20. nov 20:10:03 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CadLivros.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qspinbox.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qlistbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "CadLivros.ui.h"
/*
 *  Constructs a frmCadLivros as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
frmCadLivros::frmCadLivros( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "frmCadLivros" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );

    labISBN = new QLabel( this, "labISBN" );
    labISBN->setGeometry( QRect( 9, 9, 55, 20 ) );

    labTitulo = new QLabel( this, "labTitulo" );
    labTitulo->setGeometry( QRect( 10, 53, 60, 20 ) );

    edtTitulo = new QLineEdit( this, "edtTitulo" );
    edtTitulo->setEnabled( FALSE );
    edtTitulo->setGeometry( QRect( 9, 76, 313, 20 ) );
    edtTitulo->setMaxLength( 50 );

    labEdicao = new QLabel( this, "labEdicao" );
    labEdicao->setGeometry( QRect( 329, 53, 60, 20 ) );

    edtEdicao = new QSpinBox( this, "edtEdicao" );
    edtEdicao->setEnabled( FALSE );
    edtEdicao->setGeometry( QRect( 329, 76, 89, 20 ) );
    edtEdicao->setMaxValue( 99999999 );
    edtEdicao->setMinValue( 1 );

    edtEditora = new QLineEdit( this, "edtEditora" );
    edtEditora->setEnabled( FALSE );
    edtEditora->setGeometry( QRect( 180, 123, 212, 20 ) );
    edtEditora->setMaxLength( 30 );

    labAnoPubli = new QLabel( this, "labAnoPubli" );
    labAnoPubli->setGeometry( QRect( 10, 100, 80, 20 ) );

    labVolume = new QLabel( this, "labVolume" );
    labVolume->setGeometry( QRect( 10, 146, 80, 20 ) );

    labIdioma = new QLabel( this, "labIdioma" );
    labIdioma->setGeometry( QRect( 103, 150, 80, 20 ) );

    edtVolume = new QSpinBox( this, "edtVolume" );
    edtVolume->setEnabled( FALSE );
    edtVolume->setGeometry( QRect( 10, 169, 89, 20 ) );
    edtVolume->setMaxValue( 99999999 );
    edtVolume->setMinValue( 1 );

    cmbIdioma = new QComboBox( FALSE, this, "cmbIdioma" );
    cmbIdioma->setEnabled( FALSE );
    cmbIdioma->setGeometry( QRect( 103, 169, 316, 20 ) );

    labCodEditora = new QLabel( this, "labCodEditora" );
    labCodEditora->setGeometry( QRect( 103, 100, 80, 20 ) );

    labPreco = new QLabel( this, "labPreco" );
    labPreco->setGeometry( QRect( 10, 239, 80, 20 ) );

    labNPaginas = new QLabel( this, "labNPaginas" );
    labNPaginas->setGeometry( QRect( 10, 194, 80, 20 ) );

    edtNPaginas = new QSpinBox( this, "edtNPaginas" );
    edtNPaginas->setEnabled( FALSE );
    edtNPaginas->setGeometry( QRect( 10, 217, 89, 20 ) );
    edtNPaginas->setMaxValue( 99999999 );
    edtNPaginas->setMinValue( 1 );

    labCodAssunto = new QLabel( this, "labCodAssunto" );
    labCodAssunto->setGeometry( QRect( 103, 194, 80, 20 ) );

    edtAssunto = new QLineEdit( this, "edtAssunto" );
    edtAssunto->setEnabled( FALSE );
    edtAssunto->setGeometry( QRect( 180, 217, 188, 20 ) );
    edtAssunto->setMaxLength( 30 );

    labQtdEstoque = new QLabel( this, "labQtdEstoque" );
    labQtdEstoque->setGeometry( QRect( 10, 287, 80, 20 ) );

    labCodAutor = new QLabel( this, "labCodAutor" );
    labCodAutor->setGeometry( QRect( 103, 287, 80, 20 ) );

    edtAutor = new QLineEdit( this, "edtAutor" );
    edtAutor->setEnabled( FALSE );
    edtAutor->setGeometry( QRect( 180, 310, 188, 20 ) );
    edtAutor->setMaxLength( 30 );

    edtQtdEstoque = new QSpinBox( this, "edtQtdEstoque" );
    edtQtdEstoque->setEnabled( FALSE );
    edtQtdEstoque->setGeometry( QRect( 10, 310, 89, 20 ) );
    edtQtdEstoque->setMaxValue( 99999999 );
    edtQtdEstoque->setMinValue( 0 );

    edtAnoPubli = new QSpinBox( this, "edtAnoPubli" );
    edtAnoPubli->setEnabled( FALSE );
    edtAnoPubli->setGeometry( QRect( 10, 123, 89, 20 ) );
    edtAnoPubli->setMaxValue( 9999 );
    edtAnoPubli->setMinValue( 1 );

    edtISBN = new QLineEdit( this, "edtISBN" );
    edtISBN->setGeometry( QRect( 9, 29, 121, 20 ) );
    edtISBN->setMaxLength( 13 );

    btnNovo = new QPushButton( this, "btnNovo" );
    btnNovo->setGeometry( QRect( 141, 26, 75, 25 ) );

    edtCodEditora = new QLineEdit( this, "edtCodEditora" );
    edtCodEditora->setEnabled( FALSE );
    edtCodEditora->setGeometry( QRect( 103, 123, 73, 20 ) );
    edtCodEditora->setMaxLength( 10 );

    btnPEditora = new QPushButton( this, "btnPEditora" );
    btnPEditora->setEnabled( FALSE );
    btnPEditora->setGeometry( QRect( 397, 123, 21, 21 ) );

    edtCodAssunto = new QLineEdit( this, "edtCodAssunto" );
    edtCodAssunto->setEnabled( FALSE );
    edtCodAssunto->setGeometry( QRect( 103, 217, 73, 20 ) );
    edtCodAssunto->setMaxLength( 10 );

    btnAdAssuntos = new QPushButton( this, "btnAdAssuntos" );
    btnAdAssuntos->setEnabled( FALSE );
    btnAdAssuntos->setGeometry( QRect( 372, 217, 21, 21 ) );

    btnPAssunto = new QPushButton( this, "btnPAssunto" );
    btnPAssunto->setEnabled( FALSE );
    btnPAssunto->setGeometry( QRect( 397, 217, 21, 21 ) );

    edtPreco = new QLineEdit( this, "edtPreco" );
    edtPreco->setEnabled( FALSE );
    edtPreco->setGeometry( QRect( 10, 262, 89, 20 ) );
    edtPreco->setMaxLength( 5 );

    lstAssuntos = new QListBox( this, "lstAssuntos" );
    lstAssuntos->setEnabled( FALSE );
    lstAssuntos->setGeometry( QRect( 103, 240, 315, 42 ) );

    edtCodAutor = new QLineEdit( this, "edtCodAutor" );
    edtCodAutor->setEnabled( FALSE );
    edtCodAutor->setGeometry( QRect( 103, 310, 73, 20 ) );
    edtCodAutor->setMaxLength( 10 );

    btnAdAutores = new QPushButton( this, "btnAdAutores" );
    btnAdAutores->setEnabled( FALSE );
    btnAdAutores->setGeometry( QRect( 372, 310, 21, 21 ) );

    btnPAutor = new QPushButton( this, "btnPAutor" );
    btnPAutor->setEnabled( FALSE );
    btnPAutor->setGeometry( QRect( 397, 310, 21, 21 ) );

    lstAutores = new QListBox( this, "lstAutores" );
    lstAutores->setEnabled( FALSE );
    lstAutores->setGeometry( QRect( 103, 333, 315, 42 ) );

    btnPesquisar = new QPushButton( this, "btnPesquisar" );
    btnPesquisar->setGeometry( QRect( 426, 19, 75, 25 ) );

    btnAnterior = new QPushButton( this, "btnAnterior" );
    btnAnterior->setEnabled( FALSE );
    btnAnterior->setGeometry( QRect( 426, 51, 75, 25 ) );

    btnProximo = new QPushButton( this, "btnProximo" );
    btnProximo->setEnabled( FALSE );
    btnProximo->setGeometry( QRect( 426, 83, 75, 25 ) );

    btnSalvar = new QPushButton( this, "btnSalvar" );
    btnSalvar->setEnabled( FALSE );
    btnSalvar->setGeometry( QRect( 186, 387, 75, 25 ) );

    btnExcluir = new QPushButton( this, "btnExcluir" );
    btnExcluir->setEnabled( FALSE );
    btnExcluir->setGeometry( QRect( 266, 387, 75, 25 ) );

    btnLimpar = new QPushButton( this, "btnLimpar" );
    btnLimpar->setGeometry( QRect( 346, 387, 75, 25 ) );

    btnFechar = new QPushButton( this, "btnFechar" );
    btnFechar->setGeometry( QRect( 426, 387, 75, 25 ) );
    languageChange();
    resize( QSize(510, 420).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( edtISBN, SIGNAL( lostFocus() ), this, SLOT( edtISBN_lostFocus() ) );
    connect( btnNovo, SIGNAL( clicked() ), this, SLOT( btnNovo_clicked() ) );
    connect( edtCodEditora, SIGNAL( lostFocus() ), this, SLOT( edtCodEditora_lostFocus() ) );
    connect( btnPEditora, SIGNAL( clicked() ), this, SLOT( btnPEditora_clicked() ) );
    connect( this, SIGNAL( destroyed(QObject*) ), this, SLOT( frmCadLivros_destroyed(QObject*) ) );
    connect( edtCodAssunto, SIGNAL( lostFocus() ), this, SLOT( edtCodAssunto_lostFocus() ) );
    connect( btnAdAssuntos, SIGNAL( clicked() ), this, SLOT( btnAdAssuntos_clicked() ) );
    connect( btnPAssunto, SIGNAL( clicked() ), this, SLOT( btnPAssunto_clicked() ) );
    connect( edtPreco, SIGNAL( lostFocus() ), this, SLOT( edtPreco_lostFocus() ) );
    connect( lstAssuntos, SIGNAL( doubleClicked(QListBoxItem*) ), this, SLOT( lstAssuntos_doubleClicked(QListBoxItem*) ) );
    connect( edtCodAutor, SIGNAL( lostFocus() ), this, SLOT( edtCodAutor_lostFocus() ) );
    connect( btnAdAutores, SIGNAL( clicked() ), this, SLOT( btnAdAutores_clicked() ) );
    connect( btnPAutor, SIGNAL( clicked() ), this, SLOT( btnPAutor_clicked() ) );
    connect( lstAutores, SIGNAL( doubleClicked(QListBoxItem*) ), this, SLOT( lstAutores_doubleClicked(QListBoxItem*) ) );
    connect( btnPesquisar, SIGNAL( clicked() ), this, SLOT( btnPesquisar_clicked() ) );
    connect( btnAnterior, SIGNAL( clicked() ), this, SLOT( btnAnterior_clicked() ) );
    connect( btnProximo, SIGNAL( clicked() ), this, SLOT( btnProximo_clicked() ) );
    connect( btnSalvar, SIGNAL( clicked() ), this, SLOT( btnSalvar_clicked() ) );
    connect( btnExcluir, SIGNAL( clicked() ), this, SLOT( btnExcluir_clicked() ) );
    connect( btnLimpar, SIGNAL( clicked() ), this, SLOT( btnLimpar_clicked() ) );
    connect( btnFechar, SIGNAL( clicked() ), this, SLOT( btnFechar_clicked() ) );

    // tab order
    setTabOrder( edtISBN, btnNovo );
    setTabOrder( btnNovo, edtTitulo );
    setTabOrder( edtTitulo, edtEdicao );
    setTabOrder( edtEdicao, edtAnoPubli );
    setTabOrder( edtAnoPubli, edtCodEditora );
    setTabOrder( edtCodEditora, edtEditora );
    setTabOrder( edtEditora, btnPEditora );
    setTabOrder( btnPEditora, edtVolume );
    setTabOrder( edtVolume, cmbIdioma );
    setTabOrder( cmbIdioma, edtNPaginas );
    setTabOrder( edtNPaginas, edtCodAssunto );
    setTabOrder( edtCodAssunto, edtAssunto );
    setTabOrder( edtAssunto, btnAdAssuntos );
    setTabOrder( btnAdAssuntos, btnPAssunto );
    setTabOrder( btnPAssunto, edtPreco );
    setTabOrder( edtPreco, lstAssuntos );
    setTabOrder( lstAssuntos, edtQtdEstoque );
    setTabOrder( edtQtdEstoque, edtCodAutor );
    setTabOrder( edtCodAutor, edtAutor );
    setTabOrder( edtAutor, btnAdAutores );
    setTabOrder( btnAdAutores, btnPAutor );
    setTabOrder( btnPAutor, lstAutores );
    setTabOrder( lstAutores, btnPesquisar );
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
frmCadLivros::~frmCadLivros()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmCadLivros::languageChange()
{
    setCaption( tr( "Cadastro de Livros" ) );
    labISBN->setText( tr( "ISBN:" ) );
    labTitulo->setText( trUtf8( "\x54\xc3\xad\x74\x75\x6c\x6f\x3a" ) );
    labEdicao->setText( trUtf8( "\x45\x64\x69\xc3\xa7\xc3\xa3\x6f\x3a" ) );
    labAnoPubli->setText( trUtf8( "\x41\x6e\x6f\x20\x50\x75\x62\x6c\x69\x63\x61\xc3\xa7\xc3\xa3\x6f\x3a" ) );
    labVolume->setText( tr( "Volume:" ) );
    labIdioma->setText( tr( "Idioma:" ) );
    labCodEditora->setText( tr( "Editora:" ) );
    labPreco->setText( trUtf8( "\x50\x72\x65\xc3\xa7\x6f\x3a" ) );
    labNPaginas->setText( trUtf8( "\x4e\xc2\xba\x20\x50\x61\x67\x69\x6e\x61\x73\x3a" ) );
    labCodAssunto->setText( tr( "Assunto:" ) );
    labQtdEstoque->setText( tr( "Qtd. Estoque:" ) );
    labCodAutor->setText( tr( "Assunto:" ) );
    btnNovo->setText( tr( "&Novo" ) );
    btnNovo->setAccel( QKeySequence( tr( "Alt+N" ) ) );
    btnPEditora->setText( tr( "..." ) );
    btnAdAssuntos->setText( tr( "+" ) );
    btnPAssunto->setText( tr( "..." ) );
    edtPreco->setInputMask( tr( "#0,00; " ) );
    btnAdAutores->setText( tr( "+" ) );
    btnPAutor->setText( tr( "..." ) );
    btnPesquisar->setText( tr( "&Pesquisar" ) );
    btnPesquisar->setAccel( QKeySequence( tr( "Alt+P" ) ) );
    btnAnterior->setText( tr( "&Anterior" ) );
    btnAnterior->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    btnProximo->setText( trUtf8( "\x50\x72\xc3\xb3\x78\x69\x26\x6d\x6f" ) );
    btnProximo->setAccel( QKeySequence( tr( "Alt+M" ) ) );
    btnSalvar->setText( tr( "&Salvar" ) );
    btnSalvar->setAccel( QKeySequence( tr( "Alt+S" ) ) );
    btnExcluir->setText( tr( "&Excluir" ) );
    btnExcluir->setAccel( QKeySequence( tr( "Alt+E" ) ) );
    btnLimpar->setText( tr( "&Limpar" ) );
    btnLimpar->setAccel( QKeySequence( tr( "Alt+L" ) ) );
    btnFechar->setText( tr( "&Fechar" ) );
    btnFechar->setAccel( QKeySequence( tr( "Alt+F" ) ) );
}

