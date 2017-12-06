/****************************************************************************
** frmCadClientes meta object code from reading C++ file 'CadClientes.h'
**
** Created: seg 13. dez 22:12:02 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "CadClientes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frmCadClientes::className() const
{
    return "frmCadClientes";
}

QMetaObject *frmCadClientes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frmCadClientes( "frmCadClientes", &frmCadClientes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frmCadClientes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmCadClientes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frmCadClientes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmCadClientes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frmCadClientes::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"edtCPF_lostFocus", 0, 0 };
    static const QUMethod slot_1 = {"btnNovo_clicked", 0, 0 };
    static const QUMethod slot_2 = {"btnPesquisar_clicked", 0, 0 };
    static const QUMethod slot_3 = {"btnAnterior_clicked", 0, 0 };
    static const QUMethod slot_4 = {"btnProximo_clicked", 0, 0 };
    static const QUMethod slot_5 = {"edtCodEndereco_lostFocus", 0, 0 };
    static const QUMethod slot_6 = {"btnPEndereco_clicked", 0, 0 };
    static const QUMethod slot_7 = {"edtCodPais_lostFocus", 0, 0 };
    static const QUMethod slot_8 = {"btnPPais_clicked", 0, 0 };
    static const QUMethod slot_9 = {"edtCodProfissao_lostFocus", 0, 0 };
    static const QUMethod slot_10 = {"btnPProfissao_clicked", 0, 0 };
    static const QUMethod slot_11 = {"btnSalvar_clicked", 0, 0 };
    static const QUMethod slot_12 = {"btnExcluir_clicked", 0, 0 };
    static const QUMethod slot_13 = {"btnLimpar_clicked", 0, 0 };
    static const QUMethod slot_14 = {"btnFechar_clicked", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_15 = {"frmCadClientes_destroyed", 1, param_slot_15 };
    static const QUMethod slot_16 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "edtCPF_lostFocus()", &slot_0, QMetaData::Public },
	{ "btnNovo_clicked()", &slot_1, QMetaData::Public },
	{ "btnPesquisar_clicked()", &slot_2, QMetaData::Public },
	{ "btnAnterior_clicked()", &slot_3, QMetaData::Public },
	{ "btnProximo_clicked()", &slot_4, QMetaData::Public },
	{ "edtCodEndereco_lostFocus()", &slot_5, QMetaData::Public },
	{ "btnPEndereco_clicked()", &slot_6, QMetaData::Public },
	{ "edtCodPais_lostFocus()", &slot_7, QMetaData::Public },
	{ "btnPPais_clicked()", &slot_8, QMetaData::Public },
	{ "edtCodProfissao_lostFocus()", &slot_9, QMetaData::Public },
	{ "btnPProfissao_clicked()", &slot_10, QMetaData::Public },
	{ "btnSalvar_clicked()", &slot_11, QMetaData::Public },
	{ "btnExcluir_clicked()", &slot_12, QMetaData::Public },
	{ "btnLimpar_clicked()", &slot_13, QMetaData::Public },
	{ "btnFechar_clicked()", &slot_14, QMetaData::Public },
	{ "frmCadClientes_destroyed(QObject*)", &slot_15, QMetaData::Public },
	{ "languageChange()", &slot_16, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frmCadClientes", parentObject,
	slot_tbl, 17,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frmCadClientes.setMetaObject( metaObj );
    return metaObj;
}

void* frmCadClientes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frmCadClientes" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool frmCadClientes::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: edtCPF_lostFocus(); break;
    case 1: btnNovo_clicked(); break;
    case 2: btnPesquisar_clicked(); break;
    case 3: btnAnterior_clicked(); break;
    case 4: btnProximo_clicked(); break;
    case 5: edtCodEndereco_lostFocus(); break;
    case 6: btnPEndereco_clicked(); break;
    case 7: edtCodPais_lostFocus(); break;
    case 8: btnPPais_clicked(); break;
    case 9: edtCodProfissao_lostFocus(); break;
    case 10: btnPProfissao_clicked(); break;
    case 11: btnSalvar_clicked(); break;
    case 12: btnExcluir_clicked(); break;
    case 13: btnLimpar_clicked(); break;
    case 14: btnFechar_clicked(); break;
    case 15: frmCadClientes_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 16: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frmCadClientes::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frmCadClientes::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool frmCadClientes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
