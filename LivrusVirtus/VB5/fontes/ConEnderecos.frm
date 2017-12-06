VERSION 5.00
Object = "{00028C01-0000-0000-0000-000000000046}#1.0#0"; "DBGRID32.OCX"
Begin VB.Form frmConEnderecos 
   Caption         =   "Consulta de Endereços"
   ClientHeight    =   3870
   ClientLeft      =   2730
   ClientTop       =   2535
   ClientWidth     =   5490
   KeyPreview      =   -1  'True
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   3870
   ScaleWidth      =   5490
   Begin VB.Data Consulta 
      Caption         =   "Consulta"
      Connect         =   "Access"
      DatabaseName    =   ""
      DefaultCursorType=   0  'DefaultCursor
      DefaultType     =   2  'UseODBC
      Exclusive       =   0   'False
      Height          =   300
      Left            =   1800
      Options         =   0
      ReadOnly        =   -1  'True
      RecordsetType   =   1  'Dynaset
      RecordSource    =   ""
      Top             =   3480
      Visible         =   0   'False
      Width           =   1335
   End
   Begin VB.PictureBox Picture2 
      Align           =   2  'Align Bottom
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   525
      Left            =   0
      ScaleHeight     =   525
      ScaleWidth      =   5490
      TabIndex        =   4
      Top             =   3345
      Width           =   5490
      Begin VB.CommandButton btnLimpar 
         Caption         =   "&Limpar"
         Height          =   400
         Left            =   3160
         TabIndex        =   5
         Top             =   80
         Width           =   1065
      End
      Begin VB.CommandButton btnFechar 
         Caption         =   "&Fechar"
         Height          =   400
         Left            =   4320
         TabIndex        =   6
         Top             =   80
         Width           =   1065
      End
      Begin VB.Label labRegistros 
         Caption         =   "Registro 0 de 0"
         Height          =   255
         Left            =   120
         TabIndex        =   3
         Top             =   120
         Width           =   1575
      End
   End
   Begin VB.PictureBox Picture1 
      Align           =   1  'Align Top
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   750
      Left            =   0
      ScaleHeight     =   750
      ScaleWidth      =   5490
      TabIndex        =   0
      Top             =   0
      Width           =   5490
      Begin VB.TextBox edtDescricao 
         Height          =   285
         Left            =   105
         TabIndex        =   1
         Top             =   315
         Width           =   4080
      End
      Begin VB.CommandButton btnPesquisar 
         Caption         =   "&Pesquisar"
         Height          =   400
         Left            =   4320
         TabIndex        =   2
         Top             =   210
         Width           =   1065
      End
      Begin VB.Label lblLabels 
         Caption         =   "Endereco:"
         Height          =   255
         Left            =   105
         TabIndex        =   7
         Top             =   105
         Width           =   765
      End
   End
   Begin MSDBGrid.DBGrid gridConsulta 
      Align           =   1  'Align Top
      Bindings        =   "ConEnderecos.frx":0000
      Height          =   2505
      Left            =   0
      OleObjectBlob   =   "ConEnderecos.frx":0013
      TabIndex        =   8
      Top             =   750
      Width           =   5490
   End
End
Attribute VB_Name = "frmConEnderecos"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub btnFechar_Click()
    fConsultas.btnFechar Me
End Sub

Private Sub btnLimpar_Click()
    fConsultas.LimparDados Me, Consulta, _
    ConsSQL.Endereco("S", "0", "", "", "", "", ""), gridConsulta
End Sub

Private Sub btnPesquisar_Click()
    fConsultas.PesquisarDados Me, Consulta, _
    ConsSQL.Endereco("S", "", edtDescricao.Text, "", "", "", ""), _
    "Endereço não encontrado!", gridConsulta
End Sub

Private Sub Form_Activate()
    btnLimpar_Click
End Sub

Private Sub Form_Load()   
    fConsultas.frmLoad Me
End Sub

Private Sub Form_Unload(Cancel As Integer)
    fPrincipal.mnuConEnderecos.Enabled = True
    fConsultas.frmUnload Consulta
End Sub

Private Sub Form_Resize()
  fConsultas.frmResize Me, gridConsulta
End Sub

Private Sub gridConsulta_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    fConsultas.frmMouseMove Me
End Sub

Private Sub gridConsulta_RowColChange(LastRow As Variant, ByVal LastCol As Integer)
    fConsultas.ConsultaChange Me, Consulta
End Sub



