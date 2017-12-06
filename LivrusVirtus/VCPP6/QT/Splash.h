/****************************************************************************
** Form interface generated from reading ui file 'Splash.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMSPLASH_H
#define FRMSPLASH_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;

class frmSplash : public QDialog
{
    Q_OBJECT

public:
    frmSplash( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~frmSplash();

    QLabel* pixmapLabel1;

public slots:
    virtual void frmSplash_destroyed( QObject * );

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMSPLASH_H
