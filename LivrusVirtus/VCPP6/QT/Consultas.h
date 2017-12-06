/****************************************************************************
** Form interface generated from reading ui file 'Consultas.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMCONSULTAS_H
#define FRMCONSULTAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QLabel;
class QLineEdit;
class QPushButton;
class QTable;

class frmConsultas : public QWidget
{
    Q_OBJECT

public:
    frmConsultas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~frmConsultas();

    QFrame* frame1;
    QLabel* labDescricao;
    QLineEdit* edtDescricao;
    QPushButton* btnPesquisar;
    QTable* gridConsulta;
    QFrame* frame2;
    QPushButton* btnLimpar;
    QPushButton* btnFechar;
    QLabel* labRegistros;

public slots:
    virtual void btnPesquisar_clicked();
    virtual void btnLimpar_clicked();
    virtual void btnFechar_clicked();
    virtual void frmConsultas_destroyed( QObject * );

protected:
    QVBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // FRMCONSULTAS_H
