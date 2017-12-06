VERSION 4.00
Begin VB.MDIForm frmPrincipal 
   BackColor       =   &H8000000C&
   Caption         =   "Livrus Virtus"
   ClientHeight    =   7290
   ClientLeft      =   1185
   ClientTop       =   2130
   ClientWidth     =   10290
   Height          =   7980
   Icon            =   "Principal.frx":0000
   Left            =   1125
   Top             =   1500
   Width           =   10410
   Begin ComctlLib.Toolbar tbToolbar 
      Align           =   1  'Align Top
      Height          =   420
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   10290
      _ExtentX        =   18150
      _ExtentY        =   741
      ButtonWidth     =   635
      ButtonHeight    =   582
      Appearance      =   1
      ImageList       =   "ImageList1"
      _Version        =   327682
      BeginProperty Buttons {0713E452-850A-101B-AFC0-4210102A8DA7} 
         NumButtons      =   6
         BeginProperty Button1 {0713F354-850A-101B-AFC0-4210102A8DA7} 
            Object.Tag             =   ""
            ImageIndex      =   1
         EndProperty
         BeginProperty Button2 {0713F354-850A-101B-AFC0-4210102A8DA7} 
            Object.Tag             =   ""
            ImageIndex      =   2
         EndProperty
         BeginProperty Button3 {0713F354-850A-101B-AFC0-4210102A8DA7} 
            Object.Tag             =   ""
            ImageIndex      =   3
         EndProperty
         BeginProperty Button4 {0713F354-850A-101B-AFC0-4210102A8DA7} 
            Object.Tag             =   ""
            Style           =   3
            MixedState      =   -1  'True
         EndProperty
         BeginProperty Button5 {0713F354-850A-101B-AFC0-4210102A8DA7} 
            Object.Tag             =   ""
            ImageIndex      =   4
         EndProperty
         BeginProperty Button6 {0713F354-850A-101B-AFC0-4210102A8DA7} 
            Object.Tag             =   ""
            ImageIndex      =   5
         EndProperty
      EndProperty
   End
   Begin ComctlLib.ImageList ImageList1 
      Left            =   120
      Top             =   480
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   32896
      _Version        =   327682
      BeginProperty Images {0713E8C2-850A-101B-AFC0-4210102A8DA7} 
         NumListImages   =   5
         BeginProperty ListImage1 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "Principal.frx":030A
            Key             =   ""
         EndProperty
         BeginProperty ListImage2 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "Principal.frx":041C
            Key             =   ""
         EndProperty
         BeginProperty ListImage3 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "Principal.frx":052E
            Key             =   ""
         EndProperty
         BeginProperty ListImage4 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "Principal.frx":0640
            Key             =   ""
         EndProperty
         BeginProperty ListImage5 {0713E8C3-850A-101B-AFC0-4210102A8DA7} 
            Picture         =   "Principal.frx":0752
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin ComctlLib.StatusBar sbStatusBar 
      Align           =   2  'Align Bottom
      Height          =   330
      Left            =   0
      TabIndex        =   1
      Top             =   6960
      Width           =   10290
      _ExtentX        =   18150
      _ExtentY        =   582
      SimpleText      =   ""
      _Version        =   327682
      BeginProperty Panels {0713E89E-850A-101B-AFC0-4210102A8DA7} 
         NumPanels       =   2
         BeginProperty Panel1 {0713E89F-850A-101B-AFC0-4210102A8DA7} 
            Object.Width           =   2999
            MinWidth        =   2999
            Text            =   "Usuário: "
            TextSave        =   "Usuário: "
            Object.Tag             =   ""
         EndProperty
         BeginProperty Panel2 {0713E89F-850A-101B-AFC0-4210102A8DA7} 
            AutoSize        =   1
            Object.Width           =   14631
            TextSave        =   ""
            Object.Tag             =   ""
         EndProperty
      EndProperty
   End
   Begin VB.Menu mnuCadastros 
      Caption         =   "&Cadastros"
      Begin VB.Menu mnuCadAssuntos 
         Caption         =   "&Assuntos"
      End
      Begin VB.Menu mnuCadAutores 
         Caption         =   "A&utores"
      End
      Begin VB.Menu mnuCadEnderecos 
         Caption         =   "&Endereços"
      End
      Begin VB.Menu mnuCadEditoras 
         Caption         =   "E&ditoras"
      End
      Begin VB.Menu mnuCadIdiomas 
         Caption         =   "&Idiomas"
      End
      Begin VB.Menu mnuCadPaises 
         Caption         =   "&Países"
      End
      Begin VB.Menu mnuCadProfissoes 
         Caption         =   "P&rofissões"
      End
      Begin VB.Menu mnuSep1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuCadClientes 
         Caption         =   "&Clientes"
      End
      Begin VB.Menu mnuCadLivros 
         Caption         =   "&Livros"
      End
   End
   Begin VB.Menu mnuPesquisas 
      Caption         =   "&Pesquisas"
      Begin VB.Menu mnuConAssuntos 
         Caption         =   "&Assuntos"
      End
      Begin VB.Menu mnuConAutores 
         Caption         =   "A&utores"
      End
      Begin VB.Menu mnuConEnderecos 
         Caption         =   "&Endereços"
      End
      Begin VB.Menu mnuConEditoras 
         Caption         =   "E&ditoras"
      End
      Begin VB.Menu mnuConIdiomas 
         Caption         =   "&Idiomas"
      End
      Begin VB.Menu mnuConPaises 
         Caption         =   "&Países"
      End
      Begin VB.Menu mnuConProfissoes 
         Caption         =   "P&rofissões"
      End
      Begin VB.Menu mnuSep2 
         Caption         =   "-"
      End
      Begin VB.Menu mnuConClientes 
         Caption         =   "&Clientes"
      End
      Begin VB.Menu mnuConLivros 
         Caption         =   "&Livros"
      End
   End
   Begin VB.Menu mnuVendas 
      Caption         =   "&Vendas"
      Begin VB.Menu mnuVenderLivros 
         Caption         =   "&Vender Livros"
      End
      Begin VB.Menu mnuVendasRealizadas 
         Caption         =   "Vendas &Realizadas"
      End
   End
   Begin VB.Menu mnuJanelas 
      Caption         =   "&Janelas"
      WindowList      =   -1  'True
      Begin VB.Menu mnuLadoALadoHorizontal 
         Caption         =   "Lado a lado &horizontal"
      End
      Begin VB.Menu mnuLadoALadoVertical 
         Caption         =   "Lado a lado &vertical"
      End
      Begin VB.Menu mnuEmCascata 
         Caption         =   "Em &cascata"
      End
      Begin VB.Menu mnuOrganizarIcones 
         Caption         =   "&Organizar Ícones"
      End
   End
   Begin VB.Menu mnuOpcoes 
      Caption         =   "&Opções"
      Begin VB.Menu mnuAlterarSenha 
         Caption         =   "&Alterar Senha"
      End
      Begin VB.Menu mnuSep4 
         Caption         =   "-"
      End
      Begin VB.Menu mnuSobre 
         Caption         =   "&Sobre"
      End
      Begin VB.Menu mnuSair 
         Caption         =   "Sair"
      End
   End
