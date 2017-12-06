require 'wxruby'
require 'resource'
require 'RotinasGlobais'
require 'Sobre'
require 'Filha'
require 'ConAssuntos'
require 'ConAutores'
require 'ConEditoras'
require 'ConEnderecos'
require 'ConIdiomas'
require 'ConPaises'
require 'ConProfissoes'
require 'ConClientes'
require 'ConLivros'

$fPrincipal = nil

class FrmPrincipal < Wx::MDIParentFrame
  def initialize()
    super(nil, -1, "Livrus Virtus", Wx::DEFAULT_POSITION, 
      Wx::DEFAULT_SIZE, Wx::DEFAULT_FRAME_STYLE,"")
    evt_close {|event| on_close(event)}

  	# Barra de Menu
  
  	@mnuCadastros = Wx::Menu.new()
  	@mnuCadastros.append(Resource::MNU_CAD_ASSUNTOS, "&Assuntos", Resource::STR_CADASSUNTO)
  	@mnuCadastros.append(Resource::MNU_CAD_AUTORES, "A&utores", Resource::STR_CADAUTOR)
  	@mnuCadastros.append(Resource::MNU_CAD_EDITORAS, "&Editoras", Resource::STR_CADEDITORA)
  	@mnuCadastros.append(Resource::MNU_CAD_ENDERECOS, "E&ndereços", Resource::STR_CADENDERECO)
  	@mnuCadastros.append(Resource::MNU_CAD_IDIOMAS, "&Idiomas", Resource::STR_CADIDIOMA)
  	@mnuCadastros.append(Resource::MNU_CAD_PAISES, "&Países", Resource::STR_CADPAIS)
  	@mnuCadastros.append(Resource::MNU_CAD_PROFISSOES, "P&rofissões", Resource::STR_CADPROFISS)
  	@mnuCadastros.append_separator()
  	@mnuCadastros.append(Resource::MNU_CAD_CLIENTES, "&Clientes", Resource::STR_CADCLIENTE)
  	@mnuCadastros.append(Resource::MNU_CAD_LIVROS, "&Livros", Resource::STR_CADLIVRO)

  	@mnuPesquisas = Wx::Menu.new()
  	@mnuPesquisas.append(Resource::MNU_CON_ASSUNTOS, "&Assuntos", Resource::STR_CONASSUNTO)
  	@mnuPesquisas.append(Resource::MNU_CON_AUTORES, "A&utores", Resource::STR_CONAUTOR)
  	@mnuPesquisas.append(Resource::MNU_CON_EDITORAS, "&Editoras", Resource::STR_CONEDITORA)
  	@mnuPesquisas.append(Resource::MNU_CON_ENDERECOS, "E&ndereços", Resource::STR_CONENDERECO)
  	@mnuPesquisas.append(Resource::MNU_CON_IDIOMAS, "&Idiomas", Resource::STR_CONIDIOMA)
  	@mnuPesquisas.append(Resource::MNU_CON_PAISES, "&Países", Resource::STR_CONPAIS)
  	@mnuPesquisas.append(Resource::MNU_CON_PROFISSOES, "P&rofissões", Resource::STR_CONPROFISS)
  	@mnuPesquisas.append_separator()
  	@mnuPesquisas.append(Resource::MNU_CON_CLIENTES, "&Clientes", Resource::STR_CONCLIENTE)
  	@mnuPesquisas.append(Resource::MNU_CON_LIVROS, "&Livros", Resource::STR_CONLIVRO)
  
  	@mnuVendas = Wx::Menu.new()
  	@mnuVendas.append(Resource::MNU_VEN_VENDERLIVROS, "&Vender Livros", Resource::STR_VENLIVRO)
  	@mnuVendas.append(Resource::MNU_VEN_VENDASREALIZADAS, "Vendas &Realizadas", Resource::STR_CONVENLIVRO)
  
  	@mnuOpcoes = Wx::Menu.new()
  	@mnuOpcoes.append(Resource::MNU_OP_ALTERARSENHA, "&Alterar Senha", Resource::STR_ALTSENHA)
  	@mnuOpcoes.append_separator()
  	@mnuOpcoes.append(Resource::MNU_OP_SOBRE, "&Sobre", Resource::STR_OPSOBRE)
  	@mnuOpcoes.append(Resource::MNU_OP_SAIR, "Sa&ir\tCtrl-S", Resource::STR_OPSAIR)
  
  	barraMenu = Wx::MenuBar.new()
  	barraMenu.append(@mnuCadastros, "&Cadastros")
  	barraMenu.append(@mnuPesquisas, "&Pesquisas")
  	barraMenu.append(@mnuVendas, "&Vendas")
  	barraMenu.append(@mnuOpcoes, "&Opções")
  
  	set_menu_bar(barraMenu)

    evt_menu(Resource::MNU_CAD_ASSUNTOS) {|event| on_MnuCadAssuntos(event)}
    evt_menu(Resource::MNU_CAD_AUTORES) {|event| on_MnuCadAutores(event)}
    evt_menu(Resource::MNU_CAD_EDITORAS) {|event| on_MnuCadEditoras(event)}
    evt_menu(Resource::MNU_CAD_ENDERECOS) {|event| on_MnuCadEnderecos(event)}
    evt_menu(Resource::MNU_CAD_IDIOMAS) {|event| on_MnuCadIdiomas(event)}
    evt_menu(Resource::MNU_CAD_PAISES) {|event| on_MnuCadPaises(event)}
    evt_menu(Resource::MNU_CAD_PROFISSOES) {|event| on_MnuCadProfissoes(event)}
    evt_menu(Resource::MNU_CAD_CLIENTES) {|event| on_MnuCadClientes(event)}
    evt_menu(Resource::MNU_CAD_LIVROS) {|event| on_MnuCadLivros(event)}

    evt_menu(Resource::MNU_CON_ASSUNTOS) {|event| on_MnuConAssuntos(event)}
    evt_menu(Resource::MNU_CON_AUTORES) {|event| on_MnuConAutores(event)}
    evt_menu(Resource::MNU_CON_EDITORAS) {|event| on_MnuConEditoras(event)}
    evt_menu(Resource::MNU_CON_ENDERECOS) {|event| on_MnuConEnderecos(event)}
    evt_menu(Resource::MNU_CON_IDIOMAS) {|event| on_MnuConIdiomas(event)}
    evt_menu(Resource::MNU_CON_PAISES) {|event| on_MnuConPaises(event)}
    evt_menu(Resource::MNU_CON_PROFISSOES) {|event| on_MnuConProfissoes(event)}
    evt_menu(Resource::MNU_CON_CLIENTES) {|event| on_MnuConClientes(event)}
    evt_menu(Resource::MNU_CON_LIVROS) {|event| on_MnuConLivros(event)}

    evt_menu(Resource::MNU_VEN_VENDERLIVROS) {|event| on_MnuVenderLivros(event)}
    evt_menu(Resource::MNU_VEN_VENDASREALIZADAS) {|event| on_MnuVendasRealizadas(event)}

    evt_menu(Resource::MNU_OP_ALTERARSENHA) {|event| on_MnuAlterarSenha(event)}
    evt_menu(Resource::MNU_OP_SOBRE) {|event| on_MnuSobre(event)}
    evt_menu(Resource::MNU_OP_SAIR) {|event| on_close(event)}

    barraStatus = create_status_bar(2)
    set_status_bar_pane(1)	
    barraStatus.set_status_widths([100,-1])
    barraStatus.set_status_text(Resource::STR_USUARIO, 0) 	
  
    # Barra de ferramentas
  
    barraFerra = Wx::ToolBar.new(self, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, 
      Wx::TB_HORIZONTAL | Wx::NO_BORDER)
    set_tool_bar(barraFerra)    
    barraFerra.add_tool(Resource::MNU_CAD_CLIENTES, "", 
      Wx::Bitmap.new("xpms\\cliente.xpm", Wx::BITMAP_TYPE_ANY), "", Wx::ITEM_NORMAL)
  	barraFerra.add_tool(Resource::MNU_CAD_LIVROS, "", 
      Wx::Bitmap.new("xpms\\livro.xpm", Wx::BITMAP_TYPE_ANY), "", Wx::ITEM_NORMAL)
  	barraFerra.add_tool(Resource::MNU_VEN_VENDERLIVROS, "", 
      Wx::Bitmap.new("xpms\\livros.xpm", Wx::BITMAP_TYPE_ANY), "", Wx::ITEM_NORMAL)
    barraFerra.add_separator()
  	barraFerra.add_tool(Resource::MNU_OP_SOBRE, "", 
      Wx::Bitmap.new("xpms\\sobre.xpm", Wx::BITMAP_TYPE_ANY), "", Wx::ITEM_NORMAL)
  	barraFerra.add_tool(Resource::MNU_OP_SAIR, "", 
      Wx::Bitmap.new("xpms\\sair.xpm", Wx::BITMAP_TYPE_ANY), "", Wx::ITEM_NORMAL)
    barraFerra.realize()

    if Wx::RUBY_PLATFORM == "WXMSW"
      set_icon(Wx::Icon.new("xpms\\Livrus.ico"))
    else
      set_icon(Wx::Icon.new("xpms\\livrus.xpm"))
    end

  	FazLayout()
    
  end  

  def FazLayout() 
    self.layout()
    self.centre()
  end

  def retMenu(nMenu)
    if nMenu == 0 then
      return @mnuCadastros
    elsif nMenu == 1 then
      return @mnuPesquisas
    elsif nMenu == 2 then
      return @mnuVendas
    elsif nMenu == 3 then
      return @mnuOpcoes
    end
  end

  def retBarraFerra()
    return self.get_tool_bar()
  end

  def on_close(event)
    mens = Wx::MessageDialog.new(self, Resource::STR_SAIRSIS, "Confirma",
             Wx::NO_DEFAULT | Wx::YES_NO | Wx::ICON_QUESTION)
    if mens.show_modal() == Wx::ID_YES then
      destroy()
    end
  end

  def on_MnuCadAssuntos(event)
    @mnuCadastros.enable(Resource::MNU_CAD_ASSUNTOS, false)
    frmCadAssuntos = FrmFilha.new(self,Resource::FRMCADASSUNTOS)
    event.skip()
  end

  def on_MnuCadAutores(event)
    @mnuCadastros.enable(Resource::MNU_CAD_AUTORES, false)
    frmCadAutores = FrmFilha.new(self,Resource::FRMCADAUTORES)
    event.skip()
  end

  def on_MnuCadEditoras(event)
    @mnuCadastros.enable(Resource::MNU_CAD_EDITORAS, false)
    frmCadEditoras = FrmFilha.new(self,Resource::FRMCADEDITORAS)
    event.skip()
  end

  def on_MnuCadEnderecos(event)
    @mnuCadastros.enable(Resource::MNU_CAD_ENDERECOS, false)
    frmCadEnderecos = FrmFilha.new(self,Resource::FRMCADENDERECOS)
    event.skip()
  end

  def on_MnuCadIdiomas(event)
    @mnuCadastros.enable(Resource::MNU_CAD_IDIOMAS, false)
    frmCadIdiomas = FrmFilha.new(self,Resource::FRMCADIDIOMAS)
    event.skip()
  end

  def on_MnuCadPaises(event)
    @mnuCadastros.enable(Resource::MNU_CAD_PAISES, false)
    frmCadPaises = FrmFilha.new(self,Resource::FRMCADPAISES)
    event.skip()
  end

  def on_MnuCadProfissoes(event)
    @mnuCadastros.enable(Resource::MNU_CAD_PROFISSOES, false)
    frmCadProfissoes = FrmFilha.new(self,Resource::FRMCADPROFISSOES)
    event.skip()
  end

  def on_MnuCadClientes(event)
    self.get_tool_bar().enable_tool(Resource::MNU_CAD_CLIENTES, false)
    @mnuCadastros.enable(Resource::MNU_CAD_CLIENTES, false)
    frmCadClientes = FrmFilha.new(self,Resource::FRMCADCLIENTES)
    event.skip()
  end

  def on_MnuCadLivros(event)
    self.get_tool_bar().enable_tool(Resource::MNU_CAD_LIVROS, false)
    @mnuCadastros.enable(Resource::MNU_CAD_LIVROS, false)
    frmCadLivros = FrmFilha.new(self,Resource::FRMCADLIVROS)
    event.skip()
  end

  def on_MnuConAssuntos(event)
    self.get_status_bar().set_status_text(Resource::STR_CONASSUNTO,1)
    @mnuPesquisas.enable(Resource::MNU_CON_ASSUNTOS, false)
    fConAssuntos = FrmConAssuntos.new(self)
    fConAssuntos.show(true)
  	event.skip()
  end

  def on_MnuConAutores(event)
    self.get_status_bar().set_status_text(Resource::STR_CONAUTOR,1)
    @mnuPesquisas.enable(Resource::MNU_CON_AUTORES, false)
    fConAutores = FrmConAutores.new(self)
    fConAutores.show(true)
  	event.skip()
  end

  def on_MnuConEditoras(event)
    self.get_status_bar().set_status_text(Resource::STR_CONEDITORA,1)
    @mnuPesquisas.enable(Resource::MNU_CON_EDITORAS, false)
    fConEditoras = FrmConEditoras.new(self)
    fConEditoras.show(true)
  	event.skip()
  end

  def on_MnuConEnderecos(event)
    self.get_status_bar().set_status_text(Resource::STR_CONENDERECO,1)
    @mnuPesquisas.enable(Resource::MNU_CON_ENDERECOS, false)
    fConEnderecos = FrmConEnderecos.new(self)
    fConEnderecos.show(true)
    event.skip()
  end

  def on_MnuConIdiomas(event)
    self.get_status_bar().set_status_text(Resource::STR_CONIDIOMA,1)
    @mnuPesquisas.enable(Resource::MNU_CON_IDIOMAS, false)
    fConIdiomas = FrmConIdiomas.new(self)
    fConIdiomas.show(true)
  	event.skip()
  end

  def on_MnuConPaises(event)
    self.get_status_bar().set_status_text(Resource::STR_CONPAIS,1)
    @mnuPesquisas.enable(Resource::MNU_CON_PAISES, false)
    fConPaises = FrmConPaises.new(self)
    frmConPaises.show(true)
  	event.skip()
  end

  def on_MnuConProfissoes(event)
    self.get_status_bar().set_status_text(Resource::STR_CONPROFISS,1)
    @mnuPesquisas.enable(Resource::MNU_CON_PROFISSOES, false)
    fConProfissoes = FrmConProfissoes.new(self)
    fConProfissoes.show(true)
  	event.skip()
  end

  def on_MnuConClientes(event)
    self.get_status_bar().set_status_text(Resource::STR_CONCLIENTE,1)
    @mnuPesquisas.enable(Resource::MNU_CON_CLIENTES, false)
    fConClientes = FrmConClientes.new(self)
    fConClientes.show(true)
  	event.skip()
  end

  def on_MnuConLivros(event)
    self.get_status_bar().set_status_text(Resource::STR_CONLIVRO,1)
    @mnuPesquisas.enable(Resource::MNU_CON_LIVROS, false)
    fConLivros = FrmConLivros.new(self)
    fConLivros.show(true)
  	event.skip()
  end

  def on_MnuVenderLivros(event)
    self.get_tool_bar().enable_tool(Resource::MNU_VEN_VENDERLIVROS, false)
    @mnuVendas.enable(Resource::MNU_VEN_VENDERLIVROS, false)
    frmVenderLivros = FrmFilha.new(self,Resource::FRMVENDERLIVROS)
    event.skip()
  end

  def on_MnuVendasRealizadas(event)
    @mnuVendas.enable(Resource::MNU_VEN_VENDASREALIZADAS, false)
    frmVendasRealizadas = FrmFilha.new(self,Resource::FRMCONVENDAS)
    event.skip()
  end

  def on_MnuAlterarSenha(event)
    @mnuOpcoes.enable(Resource::MNU_OP_ALTERARSENHA, false)
    frmAlterarSenha = FrmFilha.new(self,Resource::FRMALTERARSENHA)
    event.skip()
  end
 
  def on_MnuSobre(event)
    frmSobre = FrmSobre.new(self)
    frmSobre.show_modal()
  	event.skip()
  end

end
