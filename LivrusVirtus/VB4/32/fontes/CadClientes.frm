VERSION 4.00
Begin VB.Form frmCadClientes 
   Caption         =   "Cadastro de Clientes"
   ClientHeight    =   6630
   ClientLeft      =   2430
   ClientTop       =   3120
   ClientWidth     =   7785
   Height          =   7035
   KeyPreview      =   -1  'True
   Left            =   2370
   MDIChild        =   -1  'True
   ScaleHeight     =   6630
   ScaleWidth      =   7785
   Top             =   2775
   Width           =   7905
   Begin VB.CommandButton btnPProfissao 
      Caption         =   "..."
      Enabled         =   0   'False
      Height          =   300
      Left            =   4800
      TabIndex        =   23
      Top             =   5640
      Width           =   300
   End
   Begin VB.TextBox edtProfissao 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1320
      TabIndex        =   22
      Top             =   5640
      Width           =   3495
   End
   Begin VB.TextBox edtCodProfissao 
      Enabled         =   0   'False
      Height          =   285
      Left            =   120
      MaxLength       =   10
      TabIndex        =   21
      Top             =   5640
      Width           =   1095
   End
   Begin VB.CommandButton btnPPais 
      Caption         =   "..."
      Enabled         =   0   'False
      Height          =   300
      Left            =   4800
      TabIndex        =   20
      Top             =   5040
      Width           =   300
   End
   Begin VB.TextBox edtPais 
      Enabled         =   0   'False
      Height          =   285
      Left            =   1320
      TabIndex        =   19
      Top             =   5040
      Width           =   3495
   End
   Begin VB.TextBox edtCodPais 
      Enabled         =   0   'False
      Height          =   285
      Left            =   120
      MaxLength       =   3
      TabIndex        =   18
      Top             =   5040
      Width           =   1095
   End
   Begin VB.Frame grpEndereco 
      Caption         =   "Endereço"
      Height          =   2055
      Left            =   120
      TabIndex        =   10
      Top             =   2640
      Width           =   6375
      Begin VB.CommandButton btnPEndereco 
         Caption         =   "..."
         Enabled         =   0   'False
         Height          =   300
         Left            =   1440
         TabIndex        =   12
         Top             =   360
         Width           =   300
      End
      Begin VB.TextBox edtEstado 
         Enabled         =   0   'False
         Height          =   285
         Left            =   4320
         MaxLength       =   20
         TabIndex        =   17
         Top             =   1560
         Width           =   1935
      End
      Begin VB.TextBox edtCidade 
         Enabled         =   0   'False
         Height          =   285
         Left            =   1215
         MaxLength       =   20
         TabIndex        =   16
         Top             =   1590
         Width           =   3015
      End
      Begin VB.TextBox edtCEP 
         Enabled         =   0   'False
         Height          =   285
         Left            =   135
         MaxLength       =   10
         TabIndex        =   15
         Top             =   1590
         Width           =   975
      End
      Begin VB.TextBox edtBairro 
         Enabled         =   0   'False
         Height          =   285
         Left            =   4335
         MaxLength       =   20
         TabIndex        =   14
         Top             =   990
         Width           =   1935
      End
      Begin VB.TextBox edtCodEndereco 
         Enabled         =   0   'False
         Height          =   285
         Left            =   120
         MaxLength       =   10
         TabIndex        =   11
         Top             =   375
         Width           =   1215
      End
      Begin VB.TextBox edtLogradouro 
         Enabled         =   0   'False
         Height          =   285
         Left            =   120
         MaxLength       =   30
         TabIndex        =   13
         Top             =   975
         Width           =   4110
      End
      Begin VB.Label Label10 
         Caption         =   "Estado:"
         Height          =   255
         Left            =   4335
         TabIndex        =   41
         Top             =   1335
         Width           =   660
      End
      Begin VB.Label Label9 
         Caption         =   "Cidade:"
         Height          =   255
         Left            =   1215
         TabIndex        =   40
         Top             =   1335
         Width           =   660
      End
      Begin VB.Label Label8 
         Caption         =   "CEP:"
         Height          =   255
         Left            =   135
         TabIndex        =   39
         Top             =   1335
         Width           =   660
      End
      Begin VB.Label Label7 
         Caption         =   "Bairro:"
         Height          =   255
         Left            =   4335
         TabIndex        =   38
         Top             =   735
         Width           =   660
      End
      Begin VB.Label Label5 
         Caption         =   "Logradouro:"
         Height          =   255
         Left            =   120
         TabIndex        =   37
         Top             =   735
         Width           =   1245
      End
   End
   Begin VB.TextBox edtDtNascimento 
      Enabled         =   0   'False
      Height          =   285
      Left            =   4920
      MaxLength       =   10
      TabIndex        =   9
      Top             =   2175
      Width           =   1575
   End
   Begin VB.TextBox edtTelefone 
      Enabled         =   0   'False
      Height          =   285
      Left            =   3120
      MaxLength       =   10
      TabIndex        =   8
      Top             =   2175
      Width           =   1695
   End
   Begin VB.Frame grpSexo 
      Caption         =   "Sexo"
      Height          =   615
      Left            =   120
      TabIndex        =   5
      Top             =   1920
      Width           =   2895
      Begin VB.OptionButton rbFeminino 
         Caption         =   "Feminino"
         Enabled         =   0   'False
         Height          =   255
         Left            =   1560
         TabIndex        =   7
         Top             =   240
         Width           =   975
      End
      Begin VB.OptionButton rbMasculino 
         Caption         =   "Masculino"
         Enabled         =   0   'False
         Height          =   255
         Left            =   240
         TabIndex        =   6
         Top             =   240
         Width           =   1215
      End
   End
   Begin VB.TextBox edtIdentidade 
      Enabled         =   0   'False
      Height          =   285
      Left            =   4920
      MaxLength       =   10
      TabIndex        =   4
      Top             =   1575
      Width           =   1575
   End
   Begin VB.TextBox edtEmail 
      Enabled         =   0   'False
      Height          =   285
      Left            =   120
      MaxLength       =   30
      TabIndex        =   3
      Top             =   1560
      Width           =   4710
   End
   Begin VB.CommandButton btnSalvar 
      Caption         =   "&Salvar"
      Enabled         =   0   'False
      Height          =   400
      Left            =   3180
      TabIndex        =   27
      Top             =   6120
      Width           =   1065
   End
   Begin VB.CommandButton btnExcluir 
      Caption         =   "&Excluir"
      Enabled         =   0   'False
      Height          =   400
      Left            =   4335
      TabIndex        =   28
      Top             =   6120
      Width           =   1065
   End
   Begin VB.CommandButton btnLimpar 
      Caption         =   "&Limpar"
      Height          =   400
      Left            =   5490
      TabIndex        =   29
      Top             =   6120
      Width           =   1065
   End
   Begin VB.CommandButton btnFechar 
      Caption         =   "&Fechar"
      Height          =   400
      Left            =   6645
      TabIndex        =   30
      Top             =   6120
      Width           =   1065
   End
   Begin VB.CommandButton btnProximo 
      Caption         =   "Próxi&mo"
      Enabled         =   0   'False
      Height          =   400
      Left            =   6645
      TabIndex        =   26
      Top             =   1080
      Width           =   1065
   End
   Begin VB.CommandButton btnAnterior 
      Caption         =   "&Anterior"
      Enabled         =   0   'False
      Height          =   400
      Left            =   6645
      TabIndex        =   25
      Top             =   600
      Width           =   1065
   End
   Begin VB.CommandButton btnPesquisar 
      Caption         =   "&Pesquisar"
      Height          =   400
      Left            =   6645
      TabIndex        =   24
      Top             =   105
      Width           =   1065
   End
   Begin VB.CommandButton btnNovo 
      Caption         =   "&Novo"
      Height          =   400
      Left            =   2160
      TabIndex        =   1
      Top             =   315
      Width           =   1065
   End
   Begin VB.TextBox edtDescricao 
      Enabled         =   0   'False
      Height          =   285
      Left            =   105
      MaxLength       =   30
      TabIndex        =   2
      Top             =   960
      Width           =   4710
   End
   Begin VB.TextBox edtCodigo 
      Height          =   285
      Left            =   105
      MaxLength       =   14
      TabIndex        =   0
      Top             =   360
      Width           =   1860
   End
   Begin VB.Label Label11 
      Caption         =   "Profissão:"
      Height          =   255
      Left            =   120
      TabIndex        =   43
      Top             =   5400
      Width           =   855
   End
   Begin VB.Label Label6 
      Caption         =   "País de origem:"
      Height          =   255
      Left            =   120
      TabIndex        =   42
      Top             =   4800
      Width           =   1335
   End
   Begin VB.Label Label4 
      Caption         =   "Dt. Nascimento:"
      Height          =   255
      Left            =   4920
      TabIndex        =   36
      Top             =   1920
      Width           =   1335
   End
   Begin VB.Label Label3 
      Caption         =   "Telefone:"
      Height          =   255
      Left            =   3120
      TabIndex        =   35
      Top             =   1920
      Width           =   1335
   End
   Begin VB.Label Label2 
      Caption         =   "Identidade:"
      Height          =   255
      Left            =   4920
      TabIndex        =   34
      Top             =   1320
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "E-mail:"
      Height          =   255
      Left            =   120
      TabIndex        =   33
      Top             =   1320
      Width           =   765
   End
   Begin VB.Label lblLabels2 
      Caption         =   "Nome:"
      Height          =   255
      Left            =   105
      TabIndex        =   32
      Top             =   720
      Width           =   765
   End
   Begin VB.Label lblLabels 
      Caption         =   "CPF:"
      Height          =   255
      Left            =   105
      TabIndex        =   31
      Top             =   105
      Width           =   660
   End
