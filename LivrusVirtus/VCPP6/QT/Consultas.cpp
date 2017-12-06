/****************************************************************************
** Form implementation generated from reading ui file 'Consultas.ui'
**
** Created: sáb 20. nov 20:10:04 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Consultas.h"

#include <qvariant.h>
#include <qframe.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "Consultas.ui.h"
/*
 *  Constructs a frmConsultas as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
frmConsultas::frmConsultas( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "frmConsultas" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );

    QWidget* privateLayoutWidget = new QWidget( this, "layout1" );
    privateLayoutWidget->setGeometry( QRect( 0, 0, 392, 250 ) );
    layout1 = new QVBoxLayout( privateLayoutWidget, 11, 6, "layout1"); 

    frame1 = new QFrame( privateLayoutWidget, "frame1" );
    frame1->setMinimumSize( QSize( 390, 60 ) );
    frame1->setFrameShape( QFrame::StyledPanel );
    frame1->setFrameShadow( QFrame::Plain );

    labDescricao = new QLabel( frame1, "labDescricao" );
    labDescricao->setGeometry( QRect( 8, 3, 55, 24 ) );

    edtDescricao = new QLineEdit( frame1, "edtDescricao" );
    edtDescricao->setGeometry( QRect( 10, 28, 290, 20 ) );

    btnPesquisar = new QPushButton( frame1, "btnPesquisar" );
    btnPesquisar->setGeometry( QRect( 308, 26, 75, 25 ) );
    layout1->addWidget( frame1 );

    gridConsulta = new QTable( privateLayoutWidget, "gridConsulta" );
    gridConsulta->setNumCols( gridConsulta->numCols() + 1 );
    gridConsulta->horizontalHeader()->setLabel( gridConsulta->numCols() - 1, trUtf8( "\x43\xc3\xb3\x64\x69\x67\x6f" ) );
    gridConsulta->setNumCols( gridConsulta->numCols() + 1 );
    gridConsulta->horizontalHeader()->setLabel( gridConsulta->numCols() - 1, trUtf8( "\x44\x65\x73\x63\x72\x69\xc3\xa7\xc3\xa3\x6f" ) );
    gridConsulta->setNumRows( 1 );
    gridConsulta->setNumCols( 2 );
    gridConsulta->setReadOnly( TRUE );
    gridConsulta->setSelectionMode( QTable::Single );
    layout1->addWidget( gridConsulta );

    frame2 = new QFrame( privateLayoutWidget, "frame2" );
    frame2->setMinimumSize( QSize( 390, 40 ) );
    frame2->setFrameShape( QFrame::StyledPanel );
    frame2->setFrameShadow( QFrame::Plain );

    btnLimpar = new QPushButton( frame2, "btnLimpar" );
    btnLimpar->setGeometry( QRect( 226, 8, 75, 25 ) );

    btnFechar = new QPushButton( frame2, "btnFechar" );
    btnFechar->setGeometry( QRect( 306, 8, 75, 25 ) );

    labRegistros = new QLabel( frame2, "labRegistros" );
    labRegistros->setGeometry( QRect( 10, 9, 110, 20 ) );
    layout1->addWidget( frame2 );
    languageChange();
    resize( QSize(393, 252).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( btnPesquisar, SIGNAL( clicked() ), this, SLOT( btnPesquisar_clicked() ) );
    connect( btnLimpar, SIGNAL( clicked() ), this, SLOT( btnLimpar_clicked() ) );
    connect( btnFechar, SIGNAL( clicked() ), this, SLOT( btnFechar_clicked() ) );
    connect( this, SIGNAL( destroyed(QObject*) ), this, SLOT( frmConsultas_destroyed(QObject*) ) );

    // tab order
    setTabOrder( edtDescricao, btnPesquisar );
    setTabOrder( btnPesquisar, gridConsulta );
    setTabOrder( gridConsulta, btnLimpar );
    setTabOrder( btnLimpar, btnFechar );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmConsultas::~frmConsultas()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmConsultas::languageChange()
{
    setCaption( tr( "Consulta de " ) );
    labDescricao->setText( trUtf8( "\x44\x65\x73\x63\x72\x69\xc3\xa7\xc3\xa3\x6f\x3a" ) );
    btnPesquisar->setText( tr( "&Pesquisar" ) );
    btnPesquisar->setAccel( QKeySequence( tr( "Alt+P" ) ) );
    gridConsulta->horizontalHeader()->setLabel( 0, trUtf8( "\x43\xc3\xb3\x64\x69\x67\x6f" ) );
    gridConsulta->horizontalHeader()->setLabel( 1, trUtf8( "\x44\x65\x73\x63\x72\x69\xc3\xa7\xc3\xa3\x6f" ) );
    btnLimpar->setText( tr( "&Limpar" ) );
    btnLimpar->setAccel( QKeySequence( tr( "Alt+L" ) ) );
    btnFechar->setText( tr( "&Fechar" ) );
    btnFechar->setAccel( QKeySequence( tr( "Alt+F" ) ) );
    labRegistros->setText( tr( "Registro 0 de 0" ) );
}

