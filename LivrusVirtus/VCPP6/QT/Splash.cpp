/****************************************************************************
** Form implementation generated from reading ui file 'Splash.ui'
**
** Created: sáb 20. nov 20:10:04 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "Splash.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

#include "Splash.ui.h"
/*
 *  Constructs a frmSplash as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
frmSplash::frmSplash( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "frmSplash" );
    setIcon( QPixmap::fromMimeSource( "Livrus.bmp" ) );
    setModal( TRUE );

    pixmapLabel1 = new QLabel( this, "pixmapLabel1" );
    pixmapLabel1->setGeometry( QRect( 0, 0, 254, 72 ) );
    pixmapLabel1->setPixmap( QPixmap::fromMimeSource( "LivrusVirtus.xpm" ) );
    pixmapLabel1->setScaledContents( TRUE );
    languageChange();
    resize( QSize(255, 72).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( this, SIGNAL( destroyed(QObject*) ), this, SLOT( frmSplash_destroyed(QObject*) ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frmSplash::~frmSplash()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frmSplash::languageChange()
{
    setCaption( tr( "Splash" ) );
}

