ID_FRMLOGIN_BMPLOGIN = 200
ID_FRMLOGIN_LABLOGIN = 201
ID_FRMLOGIN_EDTLOGIN = 202
ID_FRMLOGIN_LABSENHA = 203
ID_FRMLOGIN_EDTSENHA = 204
ID_FRMLOGIN_BTNLOGIN = 205
ID_FRMLOGIN_BTNCANCELAR = 206
ID_FRMLOGIN = 207

frmLogin_bmpLogin = nil
frmLogin_labLogin = nil
frmLogin_edtLogin = nil
frmLogin_labSenha = nil
frmLogin_edtSenha = nil
frmLogin_btnLogin = nil
frmLogin_btnCancelar = nil
frmLogin_bFechar = nil

function frmLogin_Criar()
  local fLogin = wx.wxDialog(wx.wxNull, ID_FRMLOGIN, "Login do Sistema", 
    wx.wxPoint(546, 346), wx.wxSize(211, 168), wx.wxDEFAULT_DIALOG_STYLE, "") 

  bmp_login = wx.wxBitmapFromXPMData(login_xpm)
  frmLogin_bmpLogin = wx.wxStaticBitmap(fLogin, ID_FRMLOGIN_BMPLOGIN, bmp_login,   
    wx.wxPoint(8, 8), wx.wxSize(90, 90))
  frmLogin_labLogin = wx.wxStaticText(fLogin, ID_FRMLOGIN_LABLOGIN,
    "Login:", wx.wxPoint(112, 8), wx.wxSize(29, 13) )
  frmLogin_edtLogin = wx.wxTextCtrl(fLogin, ID_FRMLOGIN_EDTLOGIN, "", 
    wx.wxPoint(112, 24), wx.wxSize(80, 21) )
  --frmLogin_edtLogin:SetMaxLength(10)
  frmLogin_labSenha = wx.wxStaticText(fLogin, ID_FRMLOGIN_LABSENHA,
    "Senha:", wx.wxPoint(112, 56), wx.wxSize(34, 13) )
  frmLogin_edtSenha = wx.wxTextCtrl(fLogin, ID_FRMLOGIN_EDTSENHA, "", 
    wx.wxPoint(112, 72), wx.wxSize(80, 21), wx.wxTE_PASSWORD )
  --frmLogin_edtSenha:SetMaxLength(10)
  frmLogin_btnLogin = wx.wxButton(fLogin, ID_FRMLOGIN_BTNLOGIN, "&Login",
    wx.wxPoint(24, 107), wx.wxSize(75, 25))
  frmLogin_btnCancelar = wx.wxButton(fLogin, ID_FRMLOGIN_BTNCANCELAR, "&Cancelar",
    wx.wxPoint(112, 107), wx.wxSize(75, 25))
  frmLogin_btnLogin:SetDefault()

  frmLogin_bFechar = false
  frmLogin_FazLayout(fLogin)
  
  fLogin:ConnectEvent(ID_FRMLOGIN,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      if frmLogin_bFechar then
        fLogin:Destroy()
      else
        fLogin:Destroy()
        frmPrincipal:Destroy()
        os.exit(0)
      end
      event:Skip()
    end )  

  fLogin:ConnectEvent(ID_FRMLOGIN_BTNLOGIN,wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      Rotinas_sUsuarioLogin = frmLogin_edtLogin:GetValue()
      Rotinas_sUsuarioSenha = frmLogin_edtSenha:GetValue()
    
      --if Rotinas_ConsultaDados(Consulta, ConsSQL_Usuario("S",
      --   Rotinas_sUsuarioLogin, Rotinas_sUsuarioSenha)) then
        Rotinas_sBarraLogin = STR_USUARIO .. Rotinas_sUsuarioLogin
        frmPrincipal:SetStatusText(Rotinas_sBarraLogin, 1)
      
        frmLogin_bFechar = true
        fLogin:Close(wx.TRUE)        
        frmPrincipal:Show(wx.TRUE)
      --else
      --  wxMessageBox(STR_LOGSENINC, "Erro", wxOK + wxICON_ERROR )
      --end
      event:Skip()
    end )  

  fLogin:ConnectEvent(ID_FRMLOGIN_BTNCANCELAR,wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmLogin_bFechar = false
      fLogin:Close(wx.TRUE)
      event:Skip()
    end )  

  return fLogin
end

function frmLogin_FazLayout(parent)
	sizer_1 = wx.wxBoxSizer(wx.wxVERTICAL)
	sizer_4 = wx.wxBoxSizer(wx.wxHORIZONTAL)
	sizer_2 = wx.wxBoxSizer(wx.wxHORIZONTAL)
	sizer_3 = wx.wxBoxSizer(wx.wxVERTICAL)
	sizer_2:AddWindow(frmLogin_bmpLogin, 0, wx.wxALL, 6)
	sizer_3:AddWindow(frmLogin_labLogin, 0, wx.wxALL + wx.wxALIGN_BOTTOM, 2)
	sizer_3:AddWindow(frmLogin_edtLogin, 0, wx.wxALL, 2)
	sizer_3:AddWindow(frmLogin_labSenha, 0, wx.wxALL + wx.wxALIGN_BOTTOM, 2)
	sizer_3:AddWindow(frmLogin_edtSenha, 0, wx.wxALL, 2)
	sizer_2:AddSizer(sizer_3, 0, wx.wxALL, 6)
	sizer_1:AddSizer(sizer_2, 0, 0, 3)
	sizer_4:AddWindow(frmLogin_btnLogin, 0, wx.wxLEFT + wx.wxTOP + wx.wxBOTTOM + wx.wxALIGN_BOTTOM, 10)
	sizer_4:AddWindow(frmLogin_btnCancelar, 0, wx.wxALL + wx.wxALIGN_BOTTOM, 10)
	sizer_1:AddSizer(sizer_4, 0, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL, 1)
	parent:SetSizer(sizer_1)
	sizer_1:Fit(parent)
	sizer_1:SetSizeHints(parent)
	parent:Layout()
	parent:Centre()
end

frmLogin = frmLogin_Criar()
