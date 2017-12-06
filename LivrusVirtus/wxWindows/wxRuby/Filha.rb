require 'wxruby'
require 'Principal'
require 'CadAssuntos'
require 'CadAutores'
require 'CadEditoras'
require 'CadEnderecos'
require 'CadIdiomas'
require 'CadPaises'
require 'CadProfissoes'
require 'CadClientes'
require 'CadLivros'
require 'VenderLivros'
require 'ConVendas'
require 'AlterarSenha'

class FrmFilha < Wx::MDIChildFrame
  def initialize(parent, nTelaAtiva)
    super(parent, -1, "Cadastro de ", Wx::Point.new(0, 0), 
      Wx::Size.new(342, 219), Wx::DEFAULT_FRAME_STYLE,"") 
    set_client_size(Wx::Size.new(330, 136))
    evt_close {|event| on_close(event)}

    if Wx::RUBY_PLATFORM == "WXMSW"
      set_icon(Wx::Icon.new("xpms\\Livrus.ico"))
    else
      set_icon(Wx::Icon.new("xpms\\livrus.xpm"))
    end
    @nLocalTelaAtiva = nTelaAtiva

    if nTelaAtiva == Resource::FRMCADASSUNTOS then
      FrmCadAssuntos.new(self)
      set_title(Resource::STR_CADASSUNTO)
    elsif nTelaAtiva == Resource::FRMCADAUTORES then
      FrmCadAutores.new(self)
      set_title(Resource::STR_CADAUTOR)
    elsif nTelaAtiva == Resource::FRMCADEDITORAS then
      FrmCadEditoras.new(self)
      set_title(Resource::STR_CADEDITORA)
    elsif nTelaAtiva == Resource::FRMCADENDERECOS then
      FrmCadEnderecos.new(self)
      set_title(Resource::STR_CADENDERECO)
      set_client_size(Wx::Size.new(525, 170))
    elsif nTelaAtiva == Resource::FRMCADIDIOMAS then
      FrmCadIdiomas.new(self)
      set_title(Resource::STR_CADIDIOMA)        
    elsif nTelaAtiva == Resource::FRMCADPAISES then
      FrmCadPaises.new(self)
      set_title(Resource::STR_CADPAIS)
    elsif nTelaAtiva == Resource::FRMCADPROFISSOES then
      FrmCadProfissoes.new(self)
      set_title(Resource::STR_CADPROFISS)
    elsif nTelaAtiva == Resource::FRMCADCLIENTES then
      $fCadClientes = FrmCadClientes.new(self)
      set_title(Resource::STR_CADCLIENTE)
      set_client_size(Wx::Size.new(525, 440))
    elsif nTelaAtiva == Resource::FRMCADLIVROS then
      $fCadLivros = FrmCadLivros.new(self)
      set_title(Resource::STR_CADLIVRO)
      set_client_size(Wx::Size.new(510, 425))        
    elsif nTelaAtiva == Resource::FRMVENDERLIVROS then
      $fVenderLivros = FrmVenderLivros.new(self)
      set_title(Resource::STR_VENLIVRO)
      set_client_size(Wx::Size.new(480, 310))        
    elsif nTelaAtiva == Resource::FRMCONVENDAS then
      $fConVendas = FrmConVendas.new(self)
      set_title(Resource::STR_CONVENLIVRO)
      set_client_size(Wx::Size.new(480, 330))
    elsif nTelaAtiva == Resource::FRMALTERARSENHA then
      FrmAlterarSenha.new(self)
      set_title(Resource::STR_ALTSENHA)
      set_client_size(Wx::Size.new(255, 134))
    end
  end

  def on_close(event)
    if @nLocalTelaAtiva == Resource::FRMCADASSUNTOS then
      $fPrincipal.retMenu(0).enable(Resource::MNU_CAD_ASSUNTOS, true) 
    elsif @nLocalTelaAtiva == Resource::FRMCADAUTORES then 
      $fPrincipal.retMenu(0).enable(Resource::MNU_CAD_AUTORES, true)  
    elsif @nLocalTelaAtiva == Resource::FRMCADEDITORAS then
      $fPrincipal.retMenu(0).enable(Resource::MNU_CAD_EDITORAS, true)    
    elsif @nLocalTelaAtiva == Resource::FRMCADENDERECOS then
      $fPrincipal.retMenu(0).enable(Resource::MNU_CAD_ENDERECOS, true)    
    elsif @nLocalTelaAtiva == Resource::FRMCADIDIOMAS then
      $fPrincipal.retMenu(0).enable(Resource::MNU_CAD_IDIOMAS, true)   
    elsif @nLocalTelaAtiva == Resource::FRMCADPAISES then 
      $fPrincipal.retMenu(0).enable(Resource::MNU_CAD_PAISES, true)    
    elsif @nLocalTelaAtiva == Resource::FRMCADPROFISSOES then 
      $fPrincipal.retMenu(0).enable(Resource::MNU_CAD_PROFISSOES, true)    
    elsif @nLocalTelaAtiva == Resource::FRMCADCLIENTES then
      $fPrincipal.retBarraFerra().enable_tool(Resource::MNU_CAD_CLIENTES, true)
      $fPrincipal.retMenu(0).enable(Resource::MNU_CAD_CLIENTES, true)   
    elsif @nLocalTelaAtiva == Resource::FRMCADLIVROS then
      $fPrincipal.retBarraFerra().enable_tool(Resource::MNU_CAD_LIVROS, true)
      $fPrincipal.retMenu(0).enable(Resource::MNU_CAD_LIVROS, true)
    elsif @nLocalTelaAtiva == Resource::FRMVENDERLIVROS then
      $fPrincipal.retBarraFerra().enable_tool(Resource::MNU_VEN_VENDERLIVROS, 
        true)
      $fPrincipal.retMenu(2).enable(Resource::MNU_VEN_VENDERLIVROS, true)  
    elsif @nLocalTelaAtiva == Resource::FRMCONVENDAS then 
      $fPrincipal.retMenu(2).enable(Resource::MNU_VEN_VENDASREALIZADAS, true)
    elsif @nLocalTelaAtiva == Resource::FRMALTERARSENHA then
      $fPrincipal.retMenu(3).enable(Resource::MNU_OP_ALTERARSENHA, true)
    end
    event.skip()
  end

end
