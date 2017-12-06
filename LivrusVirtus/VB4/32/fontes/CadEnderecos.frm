VERSION 4.00
Begin VB.Form frmCadEnderecos 
   Caption         =   "Cadastro de Endereços"
   ClientHeight    =   2520
   ClientLeft      =   2400
   ClientTop       =   2985
   ClientWidth     =   7845
   Height          =   2925
   KeyPreview      =   -1  'True
   Left            =   2340
   MDIChild        =   -1  'True
   ScaleHeight     =   2520
   ScaleWidth      =   7845
   Top             =   2640
   Width           =   7965
   Begin VB.ComboBox cmbEstado 
      Height          =   315
      Left            =   4320
      Style           =   2  'Dropdown List
      TabIndex        =   10
      Top             =   1560
      Width           =   2175
   End
   Begin VB.TextBox edtCidade 
      Height          =   285
      Left            =   1200
      MaxLength       =   20
      TabIndex        =   8
      Top             =   1575
      Width           =   3015
   End
   Begin VB.TextBox edtCEP 
      Height          =   285
      Left            =   120
      MaxLength       =   10
      TabIndex        =   6
      Top             =   1575
      Width           =   975
   End
   Begin VB.TextBox edtBairro 
      Height          =   285
      Left            =   4320
      MaxLength       =   20
      TabIndex        =   4
      Top             =   975
      Width           =   2175
   End
   Begin VB.CommandButton btnSalvar 
      Caption         =   "&Salvar"
      Enabled         =   0   'False
      Height          =   400
      Left            =   3180
      TabIndex        =   14
      Top             =   2040
      Width           =   1065
   End
   Begin VB.CommandButton btnExcluir 
      Caption         =   "&Excluir"
      Enabled         =   0   'False
      Height          =   400
      Left            =   4335
      TabIndex        =   15
      Top             =   2040
      Width           =   1065
   End
   Begin VB.CommandButton btnLimpar 
      Caption         =   "&Limpar"
      Height          =   400
      Left            =   5490
      TabIndex        =   16
      Top             =   2040
      Width           =   1065
   End
   Begin VB.CommandButton btnFechar 
      Caption         =   "&Fechar"
      Height          =   400
      Left            =   6645
      TabIndex        =   17
      Top             =   2040
      Width           =   1065
   End
   Begin VB.CommandButton btnProximo 
      Caption         =   "Próxi&mo"
      Enabled         =   0   'False
      Height          =   400
      Left            =   6645
      TabIndex        =   13
      Top             =   1080
      Width           =   1065
   End
   Begin VB.CommandButton btnAnterior 
      Caption         =   "&Anterior"
      Enabled         =   0   'False
      Height          =   400
      Left            =   6645
      TabIndex        =   12
      Top             =   600
      Width           =   1065
   End
   Begin VB.CommandButton btnPesquisar 
      Caption         =   "&Pesquisar"
      Height          =   400
      Left            =   6645
      TabIndex        =   11
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
      Height          =   285
      Left            =   105
      MaxLength       =   30
      TabIndex        =   2
      Top             =   960
      Width           =   4110
   End
   Begin VB.TextBox edtCodigo 
      Height          =   285
      Left            =   105
      MaxLength       =   10
      TabIndex        =   0
      Top             =   360
      Width           =   1860
   End
   Begin VB.Label Label4 
      Caption         =   "Estado:"
      Height          =   255
      Left            =   4320
      TabIndex        =   9
      Top             =   1320
      Width           =   660
   End
   Begin VB.Label Label3 
      Caption         =   "Cidade:"
      Height          =   255
      Left            =   1200
      TabIndex        =   7
      Top             =   1320
      Width           =   660
   End
   Begin VB.Label Label2 
      Caption         =   "CEP:"
      Height          =   255
      Left            =   120
      TabIndex        =   5
      Top             =   1320
      Width           =   660
   End
   Begin VB.Label Label1 
      Caption         =   "Bairro:"
      Height          =   255
      Left            =   4320
      TabIndex        =   3
      Top             =   720
      Width           =   660
   End
   Begin VB.Label lblLabels2 
      Caption         =   "Logradouro:"
      Height          =   255
      Left            =   105
      TabIndex        =   19
      Top             =   720
      Width           =   1245
   End
   Begin VB.Label lblLabels 
      Caption         =   "Código:"
      Height          =   255
      Left            =   105
      TabIndex        =   18
      Top             =   105
      Width           =   660
   End
End
Attribute VB_Name = "frmCadEnderecos"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
Private Consulta As Recordset
Private Arquiva As Recordset

Private Function ValidaDados(bTodosDados As Boolean) As Boolean
ValidaDados = True
If Rotinas.ValidaCampo(edtCodigo.Text, "Código não informado!") Then
  ValidaDados = False
  Exit Function
