/****************************************************************************
** Form interface generated from reading ui file 'Cadastros.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMCADASTROS_H
#define FRMCADASTROS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QPushButton;
class QLineEdit;

class frmCadastros : public QWidget
{
    Q_OBJECT

public:
    frmCadastros( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~frmCadastros();

    QLabel* labCodigo;
    QLabel* labDescricao;
    QPushButton* btnNovo;
    QPushButton* btnPesquisar;
    QPushButton* btnLimpar;
    QPushButton* btnFechar;
    QLineEdit* edtCodigo;
    QLineEdit* edtDescricao;
    QPushButton* btnAnterior;
    QPushButton* btnProximo;
    QPushButton* btnExcluir;
    QPushButton* btnSalvar;

public slots:
    virtual void btnNovo_clicked();
    virtual void btnPesquisar_clicked();
    virtual void btnAnterior_clicked();
    virtual void btnProximo_clicked();
    virtual void btnSalvar_clicked();
    virtual void btnExcluir_clicked();
    virtual void btnLimpar_clicked();
    virtual void btnFechar_clicked();
    virtual void edtCodigo_lostFocus();
    virtual void frmCadastros_destroyed( QObject * );

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMCADASTROS_H