End
Attribute VB_Name = "frmPrincipal"
Attribute VB_Creatable = False
Attribute VB_Exposed = False



Private Sub MDIForm_Load()
    Rotinas.ConectaBanco
    Rotinas.ChamarTela frmSplash
    Rotinas.ChamarTela frmLogin
End Sub

Private Sub MDIForm_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    fPrincipal.sbStatusBar.Panels.Item(2).Text = ""
End Sub

Private Sub MDIForm_Unload(Cancel As Integer)
    If MsgBox("Deseja sair do sistema?", vbYesNo + vbQuestion) = vbYes Then
       DB.Close
       End
    Else
     Cancel = True
    End If
End Sub

Private Sub mnuAlterarSenha_Click()
    mnuAlterarSenha.Enabled = False
    frmAlterarSenha.Show
End Sub

Private Sub mnuCadAssuntos_Click()
   mnuCadAssuntos.Enabled = False
   frmCadAssuntos.Show
End Sub

Private Sub mnuCadAutores_Click()
   mnuCadAutores.Enabled = False
   frmCadAutores.Show
End Sub

Private Sub mnuCadClientes_Click()
   tbToolBar.Buttons.Item(1).Enabled = False
   mnuCadClientes.Enabled = False
   frmCadClientes.Show
End Sub

