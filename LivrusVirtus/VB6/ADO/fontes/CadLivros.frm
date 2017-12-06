VERSION 5.00
Begin VB.Form frmCadLivros 
   Caption         =   "Cadastro de Livros"
   ClientHeight    =   5760
   ClientLeft      =   2430
   ClientTop       =   3555
   ClientWidth     =   7545
   KeyPreview      =   -1  'True
   MDIChild        =   -1  'True
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   5760
   ScaleWidth      =   7545
   Begin VB.ListBox lstAutores 
      Height          =   645
      Left            =   1440
      TabIndex        =   34
      Top             =   4440
      Width           =   4935
   End
   Begin VB.ListBox lstAssuntos 
      Height          =   645
      Left            =   1440
      TabIndex        =   26
      Top             =   3120
      Width           =   4935
   End
   Begin VB.ComboBox cmbIdioma 
      Enabled         =   0   'False
      Height          =   315
      Left            =   1440
      Style           =   2  'Dropdown List
      TabIndex        =   16
      Top             =   2160
      Width           =   4815
   End
   Begin VB.TextBox edtCodEditora 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1440
      MaxLength       =   10
      TabIndex        =   10
      Top             =   1560
      Width           =   975
   End
   Begin VB.TextBox edtEditora 
      Enabled         =   0   'False
      Height          =   285
      Left            =   2520
      TabIndex        =   11
      Top             =   1560
      Width           =   3495
   End
   Begin VB.CommandButton btnPEditora 
      Caption         =   "..."
      Enabled         =   0   'False
      Height          =   300
      Left            =   6000
      TabIndex        =   12
      Top             =   1560
      Width           =   300
   End
   Begin VB.TextBox edtCodAutor 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1440
      MaxLength       =   10
      TabIndex        =   30
      Top             =   4080
      Width           =   975
   End
   Begin VB.TextBox edtAutor 
      Enabled         =   0   'False
      Height          =   285
      Left            =   2520
      TabIndex        =   31
      Top             =   4080
      Width           =   3135
   End
   Begin VB.CommandButton btnPAutor 
      Caption         =   "..."
      Enabled         =   0   'False
      Height          =   300
      Left            =   6000
      TabIndex        =   33
      Top             =   4080
      Width           =   300
   End
   Begin VB.CommandButton btnAdAutores 
      Caption         =   "+"
      Enabled         =   0   'False
      Height          =   300
      Left            =   5640
      TabIndex        =   32
      Top             =   4080
      Width           =   300
   End
   Begin VB.TextBox edtCodAssunto 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1440
      MaxLength       =   10
      TabIndex        =   20
      Top             =   2760
      Width           =   975
   End
   Begin VB.TextBox edtAssunto 
      Enabled         =   0   'False
      Height          =   285
      Left            =   2520
      TabIndex        =   21
      Top             =   2760
      Width           =   3135
   End
   Begin VB.CommandButton btnPAssunto 
      Caption         =   "..."
      Enabled         =   0   'False
      Height          =   300
      Left            =   6000
      TabIndex        =   23
      Top             =   2760
      Width           =   300
   End
   Begin VB.CommandButton btnAdAssuntos 
      Caption         =   "+"
      Enabled         =   0   'False
      Height          =   300
      Left            =   5640
      TabIndex        =   22
      Top             =   2760
      Width           =   300
   End
   Begin VB.TextBox edtQtdEstoque 
      Enabled         =   0   'False
      Height          =   285
      Left            =   120
      MaxLength       =   4
      TabIndex        =   28
      Text            =   "0"
      Top             =   4080
      Width           =   1215
   End
   Begin VB.TextBox edtPreco 
      Enabled         =   0   'False
      Height          =   285
      Left            =   120
      MaxLength       =   10
      TabIndex        =   25
      Top             =   3480
      Width           =   1215
   End
   Begin VB.TextBox edtNPaginas 
      Enabled         =   0   'False
      Height          =   285
      Left            =   120
      MaxLength       =   4
      TabIndex        =   18
      Text            =   "1"
      Top             =   2760
      Width           =   1215
   End
   Begin VB.TextBox edtVolume 
      Enabled         =   0   'False
      Height          =   285
      Left            =   120
      MaxLength       =   4
      TabIndex        =   14
      Text            =   "1"
      Top             =   2160
      Width           =   1215
   End
   Begin VB.TextBox edtAnoPubli 
      Enabled         =   0   'False
      Height          =   285
      Left            =   120
      MaxLength       =   4
      TabIndex        =   8
      Text            =   "2004"
      Top             =   1560
      Width           =   1215
   End
   Begin VB.TextBox edtEdicao 
      Enabled         =   0   'False
      Height          =   285
      Left            =   4920
      MaxLength       =   4
      TabIndex        =   6
      Text            =   "1"
      Top             =   960
      Width           =   1335
   End
   Begin VB.CommandButton btnSalvar 
      Caption         =   "&Salvar"
      Enabled         =   0   'False
      Height          =   400
      Left            =   2940
      TabIndex        =   38
      Top             =   5280
      Width           =   1065
   End
   Begin VB.CommandButton btnExcluir 
      Caption         =   "&Excluir"
      Enabled         =   0   'False
      Height          =   400
      Left            =   4095
      TabIndex        =   39
      Top             =   5280
      Width           =   1065
   End
   Begin VB.CommandButton btnLimpar 
      Caption         =   "&Limpar"
      Height          =   400
      Left            =   5250
      TabIndex        =   40
      Top             =   5280
      Width           =   1065
   End
   Begin VB.CommandButton btnFechar 
      Caption         =   "&Fechar"
      Height          =   400
      Left            =   6405
      TabIndex        =   41
      Top             =   5280
      Width           =   1065
   End
   Begin VB.CommandButton btnProximo 
      Caption         =   "Próxi&mo"
      Enabled         =   0   'False
      Height          =   400
      Left            =   6405
      TabIndex        =   37
      Top             =   1080
      Width           =   1065
   End
   Begin VB.CommandButton btnAnterior 
      Caption         =   "&Anterior"
      Enabled         =   0   'False
      Height          =   400
      Left            =   6405
      TabIndex        =   36
      Top             =   600
      Width           =   1065
   End
   Begin VB.CommandButton btnPesquisar 
      Caption         =   "&Pesquisar"
      Height          =   400
      Left            =   6405
      TabIndex        =   35
      Top             =   105
      Width           =   1065
   End
   Begin VB.CommandButton btnNovo 
      Caption         =   "&Novo"
      Height          =   400
      Left            =   2160
      TabIndex        =   2
      Top             =   315
      Width           =   1065
   End
   Begin VB.TextBox edtDescricao 
      Enabled         =   0   'False
      Height          =   285
      Left            =   105
      MaxLength       =   30
      TabIndex        =   4
      Top             =   960
      Width           =   4710
   End
   Begin VB.TextBox edtCodigo 
      Height          =   285
      Left            =   105
      MaxLength       =   13
      TabIndex        =   1
      Top             =   360
      Width           =   1860
   End
   Begin VB.Label Label10 
      Caption         =   "Idioma:"
      Height          =   255
      Left            =   1440
      TabIndex        =   15
      Top             =   1920
      Width           =   855
   End
   Begin VB.Label Label9 
      Caption         =   "Editora:"
      Height          =   255
      Left            =   1440
      TabIndex        =   9
      Top             =   1320
      Width           =   855
   End
   Begin VB.Label Label7 
      Caption         =   "Autor:"
      Height          =   255
      Left            =   1440
      TabIndex        =   29
      Top             =   3840
      Width           =   855
   End
   Begin VB.Label Label8 
      Caption         =   "Assunto:"
      Height          =   255
      Left            =   1440
      TabIndex        =   19
      Top             =   2520
      Width           =   855
   End
   Begin VB.Label Label6 
      Caption         =   "Qtd. Estoque:"
      Height          =   255
      Left            =   120
      TabIndex        =   27
      Top             =   3840
      Width           =   1245
   End
   Begin VB.Label Label5 
      Caption         =   "Preço:"
      Height          =   255
      Left            =   120
      TabIndex        =   24
      Top             =   3240
      Width           =   1245
   End
   Begin VB.Label Label4 
      Caption         =   "Nº Páginas:"
      Height          =   255
      Left            =   120
      TabIndex        =   17
      Top             =   2520
      Width           =   1245
   End
   Begin VB.Label Label3 
      Caption         =   "Volume:"
      Height          =   255
      Left            =   120
      TabIndex        =   13
      Top             =   1920
      Width           =   1245
   End
   Begin VB.Label Label2 
      Caption         =   "Ano Publicação:"
      Height          =   255
      Left            =   120
      TabIndex        =   7
      Top             =   1320
      Width           =   1245
   End
   Begin VB.Label Label1 
      Caption         =   "Edição:"
      Height          =   255
      Left            =   4920
      TabIndex        =   5
      Top             =   720
      Width           =   765
   End
   Begin VB.Label lblLabels2 
      Caption         =   "Título:"
      Height          =   255
      Left            =   105
      TabIndex        =   3
      Top             =   720
      Width           =   765
   End
   Begin VB.Label lblLabels 
      Caption         =   "ISBN:"
      Height          =   255
      Left            =   105
      TabIndex        =   0
      Top             =   105
      Width           =   660
   End
