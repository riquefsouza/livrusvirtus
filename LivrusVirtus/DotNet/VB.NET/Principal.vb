Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb
Imports Microsoft.VisualBasic

Namespace Livrus

Public Class frmPrincipal
    Inherits System.Windows.Forms.Form

		public shared WithEvents fPrincipal as frmPrincipal

		public statusBar1 as System.Windows.Forms.StatusBar
		public db as System.Data.OleDb.OleDbConnection

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call

    End Sub

    'Form overrides dispose to clean up the component list.
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer
    private WithEvents mainMenu1 As System.Windows.Forms.MainMenu
    private WithEvents mnuCadastros As System.Windows.Forms.MenuItem
    public WithEvents mnuCadAssuntos As System.Windows.Forms.MenuItem
    private statusBarPanel1 As System.Windows.Forms.StatusBarPanel
    private statusBarPanel2 As System.Windows.Forms.StatusBarPanel
    private WithEvents toolBar1 As System.Windows.Forms.ToolBar
    public tlbClientes As System.Windows.Forms.ToolBarButton
    public tlbLivros As System.Windows.Forms.ToolBarButton
    public tlbVender As System.Windows.Forms.ToolBarButton
    private toolBarButton4 As System.Windows.Forms.ToolBarButton
    private tlbSobre As System.Windows.Forms.ToolBarButton
    private tlbSair As System.Windows.Forms.ToolBarButton
    private imageList1 As System.Windows.Forms.ImageList
    public WithEvents mnuCadAutores As System.Windows.Forms.MenuItem
    public WithEvents mnuCadEditoras As System.Windows.Forms.MenuItem
    public WithEvents mnuCadEnderecos As System.Windows.Forms.MenuItem
    public WithEvents mnuCadIdiomas As System.Windows.Forms.MenuItem
    public WithEvents mnuCadPaises As System.Windows.Forms.MenuItem
    public WithEvents mnuCadProfissoes As System.Windows.Forms.MenuItem
    private menuItem1 As System.Windows.Forms.MenuItem
    public WithEvents mnuCadClientes As System.Windows.Forms.MenuItem
    public WithEvents mnuCadLivros As System.Windows.Forms.MenuItem
    private WithEvents mnuPesquisas As System.Windows.Forms.MenuItem
    public WithEvents mnuConAssuntos As System.Windows.Forms.MenuItem
    public WithEvents mnuConAutores As System.Windows.Forms.MenuItem
    public WithEvents mnuConEditoras As System.Windows.Forms.MenuItem
    public WithEvents mnuConEnderecos As System.Windows.Forms.MenuItem
    public WithEvents mnuConIdiomas As System.Windows.Forms.MenuItem
    public WithEvents mnuConPaises As System.Windows.Forms.MenuItem
    public WithEvents mnuConProfissoes As System.Windows.Forms.MenuItem
    private menuItem2 As System.Windows.Forms.MenuItem
    public WithEvents mnuConClientes As System.Windows.Forms.MenuItem
    public WithEvents mnuConLivros As System.Windows.Forms.MenuItem
    private mnuVendas As System.Windows.Forms.MenuItem
    public WithEvents mnuVenderLivros As System.Windows.Forms.MenuItem
    public WithEvents mnuVendasRealizadas As System.Windows.Forms.MenuItem
    private mnuJanelas As System.Windows.Forms.MenuItem
    private WithEvents mnuLadoALadoHorizontal As System.Windows.Forms.MenuItem
    private WithEvents mnuLadoALadoVertical As System.Windows.Forms.MenuItem
    private WithEvents mnuEmCascata As System.Windows.Forms.MenuItem
    private WithEvents mnuOrganizarIcones As System.Windows.Forms.MenuItem
    private WithEvents mnuOpcoes As System.Windows.Forms.MenuItem
    public WithEvents mnuAlterarSenha As System.Windows.Forms.MenuItem
    private menuItem3 As System.Windows.Forms.MenuItem
    private WithEvents mnuSobre As System.Windows.Forms.MenuItem
    private WithEvents mnuSair As System.Windows.Forms.MenuItem

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()
        Me.Text = "Livrus Virtus"
		Dim resources as System.Resources.ResourceManager = new _
        System.Resources.ResourceManager(GetType(frmPrincipal))
		Me.mainMenu1 = new System.Windows.Forms.MainMenu()
		Me.mnuCadastros = new System.Windows.Forms.MenuItem()
		Me.mnuCadAssuntos = new System.Windows.Forms.MenuItem()
		Me.mnuCadAutores = new System.Windows.Forms.MenuItem()
		Me.mnuCadEditoras = new System.Windows.Forms.MenuItem()
		Me.mnuCadEnderecos = new System.Windows.Forms.MenuItem()
		Me.mnuCadIdiomas = new System.Windows.Forms.MenuItem()
		Me.mnuCadPaises = new System.Windows.Forms.MenuItem()
		Me.mnuCadProfissoes = new System.Windows.Forms.MenuItem()
		Me.menuItem1 = new System.Windows.Forms.MenuItem()
		Me.mnuCadClientes = new System.Windows.Forms.MenuItem()
		Me.mnuCadLivros = new System.Windows.Forms.MenuItem()
		Me.mnuPesquisas = new System.Windows.Forms.MenuItem()
		Me.mnuConAssuntos = new System.Windows.Forms.MenuItem()
		Me.mnuConAutores = new System.Windows.Forms.MenuItem()
		Me.mnuConEditoras = new System.Windows.Forms.MenuItem()
		Me.mnuConEnderecos = new System.Windows.Forms.MenuItem()
		Me.mnuConIdiomas = new System.Windows.Forms.MenuItem()
		Me.mnuConPaises = new System.Windows.Forms.MenuItem()
		Me.mnuConProfissoes = new System.Windows.Forms.MenuItem()
		Me.menuItem2 = new System.Windows.Forms.MenuItem()
		Me.mnuConClientes = new System.Windows.Forms.MenuItem()
		Me.mnuConLivros = new System.Windows.Forms.MenuItem()
		Me.mnuVendas = new System.Windows.Forms.MenuItem()
		Me.mnuVenderLivros = new System.Windows.Forms.MenuItem()
		Me.mnuVendasRealizadas = new System.Windows.Forms.MenuItem()
		Me.mnuJanelas = new System.Windows.Forms.MenuItem()
		Me.mnuLadoALadoHorizontal = new System.Windows.Forms.MenuItem()
		Me.mnuLadoALadoVertical = new System.Windows.Forms.MenuItem()
		Me.mnuEmCascata = new System.Windows.Forms.MenuItem()
		Me.mnuOrganizarIcones = new System.Windows.Forms.MenuItem()
		Me.mnuOpcoes = new System.Windows.Forms.MenuItem()
		Me.mnuAlterarSenha = new System.Windows.Forms.MenuItem()
		Me.menuItem3 = new System.Windows.Forms.MenuItem()
		Me.mnuSobre = new System.Windows.Forms.MenuItem()
		Me.mnuSair = new System.Windows.Forms.MenuItem()
		Me.statusBar1 = new System.Windows.Forms.StatusBar()
		Me.statusBarPanel1 = new System.Windows.Forms.StatusBarPanel()
		Me.statusBarPanel2 = new System.Windows.Forms.StatusBarPanel()
		Me.toolBar1 = new System.Windows.Forms.ToolBar()
		Me.tlbClientes = new System.Windows.Forms.ToolBarButton()
		Me.tlbLivros = new System.Windows.Forms.ToolBarButton()
		Me.tlbVender = new System.Windows.Forms.ToolBarButton()
		Me.toolBarButton4 = new System.Windows.Forms.ToolBarButton()
		Me.tlbSobre = new System.Windows.Forms.ToolBarButton()
		Me.tlbSair = new System.Windows.Forms.ToolBarButton()
		Me.imageList1 = new System.Windows.Forms.ImageList(Me.components)
		Me.db = new System.Data.OleDb.OleDbConnection()
 	    CType(Me.statusBarPanel1,System.ComponentModel.ISupportInitialize).BeginInit()
		CType(Me.statusBarPanel2,System.ComponentModel.ISupportInitialize).BeginInit()

		Me.SuspendLayout()
			'
			' mainMenu1
			'
        Me.mainMenu1.MenuItems.AddRange(New System.Windows.Forms.MenuItem() { _
			Me.mnuCadastros, Me.mnuPesquisas, Me.mnuVendas, _
            Me.mnuJanelas, Me.mnuOpcoes})
			'
			' mnuCadastros
			'
		Me.mnuCadastros.Index = 0
		Me.mnuCadastros.MenuItems.AddRange(new System.Windows.Forms.MenuItem(){ _
		    Me.mnuCadAssuntos, Me.mnuCadAutores, Me.mnuCadEditoras, _
            Me.mnuCadEnderecos, Me.mnuCadIdiomas, Me.mnuCadPaises, _
            Me.mnuCadProfissoes, Me.menuItem1, Me.mnuCadClientes, _
            Me.mnuCadLivros})
   		Me.mnuCadastros.Text = "&Cadastros"
       		'
			' mnuCadAssuntos
			'
		Me.mnuCadAssuntos.Index = 0
		Me.mnuCadAssuntos.Text = "&Assuntos"
			'
			' mnuCadAutores
			'
		Me.mnuCadAutores.Index = 1
		Me.mnuCadAutores.Text = "Au&tores"
			'
			' mnuCadEditoras
			'
		Me.mnuCadEditoras.Index = 2
		Me.mnuCadEditoras.Text = "&Editoras"
			'
			' mnuCadEnderecos
			'
		Me.mnuCadEnderecos.Index = 3
		Me.mnuCadEnderecos.Text = "E&ndereços"
			'
			' mnuCadIdiomas
			'
		Me.mnuCadIdiomas.Index = 4
		Me.mnuCadIdiomas.Text = "&Idiomas"
			'
			' mnuCadPaises
			'
		Me.mnuCadPaises.Index = 5
		Me.mnuCadPaises.Text = "&Países"
			'
			' mnuCadProfissoes
			'
		Me.mnuCadProfissoes.Index = 6
		Me.mnuCadProfissoes.Text = "P&rofissões"
			'
			' menuItem1
			'
		Me.menuItem1.Index = 7
		Me.menuItem1.Text = "-"
			'
			' mnuCadClientes
			'
		Me.mnuCadClientes.Index = 8
		Me.mnuCadClientes.Text = "&Clientes"
			'
			' mnuCadLivros
			'
		Me.mnuCadLivros.Index = 9
		Me.mnuCadLivros.Text = "&Livros"
			'
			' mnuPesquisas
			'
		Me.mnuPesquisas.Index = 1
		Me.mnuPesquisas.MenuItems.AddRange(new System.Windows.Forms.MenuItem(){ _
		    Me.mnuConAssuntos, Me.mnuConAutores, Me.mnuConEditoras, _
            Me.mnuConEnderecos, Me.mnuConIdiomas, Me.mnuConPaises, _
            Me.mnuConProfissoes, Me.menuItem2, Me.mnuConClientes, _
            Me.mnuConLivros})
		Me.mnuPesquisas.Text = "&Pesquisas"
			'
			' mnuConAssuntos
			'
		Me.mnuConAssuntos.Index = 0
		Me.mnuConAssuntos.Text = "&Assuntos"
			'
			' mnuConAutores
			'
		Me.mnuConAutores.Index = 1
		Me.mnuConAutores.Text = "Au&tores"
			'
			' mnuConEditoras
			'
		Me.mnuConEditoras.Index = 2
		Me.mnuConEditoras.Text = "&Editoras"
			' 
			' mnuConEnderecos
			' 
		Me.mnuConEnderecos.Index = 3
		Me.mnuConEnderecos.Text = "E&ndereços"
			' 
			' mnuConIdiomas
			' 
		Me.mnuConIdiomas.Index = 4
		Me.mnuConIdiomas.Text = "&Idiomas"
			' 
			' mnuConPaises
			'
		Me.mnuConPaises.Index = 5
		Me.mnuConPaises.Text = "&Países"
			' 
			' mnuConProfissoes
			'
		Me.mnuConProfissoes.Index = 6
		Me.mnuConProfissoes.Text = "P&rofissões"
			'
			' menuItem2
			'
		Me.menuItem2.Index = 7
		Me.menuItem2.Text = "-"
			'
			' mnuConClientes
			'
		Me.mnuConClientes.Index = 8
		Me.mnuConClientes.Text = "&Clientes"
			'
			' mnuConLivros
			'
		Me.mnuConLivros.Index = 9
		Me.mnuConLivros.Text = "&Livros"
			'
			' mnuVendas
			'
		Me.mnuVendas.Index = 2
		Me.mnuVendas.MenuItems.AddRange(new System.Windows.Forms.MenuItem() { _
					Me.mnuVenderLivros, Me.mnuVendasRealizadas})
		Me.mnuVendas.Text = "&Vendas"
			'
			' mnuVenderLivros
			'
		Me.mnuVenderLivros.Index = 0
		Me.mnuVenderLivros.Text = "&Vender Livros"
			'
			' mnuVendasRealizadas
			'
		Me.mnuVendasRealizadas.Index = 1
		Me.mnuVendasRealizadas.Text = "Vendas &Realizadas"
			'
			' mnuJanelas
			'
		Me.mnuJanelas.Index = 3
		Me.mnuJanelas.MdiList = true
		Me.mnuJanelas.MenuItems.AddRange(new System.Windows.Forms.MenuItem() { _
					Me.mnuLadoALadoHorizontal, Me.mnuLadoALadoVertical, _
					Me.mnuEmCascata, Me.mnuOrganizarIcones})
		Me.mnuJanelas.Text = "&Janelas"
			'
			' mnuLadoALadoHorizontal
			'
		Me.mnuLadoALadoHorizontal.Index = 0
		Me.mnuLadoALadoHorizontal.Text = "Lado a lado &horizontal"
			'
			' mnuLadoALadoVertical
			'
		Me.mnuLadoALadoVertical.Index = 1
		Me.mnuLadoALadoVertical.Text = "Lado a lado &vertical"
			'
			' mnuEmCascata
			'
		Me.mnuEmCascata.Index = 2
		Me.mnuEmCascata.Text = "Em &cascata"
			'
			' mnuOrganizarIcones
			'
		Me.mnuOrganizarIcones.Index = 3
		Me.mnuOrganizarIcones.Text = "&Organizar ícones"
			'
			' mnuOpcoes
			'
		Me.mnuOpcoes.Index = 4
		Me.mnuOpcoes.MenuItems.AddRange(new System.Windows.Forms.MenuItem() { _
					Me.mnuAlterarSenha, Me.menuItem3, Me.mnuSobre, Me.mnuSair})
		Me.mnuOpcoes.Text = "&Opções"
			' 
			' mnuAlterarSenha
			'
		Me.mnuAlterarSenha.Index = 0
		Me.mnuAlterarSenha.Text = "&Alterar Senha"
			'
			' menuItem3
			'
		Me.menuItem3.Index = 1
		Me.menuItem3.Text = "-"
			'
			' mnuSobre
			'
		Me.mnuSobre.Index = 2
		Me.mnuSobre.Text = "&Sobre"
			'
			' mnuSair
			'
		Me.mnuSair.Index = 3
		Me.mnuSair.Text = "Sa&ir"
			'
			' statusBar1
			' 
		Me.statusBar1.Location = new System.Drawing.Point(0, 348)
		Me.statusBar1.Name = "statusBar1"
		Me.statusBar1.Panels.AddRange(new System.Windows.Forms.StatusBarPanel() { _
					Me.statusBarPanel1,	Me.statusBarPanel2})
		Me.statusBar1.ShowPanels = true
		Me.statusBar1.Size = new System.Drawing.Size(480, 22)
		Me.statusBar1.TabIndex = 1
			' 
			' statusBarPanel1
			' 
		Me.statusBarPanel1.AutoSize = System.Windows.Forms.StatusBarPanelAutoSize.Contents
		Me.statusBarPanel1.Text = "Usuário:"
		Me.statusBarPanel1.Width = 56
			' 
			' statusBarPanel2
			' 
		Me.statusBarPanel2.AutoSize = System.Windows.Forms.StatusBarPanelAutoSize.Spring
		Me.statusBarPanel2.Width = 408
			'
			' toolBar1
			' 
		Me.toolBar1.Buttons.AddRange(new System.Windows.Forms.ToolBarButton() { _
					Me.tlbClientes,	Me.tlbLivros, Me.tlbVender, _
                    Me.toolBarButton4, Me.tlbSobre,	Me.tlbSair})
		Me.toolBar1.DropDownArrows = true
		Me.toolBar1.ImageList = Me.imageList1
		Me.toolBar1.Location = new System.Drawing.Point(0, 0)
		Me.toolBar1.Name = "toolBar1"
		Me.toolBar1.ShowToolTips = true
		Me.toolBar1.Size = new System.Drawing.Size(480, 28)
		Me.toolBar1.TabIndex = 2
			'
			' tlbClientes
			'
		Me.tlbClientes.ImageIndex = 0
			'
			' tlbLivros
			'
		Me.tlbLivros.ImageIndex = 1
			'
			' tlbVender
			'
		Me.tlbVender.ImageIndex = 2
			'
			' toolBarButton4
			'
		Me.toolBarButton4.Style = System.Windows.Forms.ToolBarButtonStyle.Separator
			'
			' tlbSobre
			'
		Me.tlbSobre.ImageIndex = 3
			'
			' tlbSair
			'
		Me.tlbSair.ImageIndex = 4
			'
			' imageList1
			'
		Me.imageList1.ImageSize = new System.Drawing.Size(16, 16)
        Me.imageList1.ImageStream = CType(resources.GetObject("imageList1.ImageStream"), _
            System.Windows.Forms.ImageListStreamer)
		Me.imageList1.TransparentColor = System.Drawing.Color.Olive
			'
			' frmPrincipal
			'
		Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
		Me.ClientSize = new System.Drawing.Size(480, 370)
		Me.Controls.Add(Me.toolBar1)
		Me.Controls.Add(Me.statusBar1)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
		Me.IsMdiContainer = true
		Me.Menu = Me.mainMenu1
		Me.Name = "frmPrincipal"
		Me.Text = "Livrus Virtus"
 	    CType(Me.statusBarPanel1,System.ComponentModel.ISupportInitialize).EndInit()
		CType(Me.statusBarPanel2,System.ComponentModel.ISupportInitialize).EndInit()
		Me.ResumeLayout(false)

    End Sub

