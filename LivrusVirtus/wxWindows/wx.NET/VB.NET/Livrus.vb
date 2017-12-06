Option Explicit On 
Option Strict On

Imports System
Imports System.Drawing
Imports wx

Namespace Livrus

	Public Class LivrusApp
		Inherits wx.App

		Public Overrides Function OnInit() As Boolean
      RotinasGlobais.Rotinas = new RotinasGlobais()
      ConsultasSQL.ConsSQL = new ConsultasSQL()
      frmPrincipal.fPrincipal = New frmPrincipal()

      if not RotinasGlobais.Rotinas.ConectaBanco( _
        "File Name=C:\LivrusVirtus\bancos\access\Access2k_Livrus.udl") then
        return false
      end if
      frmSplash.fSplash = new frmSplash(nothing)
      frmSplash.fSplash.Show(true)

			Return True
		End Function

    <STAThread()> Shared Sub Main()
    		dim aplicativo as LivrusApp 
        aplicativo = New LivrusApp()
    		aplicativo.Run()
    End Sub
	End Class

End NameSpace
