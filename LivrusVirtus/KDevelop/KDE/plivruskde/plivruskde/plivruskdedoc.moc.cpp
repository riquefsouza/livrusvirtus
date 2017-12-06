/****************************************************************************
** PlivruskdeDoc meta object code from reading C++ file 'plivruskdedoc.h'
**
** Created: Sun Jan 2 10:34:10 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.1.1   edited Dec 9 10:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "plivruskdedoc.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PlivruskdeDoc::className() const
{
    return "PlivruskdeDoc";
}

QMetaObject *PlivruskdeDoc::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PlivruskdeDoc( "PlivruskdeDoc", &PlivruskdeDoc::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PlivruskdeDoc::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PlivruskdeDoc", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PlivruskdeDoc::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PlivruskdeDoc", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PlivruskdeDoc::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "sender", &static_QUType_ptr, "PlivruskdeView", QUParameter::In }
    };
    static const QUMethod slot_0 = {"updateAllViews", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "updateAllViews(PlivruskdeView*)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"PlivruskdeDoc", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PlivruskdeDoc.setMetaObject( metaObj );
    return metaObj;
}

void* PlivruskdeDoc::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PlivruskdeDoc" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool PlivruskdeDoc::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: updateAllViews((PlivruskdeView*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PlivruskdeDoc::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PlivruskdeDoc::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool PlivruskdeDoc::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
