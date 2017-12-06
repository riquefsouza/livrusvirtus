/****************************************************************************
** Form implementation generated from reading ui file 'ConVendas.ui'
**
** Created: sáb 20. nov 20:10:04 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "ConVendas.h"

#include <qvariant.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qtable.h>
#include <qdatetimeedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "ConVendas.ui.h"
/*
 *  Constructs a frmConVendas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
frmConVendas::frmConVendas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "frmConVendas" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );

    edtPrecoTotal = new QLineEdit( this, "edtPrecoTotal" );
    edtPrecoTotal->setEnabled( FALSE );
    edtPrecoTotal->setGeometry( QRect( 355, 282, 121, 20 ) );
    edtPrecoTotal->setMaxLength( 10 );

    labDtHrVenda = new QLabel( this, "labDtHrVenda" );
    labDtHrVenda->setGeometry( QRect( 10, 9, 100, 20 ) );

    labPrecoTotal = new QLabel( this, "labPrecoTotal" );
    labPrecoTotal->setGeometry( QRect( 295, 282, 54, 20 ) );

    labCPF = new QLabel( this, "labCPF" );
    labCPF->setGeometry( QRect( 10, 56, 50, 20 ) );

    labISBN = new QLabel( this, "labISBN" );
    labISBN->setGeometry( QRect( 10, 106, 50, 20 ) );

    labLivro = new QLabel( this, "labLivro" );
    labLivro->setGeometry( QRect( 137, 106, 80, 20 ) );

    labCliente = new QLabel( this, "labCliente" );
    labCliente->setGeometry( QRect( 137, 56, 80, 20 ) );

    edtCliente = new QLineEdit( this, "edtCliente" );
    edtCliente->setEnabled( FALSE );
    edtCliente->setGeometry( QRect( 137, 79, 313, 20 ) );
    edtCliente->setMaxLength( 30 );

    edtLivro = new QLineEdit( this, "edtLivro" );
    edtLivro->setEnabled( FALSE );
    edtLivro->setGeometry( QRect( 137, 129, 313, 20 ) );
    edtLivro->setMaxLength( 30 );

    labRegistros = new QLabel( this, "labRegistros" );
    labRegistros->setGeometry( QRect( 10, 321, 120, 20 ) );

    table5 = new QTable( this, "table5" );
    table5->setNumCols( table5->numCols() + 1 );
    table5->horizontalHeader()->setLabel( table5->numCols() - 1, tr( "DataVenda" ) );
    table5->setNumCols( table5->numCols() + 1 );
    table5->horizontalHeader()->setLabel( table5->numCols() - 1, tr( "CPF" ) );
    table5->setNumCols( table5->numCols() + 1 );
    table5->horizontalHeader()->setLabel( table5->numCols() - 1, tr( "Cliente" ) );
    table5->setNumCols( table5->numCols() + 1 );
    table5->horizontalHeader()->setLabel( table5->numCols() - 1, tr( "ISBN" ) );
    table5->setNumCols( table5->numCols() + 1 );
    table5->horizontalHeader()->setLabel( table5->numCols() - 1, tr( "Livro" ) );
    table5->setNumCols( table5->numCols() + 1 );
    table5->horizontalHeader()->setLabel( table5->numCols() - 1, trUtf8( "\x50\x72\x65\xc3\xa7\x6f" ) );
    table5->setNumRows( table5->numRows() + 1 );
    table5->verticalHeader()->setLabel( table5->numRows() - 1, tr( "1" ) );
    table5->setGeometry( QRect( 10, 160, 470, 115 ) );
    table5->setNumRows( 1 );
    table5->setNumCols( 6 );

    edtDtHrVenda = new QDateTimeEdit( this, "edtDtHrVenda" );
    edtDtHrVenda->setGeometry( QRect( 10, 30, 160, 20 ) );

    btnPesquisar = new QPushButton( this, "btnPesquisar" );
    btnPesquisar->setEnabled( TRUE );
    btnPesquisar->setGeometry( QRect( 180, 30, 75, 25 ) );

    edtCPF = new QLineEdit( this, "edtCPF" );
    edtCPF->setEnabled( TRUE );
    edtCPF->setGeometry( QRect( 10, 79, 121, 20 ) );
    edtCPF->setMaxLength( 14 );

    btnPCliente = new QPushButton( this, "btnPCliente" );
    btnPCliente->setEnabled( TRUE );
    btnPCliente->setGeometry( QRect( 455, 79, 21, 21 ) );

    edtISBN = new QLineEdit( this, "edtISBN" );
    edtISBN->setEnabled( TRUE );
    edtISBN->setGeometry( QRect( 10, 129, 121, 20 ) );
    edtISBN->setMaxLength( 13 );

    btnPLivro = new QPushButton( this, "btnPLivro" );
    btnPLivro->setEnabled( TRUE );
    btnPLivro->setGeometry( QRect( 455, 129, 21, 21 ) );

    btnLimpar = new QPushButton( this, "btnLimpar" );
    btnLimpar->setGeometry( QRect( 321, 316, 75, 25 ) );

    btnFechar = new QPushButton( this, "btnFechar" );
    btnFechar->setGeometry( QRect( 401, 316, 75, 25 ) );
    languageChange();
    resize( QSize(486, 351).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( this, SIGNAL( destroyed(QObject*) ), this, SLOT( frmConVendas_destroyed(QObject*) ) );
    connect( edtCPF, SIGNAL( lostFocus() ), this, SLOT( edtCPF_lostFocus() ) );
    connect( btnPCliente, SIGNAL( clicked() ), this, SLOT( btnPCliente_clicked() ) );
    connect( edtISBN, SIGNAL( lostFocus() ), this, SLOT( edtISBN_lostFocus() ) );
    connect( btnPLivro, SIGNAL( clicked() ), this, SLOT( btnPLivro_clicked() ) );
    connect( btnLimpar, SIGNAL( clicked() ), this, SLOT( btnLimpar_clicked() ) );
    connect( btnFechar, SIGNAL( clicked() ), this, SLOT( btnFechar_clicked() ) );

    // tab order
    setTabOrder( edtDtHrVenda, btnPesquisar );
    setTabOrder( btnPesquisar, edtCPF );
    setTabOrder( edtCPF, edtCliente );
    setTabOrder( edtCliente, btnPCliente );
    setTabOrder( btnPCliente, edtISBN );
    setTabOrder( edtISBN, edtLivro );
    setTabOrder( edtLivro, btnPLivro );
    setTabOrder( btnPLivro, table5 );
    setTabOrder( table5, edtPrecoTotal );
    setTabOrder( edtPrecoTotal, btnLimpar );
    setTabOrder( btnLimpar, btnFechar );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmConVendas::~frmConVendas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmConVendas::languageChange()
{
    setCaption( tr( "Consulta de Vendas Realizadas" ) );
    edtPrecoTotal->setText( tr( "R$ 0,00" ) );
    labDtHrVenda->setText( tr( "Data/Hora Venda:" ) );
    labPrecoTotal->setText( trUtf8( "\x50\x72\x65\xc3\xa7\x6f\x20\x74\x6f\x74\x61\x6c\x3a" ) );
    labCPF->setText( tr( "CPF:" ) );
    labISBN->setText( tr( "ISBN:" ) );
    labLivro->setText( tr( "Livro:" ) );
    labCliente->setText( tr( "Cliente:" ) );
    labRegistros->setText( tr( "Registro 0 de 0" ) );
    table5->horizontalHeader()->setLabel( 0, tr( "DataVenda" ) );
    table5->horizontalHeader()->setLabel( 1, tr( "CPF" ) );
    table5->horizontalHeader()->setLabel( 2, tr( "Cliente" ) );
    table5->horizontalHeader()->setLabel( 3, tr( "ISBN" ) );
    table5->horizontalHeader()->setLabel( 4, tr( "Livro" ) );
    table5->horizontalHeader()->setLabel( 5, trUtf8( "\x50\x72\x65\xc3\xa7\x6f" ) );
    table5->verticalHeader()->setLabel( 0, tr( "1" ) );
    btnPesquisar->setText( tr( "&Pesquisar" ) );
    btnPesquisar->setAccel( QKeySequence( tr( "Alt+P" ) ) );
    btnPCliente->setText( tr( "..." ) );
    btnPLivro->setText( tr( "..." ) );
    btnLimpar->setText( tr( "&Limpar" ) );
    btnLimpar->setAccel( QKeySequence( tr( "Alt+L" ) ) );
    btnFechar->setText( tr( "&Fechar" ) );
    btnFechar->setAccel( QKeySequence( tr( "Alt+F" ) ) );
}

