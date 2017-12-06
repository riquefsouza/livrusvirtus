/****************************************************************************
** frmCadLivros meta object code from reading C++ file 'CadLivros.h'
**
** Created: seg 13. dez 22:12:02 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "CadLivros.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frmCadLivros::className() const
{
    return "frmCadLivros";
}

QMetaObject *frmCadLivros::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frmCadLivros( "frmCadLivros", &frmCadLivros::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frmCadLivros::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmCadLivros", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frmCadLivros::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmCadLivros", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frmCadLivros::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"edtISBN_lostFocus", 0, 0 };
    static const QUMethod slot_1 = {"btnNovo_clicked", 0, 0 };
    static const QUMethod slot_2 = {"edtCodEditora_lostFocus", 0, 0 };
    static const QUMethod slot_3 = {"btnPEditora_clicked", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_4 = {"frmCadLivros_destroyed", 1, param_slot_4 };
    static const QUMethod slot_5 = {"edtCodAssunto_lostFocus", 0, 0 };
    static const QUMethod slot_6 = {"btnAdAssuntos_clicked", 0, 0 };
    static const QUMethod slot_7 = {"btnPAssunto_clicked", 0, 0 };
    static const QUMethod slot_8 = {"edtPreco_lostFocus", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod slot_9 = {"lstAssuntos_doubleClicked", 1, param_slot_9 };
    static const QUMethod slot_10 = {"edtCodAutor_lostFocus", 0, 0 };
    static const QUMethod slot_11 = {"btnAdAutores_clicked", 0, 0 };
    static const QUMethod slot_12 = {"btnPAutor_clicked", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod slot_13 = {"lstAutores_doubleClicked", 1, param_slot_13 };
    static const QUMethod slot_14 = {"btnPesquisar_clicked", 0, 0 };
    static const QUMethod slot_15 = {"btnAnterior_clicked", 0, 0 };
    static const QUMethod slot_16 = {"btnProximo_clicked", 0, 0 };
    static const QUMethod slot_17 = {"btnSalvar_clicked", 0, 0 };
    static const QUMethod slot_18 = {"btnExcluir_clicked", 0, 0 };
    static const QUMethod slot_19 = {"btnLimpar_clicked", 0, 0 };
    static const QUMethod slot_20 = {"btnFechar_clicked", 0, 0 };
    static const QUMethod slot_21 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "edtISBN_lostFocus()", &slot_0, QMetaData::Public },
	{ "btnNovo_clicked()", &slot_1, QMetaData::Public },
	{ "edtCodEditora_lostFocus()", &slot_2, QMetaData::Public },
	{ "btnPEditora_clicked()", &slot_3, QMetaData::Public },
	{ "frmCadLivros_destroyed(QObject*)", &slot_4, QMetaData::Public },
	{ "edtCodAssunto_lostFocus()", &slot_5, QMetaData::Public },
	{ "btnAdAssuntos_clicked()", &slot_6, QMetaData::Public },
	{ "btnPAssunto_clicked()", &slot_7, QMetaData::Public },
	{ "edtPreco_lostFocus()", &slot_8, QMetaData::Public },
	{ "lstAssuntos_doubleClicked(QListBoxItem*)", &slot_9, QMetaData::Public },
	{ "edtCodAutor_lostFocus()", &slot_10, QMetaData::Public },
	{ "btnAdAutores_clicked()", &slot_11, QMetaData::Public },
	{ "btnPAutor_clicked()", &slot_12, QMetaData::Public },
	{ "lstAutores_doubleClicked(QListBoxItem*)", &slot_13, QMetaData::Public },
	{ "btnPesquisar_clicked()", &slot_14, QMetaData::Public },
	{ "btnAnterior_clicked()", &slot_15, QMetaData::Public },
	{ "btnProximo_clicked()", &slot_16, QMetaData::Public },
	{ "btnSalvar_clicked()", &slot_17, QMetaData::Public },
	{ "btnExcluir_clicked()", &slot_18, QMetaData::Public },
	{ "btnLimpar_clicked()", &slot_19, QMetaData::Public },
	{ "btnFechar_clicked()", &slot_20, QMetaData::Public },
	{ "languageChange()", &slot_21, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frmCadLivros", parentObject,
	slot_tbl, 22,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frmCadLivros.setMetaObject( metaObj );
    return metaObj;
}

void* frmCadLivros::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frmCadLivros" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool frmCadLivros::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: edtISBN_lostFocus(); break;
    case 1: btnNovo_clicked(); break;
    case 2: edtCodEditora_lostFocus(); break;
    case 3: btnPEditora_clicked(); break;
    case 4: frmCadLivros_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 5: edtCodAssunto_lostFocus(); break;
    case 6: btnAdAssuntos_clicked(); break;
    case 7: btnPAssunto_clicked(); break;
    case 8: edtPreco_lostFocus(); break;
    case 9: lstAssuntos_doubleClicked((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 10: edtCodAutor_lostFocus(); break;
    case 11: btnAdAutores_clicked(); break;
    case 12: btnPAutor_clicked(); break;
    case 13: lstAutores_doubleClicked((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 14: btnPesquisar_clicked(); break;
    case 15: btnAnterior_clicked(); break;
    case 16: btnProximo_clicked(); break;
    case 17: btnSalvar_clicked(); break;
    case 18: btnExcluir_clicked(); break;
    case 19: btnLimpar_clicked(); break;
    case 20: btnFechar_clicked(); break;
    case 21: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frmCadLivros::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frmCadLivros::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool frmCadLivros::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
