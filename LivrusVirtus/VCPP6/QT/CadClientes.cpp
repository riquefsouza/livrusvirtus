/****************************************************************************
** Form implementation generated from reading ui file 'CadClientes.ui'
**
** Created: sáb 20. nov 20:10:03 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "CadClientes.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qgroupbox.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "CadClientes.ui.h"
/*
 *  Constructs a frmCadClientes as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
frmCadClientes::frmCadClientes( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "frmCadClientes" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );

    labNome = new QLabel( this, "labNome" );
    labNome->setGeometry( QRect( 10, 59, 60, 20 ) );

    labCPF = new QLabel( this, "labCPF" );
    labCPF->setGeometry( QRect( 10, 8, 55, 20 ) );

    edtEmail = new QLineEdit( this, "edtEmail" );
    edtEmail->setEnabled( FALSE );
    edtEmail->setGeometry( QRect( 10, 123, 313, 20 ) );
    edtEmail->setMaxLength( 30 );

    edtNome = new QLineEdit( this, "edtNome" );
    edtNome->setEnabled( FALSE );
    edtNome->setGeometry( QRect( 10, 80, 313, 20 ) );
    edtNome->setFrameShape( QLineEdit::LineEditPanel );
    edtNome->setFrameShadow( QLineEdit::Sunken );
    edtNome->setMaxLength( 30 );

    labIdentidade = new QLabel( this, "labIdentidade" );
    labIdentidade->setGeometry( QRect( 330, 101, 70, 20 ) );

    edtIdentidade = new QLineEdit( this, "edtIdentidade" );
    edtIdentidade->setEnabled( FALSE );
    edtIdentidade->setGeometry( QRect( 330, 122, 105, 20 ) );
    edtIdentidade->setMaxLength( 10 );

    labDtNascimento = new QLabel( this, "labDtNascimento" );
    labDtNascimento->setGeometry( QRect( 330, 147, 90, 20 ) );

    labTelefone = new QLabel( this, "labTelefone" );
    labTelefone->setGeometry( QRect( 210, 148, 55, 20 ) );

    edtTelefone = new QLineEdit( this, "edtTelefone" );
    edtTelefone->setEnabled( FALSE );
    edtTelefone->setGeometry( QRect( 210, 168, 113, 20 ) );
    edtTelefone->setMaxLength( 17 );

    edtDtNascimento = new QDateEdit( this, "edtDtNascimento" );
    edtDtNascimento->setEnabled( FALSE );
    edtDtNascimento->setGeometry( QRect( 330, 167, 105, 20 ) );
    edtDtNascimento->setDate( QDate( 2000, 1, 1 ) );

    grpSexo = new QButtonGroup( this, "grpSexo" );
    grpSexo->setEnabled( FALSE );
    grpSexo->setGeometry( QRect( 10, 149, 190, 41 ) );

    rbFeminino = new QRadioButton( grpSexo, "rbFeminino" );
    rbFeminino->setGeometry( QRect( 110, 14, 70, 20 ) );

    rbMasculino = new QRadioButton( grpSexo, "rbMasculino" );
    rbMasculino->setGeometry( QRect( 20, 14, 70, 20 ) );

    grpEndereco = new QGroupBox( this, "grpEndereco" );
    grpEndereco->setEnabled( FALSE );
    grpEndereco->setGeometry( QRect( 10, 194, 450, 140 ) );

    labBairro = new QLabel( grpEndereco, "labBairro" );
    labBairro->setGeometry( QRect( 285, 46, 55, 20 ) );

    labEstado = new QLabel( grpEndereco, "labEstado" );
    labEstado->setGeometry( QRect( 285, 90, 55, 20 ) );

    edtLogradouro = new QLineEdit( grpEndereco, "edtLogradouro" );
    edtLogradouro->setEnabled( FALSE );
    edtLogradouro->setGeometry( QRect( 12, 67, 265, 20 ) );
    edtLogradouro->setFrameShape( QLineEdit::LineEditPanel );
    edtLogradouro->setFrameShadow( QLineEdit::Sunken );
    edtLogradouro->setMaxLength( 50 );

    edtEstado = new QLineEdit( grpEndereco, "edtEstado" );
    edtEstado->setEnabled( FALSE );
    edtEstado->setGeometry( QRect( 285, 110, 153, 20 ) );
    edtEstado->setMaxLength( 14 );

    edtBairro = new QLineEdit( grpEndereco, "edtBairro" );
    edtBairro->setEnabled( FALSE );
    edtBairro->setGeometry( QRect( 285, 67, 153, 20 ) );
    edtBairro->setMaxLength( 14 );

    labLogradouro = new QLabel( grpEndereco, "labLogradouro" );
    labLogradouro->setGeometry( QRect( 12, 46, 60, 20 ) );

    labCEP = new QLabel( grpEndereco, "labCEP" );
    labCEP->setGeometry( QRect( 12, 90, 55, 20 ) );

    edtCEP = new QLineEdit( grpEndereco, "edtCEP" );
    edtCEP->setEnabled( FALSE );
    edtCEP->setGeometry( QRect( 12, 110, 65, 20 ) );

    edtCidade = new QLineEdit( grpEndereco, "edtCidade" );
    edtCidade->setEnabled( FALSE );
    edtCidade->setGeometry( QRect( 84, 110, 193, 20 ) );
    edtCidade->setMaxLength( 30 );

    labCidade = new QLabel( grpEndereco, "labCidade" );
    labCidade->setGeometry( QRect( 84, 90, 55, 20 ) );

    edtCodEndereco = new QLineEdit( grpEndereco, "edtCodEndereco" );
    edtCodEndereco->setGeometry( QRect( 12, 23, 81, 20 ) );
    edtCodEndereco->setMaxLength( 10 );

    btnPEndereco = new QPushButton( grpEndereco, "btnPEndereco" );
    btnPEndereco->setGeometry( QRect( 100, 23, 21, 21 ) );

    labEmail = new QLabel( this, "labEmail" );
    labEmail->setGeometry( QRect( 10, 101, 55, 20 ) );

    labCodPais = new QLabel( this, "labCodPais" );
    labCodPais->setGeometry( QRect( 13, 340, 80, 20 ) );

    edtPais = new QLineEdit( this, "edtPais" );
    edtPais->setEnabled( FALSE );
    edtPais->setGeometry( QRect( 90, 360, 225, 20 ) );
    edtPais->setMaxLength( 30 );

    edtProfissao = new QLineEdit( this, "edtProfissao" );
    edtProfissao->setEnabled( FALSE );
    edtProfissao->setGeometry( QRect( 90, 403, 225, 20 ) );
    edtProfissao->setMaxLength( 30 );

    edtCPF = new QLineEdit( this, "edtCPF" );
    edtCPF->setGeometry( QRect( 10, 33, 121, 20 ) );
    edtCPF->setMaxLength( 14 );

    btnNovo = new QPushButton( this, "btnNovo" );
    btnNovo->setGeometry( QRect( 152, 30, 75, 25 ) );

    btnPesquisar = new QPushButton( this, "btnPesquisar" );
    btnPesquisar->setGeometry( QRect( 455, 20, 75, 25 ) );

    btnAnterior = new QPushButton( this, "btnAnterior" );
    btnAnterior->setEnabled( FALSE );
    btnAnterior->setGeometry( QRect( 455, 52, 75, 25 ) );

    btnProximo = new QPushButton( this, "btnProximo" );
    btnProximo->setEnabled( FALSE );
    btnProximo->setGeometry( QRect( 455, 84, 75, 25 ) );

    edtCodPais = new QLineEdit( this, "edtCodPais" );
    edtCodPais->setEnabled( FALSE );
    edtCodPais->setGeometry( QRect( 13, 360, 73, 20 ) );
    edtCodPais->setMaxLength( 3 );

    btnPPais = new QPushButton( this, "btnPPais" );
    btnPPais->setEnabled( FALSE );
    btnPPais->setGeometry( QRect( 319, 360, 21, 21 ) );

    btnPProfissao = new QPushButton( this, "btnPProfissao" );
    btnPProfissao->setEnabled( FALSE );
    btnPProfissao->setGeometry( QRect( 319, 403, 21, 21 ) );

    btnSalvar = new QPushButton( this, "btnSalvar" );
    btnSalvar->setEnabled( FALSE );
    btnSalvar->setGeometry( QRect( 215, 438, 75, 25 ) );

    btnExcluir = new QPushButton( this, "btnExcluir" );
    btnExcluir->setEnabled( FALSE );
    btnExcluir->setGeometry( QRect( 295, 438, 75, 25 ) );

    btnLimpar = new QPushButton( this, "btnLimpar" );
    btnLimpar->setGeometry( QRect( 375, 438, 75, 25 ) );

    btnFechar = new QPushButton( this, "btnFechar" );
    btnFechar->setGeometry( QRect( 455, 438, 75, 25 ) );

    labCodProfissao = new QLabel( this, "labCodProfissao" );
    labCodProfissao->setGeometry( QRect( 13, 383, 80, 20 ) );

    edtCodProfissao = new QLineEdit( this, "edtCodProfissao" );
    edtCodProfissao->setEnabled( FALSE );
    edtCodProfissao->setGeometry( QRect( 13, 403, 73, 20 ) );
    edtCodProfissao->setMaxLength( 10 );
    languageChange();
    resize( QSize(537, 471).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( edtCPF, SIGNAL( lostFocus() ), this, SLOT( edtCPF_lostFocus() ) );
    connect( btnNovo, SIGNAL( clicked() ), this, SLOT( btnNovo_clicked() ) );
    connect( btnPesquisar, SIGNAL( clicked() ), this, SLOT( btnPesquisar_clicked() ) );
    connect( btnAnterior, SIGNAL( clicked() ), this, SLOT( btnAnterior_clicked() ) );
    connect( btnProximo, SIGNAL( clicked() ), this, SLOT( btnProximo_clicked() ) );
    connect( edtCodEndereco, SIGNAL( lostFocus() ), this, SLOT( edtCodEndereco_lostFocus() ) );
    connect( btnPEndereco, SIGNAL( clicked() ), this, SLOT( btnPEndereco_clicked() ) );
    connect( edtCodPais, SIGNAL( lostFocus() ), this, SLOT( edtCodPais_lostFocus() ) );
    connect( btnPPais, SIGNAL( clicked() ), this, SLOT( btnPPais_clicked() ) );
    connect( edtCodProfissao, SIGNAL( lostFocus() ), this, SLOT( edtCodProfissao_lostFocus() ) );
    connect( btnPProfissao, SIGNAL( clicked() ), this, SLOT( btnPProfissao_clicked() ) );
    connect( btnSalvar, SIGNAL( clicked() ), this, SLOT( btnSalvar_clicked() ) );
    connect( btnExcluir, SIGNAL( clicked() ), this, SLOT( btnExcluir_clicked() ) );
    connect( btnLimpar, SIGNAL( clicked() ), this, SLOT( btnLimpar_clicked() ) );
    connect( btnFechar, SIGNAL( clicked() ), this, SLOT( btnFechar_clicked() ) );
    connect( this, SIGNAL( destroyed(QObject*) ), this, SLOT( frmCadClientes_destroyed(QObject*) ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmCadClientes::~frmCadClientes()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmCadClientes::languageChange()
{
    setCaption( tr( "Cadastro de Clientes" ) );
    labNome->setText( tr( "Nome:" ) );
    labCPF->setText( tr( "CPF:" ) );
    labIdentidade->setText( tr( "Identidade:" ) );
    labDtNascimento->setText( tr( "Dt. Nascimento:" ) );
    labTelefone->setText( tr( "Telefone:" ) );
    grpSexo->setTitle( tr( "Sexo" ) );
    rbFeminino->setText( tr( "Feminino" ) );
    rbMasculino->setText( tr( "Masculino" ) );
    grpEndereco->setTitle( trUtf8( "\x45\x6e\x64\x65\x72\x65\xc3\xa7\x6f" ) );
    labBairro->setText( tr( "Bairro:" ) );
    labEstado->setText( tr( "Estado:" ) );
    labLogradouro->setText( tr( "Logradouro:" ) );
    labCEP->setText( tr( "CEP:" ) );
    labCidade->setText( tr( "Cidade:" ) );
    btnPEndereco->setText( tr( "..." ) );
    labEmail->setText( tr( "E-mail:" ) );
    labCodPais->setText( trUtf8( "\x50\x61\xc3\xad\x73\x20\x64\x65\x20\x6f\x72\x69\x67\x65\x6d\x3a" ) );
    btnNovo->setText( tr( "&Novo" ) );
    btnNovo->setAccel( QKeySequence( tr( "Alt+N" ) ) );
    btnPesquisar->setText( tr( "&Pesquisar" ) );
    btnPesquisar->setAccel( QKeySequence( tr( "Alt+P" ) ) );
    btnAnterior->setText( tr( "&Anterior" ) );
    btnAnterior->setAccel( QKeySequence( tr( "Alt+A" ) ) );
    btnProximo->setText( trUtf8( "\x50\x72\xc3\xb3\x78\x69\x26\x6d\x6f" ) );
    btnProximo->setAccel( QKeySequence( tr( "Alt+M" ) ) );
    btnPPais->setText( tr( "..." ) );
    btnPProfissao->setText( tr( "..." ) );
    btnSalvar->setText( tr( "&Salvar" ) );
    btnSalvar->setAccel( QKeySequence( tr( "Alt+S" ) ) );
    btnExcluir->setText( tr( "&Excluir" ) );
    btnExcluir->setAccel( QKeySequence( tr( "Alt+E" ) ) );
    btnLimpar->setText( tr( "&Limpar" ) );
    btnLimpar->setAccel( QKeySequence( tr( "Alt+L" ) ) );
    btnFechar->setText( tr( "&Fechar" ) );
    btnFechar->setAccel( QKeySequence( tr( "Alt+F" ) ) );
    labCodProfissao->setText( trUtf8( "\x50\x72\x6f\x66\x69\x73\x73\xc3\xa3\x6f\x3a" ) );
}

