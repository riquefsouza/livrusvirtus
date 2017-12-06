from FXPy.fox import *
from resource import Resource
from RotinasGlobais import RotinasGlobais
import CadAssuntos
import CadAutores
import CadEditoras
import CadEnderecos
import CadIdiomas
import CadPaises
import CadProfissoes
import CadClientes
import CadLivros
import ConAssuntos
import ConAutores
import ConEditoras
import ConEnderecos
import ConIdiomas
import ConPaises
import ConProfissoes
import ConClientes
import ConLivros
import VenderLivros
import ConVendas
import AlterarSenha
import Sobre

def create(parent):
  return frmPrincipal(parent)

class frmPrincipal(FXMainWindow):
  def __init__(self, app):
    FXMainWindow.__init__(self, app, Resource.STR_TITULO, None, None,
      DECOR_ALL, 0, 0, 800, 600)
      
    # Atribui o mapa de mensagens para esta classe
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CAD_ASSUNTOS, 
      frmPrincipal.onCmdCadAssuntos)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CAD_AUTORES, 
      frmPrincipal.onCmdCadAutores)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CAD_EDITORAS,  
      frmPrincipal.onCmdCadEditoras)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CAD_ENDERECOS,  
      frmPrincipal.onCmdCadEnderecos)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CAD_IDIOMAS,  
      frmPrincipal.onCmdCadIdiomas)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CAD_PAISES,  
      frmPrincipal.onCmdCadPaises)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CAD_PROFISSOES,  
      frmPrincipal.onCmdCadProfissoes)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CAD_CLIENTES,  
      frmPrincipal.onCmdCadClientes)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CAD_LIVROS, 
      frmPrincipal.onCmdCadLivros)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CON_ASSUNTOS, 
      frmPrincipal.onCmdConAssuntos)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CON_AUTORES,  
      frmPrincipal.onCmdConAutores)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CON_EDITORAS,  
      frmPrincipal.onCmdConEditoras)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CON_ENDERECOS,  
      frmPrincipal.onCmdConEnderecos)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CON_IDIOMAS,  
      frmPrincipal.onCmdConIdiomas)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CON_PAISES,  
      frmPrincipal.onCmdConPaises)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CON_PROFISSOES,  
      frmPrincipal.onCmdConProfissoes)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CON_CLIENTES,  
      frmPrincipal.onCmdConClientes)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_CON_LIVROS, 
      frmPrincipal.onCmdConLivros)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_VEN_VENDERLIVROS, 
      frmPrincipal.onCmdVenderLivros)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_VEN_VENDASREALIZADAS, 
      frmPrincipal.onCmdVendasRealizadas)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_OP_ALTERARSENHA ,  
      frmPrincipal.onCmdOpAlterarSenha)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_OP_SOBRE,  
      frmPrincipal.onCmdOpSobre)
    FXMAPFUNC(self, SEL_COMMAND, Resource.MNU_OP_SAIR, 
      frmPrincipal.onCmdOpSair)
    FXMAPFUNC(self, SEL_CLOSE, Resource.FRMPRINCIPAL, 
      frmPrincipal.onCmdOpSair)

    self.fonteSistema = FXFont(self.getApp(), "courier", 15, FONTWEIGHT_BOLD)
    barraMenu = FXMenubar(self, LAYOUT_SIDE_TOP|LAYOUT_FILL_X)

    frameStatus = FXHorizontalFrame(self, LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X)
    self.labStatus = FXLabel(frameStatus,Resource.STR_USUARIO, None, FRAME_SUNKEN|
      LAYOUT_CENTER_Y|LAYOUT_FIX_WIDTH, 0, 0, 100, 13)
    self.labStatus.setJustify(JUSTIFY_LEFT)
    barraStatus = FXStatusbar(frameStatus,LAYOUT_FILL_X|
      STATUSBAR_WITH_DRAGCORNER)
    barraStatus.getStatusline().setNormalText("")

    Rotinas = RotinasGlobais.Rotinas
    self.iconeMDI = Rotinas.lerFigura(self.getApp(), "livrus.bmp")
    self.bmpcliente = Rotinas.lerFigura(self.getApp(), "cliente.bmp")
    self.bmplivro = Rotinas.lerFigura(self.getApp(), "livro.bmp")
    self.bmplivros = Rotinas.lerFigura(self.getApp(), "livros.bmp")
    self.bmpsobre = Rotinas.lerFigura(self.getApp(), "sobre.bmp")
    self.bmpsair = Rotinas.lerFigura(self.getApp(), "sair.bmp")   

    self.setIcon(self.iconeMDI)
    #self.setMiniIcon(self.smallicon)

    barraFerra = FXToolbar(self, LAYOUT_SIDE_TOP|LAYOUT_FILL_X|
      PACK_UNIFORM_WIDTH|PACK_UNIFORM_HEIGHT|FRAME_THICK)

    self.tlbCliente = FXButton(barraFerra, "\t\t"+Resource.STR_CADCLIENTE+".",
      self.bmpcliente, self, Resource.MNU_CAD_CLIENTES, 
      (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT))
    self.tlbLivro = FXButton(barraFerra, "\t\t"+Resource.STR_CADLIVRO+".", 
      self.bmplivro, self, Resource.MNU_CAD_LIVROS, 
      (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT))
    self.tlbVenda = FXButton(barraFerra, "\t\t"+Resource.STR_VENLIVRO+".", 
      self.bmplivros, self, Resource.MNU_VEN_VENDERLIVROS, 
      (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT))
    self.tlbSobre = FXButton(barraFerra, "\t\t"+Resource.STR_OPSOBRE+".", 
      self.bmpsobre, self, Resource.MNU_OP_SOBRE, 
      (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT))
    self.tlbSair = FXButton(barraFerra, "\t\t"+Resource.STR_OPSAIR+".", 
      self.bmpsair, self, Resource.MNU_OP_SAIR, 
      (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT))    

    self.setTarget(self)
    self.setSelector(Resource.FRMPRINCIPAL)

    self.clienteMDI = FXMDIClient(self, LAYOUT_FILL_X|LAYOUT_FILL_Y) 
    self.menuMDI = FXMDIMenu(self, self.clienteMDI)
  
    FXMDIWindowButton(barraMenu, self.clienteMDI, 
      FXMDIClient.ID_MDI_MENUWINDOW, LAYOUT_LEFT)
    FXMDIDeleteButton(barraMenu, self.clienteMDI, 
      FXMDIClient.ID_MDI_MENUCLOSE,FRAME_RAISED|LAYOUT_RIGHT)
    FXMDIRestoreButton(barraMenu, self.clienteMDI, 
      FXMDIClient.ID_MDI_MENURESTORE,FRAME_RAISED|LAYOUT_RIGHT)
    FXMDIMinimizeButton(barraMenu, self.clienteMDI,
      FXMDIClient.ID_MDI_MENUMINIMIZE, FRAME_RAISED|LAYOUT_RIGHT)
  
    # menu dos cadastros
    mnuCadastros = FXMenuPane(self)
    self.mnuCadAssuntos = FXMenuCommand(mnuCadastros, 
      "&Assuntos\t\tCadastro de Assuntos.", None, self, 
      Resource.MNU_CAD_ASSUNTOS)
    self.mnuCadAutores = FXMenuCommand(mnuCadastros, 
      "Au&tores\t\tCadastro de Autores.", None, self, 
      Resource.MNU_CAD_AUTORES)
    self.mnuCadEditoras = FXMenuCommand(mnuCadastros, 
      "&Editoras\t\tCadastro de Editoras.", None, self, 
      Resource.MNU_CAD_EDITORAS)
    self.mnuCadEnderecos = FXMenuCommand(mnuCadastros, 
      "E&ndereços\t\tCadastro de Endereços.", None, self, 
      Resource.MNU_CAD_ENDERECOS)
    self.mnuCadIdiomas = FXMenuCommand(mnuCadastros, 
      "&Idiomas\t\tCadastro de Idiomas.", None, self,Resource.MNU_CAD_IDIOMAS)
    self.mnuCadPaises = FXMenuCommand(mnuCadastros, 
      "&Países\t\tCadastro de Países.", None, self, Resource.MNU_CAD_PAISES)
    self.mnuCadProfissoes = FXMenuCommand(mnuCadastros, 
      "P&rofissões\t\tCadastro de Profissões.",
      None, self, Resource.MNU_CAD_PROFISSOES)
    FXMenuSeparator(mnuCadastros)
    self.mnuCadClientes = FXMenuCommand(mnuCadastros, 
      "&Clientes\t\tCadastro de Clientes.",
      None, self, Resource.MNU_CAD_CLIENTES)
    self.mnuCadLivros = FXMenuCommand(mnuCadastros, 
      "&Livros\t\tCadastro de Livros.",
      None, self, Resource.MNU_CAD_LIVROS)
    FXMenuTitle(barraMenu, "&Cadastros", None, mnuCadastros)

    # menu das pesquisas
    mnuPesquisas = FXMenuPane(self)
    FXMenuCommand(mnuPesquisas, "&Assuntos\t\tConsulta de Assuntos.",
      None, self, Resource.MNU_CON_ASSUNTOS)
    FXMenuCommand(mnuPesquisas, "Au&tores\t\tConsulta de Autores.",
      None, self, Resource.MNU_CON_AUTORES)
    FXMenuCommand(mnuPesquisas, "&Editoras\t\tConsulta de Editoras.",
      None, self, Resource.MNU_CON_EDITORAS)
    FXMenuCommand(mnuPesquisas, "E&ndereços\t\tConsulta de Endereços.",
      None, self, Resource.MNU_CON_ENDERECOS)
    FXMenuCommand(mnuPesquisas, "&Idiomas\t\tConsulta de Idiomas.",
      None, self, Resource.MNU_CON_IDIOMAS)
    FXMenuCommand(mnuPesquisas, "&Países\t\tConsulta de Países.",
      None, self, Resource.MNU_CON_PAISES)
    FXMenuCommand(mnuPesquisas, "P&rofissões\t\tConsulta de Profissões.",
      None, self, Resource.MNU_CON_PROFISSOES)
    FXMenuSeparator(mnuPesquisas)
    FXMenuCommand(mnuPesquisas, "&Clientes\t\tConsulta de Clientes.",
      None, self, Resource.MNU_CON_CLIENTES)
    FXMenuCommand(mnuPesquisas, "&Livros\t\tConsulta de Livros.",
      None, self, Resource.MNU_CON_LIVROS)
    FXMenuTitle(barraMenu, "&Pesquisas", None, mnuPesquisas)

    # menu das vendas
    mnuVendas = FXMenuPane(self)
    self.mnuVenderLivros = FXMenuCommand(mnuVendas, 
      "&Vender Livros\t\tVender Livros.",
      None, self, Resource.MNU_VEN_VENDERLIVROS)
    self.mnuVendasRealizadas = FXMenuCommand(mnuVendas, 
      "Vendas &Realizadas\t\tVendas Realizadas.",
      None, self, Resource.MNU_VEN_VENDASREALIZADAS)
    FXMenuTitle(barraMenu, "&Vendas", None, mnuVendas)

    # menu das janelas
    mnuJanelas = FXMenuPane(self)
    FXMenuCommand(mnuJanelas, "Lado a lado &horizontal", None,
      self.clienteMDI, FXMDIClient.ID_MDI_TILEHORIZONTAL)
    FXMenuCommand(mnuJanelas, "Lado a lado &vertical", None,
      self.clienteMDI, FXMDIClient.ID_MDI_TILEVERTICAL)
    FXMenuCommand(mnuJanelas, "Em &cascata", None,
      self.clienteMDI, FXMDIClient.ID_MDI_CASCADE)
    FXMenuCommand(mnuJanelas, "&Fechar janela", None,
      self.clienteMDI, FXMDIClient.ID_MDI_CLOSE)
    sepjanelas1 = FXMenuSeparator(mnuJanelas)
    sepjanelas1.setTarget(self.clienteMDI)
    sepjanelas1.setSelector(FXMDIClient.ID_MDI_ANY)
    FXMenuCommand(mnuJanelas, None, None, self.clienteMDI, FXMDIClient.ID_MDI_1)
    FXMenuCommand(mnuJanelas, None, None, self.clienteMDI, FXMDIClient.ID_MDI_2)
    FXMenuCommand(mnuJanelas, None, None, self.clienteMDI, FXMDIClient.ID_MDI_3)
    FXMenuCommand(mnuJanelas, None, None, self.clienteMDI, FXMDIClient.ID_MDI_4)
    FXMenuTitle(barraMenu,"&Janelas", None, mnuJanelas)
    
    # menu das opcoes
    mnuOpcoes = FXMenuPane(self)    
    self.mnuAlterarSenha = FXMenuCommand(mnuOpcoes, 
      "&Alterar Senha\t\tAlteração de Senha.", None, self, Resource.MNU_OP_ALTERARSENHA)
    FXMenuSeparator(mnuOpcoes)
    FXMenuCommand(mnuOpcoes, "&Sobre\t\tSobre o Sistema.",
      None, self, Resource.MNU_OP_SOBRE)
    FXMenuCommand(mnuOpcoes, "Sa&ir\tCtrl-S\tSair do sistema.",
      None, self, Resource.MNU_OP_SAIR)
    FXMenuTitle(barraMenu, "&Opções", None, mnuOpcoes)  

  def create(self):
    FXMainWindow.create(self)
    self.fonteSistema.create()
    mdichild = self.clienteMDI.getMDIChildFirst()
    while (mdichild):
      sb = mdichild.contentWindow().verticalScrollbar()
      sb.setLine(self.fonteSistema.fontHeight)
      mdichild = mdichild.getMDINext()

  def onCmdCadAssuntos(self, sender, sel, ptr):
    self.mnuCadAssuntos.disable()
    frmCadAssuntos = CadAssuntos.frmCadAssuntos(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmCadAssuntos.create()
    return True
  
  def onCmdCadAutores(self, sender, sel, ptr):
    self.mnuCadAutores.disable()
    frmCadAutores = CadAutores.frmCadAutores(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmCadAutores.create()
    return True
  
  def onCmdCadEditoras(self, sender, sel, ptr):
    self.mnuCadEditoras.disable()
    frmCadEditoras = CadEditoras.frmCadEditoras(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmCadEditoras.create()
    return True
  
  def onCmdCadEnderecos(self, sender, sel, ptr):
    self.mnuCadEnderecos.disable()
    frmCadEnderecos = CadEnderecos.frmCadEnderecos(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmCadEnderecos.create()
    return True
  
  def onCmdCadIdiomas(self, sender, sel, ptr):
    self.mnuCadIdiomas.disable()
    frmCadIdiomas = CadIdiomas.frmCadIdiomas(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmCadIdiomas.create()
    return True
  
  def onCmdCadPaises(self, sender, sel, ptr):
    self.mnuCadPaises.disable()
    frmCadPaises = CadPaises.frmCadPaises(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmCadPaises.create()
    return True
  
  def onCmdCadProfissoes(self, sender, sel, ptr):
    self.mnuCadProfissoes.disable()
    frmCadProfissoes = CadProfissoes.frmCadProfissoes(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmCadProfissoes.create()
    return True
  
  def onCmdCadClientes(self, sender, sel, ptr):
    self.tlbCliente.disable()
    self.mnuCadClientes.disable()
    frmCadClientes = CadClientes.frmCadClientes(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmCadClientes.create()
    return True
  
  def onCmdCadLivros(self, sender, sel, ptr):
    self.tlbLivro.disable()
    self.mnuCadLivros.disable()
    frmCadLivros = CadLivros.frmCadLivros(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmCadLivros.create()
    return True

  def onCmdConAssuntos(self, sender, sel, ptr):
    frmConAssuntos = ConAssuntos.frmConAssuntos(self)
    frmConAssuntos.execute(PLACEMENT_SCREEN)
    return True

  def onCmdConAutores(self, sender, sel, ptr):
    frmConAutores = ConAutores.frmConAutores(self)
    frmConAutores.execute(PLACEMENT_SCREEN)
    return True
  
  def onCmdConEditoras(self, sender, sel, ptr):
    frmConEditoras = ConEditoras.frmConEditoras(self)
    frmConEditoras.execute(PLACEMENT_SCREEN)
    return True
  
  def onCmdConEnderecos(self, sender, sel, ptr):
    frmConEnderecos = ConEnderecos.frmConEnderecos(self)
    frmConEnderecos.execute(PLACEMENT_SCREEN)
    return True
  
  def onCmdConIdiomas(self, sender, sel, ptr):
    frmConIdiomas = ConIdiomas.frmConIdiomas(self)
    frmConIdiomas.execute(PLACEMENT_SCREEN)
    return True
  
  def onCmdConPaises(self, sender, sel, ptr):
    frmConPaises = ConPaises.frmConPaises(self)
    frmConPaises.execute(PLACEMENT_SCREEN)
    return True
  
  def onCmdConProfissoes(self, sender, sel, ptr):
    frmConProfissoes = ConProfissoes.frmConProfissoes(self)
    frmConProfissoes.execute(PLACEMENT_SCREEN)
    return True

  def onCmdConClientes(self, sender, sel, ptr):
    frmConClientes = ConClientes.frmConClientes(self)
    frmConClientes.execute(PLACEMENT_SCREEN)
    return True
  
  def onCmdConLivros(self, sender, sel, ptr):
    frmConLivros = ConLivros.frmConLivros(self)
    frmConLivros.execute(PLACEMENT_SCREEN)
    return True
  
  def onCmdVenderLivros(self, sender, sel, ptr):
    self.tlbVenda.disable()
    self.mnuVenderLivros.disable()
    frmVenderLivros = VenderLivros.frmVenderLivros(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmVenderLivros.create()
    return True
  
  def onCmdVendasRealizadas(self, sender, sel, ptr):
    self.mnuVendasRealizadas.disable()
    frmConVendas = ConVendas.frmConVendas(self.clienteMDI, self.iconeMDI, 
      self.menuMDI)
    frmConVendas.create()
    return True
  
  def onCmdOpAlterarSenha(self, sender, sel, ptr):
    self.mnuAlterarSenha.disable()
    frmAlterarSenha = AlterarSenha.frmAlterarSenha(self.clienteMDI, 
      self.iconeMDI, self.menuMDI)
    frmAlterarSenha.create()
    return True
  
  def onCmdOpSobre(self, sender, sel, ptr):
    frmSobre = Sobre.create(self)
    frmSobre.execute(PLACEMENT_SCREEN)
    return True
  
  def onCmdOpSair(self, sender, sel, ptr):
    if showModalQuestionBox(self, MBOX_YES_NO, "Livrus Virtus",
       "Deseja sair do sistema?") == MBOX_CLICKED_NO:
       return True
    
    self.getApp().exit(0)
    return True

  def setLabStatus(self, sTexto):
     self.labStatus.setText(sTexto)

  def habilitaMenu(self, smenu):
    if smenu == "CadAssuntos":
      self.mnuCadAssuntos.enable()
    elif smenu == "CadAutores":
      self.mnuCadAutores.enable()
    elif smenu == "CadEditoras":   
      self.mnuCadEditoras.enable()
    elif smenu == "CadEnderecos":
      self.mnuCadEnderecos.enable()
    elif smenu == "CadIdiomas":
      self.mnuCadIdiomas.enable()
    elif smenu == "CadPaises":
      self.mnuCadPaises.enable()
    elif smenu == "CadProfissoes":
      self.mnuCadProfissoes.enable()
    elif smenu == "CadClientes":
      self.mnuCadClientes.enable()
    elif smenu == "CadLivros":
      self.mnuCadLivros.enable()
    elif smenu == "VenderLivros":
      self.mnuVenderLivros.enable()
    elif smenu == "VendasRealizadas":
      self.mnuVendasRealizadas.enable()
    elif smenu == "AlterarSenha":
       self.mnuAlterarSenha.enable()

  def habilitaToolButton(self, stlb):
    if stlb == "tlbCliente":
      self.tlbCliente.enable()
    elif stlb == "tlbLivro":
      self.tlbLivro.enable()
    elif stlb == "tlbVenda":
      self.tlbVenda.enable()
