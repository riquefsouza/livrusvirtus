Imports System
Imports System.Drawing
Imports System.Collections
Imports Microsoft.VisualBasic
Imports wx

Namespace Livrus

	Public Class frmFilha
		Inherits wx.MDIChildFrame

    private nLocalTelaAtiva as integer

    private fCadAssuntos as frmCadAssuntos
    private fCadAutores as frmCadAutores
    private fCadEditoras as frmCadEditoras
    private fCadEnderecos as frmCadEnderecos
    private fCadIdiomas as frmCadIdiomas
    private fCadPaises as frmCadPaises
    private fCadProfissoes as frmCadProfissoes
    private fCadClientes as frmCadClientes
    private fCadLivros as frmCadLivros
    private fVenderLivros as frmVenderLivros
    private fConVendas as frmConVendas
    private fAlterarSenha as frmAlterarSenha
		
		public Sub New(ByVal parent as MDIParentFrame, ByVal nTelaAtiva as integer )
			MyBase.New(parent, -1, "Cadastro de ", new Point(0, 0), _
        new Size(342, 219), wxDEFAULT_FRAME_STYLE,"")

      ClientSize = new Size(330, 136)
			Icon = new wx.Icon( "xpms/livrus.xpm" )
			EVT_CLOSE( new EventListener(AddressOf OnClose ) )
      nLocalTelaAtiva = nTelaAtiva
  
      if nTelaAtiva = Resource.FRMCADASSUNTOS then
        fCadAssuntos = new frmCadAssuntos(Me)
        Title = Resource.STR_CADASSUNTO
      else if nTelaAtiva = Resource.FRMCADAUTORES then
        fCadAutores = new frmCadAutores(Me)
        Title = Resource.STR_CADAUTOR
      else if nTelaAtiva = Resource.FRMCADEDITORAS then
        fCadEditoras = new frmCadEditoras(Me)
        Title = Resource.STR_CADEDITORA
      else if nTelaAtiva = Resource.FRMCADENDERECOS then
        fCadEnderecos = new frmCadEnderecos(Me)
        Title = Resource.STR_CADENDERECO
        ClientSize = new Size(525, 170)
      else if nTelaAtiva = Resource.FRMCADIDIOMAS then
        fCadIdiomas = new frmCadIdiomas(Me)
        Title = Resource.STR_CADIDIOMA
      else if nTelaAtiva = Resource.FRMCADPAISES then
        fCadPaises = new frmCadPaises(Me)
        Title = Resource.STR_CADPAIS
      else if nTelaAtiva = Resource.FRMCADPROFISSOES then
        fCadProfissoes = new frmCadProfissoes(Me)
        Title = Resource.STR_CADPROFISS
      else if nTelaAtiva = Resource.FRMCADCLIENTES then
        fCadClientes = new frmCadClientes(Me)
        Title = Resource.STR_CADCLIENTE
        ClientSize = new Size(525, 440)
      else if nTelaAtiva = Resource.FRMCADLIVROS then
        fCadLivros = new frmCadLivros(Me)
        Title = Resource.STR_CADLIVRO
        ClientSize = new Size(510, 385)
      else if nTelaAtiva = Resource.FRMVENDERLIVROS then
        fVenderLivros = new frmVenderLivros(Me)
        Title = Resource.STR_VENLIVRO
        ClientSize = new Size(480, 310)
      else if nTelaAtiva = Resource.FRMCONVENDAS then
        fConVendas = new frmConVendas(Me)
        Title = Resource.STR_CONVENLIVRO
        ClientSize = new Size(480, 330)
      else if nTelaAtiva = Resource.FRMALTERARSENHA then
        fAlterarSenha = new frmAlterarSenha(Me)
        Title = Resource.STR_ALTSENHA
        ClientSize = new Size(255, 134)
      end if
		end sub

		Overrides public sub OnActivate(ByVal sender As Object, ByVal e As wx.Event)
			dim ae as wx.ActivateEvent = CType(e, wx.ActivateEvent)
			if ae.Active then
        if nLocalTelaAtiva = Resource.FRMCADASSUNTOS then
          fCadAssuntos.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMCADAUTORES then
          fCadAutores.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMCADEDITORAS then
          fCadEditoras.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMCADENDERECOS then
          fCadEnderecos.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMCADIDIOMAS then
          fCadIdiomas.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMCADPAISES then
          fCadPaises.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMCADPROFISSOES then
          fCadProfissoes.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMCADCLIENTES then
          fCadClientes.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMCADLIVROS then
          fCadLivros.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMVENDERLIVROS then
          fVenderLivros.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMCONVENDAS then
          fConVendas.SetFocus()
        else if nLocalTelaAtiva = Resource.FRMALTERARSENHA then
          fAlterarSenha.SetFocus()
        end if
      end if
		end sub

		Private Sub OnClose(ByVal sender As Object, ByVal e As wx.Event)
      if nLocalTelaAtiva = Resource.FRMCADASSUNTOS then
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_ASSUNTOS, true)
      else if nLocalTelaAtiva = Resource.FRMCADAUTORES then 
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_AUTORES, true)
      else if nLocalTelaAtiva = Resource.FRMCADEDITORAS then
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_EDITORAS, true)    
      else if nLocalTelaAtiva = Resource.FRMCADENDERECOS then
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_ENDERECOS, true)    
      else if nLocalTelaAtiva = Resource.FRMCADIDIOMAS then
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_IDIOMAS, true)
      else if nLocalTelaAtiva = Resource.FRMCADPAISES then 
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_PAISES, true)    
      else if nLocalTelaAtiva = Resource.FRMCADPROFISSOES then 
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_PROFISSOES, true)
      else if nLocalTelaAtiva = Resource.FRMCADCLIENTES then 
        frmPrincipal.fPrincipal.barraFerra.EnableTool(Resource.MNU_CAD_CLIENTES, true)
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_CLIENTES, true)
      else if nLocalTelaAtiva = Resource.FRMCADLIVROS then 
        frmPrincipal.fPrincipal.barraFerra.EnableTool(Resource.MNU_CAD_LIVROS, true)
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_LIVROS, true)
      else if nLocalTelaAtiva = Resource.FRMVENDERLIVROS then 
        frmPrincipal.fPrincipal.barraFerra.EnableTool(Resource.MNU_VEN_VENDERLIVROS, true)
        frmPrincipal.fPrincipal.barraMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDERLIVROS, true)  
      else if nLocalTelaAtiva = Resource.FRMCONVENDAS then 
        frmPrincipal.fPrincipal.barraMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDASREALIZADAS, true)
      else if nLocalTelaAtiva = Resource.FRMALTERARSENHA then
        frmPrincipal.fPrincipal.barraMenu.GetMenu(3).Enable(Resource.MNU_OP_ALTERARSENHA, true)
      end if
      e.Skip()
		end sub

	End Class
End Namespace
