VERSION 5.00
Begin VB.Form frmLogin 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Login do Sistema"
   ClientHeight    =   2145
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   3105
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2145
   ScaleWidth      =   3105
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Tag             =   "Login"
   Begin VB.CommandButton btnCancelar 
      Cancel          =   -1  'True
      Caption         =   "Cancelar"
      Height          =   360
      Left            =   1680
      TabIndex        =   3
      Tag             =   "Cancel"
      Top             =   1620
      Width           =   1140
   End
   Begin VB.CommandButton btnLogin 
      Caption         =   "Login"
      Default         =   -1  'True
      Height          =   360
      Left            =   390
      TabIndex        =   2
      Tag             =   "OK"
      Top             =   1620
      Width           =   1140
   End
   Begin VB.TextBox edtSenha 
      Height          =   285
      IMEMode         =   3  'DISABLE
      Left            =   1815
      MaxLength       =   10
      PasswordChar    =   "*"
      TabIndex        =   1
      Top             =   1155
      Width           =   1125
   End
   Begin VB.TextBox edtLogin 
      Height          =   285
      Left            =   1815
      MaxLength       =   10
      TabIndex        =   0
      Top             =   420
      Width           =   1125
   End
   Begin VB.Image Image1 
      Height          =   1350
      Left            =   90
      Picture         =   "Login.frx":0000
      Stretch         =   -1  'True
      Top             =   105
      Width           =   1470
   End
   Begin VB.Label lblLabels 
      Caption         =   "Senha:"
      Height          =   255
      Index           =   1
      Left            =   1815
      TabIndex        =   4
      Top             =   885
      Width           =   600
   End
   Begin VB.Label lblLabels 
      Caption         =   "Login:"
      Height          =   255
      Index           =   0
      Left            =   1815
      TabIndex        =   5
      Top             =   150
      Width           =   480
   End
End
Attribute VB_Name = "frmLogin"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private bFecharOuTerminar As Boolean
Private Consulta As ADODB.Recordset

Private Sub btnCancelar_Click()
     bFecharOuTerminar = False
     Unload Me
End Sub

Private Sub btnLogin_Click()

If Rotinas.ConsultaDados(Consulta, _
   ConsSQL.Usuario("S", edtLogin.Text, edtSenha.Text)) Then
 Rotinas.sUsuarioLogin = edtLogin.Text
 Rotinas.sUsuarioSenha = edtSenha.Text
 fPrincipal.sbStatusBar.Panels.Item(1).Text = "Usuário: " & edtLogin.Text

 bFecharOuTerminar = True
 Unload Me
Else
    MsgBox "Login ou senha incorretos!", vbCritical + vbOKOnly
End If

End Sub

Private Sub Form_Load()
    Set Consulta = New Recordset
End Sub

Private Sub Form_Unload(Cancel As Integer)
    If bFecharOuTerminar Then
       Cancel = False
    Else
      End
    End If
End Sub
