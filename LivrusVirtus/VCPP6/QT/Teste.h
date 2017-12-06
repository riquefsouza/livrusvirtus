/****************************************************************************
** Form interface generated from reading ui file 'Teste.ui'
**
** Created: sáb 20. nov 20:02:39 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMTESTE_H
#define FRMTESTE_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QSqlDatabase;
class QSqlCursor;
class QSqlForm;
class QDataTable;
class QSqlRecord;
class QDataBrowser;
class QSpinBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QDataView;

class frmTeste : public QWidget
{
    Q_OBJECT

public:
    frmTeste( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~frmTeste();

    QDataTable* dataTable1;
    QDataBrowser* dataBrowser1;
    QSpinBox* QSpinBoxCodassunto;
    QLabel* labelCodassunto;
    QLabel* labelAssunto;
    QLineEdit* QLineEditAssunto;
    QPushButton* PushButtonFirst;
    QPushButton* PushButtonPrev;
    QPushButton* PushButtonNext;
    QPushButton* PushButtonLast;
    QPushButton* PushButtonInsert;
    QPushButton* PushButtonUpdate;
    QPushButton* PushButtonDelete;
    QDataView* dataView2;
    QLabel* labelCodassunto_2;
    QLabel* labelAssunto_2;
    QLineEdit* QLineEditAssunto_2;
    QSpinBox* QSpinBoxCodassunto_2;

    QSqlDatabase* ACLivrusConnection;

public slots:
    virtual void polish();

protected:
    QGridLayout* dataBrowser1Layout;
    QGridLayout* layout2;
    QHBoxLayout* layout3;
    QHBoxLayout* layout4;
    QGridLayout* dataView2Layout;
    QGridLayout* layout5;

protected slots:
    virtual void languageChange();

};

#endif // FRMTESTE_H
