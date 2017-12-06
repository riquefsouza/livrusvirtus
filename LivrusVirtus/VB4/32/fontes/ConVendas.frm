VERSION 4.00
Begin VB.Form frmConVendas 
   Caption         =   "Consulta de Vendas"
   ClientHeight    =   4530
   ClientLeft      =   2880
   ClientTop       =   3675
   ClientWidth     =   6810
   Height          =   4935
   KeyPreview      =   -1  'True
   Left            =   2820
   MDIChild        =   -1  'True
   ScaleHeight     =   4530
   ScaleWidth      =   6810
   Top             =   3330
   Width           =   6930
   Begin VB.Data Consulta 
      Caption         =   "Consulta"
      Connect         =   "Access"
      DatabaseName    =   ""
      Exclusive       =   0   'False
      Height          =   300
      Left            =   3000
      Options         =   0
      ReadOnly        =   -1  'True
      RecordsetType   =   1  'Dynaset
      RecordSource    =   ""
      Top             =   4080
      Visible         =   0   'False
      Width           =   1335
   End
   Begin VB.PictureBox Picture2 
      Align           =   2  'Align Bottom
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   930
      Left            =   0
      ScaleHeight     =   930
      ScaleWidth      =   6810
      TabIndex        =   4
      Top             =   3600
      Width           =   6810
      Begin VB.TextBox edtPrecoTotal 
         Enabled         =   0   'False
         Height          =   285
         Left            =   4800
         TabIndex        =   20
         Top             =   0
         Width           =   1935
      End
      Begin VB.CommandButton btnLimpar 
         Caption         =   "&Limpar"
         Height          =   400
         Left            =   4485
         TabIndex        =   5
         Top             =   435
         Width           =   1065
      End
      Begin VB.CommandButton btnFechar 
         Caption         =   "&Fechar"
         Height          =   400
         Left            =   5640
         TabIndex        =   6
         Top             =   435
         Width           =   1065
      End
      Begin VB.Label LabPrecoTotal 
         Caption         =   "Prelo total:"
         Height          =   255
         Left            =   3840
         TabIndex        =   21
         Top             =   0
         Width           =   855
      End
      Begin VB.Label labRegistros 
         Caption         =   "Registro 0 de 0"
         Height          =   255
         Left            =   120
         TabIndex        =   3
         Top             =   480
         Width           =   2175
      End
   End
   Begin VB.PictureBox Picture1 
      Align           =   1  'Align Top
      Appearance      =   0  'Flat
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   1950
      Left            =   0
      ScaleHeight     =   1950
      ScaleWidth      =   6810
      TabIndex        =   0
      Top             =   0
      Width           =   6810
      Begin VB.TextBox edtDtVenda 
         Height          =   285
         Left            =   120
         MaxLength       =   10
         TabIndex        =   15
         Top             =   375
         Width           =   1455
      End
      Begin VB.TextBox edtHrVenda 
         Height          =   285
         Left            =   1680
         MaxLength       =   10
         TabIndex        =   14
         Top             =   375
         Width           =   1455
      End
      Begin VB.CommandButton btnPLivro 
         Caption         =   "..."
         Height          =   300
         Left            =   6360
         TabIndex        =   13
         Top             =   1455
         Width           =   300
      End
      Begin VB.TextBox edtLivro 
         Enabled         =   0   'False
         Height          =   285
         Left            =   2160
         TabIndex        =   12
         Top             =   1455
         Width           =   4215
      End
      Begin VB.TextBox edtISBN 
         Height          =   285
         Left            =   120
         MaxLength       =   13
         TabIndex        =   11
         Top             =   1455
         Width           =   1935
      End
      Begin VB.CommandButton btnPCliente 
         Caption         =   "..."
         Height          =   300
         Left            =   6360
         TabIndex        =   10
         Top             =   915
         Width           =   300
      End
      Begin VB.TextBox edtCliente 
         Enabled         =   0   'False
         Height          =   285
         Left            =   2160
         TabIndex        =   9
         Top             =   915
         Width           =   4215
      End
      Begin VB.TextBox edtDescricao 
         Height          =   285
         Left            =   105
         MaxLength       =   14
         TabIndex        =   1
         Top             =   915
         Width           =   1950
      End
      Begin VB.CommandButton btnPesquisar 
         Caption         =   "&Pesquisar"
         Height          =   400
         Left            =   3240
         TabIndex        =   2
         Top             =   240
         Width           =   1065
      End
      Begin VB.Label Label1 
         Caption         =   "Data/Hora Venda:"
         Height          =   255
         Left            =   120
         TabIndex        =   19
         Top             =   120
         Width           =   1725
      End
      Begin VB.Label Label5 
         Caption         =   "Livro:"
         Height          =   255
         Left            =   2160
         TabIndex        =   18
         Top             =   1215
         Width           =   1575
      End
      Begin VB.Label Label4 
         Caption         =   "ISBN:"
         Height          =   255
         Left            =   120
         TabIndex        =   17
         Top             =   1215
         Width           =   1575
      End
      Begin VB.Label Label3 
         Caption         =   "Cliente:"
         Height          =   255
         Left            =   2160
         TabIndex        =   16
         Top             =   705
         Width           =   1575
      End
      Begin VB.Label lblLabels 
         Caption         =   "CPF:"
         Height          =   255
         Left            =   105
         TabIndex        =   7
         Top             =   705
         Width           =   765
      End
   End
   Begin MSDBGrid.DBGrid gridConsulta 
      Align           =   1  'Align Top
      Bindings        =   "ConVendas.frx":0000
      Height          =   1560
      Left            =   0
      OleObjectBlob   =   "ConVendas.frx":0011
      TabIndex        =   8
      Top             =   1950
      Width           =   6810
   End
