option explicit

Const ID_FRMCADENDERECOS_CMBESTADO = 700
Const ID_FRMCADENDERECOS_EDTBAIRRO = 701
Const ID_FRMCADENDERECOS_EDTCEP = 702
Const ID_FRMCADENDERECOS_EDTCIDADE = 703
Const ID_FRMCADENDERECOS_LABBAIRRO = 704
Const ID_FRMCADENDERECOS_LABCEP = 705
Const ID_FRMCADENDERECOS_LABCIDADE = 706
Const ID_FRMCADENDERECOS_LABESTADO = 707

dim common frmCadEnderecos
dim common frmCadEnderecos_labBairro
dim common frmCadEnderecos_edtBairro
dim common frmCadEnderecos_edtCEP
dim common frmCadEnderecos_labCEP
dim common frmCadEnderecos_edtCidade
dim common frmCadEnderecos_labCidade
dim common frmCadEnderecos_labEstado
dim common frmCadEnderecos_cmbEstado

function frmCadEnderecos_Criar(parent)
  dim fCadEnderecos = frmCadastros_Criar(parent, 0, False)

  frmCadastros_labDescricao.SetLabel("Logradouro: ")
  frmCadastros_labDescricao.SetSize(57, 13)
  frmCadastros_edtDescricao.SetSize(264, 21)

	frmCadEnderecos_labBairro = new wxStaticText(fCadEnderecos, ID_FRMCADENDERECOS_LABBAIRRO,
    "Bairro:", wxPoint(280, 48), wxSize(48, 13) )
	frmCadEnderecos_edtBairro = new wxTextCtrl(fCadEnderecos, ID_FRMCADENDERECOS_EDTBAIRRO,
    "", wxPoint(280, 64), wxSize(144, 21) )
  frmCadEnderecos_edtBairro.Enable(False)
	frmCadEnderecos_labCEP = new wxStaticText(fCadEnderecos, ID_FRMCADENDERECOS_LABCEP,
    "CEP: ", wxPoint(8, 88), wxSize(40, 13) )
	frmCadEnderecos_edtCEP = new wxTextCtrl(fCadEnderecos, ID_FRMCADENDERECOS_EDTCEP,
    "", wxPoint(8, 104), wxSize(72, 21) )
  frmCadEnderecos_edtCEP.Enable(False)
	frmCadEnderecos_labCidade = new wxStaticText(fCadEnderecos, ID_FRMCADENDERECOS_LABCIDADE,
    "Cidade: ", wxPoint(88, 88), wxSize(39, 13) )
	frmCadEnderecos_edtCidade = new wxTextCtrl(fCadEnderecos, ID_FRMCADENDERECOS_EDTCIDADE,
    "", wxPoint(88, 104), wxSize(184, 21) )
  frmCadEnderecos_edtCidade.Enable(False)
	frmCadEnderecos_labEstado = new wxStaticText(fCadEnderecos, ID_FRMCADENDERECOS_LABESTADO, 
    "Estado: ", wxPoint(280, 88), wxSize(56, 13) )
	frmCadEnderecos_cmbEstado = new wxChoice(fCadEnderecos, ID_FRMCADENDERECOS_CMBESTADO,
    wxPoint(280, 104), wxSize(144, 21) )
  frmCadEnderecos_cmbEstado.Enable(False)
  frmCadEnderecos_AdicionaCombo()
  frmCadastros_IniciaBotoes(fCadEnderecos)

  frmCadastros_btnPesquisar.SetDimensions(440, 8, 75, 25)
  frmCadastros_btnAnterior.SetDimensions(440, 40, 75, 25)
  frmCadastros_btnProximo.SetDimensions(440, 72, 75, 25)
  frmCadastros_btnSalvar.SetDimensions(200, 136, 75, 25)
  frmCadastros_btnExcluir.SetDimensions(280, 136, 75, 25)
  frmCadastros_btnLimpar.SetDimensions(360, 136, 75, 25)
  frmCadastros_btnFechar.SetDimensions(440, 136, 75, 25)

  frmCadEnderecos_FazLayout(fCadEnderecos)

  'frmCadastros_edtDescricao.SetMaxLength(40)
  'frmCadEnderecos_edtBairro.SetMaxLength(15)
  'frmCadEnderecos_edtCEP.SetMaxLength(8)
  'frmCadEnderecos_edtCidade.SetMaxLength(30)

  Connect( fCadEnderecos, wxEVT_CLOSE_WINDOW, "frmCadEnderecos_OnClose" )
  Connect( fCadEnderecos, ID_FRMCADASTROS_BTNNOVO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEnderecos_OnBtnNovo" )
  Connect( fCadEnderecos, ID_FRMCADASTROS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEnderecos_OnBtnPesquisar" )
  Connect( fCadEnderecos, ID_FRMCADASTROS_BTNANTERIOR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEnderecos_OnBtnAnterior" )
  Connect( fCadEnderecos, ID_FRMCADASTROS_BTNPROXIMO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEnderecos_OnBtnProximo" )
  Connect( fCadEnderecos, ID_FRMCADASTROS_BTNSALVAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEnderecos_OnBtnSalvar" )
  Connect( fCadEnderecos, ID_FRMCADASTROS_BTNEXCLUIR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEnderecos_OnBtnExcluir" )
  Connect( fCadEnderecos, ID_FRMCADASTROS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEnderecos_OnBtnFechar" )
  Connect( fCadEnderecos, ID_FRMCADASTROS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEnderecos_OnBtnLimpar" )

  return fCadEnderecos
end function

sub frmCadEnderecos_FazLayout(parent)
  dim sizer_1 = new wxBoxSizer(wxVERTICAL)
  dim sizer_2 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_3 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_4 = new wxBoxSizer(wxVERTICAL)
  dim sizer_5 = new wxBoxSizer(wxVERTICAL)
  dim sizer_6 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_6 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_5 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_4 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_8 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_9 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_8 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_7 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_7 = new wxGridSizer(2, 1, 0, 0)
  grid_sizer_7.Add(frmCadastros_labCodigo, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_7.Add(frmCadastros_edtCodigo, 0, 0, 0)
  sizer_7.Add(grid_sizer_7, 0, 0, 0)
  sizer_7.Add(frmCadastros_btnNovo, 0, wxLEFT + wxALIGN_BOTTOM, 5)
  sizer_5.Add(sizer_7, 1, 0, 0)
  grid_sizer_8.Add(frmCadastros_labDescricao, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_8.Add(frmCadastros_edtDescricao, 0, 0, 0)
  sizer_8.Add(grid_sizer_8, 0, 0, 0)
  grid_sizer_9.Add(frmCadEnderecos_labBairro, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_9.Add(frmCadEnderecos_edtBairro, 0, 0, 0)
  sizer_8.Add(grid_sizer_9, 0, wxLEFT, 2)
  sizer_5.Add(sizer_8, 1, wxEXPAND, 0)
  grid_sizer_4.Add(frmCadEnderecos_labCEP, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_4.Add(frmCadEnderecos_edtCEP, 0, 0, 0)
  sizer_6.Add(grid_sizer_4, 0, 0, 0)
  grid_sizer_5.Add(frmCadEnderecos_labCidade, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_5.Add(frmCadEnderecos_edtCidade, 0, 0, 0)
  sizer_6.Add(grid_sizer_5, 0, wxLEFT, 4)
  grid_sizer_6.Add(frmCadEnderecos_labEstado, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_6.Add(frmCadEnderecos_cmbEstado, 0, 0, 0)
  sizer_6.Add(grid_sizer_6, 0, wxLEFT, 5)
  sizer_5.Add(sizer_6, 0, 0, 0)
  sizer_3.Add(sizer_5, 0, 0, 0)
  sizer_4.Add(frmCadastros_btnPesquisar, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_4.Add(frmCadastros_btnAnterior, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_4.Add(frmCadastros_btnProximo, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_3.Add(sizer_4, 1, 0, 0)
  sizer_1.Add(sizer_3, 1, wxALL + wxEXPAND, 4)
  sizer_2.Add(frmCadastros_btnSalvar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_2.Add(frmCadastros_btnExcluir, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_2.Add(frmCadastros_btnLimpar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_2.Add(frmCadastros_btnFechar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_1.Add(sizer_2, 0, wxRIGHT + wxBOTTOM + wxALIGN_RIGHT + 
    wxALIGN_BOTTOM, 4)
  parent.SetAutoLayout(True)
  parent.SetSizer(sizer_1)
  sizer_1.Fit(parent)
  sizer_1.SetSizeHints(parent)
end sub

function frmCadEnderecos_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo.GetValue(),
    STR_CODNINF) then
    return False
  end if
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao.GetValue(),
      STR_ENDNINF) then
    	return False
    end if
    if Rotinas_ValidaCampo(frmCadEnderecos_edtBairro.GetValue(),
      STR_BAIRRONINF) then
    	return False
    end if
    if Rotinas_ValidaCampo(frmCadEnderecos_edtCEP.GetValue(),
      STR_CEPNINF) then
    	return False
    end if
    if Rotinas_ValidaCampo(frmCadEnderecos_edtCidade.GetValue(),
      STR_CIDADENINF) then
    	return False
    end if
  end if
	return True
end function

Function frmCadEnderecos_OnClose( event )
  frmCadEnderecos.GetParent().Close(True)
	event.Skip()
End Function

function frmCadEnderecos_OnBtnNovo( event )
  frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadEnderecos_InformaLimpaDados(False)
  frmCadEnderecos_HabilitaDados(True)
  frmCadastros_NovoDado(ConsSQL_Endereco("N", 
    frmCadastros_edtCodigo.GetValue(),"","","","",""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadEnderecos_OnBtnPesquisar( event )
  if frmCadastros_PesquisarDados(ConsSQL_Endereco("S", 
    frmCadastros_edtCodigo.GetValue(),"","","","",""), STR_ENDNENC,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir) then
    frmCadEnderecos_InformaLimpaDados(True)
    frmCadEnderecos_HabilitaDados(True)
  end if
  event.Skip()
end function

function frmCadEnderecos_OnBtnAnterior( event )
  if frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao) then
    frmCadEnderecos_InformaLimpaDados(True)
  end if	
  event.Skip()
end function

function frmCadEnderecos_OnBtnProximo( event )
  if frmCadastros_registroProximo(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao) then
    frmCadEnderecos_InformaLimpaDados(True)
  end if	
  event.Skip()
end function

function frmCadEnderecos_OnBtnSalvar( event )
  if frmCadastros_SalvarDados(frmCadEnderecos_ValidaDados(True),
    ConsSQL_Endereco("S", frmCadastros_edtCodigo.GetValue(),"","","","",""),
    ConsSQL_Endereco("U", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.Value(),"","","",""),
    ConsSQL_Endereco("I", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue(),"","","",""), True,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir) then
    frmCadEnderecos_InformaLimpaDados(False)
    frmCadEnderecos_HabilitaDados(False)
  end if
  event.Skip()
end function

function frmCadEnderecos_OnBtnExcluir( event )
  if frmCadastros_ExcluirDados(frmCadEnderecos_ValidaDados(False),
    ConsSQL_Endereco("D", frmCadastros_edtCodigo.GetValue(),"","","","",""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir) then
    frmCadEnderecos_InformaLimpaDados(False)
    frmCadEnderecos_HabilitaDados(False)
  end if
  event.Skip()
end function

function frmCadEnderecos_OnBtnFechar( event )
  frmCadEnderecos.Close(True)
  event.Skip()
end function

function frmCadEnderecos_OnBtnLimpar( event )
  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadEnderecos_InformaLimpaDados(False)
  frmCadEnderecos_HabilitaDados(False)
  event.Skip()
end function

sub frmCadEnderecos_InformaLimpaDados(bInformar)

  if bInformar then
    frmCadEnderecos_edtBairro.SetValue("2")
    frmCadEnderecos_edtCEP.SetValue("3")
    frmCadEnderecos_edtCidade.SetValue("4")
    frmCadEnderecos_cmbEstado.SetStringSelection("Pernambuco")
  else
    frmCadEnderecos_edtBairro.Clear()
    frmCadEnderecos_edtCEP.Clear()
    frmCadEnderecos_edtCidade.Clear()
    frmCadEnderecos_cmbEstado.SetSelection(0)
  end if
end sub

sub frmCadEnderecos_HabilitaDados(bHabilita)
  frmCadEnderecos_edtBairro.Enable(bHabilita)
  frmCadEnderecos_edtCEP.Enable(bHabilita)  
  frmCadEnderecos_edtCidade.Enable(bHabilita)
  frmCadEnderecos_cmbEstado.Enable(bHabilita)  
end sub

sub frmCadEnderecos_AdicionaCombo()
  frmCadEnderecos_cmbEstado.Append(STR_PE)
  frmCadEnderecos_cmbEstado.Append(STR_AC)
  frmCadEnderecos_cmbEstado.Append(STR_AL)
  frmCadEnderecos_cmbEstado.Append(STR_AP)
  frmCadEnderecos_cmbEstado.Append(STR_AM)
  frmCadEnderecos_cmbEstado.Append(STR_BA)
  frmCadEnderecos_cmbEstado.Append(STR_BR)
  frmCadEnderecos_cmbEstado.Append(STR_CE)
  frmCadEnderecos_cmbEstado.Append(STR_DF)
  frmCadEnderecos_cmbEstado.Append(STR_ES)
  frmCadEnderecos_cmbEstado.Append(STR_GO)
  frmCadEnderecos_cmbEstado.Append(STR_MT)
  frmCadEnderecos_cmbEstado.Append(STR_MS)
  frmCadEnderecos_cmbEstado.Append(STR_MG)
  frmCadEnderecos_cmbEstado.Append(STR_PA)
  frmCadEnderecos_cmbEstado.Append(STR_PB)
  frmCadEnderecos_cmbEstado.Append(STR_PR)
  frmCadEnderecos_cmbEstado.Append(STR_SC)
  frmCadEnderecos_cmbEstado.Append(STR_RN)
  frmCadEnderecos_cmbEstado.Append(STR_RS)
  frmCadEnderecos_cmbEstado.Append(STR_RJ)
  frmCadEnderecos_cmbEstado.Append(STR_RO)
  frmCadEnderecos_cmbEstado.Append(STR_RR)
  frmCadEnderecos_cmbEstado.Append(STR_SP)
  frmCadEnderecos_cmbEstado.Append(STR_SE)
  frmCadEnderecos_cmbEstado.Append(STR_TO)
end sub
