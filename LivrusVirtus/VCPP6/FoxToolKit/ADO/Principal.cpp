#include "resource.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "CadAssuntos.h"
#include "CadAutores.h"
#include "CadEditoras.h"
#include "CadEnderecos.h"
#include "CadIdiomas.h"
#include "CadPaises.h"
#include "CadProfissoes.h"
#include "CadClientes.h"
#include "CadLivros.h"
#include "ConAssuntos.h"
#include "ConAutores.h"
#include "ConEditoras.h"
#include "ConEnderecos.h"
#include "ConIdiomas.h"
#include "ConPaises.h"
#include "ConProfissoes.h"
#include "ConClientes.h"
#include "ConLivros.h"
#include "VenderLivros.h"
#include "ConVendas.h"
#include "AlterarSenha.h"
#include "Sobre.h"

CfrmPrincipal *frmPrincipal = (CfrmPrincipal *) NULL;

FXDEFMAP(CfrmPrincipal) CfrmPrincipalMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CAD_ASSUNTOS, 
    CfrmPrincipal::onCmdCadAssuntos),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CAD_AUTORES, 
    CfrmPrincipal::onCmdCadAutores),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CAD_EDITORAS,  
    CfrmPrincipal::onCmdCadEditoras),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CAD_ENDERECOS,  
    CfrmPrincipal::onCmdCadEnderecos),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CAD_IDIOMAS,  
    CfrmPrincipal::onCmdCadIdiomas),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CAD_PAISES,  
    CfrmPrincipal::onCmdCadPaises),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CAD_PROFISSOES,  
    CfrmPrincipal::onCmdCadProfissoes),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CAD_CLIENTES,  
    CfrmPrincipal::onCmdCadClientes),

  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CAD_LIVROS, 
    CfrmPrincipal::onCmdCadLivros),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CON_ASSUNTOS,  
    CfrmPrincipal::onCmdConAssuntos),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CON_AUTORES,  
    CfrmPrincipal::onCmdConAutores),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CON_EDITORAS,  
    CfrmPrincipal::onCmdConEditoras),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CON_ENDERECOS,  
    CfrmPrincipal::onCmdConEnderecos),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CON_IDIOMAS,  
    CfrmPrincipal::onCmdConIdiomas),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CON_PAISES,  
    CfrmPrincipal::onCmdConPaises),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CON_PROFISSOES,  
    CfrmPrincipal::onCmdConProfissoes),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CON_CLIENTES,  
    CfrmPrincipal::onCmdConClientes),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_CON_LIVROS, 
    CfrmPrincipal::onCmdConLivros),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_VEN_VENDERLIVROS, 
    CfrmPrincipal::onCmdVenderLivros),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_VEN_VENDASREALIZADAS, 
    CfrmPrincipal::onCmdVendasRealizadas),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_OP_ALTERARSENHA ,  
    CfrmPrincipal::onCmdOpAlterarSenha),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_OP_SOBRE,  
    CfrmPrincipal::onCmdOpSobre),
  FXMAPFUNC(SEL_COMMAND, CfrmPrincipal::MNU_OP_SAIR, 
    CfrmPrincipal::onCmdOpSair),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmPrincipal::onCmdOpSair)
  };
FXIMPLEMENT(CfrmPrincipal,FXMainWindow,CfrmPrincipalMap,
            ARRAYNUMBER(CfrmPrincipalMap))

CfrmPrincipal::CfrmPrincipal(FXApp* app):
  FXMainWindow(app,STR_TITULO,NULL,NULL,DECOR_ALL,0,0,800,600){
  IniciaControles();
}

