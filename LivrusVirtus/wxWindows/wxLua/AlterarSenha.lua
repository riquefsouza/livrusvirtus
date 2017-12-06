ID_FRMALTERARSENHA_BTNFECHAR = 600
ID_FRMALTERARSENHA_BTNLIMPAR = 601
ID_FRMALTERARSENHA_BTNSALVAR = 602
ID_FRMALTERARSENHA_EDTCONFIRMARSENHA = 603
ID_FRMALTERARSENHA_EDTLOGIN = 604
ID_FRMALTERARSENHA_EDTNOVASENHA = 605
ID_FRMALTERARSENHA_EDTSENHAATUAL = 606
ID_FRMALTERARSENHA_LABCONFIRMARSENHA = 607
ID_FRMALTERARSENHA_LABLOGIN = 608
ID_FRMALTERARSENHA_LABNOVASENHA = 609
ID_FRMALTERARSENHA_LABSENHAATUAL = 610
ID_FRMALTERARSENHA = 611

local frmAlterarSenha
local frmAlterarSenha_labLogin
local frmAlterarSenha_edtLogin
local frmAlterarSenha_labSenhaAtual
local frmAlterarSenha_edtSenhaAtual
local frmAlterarSenha_labNovaSenha
local frmAlterarSenha_edtNovaSenha
local frmAlterarSenha_labConfirmarSenha
local frmAlterarSenha_edtConfirmarSenha
local frmAlterarSenha_btnSalvar
local frmAlterarSenha_btnLimpar
local frmAlterarSenha_btnFechar

local frmAlterarSenha

function frmAlterarSenha_Criar(parent)
  local fAlterarSenha = wx.wxPanel(parent, ID_FRMALTERARSENHA, wx.wxPoint(424, 292), 
    wx.wxSize(257, 161), wx.wxTAB_TRAVERSAL,"")

  fAlterarSenha:SetClientSize(wx.wxSize(249, 134))

	frmAlterarSenha_labLogin = wx.wxStaticText(fAlterarSenha, ID_FRMALTERARSENHA_LABLOGIN,
    "Login: ", wx.wxPoint(8, 8), wx.wxSize(29, 13) )
	frmAlterarSenha_edtLogin = wx.wxTextCtrl(fAlterarSenha, ID_FRMALTERARSENHA_EDTLOGIN, "", 
    wx.wxPoint(8, 24), wx.wxSize(100, 21) )
	frmAlterarSenha_edtLogin:Enable(false)
	frmAlterarSenha_labSenhaAtual = wx.wxStaticText(fAlterarSenha, ID_FRMALTERARSENHA_LABSENHAATUAL,
    "Senha atual:", wx.wxPoint(112, 8), wx.wxSize(60, 13) )
	frmAlterarSenha_edtSenhaAtual = wx.wxTextCtrl(fAlterarSenha, ID_FRMALTERARSENHA_EDTSENHAATUAL,
    "", wx.wxPoint(112, 24), wx.wxSize(100, 21), wxTE_PASSWORD )
	frmAlterarSenha_labNovaSenha = wx.wxStaticText(fAlterarSenha, ID_FRMALTERARSENHA_LABNOVASENHA,
    "Nova Senha:", wx.wxPoint(8, 48), wx.wxSize(61, 13) )
	frmAlterarSenha_edtNovaSenha = wx.wxTextCtrl(fAlterarSenha, ID_FRMALTERARSENHA_EDTNOVASENHA,
    "", wx.wxPoint(8, 64), wx.wxSize(100, 21), wxTE_PASSWORD )
	frmAlterarSenha_labConfirmarSenha = wx.wxStaticText(fAlterarSenha,
    ID_FRMALTERARSENHA_LABCONFIRMARSENHA, "Confirmar senha:",
    wx.wxPoint(112, 48), wx.wxSize(79, 13) )
	frmAlterarSenha_edtConfirmarSenha = wx.wxTextCtrl(fAlterarSenha,
    ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, "",
    wx.wxPoint(112, 64), wx.wxSize(100, 21), wxTE_PASSWORD )
	frmAlterarSenha_btnSalvar = wx.wxButton(fAlterarSenha, ID_FRMALTERARSENHA_BTNSALVAR,
    "&Salvar", wx.wxPoint(8, 104), wx.wxSize(75, 25))
	frmAlterarSenha_btnLimpar = wx.wxButton(fAlterarSenha, ID_FRMALTERARSENHA_BTNLIMPAR,
    "&Limpar", wx.wxPoint(88, 104), wx.wxSize(75, 25))
	frmAlterarSenha_btnFechar = wx.wxButton(fAlterarSenha, ID_FRMALTERARSENHA_BTNFECHAR,
    "&Fechar", wx.wxPoint(168, 104), wx.wxSize(75, 25)) 

  frmAlterarSenha_edtLogin:SetValue(Rotinas_sUsuarioLogin)
  --frmAlterarSenha_edtSenhaAtual:MaxLength = 10
  --frmAlterarSenha_edtNovaSenha:MaxLength = 10
  --frmAlterarSenha_edtConfirmarSenha:MaxLength = 10

  frmAlterarSenha_FazLayout(fAlterarSenha)
  frmAlterarSenha_edtSenhaAtual:SetFocus()

  fAlterarSenha:ConnectEvent(ID_FRMALTERARSENHA,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fAlterarSenha:GetParent():Close(true)
      event:Skip()
    end )

  fAlterarSenha:ConnectEvent(ID_FRMALTERARSENHA_BTNSALVAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      local Arquiva
      if frmAlterarSenha_ValidaDados() then
        --if Rotinas_AtualizaDados(Arquiva,
        --  ConsSQL_Usuario("U", frmAlterarSenha_edtLogin:GetValue(),
        --  frmAlterarSenha_edtConfirmarSenha:GetValue())) then
        --  wx.wxMessageBox(STR_SENALTSUC, "Erro", wx.wxOK + wx.wxICON_ERROR )
        --end
      end
      event:Skip()
    end )

  fAlterarSenha:ConnectEvent(ID_FRMALTERARSENHA_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmAlterarSenha_edtSenhaAtual:Clear()
      frmAlterarSenha_edtNovaSenha:Clear()
      frmAlterarSenha_edtConfirmarSenha:Clear()
      frmAlterarSenha_edtSenhaAtual:SetFocus()
      event:Skip()
    end )

  fAlterarSenha:ConnectEvent(ID_FRMALTERARSENHA_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fAlterarSenha:Close(true)
      event:Skip()
    end )

  return fAlterarSenha
