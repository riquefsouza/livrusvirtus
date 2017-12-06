/****************************************************************************
** frmAlterarSenha meta object code from reading C++ file 'AlterarSenha.h'
**
** Created: seg 13. dez 22:12:01 2004
**      by: The Qt MOC ($Id: $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "AlterarSenha.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frmAlterarSenha::className() const
{
    return "frmAlterarSenha";
}

QMetaObject *frmAlterarSenha::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frmAlterarSenha( "frmAlterarSenha", &frmAlterarSenha::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frmAlterarSenha::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmAlterarSenha", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frmAlterarSenha::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frmAlterarSenha", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frmAlterarSenha::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"btnSalvar_clicked", 0, 0 };
    static const QUMethod slot_1 = {"btnLimpar_clicked", 0, 0 };
    static const QUMethod slot_2 = {"btnFechar_clicked", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_3 = {"frmAlterarSenha_destroyed", 1, param_slot_3 };
    static const QUMethod slot_4 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "btnSalvar_clicked()", &slot_0, QMetaData::Public },
	{ "btnLimpar_clicked()", &slot_1, QMetaData::Public },
	{ "btnFechar_clicked()", &slot_2, QMetaData::Public },
	{ "frmAlterarSenha_destroyed(QObject*)", &slot_3, QMetaData::Public },
	{ "languageChange()", &slot_4, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frmAlterarSenha", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frmAlterarSenha.setMetaObject( metaObj );
    return metaObj;
}

void* frmAlterarSenha::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frmAlterarSenha" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool frmAlterarSenha::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: btnSalvar_clicked(); break;
    case 1: btnLimpar_clicked(); break;
    case 2: btnFechar_clicked(); break;
    case 3: frmAlterarSenha_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 4: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frmAlterarSenha::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frmAlterarSenha::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool frmAlterarSenha::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
