/****************************************************************************
** Form interface generated from reading ui file 'AlterarSenha.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMALTERARSENHA_H
#define FRMALTERARSENHA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class frmAlterarSenha : public QWidget
{
    Q_OBJECT

public:
    frmAlterarSenha( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~frmAlterarSenha();

    QLabel* labLogin;
    QLineEdit* edtLogin;
    QLabel* labNovaSenha;
    QLineEdit* edtNovaSenha;
    QLineEdit* edtConfirmarSenha;
    QLabel* labConfirmarSenha;
    QLineEdit* edtSenhaAtual;
    QLabel* labSenhaAtual;
    QPushButton* btnSalvar;
    QPushButton* btnLimpar;
    QPushButton* btnFechar;

public slots:
    virtual void btnSalvar_clicked();
    virtual void btnLimpar_clicked();
    virtual void btnFechar_clicked();
    virtual void frmAlterarSenha_destroyed( QObject * );

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMALTERARSENHA_H
