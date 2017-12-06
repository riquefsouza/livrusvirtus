/****************************************************************************
** Form interface generated from reading ui file 'Sobre.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMSOBRE_H
#define FRMSOBRE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QPushButton;

class frmSobre : public QDialog
{
    Q_OBJECT

public:
    frmSobre( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~frmSobre();

    QGroupBox* groupBox1;
    QLabel* labVersao;
    QLabel* labDireitos;
    QLabel* labSistema;
    QLabel* labFigura;
    QPushButton* btkOk;

public slots:
    virtual void btkOk_clicked();

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMSOBRE_H
