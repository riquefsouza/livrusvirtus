#ifndef PRINCIPAL_H
#define PRINCIPAL_H

class CfrmPrincipal : public FXMainWindow {
  FXDECLARE(CfrmPrincipal)

public:
  enum { MNU_CAD_ASSUNTOS = FXMainWindow::ID_LAST, MNU_CAD_AUTORES, 
  MNU_CAD_EDITORAS, MNU_CAD_ENDERECOS, MNU_CAD_IDIOMAS, MNU_CAD_PAISES, 
  MNU_CAD_PROFISSOES, MNU_CAD_CLIENTES, MNU_CAD_LIVROS, MNU_CON_ASSUNTOS, 
  MNU_CON_AUTORES, MNU_CON_EDITORAS, MNU_CON_ENDERECOS, MNU_CON_IDIOMAS, 
  MNU_CON_PAISES, MNU_CON_PROFISSOES, MNU_CON_CLIENTES, MNU_CON_LIVROS,	
  MNU_VEN_VENDERLIVROS,	MNU_VEN_VENDASREALIZADAS, MNU_JAN_LADOALADO_HORZ, 
  MNU_JAN_LADOALADO_VERT, MNU_JAN_EM_CASCATA, MNU_JAN_ORGANIZAR_ICONES, 
  MNU_OP_ALTERARSENHA, MNU_OP_SOBRE, MNU_OP_SAIR };

  FXLabel           *labStatus;
  FXStatusBar       *barraStatus;
  FXButton          *tlbCliente;
  FXButton          *tlbLivro;
  FXButton          *tlbVenda;
  FXButton          *tlbSobre;
  FXButton          *tlbSair;
  FXMenuCommand     *mnuCadAssuntos;
  FXMenuCommand     *mnuCadAutores;
  FXMenuCommand     *mnuCadEditoras;
  FXMenuCommand     *mnuCadEnderecos;
  FXMenuCommand     *mnuCadIdiomas;
  FXMenuCommand     *mnuCadPaises;
  FXMenuCommand     *mnuCadProfissoes;
  FXMenuCommand     *mnuCadClientes;
  FXMenuCommand     *mnuCadLivros;
  FXMenuCommand     *mnuVenderLivros;
  FXMenuCommand     *mnuVendasRealizadas;
  FXMenuCommand     *mnuAlterarSenha;

  CfrmPrincipal(FXApp* app);
  virtual void create();
  virtual ~CfrmPrincipal();
  long onCmdCadAssuntos(FXObject*,FXSelector,void*);
  long onCmdCadAutores(FXObject*,FXSelector,void*);
  long onCmdCadEditoras(FXObject*,FXSelector,void*);
  long onCmdCadEnderecos(FXObject*,FXSelector,void*);
  long onCmdCadIdiomas(FXObject*,FXSelector,void*);
  long onCmdCadPaises(FXObject*,FXSelector,void*);
  long onCmdCadProfissoes(FXObject*,FXSelector,void*);
  long onCmdCadClientes(FXObject*,FXSelector,void*);
  long onCmdCadLivros(FXObject*,FXSelector,void*);
  long onCmdConAssuntos(FXObject*,FXSelector,void*);
  long onCmdConAutores(FXObject*,FXSelector,void*);
  long onCmdConEditoras(FXObject*,FXSelector,void*);
  long onCmdConEnderecos(FXObject*,FXSelector,void*);
  long onCmdConIdiomas(FXObject*,FXSelector,void*);
  long onCmdConPaises(FXObject*,FXSelector,void*);
  long onCmdConProfissoes(FXObject*,FXSelector,void*);
  long onCmdConClientes(FXObject*,FXSelector,void*);
  long onCmdConLivros(FXObject*,FXSelector,void*);
  long onCmdVenderLivros(FXObject*,FXSelector,void*);
  long onCmdVendasRealizadas(FXObject*,FXSelector,void*);
  long onCmdOpAlterarSenha(FXObject*,FXSelector,void*);
  long onCmdOpSobre(FXObject*,FXSelector,void*);
  long onCmdOpSair(FXObject*,FXSelector,void*);

protected:
  FXMenuBar         *barraMenu;
  FXMDIClient       *clienteMDI;
  FXMDIMenu         *mnuMDI;
  FXToolBar         *barraFerra;
  FXHorizontalFrame *frameStatus;
  FXMenuPane        *mnuCadastros;
  FXMenuPane        *mnuPesquisas;
  FXMenuPane        *mnuVendas;
  FXMenuPane        *mnuOpcoes;
  FXMenuPane        *mnuJanelas;
  FXFont            *fonteSistema;
  FXIcon            *iconeMDI;
  FXIcon            *bmpCliente;
  FXIcon            *bmpLivro;
  FXIcon            *bmpLivros;
  FXIcon            *bmpSobre;
  FXIcon            *bmpSair;
 

private:
  CfrmPrincipal(){}

  void IniciaControles();
};

extern CfrmPrincipal *frmPrincipal;

#endif
