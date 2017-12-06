/****************************************************************************
** frmPrincipal meta object code from reading C++ file 'Principal.h'
**
** Created: seg 13. dez 22:12:01 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "Principal.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frmPrincipal::className() const
{
    return "frmPrincipal";
}

QMetaObject *frmPrincipal::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frmPrincipal( "frmPrincipal", &frmPrincipal::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frmPrincipal::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmPrincipal", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frmPrincipal::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmPrincipal", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frmPrincipal::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"cadastrosAssuntosAction_activated", 0, 0 };
    static const QUMethod slot_1 = {"cadastrosAutoresAction_activated", 0, 0 };
    static const QUMethod slot_2 = {"cadastrosEditorasAction_activated", 0, 0 };
    static const QUMethod slot_3 = {"cadastrosEnderecosAction_activated", 0, 0 };
    static const QUMethod slot_4 = {"cadastrosIdiomasAction_activated", 0, 0 };
    static const QUMethod slot_5 = {"cadastrosPaisesAction_activated", 0, 0 };
    static const QUMethod slot_6 = {"cadastrosProfissoesAction_activated", 0, 0 };
    static const QUMethod slot_7 = {"cadastrosClientesAction_activated", 0, 0 };
    static const QUMethod slot_8 = {"cadastrosLivrosAction_activated", 0, 0 };
    static const QUMethod slot_9 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "cadastrosAssuntosAction_activated()", &slot_0, QMetaData::Public },
	{ "cadastrosAutoresAction_activated()", &slot_1, QMetaData::Public },
	{ "cadastrosEditorasAction_activated()", &slot_2, QMetaData::Public },
	{ "cadastrosEnderecosAction_activated()", &slot_3, QMetaData::Public },
	{ "cadastrosIdiomasAction_activated()", &slot_4, QMetaData::Public },
	{ "cadastrosPaisesAction_activated()", &slot_5, QMetaData::Public },
	{ "cadastrosProfissoesAction_activated()", &slot_6, QMetaData::Public },
	{ "cadastrosClientesAction_activated()", &slot_7, QMetaData::Public },
	{ "cadastrosLivrosAction_activated()", &slot_8, QMetaData::Public },
	{ "languageChange()", &slot_9, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frmPrincipal", parentObject,
	slot_tbl, 10,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frmPrincipal.setMetaObject( metaObj );
    return metaObj;
}

void* frmPrincipal::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frmPrincipal" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool frmPrincipal::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: cadastrosAssuntosAction_activated(); break;
    case 1: cadastrosAutoresAction_activated(); break;
    case 2: cadastrosEditorasAction_activated(); break;
    case 3: cadastrosEnderecosAction_activated(); break;
    case 4: cadastrosIdiomasAction_activated(); break;
    case 5: cadastrosPaisesAction_activated(); break;
    case 6: cadastrosProfissoesAction_activated(); break;
    case 7: cadastrosClientesAction_activated(); break;
    case 8: cadastrosLivrosAction_activated(); break;
    case 9: languageChange(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frmPrincipal::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frmPrincipal::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool frmPrincipal::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
