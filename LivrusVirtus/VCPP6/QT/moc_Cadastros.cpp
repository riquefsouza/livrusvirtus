/****************************************************************************
** frmCadastros meta object code from reading C++ file 'Cadastros.h'
**
** Created: seg 13. dez 22:12:01 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "Cadastros.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frmCadastros::className() const
{
    return "frmCadastros";
}

QMetaObject *frmCadastros::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frmCadastros( "frmCadastros", &frmCadastros::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frmCadastros::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmCadastros", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frmCadastros::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmCadastros", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frmCadastros::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"btnNovo_clicked", 0, 0 };
    static const QUMethod slot_1 = {"btnPesquisar_clicked", 0, 0 };
    static const QUMethod slot_2 = {"btnAnterior_clicked", 0, 0 };
    static const QUMethod slot_3 = {"btnProximo_clicked", 0, 0 };
    static const QUMethod slot_4 = {"btnSalvar_clicked", 0, 0 };
    static const QUMethod slot_5 = {"btnExcluir_clicked", 0, 0 };
    static const QUMethod slot_6 = {"btnLimpar_clicked", 0, 0 };
    static const QUMethod slot_7 = {"btnFechar_clicked", 0, 0 };
    static const QUMethod slot_8 = {"edtCodigo_lostFocus", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_9 = {"frmCadastros_destroyed", 1, param_slot_9 };
    static const QUMethod slot_10 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "btnNovo_clicked()", &slot_0, QMetaData::Public },
	{ "btnPesquisar_clicked()", &slot_1, QMetaData::Public },
	{ "btnAnterior_clicked()", &slot_2, QMetaData::Public },
	{ "btnProximo_clicked()", &slot_3, QMetaData::Public },
	{ "btnSalvar_clicked()", &slot_4, QMetaData::Public },
	{ "btnExcluir_clicked()", &slot_5, QMetaData::Public },
	{ "btnLimpar_clicked()", &slot_6, QMetaData::Public },
	{ "btnFechar_clicked()", &slot_7, QMetaData::Public },
	{ "edtCodigo_lostFocus()", &slot_8, QMetaData::Public },
	{ "frmCadastros_destroyed(QObject*)", &slot_9, QMetaData::Public },
	{ "languageChange()", &slot_10, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frmCadastros", parentObject,
	slot_tbl, 11,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frmCadastros.setMetaObject( metaObj );
    return metaObj;
}

void* frmCadastros::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frmCadastros" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool frmCadastros::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: btnNovo_clicked(); break;
    case 1: btnPesquisar_clicked(); break;
    case 2: btnAnterior_clicked(); break;
    case 3: btnProximo_clicked(); break;
    case 4: btnSalvar_clicked(); break;
    case 5: btnExcluir_clicked(); break;
    case 6: btnLimpar_clicked(); break;
    case 7: btnFechar_clicked(); break;
    case 8: edtCodigo_lostFocus(); break;
    case 9: frmCadastros_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 10: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frmCadastros::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frmCadastros::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool frmCadastros::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
