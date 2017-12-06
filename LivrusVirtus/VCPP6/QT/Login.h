/****************************************************************************
** Form interface generated from reading ui file 'Login.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMLOGIN_H
#define FRMLOGIN_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class frmLogin : public QDialog
{
    Q_OBJECT

public:
    frmLogin( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~frmLogin();

    QLabel* textLabel15;
    QLabel* labSenha;
    QLabel* labLogin;
    QLineEdit* edtLogin;
    QLineEdit* edtSenha;
    QPushButton* btkLogin;
    QPushButton* btkCancelar;

public slots:
    virtual void btkLogin_clicked();
    virtual void btkCancelar_clicked();

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMLOGIN_H