end

function frmAlterarSenha_FazLayout(parent)
  sizer_1 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_2 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_9 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_10 = wx.wxGridSizer(4, 1, 0, 0)
  grid_sizer_3 = wx.wxGridSizer(4, 1, 0, 0)
  grid_sizer_3:AddWindow(frmAlterarSenha_labLogin, 0, wx.wxLEFT + wx.wxALIGN_BOTTOM, 8)
  grid_sizer_3:AddWindow(frmAlterarSenha_edtLogin, 0, wx.wxLEFT, 8)
  grid_sizer_3:AddWindow(frmAlterarSenha_labNovaSenha, 0, wx.wxLEFT + wx.wxALIGN_BOTTOM, 8)
  grid_sizer_3:AddWindow(frmAlterarSenha_edtNovaSenha, 0, wx.wxLEFT, 8)
  sizer_9:AddSizer(grid_sizer_3, 0, 0, 0)
  grid_sizer_10:AddWindow(frmAlterarSenha_labSenhaAtual, 0, wx.wxLEFT + wx.wxALIGN_BOTTOM, 4)
  grid_sizer_10:AddWindow(frmAlterarSenha_edtSenhaAtual, 0, wx.wxLEFT, 4)
  grid_sizer_10:AddWindow(frmAlterarSenha_labConfirmarSenha, 0, wx.wxLEFT + wx.wxALIGN_BOTTOM, 4)
  grid_sizer_10:AddWindow(frmAlterarSenha_edtConfirmarSenha, 0, wx.wxLEFT, 4)
  sizer_9:AddSizer(grid_sizer_10, 0, 0, 0)
  sizer_1:AddSizer(sizer_9, 1, 0, 0)
  sizer_2:AddWindow(frmAlterarSenha_btnSalvar, 0, wx.wxALL, 2)
  sizer_2:AddWindow(frmAlterarSenha_btnLimpar, 0, wx.wxALL, 2)
  sizer_2:AddWindow(frmAlterarSenha_btnFechar, 0, wx.wxALL, 2)
  sizer_1:AddSizer(sizer_2, 0, wx.wxALL, 4)
  parent:SetAutoLayout(true)
  parent:SetSizer(sizer_1)
  sizer_1:Fit(parent)
  sizer_1:SetSizeHints(parent)
end

function frmAlterarSenha_ValidaDados()
  if frmAlterarSenha_edtSenhaAtual:GetValue() ~= Rotinas_sUsuarioSenha then
    wx.wxMessageBox(STR_SENNCSU, "Erro", wx.wxOK + wx.wxICON_ERROR )
    return false
  end
  if Rotinas_ValidaCampo(frmAlterarSenha_edtNovaSenha:GetValue(), 
    STR_NSENNINF) then
    return false
  end
  if frmAlterarSenha_edtNovaSenha:GetValue() ~= 
    frmAlterarSenha_edtConfirmarSenha:GetValue() then
    wx.wxMessageBox(STR_NSENNCCON, "Erro", wx.wxOK + wx.wxICON_ERROR )
    return false
  end
	return true
end
