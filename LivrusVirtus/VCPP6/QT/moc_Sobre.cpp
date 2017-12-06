/****************************************************************************
** frmSobre meta object code from reading C++ file 'Sobre.h'
**
** Created: seg 13. dez 22:12:01 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "Sobre.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frmSobre::className() const
{
    return "frmSobre";
}

QMetaObject *frmSobre::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frmSobre( "frmSobre", &frmSobre::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frmSobre::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmSobre", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frmSobre::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmSobre", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frmSobre::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"btkOk_clicked", 0, 0 };
    static const QUMethod slot_1 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "btkOk_clicked()", &slot_0, QMetaData::Public },
	{ "languageChange()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frmSobre", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frmSobre.setMetaObject( metaObj );
    return metaObj;
}

void* frmSobre::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frmSobre" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool frmSobre::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: btkOk_clicked(); break;
    case 1: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frmSobre::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frmSobre::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool frmSobre::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
