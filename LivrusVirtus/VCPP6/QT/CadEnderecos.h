/****************************************************************************
** Form interface generated from reading ui file 'CadEnderecos.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMCADENDERECOS_H
#define FRMCADENDERECOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QComboBox;

class frmCadEnderecos : public QWidget
{
    Q_OBJECT

public:
    frmCadEnderecos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~frmCadEnderecos();

    QLabel* labCodigo;
    QLabel* labEstado;
    QLineEdit* edtCodigo;
    QPushButton* btnPesquisar;
    QPushButton* btnLimpar;
    QPushButton* btnFechar;
    QPushButton* btnNovo;
    QPushButton* btnAnterior;
    QPushButton* btnProximo;
    QPushButton* btnExcluir;
    QPushButton* btnSalvar;
    QLineEdit* edtLogradouro;
    QLineEdit* edtBairro;
    QLabel* labCEP;
    QLineEdit* edtCEP;
    QLineEdit* edtCidade;
    QLabel* labCidade;
    QLabel* labLogradouro;
    QLabel* labBairro;
    QComboBox* cmbEstado;

public slots:
    virtual void edtCodigo_lostFocus();
    virtual void btnNovo_clicked();
    virtual void btnPesquisar_clicked();
    virtual void btnAnterior_clicked();
    virtual void btnProximo_clicked();
    virtual void btnSalvar_clicked();
    virtual void btnExcluir_clicked();
    virtual void btnLimpar_clicked();
    virtual void btnFechar_clicked();
    virtual void frmCadEnderecos_destroyed( QObject * );

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMCADENDERECOS_H
