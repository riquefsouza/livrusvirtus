/****************************************************************************
** PlivrusqtView meta object code from reading C++ file 'plivrusqtview.h'
**
** Created: Sat Jan 1 16:31:10 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.1.1   edited Dec 9 10:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "plivrusqtview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PlivrusqtView::className() const
{
    return "PlivrusqtView";
}

QMetaObject *PlivrusqtView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PlivrusqtView( "PlivrusqtView", &PlivrusqtView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PlivrusqtView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PlivrusqtView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PlivrusqtView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PlivrusqtView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PlivrusqtView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"PlivrusqtView", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PlivrusqtView.setMetaObject( metaObj );
    return metaObj;
}

void* PlivrusqtView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PlivrusqtView" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool PlivrusqtView::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool PlivrusqtView::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PlivrusqtView::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool PlivrusqtView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