End
Attribute VB_Name = "frmConVendas"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
Private ConsTotal As Recordset
Private ConsCampo As Recordset

Private Sub btnFechar_Click()
    fConsultas.btnFechar Me
End Sub

Private Sub btnLimpar_Click()
    edtDtVenda.Text = Format(Date, "dd/MM/yyyy")
    edtHrVenda.Text = Format(Time, "hh:mm:ss")
    edtCliente.Text = ""
    edtISBN.Text = ""
    edtLivro.Text = ""
    edtPrecoTotal.Text = "R$ 0,00"
    edtDtVenda.SetFocus
    
    fConsultas.LimparDados Me, Consulta, _
    ConsVenda("L"), gridConsulta
End Sub

Private Function ConsVenda(sOpcao As String) As String
  Dim sDataVenda, sHoraVenda, sDtHrVenda As String

  If edtDtVenda.Text <> "" Then
        sDataVenda = Format(edtDtVenda.Text, "dd/MM/yyyy")
  Else
         sDataVenda = ""
  End If
  If edtHrVenda.Text <> "" Then
        sHoraVenda = Format(edtHrVenda.Text, "hh:mm:ss")
  Else
         sHoraVenda = ""
  End If
  sDtHrVenda = Trim(sDataVenda) + " " + Trim(sHoraVenda)
  If sOpcao = "L" Then
   ConsVenda = ConsSQL.Venda("S", "ZERO", "", "", "", "")
  Else
   ConsVenda = ConsSQL.Venda(sOpcao, edtISBN.Text, _
   edtDescricao.Text, Trim(sDtHrVenda), "", "")
  End If
End Function


Private Sub btnPesquisar_Click()
 If fConsultas.PesquisarDados(Me, Consulta, _
    ConsVenda("S"), "Venda não encontrada!", gridConsulta) Then
     Rotinas.ConsultaDados ConsTotal, ConsVenda("P")
     If ConsTotal.RecordCount > 0 Then
        edtPrecoTotal.Text = "R$ " & ConsTotal.Fields.Item(0).Value
     End If
 End If