End
Attribute VB_Name = "frmCadClientes"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
Private Consulta As Recordset
Private Arquiva As Recordset
Private ConsCampo As Recordset
Private sSexo As String

Private Function ValidaDados(bTodosDados As Boolean) As Boolean
ValidaDados = True
If Rotinas.ValidaCampo(edtCodigo.Text, "CPF não informado!") Then
  ValidaDados = False
  Exit Function
End If
If bTodosDados Then
  If Rotinas.ValidaCampo(edtDescricao.Text, "Nome não informado!") Then
    ValidaDados = False
    Exit Function
  End If
  If (Rotinas.ValidaCampo(edtEmail.Text, "E-mail não informado!")) Then
     ValidaDados = False
     Exit Function
  End If
  If (rbMasculino.Value = False And rbFeminino.Value = False) Then
    MsgBox "Sexo não informado!", vbCritical + vbOKOnly, fPrincipal.Caption
    ValidaDados = False
    Exit Function
  End If
  If (Rotinas.ValidaCampo(edtTelefone.Text, "Telefone não informado!")) Then
    ValidaDados = False
    Exit Function
  End If
  If (Rotinas.ValidaCampo(edtCodEndereco.Text, "Endereço não informado!")) Then
    ValidaDados = False
    Exit Function
  End If
  If (Rotinas.ValidaCampo(edtCodPais.Text, "País não informado!")) Then
    ValidaDados = False
    Exit Function
  End If
  If (Rotinas.ValidaCampo(edtCodProfissao.Text, "Profissão não informada!")) Then
    ValidaDados = False
    Exit Function
  End If