void CfrmPrincipal::IniciaControles() {
  this->setIcon(new FXBMPIcon(getApp(),Livrus));

  fonteSistema=new FXFont(getApp(),"courier",15,FONTWEIGHT_BOLD);
  barraMenu=new FXMenuBar(this,LAYOUT_SIDE_TOP|LAYOUT_FILL_X);

  frameStatus = new FXHorizontalFrame(this, LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X);
  labStatus=new FXLabel(frameStatus,STR_USUARIO, NULL, FRAME_SUNKEN|
    LAYOUT_CENTER_Y|LAYOUT_FIX_WIDTH, 0, 0, 100, 13);
  labStatus->setJustify(FX::JUSTIFY_LEFT);
  barraStatus=new FXStatusBar(frameStatus,LAYOUT_FILL_X|
    STATUSBAR_WITH_DRAGCORNER);
  barraStatus->getStatusLine()->setNormalText("");

  //iconeMDI=new FXGIFIcon(getApp(),Livrus);
  iconeMDI=new FXBMPIcon(getApp(),Livrus);
  bmpCliente=new FXBMPIcon(getApp(),Cliente);
  bmpLivro=new FXBMPIcon(getApp(),Livro);
  bmpLivros=new FXBMPIcon(getApp(),Livros);
  bmpSobre=new FXBMPIcon(getApp(),Sobre);
  bmpSair=new FXBMPIcon(getApp(),Sair);

  barraFerra = new FXToolBar(this, 
    LAYOUT_SIDE_TOP|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH|PACK_UNIFORM_HEIGHT|FRAME_THICK);

  tlbCliente = new FXButton(barraFerra, "\t\tCadastro de Clientes.", bmpCliente,
    this, MNU_CAD_CLIENTES, (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|
    LAYOUT_TOP|LAYOUT_LEFT));
  tlbLivro = new FXButton(barraFerra, "\t\tCadastro de Livros.", bmpLivro,
    this, MNU_CAD_LIVROS, (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|
    LAYOUT_TOP|LAYOUT_LEFT));
  tlbVenda = new FXButton(barraFerra, "\t\tVender Livros.", bmpLivros,
    this, MNU_VEN_VENDERLIVROS, (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|
    LAYOUT_TOP|LAYOUT_LEFT));
  tlbSobre = new FXButton(barraFerra, "\t\tSobre o sistema.", bmpSobre,
    this, MNU_OP_SOBRE, (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|
    LAYOUT_TOP|LAYOUT_LEFT));
  tlbSair = new FXButton(barraFerra, "\t\tSair do sistema.", bmpSair,
    this, MNU_OP_SAIR, (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|
    LAYOUT_TOP|LAYOUT_LEFT));

  clienteMDI=new FXMDIClient(this,LAYOUT_FILL_X|LAYOUT_FILL_Y);
  mnuMDI=new FXMDIMenu(this,clienteMDI);

  new FXMDIWindowButton(barraMenu,mnuMDI,clienteMDI,
    FXMDIClient::ID_MDI_MENUWINDOW,LAYOUT_LEFT);
  new FXMDIDeleteButton(barraMenu,clienteMDI,
    FXMDIClient::ID_MDI_MENUCLOSE,FRAME_RAISED|LAYOUT_RIGHT);
  new FXMDIRestoreButton(barraMenu,clienteMDI,
    FXMDIClient::ID_MDI_MENURESTORE,FRAME_RAISED|LAYOUT_RIGHT);
  new FXMDIMinimizeButton(barraMenu,clienteMDI,
    FXMDIClient::ID_MDI_MENUMINIMIZE,FRAME_RAISED|LAYOUT_RIGHT);

  // menu dos cadastros
  mnuCadastros = new FXMenuPane(this);
  mnuCadAssuntos = new FXMenuCommand(mnuCadastros, 
    "&Assuntos\t\tCadastro de Assuntos.", NULL, this, MNU_CAD_ASSUNTOS);
  mnuCadAutores = new FXMenuCommand(mnuCadastros, 
    "Au&tores\t\tCadastro de Autores.", NULL, this, MNU_CAD_AUTORES);
  mnuCadEditoras = new FXMenuCommand(mnuCadastros, 
    "&Editoras\t\tCadastro de Editoras.", NULL, this, MNU_CAD_EDITORAS);
  mnuCadEnderecos = new FXMenuCommand(mnuCadastros, 
    "E&ndereços\t\tCadastro de Endereços.", NULL, this, MNU_CAD_ENDERECOS);
  mnuCadIdiomas = new FXMenuCommand(mnuCadastros, 
    "&Idiomas\t\tCadastro de Idiomas.", NULL, this, MNU_CAD_IDIOMAS);
  mnuCadPaises = new FXMenuCommand(mnuCadastros, 
    "&Países\t\tCadastro de Países.", NULL, this, MNU_CAD_PAISES);
  mnuCadProfissoes = new FXMenuCommand(mnuCadastros, 
    "P&rofissões\t\tCadastro de Profissões.", NULL, this, MNU_CAD_PROFISSOES);
  new FXMenuSeparator(mnuCadastros);
  mnuCadClientes = new FXMenuCommand(mnuCadastros, 
    "&Clientes\t\tCadastro de Clientes.", NULL, this, MNU_CAD_CLIENTES);
  mnuCadLivros = new FXMenuCommand(mnuCadastros, 
    "&Livros\t\tCadastro de Livros.", NULL, this, MNU_CAD_LIVROS);
  new FXMenuTitle(barraMenu, "&Cadastros", NULL, mnuCadastros);

  // menu das pesquisas
  mnuPesquisas = new FXMenuPane(this);
  new FXMenuCommand(mnuPesquisas, "&Assuntos\t\tConsulta de Assuntos.", 
    NULL, this, MNU_CON_ASSUNTOS);
  new FXMenuCommand(mnuPesquisas, "Au&tores\t\tConsulta de Autores.",
    NULL, this, MNU_CON_AUTORES);
  new FXMenuCommand(mnuPesquisas, "&Editoras\t\tConsulta de Editoras.",
    NULL, this, MNU_CON_EDITORAS);
  new FXMenuCommand(mnuPesquisas, "E&ndereços\t\tConsulta de Endereços.",
    NULL, this, MNU_CON_ENDERECOS);
  new FXMenuCommand(mnuPesquisas, "&Idiomas\t\tConsulta de Idiomas.",
    NULL, this, MNU_CON_IDIOMAS);
  new FXMenuCommand(mnuPesquisas, "&Países\t\tConsulta de Países.",
    NULL, this, MNU_CON_PAISES);
  new FXMenuCommand(mnuPesquisas, "P&rofissões\t\tConsulta de Profissões.",
    NULL, this, MNU_CON_PROFISSOES);
  new FXMenuSeparator(mnuPesquisas);
  new FXMenuCommand(mnuPesquisas, "&Clientes\t\tConsulta de Clientes.",
    NULL, this, MNU_CON_CLIENTES);
  new FXMenuCommand(mnuPesquisas, "&Livros\t\tConsulta de Livros.",
    NULL, this, MNU_CON_LIVROS);
  new FXMenuTitle(barraMenu, "&Pesquisas", NULL, mnuPesquisas);

  // menu das vendas
  mnuVendas = new FXMenuPane(this);
  mnuVenderLivros = new FXMenuCommand(mnuVendas, 
    "&Vender Livros\t\tVender Livros.", NULL, this, MNU_VEN_VENDERLIVROS);
  mnuVendasRealizadas = new FXMenuCommand(mnuVendas, 
    "Vendas &Realizadas\t\tVendas Realizadas.",
    NULL, this, MNU_VEN_VENDASREALIZADAS);
  new FXMenuTitle(barraMenu, "&Vendas", NULL, mnuVendas);

  // menu das janelas
  mnuJanelas = new FXMenuPane(this);
  new FXMenuCommand(mnuJanelas, "Lado a lado &horizontal", NULL,
    clienteMDI, FXMDIClient::ID_MDI_TILEHORIZONTAL);
  new FXMenuCommand(mnuJanelas, "Lado a lado &vertical", NULL,
    clienteMDI, FXMDIClient::ID_MDI_TILEVERTICAL);
  new FXMenuCommand(mnuJanelas, "Em &cascata", NULL,
    clienteMDI, FXMDIClient::ID_MDI_CASCADE);
  new FXMenuCommand(mnuJanelas, "&Fechar janela", NULL,
    clienteMDI, FXMDIClient::ID_MDI_CLOSE);
  FXMenuSeparator* sepJanelas=new FXMenuSeparator(mnuJanelas);
  sepJanelas->setTarget(clienteMDI);
  sepJanelas->setSelector(FXMDIClient::ID_MDI_ANY);
  new FXMenuCommand(mnuJanelas, NULL, NULL, clienteMDI, FXMDIClient::ID_MDI_1);
  new FXMenuCommand(mnuJanelas, NULL, NULL, clienteMDI, FXMDIClient::ID_MDI_2);
  new FXMenuCommand(mnuJanelas, NULL, NULL, clienteMDI, FXMDIClient::ID_MDI_3);
  new FXMenuCommand(mnuJanelas, NULL, NULL, clienteMDI, FXMDIClient::ID_MDI_4);
  new FXMenuTitle(barraMenu,"&Janelas", NULL, mnuJanelas);
  
  // menu das opções
  mnuOpcoes = new FXMenuPane(this);    
  mnuAlterarSenha = new FXMenuCommand(mnuOpcoes, 
    "&Alterar Senha\t\tAlteração de Senha.", NULL, this, MNU_OP_ALTERARSENHA);
  new FXMenuSeparator(mnuOpcoes);
  new FXMenuCommand(mnuOpcoes, "&Sobre\t\tSobre o Sistema.",
    NULL, this, MNU_OP_SOBRE);
  new FXMenuCommand(mnuOpcoes, "Sa&ir\tCtrl-S\tSair do sistema.",
    NULL, this, MNU_OP_SAIR);
  new FXMenuTitle(barraMenu, "&Opções", NULL, mnuOpcoes);
}

