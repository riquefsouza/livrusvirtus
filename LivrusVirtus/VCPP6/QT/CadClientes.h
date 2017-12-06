/****************************************************************************
** Form interface generated from reading ui file 'CadClientes.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMCADCLIENTES_H
#define FRMCADCLIENTES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QDateEdit;
class QButtonGroup;
class QRadioButton;
class QGroupBox;
class QPushButton;

class frmCadClientes : public QWidget
{
    Q_OBJECT

public:
    frmCadClientes( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~frmCadClientes();

    QLabel* labNome;
    QLabel* labCPF;
    QLineEdit* edtEmail;
    QLineEdit* edtNome;
    QLabel* labIdentidade;
    QLineEdit* edtIdentidade;
    QLabel* labDtNascimento;
    QLabel* labTelefone;
    QLineEdit* edtTelefone;
    QDateEdit* edtDtNascimento;
    QButtonGroup* grpSexo;
    QRadioButton* rbFeminino;
    QRadioButton* rbMasculino;
    QGroupBox* grpEndereco;
    QLabel* labBairro;
    QLabel* labEstado;
    QLineEdit* edtLogradouro;
    QLineEdit* edtEstado;
    QLineEdit* edtBairro;
    QLabel* labLogradouro;
    QLabel* labCEP;
    QLineEdit* edtCEP;
    QLineEdit* edtCidade;
    QLabel* labCidade;
    QLineEdit* edtCodEndereco;
    QPushButton* btnPEndereco;
    QLabel* labEmail;
    QLabel* labCodPais;
    QLineEdit* edtPais;
    QLineEdit* edtProfissao;
    QLineEdit* edtCPF;
    QPushButton* btnNovo;
    QPushButton* btnPesquisar;
    QPushButton* btnAnterior;
    QPushButton* btnProximo;
    QLineEdit* edtCodPais;
    QPushButton* btnPPais;
    QPushButton* btnPProfissao;
    QPushButton* btnSalvar;
    QPushButton* btnExcluir;
    QPushButton* btnLimpar;
    QPushButton* btnFechar;
    QLabel* labCodProfissao;
    QLineEdit* edtCodProfissao;

public slots:
    virtual void edtCPF_lostFocus();
    virtual void btnNovo_clicked();
    virtual void btnPesquisar_clicked();
    virtual void btnAnterior_clicked();
    virtual void btnProximo_clicked();
    virtual void edtCodEndereco_lostFocus();
    virtual void btnPEndereco_clicked();
    virtual void edtCodPais_lostFocus();
    virtual void btnPPais_clicked();
    virtual void edtCodProfissao_lostFocus();
    virtual void btnPProfissao_clicked();
    virtual void btnSalvar_clicked();
    virtual void btnExcluir_clicked();
    virtual void btnLimpar_clicked();
    virtual void btnFechar_clicked();
    virtual void frmCadClientes_destroyed( QObject * );

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMCADCLIENTES_H