End If
End Function

Private Sub InformaLimpaDados(Consulta As Recordset, bInformar As Boolean)
  fCadastros.InformaLimpaDados Me, Consulta, bInformar

  If bInformar Then
    edtEmail.Text = Consulta.Fields.Item(2).Value
    edtIdentidade.Text = Consulta.Fields.Item(3).Value
    If Consulta.Fields.Item(4).Value = "M" Then
       rbMasculino.Value = True
       rbFeminino.Value = False
    Else
      rbMasculino.Value = False
      rbFeminino.Value = True
    End If
    edtTelefone.Text = Consulta.Fields.Item(5).Value
    edtDtNascimento.Text = Format(CDate(Consulta.Fields.Item(6).Value), "dd/MM/yyyy")
    edtCodEndereco.Text = Consulta.Fields.Item(7).Value
    edtLogradouro.Text = Consulta.Fields.Item(8).Value
    edtBairro.Text = Consulta.Fields.Item(9).Value
    edtCEP.Text = Consulta.Fields.Item(10).Value
    edtCidade.Text = Consulta.Fields.Item(11).Value
    edtEstado.Text = Consulta.Fields.Item(12).Value
    edtCodPais.Text = Consulta.Fields.Item(13).Value
    edtPais.Text = Consulta.Fields.Item(14).Value
    edtCodProfissao.Text = Consulta.Fields.Item(15).Value
    edtProfissao.Text = Consulta.Fields.Item(16).Value
  Else
    edtEmail.Text = ""
    edtIdentidade.Text = ""
    rbMasculino.Value = False
    rbFeminino.Value = False
    edtTelefone.Text = ""
    edtDtNascimento.Text = Format(Date, "dd/MM/yyyy")
    edtCodEndereco.Text = ""
    edtLogradouro.Text = ""
    edtBairro.Text = ""
    edtCEP.Text = ""
    edtCidade.Text = ""
    edtEstado.Text = ""
    edtCodPais.Text = ""
    edtPais.Text = ""
    edtCodProfissao.Text = ""
    edtProfissao.Text = ""
  End If