void CfrmPrincipal::create(){
  FXMainWindow::create();
}

CfrmPrincipal::~CfrmPrincipal(){
  delete mnuCadastros;
  delete mnuPesquisas;
  delete mnuVendas;
  delete mnuOpcoes;
  delete mnuJanelas;
  delete fonteSistema;
  delete iconeMDI;
}

long CfrmPrincipal::onCmdCadAssuntos(FXObject*,FXSelector,void*){  
  mnuCadAssuntos->disable();
  frmCadAssuntos = new CfrmCadAssuntos(clienteMDI,iconeMDI, mnuMDI);
  frmCadAssuntos->create();
  return true;
}

long CfrmPrincipal::onCmdCadAutores(FXObject*,FXSelector,void*){
  mnuCadAutores->disable();
  frmCadAutores = new CfrmCadAutores(clienteMDI,iconeMDI, mnuMDI);
  frmCadAutores->create();
  return true;
}

long CfrmPrincipal::onCmdCadEditoras(FXObject*,FXSelector,void*){
  mnuCadEditoras->disable();
  frmCadEditoras = new CfrmCadEditoras(clienteMDI,iconeMDI, mnuMDI);
  frmCadEditoras->create();
  return true;
}

long CfrmPrincipal::onCmdCadEnderecos(FXObject*,FXSelector,void*){
  mnuCadEnderecos->disable();
  frmCadEnderecos = new CfrmCadEnderecos(clienteMDI,iconeMDI, mnuMDI);
  frmCadEnderecos->create();
  return true;
}

