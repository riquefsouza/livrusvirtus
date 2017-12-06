/****************************************************************************
** Form interface generated from reading ui file 'Principal.ui'
**
** Created: sáb 20. nov 20:10:02 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FRMPRINCIPAL_H
#define FRMPRINCIPAL_H

#include <qvariant.h>
#include <qmainwindow.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QAction;
class QActionGroup;
class QToolBar;
class QPopupMenu;
class QToolButton;

class frmPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    frmPrincipal( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
    ~frmPrincipal();

    QToolButton* tbClientes;
    QToolButton* tbLivros;
    QToolButton* tbVender;
    QToolButton* tbSobre;
    QToolButton* tbSair;
    QMenuBar *MenuBar;
    QPopupMenu *Cadastros;
    QPopupMenu *Pesquisas;
    QPopupMenu *Vendas;
    QPopupMenu *Janelas;
    QPopupMenu *Opes;
    QToolBar *toolBar;
    QAction* cadastrosAssuntosAction;
    QAction* cadastrosAutoresAction;
    QAction* cadastrosEditorasAction;
    QAction* cadastrosEnderecosAction;
    QAction* cadastrosIdiomasAction;
    QAction* cadastrosPaisesAction;
    QAction* cadastrosProfissoesAction;
    QAction* cadastrosClientesAction;
    QAction* cadastrosLivrosAction;
    QAction* pesquisasAssuntosAction;
    QAction* pesquisasAutoresAction;
    QAction* pesquisasEditorasAction;
    QAction* pesquisasEnderecosAction;
    QAction* pesquisasIdiomasAction;
    QAction* pesquisasPaisesAction;
    QAction* pesquisasProfissoesAction;
    QAction* pesquisasClientesAction;
    QAction* pesquisasLivrosAction;
    QAction* vendasVenderLivrosAction;
    QAction* vendasVendas_RealizadasAction;
    QAction* janelasLadoaladohorizontalAction;
    QAction* janelasLadoaladoverticalAction;
    QAction* janelasEmcascataAction;
    QAction* opcoesAlterarSenhaAction;
    QAction* opcoesSobreAction;
    QAction* opcoesSairAction;
    QAction* janelasOrganizarIconesAction;

public slots:
    virtual void cadastrosAssuntosAction_activated();
    virtual void cadastrosAutoresAction_activated();
    virtual void cadastrosEditorasAction_activated();
    virtual void cadastrosEnderecosAction_activated();
    virtual void cadastrosIdiomasAction_activated();
    virtual void cadastrosPaisesAction_activated();
    virtual void cadastrosProfissoesAction_activated();
    virtual void cadastrosClientesAction_activated();
    virtual void cadastrosLivrosAction_activated();

protected:

protected slots:
    virtual void languageChange();

};

#endif // FRMPRINCIPAL_H