End
Attribute VB_Name = "frmCadLivros"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Consulta, Arquiva As ADODB.Recordset
Private slIdiomas As Collection
Private slAssuntos As Collection
Private slAutores As Collection
Private ConsCampo, ConsLista As ADODB.Recordset

Private Function ValidaDados(bTodosDados As Boolean) As Boolean
ValidaDados = True
If Rotinas.ValidaCampo(edtCodigo.Text, "ISBN não informado!") Then
  ValidaDados = False
  Exit Function
End If
If bTodosDados Then
  If Rotinas.ValidaCampo(edtDescricao.Text, "Título não informado!") Then
    ValidaDados = False
    Exit Function
  End If
  If (Rotinas.ValidaCampo(edtEditora.Text, "Editora não informada!")) Then
    ValidaDados = False
    Exit Function
  End If
  If (lstAssuntos.ListCount = 0) Then
    MsgBox "Assunto(s) não informado(s)!", vbCritical + vbOKOnly, fPrincipal.Caption
    ValidaDados = False
    Exit Function
  End If
  If (lstAutores.ListCount = 0) Then
    MsgBox "Autor(es) não informado(s)!", vbCritical + vbOKOnly, fPrincipal.Caption
    ValidaDados = False
    Exit Function
  End If
End If
End Function

