/****************************************************************************
** frmVenderLivros meta object code from reading C++ file 'VenderLivros.h'
**
** Created: seg 13. dez 22:12:02 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "VenderLivros.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frmVenderLivros::className() const
{
    return "frmVenderLivros";
}

QMetaObject *frmVenderLivros::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frmVenderLivros( "frmVenderLivros", &frmVenderLivros::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frmVenderLivros::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmVenderLivros", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frmVenderLivros::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmVenderLivros", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frmVenderLivros::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_0 = {"frmVenderLivros_destroyed", 1, param_slot_0 };
    static const QUMethod slot_1 = {"edtCPF_lostFocus", 0, 0 };
    static const QUMethod slot_2 = {"btnPCliente_clicked", 0, 0 };
    static const QUMethod slot_3 = {"edtISBN_lostFocus", 0, 0 };
    static const QUMethod slot_4 = {"btnAdLivros_clicked", 0, 0 };
    static const QUMethod slot_5 = {"btnPLivro_clicked", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod slot_6 = {"lstLivros_doubleClicked", 1, param_slot_6 };
    static const QUMethod slot_7 = {"btnVender_clicked", 0, 0 };
    static const QUMethod slot_8 = {"btnLimpar_clicked", 0, 0 };
    static const QUMethod slot_9 = {"btnFechar_clicked", 0, 0 };
    static const QUMethod slot_10 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "frmVenderLivros_destroyed(QObject*)", &slot_0, QMetaData::Public },
	{ "edtCPF_lostFocus()", &slot_1, QMetaData::Public },
	{ "btnPCliente_clicked()", &slot_2, QMetaData::Public },
	{ "edtISBN_lostFocus()", &slot_3, QMetaData::Public },
	{ "btnAdLivros_clicked()", &slot_4, QMetaData::Public },
	{ "btnPLivro_clicked()", &slot_5, QMetaData::Public },
	{ "lstLivros_doubleClicked(QListBoxItem*)", &slot_6, QMetaData::Public },
	{ "btnVender_clicked()", &slot_7, QMetaData::Public },
	{ "btnLimpar_clicked()", &slot_8, QMetaData::Public },
	{ "btnFechar_clicked()", &slot_9, QMetaData::Public },
	{ "languageChange()", &slot_10, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frmVenderLivros", parentObject,
	slot_tbl, 11,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frmVenderLivros.setMetaObject( metaObj );
    return metaObj;
}

void* frmVenderLivros::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frmVenderLivros" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool frmVenderLivros::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: frmVenderLivros_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 1: edtCPF_lostFocus(); break;
    case 2: btnPCliente_clicked(); break;
    case 3: edtISBN_lostFocus(); break;
    case 4: btnAdLivros_clicked(); break;
    case 5: btnPLivro_clicked(); break;
    case 6: lstLivros_doubleClicked((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 7: btnVender_clicked(); break;
    case 8: btnLimpar_clicked(); break;
    case 9: btnFechar_clicked(); break;
    case 10: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frmVenderLivros::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frmVenderLivros::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool frmVenderLivros::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
