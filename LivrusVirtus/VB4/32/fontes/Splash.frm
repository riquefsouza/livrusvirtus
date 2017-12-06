VERSION 4.00
Begin VB.Form frmSplash 
   BorderStyle     =   0  'None
   ClientHeight    =   1050
   ClientLeft      =   4320
   ClientTop       =   4785
   ClientWidth     =   3795
   ControlBox      =   0   'False
   Height          =   1455
   Left            =   4260
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   Picture         =   "Splash.frx":0000
   ScaleHeight     =   1050
   ScaleWidth      =   3795
   ShowInTaskbar   =   0   'False
   Top             =   4440
   Visible         =   0   'False
   Width           =   3915
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   3360
      Top             =   600
   End
End
Attribute VB_Name = "frmSplash"
Attribute VB_Creatable = False
Attribute VB_Exposed = False


Private Sub Form_Load()
    'lblVersion.Caption = "Version " & App.Major & "." & App.Minor & "." & App.Revision
End Sub

Private Sub Timer1_Timer()
  Unload Me
End Sub
