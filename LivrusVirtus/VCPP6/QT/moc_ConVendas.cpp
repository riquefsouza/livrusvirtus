/****************************************************************************
** frmConVendas meta object code from reading C++ file 'ConVendas.h'
**
** Created: seg 13. dez 22:12:03 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "ConVendas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frmConVendas::className() const
{
    return "frmConVendas";
}

QMetaObject *frmConVendas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frmConVendas( "frmConVendas", &frmConVendas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frmConVendas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmConVendas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frmConVendas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmConVendas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frmConVendas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_0 = {"frmConVendas_destroyed", 1, param_slot_0 };
    static const QUMethod slot_1 = {"edtCPF_lostFocus", 0, 0 };
    static const QUMethod slot_2 = {"btnPCliente_clicked", 0, 0 };
    static const QUMethod slot_3 = {"edtISBN_lostFocus", 0, 0 };
    static const QUMethod slot_4 = {"btnPLivro_clicked", 0, 0 };
    static const QUMethod slot_5 = {"btnLimpar_clicked", 0, 0 };
    static const QUMethod slot_6 = {"btnFechar_clicked", 0, 0 };
    static const QUMethod slot_7 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "frmConVendas_destroyed(QObject*)", &slot_0, QMetaData::Public },
	{ "edtCPF_lostFocus()", &slot_1, QMetaData::Public },
	{ "btnPCliente_clicked()", &slot_2, QMetaData::Public },
	{ "edtISBN_lostFocus()", &slot_3, QMetaData::Public },
	{ "btnPLivro_clicked()", &slot_4, QMetaData::Public },
	{ "btnLimpar_clicked()", &slot_5, QMetaData::Public },
	{ "btnFechar_clicked()", &slot_6, QMetaData::Public },
	{ "languageChange()", &slot_7, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frmConVendas", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frmConVendas.setMetaObject( metaObj );
    return metaObj;
}

void* frmConVendas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frmConVendas" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool frmConVendas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: frmConVendas_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 1: edtCPF_lostFocus(); break;
    case 2: btnPCliente_clicked(); break;
    case 3: edtISBN_lostFocus(); break;
    case 4: btnPLivro_clicked(); break;
    case 5: btnLimpar_clicked(); break;
    case 6: btnFechar_clicked(); break;
    case 7: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frmConVendas::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frmConVendas::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool frmConVendas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