End Sub

Private Sub HabilitaDados(bHabilita As Boolean)
  fCadastros.HabilitaDados Me, bHabilita
  
   edtEmail.Enabled = bHabilita
   edtIdentidade.Enabled = bHabilita
   rbMasculino.Enabled = bHabilita
   rbFeminino.Enabled = bHabilita
   edtTelefone.Enabled = bHabilita
   edtDtNascimento.Enabled = bHabilita
   edtCodEndereco.Enabled = bHabilita
   btnPEndereco.Enabled = bHabilita
   edtCodPais.Enabled = bHabilita
   btnPPais.Enabled = bHabilita
   edtCodProfissao.Enabled = bHabilita
   btnPProfissao.Enabled = bHabilita
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
    ConsSQL.Cliente("D", edtCodigo.Text, _
    "", "", "", "", "", "", "", "", "")) Then
       btnLimpar_Click
    End If
 End If
End Sub

Private Sub btnFechar_Click()
    fCadastros.btnFechar Me
End Sub

Private Sub btnLimpar_Click()
    fCadastros.btnLimpar Me, Consulta
    InformaLimpaDados Consulta, False
    HabilitaDados False
End Sub

Private Sub btnNovo_Click()
    InformaLimpaDados Consulta, False
    HabilitaDados True
    fCadastros.btnNovo Me, Consulta
End Sub

Private Sub btnPesquisar_Click()
  If fCadastros.PesquisarDados(Me, Consulta, _
    ConsSQL.Cliente("S", edtCodigo.Text, _
    "", "", "", "", "", "", "", "", ""), "Cliente não encontrado!") Then
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
   
 If rbMasculino.Value Then
    sSexo = "M"
 Else
    sSexo = "F"
 End If
 
 If bValida Then
    fCadastros.SalvarDados Me, bValida, Consulta, Arquiva, _
    ConsSQL.Cliente("S", edtCodigo.Text, "", "", "", "", "", "", "", "", ""), _
    ConsSQL.Cliente("U", edtCodigo.Text, edtDescricao.Text, _
    edtEmail.Text, edtIdentidade.Text, sSexo, edtTelefone.Text, _
    Format(CDate(edtDtNascimento.Text), "MM/dd/yyyy"), _
    edtCodEndereco.Text, edtCodPais.Text, edtCodProfissao.Text), _
    ConsSQL.Cliente("I", edtCodigo.Text, edtDescricao.Text, _
    edtEmail.Text, edtIdentidade.Text, sSexo, edtTelefone.Text, _
    Format(CDate(edtDtNascimento.Text), "MM/dd/yyyy"), _
    edtCodEndereco.Text, edtCodPais.Text, edtCodProfissao.Text), True
    btnLimpar_Click
 End If
