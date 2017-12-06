option explicit

Const ID_FRMALTERARSENHA_BTNFECHAR = 600
Const ID_FRMALTERARSENHA_BTNLIMPAR = 601
Const ID_FRMALTERARSENHA_BTNSALVAR = 602
Const ID_FRMALTERARSENHA_EDTCONFIRMARSENHA = 603
Const ID_FRMALTERARSENHA_EDTLOGIN = 604
Const ID_FRMALTERARSENHA_EDTNOVASENHA = 605
Const ID_FRMALTERARSENHA_EDTSENHAATUAL = 606
Const ID_FRMALTERARSENHA_LABCONFIRMARSENHA = 607
Const ID_FRMALTERARSENHA_LABLOGIN = 608
Const ID_FRMALTERARSENHA_LABNOVASENHA = 609
Const ID_FRMALTERARSENHA_LABSENHAATUAL = 610

dim common frmAlterarSenha
dim common frmAlterarSenha_labLogin
dim common frmAlterarSenha_edtLogin
dim common frmAlterarSenha_labSenhaAtual
dim common frmAlterarSenha_edtSenhaAtual
dim common frmAlterarSenha_labNovaSenha
dim common frmAlterarSenha_edtNovaSenha
dim common frmAlterarSenha_labConfirmarSenha
dim common frmAlterarSenha_edtConfirmarSenha
dim common frmAlterarSenha_btnSalvar
dim common frmAlterarSenha_btnLimpar
dim common frmAlterarSenha_btnFechar

