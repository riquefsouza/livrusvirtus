/****************************************************************************
** PlivrusqtDoc meta object code from reading C++ file 'plivrusqtdoc.h'
**
** Created: Sat Jan 1 16:31:05 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.1.1   edited Dec 9 10:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "plivrusqtdoc.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PlivrusqtDoc::className() const
{
    return "PlivrusqtDoc";
}

QMetaObject *PlivrusqtDoc::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PlivrusqtDoc( "PlivrusqtDoc", &PlivrusqtDoc::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PlivrusqtDoc::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PlivrusqtDoc", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PlivrusqtDoc::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PlivrusqtDoc", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PlivrusqtDoc::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "sender", &static_QUType_ptr, "PlivrusqtView", QUParameter::In }
    };
    static const QUMethod slot_0 = {"updateAllViews", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "updateAllViews(PlivrusqtView*)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"PlivrusqtDoc", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PlivrusqtDoc.setMetaObject( metaObj );
    return metaObj;
}

void* PlivrusqtDoc::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PlivrusqtDoc" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool PlivrusqtDoc::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: updateAllViews((PlivrusqtView*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PlivrusqtDoc::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PlivrusqtDoc::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool PlivrusqtDoc::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
