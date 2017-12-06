VERSION 4.00
Begin VB.Form frmSobre 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Sobre o Sistema"
   ClientHeight    =   3405
   ClientLeft      =   4395
   ClientTop       =   3750
   ClientWidth     =   4575
   ClipControls    =   0   'False
   Height          =   3810
   Left            =   4335
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3405
   ScaleWidth      =   4575
   ShowInTaskbar   =   0   'False
   Tag             =   "Sobre Livrus"
   Top             =   3405
   Width           =   4695
   Begin VB.CommandButton cmdOK 
      Cancel          =   -1  'True
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   345
      Left            =   1680
      TabIndex        =   0
      Tag             =   "OK"
      Top             =   2950
      Width           =   1155
   End
   Begin VB.Frame Frame1 
      Height          =   2775
      Left            =   120
      TabIndex        =   1
      Top             =   0
      Width           =   4335
      Begin VB.PictureBox picIcon 
         AutoSize        =   -1  'True
         BorderStyle     =   0  'None
         ClipControls    =   0   'False
         Height          =   1080
         Left            =   240
         Picture         =   "Sobre.frx":0000
         ScaleHeight     =   1080
         ScaleMode       =   0  'User
         ScaleWidth      =   3810
         TabIndex        =   2
         TabStop         =   0   'False
         Top             =   240
         Width           =   3810
      End
      Begin VB.Label Label1 
         Caption         =   "Todos os diretos reservados para: Henrique F. de Souza"
         Height          =   225
         Left            =   135
         TabIndex        =   5
         Tag             =   "Version"
         Top             =   1740
         Width           =   4080
      End
      Begin VB.Label lblVersion 
         Alignment       =   1  'Right Justify
         Caption         =   "Versão: 1.0.0"
         Height          =   225
         Left            =   120
         TabIndex        =   4
         Tag             =   "Version"
         Top             =   1440
         Width           =   4080
      End
      Begin VB.Label lblDescription 
         Caption         =   "Sistema integrante do projeto Livrus Virtus, versão programada no Microsoft Visual Basic 4.0."
         ForeColor       =   &H00000000&
         Height          =   450
         Left            =   375
         TabIndex        =   3
         Tag             =   "App Description"
         Top             =   2100
         Width           =   3495
      End
   End
End
Attribute VB_Name = "frmSobre"
Attribute VB_Creatable = False
Attribute VB_Exposed = False


Private Sub Form_Activate()
    fPrincipal.sbStatusBar.Panels.Item(2).Text = Caption
End Sub

Private Sub Form_Load()
    'lblVersion.Caption = "Version " & App.Major & "." & App.Minor & "." & App.Revision
    'lblTitle.Caption = App.Title
End Sub

Private Sub cmdOK_Click()
        Unload Me
End Sub

