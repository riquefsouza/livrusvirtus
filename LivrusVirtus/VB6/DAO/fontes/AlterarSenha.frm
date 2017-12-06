VERSION 5.00
Begin VB.Form frmAlterarSenha 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Alteração de Senha"
   ClientHeight    =   1950
   ClientLeft      =   5205
   ClientTop       =   5910
   ClientWidth     =   3615
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MDIChild        =   -1  'True
   MinButton       =   0   'False
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   1950
   ScaleWidth      =   3615
   ShowInTaskbar   =   0   'False
   Begin VB.TextBox edtConfirmarSenha 
      Height          =   285
      IMEMode         =   3  'DISABLE
      Left            =   1680
      MaxLength       =   10
      PasswordChar    =   "*"
      TabIndex        =   3
      Top             =   1005
      Width           =   1335
   End
   Begin VB.TextBox edtSenhaAtual 
      Height          =   285
      IMEMode         =   3  'DISABLE
      Left            =   1680
      MaxLength       =   10
      PasswordChar    =   "*"
      TabIndex        =   1
      Top             =   375
      Width           =   1335
   End
   Begin VB.TextBox edtLogin 
      Enabled         =   0   'False
      Height          =   285
      Left            =   105
      MaxLength       =   10
      TabIndex        =   0
      Top             =   375
      Width           =   1335
   End
   Begin VB.TextBox edtNovaSenha 
      Height          =   285
      IMEMode         =   3  'DISABLE
      Left            =   105
      MaxLength       =   10
      PasswordChar    =   "*"
      TabIndex        =   2
      Top             =   1005
      Width           =   1335
   End
   Begin VB.CommandButton cmdFechar 
      Caption         =   "&Fechar"
      Height          =   400
      Left            =   2415
      TabIndex        =   6
      Top             =   1470
      Width           =   1065
   End
   Begin VB.CommandButton cmdLimpar 
      Caption         =   "&Limpar"
      Height          =   400
      Left            =   1260
      TabIndex        =   5
      Top             =   1470
      Width           =   1065
   End
   Begin VB.CommandButton cmdSalvar 
      Caption         =   "&Salvar"
      Height          =   400
      Left            =   105
      TabIndex        =   4
      Top             =   1470
      Width           =   1065
   End
   Begin VB.Label Label2 
      Caption         =   "Confirmar senha:"
      Height          =   255
      Left            =   1680
      TabIndex        =   10
      Top             =   735
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Senha atual:"
      Height          =   255
      Left            =   1680
      TabIndex        =   9
      Top             =   105
      Width           =   1215
   End
   Begin VB.Label labLogin 
      Caption         =   "Login:"
      Height          =   255
      Left            =   105
      TabIndex        =   8
      Top             =   105
      Width           =   480
   End
   Begin VB.Label labNovaSenha 
      Caption         =   "Nova Senha:"
      Height          =   255
      Left            =   105
      TabIndex        =   7
      Top             =   735
      Width           =   1020
   End
End
Attribute VB_Name = "frmAlterarSenha"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub cmdFechar_Click()
    Unload Me
End Sub

Private Sub cmdLimpar_Click()
    edtNovaSenha.Text = ""
    edtConfirmarSenha.Text = ""
    edtSenhaAtual.SetFocus
End Sub

Private Sub cmdSalvar_Click()
    If ValidaDados Then
        DB.Execute ConsSQL.Usuario("U", Rotinas.sUsuarioLogin, _
        edtConfirmarSenha.Text)
        Rotinas.sUsuarioSenha = edtNovaSenha.Text
        MsgBox "Senha alterada com sucesso!", vbOKOnly + vbInformation
    End If
End Sub

Private Sub Form_Load()
    edtLogin.Text = Rotinas.sUsuarioLogin
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
  fPrincipal.sbStatusBar.Panels.Item(2).Text = Caption
End Sub

Private Sub Form_Unload(Cancel As Integer)
    fPrincipal.mnuAlterarSenha.Enabled = True
End Sub

Function ValidaDados() As Boolean

ValidaDados = True
If Trim(edtSenhaAtual.Text) <> Trim(Rotinas.sUsuarioSenha) Then
 MsgBox "A Senha atual não confere com a senha do usuário!", vbCritical + vbOKOnly
 ValidaDados = False
 Exit Function
End If
If Rotinas.ValidaCampo(edtNovaSenha.Text, "Nova senha não informada!") Then
  ValidaDados = False
  Exit Function
End If
If Trim(edtNovaSenha.Text) <> Trim(edtConfirmarSenha.Text) Then
  MsgBox "A Nova senha não confere com a senha a confirmar!", vbCritical + vbOKOnly
  ValidaDados = False
  Exit Function
End If

End Function

