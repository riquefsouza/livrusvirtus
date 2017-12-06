/****************************************************************************
** Form implementation generated from reading ui file 'Teste.ui'
**
** Created: sáb 20. nov 20:02:39 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Teste.h"

#include <qvariant.h>
#include <qsqldatabase.h>
#include <qsqlcursor.h>
#include <qsqlform.h>
#include <qsqlrecord.h>
#include <qpushbutton.h>
#include <qdatatable.h>
#include <qdatabrowser.h>
#include <qspinbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qdataview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a frmTeste as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
frmTeste::frmTeste( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "frmTeste" );

    dataTable1 = new QDataTable( this, "dataTable1" );
    dataTable1->addColumn( "codassunto", tr( "Codassunto" ) );
    dataTable1->addColumn( "assunto", tr( "Assunto" ) );
    dataTable1->setGeometry( QRect( 30, 20, 350, 230 ) );
    dataTable1->setReadOnly( TRUE );
    dataTable1->setSorting( TRUE );

    dataBrowser1 = new QDataBrowser( this, "dataBrowser1" );
    dataBrowser1->setGeometry( QRect( 20, 270, 362, 108 ) );
    dataBrowser1Layout = new QGridLayout( dataBrowser1, 1, 1, 11, 6, "dataBrowser1Layout"); 

    layout2 = new QGridLayout( 0, 1, 1, 0, 6, "layout2"); 

    QSpinBoxCodassunto = new QSpinBox( dataBrowser1, "QSpinBoxCodassunto" );
    QSpinBoxCodassunto->setMaxValue( 2147483647 );

    layout2->addWidget( QSpinBoxCodassunto, 0, 1 );

    labelCodassunto = new QLabel( dataBrowser1, "labelCodassunto" );

    layout2->addWidget( labelCodassunto, 0, 0 );

    labelAssunto = new QLabel( dataBrowser1, "labelAssunto" );

    layout2->addWidget( labelAssunto, 0, 2 );

    QLineEditAssunto = new QLineEdit( dataBrowser1, "QLineEditAssunto" );

    layout2->addWidget( QLineEditAssunto, 0, 3 );

    dataBrowser1Layout->addLayout( layout2, 0, 0 );

    layout3 = new QHBoxLayout( 0, 0, 6, "layout3"); 

    PushButtonFirst = new QPushButton( dataBrowser1, "PushButtonFirst" );
    layout3->addWidget( PushButtonFirst );

    PushButtonPrev = new QPushButton( dataBrowser1, "PushButtonPrev" );
    layout3->addWidget( PushButtonPrev );

    PushButtonNext = new QPushButton( dataBrowser1, "PushButtonNext" );
    layout3->addWidget( PushButtonNext );

    PushButtonLast = new QPushButton( dataBrowser1, "PushButtonLast" );
    layout3->addWidget( PushButtonLast );

    dataBrowser1Layout->addLayout( layout3, 1, 0 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    PushButtonInsert = new QPushButton( dataBrowser1, "PushButtonInsert" );
    layout4->addWidget( PushButtonInsert );

    PushButtonUpdate = new QPushButton( dataBrowser1, "PushButtonUpdate" );
    layout4->addWidget( PushButtonUpdate );

    PushButtonDelete = new QPushButton( dataBrowser1, "PushButtonDelete" );
    layout4->addWidget( PushButtonDelete );

    dataBrowser1Layout->addLayout( layout4, 2, 0 );

    dataView2 = new QDataView( this, "dataView2" );
    dataView2->setGeometry( QRect( 20, 400, 460, 44 ) );
    dataView2Layout = new QGridLayout( dataView2, 1, 1, 11, 6, "dataView2Layout"); 

    layout5 = new QGridLayout( 0, 1, 1, 0, 6, "layout5"); 

    labelCodassunto_2 = new QLabel( dataView2, "labelCodassunto_2" );

    layout5->addWidget( labelCodassunto_2, 0, 0 );

    labelAssunto_2 = new QLabel( dataView2, "labelAssunto_2" );

    layout5->addWidget( labelAssunto_2, 0, 2 );

    QLineEditAssunto_2 = new QLineEdit( dataView2, "QLineEditAssunto_2" );

    layout5->addWidget( QLineEditAssunto_2, 0, 3 );

    QSpinBoxCodassunto_2 = new QSpinBox( dataView2, "QSpinBoxCodassunto_2" );
    QSpinBoxCodassunto_2->setMaxValue( 2147483647 );

    layout5->addWidget( QSpinBoxCodassunto_2, 0, 1 );

    dataView2Layout->addLayout( layout5, 0, 0 );

    ACLivrusConnection = QSqlDatabase::database( "ACLivrus" );
    QSqlForm* dataBrowser1Form =  new QSqlForm( this, "dataBrowser1Form" );
    dataBrowser1Form->insert( QSpinBoxCodassunto, "codassunto" );
    dataBrowser1Form->insert( QLineEditAssunto, "assunto" );
    dataBrowser1->setForm( dataBrowser1Form );
    QSqlForm* dataView2Form =  new QSqlForm( this, "dataView2Form" );
    dataView2Form->insert( QLineEditAssunto_2, "assunto" );
    dataView2Form->insert( QSpinBoxCodassunto_2, "codassunto" );
    dataView2->setForm( dataView2Form );
    languageChange();
    resize( QSize(498, 480).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( PushButtonFirst, SIGNAL( clicked() ), dataBrowser1, SLOT( first() ) );
    connect( dataBrowser1, SIGNAL( firstRecordAvailable( bool ) ), PushButtonFirst, SLOT( setEnabled(bool) ) );
    connect( PushButtonPrev, SIGNAL( clicked() ), dataBrowser1, SLOT( prev() ) );
    connect( dataBrowser1, SIGNAL( prevRecordAvailable( bool ) ), PushButtonPrev, SLOT( setEnabled(bool) ) );
    connect( PushButtonNext, SIGNAL( clicked() ), dataBrowser1, SLOT( next() ) );
    connect( dataBrowser1, SIGNAL( nextRecordAvailable( bool ) ), PushButtonNext, SLOT( setEnabled(bool) ) );
    connect( PushButtonLast, SIGNAL( clicked() ), dataBrowser1, SLOT( last() ) );
    connect( dataBrowser1, SIGNAL( lastRecordAvailable( bool ) ), PushButtonLast, SLOT( setEnabled(bool) ) );
    connect( PushButtonInsert, SIGNAL( clicked() ), dataBrowser1, SLOT( insert() ) );
    connect( PushButtonUpdate, SIGNAL( clicked() ), dataBrowser1, SLOT( update() ) );
    connect( PushButtonDelete, SIGNAL( clicked() ), dataBrowser1, SLOT( del() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmTeste::~frmTeste()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Widget polish.  Reimplemented to handle
 *  default data table initialization
 *  default data browser initialization
 */