function frmAlterarSenha_Criar(parent)
  dim fAlterarSenha = new wxPanel(parent, -1, wxPoint(424, 292), 
    wxSize(257, 161), wxTAB_TRAVERSAL,"")

  fAlterarSenha.SetClientSize(wxSize(249, 134))

	frmAlterarSenha_labLogin = new wxStaticText(fAlterarSenha, ID_FRMALTERARSENHA_LABLOGIN,
    "Login: ", wxPoint(8, 8), wxSize(29, 13) )
	frmAlterarSenha_edtLogin = new wxTextCtrl(fAlterarSenha, ID_FRMALTERARSENHA_EDTLOGIN, "", 
    wxPoint(8, 24), wxSize(100, 21) )
	frmAlterarSenha_edtLogin.Enable(False)
	frmAlterarSenha_labSenhaAtual = new wxStaticText(fAlterarSenha, ID_FRMALTERARSENHA_LABSENHAATUAL,
    "Senha atual:", wxPoint(112, 8), wxSize(60, 13) )
	frmAlterarSenha_edtSenhaAtual = new wxTextCtrl(fAlterarSenha, ID_FRMALTERARSENHA_EDTSENHAATUAL,
    "", wxPoint(112, 24), wxSize(100, 21), wxTE_PASSWORD )
	frmAlterarSenha_labNovaSenha = new wxStaticText(fAlterarSenha, ID_FRMALTERARSENHA_LABNOVASENHA,
    "Nova Senha:", wxPoint(8, 48), wxSize(61, 13) )
	frmAlterarSenha_edtNovaSenha = new wxTextCtrl(fAlterarSenha, ID_FRMALTERARSENHA_EDTNOVASENHA,
    "", wxPoint(8, 64), wxSize(100, 21), wxTE_PASSWORD )
	frmAlterarSenha_labConfirmarSenha = new wxStaticText(fAlterarSenha,
    ID_FRMALTERARSENHA_LABCONFIRMARSENHA, "Confirmar senha:",
    wxPoint(112, 48), wxSize(79, 13) )
	frmAlterarSenha_edtConfirmarSenha = new wxTextCtrl(fAlterarSenha,
    ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, "",
    wxPoint(112, 64), wxSize(100, 21), wxTE_PASSWORD )
	frmAlterarSenha_btnSalvar = new wxButton(fAlterarSenha, ID_FRMALTERARSENHA_BTNSALVAR,
    "&Salvar", wxPoint(8, 104), wxSize(75, 25))
	frmAlterarSenha_btnLimpar = new wxButton(fAlterarSenha, ID_FRMALTERARSENHA_BTNLIMPAR,
    "&Limpar", wxPoint(88, 104), wxSize(75, 25))
	frmAlterarSenha_btnFechar = new wxButton(fAlterarSenha, ID_FRMALTERARSENHA_BTNFECHAR,
    "&Fechar", wxPoint(168, 104), wxSize(75, 25)) 

  frmAlterarSenha_edtLogin.SetValue(Rotinas_sUsuarioLogin)
  'frmAlterarSenha_edtSenhaAtual.MaxLength = 10
  'frmAlterarSenha_edtNovaSenha.MaxLength = 10
  'frmAlterarSenha_edtConfirmarSenha.MaxLength = 10

  Connect( fAlterarSenha, wxEVT_CLOSE_WINDOW, "frmAlterarSenha_OnClose" )
  Connect( fAlterarSenha, ID_FRMALTERARSENHA_BTNSALVAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmAlterarSenha_OnBtnSalvar" )
  Connect( fAlterarSenha, ID_FRMALTERARSENHA_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmAlterarSenha_OnBtnLimpar" )
  Connect( fAlterarSenha, ID_FRMALTERARSENHA_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmAlterarSenha_OnBtnFechar" )

  frmAlterarSenha_FazLayout(fAlterarSenha)
  frmAlterarSenha_edtSenhaAtual.SetFocus()

  return fAlterarSenha
end function

sub frmAlterarSenha_FazLayout(parent)
  dim sizer_1 = new wxBoxSizer(wxVERTICAL)
  dim sizer_2 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_9 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_10 = new wxGridSizer(4, 1, 0, 0)
  dim grid_sizer_3 = new wxGridSizer(4, 1, 0, 0)
  grid_sizer_3.Add(frmAlterarSenha_labLogin, 0, wxLEFT + wxALIGN_BOTTOM, 8)
  grid_sizer_3.Add(frmAlterarSenha_edtLogin, 0, wxLEFT, 8)
  grid_sizer_3.Add(frmAlterarSenha_labNovaSenha, 0, wxLEFT + wxALIGN_BOTTOM, 8)
  grid_sizer_3.Add(frmAlterarSenha_edtNovaSenha, 0, wxLEFT, 8)
  sizer_9.Add(grid_sizer_3, 0, 0, 0)
  grid_sizer_10.Add(frmAlterarSenha_labSenhaAtual, 0, wxLEFT + wxALIGN_BOTTOM, 4)
  grid_sizer_10.Add(frmAlterarSenha_edtSenhaAtual, 0, wxLEFT, 4)
  grid_sizer_10.Add(frmAlterarSenha_labConfirmarSenha, 0, wxLEFT + wxALIGN_BOTTOM, 4)
  grid_sizer_10.Add(frmAlterarSenha_edtConfirmarSenha, 0, wxLEFT, 4)
  sizer_9.Add(grid_sizer_10, 0, 0, 0)
  sizer_1.Add(sizer_9, 1, 0, 0)
  sizer_2.Add(frmAlterarSenha_btnSalvar, 0, wxALL, 2)
  sizer_2.Add(frmAlterarSenha_btnLimpar, 0, wxALL, 2)
  sizer_2.Add(frmAlterarSenha_btnFechar, 0, wxALL, 2)
  sizer_1.Add(sizer_2, 0, wxALL, 4)
  parent.SetAutoLayout(True)
  parent.SetSizer(sizer_1)
  sizer_1.Fit(parent)
  sizer_1.SetSizeHints(parent)
End Sub

Function frmAlterarSenha_OnClose( event )
  frmAlterarSenha.GetParent().Close(True)
	event.Skip()
End Function

function frmAlterarSenha_OnBtnSalvar( event )
  dim Arquiva
  if frmAlterarSenha_ValidaDados() then
    'if Rotinas_AtualizaDados(Arquiva,
    '  ConsSQL_Usuario("U", frmAlterarSenha_edtLogin.GetValue(),
    '  frmAlterarSenha_edtConfirmarSenha.GetValue())) then
    '  wxMessageBox(STR_SENALTSUC, "Erro", wxOK + wxICON_ERROR )
    'end if
  end if
  event.Skip()
end function

function frmAlterarSenha_OnBtnLimpar( event )
  frmAlterarSenha_edtSenhaAtual.Clear()
  frmAlterarSenha_edtNovaSenha.Clear()
  frmAlterarSenha_edtConfirmarSenha.Clear()
  frmAlterarSenha_edtSenhaAtual.SetFocus()
  event.Skip()
end function

function frmAlterarSenha_OnBtnFechar( event )
  frmAlterarSenha.Close(True)
  event.Skip()
end function

function frmAlterarSenha_ValidaDados()
  if frmAlterarSenha_edtSenhaAtual.GetValue() <> Rotinas_sUsuarioSenha then
    wxMessageBox(STR_SENNCSU, "Erro", wxOK + wxICON_ERROR )
    return False
  end if
  if Rotinas_ValidaCampo(frmAlterarSenha_edtNovaSenha.GetValue(), 
    STR_NSENNINF) then
    return False
  end if
  if frmAlterarSenha_edtNovaSenha.GetValue() <> 
    frmAlterarSenha_edtConfirmarSenha.GetValue() then
    wxMessageBox(STR_NSENNCCON, "Erro", wxOK + wxICON_ERROR )
    return False
  end if
  return True
end function
