VERSION 5.00
Begin VB.Form frmCadAutores 
   Caption         =   "Cadastro de Autores"
   ClientHeight    =   2100
   ClientLeft      =   3990
   ClientTop       =   3945
   ClientWidth     =   4935
   KeyPreview      =   -1  'True
   MDIChild        =   -1  'True
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   2100
   ScaleWidth      =   4935
   Begin VB.CommandButton btnSalvar 
      Caption         =   "&Salvar"
      Enabled         =   0   'False
      Height          =   400
      Left            =   300
      TabIndex        =   6
      Top             =   1560
      Width           =   1065
   End
   Begin VB.CommandButton btnExcluir 
      Caption         =   "&Excluir"
      Enabled         =   0   'False
      Height          =   400
      Left            =   1455
      TabIndex        =   7
      Top             =   1560
      Width           =   1065
   End
   Begin VB.CommandButton btnLimpar 
      Caption         =   "&Limpar"
      Height          =   400
      Left            =   2610
      TabIndex        =   8
      Top             =   1560
      Width           =   1065
   End
   Begin VB.CommandButton btnFechar 
      Caption         =   "&Fechar"
      Height          =   400
      Left            =   3765
      TabIndex        =   9
      Top             =   1560
      Width           =   1065
   End
   Begin VB.CommandButton btnProximo 
      Caption         =   "Próxi&mo"
      Enabled         =   0   'False
      Height          =   400
      Left            =   3765
      TabIndex        =   5
      Top             =   1080
      Width           =   1065
   End
   Begin VB.CommandButton btnAnterior 
      Caption         =   "&Anterior"
      Enabled         =   0   'False
      Height          =   400
      Left            =   3765
      TabIndex        =   4
      Top             =   600
      Width           =   1065
   End
   Begin VB.CommandButton btnPesquisar 
      Caption         =   "&Pesquisar"
      Height          =   400
      Left            =   3765
      TabIndex        =   3
      Top             =   105
      Width           =   1065
   End
   Begin VB.CommandButton btnNovo 
      Caption         =   "&Novo"
      Height          =   400
      Left            =   1770
      TabIndex        =   1
      Top             =   315
      Width           =   1065
   End
   Begin VB.TextBox edtDescricao 
      Height          =   285
      Left            =   105
      TabIndex        =   2
      Top             =   960
      Width           =   3480
   End
   Begin VB.TextBox edtCodigo 
      Height          =   285
      Left            =   105
      TabIndex        =   0
      Top             =   360
      Width           =   1380
   End
   Begin VB.Label lblLabels2 
      Caption         =   "Autor:"
      Height          =   255
      Left            =   105
      TabIndex        =   11
      Top             =   720
      Width           =   765
   End
   Begin VB.Label lblLabels 
      Caption         =   "Código:"
      Height          =   255
      Left            =   105
      TabIndex        =   10
      Top             =   105
      Width           =   660
   End
End
Attribute VB_Name = "frmCadAutores"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Consulta, Arquiva As ADODB.Recordset

Private Function ValidaDados(bTodosDados As Boolean) As Boolean
ValidaDados = True
If Rotinas.ValidaCampo(edtCodigo.Text, "Código não informado!") Then
  ValidaDados = False
  Exit Function
End If
If bTodosDados Then
  If Rotinas.ValidaCampo(edtDescricao.Text, "Autor não informado!") Then
    ValidaDados = False
    Exit Function
  End If
End If
End Function

Private Sub btnAnterior_Click()
    fCadastros.btnAnterior Me, Consulta
End Sub

Private Sub btnExcluir_Click()
    fCadastros.ExcluirDados Me, ValidaDados(False), Consulta, _
    ConsSQL.Autor("D", edtCodigo.Text, "")
End Sub

Private Sub btnFechar_Click()
    fCadastros.btnFechar Me
End Sub

Private Sub btnLimpar_Click()
    fCadastros.btnLimpar Me, Consulta
End Sub

Private Sub btnNovo_Click()
    fCadastros.btnNovo Me, Consulta
    fCadastros.NovoDado Me, Consulta, ConsSQL.Autor("N", edtCodigo.Text, "")
End Sub

Private Sub btnPesquisar_Click()
    fCadastros.PesquisarDados Me, Consulta, _
    ConsSQL.Autor("S", edtCodigo.Text, ""), "Autor não encontrado!"
End Sub

Private Sub btnProximo_Click()
    fCadastros.btnProximo Me, Consulta
End Sub

Private Sub btnSalvar_Click()
    fCadastros.SalvarDados Me, ValidaDados(True), Consulta, Arquiva, _
    ConsSQL.Autor("S", edtCodigo.Text, ""), _
    ConsSQL.Autor("U", edtCodigo.Text, edtDescricao.Text), _
    ConsSQL.Autor("I", edtCodigo.Text, edtDescricao.Text), True
End Sub

Private Sub edtCodigo_LostFocus()
    fCadastros.edtCodigoLostFocus Me
End Sub

Private Sub Form_Load()
    Set Consulta = New ADODB.Recordset
    Set Arquiva = New ADODB.Recordset

    fCadastros.frmLoad Me
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, _
Y As Single)
    fCadastros.frmMouseMove Me
End Sub

Private Sub Form_Unload(Cancel As Integer)
    fPrincipal.mnuCadAutores.Enabled = True
End Sub