long CfrmPrincipal::onCmdCadIdiomas(FXObject*,FXSelector,void*){
  mnuCadIdiomas->disable();
  frmCadIdiomas = new CfrmCadIdiomas(clienteMDI,iconeMDI, mnuMDI);
  frmCadIdiomas->create();
  return true;
}

long CfrmPrincipal::onCmdCadPaises(FXObject*,FXSelector,void*){
  mnuCadPaises->disable();
  frmCadPaises = new CfrmCadPaises(clienteMDI,iconeMDI, mnuMDI);

  frmCadPaises->create();
  return true;
}

long CfrmPrincipal::onCmdCadProfissoes(FXObject*,FXSelector,void*){
  mnuCadProfissoes->disable();
  frmCadProfissoes = new CfrmCadProfissoes(clienteMDI,iconeMDI, mnuMDI);
  frmCadProfissoes->create();
  return true;
}

long CfrmPrincipal::onCmdCadClientes(FXObject*,FXSelector,void*){
  tlbCliente->disable();
  mnuCadClientes->disable();
  frmCadClientes = new CfrmCadClientes(clienteMDI,iconeMDI, mnuMDI);
  frmCadClientes->create();
  return true;
}

long CfrmPrincipal::onCmdCadLivros(FXObject*,FXSelector,void*){
  tlbLivro->disable();
  mnuCadLivros->disable();
  frmCadLivros = new CfrmCadLivros(clienteMDI,iconeMDI, mnuMDI);
  frmCadLivros->create();
  return true;
}

