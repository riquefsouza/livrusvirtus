Imports System
Imports System.Drawing
Imports wx

Namespace Livrus

	Public Class frmSplash
		Inherits wx.SplashScreen
		
		public shared ID_FRMSPLASH As Integer = 100
		public shared WithEvents fSplash as frmSplash

    Public Sub New(ByVal parent as Window)
      MyBase.New( new wx.Bitmap("xpms/LivrusVirtus.xpm", _
        wx.BitmapType.wxBITMAP_TYPE_XPM), _
        wx.SplashScreen.wxSPLASH_CENTRE_ON_SCREEN or _
        wx.SplashScreen.wxSPLASH_TIMEOUT, _
        1000, parent, ID_FRMSPLASH, wxDefaultPosition, wxDefaultSize, _
        wxSIMPLE_BORDER or wxSTAY_ON_TOP )
			EVT_CLOSE( new EventListener(AddressOf OnClose ) )
    End Sub

		public sub OnClose(ByVal sender As Object, ByVal e As wx.Event)
      frmLogin.fLogin = new frmLogin(nothing)
      frmLogin.fLogin.Show(true)
			e.Skip()
		End Sub

	End Class

End Namespace