End Sub

Private Sub edtCodigo_LostFocus()
  If (edtCodigo.Text <> "") Then
    If (Rotinas.ValidaCPF(edtCodigo.Text) = False) Then
       MsgBox "CPF inválido!", vbCritical + vbOKOnly, fPrincipal.Caption
       edtCodigo.Text = ""
       edtCodigo.SetFocus
    End If
  End If
End Sub

Private Sub Form_Load()
    Me.Height = 7035
    Me.Width = 7905
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, _
Y As Single)
    fCadastros.frmMouseMove Me
End Sub

Private Sub Form_Unload(Cancel As Integer)
    fPrincipal.tbToolBar.Buttons.Item(1).Enabled = True
    fPrincipal.mnuCadClientes.Enabled = True
End Sub

Private Sub edtCodEndereco_LostFocus()
  If (edtCodEndereco.Text <> "") Then
    edtLogradouro.Text = _
    Rotinas.ConsultaCampoDesc(ConsCampo, _
    edtCodEndereco.Text, ConsSQL.Endereco("S", _
    edtCodEndereco.Text, "", "", "", "", ""), "Endereço não encontrado!")
    If (edtLogradouro.Text <> "") Then
      edtBairro.Text = ConsCampo.Fields.Item(2).Value
      edtCEP.Text = ConsCampo.Fields.Item(3).Value
      edtCidade.Text = ConsCampo.Fields.Item(4).Value
      edtEstado.Text = ConsCampo.Fields.Item(5).Value
    Else
      edtCodEndereco.SetFocus
      edtLogradouro.Text = ""
      edtBairro.Text = ""
      edtCEP.Text = ""
      edtCidade.Text = ""
      edtEstado.Text = ""
    End If
  Else
    edtLogradouro.Text = ""
    edtBairro.Text = ""
    edtCEP.Text = ""
    edtCidade.Text = ""
    edtEstado.Text = ""
  End If
End Sub

Private Sub edtCodPais_LostFocus()
  If (edtCodPais.Text <> "") Then
     edtPais.Text = Rotinas.ConsultaCampoDescX(ConsCampo, _
     ConsSQL.Pais("S", edtCodPais.Text, ""), "País não encontrado!")
     If (edtPais.Text = "") Then
         edtCodPais.Text = ""
         edtCodPais.SetFocus
     End If
   Else
        edtPais.Text = ""
   End If
End Sub

Private Sub edtCodProfissao_LostFocus()
  If (edtCodProfissao.Text <> "") Then
     edtProfissao.Text = Rotinas.ConsultaCampoDesc(ConsCampo, _
     edtCodProfissao.Text, ConsSQL.Profissao("S", _
     edtCodProfissao.Text, ""), "Profissão não encontrada!")
     If (edtProfissao.Text = "") Then
         edtProfissao.Text = ""
         edtCodProfissao.SetFocus
     End If
  Else
     edtProfissao.Text = ""
  End If
End Sub

Private Sub btnPEndereco_Click()
  Dim pfConEnderecos As frmConEnderecos
  Set pfConEnderecos = New frmConEnderecos
  Rotinas.ChamarTela pfConEnderecos
  edtCodEndereco.Text = Rotinas.sCodigoSelecionado
  edtCodEndereco_LostFocus
End Sub

Private Sub btnPPais_Click()
  Dim pfConPaises As frmConPaises
  Set pfConPaises = New frmConPaises
  Rotinas.ChamarTela pfConPaises
  edtCodPais.Text = Rotinas.sCodigoSelecionado
  edtCodPais_LostFocus
End Sub

Private Sub btnPProfissao_Click()
  Dim pfConProfissoes As frmConProfissoes
  Set pfConProfissoes = New frmConProfissoes
  Rotinas.ChamarTela pfConProfissoes
  edtCodProfissao.Text = Rotinas.sCodigoSelecionado
  edtCodProfissao_LostFocus
End Sub
