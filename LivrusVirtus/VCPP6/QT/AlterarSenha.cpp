/****************************************************************************
** Form implementation generated from reading ui file 'AlterarSenha.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "AlterarSenha.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "AlterarSenha.ui.h"
/*
 *  Constructs a frmAlterarSenha as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
frmAlterarSenha::frmAlterarSenha( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "frmAlterarSenha" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );

    labLogin = new QLabel( this, "labLogin" );
    labLogin->setGeometry( QRect( 10, 8, 49, 20 ) );

    edtLogin = new QLineEdit( this, "edtLogin" );
    edtLogin->setEnabled( FALSE );
    edtLogin->setGeometry( QRect( 8, 29, 90, 20 ) );
    edtLogin->setFrameShape( QLineEdit::LineEditPanel );
    edtLogin->setFrameShadow( QLineEdit::Sunken );
    edtLogin->setMaxLength( 10 );

    labNovaSenha = new QLabel( this, "labNovaSenha" );
    labNovaSenha->setGeometry( QRect( 8, 60, 70, 20 ) );

    edtNovaSenha = new QLineEdit( this, "edtNovaSenha" );
    edtNovaSenha->setGeometry( QRect( 8, 80, 90, 20 ) );
    edtNovaSenha->setMaxLength( 10 );
    edtNovaSenha->setEchoMode( QLineEdit::Password );

    edtConfirmarSenha = new QLineEdit( this, "edtConfirmarSenha" );
    edtConfirmarSenha->setGeometry( QRect( 122, 80, 90, 20 ) );
    edtConfirmarSenha->setMaxLength( 10 );
    edtConfirmarSenha->setEchoMode( QLineEdit::Password );

    labConfirmarSenha = new QLabel( this, "labConfirmarSenha" );
    labConfirmarSenha->setGeometry( QRect( 121, 60, 90, 20 ) );

    edtSenhaAtual = new QLineEdit( this, "edtSenhaAtual" );
    edtSenhaAtual->setGeometry( QRect( 123, 29, 90, 20 ) );
    edtSenhaAtual->setMaxLength( 10 );
    edtSenhaAtual->setEchoMode( QLineEdit::Password );

    labSenhaAtual = new QLabel( this, "labSenhaAtual" );
    labSenhaAtual->setGeometry( QRect( 121, 8, 70, 20 ) );

    btnSalvar = new QPushButton( this, "btnSalvar" );
    btnSalvar->setGeometry( QRect( 10, 115, 75, 25 ) );

    btnLimpar = new QPushButton( this, "btnLimpar" );
    btnLimpar->setGeometry( QRect( 93, 115, 75, 25 ) );

    btnFechar = new QPushButton( this, "btnFechar" );
    btnFechar->setGeometry( QRect( 175, 115, 75, 25 ) );
    languageChange();
    resize( QSize(261, 147).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( btnSalvar, SIGNAL( clicked() ), this, SLOT( btnSalvar_clicked() ) );
    connect( btnLimpar, SIGNAL( clicked() ), this, SLOT( btnLimpar_clicked() ) );
    connect( btnFechar, SIGNAL( clicked() ), this, SLOT( btnFechar_clicked() ) );
    connect( this, SIGNAL( destroyed(QObject*) ), this, SLOT( frmAlterarSenha_destroyed(QObject*) ) );

    // tab order
    setTabOrder( edtLogin, edtSenhaAtual );
    setTabOrder( edtSenhaAtual, edtNovaSenha );
    setTabOrder( edtNovaSenha, edtConfirmarSenha );
    setTabOrder( edtConfirmarSenha, btnSalvar );
    setTabOrder( btnSalvar, btnLimpar );
    setTabOrder( btnLimpar, btnFechar );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmAlterarSenha::~frmAlterarSenha()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmAlterarSenha::languageChange()
{
    setCaption( trUtf8( "\x41\x6c\x74\x65\x72\x61\xc3\xa7\xc3\xa3\x6f\x20\x64\x65\x20\x53\x65\x6e\x68\x61" ) );
    labLogin->setText( tr( "Login:" ) );
    labNovaSenha->setText( tr( "Nova senha:" ) );
    labConfirmarSenha->setText( tr( "Confirmar senha:" ) );
    labSenhaAtual->setText( tr( "Senha atual:" ) );
    btnSalvar->setText( tr( "&Salvar" ) );
    btnSalvar->setAccel( QKeySequence( tr( "Alt+S" ) ) );
    btnLimpar->setText( tr( "&Limpar" ) );
    btnLimpar->setAccel( QKeySequence( tr( "Alt+L" ) ) );
    btnFechar->setText( tr( "&Fechar" ) );
    btnFechar->setAccel( QKeySequence( tr( "Alt+F" ) ) );
}

