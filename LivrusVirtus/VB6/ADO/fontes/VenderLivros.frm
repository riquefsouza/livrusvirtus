VERSION 5.00
Begin VB.Form frmVenderLivros 
   Caption         =   "Vender Livros"
   ClientHeight    =   4650
   ClientLeft      =   3120
   ClientTop       =   3225
   ClientWidth     =   7200
   LinkTopic       =   "Form1"
   MDIChild        =   -1  'True
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   4650
   ScaleWidth      =   7200
   Begin VB.CommandButton btnAdLivros 
      Caption         =   "+"
      Height          =   300
      Left            =   6360
      TabIndex        =   11
      Top             =   1560
      Width           =   300
   End
   Begin VB.CommandButton btnFechar 
      Caption         =   "&Fechar"
      Height          =   400
      Left            =   6030
      TabIndex        =   19
      Top             =   4200
      Width           =   1065
   End
   Begin VB.CommandButton btnLimpar 
      Caption         =   "&Limpar"
      Height          =   400
      Left            =   4875
      TabIndex        =   18
      Top             =   4200
      Width           =   1065
   End
   Begin VB.CommandButton btnVender 
      Caption         =   "&Vender"
      Height          =   400
      Left            =   3720
      TabIndex        =   17
      Top             =   4200
      Width           =   1065
   End
   Begin VB.TextBox edtPrecoTotal 
      Enabled         =   0   'False
      Height          =   285
      Left            =   5160
      TabIndex        =   16
      Top             =   3720
      Width           =   1935
   End
   Begin VB.ListBox lstLivros 
      Height          =   1425
      Left            =   120
      TabIndex        =   14
      Top             =   2160
      Width           =   6975
   End
   Begin VB.CommandButton btnPLivro 
      Caption         =   "..."
      Height          =   300
      Left            =   6720
      TabIndex        =   12
      Top             =   1560
      Width           =   300
   End
   Begin VB.TextBox edtLivro 
      Enabled         =   0   'False
      Height          =   285
      Left            =   2160
      TabIndex        =   10
      Top             =   1560
      Width           =   4215
   End
   Begin VB.TextBox edtISBN 
      Height          =   285
      Left            =   120
      MaxLength       =   14
      TabIndex        =   8
      Top             =   1560
      Width           =   1935
   End
   Begin VB.CommandButton btnPCliente 
      Caption         =   "..."
      Height          =   300
      Left            =   6720
      TabIndex        =   6
      Top             =   960
      Width           =   300
   End
   Begin VB.TextBox edtCliente 
      Enabled         =   0   'False
      Height          =   285
      Left            =   2160
      TabIndex        =   5
      Top             =   960
      Width           =   4575
   End
   Begin VB.TextBox edtCPF 
      Height          =   285
      Left            =   120
      MaxLength       =   14
      TabIndex        =   3
      Top             =   960
      Width           =   1935
   End
   Begin VB.TextBox edtDtHrVenda 
      Enabled         =   0   'False
      Height          =   285
      Left            =   120
      TabIndex        =   1
      Top             =   360
      Width           =   1935
   End
   Begin VB.Label Label7 
      Caption         =   "Prelo total:"
      Height          =   255
      Left            =   4200
      TabIndex        =   15
      Top             =   3720
      Width           =   855
   End
   Begin VB.Label Label6 
      Caption         =   "Livros para vender:"
      Height          =   255
      Left            =   120
      TabIndex        =   13
      Top             =   1920
      Width           =   1575
   End
   Begin VB.Label Label5 
      Caption         =   "Livro:"
      Height          =   255
      Left            =   2160
      TabIndex        =   9
      Top             =   1320
      Width           =   1575
   End
   Begin VB.Label Label4 
      Caption         =   "ISBN:"
      Height          =   255
      Left            =   120
      TabIndex        =   7
      Top             =   1320
      Width           =   1575
   End
   Begin VB.Label Label3 
      Caption         =   "Cliente:"
      Height          =   255
      Left            =   2160
      TabIndex        =   4
      Top             =   720
      Width           =   1575
   End
   Begin VB.Label Label2 
      Caption         =   "CPF:"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   720
      Width           =   1575
   End
   Begin VB.Label Label1 
      Caption         =   "Data/Hora Venda:"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1575
   End
End
Attribute VB_Name = "frmVenderLivros"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private nPrecoTotal As Single
Private slISBNs As Collection
Private slPrecos As Collection
Private slQtdEstoque As Collection
Private ConsCampo, Arquiva As ADODB.Recordset

Private Sub Form_Load()
  Set ConsCampo = New ADODB.Recordset
  Set Arquiva = New ADODB.Recordset
  
  Me.Height = 5055
  Me.Width = 7320

  nPrecoTotal = 0
  edtDtHrVenda.Text = Format(Date, "dd/MM/yyyy") + _
  " " + Format(Time, "hh:mm:ss")
  Set slISBNs = New Collection
  Set slPrecos = New Collection
  Set slQtdEstoque = New Collection
End Sub

Private Sub LimpaDados()
  edtDtHrVenda.Text = Format(Date, "dd/MM/yyyy") + _
  " " + Format(Time, "hh:mm:ss")
  edtCPF.Text = ""
  edtCliente.Text = ""
  edtISBN.Text = ""
  edtLivro.Text = ""
  lstLivros.Clear
  Rotinas.LimpaColecao slPrecos
  nPrecoTotal = 0
  edtPrecoTotal.Text = "R$ 0,00"
  edtCPF.SetFocus
