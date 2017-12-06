include Principal.e

constant ID_FRMLOGIN_BMPLOGIN = 200
constant ID_FRMLOGIN_LABLOGIN = 201
constant ID_FRMLOGIN_EDTLOGIN = 202
constant ID_FRMLOGIN_LABSENHA = 203
constant ID_FRMLOGIN_EDTSENHA = 204
constant ID_FRMLOGIN_BTNLOGIN = 205
constant ID_FRMLOGIN_BTNCANCELAR = 206

atom bmp_login, frmLogin_bmpLogin, frmLogin_labLogin, frmLogin_edtLogin, 
  frmLogin_labSenha, frmLogin_edtSenha, frmLogin_btnLogin, 
  frmLogin_btnCancelar, frmLogin_bFechar

object void
global constant frmLogin = create( wxDialog,{0, FRMLOGIN, "Login do Sistema", 546, 346,
      211, 168, wxDEFAULT_DIALOG_STYLE, ""} )

procedure frmLogin_IniciaControles()
  bmp_login = create( wxBitmap, {BM_FROM_FILE, "login.xpm", wxBITMAP_TYPE_XPM})
  frmLogin_bmpLogin = create( wxPanel, {frmLogin, ID_FRMLOGIN_BMPLOGIN, 8, 8, 90, 90})

	frmLogin_labLogin = create( wxStaticText, {frmLogin, ID_FRMLOGIN_LABLOGIN,
    "Login:", 112, 8, 29, 13} )
	frmLogin_edtLogin = create( wxTextCtrl, {frmLogin, ID_FRMLOGIN_EDTLOGIN, "", 
    112, 24, 80, 21 } )
  --frmLogin_edtLogin.SetMaxLength(10)
	frmLogin_labSenha = create( wxStaticText, {frmLogin, ID_FRMLOGIN_LABSENHA,
    "Senha:", 112, 56, 34, 13})
	frmLogin_edtSenha = create( wxTextCtrl, {frmLogin, ID_FRMLOGIN_EDTSENHA, "", 
    112, 72, 80, 21, wxTE_PASSWORD} )
  --frmLogin_edtSenha.MaxLength(10)
	frmLogin_btnLogin = create( wxButton, {frmLogin, ID_FRMLOGIN_BTNLOGIN, 
    "&Login", 24, 107, 75, 25 })
	frmLogin_btnCancelar = create( wxButton, {frmLogin, 
    ID_FRMLOGIN_BTNCANCELAR, "&Cancelar", 112, 107, 75, 25})
	set_default_item(frmLogin, frmLogin_btnLogin)
  frmLogin_bFechar = FALSE
end procedure

procedure frmLogin_FazLayout(atom parent)
atom sizer_1, sizer_2, sizer_3, sizer_4

	sizer_1 = create( wxBoxSizer,{wxVERTICAL} )
	sizer_4 = create( wxBoxSizer,{wxHORIZONTAL} )
	sizer_2 = create( wxBoxSizer,{wxHORIZONTAL} )
	sizer_3 = create( wxBoxSizer,{wxVERTICAL} )
  add_window_to_sizer( sizer_2, frmLogin_bmpLogin, 0, wxALL, 6)
  add_window_to_sizer( sizer_3, frmLogin_labLogin, 0, 
    wxALL + wxALIGN_BOTTOM, 2)
  add_window_to_sizer( sizer_3, frmLogin_edtLogin, 0, wxALL, 2)
  add_window_to_sizer( sizer_3, frmLogin_labSenha, 0, 
    wxALL + wxALIGN_BOTTOM, 2)
  add_window_to_sizer( sizer_3, frmLogin_edtSenha, 0, wxALL, 2)
  add_sizer_to_sizer( sizer_2, sizer_3, 0, wxALL, 6)
  add_sizer_to_sizer( sizer_1, sizer_2, 0, 0, 3)
  add_window_to_sizer( sizer_4, frmLogin_btnLogin, 0, 
    wxLEFT + wxTOP + wxBOTTOM + wxALIGN_BOTTOM, 10)
  add_window_to_sizer( sizer_4, frmLogin_btnCancelar, 0, 
    wxALL + wxALIGN_BOTTOM, 10)
  add_sizer_to_sizer( sizer_1, sizer_4, 0, 
    wxALL + wxALIGN_CENTER_HORIZONTAL, 1)
	set_sizer(parent, sizer_1)
--	sizer_1.Fit(parent)
--	sizer_1.SetSizeHints(parent)
--	parent.Layout()
--	parent.Centre()
end procedure

frmLogin_IniciaControles()
frmLogin_FazLayout(frmLogin)

procedure onpaint( atom this, atom id, atom event_type, atom event )
	atom dc

	dc = create( wxPaintDC, {this})
	draw_bitmap( dc, bmp_login,  0, 0, 1 )
	delete_instance(dc)
end procedure
set_event_handler( frmLogin_bmpLogin, get_id(frmLogin_bmpLogin), wxEVT_PAINT, 
  routine_id("onpaint"))

procedure frmLogin_OnClose( atom this, atom id, atom event_type, atom event )
  if frmLogin_bFechar then
    --frmLogin.Destroy()
  else
    --frmLogin.Destroy()
    --frmPrincipal.Destroy()
    exit_main()
  end if
end procedure
set_event_handler( frmLogin, get_id(frmLogin), wxEVT_CLOSE_WINDOW, 
  routine_id("frmLogin_OnClose"))

procedure frmLogin_OnBtnLoginClick( atom this, atom id, atom event_type, atom event )
--  Rotinas_sUsuarioLogin = frmLogin_edtLogin.GetValue()
--  Rotinas_sUsuarioSenha = frmLogin_edtSenha.GetValue()

  --if Rotinas_ConsultaDados(Consulta, ConsSQL_Usuario("S",
  --   Rotinas_sUsuarioLogin, Rotinas_sUsuarioSenha)) then
  --  Rotinas_sBarraLogin = STR_USUARIO + Rotinas_sUsuarioLogin
    --frmPrincipal.SetStatusText(Rotinas_sBarraLogin, 1)
    --set_status_text ( frmPrincipal_barraStatus, "Henrique", 1 )
  
    frmLogin_bFechar = TRUE
  --  frmLogin.Close(True)
	--	frmPrincipal.Show(True)
  --else
  --  wxMessageBox(STR_LOGSENINC, "Erro", wxOK + wxICON_ERROR )
  --end if
end procedure
set_event_handler( frmLogin, ID_FRMLOGIN_BTNLOGIN, wxEVT_COMMAND_BUTTON_CLICKED, 
  routine_id("frmLogin_OnBtnLoginClick"))

procedure frmLogin_OnBtnCancelarClick( atom this, atom id, atom event_type, atom event )
  frmLogin_bFechar = FALSE
  --frmLogin.Close(True)
end procedure
set_event_handler( frmLogin, ID_FRMLOGIN_BTNCANCELAR, wxEVT_COMMAND_BUTTON_CLICKED, 
  routine_id("frmLogin_OnBtnCancelarClick"))
