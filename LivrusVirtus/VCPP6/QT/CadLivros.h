/****************************************************************************
** Form interface generated from reading ui file 'CadLivros.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMCADLIVROS_H
#define FRMCADLIVROS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QSpinBox;
class QComboBox;
class QPushButton;
class QListBox;
class QListBoxItem;

class frmCadLivros : public QWidget
{
    Q_OBJECT

public:
    frmCadLivros( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~frmCadLivros();

    QLabel* labISBN;
    QLabel* labTitulo;
    QLineEdit* edtTitulo;
    QLabel* labEdicao;
    QSpinBox* edtEdicao;
    QLineEdit* edtEditora;
    QLabel* labAnoPubli;
    QLabel* labVolume;
    QLabel* labIdioma;
    QSpinBox* edtVolume;
    QComboBox* cmbIdioma;
    QLabel* labCodEditora;
    QLabel* labPreco;
    QLabel* labNPaginas;
    QSpinBox* edtNPaginas;
    QLabel* labCodAssunto;
    QLineEdit* edtAssunto;
    QLabel* labQtdEstoque;
    QLabel* labCodAutor;
    QLineEdit* edtAutor;
    QSpinBox* edtQtdEstoque;
    QSpinBox* edtAnoPubli;
    QLineEdit* edtISBN;
    QPushButton* btnNovo;
    QLineEdit* edtCodEditora;
    QPushButton* btnPEditora;
    QLineEdit* edtCodAssunto;
    QPushButton* btnAdAssuntos;
    QPushButton* btnPAssunto;
    QLineEdit* edtPreco;
    QListBox* lstAssuntos;
    QLineEdit* edtCodAutor;
    QPushButton* btnAdAutores;
    QPushButton* btnPAutor;
    QListBox* lstAutores;
    QPushButton* btnPesquisar;
    QPushButton* btnAnterior;
    QPushButton* btnProximo;
    QPushButton* btnSalvar;
    QPushButton* btnExcluir;
    QPushButton* btnLimpar;
    QPushButton* btnFechar;

public slots:
    virtual void edtISBN_lostFocus();
    virtual void btnNovo_clicked();
    virtual void edtCodEditora_lostFocus();
    virtual void btnPEditora_clicked();
    virtual void frmCadLivros_destroyed( QObject * );
    virtual void edtCodAssunto_lostFocus();
    virtual void btnAdAssuntos_clicked();
    virtual void btnPAssunto_clicked();
    virtual void edtPreco_lostFocus();
    virtual void lstAssuntos_doubleClicked( QListBoxItem * );
    virtual void edtCodAutor_lostFocus();
    virtual void btnAdAutores_clicked();
    virtual void btnPAutor_clicked();
    virtual void lstAutores_doubleClicked( QListBoxItem * );
    virtual void btnPesquisar_clicked();
    virtual void btnAnterior_clicked();
    virtual void btnProximo_clicked();
    virtual void btnSalvar_clicked();
    virtual void btnExcluir_clicked();
    virtual void btnLimpar_clicked();
    virtual void btnFechar_clicked();

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMCADLIVROS_H
