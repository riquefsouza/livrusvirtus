/****************************************************************************
** Form implementation generated from reading ui file 'Sobre.ui'
**
** Created: sáb 20. nov 20:10:04 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Sobre.h"

#include <qvariant.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "Sobre.ui.h"
/*
 *  Constructs a frmSobre as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
frmSobre::frmSobre( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "frmSobre" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );
    setModal( TRUE );

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setGeometry( QRect( 10, 10, 290, 190 ) );

    labVersao = new QLabel( groupBox1, "labVersao" );
    labVersao->setGeometry( QRect( 205, 90, 70, 20 ) );

    labDireitos = new QLabel( groupBox1, "labDireitos" );
    labDireitos->setGeometry( QRect( 10, 114, 266, 20 ) );

    labSistema = new QLabel( groupBox1, "labSistema" );
    labSistema->setGeometry( QRect( 23, 132, 240, 40 ) );
    labSistema->setAlignment( int( QLabel::WordBreak | QLabel::AlignCenter ) );

    labFigura = new QLabel( groupBox1, "labFigura" );
    labFigura->setGeometry( QRect( 15, 10, 254, 72 ) );
    labFigura->setPixmap( QPixmap::fromMimeSource( "LivrusVirtus.xpm" ) );

    btkOk = new QPushButton( this, "btkOk" );
    btkOk->setGeometry( QRect( 112, 208, 75, 25 ) );
    languageChange();
    resize( QSize(309, 240).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( btkOk, SIGNAL( clicked() ), this, SLOT( btkOk_clicked() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmSobre::~frmSobre()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmSobre::languageChange()
{
    setCaption( tr( "Sobre o Sistema" ) );
    groupBox1->setTitle( QString::null );
    labVersao->setText( trUtf8( "\x56\x65\x72\x73\xc3\xa3\x6f\x3a\x20\x31\x2e\x30\x2e\x30" ) );
    labDireitos->setText( tr( "Todos os diretos reservados para: Henrique F. de Souza" ) );
    labSistema->setText( trUtf8( "\x53\x69\x73\x74\x65\x6d\x61\x20\x69\x6e\x74\x65\x67\x72\x61\x6e\x74\x65\x20\x64\x6f\x20\x70\x72\x6f\x6a\x65\x74\x6f\x20\x4c\x69\x76\x72\x75\x73\x20\x56\x69\x72\x74\x75\x73\x2c\x20\x76\x65\x72\x73\xc3\xa3\x6f\x20\x70\x72\x6f\x67\x72\x61\x6d\x61\x64\x61\x20\x6e\x6f\x20\x51\x54\x20\x44\x65\x73\x69\x67\x6e\x65\x72\x2e" ) );
    labFigura->setText( QString::null );
    btkOk->setText( tr( "&Ok" ) );
    btkOk->setAccel( QKeySequence( tr( "Alt+O" ) ) );
}

