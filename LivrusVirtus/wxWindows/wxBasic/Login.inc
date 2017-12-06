option explicit

Const ID_FRMLOGIN_BMPLOGIN = 200
Const ID_FRMLOGIN_LABLOGIN = 201
Const ID_FRMLOGIN_EDTLOGIN = 202
Const ID_FRMLOGIN_LABSENHA = 203
Const ID_FRMLOGIN_EDTSENHA = 204
Const ID_FRMLOGIN_BTNLOGIN = 205
Const ID_FRMLOGIN_BTNCANCELAR = 206

dim common frmLogin_bmpLogin
dim common frmLogin_labLogin
dim common frmLogin_edtLogin
dim common frmLogin_labSenha
dim common frmLogin_edtSenha
dim common frmLogin_btnLogin
dim common frmLogin_btnCancelar
dim common frmLogin_bFechar

function frmLogin_Criar()
  dim fLogin = new wxDialog(0, -1, "Login do Sistema", wxPoint(546, 346), 
      wxSize(211, 168), wxDEFAULT_DIALOG_STYLE, "") 

  dim bmp_login = new wxEmptyBitmap( 0, 0 ) 
  bmp_login.LoadFile( "xpms/login.xpm", wxBITMAP_TYPE_XPM ) 

  frmLogin_bmpLogin = new wxStaticBitmap(fLogin, ID_FRMLOGIN_BMPLOGIN,    
    wxPoint(8, 8), wxSize(90, 90), bmp_login)
	frmLogin_labLogin = new wxStaticText(fLogin, ID_FRMLOGIN_LABLOGIN,
    "Login:", wxPoint(112, 8), wxSize(29, 13) )
	frmLogin_edtLogin = new wxTextCtrl(fLogin, ID_FRMLOGIN_EDTLOGIN, "", 
    wxPoint(112, 24), wxSize(80, 21) )
  'frmLogin_edtLogin.SetMaxLength(10)
	frmLogin_labSenha = new wxStaticText(fLogin, ID_FRMLOGIN_LABSENHA,
    "Senha:", wxPoint(112, 56), wxSize(34, 13) )
	frmLogin_edtSenha = new wxTextCtrl(fLogin, ID_FRMLOGIN_EDTSENHA, "", 
    wxPoint(112, 72), wxSize(80, 21), wxTE_PASSWORD )
  'frmLogin_edtSenha.MaxLength(10)
	frmLogin_btnLogin = new wxButton(fLogin, ID_FRMLOGIN_BTNLOGIN, "&Login",
    wxPoint(24, 107), wxSize(75, 25))
	frmLogin_btnCancelar = new wxButton(fLogin, ID_FRMLOGIN_BTNCANCELAR, "&Cancelar",
    wxPoint(112, 107), wxSize(75, 25))
	frmLogin_btnLogin.SetDefault()

  frmLogin_bFechar = False
  frmLogin_FazLayout(fLogin)

  return fLogin
end function

sub frmLogin_FazLayout(parent)
	dim sizer_1 = new wxBoxSizer(wxVERTICAL)
	dim sizer_4 = new wxBoxSizer(wxHORIZONTAL)
	dim sizer_2 = new wxBoxSizer(wxHORIZONTAL)
	dim sizer_3 = new wxBoxSizer(wxVERTICAL)
	sizer_2.Add(frmLogin_bmpLogin, 0, wxALL, 6)
	sizer_3.Add(frmLogin_labLogin, 0, wxALL + wxALIGN_BOTTOM, 2)
	sizer_3.Add(frmLogin_edtLogin, 0, wxALL, 2)
	sizer_3.Add(frmLogin_labSenha, 0, wxALL + wxALIGN_BOTTOM, 2)
	sizer_3.Add(frmLogin_edtSenha, 0, wxALL, 2)
	sizer_2.Add(sizer_3, 0, wxALL, 6)
	sizer_1.Add(sizer_2, 0, 0, 3)
	sizer_4.Add(frmLogin_btnLogin, 0, wxLEFT + wxTOP + wxBOTTOM + wxALIGN_BOTTOM, 10)
	sizer_4.Add(frmLogin_btnCancelar, 0, wxALL + wxALIGN_BOTTOM, 10)
	sizer_1.Add(sizer_4, 0, wxALL + wxALIGN_CENTER_HORIZONTAL, 1)
	parent.SetSizer(sizer_1)
	'sizer_1.Fit(parent)
	sizer_1.SetSizeHints(parent)
	parent.Layout()
	parent.Centre()
End Sub

dim common frmLogin = frmLogin_Criar()

Function frmLogin_OnClose( event )
  if frmLogin_bFechar then
    frmLogin.Destroy()
  else
    frmLogin.Destroy()
    frmPrincipal.Destroy()
    End
  end if
  event.Skip()
End Function
Connect( frmLogin, wxEVT_CLOSE_WINDOW, "frmLogin_OnClose" )

Function frmLogin_OnBtnLoginClick( event )
  Rotinas_sUsuarioLogin = frmLogin_edtLogin.GetValue()
  Rotinas_sUsuarioSenha = frmLogin_edtSenha.GetValue()

  'if Rotinas_ConsultaDados(Consulta, ConsSQL_Usuario("S",
  '   Rotinas_sUsuarioLogin, Rotinas_sUsuarioSenha)) then
    Rotinas_sBarraLogin = STR_USUARIO + Rotinas_sUsuarioLogin
    frmPrincipal.SetStatusText(Rotinas_sBarraLogin, 1)
  
    frmLogin_bFechar = True
    frmLogin.Close(True)
		frmPrincipal.Show(True)
  'else
  '  wxMessageBox(STR_LOGSENINC, "Erro", wxOK + wxICON_ERROR )
  'end if
  
  event.Skip()
End Function
connect( frmLogin, ID_FRMLOGIN_BTNLOGIN, wxEVT_COMMAND_BUTTON_CLICKED, 
  "frmLogin_OnBtnLoginClick" )

Function frmLogin_OnBtnCancelarClick( event )
  frmLogin_bFechar = False
  frmLogin.Close(True)
  event.Skip()
End Function
connect( frmLogin, ID_FRMLOGIN_BTNCANCELAR, wxEVT_COMMAND_BUTTON_CLICKED, 
  "frmLogin_OnBtnCancelarClick" )
