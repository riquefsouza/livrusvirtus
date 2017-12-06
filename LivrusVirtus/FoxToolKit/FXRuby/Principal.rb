#!/usr/bin/env ruby

require 'fox'
require 'fox/colors'
require 'fox/responder'

require 'RotinasGlobais'
require 'resource'
require 'CadAssuntos'
require 'CadAutores'
require 'CadEditoras'
require 'CadEnderecos'
require 'CadIdiomas'
require 'CadPaises'
require 'CadProfissoes'
require 'CadClientes'
require 'CadLivros'
require 'ConAssuntos'
require 'ConAutores'
require 'ConEditoras'
require 'ConEnderecos'
require 'ConIdiomas'
require 'ConPaises'
require 'ConProfissoes'
require 'ConClientes'
require 'ConLivros'
require 'VenderLivros'
require 'ConVendas'
require 'AlterarSenha'
require 'Sobre'

include Fox
include Responder

$frmPrincipal = nil

class FRMPrincipal < FXMainWindow

  def initialize(app)
    super(app, Resource::STR_TITULO, nil, nil, DECOR_ALL, 0, 0, 800, 600)
       
    # Atribui o mapa de mensagens para esta classe
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CAD_ASSUNTOS, :onCmdCadAssuntos)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CAD_AUTORES, :onCmdCadAutores)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CAD_EDITORAS,  :onCmdCadEditoras)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CAD_ENDERECOS,  :onCmdCadEnderecos)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CAD_IDIOMAS,  :onCmdCadIdiomas)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CAD_PAISES,  :onCmdCadPaises)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CAD_PROFISSOES,  :onCmdCadProfissoes)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CAD_CLIENTES,  :onCmdCadClientes)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CAD_LIVROS, :onCmdCadLivros)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CON_ASSUNTOS,  :onCmdConAssuntos)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CON_AUTORES,  :onCmdConAutores)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CON_EDITORAS,  :onCmdConEditoras)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CON_ENDERECOS,  :onCmdConEnderecos)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CON_IDIOMAS,  :onCmdConIdiomas)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CON_PAISES,  :onCmdConPaises)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CON_PROFISSOES,  :onCmdConProfissoes)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CON_CLIENTES,  :onCmdConClientes)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_CON_LIVROS, :onCmdConLivros)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_VEN_VENDERLIVROS, :onCmdVenderLivros)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_VEN_VENDASREALIZADAS, 
      :onCmdVendasRealizadas)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_OP_ALTERARSENHA ,  
      :onCmdOpAlterarSenha)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_OP_SOBRE,  :onCmdOpSobre)
    FXMAPFUNC(SEL_COMMAND, Resource::MNU_OP_SAIR, :onCmdOpSair)
    FXMAPFUNC(SEL_CLOSE, Resource::FRMPRINCIPAL, :onCmdOpSair)

    @fonteSistema = FXFont.new(getApp(), "courier", 15, FONTWEIGHT_BOLD)
    barraMenu = FXMenubar.new(self, LAYOUT_SIDE_TOP|LAYOUT_FILL_X)

    frameStatus = FXHorizontalFrame.new(self, LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X)
    @labStatus = FXLabel.new(frameStatus,Resource::STR_USUARIO, nil, FRAME_SUNKEN|
      LAYOUT_CENTER_Y|LAYOUT_FIX_WIDTH, 0, 0, 100, 13)
    @labStatus.setJustify(JUSTIFY_LEFT)
    barraStatus = FXStatusbar.new(frameStatus,LAYOUT_FILL_X|
      STATUSBAR_WITH_DRAGCORNER)
    barraStatus.getStatusline().setNormalText("")

    @iconeMDI = $Rotinas.lerFigura(getApp(), "livrus.bmp")
    @bmpcliente = $Rotinas.lerFigura(getApp(), "cliente.bmp")
    @bmplivro = $Rotinas.lerFigura(getApp(), "livro.bmp")
    @bmplivros = $Rotinas.lerFigura(getApp(), "livros.bmp")
    @bmpsobre = $Rotinas.lerFigura(getApp(), "sobre.bmp")
    @bmpsair = $Rotinas.lerFigura(getApp(), "sair.bmp")   

    setIcon(@iconeMDI)
    #setMiniIcon(@smallicon)

    barraFerra = FXToolbar.new(self, LAYOUT_SIDE_TOP|LAYOUT_FILL_X|
      PACK_UNIFORM_WIDTH|PACK_UNIFORM_HEIGHT|FRAME_THICK)

    @tlbCliente = FXButton.new(barraFerra, "\t\t"+Resource::STR_CADCLIENTE+".",
      @bmpcliente, self, Resource::MNU_CAD_CLIENTES, 
      (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT))
    @tlbLivro = FXButton.new(barraFerra, "\t\t"+Resource::STR_CADLIVRO+".", 
      @bmplivro, self, Resource::MNU_CAD_LIVROS, 
      (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT))
    @tlbVenda = FXButton.new(barraFerra, "\t\t"+Resource::STR_VENLIVRO+".", 
      @bmplivros, self, Resource::MNU_VEN_VENDERLIVROS, 
      (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT))
    @tlbSobre = FXButton.new(barraFerra, "\t\t"+Resource::STR_OPSOBRE+".", 
      @bmpsobre, self, Resource::MNU_OP_SOBRE, 
      (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT))
    @tlbSair = FXButton.new(barraFerra, "\t\t"+Resource::STR_OPSAIR+".", 
      @bmpsair, self, Resource::MNU_OP_SAIR, 
      (ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT))    

    setTarget(self)
    setSelector(Resource::FRMPRINCIPAL)

    @clienteMDI = FXMDIClient.new(self, LAYOUT_FILL_X|LAYOUT_FILL_Y) 
    @menuMDI = FXMDIMenu.new(self, @clienteMDI)
  
    FXMDIWindowButton.new(barraMenu, @clienteMDI, 
      FXMDIClient::ID_MDI_MENUWINDOW, LAYOUT_LEFT)
    FXMDIDeleteButton.new(barraMenu, @clienteMDI, 
      FXMDIClient::ID_MDI_MENUCLOSE,FRAME_RAISED|LAYOUT_RIGHT)
    FXMDIRestoreButton.new(barraMenu, @clienteMDI, 
      FXMDIClient::ID_MDI_MENURESTORE,FRAME_RAISED|LAYOUT_RIGHT)
    FXMDIMinimizeButton.new(barraMenu, @clienteMDI,
      FXMDIClient::ID_MDI_MENUMINIMIZE, FRAME_RAISED|LAYOUT_RIGHT)
  
    # menu dos cadastros
    mnuCadastros = FXMenuPane.new(self)
    @mnuCadAssuntos = FXMenuCommand.new(mnuCadastros, 
      "&Assuntos\t\tCadastro de Assuntos.", nil, self, 
      Resource::MNU_CAD_ASSUNTOS)
    @mnuCadAutores = FXMenuCommand.new(mnuCadastros, 
      "Au&tores\t\tCadastro de Autores.", nil, self, 
      Resource::MNU_CAD_AUTORES)
    @mnuCadEditoras = FXMenuCommand.new(mnuCadastros, 
      "&Editoras\t\tCadastro de Editoras.", nil, self, 
      Resource::MNU_CAD_EDITORAS)
    @mnuCadEnderecos = FXMenuCommand.new(mnuCadastros, 
      "E&ndereços\t\tCadastro de Endereços.", nil, self, 
      Resource::MNU_CAD_ENDERECOS)
    @mnuCadIdiomas = FXMenuCommand.new(mnuCadastros, 
      "&Idiomas\t\tCadastro de Idiomas.", nil, self,Resource::MNU_CAD_IDIOMAS)
    @mnuCadPaises = FXMenuCommand.new(mnuCadastros, 
      "&Países\t\tCadastro de Países.", nil, self, Resource::MNU_CAD_PAISES)
    @mnuCadProfissoes = FXMenuCommand.new(mnuCadastros, 
      "P&rofissões\t\tCadastro de Profissões.",
      nil, self, Resource::MNU_CAD_PROFISSOES)
    FXMenuSeparator.new(mnuCadastros)
    @mnuCadClientes = FXMenuCommand.new(mnuCadastros, 
      "&Clientes\t\tCadastro de Clientes.",
      nil, self, Resource::MNU_CAD_CLIENTES)
    @mnuCadLivros = FXMenuCommand.new(mnuCadastros, 
      "&Livros\t\tCadastro de Livros.",
      nil, self, Resource::MNU_CAD_LIVROS)
    FXMenuTitle.new(barraMenu, "&Cadastros", nil, mnuCadastros)

    # menu das pesquisas
    mnuPesquisas = FXMenuPane.new(self)
    FXMenuCommand.new(mnuPesquisas, "&Assuntos\t\tConsulta de Assuntos.",
      nil, self, Resource::MNU_CON_ASSUNTOS)
    FXMenuCommand.new(mnuPesquisas, "Au&tores\t\tConsulta de Autores.",
      nil, self, Resource::MNU_CON_AUTORES)
    FXMenuCommand.new(mnuPesquisas, "&Editoras\t\tConsulta de Editoras.",
      nil, self, Resource::MNU_CON_EDITORAS)
    FXMenuCommand.new(mnuPesquisas, "E&ndereços\t\tConsulta de Endereços.",
      nil, self, Resource::MNU_CON_ENDERECOS)
    FXMenuCommand.new(mnuPesquisas, "&Idiomas\t\tConsulta de Idiomas.",
      nil, self, Resource::MNU_CON_IDIOMAS)
    FXMenuCommand.new(mnuPesquisas, "&Países\t\tConsulta de Países.",
      nil, self, Resource::MNU_CON_PAISES)
    FXMenuCommand.new(mnuPesquisas, "P&rofissões\t\tConsulta de Profissões.",
      nil, self, Resource::MNU_CON_PROFISSOES)
    FXMenuSeparator.new(mnuPesquisas)
    FXMenuCommand.new(mnuPesquisas, "&Clientes\t\tConsulta de Clientes.",
      nil, self, Resource::MNU_CON_CLIENTES)
    FXMenuCommand.new(mnuPesquisas, "&Livros\t\tConsulta de Livros.",
      nil, self, Resource::MNU_CON_LIVROS)
    FXMenuTitle.new(barraMenu, "&Pesquisas", nil, mnuPesquisas)

    # menu das vendas
    mnuVendas = FXMenuPane.new(self)
    @mnuVenderLivros = FXMenuCommand.new(mnuVendas, 
      "&Vender Livros\t\tVender Livros.",
      nil, self, Resource::MNU_VEN_VENDERLIVROS)
    @mnuVendasRealizadas = FXMenuCommand.new(mnuVendas, 
      "Vendas &Realizadas\t\tVendas Realizadas.",
      nil, self, Resource::MNU_VEN_VENDASREALIZADAS)
    FXMenuTitle.new(barraMenu, "&Vendas", nil, mnuVendas)

    # menu das janelas
    mnuJanelas = FXMenuPane.new(self)
    FXMenuCommand.new(mnuJanelas, "Lado a lado &horizontal", nil,
      @clienteMDI, FXMDIClient::ID_MDI_TILEHORIZONTAL)
    FXMenuCommand.new(mnuJanelas, "Lado a lado &vertical", nil,
      @clienteMDI, FXMDIClient::ID_MDI_TILEVERTICAL)
    FXMenuCommand.new(mnuJanelas, "Em &cascata", nil,
      @clienteMDI, FXMDIClient::ID_MDI_CASCADE)
    FXMenuCommand.new(mnuJanelas, "&Fechar janela", nil,
      @clienteMDI, FXMDIClient::ID_MDI_CLOSE)
    sepjanelas1 = FXMenuSeparator.new(mnuJanelas)
    sepjanelas1.setTarget(@clienteMDI)
    sepjanelas1.setSelector(FXMDIClient::ID_MDI_ANY)
    FXMenuCommand.new(mnuJanelas, nil, nil, @clienteMDI, FXMDIClient::ID_MDI_1)
    FXMenuCommand.new(mnuJanelas, nil, nil, @clienteMDI, FXMDIClient::ID_MDI_2)
    FXMenuCommand.new(mnuJanelas, nil, nil, @clienteMDI, FXMDIClient::ID_MDI_3)
    FXMenuCommand.new(mnuJanelas, nil, nil, @clienteMDI, FXMDIClient::ID_MDI_4)
    FXMenuTitle.new(barraMenu,"&Janelas", nil, mnuJanelas)
    
    # menu das opções
    mnuOpcoes = FXMenuPane.new(self)    
    @mnuAlterarSenha = FXMenuCommand.new(mnuOpcoes, 
      "&Alterar Senha\t\tAlteração de Senha.", nil, self, Resource::MNU_OP_ALTERARSENHA)
    FXMenuSeparator.new(mnuOpcoes)
    FXMenuCommand.new(mnuOpcoes, "&Sobre\t\tSobre o Sistema.",
      nil, self, Resource::MNU_OP_SOBRE)
    FXMenuCommand.new(mnuOpcoes, "Sa&ir\tCtrl-S\tSair do sistema.",
      nil, self, Resource::MNU_OP_SAIR)
    FXMenuTitle.new(barraMenu, "&Opções", nil, mnuOpcoes)  
  end

  def create
    super
    @fonteSistema.create
    mdichild = @clienteMDI.getMDIChildFirst()
    while mdichild
      sb = mdichild.contentWindow().verticalScrollbar()
      sb.setLine(@fonteSistema.fontHeight)
      mdichild = mdichild.getMDINext()
    end
  end 

  def onCmdCadAssuntos(sender, sel, ptr)
    @mnuCadAssuntos.disable()
    frmCadAssuntos = FRMCadAssuntos.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmCadAssuntos.create
    return true
  end
  
  def onCmdCadAutores(sender, sel, ptr)
    @mnuCadAutores.disable()
    frmCadAutores = FRMCadAutores.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmCadAutores.create
    return true
  end
  
  def onCmdCadEditoras(sender, sel, ptr)
    @mnuCadEditoras.disable()
    frmCadEditoras = FRMCadEditoras.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmCadEditoras.create
    return true
  end
  
  def onCmdCadEnderecos(sender, sel, ptr)
    @mnuCadEnderecos.disable()
    frmCadEnderecos = FRMCadEnderecos.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmCadEnderecos.create
    return true
  end
  
  def onCmdCadIdiomas(sender, sel, ptr)
    @mnuCadIdiomas.disable()
    frmCadIdiomas = FRMCadIdiomas.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmCadIdiomas.create
    return true
  end
  
  def onCmdCadPaises(sender, sel, ptr)
    @mnuCadPaises.disable()
    frmCadPaises = FRMCadPaises.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmCadPaises.create
    return true
  end
  
  def onCmdCadProfissoes(sender, sel, ptr)
    @mnuCadProfissoes.disable()
    frmCadProfissoes = FRMCadProfissoes.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmCadProfissoes.create
    return true
  end
  
  def onCmdCadClientes(sender, sel, ptr)
    @tlbCliente.disable()
    @mnuCadClientes.disable()
    frmCadClientes = FRMCadClientes.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmCadClientes.create
    return true
  end
  
  def onCmdCadLivros(sender, sel, ptr)
    @tlbLivro.disable()
    @mnuCadLivros.disable()
    frmCadLivros = FRMCadLivros.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmCadLivros.create
    return true
  end
  
  def onCmdConAssuntos(sender, sel, ptr)
    frmConAssuntos = FRMConAssuntos.new(self)
    frmConAssuntos.execute(PLACEMENT_SCREEN)
    return true
  end
  
  def onCmdConAutores(sender, sel, ptr)
    frmConAutores = FRMConAutores.new(self)
    frmConAutores.execute(PLACEMENT_SCREEN)
    return true
  end
  
  def onCmdConEditoras(sender, sel, ptr)
    frmConEditoras = FRMConEditoras.new(self)
    frmConEditoras.execute(PLACEMENT_SCREEN)
    return true
  end
  
  def onCmdConEnderecos(sender, sel, ptr)
    frmConEnderecos = FRMConEnderecos.new(self)
    frmConEnderecos.execute(PLACEMENT_SCREEN)
    return true
  end
  
  def onCmdConIdiomas(sender, sel, ptr)
    frmConIdiomas = FRMConIdiomas.new(self)
    frmConIdiomas.execute(PLACEMENT_SCREEN)
    return true
  end
  
  def onCmdConPaises(sender, sel, ptr)
    frmConPaises = FRMConPaises.new(self)
    frmConPaises.execute(PLACEMENT_SCREEN)
    return true
  end
  
  def onCmdConProfissoes(sender, sel, ptr)
    frmConProfissoes = FRMConProfissoes.new(self)
    frmConProfissoes.execute(PLACEMENT_SCREEN)
    return true
  end
  
  def onCmdConClientes(sender, sel, ptr)
    frmConClientes = FRMConClientes.new(self)
    frmConClientes.execute(PLACEMENT_SCREEN)
    return true
  end
  
  def onCmdConLivros(sender, sel, ptr)
    frmConLivros = FRMConLivros.new(self)
    frmConLivros.execute(PLACEMENT_SCREEN)
    return true
  end
  
  def onCmdVenderLivros(sender, sel, ptr)
    @tlbVenda.disable()
    @mnuVenderLivros.disable()
    frmVenderLivros = FRMVenderLivros.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmVenderLivros.create
    return true
  end
  
  def onCmdVendasRealizadas(sender, sel, ptr)
    @mnuVendasRealizadas.disable()
    frmConVendas = FRMConVendas.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmConVendas.create
    return true
  end
  
  def onCmdOpAlterarSenha(sender, sel, ptr)
    @mnuAlterarSenha.disable
    frmAlterarSenha = FRMAlterarSenha.new(@clienteMDI, @iconeMDI, @menuMDI)
    frmAlterarSenha.create
    return true
  end
  
  def onCmdOpSobre(sender, sel, ptr)
    frmSobre = FRMSobre.new(self)
    frmSobre.execute(PLACEMENT_SCREEN)
    return true
  end
  
  def onCmdOpSair(sender, sel, ptr)
    if FXMessageBox.question(self, MBOX_YES_NO, "Livrus Virtus",
       "Deseja sair do sistema?") == MBOX_CLICKED_NO
       return true
    end  
    getApp().exit(0)
    return true
  end

  def setLabStatus(sTexto)
     @labStatus.setText(sTexto)
  end

  def habilitaMenu(smenu)
    if smenu == "CadAssuntos"
      @mnuCadAssuntos.enable
    elsif smenu == "CadAutores"
      @mnuCadAutores.enable
    elsif smenu == "CadEditoras"     
      @mnuCadEditoras.enable
    elsif smenu == "CadEnderecos"    
      @mnuCadEnderecos.enable
    elsif smenu == "CadIdiomas"
      @mnuCadIdiomas.enable
    elsif smenu == "CadPaises"
      @mnuCadPaises.enable
    elsif smenu == "CadProfissoes"   
      @mnuCadProfissoes.enable
    elsif smenu == "CadClientes"     
      @mnuCadClientes.enable
    elsif smenu == "CadLivros"
      @mnuCadLivros.enable
    elsif smenu == "VenderLivros"    
      @mnuVenderLivros.enable
    elsif smenu == "VendasRealizadas"
      @mnuVendasRealizadas.enable
    elsif smenu == "AlterarSenha"
       @mnuAlterarSenha.enable
    end   
  end

  def habilitaToolButton(stlb)
    if stlb == "tlbCliente"
      @tlbCliente.enable
    elsif stlb == "tlbLivro"
      @tlbLivro.enable
    elsif stlb == "tlbVenda"
      @tlbVenda.enable
    end   
  end

end