Private Sub InformaLimpaDados(ByVal Consulta As ADODB.Recordset, bInformar As Boolean)
  fCadastros.InformaLimpaDados Me, Consulta, bInformar

  If bInformar Then
    edtEdicao.Text = Consulta.Fields(2).Value
    edtAnoPubli.Text = Consulta.Fields(3).Value
    edtVolume.Text = Consulta.Fields(4).Value
    edtCodEditora.Text = Consulta.Fields(5).Value
    edtEditora.Text = Consulta.Fields(6).Value
    cmbIdioma.ListIndex = Rotinas.ColecaoIndiceDe(slIdiomas, Consulta.Fields(7).Value)
    edtNPaginas.Text = Consulta.Fields(9).Value
    edtPreco.Text = Rotinas.VirgulaParaPonto(Consulta.Fields(10).Value, True)
    edtQtdEstoque.Text = Consulta.Fields(11).Value
    Rotinas.AdicionaValoresLista ConsLista, _
    ConsSQL.LivroAss("S", edtCodigo.Text, ""), lstAssuntos, slAssuntos
    Rotinas.AdicionaValoresLista ConsLista, _
    ConsSQL.LivroAut("S", edtCodigo.Text, ""), lstAutores, slAutores
  Else
    edtEdicao.Text = "1"
    edtAnoPubli.Text = CStr(Year(Date))
    edtVolume.Text = "1"
    edtCodEditora.Text = ""
    edtEditora.Text = ""
    edtNPaginas.Text = "1"
    edtPreco.Text = "0,00"
    edtQtdEstoque.Text = "1"
    edtCodAssunto.Text = ""
    lstAssuntos.Clear
    edtCodAutor.Text = ""
    lstAutores.Clear
    Rotinas.LimpaColecao slAssuntos
    Rotinas.LimpaColecao slAutores
  End If

End Sub

Private Sub HabilitaDados(bHabilita As Boolean)
  fCadastros.HabilitaDados Me, bHabilita
  
  edtEdicao.Enabled = bHabilita
  edtAnoPubli.Enabled = bHabilita
  edtVolume.Enabled = bHabilita
  edtCodEditora.Enabled = bHabilita
  btnPEditora.Enabled = bHabilita
  cmbIdioma.Enabled = bHabilita
  edtNPaginas.Enabled = bHabilita
  edtPreco.Enabled = bHabilita
  edtQtdEstoque.Enabled = bHabilita
  edtCodAssunto.Enabled = bHabilita
  btnPAssunto.Enabled = bHabilita
  btnAdAssuntos.Enabled = bHabilita
  lstAssuntos.Enabled = bHabilita
  edtCodAutor.Enabled = bHabilita
  btnPAutor.Enabled = bHabilita
  btnAdAutores.Enabled = bHabilita
  lstAutores.Enabled = bHabilita