End If
If bTodosDados Then
  If Rotinas.ValidaCampo(edtDescricao.Text, "Logradouro não informado!") Then
    ValidaDados = False
    Exit Function
  End If
  If (Rotinas.ValidaCampo(edtBairro.Text, "Bairro não informado!")) Then
    ValidaDados = False
    Exit Function
  End If
  If (Rotinas.ValidaCampo(edtCEP.Text, "CEP não informado!")) Then
    ValidaDados = False
    Exit Function
  End If
  If (Rotinas.ValidaCampo(edtCidade.Text, "Cidade não informada!")) Then
    ValidaDados = False
    Exit Function
  End If
End If
End Function

Private Sub InformaLimpaDados(Consulta As Recordset, bInformar As Boolean)
  fCadastros.InformaLimpaDados Me, Consulta, bInformar
  
  If (bInformar) Then
    edtBairro.Text = Consulta.Fields.Item(2).Value
    edtCEP.Text = Consulta.Fields.Item(3).Value
    edtCidade.Text = Consulta.Fields.Item(4).Value
    RecuperaEstado (Consulta.Fields.Item(5).Value)
  Else
    edtBairro.Text = ""
    edtCEP.Text = ""
    edtCidade.Text = ""
    cmbEstado.ListIndex = 0
  End If
End Sub

Private Sub HabilitaDados(bHabilita As Boolean)
  fCadastros.HabilitaDados Me, bHabilita
  
  edtBairro.Enabled = bHabilita
  edtCEP.Enabled = bHabilita
  edtCidade.Enabled = bHabilita
  cmbEstado.Enabled = bHabilita
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
    ConsSQL.Endereco("D", edtCodigo.Text, "", "", "", "", "")) Then
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
    fCadastros.NovoDado Me, Consulta, _
    ConsSQL.Endereco("N", edtCodigo.Text, "", "", "", "", "")
End Sub

Private Sub btnPesquisar_Click()
  If fCadastros.PesquisarDados(Me, Consulta, _
    ConsSQL.Endereco("S", edtCodigo.Text, _
    "", "", "", "", ""), "Endereço não encontrado!") Then
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
    ConsSQL.Endereco("S", edtCodigo.Text, "", "", "", "", ""), _
    ConsSQL.Endereco("U", edtCodigo.Text, edtDescricao.Text, _
    edtBairro.Text, edtCEP.Text, edtCidade.Text, cmbEstado.Text), _
    ConsSQL.Endereco("I", edtCodigo.Text, edtDescricao.Text, _
    edtBairro.Text, edtCEP.Text, edtCidade.Text, cmbEstado.Text), True
    btnLimpar_Click
 End If
End Sub

Private Sub edtCodigo_LostFocus()
    fCadastros.edtCodigoLostFocus Me
End Sub

Private Sub Form_Load()
    Me.Height = 2925
    Me.Width = 7965
    AdicionaCombo
    cmbEstado.ListIndex = 0
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, _
Y As Single)
    fCadastros.frmMouseMove Me
End Sub

Private Sub Form_Unload(Cancel As Integer)
    fPrincipal.mnuCadEnderecos.Enabled = True
End Sub

Private Sub AdicionaCombo()
  cmbEstado.AddItem "Pernambuco"
  cmbEstado.AddItem "Acre"
  cmbEstado.AddItem "Alagoas"
  cmbEstado.AddItem "Amapá"
  cmbEstado.AddItem "Amazonas"
  cmbEstado.AddItem "Bahia"
  cmbEstado.AddItem "Brasília"
  cmbEstado.AddItem "Ceará"
  cmbEstado.AddItem "Distrito Federal"
  cmbEstado.AddItem "Espírito Santo"
  cmbEstado.AddItem "Goiás"
  cmbEstado.AddItem "Mato Grosso"
  cmbEstado.AddItem "Mato Grosso do Sul"
  cmbEstado.AddItem "Minas Gerais"
  cmbEstado.AddItem "Pará"
  cmbEstado.AddItem "Paraíba"
  cmbEstado.AddItem "Paraná"
  cmbEstado.AddItem "Santa Catarina"
  cmbEstado.AddItem "Rio Grande do Norte"
  cmbEstado.AddItem "Rio Grande do Sul"
  cmbEstado.AddItem "Rio de Janeiro"
  cmbEstado.AddItem "Rondônia"
  cmbEstado.AddItem "Roraima"
  cmbEstado.AddItem "São Paulo"
  cmbEstado.AddItem "Sergipe"
  cmbEstado.AddItem "Tocantins"
End Sub

Private Sub RecuperaEstado(sEstado As String)
 Dim nCont As Integer

 For nCont = 0 To cmbEstado.ListCount - 1
    If cmbEstado.List(nCont) = sEstado Then
       cmbEstado.ListIndex = nCont
    End If
 Next nCont
End Sub

