/****************************************************************************
** PlivrusqtApp meta object code from reading C++ file 'plivrusqt.h'
**
** Created: Sat Jan 1 16:31:07 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.1.1   edited Dec 9 10:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "plivrusqt.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PlivrusqtApp::className() const
{
    return "PlivrusqtApp";
}

QMetaObject *PlivrusqtApp::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PlivrusqtApp( "PlivrusqtApp", &PlivrusqtApp::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PlivrusqtApp::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PlivrusqtApp", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PlivrusqtApp::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PlivrusqtApp", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PlivrusqtApp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"slotFileNew", 0, 0 };
    static const QUMethod slot_1 = {"slotFileOpen", 0, 0 };
    static const QUMethod slot_2 = {"slotFileSave", 0, 0 };
    static const QUMethod slot_3 = {"slotFileSaveAs", 0, 0 };
    static const QUMethod slot_4 = {"slotFileClose", 0, 0 };
    static const QUMethod slot_5 = {"slotFilePrint", 0, 0 };
    static const QUMethod slot_6 = {"slotFileQuit", 0, 0 };
    static const QUMethod slot_7 = {"slotEditUndo", 0, 0 };
    static const QUMethod slot_8 = {"slotEditCut", 0, 0 };
    static const QUMethod slot_9 = {"slotEditCopy", 0, 0 };
    static const QUMethod slot_10 = {"slotEditPaste", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ "toggle", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"slotViewToolBar", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "toggle", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"slotViewStatusBar", 1, param_slot_12 };
    static const QUMethod slot_13 = {"slotWindowNewWindow", 0, 0 };
    static const QUMethod slot_14 = {"slotHelpAbout", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"slotStatusHelpMsg", 1, param_slot_15 };
    static const QUMethod slot_16 = {"windowMenuAboutToShow", 0, 0 };
    static const QUParameter param_slot_17[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"windowMenuActivated", 1, param_slot_17 };
    static const QMetaData slot_tbl[] = {
	{ "slotFileNew()", &slot_0, QMetaData::Private },
	{ "slotFileOpen()", &slot_1, QMetaData::Private },
	{ "slotFileSave()", &slot_2, QMetaData::Private },
	{ "slotFileSaveAs()", &slot_3, QMetaData::Private },
	{ "slotFileClose()", &slot_4, QMetaData::Private },
	{ "slotFilePrint()", &slot_5, QMetaData::Private },
	{ "slotFileQuit()", &slot_6, QMetaData::Private },
	{ "slotEditUndo()", &slot_7, QMetaData::Private },
	{ "slotEditCut()", &slot_8, QMetaData::Private },
	{ "slotEditCopy()", &slot_9, QMetaData::Private },
	{ "slotEditPaste()", &slot_10, QMetaData::Private },
	{ "slotViewToolBar(bool)", &slot_11, QMetaData::Private },
	{ "slotViewStatusBar(bool)", &slot_12, QMetaData::Private },
	{ "slotWindowNewWindow()", &slot_13, QMetaData::Private },
	{ "slotHelpAbout()", &slot_14, QMetaData::Private },
	{ "slotStatusHelpMsg(const QString&)", &slot_15, QMetaData::Private },
	{ "windowMenuAboutToShow()", &slot_16, QMetaData::Private },
	{ "windowMenuActivated(int)", &slot_17, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"PlivrusqtApp", parentObject,
	slot_tbl, 18,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PlivrusqtApp.setMetaObject( metaObj );
    return metaObj;
}

void* PlivrusqtApp::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PlivrusqtApp" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool PlivrusqtApp::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotFileNew(); break;
    case 1: slotFileOpen(); break;
    case 2: slotFileSave(); break;
    case 3: slotFileSaveAs(); break;
    case 4: slotFileClose(); break;
    case 5: slotFilePrint(); break;
    case 6: slotFileQuit(); break;
    case 7: slotEditUndo(); break;
    case 8: slotEditCut(); break;
    case 9: slotEditCopy(); break;
    case 10: slotEditPaste(); break;
    case 11: slotViewToolBar((bool)static_QUType_bool.get(_o+1)); break;
    case 12: slotViewStatusBar((bool)static_QUType_bool.get(_o+1)); break;
    case 13: slotWindowNewWindow(); break;
    case 14: slotHelpAbout(); break;
    case 15: slotStatusHelpMsg((const QString&)static_QUType_QString.get(_o+1)); break;
    case 16: windowMenuAboutToShow(); break;
    case 17: windowMenuActivated((int)static_QUType_int.get(_o+1)); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PlivrusqtApp::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PlivrusqtApp::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool PlivrusqtApp::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
