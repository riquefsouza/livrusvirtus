Attribute VB_Name = "LivrusApp"
Option Base 0
Option Explicit

Public WS As Workspace
Public DB As Database
Public sDirDB As String

Public Rotinas As clsRotinas
Public ConsSQL As clsConsSql

Public fPrincipal As frmPrincipal
Public fCadastros As clsCadastros
Public fConsultas As clsConsultas

Public Declare Function FindWindow Lib "user32" Alias "FindWindowA" (ByVal lpClassName As String, ByVal lpWindowName As String) As Long
'Public Declare Function GetClassName Lib "user32" Alias "GetClassNameA" (ByVal hwnd As Long, ByVal lpClassName As String, ByVal nMaxCount As Long) As Long

Sub Main()

  If FindWindow("ThunderMDIForm", "") = 0 Then
    
    Set Rotinas = New clsRotinas
    Set ConsSQL = New clsConsSql
    Set fCadastros = New clsCadastros
    Set fConsultas = New clsConsultas
    Set fPrincipal = New frmPrincipal
           
    Load fPrincipal
    fPrincipal.Show
  Else
    MsgBox "A Aplicação já está sendo executada.", vbOKOnly, "Erro"
  End If
End Sub


