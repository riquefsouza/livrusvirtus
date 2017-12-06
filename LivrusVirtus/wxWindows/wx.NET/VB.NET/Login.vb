Imports System
Imports System.Drawing
Imports wx
Imports System.Data.OleDb

Namespace Livrus

	Public Class frmLogin
		Inherits wx.Dialog

		public shared WithEvents fLogin as frmLogin

		private enum idt
      ID_FRMLOGIN_BMPLOGIN = 200
      ID_FRMLOGIN_LABLOGIN
      ID_FRMLOGIN_EDTLOGIN 
      ID_FRMLOGIN_LABSENHA
      ID_FRMLOGIN_EDTSENHA
      ID_FRMLOGIN_BTNLOGIN
      ID_FRMLOGIN_BTNCANCELAR
		End Enum
    private bmpLogin as wx.StaticBitmap
    private labLogin as wx.StaticText
    private edtLogin as wx.TextCtrl
    private labSenha as wx.StaticText
    private edtSenha as wx.TextCtrl
    private btnLogin as wx.Button
    private btnCancelar as wx.Button
    private bFechar as boolean

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent, -1, "Login do Sistema", new Point(546, 346), _
        new Size(211, 168), wxDEFAULT_DIALOG_STYLE,"")

      bmpLogin = new wx.StaticBitmap(Me, idt.ID_FRMLOGIN_BMPLOGIN, _ 
        new wx.Bitmap("xpms/login.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), _
        new Point(8, 8), new Size(90, 90))
    	labLogin = new wx.StaticText(Me, idt.ID_FRMLOGIN_LABLOGIN, _
        "Login:", new Point(112, 8), new Size(29, 13) )
    	edtLogin = new wx.TextCtrl(Me, idt.ID_FRMLOGIN_EDTLOGIN, "", _ 
        new Point(112, 24), new Size(80, 21) )
      edtLogin.MaxLength = 10
    	labSenha = new wx.StaticText(Me, idt.ID_FRMLOGIN_LABSENHA, _
        "Senha:", new Point(112, 56), new Size(34, 13) )
    	edtSenha = new wx.TextCtrl(Me, idt.ID_FRMLOGIN_EDTSENHA, "", _ 
        new Point(112, 72), new Size(80, 21), wx.TextCtrl.wxTE_PASSWORD )
      edtSenha.MaxLength = 10
    	btnLogin = new wx.Button(Me, idt.ID_FRMLOGIN_BTNLOGIN, "&Login", _
        new Point(24, 107), new Size(75, 25))
    	btnCancelar = new wx.Button(Me, idt.ID_FRMLOGIN_BTNCANCELAR, "&Cancelar", _
        new Point(112, 107), new Size(75, 25))
    	btnLogin.SetDefault()
  
      bFechar = false
      FazLayout()

			EVT_CLOSE( new EventListener(AddressOf OnClose ) )
      EVT_BUTTON(idt.ID_FRMLOGIN_BTNLOGIN, _
        new EventListener(AddressOf OnBtnLoginClick ) )
      EVT_BUTTON(idt.ID_FRMLOGIN_BTNCANCELAR, _
        new EventListener(AddressOf OnBtnCancelarClick ) )
    End Sub

		private sub FazLayout()
    	dim sizer_1 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
    	dim sizer_4 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
    	dim sizer_2 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
    	dim sizer_3 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
    	sizer_2.Add(bmpLogin, 0, wx.Direction.wxALL, 6)
    	sizer_3.Add(labLogin, 0, wx.Direction.wxALL or wx.Alignment.wxALIGN_BOTTOM, 2)
    	sizer_3.Add(edtLogin, 0, wx.Direction.wxALL, 2)
    	sizer_3.Add(labSenha, 0, wx.Direction.wxALL or wx.Alignment.wxALIGN_BOTTOM, 2)
    	sizer_3.Add(edtSenha, 0, wx.Direction.wxALL, 2)
    	sizer_2.Add(sizer_3, 0, wx.Direction.wxALL, 6)
    	sizer_1.Add(sizer_2, 0, 0, 3)
    	sizer_4.Add(btnLogin, 0, wx.Direction.wxLEFT or wx.Direction.wxTOP or  _
        wx.Direction.wxBOTTOM or wx.Alignment.wxALIGN_BOTTOM, 10)
    	sizer_4.Add(btnCancelar, 0, wx.Direction.wxALL or wx.Alignment.wxALIGN_BOTTOM, 10)
    	sizer_1.Add(sizer_4, 0, _
        wx.Direction.wxALL or wx.Alignment.wxALIGN_CENTER_HORIZONTAL, 1)
    	Me.SetSizer(sizer_1)
    	sizer_1.Fit(Me)
    	sizer_1.SetSizeHints(Me)
    	Me.Layout()
    	Me.Centre()
		End Sub

		public sub OnClose(ByVal sender As Object, ByVal e As wx.Event)
      if bFechar then
        Destroy()
      else
        Destroy()
        frmPrincipal.fPrincipal.Destroy()
      end if
		End Sub

		public sub OnBtnLoginClick(ByVal sender As Object, ByVal e As wx.Event)
      dim Consulta as OleDbCommand = new OleDbCommand()
      RotinasGlobais.Rotinas.sUsuarioLogin = edtLogin.Value
      RotinasGlobais.Rotinas.sUsuarioSenha = edtSenha.Value
  
      if RotinasGlobais.Rotinas.ConsultaDados(Consulta, _
         ConsultasSQL.ConsSQL.Usuario("S", _
         RotinasGlobais.Rotinas.sUsuarioLogin, _
         RotinasGlobais.Rotinas.sUsuarioSenha)) then
        RotinasGlobais.Rotinas.sBarraLogin = Resource.STR_USUARIO + _
          RotinasGlobais.Rotinas.sUsuarioLogin
        frmPrincipal.fPrincipal.SetStatusText(RotinasGlobais.Rotinas.sBarraLogin, 0)
      
        bFechar = true
        Me.Close(true)
  			frmPrincipal.fPrincipal.Show( true )      
      else
        MessageDialog.MessageBox(Resource.STR_LOGSENINC, "Erro", _
          Dialog.wxOK or Dialog.wxICON_ERROR )
      end if
      
      e.Skip()
		End Sub

		public sub OnBtnCancelarClick(ByVal sender As Object, ByVal e As wx.Event)
      bFechar = false
      Me.Close(true)
      e.Skip()
		End Sub

	End Class

End Namespace