End Sub


Private Sub edtDtVenda_LostFocus()
  If edtDtVenda.Text <> "" Then
    If Rotinas.ValidaDateTime(edtDtVenda.Text) = False Then
      edtDtVenda.Text = ""
      edtDtVenda.SetFocus
    End If
  End If
End Sub


Private Sub edtHrVenda_LostFocus()
  If edtHrVenda.Text <> "" Then
    If Rotinas.ValidaDateTime(edtHrVenda.Text) = False Then
      edtHrVenda.Text = ""
      edtHrVenda.SetFocus
    End If
  End If
End Sub


Private Sub edtISBN_LostFocus()
  If edtISBN.Text <> "" Then
    If Rotinas.ValidaISBN(edtISBN.Text) Then
      edtLivro.Text = _
      Rotinas.ConsultaCampoDescX(ConsCampo, _
      ConsSQL.Livro("Q", edtISBN.Text, _
      "", "", "", "", "", "", "", "", ""), "Livro não encontrado!")
      If edtLivro.Text <> "" Then
          If CInt(ConsCampo.Fields.Item(3).Value) > 0 Then
            Rotinas.sPreco = ConsCampo.Fields.Item(2).Value
          Else
            MsgBox "Livro não existe no estoque!", _
            vbCritical + vbOKOnly, fPrincipal.Caption
          End If
      Else
          edtISBN.Text = ""
          edtISBN.SetFocus
      End If
    Else
      MsgBox "ISBN inválido!", _
      vbCritical + vbOKOnly, fPrincipal.Caption
      edtISBN.Text = ""
      edtLivro.Text = ""
    End If
  End If
End Sub

Private Sub btnPCliente_Click()
  Dim pfConClientes As frmConClientes
  Set pfConClientes = New frmConClientes
  Rotinas.ChamarTela pfConClientes
  edtDescricao.Text = Rotinas.sCodigoSelecionado
  edtDescricao_LostFocus
End Sub

Private Sub btnPLivro_Click()
  Dim pfConLivros As frmConLivros
  Set pfConLivros = New frmConLivros
  Rotinas.ChamarTela pfConLivros
  edtISBN.Text = Rotinas.sCodigoSelecionado
  edtISBN_LostFocus
End Sub


Private Sub edtDescricao_LostFocus()
  If edtDescricao.Text <> "" Then
    If Rotinas.ValidaCPF(edtDescricao.Text) Then
          edtCliente.Text = _
          Rotinas.ConsultaCampoDescX(ConsCampo, _
          ConsSQL.Cliente("S", edtDescricao.Text, _
          "", "", "", "", "", "", "", "", ""), "Cliente não encontrado!")
          If edtCliente.Text = "" Then
                edtDescricao.Text = ""
                edtDescricao.SetFocus
          End If
    Else
      MsgBox "CPF inválido!", vbCritical + vbOKOnly, fPrincipal.Caption
      edtDescricao.Text = ""
      edtCliente.Text = ""
    End If
  End If
End Sub

Private Sub Form_Activate()
    btnLimpar_Click
End Sub

Private Sub Form_Load()   
    Me.Height = 4935
    Me.Width = 6930
End Sub

Private Sub Form_Unload(Cancel As Integer)
    fPrincipal.mnuVendasRealizadas.Enabled = True
    fConsultas.frmUnload Consulta
End Sub

Private Sub Form_Resize()
  gridConsulta.Height = Me.Height - 3375
  btnLimpar.Left = Me.Width - 2445
  btnFechar.Left = Me.Width - 1290
  LabPrecoTotal.Left = Me.Width - 3090
  edtPrecoTotal.Left = Me.Width - 2130
End Sub

Private Sub gridConsulta_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    fConsultas.frmMouseMove Me
End Sub

Private Sub gridConsulta_RowColChange(LastRow As Variant, ByVal LastCol As Integer)
    fConsultas.ConsultaChange Me, Consulta
End Sub