void frmTeste::polish()
{
    if ( dataTable1 ) {
        QSqlCursor* cursor = dataTable1->sqlCursor();
        if ( !cursor ) {
            cursor = new QSqlCursor( "Assunto", TRUE, ACLivrusConnection );
            if ( dataTable1->isReadOnly() ) 
                cursor->setMode( QSqlCursor::ReadOnly );
            dataTable1->setSqlCursor( cursor, FALSE, TRUE );
        }
        if ( !cursor->isActive() )
            dataTable1->refresh( QDataTable::RefreshAll );
    }
    if ( dataBrowser1 ) {
        if ( !dataBrowser1->sqlCursor() ) {
            QSqlCursor* cursor = new QSqlCursor( "Assunto", TRUE, ACLivrusConnection );
            dataBrowser1->setSqlCursor( cursor, TRUE );
            dataBrowser1->refresh();
            dataBrowser1->first();
        }
    }
    QWidget::polish();
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmTeste::languageChange()
{
    setCaption( tr( "Form1" ) );
    labelCodassunto->setText( tr( "Codassunto" ) );
    labelAssunto->setText( tr( "Assunto" ) );
    PushButtonFirst->setText( tr( "|< &First" ) );
    PushButtonPrev->setText( tr( "<< &Prev" ) );
    PushButtonNext->setText( tr( "&Next >>" ) );
    PushButtonLast->setText( tr( "&Last >|" ) );
    PushButtonInsert->setText( tr( "&Insert" ) );
    PushButtonUpdate->setText( tr( "&Update" ) );
    PushButtonDelete->setText( tr( "&Delete" ) );
    labelCodassunto_2->setText( tr( "Codassunto" ) );
    labelAssunto_2->setText( tr( "Assunto" ) );
}

