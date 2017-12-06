Imports System
Imports System.Drawing
Imports System.Collections
Imports Microsoft.VisualBasic
Imports wx
Imports System.IO

Namespace Livrus

	Public Class frmPrincipal
		Inherits wx.MDIParentFrame	
	
		public shared WithEvents fPrincipal as frmPrincipal
    private mnuCadastros as wx.Menu
    private mnuPesquisas as wx.Menu
    private mnuVendas as wx.Menu
    private mnuOpcoes as wx.Menu
    public barraMenu as wx.MenuBar
    private barraStatus as wx.StatusBar
    private nLarguras(2) as integer
    public barraFerra as wx.ToolBar

    Public Sub New()
        MyBase.New( nothing, -1, Resource.STR_TITULO, new Point( -1, -1 ), _
        new Size(640, 480) )

      Icon = new wx.Icon("xpms/livrus.xpm")

      'Barra de Menu
    	mnuCadastros = new wx.Menu()
    	mnuCadastros.Append(Resource.MNU_CAD_ASSUNTOS, "&Assuntos", Resource.STR_CADASSUNTO)
    	mnuCadastros.Append(Resource.MNU_CAD_AUTORES, "A&utores", Resource.STR_CADAUTOR)
    	mnuCadastros.Append(Resource.MNU_CAD_EDITORAS, "&Editoras", Resource.STR_CADEDITORA)
    	mnuCadastros.Append(Resource.MNU_CAD_ENDERECOS, "E&ndereços", Resource.STR_CADENDERECO)
    	mnuCadastros.Append(Resource.MNU_CAD_IDIOMAS, "&Idiomas", Resource.STR_CADIDIOMA)
    	mnuCadastros.Append(Resource.MNU_CAD_PAISES, "&Países", Resource.STR_CADPAIS)
    	mnuCadastros.Append(Resource.MNU_CAD_PROFISSOES, "P&rofissões", Resource.STR_CADPROFISS)
    	mnuCadastros.AppendSeparator()
    	mnuCadastros.Append(Resource.MNU_CAD_CLIENTES, "&Clientes", Resource.STR_CADCLIENTE)
    	mnuCadastros.Append(Resource.MNU_CAD_LIVROS, "&Livros", Resource.STR_CADLIVRO)
  
    	mnuPesquisas = new wx.Menu()
    	mnuPesquisas.Append(Resource.MNU_CON_ASSUNTOS, "&Assuntos", Resource.STR_CONASSUNTO)
    	mnuPesquisas.Append(Resource.MNU_CON_AUTORES, "A&utores", Resource.STR_CONAUTOR)
    	mnuPesquisas.Append(Resource.MNU_CON_EDITORAS, "&Editoras", Resource.STR_CONEDITORA)
    	mnuPesquisas.Append(Resource.MNU_CON_ENDERECOS, "E&ndereços", Resource.STR_CONENDERECO)
    	mnuPesquisas.Append(Resource.MNU_CON_IDIOMAS, "&Idiomas", Resource.STR_CONIDIOMA)
    	mnuPesquisas.Append(Resource.MNU_CON_PAISES, "&Países", Resource.STR_CONPAIS)
    	mnuPesquisas.Append(Resource.MNU_CON_PROFISSOES, "P&rofissões", Resource.STR_CONPROFISS)
    	mnuPesquisas.AppendSeparator()
    	mnuPesquisas.Append(Resource.MNU_CON_CLIENTES, "&Clientes", Resource.STR_CONCLIENTE)
    	mnuPesquisas.Append(Resource.MNU_CON_LIVROS, "&Livros", Resource.STR_CONLIVRO)
    
    	mnuVendas = new wx.Menu()
    	mnuVendas.Append(Resource.MNU_VEN_VENDERLIVROS, "&Vender Livros", Resource.STR_VENLIVRO)
    	mnuVendas.Append(Resource.MNU_VEN_VENDASREALIZADAS, "Vendas &Realizadas", Resource.STR_CONVENLIVRO)
    
    	mnuOpcoes = new wx.Menu()
    	mnuOpcoes.Append(Resource.MNU_OP_ALTERARSENHA, "&Alterar Senha", Resource.STR_ALTSENHA)
    	mnuOpcoes.AppendSeparator()
    	mnuOpcoes.Append(Resource.MNU_OP_SOBRE, "&Sobre", Resource.STR_OPSOBRE)
    	mnuOpcoes.Append(Resource.MNU_OP_SAIR, "Sa&ir"+chr(9)+"Ctrl-S", Resource.STR_OPSAIR)
    
    	barraMenu = new wx.MenuBar()
    	barraMenu.Append(mnuCadastros, "&Cadastros")
    	barraMenu.Append(mnuPesquisas, "&Pesquisas")
    	barraMenu.Append(mnuVendas, "&Vendas")
    	barraMenu.Append(mnuOpcoes, "&Opções")
    
    	MenuBar = barraMenu 
    
      'Barra de ferramentas    
      barraFerra = new wx.ToolBar(Me, -1, wxDefaultPosition, wxDefaultSize, _
        wx.ToolBar.wxTB_HORIZONTAL or wx.ToolBar.wxNO_BORDER)
      ToolBar = barraFerra
      barraFerra.AddTool(Resource.MNU_CAD_CLIENTES, "", _ 
        new wx.Bitmap("xpms/cliente.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), _ 
        "", wx.ItemKind.wxITEM_NORMAL)
    	barraFerra.AddTool(Resource.MNU_CAD_LIVROS, "", _ 
        new wx.Bitmap("xpms/livro.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), _ 
        "", wx.ItemKind.wxITEM_NORMAL)
    	barraFerra.AddTool(Resource.MNU_VEN_VENDERLIVROS, "", _ 
        new wx.Bitmap("xpms/livros.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), _ 
        "", wx.ItemKind.wxITEM_NORMAL)
      barraFerra.AddSeparator()
    	barraFerra.AddTool(Resource.MNU_OP_SOBRE, "", _ 
        new wx.Bitmap("xpms/sobre.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), _ 
        "", wx.ItemKind.wxITEM_NORMAL)
    	barraFerra.AddTool(Resource.MNU_OP_SAIR, "", _ 
        new wx.Bitmap("xpms/sair.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), _ 
        "", wx.ItemKind.wxITEM_NORMAL)
      barraFerra.Realize()

      barraStatus = CreateStatusBar(2)
      StatusBarPane = 1
      nLarguras(0) = 100
      nLarguras(1) = -1
      barraStatus.StatusWidths = nLarguras
      barraStatus.SetStatusText(Resource.STR_USUARIO, 0)
  
    	FazLayout()

      EVT_MENU(Resource.MNU_CAD_ASSUNTOS, new EventListener(AddressOf OnMnuCadAssuntos ))
      EVT_MENU(Resource.MNU_CAD_AUTORES, new EventListener(AddressOf OnMnuCadAutores ))
      EVT_MENU(Resource.MNU_CAD_EDITORAS, new EventListener(AddressOf OnMnuCadEditoras ))
      EVT_MENU(Resource.MNU_CAD_ENDERECOS, new EventListener(AddressOf OnMnuCadEnderecos ))
      EVT_MENU(Resource.MNU_CAD_IDIOMAS, new EventListener(AddressOf OnMnuCadIdiomas ))
      EVT_MENU(Resource.MNU_CAD_PAISES, new EventListener(AddressOf OnMnuCadPaises ))
      EVT_MENU(Resource.MNU_CAD_PROFISSOES, new EventListener(AddressOf OnMnuCadProfissoes ))
      EVT_MENU(Resource.MNU_CAD_CLIENTES, new EventListener(AddressOf OnMnuCadClientes ))
      EVT_MENU(Resource.MNU_CAD_LIVROS, new EventListener(AddressOf OnMnuCadLivros ))
  
      EVT_MENU(Resource.MNU_CON_ASSUNTOS, new EventListener(AddressOf OnMnuConAssuntos ))
      EVT_MENU(Resource.MNU_CON_AUTORES, new EventListener(AddressOf OnMnuConAutores ))
      EVT_MENU(Resource.MNU_CON_EDITORAS, new EventListener(AddressOf OnMnuConEditoras ))
      EVT_MENU(Resource.MNU_CON_ENDERECOS, new EventListener(AddressOf OnMnuConEnderecos ))
      EVT_MENU(Resource.MNU_CON_IDIOMAS, new EventListener(AddressOf OnMnuConIdiomas ))
      EVT_MENU(Resource.MNU_CON_PAISES, new EventListener(AddressOf OnMnuConPaises ))
      EVT_MENU(Resource.MNU_CON_PROFISSOES, new EventListener(AddressOf OnMnuConProfissoes ))
      EVT_MENU(Resource.MNU_CON_CLIENTES, new EventListener(AddressOf OnMnuConClientes ))
      EVT_MENU(Resource.MNU_CON_LIVROS, new EventListener(AddressOf OnMnuConLivros ))
  
      EVT_MENU(Resource.MNU_VEN_VENDERLIVROS, new EventListener(AddressOf OnMnuVenderLivros ))
      EVT_MENU(Resource.MNU_VEN_VENDASREALIZADAS, new EventListener(AddressOf OnMnuVendasRealizadas ))
  
      EVT_MENU(Resource.MNU_OP_ALTERARSENHA, new EventListener(AddressOf OnMnuAlterarSenha ))
      EVT_MENU(Resource.MNU_OP_SOBRE, new EventListener(AddressOf OnMnuSobre ))
      EVT_MENU(Resource.MNU_OP_SAIR, new EventListener(AddressOf OnClose ))

			EVT_CLOSE( new EventListener(AddressOf OnClose ) )
    End Sub
	
    public sub FazLayout()
      Me.Layout()
      Me.Centre()
    end sub

		public sub OnClose(ByVal sender As Object, ByVal e As wx.Event)
      dim mens as wx.MessageDialog
      mens = new wx.MessageDialog(Me, Resource.STR_SAIRSIS, "Confirma", _
       wx.Dialog.wxNO_DEFAULT or wx.Dialog.wxYES_NO or wx.Dialog.wxICON_QUESTION)
      if mens.ShowModal() = wx.Dialog.wxID_YES then
        Destroy()
      end if
		End Sub

    public sub OnMnuCadAssuntos(ByVal sender As Object, ByVal e As wx.Event)
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_ASSUNTOS, false)
      dim fCadAssuntos as frmFilha = new frmFilha(Me, Resource.FRMCADASSUNTOS)
      e.Skip()
    end sub
  
    public sub OnMnuCadAutores(ByVal sender As Object, ByVal e As wx.Event)
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_AUTORES, false)
      dim fCadAutores as frmFilha = new frmFilha(Me, Resource.FRMCADAUTORES)
      e.Skip()
    end sub
  
    public sub OnMnuCadEditoras(ByVal sender As Object, ByVal e As wx.Event)
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_EDITORAS, false)
      dim fCadEditoras as frmFilha = new frmFilha(Me, Resource.FRMCADEDITORAS)
      e.Skip()
    end sub
  
    public sub OnMnuCadEnderecos(ByVal sender As Object, ByVal e As wx.Event)
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_ENDERECOS, false)
      dim fCadEnderecos as frmFilha = new frmFilha(Me, Resource.FRMCADENDERECOS)
      e.Skip()
    end sub
  
    public sub OnMnuCadIdiomas(ByVal sender As Object, ByVal e As wx.Event)
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_IDIOMAS, false)
      dim fCadIdiomas as frmFilha = new frmFilha(Me, Resource.FRMCADIDIOMAS)
      e.Skip()
    end sub
  
    public sub OnMnuCadPaises(ByVal sender As Object, ByVal e As wx.Event)
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_PAISES, false)
      dim fCadPaises as frmFilha = new frmFilha(Me, Resource.FRMCADPAISES)
      e.Skip()
    end sub
  
    public sub OnMnuCadProfissoes(ByVal sender As Object, ByVal e As wx.Event)
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_PROFISSOES, false)
      dim fCadProfissoes as frmFilha = new frmFilha(Me, Resource.FRMCADPROFISSOES)
      e.Skip()
    end sub
  
    public sub OnMnuCadClientes(ByVal sender As Object, ByVal e As wx.Event)
      barraFerra.EnableTool(Resource.MNU_CAD_CLIENTES, false)
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_CLIENTES, false)
      dim fCadClientes as frmFilha = new frmFilha(Me, Resource.FRMCADCLIENTES)
      e.Skip()
    end sub
  
    public sub OnMnuCadLivros(ByVal sender As Object, ByVal e As wx.Event)
      barraFerra.EnableTool(Resource.MNU_CAD_LIVROS, false)
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_LIVROS, false)
      dim fCadLivros as frmFilha = new frmFilha(Me, Resource.FRMCADLIVROS)
      e.Skip()
    end sub
  
    public sub OnMnuConAssuntos(ByVal sender As Object, ByVal e As wx.Event)
      Me.StatusBar.SetStatusText(Resource.STR_CONASSUNTO,1)
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_ASSUNTOS, false)
      frmConAssuntos.fConAssuntos = new frmConAssuntos(Me)
      frmConAssuntos.fConAssuntos.Show(true)
    	e.Skip()
    end sub
  
    public sub OnMnuConAutores(ByVal sender As Object, ByVal e As wx.Event)
      Me.StatusBar.SetStatusText(Resource.STR_CONAUTOR,1)
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_AUTORES, false)
      frmConAutores.fConAutores = new frmConAutores(Me)
      frmConAutores.fConAutores.Show(true)
    	e.Skip()
    end sub
  
    public sub OnMnuConEditoras(ByVal sender As Object, ByVal e As wx.Event)
      Me.StatusBar.SetStatusText(Resource.STR_CONEDITORA,1)
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_EDITORAS, false)
      frmConEditoras.fConEditoras = new frmConEditoras(Me)
      frmConEditoras.fConEditoras.Show(true)
    	e.Skip()
    end sub
  
    public sub OnMnuConEnderecos(ByVal sender As Object, ByVal e As wx.Event)
      Me.StatusBar.SetStatusText(Resource.STR_CONENDERECO,1)
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_ENDERECOS, false)
      frmConEnderecos.fConEnderecos = new frmConEnderecos(Me)
      frmConEnderecos.fConEnderecos.Show(true)
      e.Skip()
    end sub
  
    public sub OnMnuConIdiomas(ByVal sender As Object, ByVal e As wx.Event)
      Me.StatusBar.SetStatusText(Resource.STR_CONIDIOMA,1)
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_IDIOMAS, false)
      frmConIdiomas.fConIdiomas = new frmConIdiomas(Me)
      frmConIdiomas.fConIdiomas.Show(true)
    	e.Skip()
    end sub
  
    public sub OnMnuConPaises(ByVal sender As Object, ByVal e As wx.Event)
      Me.StatusBar.SetStatusText(Resource.STR_CONPAIS,1)
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_PAISES, false)
      frmConPaises.fConPaises = new frmConPaises(Me)
      frmConPaises.fConPaises.Show(true)
    	e.Skip()
    end sub
  
    public sub OnMnuConProfissoes(ByVal sender As Object, ByVal e As wx.Event)
      Me.StatusBar.SetStatusText(Resource.STR_CONPROFISS,1)
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_PROFISSOES, false)
      frmConProfissoes.fConProfissoes = new frmConProfissoes(Me)
      frmConProfissoes.fConProfissoes.Show(true)
    	e.Skip()
    end sub
  
    public sub OnMnuConClientes(ByVal sender As Object, ByVal e As wx.Event)
      Me.StatusBar.SetStatusText(Resource.STR_CONCLIENTE,1)
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_CLIENTES, false)
      frmConClientes.fConClientes = new frmConClientes(Me)
      frmConClientes.fConClientes.Show(true)
    	e.Skip()
    end sub
  
    public sub OnMnuConLivros(ByVal sender As Object, ByVal e As wx.Event)
      Me.StatusBar.SetStatusText(Resource.STR_CONLIVRO,1)
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_LIVROS, false)
      frmConLivros.fConLivros = new frmConLivros(Me)
      frmConLivros.fConLivros.Show(true)
    	e.Skip()
    end sub
  
    public sub OnMnuVenderLivros(ByVal sender As Object, ByVal e As wx.Event)
      barraFerra.EnableTool(Resource.MNU_VEN_VENDERLIVROS, false)
      barraMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDERLIVROS, false)
      dim fVenderLivros as frmFilha = new frmFilha(Me, Resource.FRMVENDERLIVROS)
      e.Skip()
    end sub
  
    public sub OnMnuVendasRealizadas(ByVal sender As Object, ByVal e As wx.Event)
      barraMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDASREALIZADAS, false)
      dim fVendasRealizadas as frmFilha = new frmFilha(Me, Resource.FRMCONVENDAS)
      e.Skip()
    end sub
  
    public sub OnMnuAlterarSenha(ByVal sender As Object, ByVal e As wx.Event)
      barraMenu.GetMenu(3).Enable(Resource.MNU_OP_ALTERARSENHA, false)
      dim fAlterarSenha as frmFilha = new frmFilha(Me, Resource.FRMALTERARSENHA)
      e.Skip()
    end sub
   
    public sub OnMnuSobre(ByVal sender As Object, ByVal e As wx.Event)
      frmSobre.fSobre = new frmSobre(Me)
      frmSobre.fSobre.ShowModal()
      e.Skip()
		end sub

	End Class
End Namespace
