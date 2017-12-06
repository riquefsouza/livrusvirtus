/****************************************************************************
** Form interface generated from reading ui file 'VenderLivros.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMVENDERLIVROS_H
#define FRMVENDERLIVROS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QListBox;
class QListBoxItem;

class frmVenderLivros : public QWidget
{
    Q_OBJECT

public:
    frmVenderLivros( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~frmVenderLivros();

    QLabel* labDtHrVenda;
    QLineEdit* edtCliente;
    QLabel* labCliente;
    QLineEdit* edtPrecoTotal;
    QLabel* labCPF;
    QLabel* labLivro;
    QLabel* labPrecoTotal;
    QLabel* labISBN;
    QLineEdit* edtLivro;
    QLabel* labCodAssunto_2_2;
    QLineEdit* edtDtHrVenda;
    QLineEdit* edtCPF;
    QPushButton* btnPCliente;
    QLineEdit* edtISBN;
    QPushButton* btnAdLivros;
    QPushButton* btnPLivro;
    QListBox* lstLivros;
    QPushButton* btnVender;
    QPushButton* btnLimpar;
    QPushButton* btnFechar;

public slots:
    virtual void frmVenderLivros_destroyed( QObject * );
    virtual void edtCPF_lostFocus();
    virtual void btnPCliente_clicked();
    virtual void edtISBN_lostFocus();
    virtual void btnAdLivros_clicked();
    virtual void btnPLivro_clicked();
    virtual void lstLivros_doubleClicked( QListBoxItem * );
    virtual void btnVender_clicked();
    virtual void btnLimpar_clicked();
    virtual void btnFechar_clicked();

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMVENDERLIVROS_H
