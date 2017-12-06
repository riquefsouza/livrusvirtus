VERSION 5.00
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Begin VB.Form frmConClientes 
   Caption         =   "Consulta de Clientes"
   ClientHeight    =   3870
   ClientLeft      =   2730
   ClientTop       =   2535
   ClientWidth     =   5490
   KeyPreview      =   -1  'True
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   3870
   ScaleWidth      =   5490
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
         Caption         =   "Cliente:"
         Height          =   255
         Left            =   105
         TabIndex        =   7
         Top             =   105
         Width           =   765
      End
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
      Begin MSAdodcLib.Adodc Consulta 
         Height          =   330
         Left            =   1800
         Top             =   120
         Visible         =   0   'False
         Width           =   1335
         _ExtentX        =   2355
         _ExtentY        =   582
         ConnectMode     =   0
         CursorLocation  =   3
         IsolationLevel  =   -1
         ConnectionTimeout=   15
         CommandTimeout  =   30
         CursorType      =   3
         LockType        =   3
         CommandType     =   8
         CursorOptions   =   0
         CacheSize       =   50
         MaxRecords      =   0
         BOFAction       =   0
         EOFAction       =   0
         ConnectStringType=   1
         Appearance      =   1
         BackColor       =   -2147483643
         ForeColor       =   -2147483640
         Orientation     =   0
         Enabled         =   -1
         Connect         =   ""
         OLEDBString     =   ""
         OLEDBFile       =   ""
         DataSourceName  =   ""
         OtherAttributes =   ""
         UserName        =   ""
         Password        =   ""
         RecordSource    =   ""
         Caption         =   "Consulta"
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         _Version        =   393216
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
   Begin MSDataGridLib.DataGrid gridConsulta 
      Align           =   1  'Align Top
      Bindings        =   "ConClientes.frx":0000
      Height          =   2595
      Left            =   0
      TabIndex        =   8
      Top             =   750
      Width           =   5490
      _ExtentX        =   9684
      _ExtentY        =   4577
      _Version        =   393216
      AllowUpdate     =   0   'False
      AllowArrows     =   -1  'True
      HeadLines       =   1
      RowHeight       =   15
      FormatLocked    =   -1  'True
      BeginProperty HeadFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ColumnCount     =   2
      BeginProperty Column00 
         DataField       =   ""
         Caption         =   "Código"
         BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
            Type            =   0
            Format          =   ""
            HaveTrueFalseNull=   0
            FirstDayOfWeek  =   0
            FirstWeekOfYear =   0
            LCID            =   1046
            SubFormatType   =   0
         EndProperty
      EndProperty
      BeginProperty Column01 
         DataField       =   ""
         Caption         =   "Descrição"
         BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
            Type            =   0
            Format          =   ""
            HaveTrueFalseNull=   0
            FirstDayOfWeek  =   0
            FirstWeekOfYear =   0
            LCID            =   1046
            SubFormatType   =   0
         EndProperty
      EndProperty
      SplitCount      =   1
      BeginProperty Split0 
         BeginProperty Column00 
         EndProperty
         BeginProperty Column01 
         EndProperty
      EndProperty
   End
End
Attribute VB_Name = "frmConClientes"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub btnFechar_Click()
    fConsultas.btnFechar Me
End Sub

Private Sub btnLimpar_Click()
    fConsultas.LimparDados Me, Consulta, _
    ConsSQL.Cliente("S", "0", "", _
    "", "", "", "", "", "", "", ""), gridConsulta
End Sub

Private Sub btnPesquisar_Click()
    fConsultas.PesquisarDados Me, Consulta, _
    ConsSQL.Cliente("S", "", edtDescricao.Text, _
    "", "", "", "", "", "", "", ""), _
    "Cliente não encontrado!", gridConsulta
End Sub

Private Sub Form_Activate()
    btnLimpar_Click
End Sub

Private Sub Form_Load()
    fConsultas.frmLoad Me
End Sub

Private Sub Form_Unload(Cancel As Integer)
    fPrincipal.mnuConClientes.Enabled = True
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