long CfrmPrincipal::onCmdConAssuntos(FXObject*,FXSelector,void*){
  frmConAssuntos = new CfrmConAssuntos(this);
  frmConAssuntos->execute(PLACEMENT_SCREEN);
  return true;
}

long CfrmPrincipal::onCmdConAutores(FXObject*,FXSelector,void*){
  frmConAutores = new CfrmConAutores(this);
  frmConAutores->execute(PLACEMENT_SCREEN);
  return true;
}

long CfrmPrincipal::onCmdConEditoras(FXObject*,FXSelector,void*){
  frmConEditoras = new CfrmConEditoras(this);
  frmConEditoras->execute(PLACEMENT_SCREEN);
  return true;
}

long CfrmPrincipal::onCmdConEnderecos(FXObject*,FXSelector,void*){
  frmConEnderecos = new CfrmConEnderecos(this);
  frmConEnderecos->execute(PLACEMENT_SCREEN);

  return true;
}

long CfrmPrincipal::onCmdConIdiomas(FXObject*,FXSelector,void*){
  frmConIdiomas = new CfrmConIdiomas(this);
  frmConIdiomas->execute(PLACEMENT_SCREEN);
  return true;
}

long CfrmPrincipal::onCmdConPaises(FXObject*,FXSelector,void*){
  frmConPaises = new CfrmConPaises(this);
  frmConPaises->execute(PLACEMENT_SCREEN);
  return true;
}

long CfrmPrincipal::onCmdConProfissoes(FXObject*,FXSelector,void*){
  frmConProfissoes = new CfrmConProfissoes(this);
  frmConProfissoes->execute(PLACEMENT_SCREEN);
  return true;
}

long CfrmPrincipal::onCmdConClientes(FXObject*,FXSelector,void*){
  frmConClientes = new CfrmConClientes(this);
  frmConClientes->execute(PLACEMENT_SCREEN);
  return true;
}

long CfrmPrincipal::onCmdConLivros(FXObject*,FXSelector,void*){
  frmConLivros = new CfrmConLivros(this);
  frmConLivros->execute(PLACEMENT_SCREEN);
  return true;
}

long CfrmPrincipal::onCmdVenderLivros(FXObject*,FXSelector,void*){
  tlbVenda->disable();
  mnuVenderLivros->disable();
  frmVenderLivros = new CfrmVenderLivros(clienteMDI,iconeMDI, mnuMDI);
  frmVenderLivros->create();
  return true;
}

long CfrmPrincipal::onCmdVendasRealizadas(FXObject*,FXSelector,void*){
  mnuVendasRealizadas->disable();
  frmConVendas = new CfrmConVendas(clienteMDI,iconeMDI, mnuMDI);
  frmConVendas->create();
  return true;
}

long CfrmPrincipal::onCmdOpAlterarSenha(FXObject*,FXSelector,void*){
  mnuAlterarSenha->disable();
  frmAlterarSenha = new CfrmAlterarSenha(clienteMDI,iconeMDI, mnuMDI);
  frmAlterarSenha->create();
  return true;
}

long CfrmPrincipal::onCmdOpSobre(FXObject*,FXSelector,void*){
  frmSobre = new CfrmSobre(this);
  frmSobre->execute(PLACEMENT_SCREEN);
  return true;
}

long CfrmPrincipal::onCmdOpSair(FXObject*,FXSelector,void*){
  if (FXMessageBox::question(this, MBOX_YES_NO, STR_TITULO,
    STR_SAIRSIS) == MBOX_CLICKED_NO) {
     return true;
  }
  getApp()->exit(0);
  return true;
}

