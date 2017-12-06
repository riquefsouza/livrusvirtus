/****************************************************************************
** Form interface generated from reading ui file 'ConVendas.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMCONVENDAS_H
#define FRMCONVENDAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLineEdit;
class QLabel;
class QTable;
class QDateTimeEdit;
class QPushButton;

class frmConVendas : public QWidget
{
    Q_OBJECT

public:
    frmConVendas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~frmConVendas();

    QLineEdit* edtPrecoTotal;
    QLabel* labDtHrVenda;
    QLabel* labPrecoTotal;
    QLabel* labCPF;
    QLabel* labISBN;
    QLabel* labLivro;
    QLabel* labCliente;
    QLineEdit* edtCliente;
    QLineEdit* edtLivro;
    QLabel* labRegistros;
    QTable* table5;
    QDateTimeEdit* edtDtHrVenda;
    QPushButton* btnPesquisar;
    QLineEdit* edtCPF;
    QPushButton* btnPCliente;
    QLineEdit* edtISBN;
    QPushButton* btnPLivro;
    QPushButton* btnLimpar;
    QPushButton* btnFechar;

public slots:
    virtual void frmConVendas_destroyed( QObject * );
    virtual void edtCPF_lostFocus();
    virtual void btnPCliente_clicked();
    virtual void edtISBN_lostFocus();
    virtual void btnPLivro_clicked();
    virtual void btnLimpar_clicked();
    virtual void btnFechar_clicked();

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMCONVENDAS_H