#End Region

    <STAThread()> Shared Sub Main()
        if (frmPrincipal.fPrincipal is nothing) then
            frmPrincipal.fPrincipal = New frmPrincipal()

            frmPrincipal.fPrincipal.db = new OleDbConnection()
            frmPrincipal.fPrincipal.db.ConnectionString = _
            "File Name=C:\LivrusVirtus\bancos\access\Access2k_Livrus.udl"

            Application.Run(fPrincipal)
        else
          MessageBox.Show("A Aplicação já está sendo executada.", _
          "Livrus Virtus", MessageBoxButtons.OK)
        end if
    End Sub

    Private Sub frmPrincipal_Closing(sender As Object, e As System.ComponentModel.CancelEventArgs) _
        Handles MyBase.Closing

        dim res as DialogResult
        res = MessageBox.Show(Me, "Deseja sair do sistema?", _
        Me.Text, MessageBoxButtons.YesNo, _
        MessageBoxIcon.Question,MessageBoxDefaultButton.Button2)

        if (res = DialogResult.Yes) then
            db.Close()
            e.Cancel=false
         else
            e.Cancel=true
         end if
    End sub

    private sub toolBar1_ButtonClick(sender as object, _ 
	e as System.Windows.Forms.ToolBarButtonClickEventArgs) Handles toolBar1.ButtonClick

       select case toolBar1.Buttons.IndexOf(e.Button)
          case 0
             mnuCadClientes_Click(Me,Nothing)
          case 1
             mnuCadLivros_Click(Me,Nothing)
          case 2
             mnuVenderLivros_Click(Me,Nothing)
          case 4
             mnuSobre_Click(Me,Nothing)
          case 5
             mnuSair_Click(Me,Nothing)
        end select
    end sub

    private sub frmPrincipal_Load(sender as object, e as System.EventArgs) _
        Handles MyBase.Load

      db.Open()

      ConsultasSQL.ConsSQL = new ConsultasSQL()
      RotinasGlobais.Rotinas = new RotinasGlobais()

      frmSplash.fSplash = new frmSplash()
      frmSplash.fSplash.ShowDialog()

      frmLogin.fLogin = new frmLogin()
      frmLogin.fLogin.ShowDialog()

    end sub

    private sub mnuSair_Click(sender as object, e as System.EventArgs) _
        Handles mnuSair.Click

        Close()
    end sub

    private sub mnuLadoALadoHorizontal_Click(sender as object, e as System.EventArgs) _
        Handles mnuLadoALadoHorizontal.Click

        Me.LayoutMdi(MdiLayout.TileHorizontal)
    end sub

    private sub mnuLadoALadoVertical_Click(sender as object, e as System.EventArgs) _
        Handles mnuLadoALadoVertical.Click

        Me.LayoutMdi(MdiLayout.TileVertical)
    end sub
		
    private sub mnuEmCascata_Click(sender as object, e as System.EventArgs) _
        Handles mnuEmCascata.Click
	
        Me.LayoutMdi(MdiLayout.Cascade)
    end sub
		
    private sub mnuOrganizarIcones_Click(sender as object, e as System.EventArgs) _
        Handles mnuOrganizarIcones.Click

        Me.LayoutMdi(MdiLayout.ArrangeIcons)
    end sub

    private sub mnuSobre_Click(sender as object, e as System.EventArgs) _
        Handles mnuSobre.Click

        frmSobre.fSobre = new frmSobre()
        frmSobre.fSobre.ShowDialog()
    end sub

    private sub frmPrincipal_MouseMove(sender as object, e as System.Windows.Forms.MouseEventArgs) _
        Handles MyBase.MouseMove

        Me.statusBar1.Panels(1).Text=" "
    end sub

    Private Sub mnuCadAssuntos_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuCadAssuntos.Click
	
	mnuCadAssuntos.Enabled=false
        frmCadAssuntos.fCadAssuntos = new frmCadAssuntos()
        frmCadAssuntos.fCadAssuntos.MdiParent=Me
        frmCadAssuntos.fCadAssuntos.Show()
    End Sub

    private sub mnuAlterarSenha_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuAlterarSenha.Click

	mnuAlterarSenha.Enabled=false
        frmAlterarSenha.fAlterarSenha = new frmAlterarSenha()
        frmAlterarSenha.fAlterarSenha.MdiParent=Me
        frmAlterarSenha.fAlterarSenha.Show()
    End Sub

    private sub mnuConAssuntos_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuConAssuntos.Click

	mnuConAssuntos.Enabled=false
        frmConAssuntos.fConAssuntos = new frmConAssuntos()
        frmConAssuntos.fConAssuntos.MdiParent=Me
        frmConAssuntos.fConAssuntos.Show()
    End Sub

    Private Sub mnuCadAutores_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuCadAutores.Click
	
	mnuCadAutores.Enabled=false
        frmCadAutores.fCadAutores = new frmCadAutores()
        frmCadAutores.fCadAutores.MdiParent=Me
        frmCadAutores.fCadAutores.Show()
    End Sub

    private sub mnuConAutores_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuConAutores.Click

	mnuConAutores.Enabled=false
        frmConAutores.fConAutores = new frmConAutores()
        frmConAutores.fConAutores.MdiParent=Me
        frmConAutores.fConAutores.Show()
    End Sub

    Private Sub mnuCadEditoras_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuCadEditoras.Click
	
	mnuCadEditoras.Enabled=false
        frmCadEditoras.fCadEditoras = new frmCadEditoras()
        frmCadEditoras.fCadEditoras.MdiParent=Me
        frmCadEditoras.fCadEditoras.Show()
    End Sub

    private sub mnuConEditoras_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuConEditoras.Click

	mnuConEditoras.Enabled=false
        frmConEditoras.fConEditoras = new frmConEditoras()
        frmConEditoras.fConEditoras.MdiParent=Me
        frmConEditoras.fConEditoras.Show()
    End Sub

    Private Sub mnuCadEnderecos_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuCadEnderecos.Click
	
	mnuCadEnderecos.Enabled=false
        frmCadEnderecos.fCadEnderecos = new frmCadEnderecos()
        frmCadEnderecos.fCadEnderecos.MdiParent=Me
        frmCadEnderecos.fCadEnderecos.Show()
    End Sub

    private sub mnuConEnderecos_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuConEnderecos.Click

	mnuConEnderecos.Enabled=false
        frmConEnderecos.fConEnderecos = new frmConEnderecos()
        frmConEnderecos.fConEnderecos.MdiParent=Me
        frmConEnderecos.fConEnderecos.Show()
    End Sub

    Private Sub mnuCadIdiomas_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuCadIdiomas.Click
	
	mnuCadIdiomas.Enabled=false
        frmCadIdiomas.fCadIdiomas = new frmCadIdiomas()
        frmCadIdiomas.fCadIdiomas.MdiParent=Me
        frmCadIdiomas.fCadIdiomas.Show()
    End Sub

    private sub mnuConIdiomas_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuConIdiomas.Click

	mnuConIdiomas.Enabled=false
        frmConIdiomas.fConIdiomas = new frmConIdiomas()
        frmConIdiomas.fConIdiomas.MdiParent=Me
        frmConIdiomas.fConIdiomas.Show()
    End Sub

    Private Sub mnuCadPaises_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuCadPaises.Click
	
	mnuCadPaises.Enabled=false
        frmCadPaises.fCadPaises = new frmCadPaises()
        frmCadPaises.fCadPaises.MdiParent=Me
        frmCadPaises.fCadPaises.Show()
    End Sub

    private sub mnuConPaises_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuConPaises.Click

	mnuConPaises.Enabled=false
        frmConPaises.fConPaises = new frmConPaises()
        frmConPaises.fConPaises.MdiParent=Me
        frmConPaises.fConPaises.Show()
    End Sub

    Private Sub mnuCadProfissoes_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuCadProfissoes.Click
	
	mnuCadProfissoes.Enabled=false
        frmCadProfissoes.fCadProfissoes = new frmCadProfissoes()
        frmCadProfissoes.fCadProfissoes.MdiParent=Me
        frmCadProfissoes.fCadProfissoes.Show()
    End Sub

    private sub mnuConProfissoes_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuConProfissoes.Click

	mnuConProfissoes.Enabled=false
        frmConProfissoes.fConProfissoes = new frmConProfissoes()
        frmConProfissoes.fConProfissoes.MdiParent=Me
        frmConProfissoes.fConProfissoes.Show()
    End Sub

    Private Sub mnuCadClientes_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuCadClientes.Click
	
	mnuCadClientes.Enabled=false
	tlbClientes.Enabled=false
        frmCadClientes.fCadClientes = new frmCadClientes()
        frmCadClientes.fCadClientes.MdiParent=Me
        frmCadClientes.fCadClientes.Show()
    End Sub

    private sub mnuConClientes_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuConClientes.Click

	mnuConClientes.Enabled=false
        frmConClientes.fConClientes = new frmConClientes()
        frmConClientes.fConClientes.MdiParent=Me
        frmConClientes.fConClientes.Show()
    End Sub

    Private Sub mnuCadLivros_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuCadLivros.Click
	
	mnuCadLivros.Enabled=false
	tlbLivros.Enabled=false
        frmCadLivros.fCadLivros = new frmCadLivros()
        frmCadLivros.fCadLivros.MdiParent=Me
        frmCadLivros.fCadLivros.Show()
    End Sub

    private sub mnuConLivros_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuConLivros.Click

	mnuConLivros.Enabled=false
        frmConLivros.fConLivros = new frmConLivros()
        frmConLivros.fConLivros.MdiParent=Me
        frmConLivros.fConLivros.Show()
    End Sub

    Private Sub mnuVenderLivros_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuVenderLivros.Click
	
	mnuVenderLivros.Enabled=false
	tlbVender.Enabled=false
        frmVenderLivros.fVenderLivros = new frmVenderLivros()
        frmVenderLivros.fVenderLivros.MdiParent=Me
        frmVenderLivros.fVenderLivros.Show()
    End Sub

    private sub mnuVendasRealizadas_Click(ByVal sender As System.Object, ByVal e as System.EventArgs) _
        Handles mnuVendasRealizadas.Click

	mnuVendasRealizadas.Enabled=false
        frmConVendas.fConVendas = new frmConVendas()
        frmConVendas.fConVendas.MdiParent=Me
        frmConVendas.fConVendas.Show()
    End Sub

End Class

End NameSpace