Private Sub mnuCadEditoras_Click()
   mnuCadEditoras.Enabled = False
   frmCadEditoras.Show
End Sub

Private Sub mnuCadEnderecos_Click()
   mnuCadEnderecos.Enabled = False
   frmCadEnderecos.Show
End Sub

Private Sub mnuCadIdiomas_Click()
   mnuCadIdiomas.Enabled = False
   frmCadIdiomas.Show
End Sub

Private Sub mnuCadLivros_Click()
    tbToolBar.Buttons.Item(2).Enabled = False
    mnuCadLivros.Enabled = False
    frmCadLivros.Show
End Sub

Private Sub mnuCadPaises_Click()
    mnuCadPaises.Enabled = False
    frmCadPaises.Show
End Sub

Private Sub mnuCadProfissoes_Click()
    mnuCadProfissoes.Enabled = False
    frmCadProfissoes.Show
End Sub

Private Sub mnuConAssuntos_Click()
    mnuConAssuntos.Enabled = False
    Rotinas.ChamarTela frmConAssuntos
End Sub

Private Sub mnuConAutores_Click()
    mnuConAutores.Enabled = False
    Rotinas.ChamarTela frmConAutores
End Sub

Private Sub mnuConClientes_Click()
   mnuConClientes.Enabled = False
   Rotinas.ChamarTela frmConClientes
End Sub

Private Sub mnuConEditoras_Click()
   mnuConEditoras.Enabled = False
   Rotinas.ChamarTela frmConEditoras
End Sub

Private Sub mnuConEnderecos_Click()
    mnuConEnderecos.Enabled = False
    Rotinas.ChamarTela frmConEnderecos
End Sub

Private Sub mnuConIdiomas_Click()
   mnuConIdiomas.Enabled = False
   Rotinas.ChamarTela frmConIdiomas
End Sub

Private Sub mnuConLivros_Click()
    mnuConLivros.Enabled = False
    Rotinas.ChamarTela frmConLivros
End Sub

Private Sub mnuConPaises_Click()
    mnuConPaises.Enabled = False
    Rotinas.ChamarTela frmConPaises
End Sub

Private Sub mnuConProfissoes_Click()
    mnuConProfissoes.Enabled = False
    Rotinas.ChamarTela frmConProfissoes
End Sub

Private Sub mnuEmCascata_Click()
    Me.Arrange vbCascade
End Sub

Private Sub mnuLadoALadoHorizontal_Click()
    Me.Arrange vbTileHorizontal
End Sub

Private Sub mnuLadoALadoVertical_Click()
    Me.Arrange vbTileVertical
End Sub

Private Sub mnuOrganizarIcones_Click()
    Me.Arrange vbArrangeIcons
End Sub

Private Sub mnuSair_Click()
    Unload Me
End Sub

Private Sub mnuSobre_Click()
    Rotinas.ChamarTela frmSobre
End Sub

Private Sub mnuVendasRealizadas_Click()
    mnuVendasRealizadas.Enabled = False
    frmConVendas.Show
End Sub

Private Sub mnuVenderLivros_Click()
    tbToolBar.Buttons.Item(3).Enabled = False
    mnuVenderLivros.Enabled = False
    frmVenderLivros.Show
End Sub



Private Sub tbToolBar_ButtonClick(ByVal Button As Button)
    Select Case Button.Index
        Case 1
            mnuCadClientes_Click
        Case 2
            mnuCadLivros_Click
        Case 3
            mnuVenderLivros_Click
        Case 5
            mnuSobre_Click
        Case 6
            mnuSair_Click
    End Select
End Sub