End Sub

Private Sub btnAnterior_Click()
    If fCadastros.btnAnterior(Me, Consulta) Then
       InformaLimpaDados Consulta, True
    End If
End Sub

Private Sub btnExcluir_Click()
Dim bValida As Boolean
bValida = ValidaDados(False)

 If bValida Then
    If fCadastros.ExcluirDados(Me, bValida, Consulta, _
    ConsSQL.Livro("D", edtCodigo.Text, _
    "", "", "", "", "", "", "", "", "")) Then
       btnLimpar_Click
    End If
 End If
End Sub

Private Sub btnFechar_Click()
    fCadastros.btnFechar Me
    Form_Unload False
End Sub

Private Sub btnLimpar_Click()
    fCadastros.btnLimpar Me, Consulta
    InformaLimpaDados Consulta, False
    HabilitaDados False
End Sub

Private Sub btnNovo_Click()
    fCadastros.btnNovo Me, Consulta
    HabilitaDados True
    fCadastros.btnNovo Me, Consulta
End Sub

Private Sub btnPesquisar_Click()
  If fCadastros.PesquisarDados(Me, Consulta, _
    ConsSQL.Livro("S", edtCodigo.Text, _
    "", "", "", "", "", "", "", "", ""), "Livro não encontrado!") Then
    InformaLimpaDados Consulta, True
    HabilitaDados True
  End If
End Sub

Private Sub btnProximo_Click()
    If fCadastros.btnProximo(Me, Consulta) Then
       InformaLimpaDados Consulta, True
    End If
End Sub

Private Sub btnSalvar_Click()
Dim bValida As Boolean
bValida = ValidaDados(True)

 If bValida Then
    fCadastros.SalvarDados Me, bValida, Consulta, Arquiva, _
    ConsSQL.Livro("S", edtCodigo.Text, "", "", "", "", "", "", "", "", ""), _
    ConsSQL.Livro("U", edtCodigo.Text, edtDescricao.Text, _
    edtEdicao.Text, edtAnoPubli.Text, edtVolume.Text, edtCodEditora.Text, _
    slIdiomas(cmbIdioma.ListIndex), edtNPaginas.Text, _
    Rotinas.VirgulaParaPonto(edtPreco.Text, False), edtQtdEstoque.Text), _
    ConsSQL.Livro("I", edtCodigo.Text, edtDescricao.Text, _
    edtEdicao.Text, edtAnoPubli.Text, edtVolume.Text, edtCodEditora.Text, _
    slIdiomas(cmbIdioma.ListIndex), edtNPaginas.Text, _
    Rotinas.VirgulaParaPonto(edtPreco.Text, False), edtQtdEstoque.Text), True
    SalvaLista ("A")
    SalvaLista ("B")
    btnLimpar_Click
 End If
End Sub

Private Sub Form_Load()
    Set Consulta = New ADODB.Recordset
    Set Arquiva = New ADODB.Recordset
    Set ConsCampo = New ADODB.Recordset
    Set ConsLista = New ADODB.Recordset

    Me.Height = 6165
    Me.Width = 7665

    Set slIdiomas = New Collection
    Set slAssuntos = New Collection
    Set slAutores = New Collection

  edtAnoPubli.Text = CStr(Year(Date))
  AdicionaCombo
  cmbIdioma.ListIndex = 0
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, _
Y As Single)
    fCadastros.frmMouseMove Me
End Sub

Private Sub Form_Unload(Cancel As Integer)
    fPrincipal.tbToolBar.Buttons.Item(2).Enabled = True
    fPrincipal.mnuCadLivros.Enabled = True
End Sub

Private Sub AdicionaCombo()
Dim cont As Integer
Dim regs As ADODB.Recordset

  Set regs = New ADODB.Recordset

  Rotinas.ConsultaDados regs, ConsSQL.Idioma("S", "", "")
  
  Do While Not regs.EOF
    slIdiomas.Add regs.Fields.Item(0).Value
    cmbIdioma.AddItem regs.Fields.Item(1).Value
    regs.MoveNext
  Loop
End Sub

