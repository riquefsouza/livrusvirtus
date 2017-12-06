/****************************************************************************
** frmSplash meta object code from reading C++ file 'Splash.h'
**
** Created: seg 13. dez 22:12:03 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "Splash.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frmSplash::className() const
{
    return "frmSplash";
}

QMetaObject *frmSplash::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frmSplash( "frmSplash", &frmSplash::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frmSplash::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmSplash", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frmSplash::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmSplash", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frmSplash::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_0 = {"frmSplash_destroyed", 1, param_slot_0 };
    static const QUMethod slot_1 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "frmSplash_destroyed(QObject*)", &slot_0, QMetaData::Public },
	{ "languageChange()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frmSplash", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frmSplash.setMetaObject( metaObj );
    return metaObj;
}

void* frmSplash::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frmSplash" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool frmSplash::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: frmSplash_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 1: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frmSplash::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frmSplash::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool frmSplash::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
