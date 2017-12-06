/****************************************************************************
** Form implementation generated from reading ui file 'VenderLivros.ui'
**
** Created: sáb 20. nov 20:10:05 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "VenderLivros.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistbox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "VenderLivros.ui.h"
/*
 *  Constructs a frmVenderLivros as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
frmVenderLivros::frmVenderLivros( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "frmVenderLivros" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );

    labDtHrVenda = new QLabel( this, "labDtHrVenda" );
    labDtHrVenda->setGeometry( QRect( 10, 8, 100, 20 ) );

    edtCliente = new QLineEdit( this, "edtCliente" );
    edtCliente->setEnabled( FALSE );
    edtCliente->setGeometry( QRect( 137, 78, 313, 20 ) );
    edtCliente->setMaxLength( 30 );

    labCliente = new QLabel( this, "labCliente" );
    labCliente->setGeometry( QRect( 137, 55, 80, 20 ) );

    edtPrecoTotal = new QLineEdit( this, "edtPrecoTotal" );
    edtPrecoTotal->setEnabled( FALSE );
    edtPrecoTotal->setGeometry( QRect( 355, 281, 121, 20 ) );
    edtPrecoTotal->setMaxLength( 10 );

    labCPF = new QLabel( this, "labCPF" );
    labCPF->setGeometry( QRect( 10, 55, 50, 20 ) );

    labLivro = new QLabel( this, "labLivro" );
    labLivro->setGeometry( QRect( 137, 105, 80, 20 ) );

    labPrecoTotal = new QLabel( this, "labPrecoTotal" );
    labPrecoTotal->setGeometry( QRect( 295, 281, 54, 20 ) );

    labISBN = new QLabel( this, "labISBN" );
    labISBN->setGeometry( QRect( 10, 105, 50, 20 ) );

    edtLivro = new QLineEdit( this, "edtLivro" );
    edtLivro->setEnabled( FALSE );
    edtLivro->setGeometry( QRect( 137, 128, 289, 20 ) );
    edtLivro->setMaxLength( 30 );

    labCodAssunto_2_2 = new QLabel( this, "labCodAssunto_2_2" );
    labCodAssunto_2_2->setGeometry( QRect( 10, 155, 120, 20 ) );

    edtDtHrVenda = new QLineEdit( this, "edtDtHrVenda" );
    edtDtHrVenda->setEnabled( FALSE );
    edtDtHrVenda->setGeometry( QRect( 10, 30, 121, 20 ) );
    edtDtHrVenda->setMaxLength( 14 );

    edtCPF = new QLineEdit( this, "edtCPF" );
    edtCPF->setEnabled( TRUE );
    edtCPF->setGeometry( QRect( 10, 78, 121, 20 ) );
    edtCPF->setMaxLength( 14 );

    btnPCliente = new QPushButton( this, "btnPCliente" );
    btnPCliente->setEnabled( TRUE );
    btnPCliente->setGeometry( QRect( 455, 78, 21, 21 ) );

    edtISBN = new QLineEdit( this, "edtISBN" );
    edtISBN->setEnabled( TRUE );
    edtISBN->setGeometry( QRect( 10, 128, 121, 20 ) );
    edtISBN->setMaxLength( 13 );

    btnAdLivros = new QPushButton( this, "btnAdLivros" );
    btnAdLivros->setEnabled( TRUE );
    btnAdLivros->setGeometry( QRect( 430, 128, 21, 21 ) );

    btnPLivro = new QPushButton( this, "btnPLivro" );
    btnPLivro->setEnabled( TRUE );
    btnPLivro->setGeometry( QRect( 455, 128, 21, 21 ) );

    lstLivros = new QListBox( this, "lstLivros" );
    lstLivros->setEnabled( FALSE );
    lstLivros->setGeometry( QRect( 10, 178, 465, 97 ) );

    btnVender = new QPushButton( this, "btnVender" );
    btnVender->setEnabled( TRUE );
    btnVender->setGeometry( QRect( 241, 315, 75, 25 ) );

    btnLimpar = new QPushButton( this, "btnLimpar" );
    btnLimpar->setGeometry( QRect( 321, 315, 75, 25 ) );

    btnFechar = new QPushButton( this, "btnFechar" );
    btnFechar->setGeometry( QRect( 401, 315, 75, 25 ) );
    languageChange();
    resize( QSize(483, 348).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( this, SIGNAL( destroyed(QObject*) ), this, SLOT( frmVenderLivros_destroyed(QObject*) ) );
    connect( edtCPF, SIGNAL( lostFocus() ), this, SLOT( edtCPF_lostFocus() ) );
    connect( btnPCliente, SIGNAL( clicked() ), this, SLOT( btnPCliente_clicked() ) );
    connect( edtISBN, SIGNAL( lostFocus() ), this, SLOT( edtISBN_lostFocus() ) );
    connect( btnAdLivros, SIGNAL( clicked() ), this, SLOT( btnAdLivros_clicked() ) );
    connect( btnPLivro, SIGNAL( clicked() ), this, SLOT( btnPLivro_clicked() ) );
    connect( lstLivros, SIGNAL( doubleClicked(QListBoxItem*) ), this, SLOT( lstLivros_doubleClicked(QListBoxItem*) ) );
    connect( btnVender, SIGNAL( clicked() ), this, SLOT( btnVender_clicked() ) );
    connect( btnLimpar, SIGNAL( clicked() ), this, SLOT( btnLimpar_clicked() ) );
    connect( btnFechar, SIGNAL( clicked() ), this, SLOT( btnFechar_clicked() ) );

    // tab order
    setTabOrder( edtDtHrVenda, edtCPF );
    setTabOrder( edtCPF, edtCliente );
    setTabOrder( edtCliente, btnPCliente );
    setTabOrder( btnPCliente, edtISBN );
    setTabOrder( edtISBN, edtLivro );
    setTabOrder( edtLivro, btnAdLivros );
    setTabOrder( btnAdLivros, btnPLivro );
    setTabOrder( btnPLivro, lstLivros );
    setTabOrder( lstLivros, edtPrecoTotal );
    setTabOrder( edtPrecoTotal, btnVender );
    setTabOrder( btnVender, btnLimpar );
    setTabOrder( btnLimpar, btnFechar );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmVenderLivros::~frmVenderLivros()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmVenderLivros::languageChange()
{
    setCaption( tr( "Vender Livros" ) );
    labDtHrVenda->setText( tr( "Data/Hora Venda:" ) );
    labCliente->setText( tr( "Cliente:" ) );
    edtPrecoTotal->setText( tr( "R$ 0,00" ) );
    labCPF->setText( tr( "CPF:" ) );
    labLivro->setText( tr( "Livro:" ) );
    labPrecoTotal->setText( trUtf8( "\x50\x72\x65\xc3\xa7\x6f\x20\x74\x6f\x74\x61\x6c\x3a" ) );
    labISBN->setText( tr( "ISBN:" ) );
    labCodAssunto_2_2->setText( tr( "Livros para vender" ) );
    btnPCliente->setText( tr( "..." ) );
    btnAdLivros->setText( tr( "+" ) );
    btnPLivro->setText( tr( "..." ) );
    btnVender->setText( tr( "&Vender" ) );
    btnVender->setAccel( QKeySequence( tr( "Alt+V" ) ) );
    btnLimpar->setText( tr( "&Limpar" ) );
    btnLimpar->setAccel( QKeySequence( tr( "Alt+L" ) ) );
    btnFechar->setText( tr( "&Fechar" ) );
    btnFechar->setAccel( QKeySequence( tr( "Alt+F" ) ) );
}

