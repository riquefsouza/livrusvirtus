/****************************************************************************
** Form implementation generated from reading ui file 'Login.ui'
**
** Created: sáb 20. nov 20:10:04 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Login.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "Login.ui.h"
/*
 *  Constructs a frmLogin as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
frmLogin::frmLogin( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "frmLogin" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );
    setSizeGripEnabled( FALSE );
    setModal( TRUE );

    textLabel15 = new QLabel( this, "textLabel15" );
    textLabel15->setGeometry( QRect( 10, 10, 90, 90 ) );
    textLabel15->setPixmap( QPixmap::fromMimeSource( "Login.xpm" ) );

    labSenha = new QLabel( this, "labSenha" );
    labSenha->setGeometry( QRect( 113, 61, 55, 20 ) );

    labLogin = new QLabel( this, "labLogin" );
    labLogin->setGeometry( QRect( 113, 11, 55, 20 ) );

    edtLogin = new QLineEdit( this, "edtLogin" );
    edtLogin->setEnabled( TRUE );
    edtLogin->setGeometry( QRect( 113, 31, 70, 20 ) );
    edtLogin->setMaxLength( 10 );

    edtSenha = new QLineEdit( this, "edtSenha" );
    edtSenha->setGeometry( QRect( 113, 80, 70, 20 ) );
    edtSenha->setMaxLength( 10 );
    edtSenha->setEchoMode( QLineEdit::Password );

    btkLogin = new QPushButton( this, "btkLogin" );
    btkLogin->setGeometry( QRect( 20, 110, 75, 25 ) );

    btkCancelar = new QPushButton( this, "btkCancelar" );
    btkCancelar->setGeometry( QRect( 98, 110, 75, 25 ) );
    languageChange();
    resize( QSize(193, 144).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( btkLogin, SIGNAL( clicked() ), this, SLOT( btkLogin_clicked() ) );
    connect( btkCancelar, SIGNAL( clicked() ), this, SLOT( btkCancelar_clicked() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmLogin::~frmLogin()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmLogin::languageChange()
{
    setCaption( tr( "Login do sistema" ) );
    textLabel15->setText( QString::null );
    labSenha->setText( tr( "Senha:" ) );
    labLogin->setText( tr( "Login:" ) );
    edtLogin->setText( QString::null );
    btkLogin->setText( tr( "&Login" ) );
    btkLogin->setAccel( QKeySequence( tr( "Alt+L" ) ) );
    btkCancelar->setText( tr( "&Cancelar" ) );
    btkCancelar->setAccel( QKeySequence( tr( "Alt+C" ) ) );
}