End Sub

Private Function ValidaDados() As Boolean
    If (Rotinas.ValidaCampo(edtCPF.Text, _
                "CPF não informado!")) Then
      ValidaDados = False
    End If
    If (lstLivros.ListCount = 0) Then
      MsgBox "Livro(s) para vender não informado(s)!", _
      vbCritical + vbOKOnly, fPrincipal.Caption
      ValidaDados = False
    End If
    ValidaDados = True
End Function

Private Function SalvaLista() As Boolean
  Dim nCont, nQtdEstoque As Integer
On Error GoTo Erro
  For nCont = 1 To slISBNs.Count
   db.Execute _
   ConsSQL.Venda("I", slISBNs.Item(nCont), _
   edtCPF.Text, Format(CDate(edtDtHrVenda.Text), "MM/dd/yyyy hh:mm:ss"), _
   Rotinas.VirgulaParaPonto(CStr(nPrecoTotal), False), "")
  
   nQtdEstoque = CInt(slQtdEstoque.Item(nCont))
   nQtdEstoque = nQtdEstoque - 1
   db.Execute _
   ConsSQL.Venda("U", slISBNs.Item(nCont), "", "", "", CStr(nQtdEstoque))
  Next nCont
    SalvaLista = True
Erro:
  MsgBox Err.Description, vbCritical + vbOKOnly, fPrincipal.Caption
  SalvaLista = False
End Function

Private Sub edtCPF_LostFocus()
  If edtCPF.Text <> "" Then
    If (Rotinas.ValidaCPF(edtCPF.Text)) Then
      edtCliente.Text = _
      Rotinas.ConsultaCampoDescX(ConsCampo, _
      ConsSQL.Cliente("S", edtCPF.Text, _
      "", "", "", "", "", "", "", "", ""), "Cliente não encontrado!")
      If (edtCliente.Text = "") Then
        edtCPF.Text = ""
        edtCPF.SetFocus
      End If
    Else
      MsgBox "CPF inválido!", _
      vbCritical + vbOKOnly, fPrincipal.Caption
      edtCPF.Text = ""
      edtCliente.Text = ""
    End If
  End If
End Sub

Private Sub btnPCliente_Click()
  Dim pfConClientes As frmConClientes
  Set pfConClientes = New frmConClientes
  Rotinas.ChamarTela pfConClientes
  edtCPF.Text = Rotinas.sCodigoSelecionado
  edtCPF_LostFocus
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

Private Sub btnPLivro_Click()
  Dim pfConLivros As frmConLivros
  Set pfConLivros = New frmConLivros
  Rotinas.ChamarTela pfConLivros
  edtISBN.Text = Rotinas.sCodigoSelecionado
  edtISBN_LostFocus
End Sub

Private Sub btnAdLivros_Click()
  Dim sLivros As String
  
  If edtISBN.Text <> "" Then
    sLivros = edtISBN.Text & " - " & edtLivro.Text & _
    " - R$ " & Rotinas.sPreco
    If Rotinas.ListaIndiceDe(lstLivros, sLivros) = -1 Then
       slISBNs.Add edtISBN.Text
       slPrecos.Add Rotinas.sPreco
       slQtdEstoque.Add Rotinas.sQtdEstoque
       lstLivros.AddItem sLivros
       nPrecoTotal = nPrecoTotal + CSng(Rotinas.sPreco)
    End If
    edtISBN.Text = ""
    edtLivro.Text = ""
    edtPrecoTotal.Text = "R$ " & Rotinas.VirgulaParaPonto( _
                   CStr(nPrecoTotal), True)
  End If
End Sub

Private Sub lstLivros_DblClick()
  Dim nPreco As Single
  
  If (lstLivros.ListCount > 0) Then
    nPreco = CSng(slPrecos.Item(lstLivros.ListIndex + 1))
    nPrecoTotal = nPrecoTotal - nPreco
    edtPrecoTotal.Text = "R$ " + CStr(nPrecoTotal)
  
    slISBNs.Remove lstLivros.ListIndex + 1
    slPrecos.Remove lstLivros.ListIndex + 1
    slQtdEstoque.Remove lstLivros.ListIndex + 1
    lstLivros.RemoveItem lstLivros.ListIndex
  End If
End Sub

Private Sub btnVender_Click()
  If ValidaDados Then
     If SalvaLista Then
        MsgBox "Venda realizada com sucesso!", _
        vbInformation + vbOKOnly, fPrincipal.Caption
        LimpaDados
     End If
  End If
End Sub

Private Sub btnLimpar_Click()
  LimpaDados
End Sub

Private Sub btnFechar_Click()
  Form_Unload False
  Unload Me
End Sub

Private Sub Form_Unload(Cancel As Integer)
  fPrincipal.tbToolBar.Buttons.Item(3).Enabled = True
  fPrincipal.mnuVenderLivros.Enabled = True
  fPrincipal.sbStatusBar.Panels.Item(2).Text = ""
End Sub
 
Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, _
Y As Single)
  fPrincipal.sbStatusBar.Panels.Item(2).Text = Me.Caption
End Sub

