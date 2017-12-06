/****************************************************************************
** frmLogin meta object code from reading C++ file 'Login.h'
**
** Created: seg 13. dez 22:12:03 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "Login.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frmLogin::className() const
{
    return "frmLogin";
}

QMetaObject *frmLogin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frmLogin( "frmLogin", &frmLogin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frmLogin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmLogin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frmLogin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmLogin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frmLogin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"btkLogin_clicked", 0, 0 };
    static const QUMethod slot_1 = {"btkCancelar_clicked", 0, 0 };
    static const QUMethod slot_2 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "btkLogin_clicked()", &slot_0, QMetaData::Public },
	{ "btkCancelar_clicked()", &slot_1, QMetaData::Public },
	{ "languageChange()", &slot_2, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frmLogin", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frmLogin.setMetaObject( metaObj );
    return metaObj;
}

void* frmLogin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frmLogin" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool frmLogin::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: btkLogin_clicked(); break;
    case 1: btkCancelar_clicked(); break;
    case 2: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frmLogin::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frmLogin::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool frmLogin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