Private Sub SalvaLista(sOpcao As String)
Dim nCont As Integer

  If sOpcao = "A" Then
   Rotinas.ConsultaDados Arquiva, _
   ConsSQL.LivroAss("D", edtCodigo.Text, "")
  
   For nCont = 0 To slAssuntos.Count - 1
    Rotinas.ConsultaDados Arquiva, _
    ConsSQL.LivroAss("I", edtCodigo.Text, slAssuntos(nCont))
   Next nCont
  ElseIf sOpcao = "B" Then
    Rotinas.ConsultaDados Arquiva, _
    ConsSQL.LivroAut("D", edtCodigo.Text, "")
  
    For nCont = 0 To slAutores.Count - 1
     Rotinas.ConsultaDados Arquiva, _
     ConsSQL.LivroAut("I", edtCodigo.Text, slAssuntos(nCont))
    Next nCont
  End If
End Sub

Private Sub edtCodigo_LostFocus()
  If edtCodigo.Text <> "" Then
    If Rotinas.ValidaISBN(edtCodigo.Text) = False Then
          MsgBox "ISBN inválido!", vbCritical + vbOKOnly, fPrincipal.Caption
          edtCodigo.Text = ""
          edtCodigo.SetFocus
    End If
  End If
End Sub

Private Sub edtCodEditora_LostFocus()
  If edtCodEditora.Text <> "" Then
     edtEditora.Text = Rotinas.ConsultaCampoDesc(ConsCampo, _
     edtCodEditora.Text, ConsSQL.Editora("S", _
     edtCodEditora.Text, ""), "Editora não encontrada!")
     If edtEditora.Text = "" Then
        edtCodEditora.SetFocus
     End If
  Else
        edtEditora.Text = ""
  End If
End Sub

Private Sub btnPEditora_Click()
  Dim pfConEditoras As frmConEditoras
  Set pfConEditoras = New frmConEditoras
  Rotinas.ChamarTela pfConEditoras
  edtCodEditora.Text = RotinasGlobais.Rotinas.sCodigoSelecionado
  edtCodEditora_LostFocus
End Sub

Private Sub edtPreco_LostFocus()
  If Rotinas.ValidaFloat(edtPreco.Text) Then
    edtPreco.Text = Rotinas.VirgulaParaPonto(edtPreco.Text, True)
  Else
    edtPreco.Text = "0,00"
  End If
End Sub

Private Sub edtCodAssunto_LostFocus()
  If edtCodAssunto.Text <> "" Then
     edtAssunto.Text = Rotinas.ConsultaCampoDesc(ConsCampo, _
     edtCodAssunto.Text, ConsSQL.Assunto("S", _
     edtCodAssunto.Text, ""), "Assunto não encontrado!")
     If edtAssunto.Text = "" Then
        edtCodAssunto.SetFocus
     End If
  Else
    edtAssunto.Text = ""
  End If
End Sub

Private Sub edtCodAutor_LostFocus()
  If edtCodAutor.Text <> "" Then
     edtAutor.Text = Rotinas.ConsultaCampoDesc(ConsCampo, _
     edtCodAutor.Text, ConsSQL.Autor("S", _
     edtCodAutor.Text, ""), "Autor não encontrado!")
     If edtAutor.Text = "" Then
        edtCodAutor.SetFocus
     End If
  Else
        edtAutor.Text = ""
  End If
End Sub

Private Sub btnPAssunto_Click()
  Dim pfConAssuntos As frmConAssuntos
  Set pfConAssuntos = New frmConAssuntos
  Rotinas.ChamarTela pfConAssuntos
  edtCodAssunto.Text = Rotinas.sCodigoSelecionado
  edtCodAssunto_LostFocus
End Sub

Private Sub btnPAutor_Click()
  Dim pfConAutores As frmConAutores
  Set pfConAutores = New frmConAutores
  Rotinas.ChamarTela pfConAutores
  edtCodAutor.Text = Rotinas.sCodigoSelecionado
  edtCodAutor_LostFocus
End Sub

Private Sub btnAdAssuntos_Click()
  Rotinas.AdicionaItemLista lstAssuntos, slAssuntos, edtCodAssunto, edtAssunto
End Sub

Private Sub lstAssuntos_DblClick()
  Rotinas.RemoveItemLista lstAssuntos, slAssuntos
End Sub

Private Sub btnAdAutores_Click()
  Rotinas.AdicionaItemLista lstAutores, slAutores, edtCodAutor, edtAutor
End Sub

Private Sub lstAutores_DblClick()
  Rotinas.RemoveItemLista lstAutores, slAutores
End Sub

