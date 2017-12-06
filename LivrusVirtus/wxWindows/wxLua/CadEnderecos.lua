ID_FRMCADENDERECOS_CMBESTADO = 700
ID_FRMCADENDERECOS_EDTBAIRRO = 701
ID_FRMCADENDERECOS_EDTCEP = 702
ID_FRMCADENDERECOS_EDTCIDADE = 703
ID_FRMCADENDERECOS_LABBAIRRO = 704
ID_FRMCADENDERECOS_LABCEP = 705
ID_FRMCADENDERECOS_LABCIDADE = 706
ID_FRMCADENDERECOS_LABESTADO = 707
ID_FRMCADENDERECOS = 708

local frmCadEnderecos
local frmCadEnderecos_labBairro
local frmCadEnderecos_edtBairro
local frmCadEnderecos_edtCEP
local frmCadEnderecos_labCEP
local frmCadEnderecos_edtCidade
local frmCadEnderecos_labCidade
local frmCadEnderecos_labEstado
local frmCadEnderecos_cmbEstado

function frmCadEnderecos_Criar(parent)
  local fCadEnderecos = frmCadastros_Criar(parent, ID_FRMCADENDERECOS, 0, false)

  frmCadastros_labDescricao:SetLabel("Logradouro: ")
  frmCadastros_labDescricao:SetSize(57, 13)
  frmCadastros_edtDescricao:SetSize(264, 21)

	frmCadEnderecos_labBairro = wx.wxStaticText(fCadEnderecos, ID_FRMCADENDERECOS_LABBAIRRO,
    "Bairro:", wx.wxPoint(280, 48), wx.wxSize(48, 13) )
	frmCadEnderecos_edtBairro = wx.wxTextCtrl(fCadEnderecos, ID_FRMCADENDERECOS_EDTBAIRRO,
    "", wx.wxPoint(280, 64), wx.wxSize(144, 21) )
  frmCadEnderecos_edtBairro:Enable(false)
	frmCadEnderecos_labCEP = wx.wxStaticText(fCadEnderecos, ID_FRMCADENDERECOS_LABCEP,
    "CEP: ", wx.wxPoint(8, 88), wx.wxSize(40, 13) )
	frmCadEnderecos_edtCEP = wx.wxTextCtrl(fCadEnderecos, ID_FRMCADENDERECOS_EDTCEP,
    "", wx.wxPoint(8, 104), wx.wxSize(72, 21) )
  frmCadEnderecos_edtCEP:Enable(false)
	frmCadEnderecos_labCidade = wx.wxStaticText(fCadEnderecos, ID_FRMCADENDERECOS_LABCIDADE,
    "Cidade: ", wx.wxPoint(88, 88), wx.wxSize(39, 13) )
	frmCadEnderecos_edtCidade = wx.wxTextCtrl(fCadEnderecos, ID_FRMCADENDERECOS_EDTCIDADE,
    "", wx.wxPoint(88, 104), wx.wxSize(184, 21) )
  frmCadEnderecos_edtCidade:Enable(false)
	frmCadEnderecos_labEstado = wx.wxStaticText(fCadEnderecos, ID_FRMCADENDERECOS_LABESTADO, 
    "Estado: ", wx.wxPoint(280, 88), wx.wxSize(56, 13) )
	frmCadEnderecos_cmbEstado = wx.wxChoice(fCadEnderecos, ID_FRMCADENDERECOS_CMBESTADO,
    wx.wxPoint(280, 104), wx.wxSize(144, 21) )
  frmCadEnderecos_cmbEstado:Enable(false)
  frmCadEnderecos_AdicionaCombo()
  frmCadastros_IniciaBotoes(fCadEnderecos)

  frmCadastros_btnPesquisar:SetDimensions(440, 8, 75, 25)
  frmCadastros_btnAnterior:SetDimensions(440, 40, 75, 25)
  frmCadastros_btnProximo:SetDimensions(440, 72, 75, 25)
  frmCadastros_btnSalvar:SetDimensions(200, 136, 75, 25)
  frmCadastros_btnExcluir:SetDimensions(280, 136, 75, 25)
  frmCadastros_btnLimpar:SetDimensions(360, 136, 75, 25)
  frmCadastros_btnFechar:SetDimensions(440, 136, 75, 25)

  frmCadEnderecos_FazLayout(fCadEnderecos)

  --frmCadastros_edtDescricao:SetMaxLength(40)
  --frmCadEnderecos_edtBairro:SetMaxLength(15)
  --frmCadEnderecos_edtCEP:SetMaxLength(8)
  --frmCadEnderecos_edtCidade:SetMaxLength(30)

  fCadEnderecos:ConnectEvent(ID_FRMCADENDERECOS,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fCadEnderecos:GetParent():Close(true)
      event:Skip()
    end )

  fCadEnderecos:ConnectEvent(ID_FRMCADASTROS_BTNNOVO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
      frmCadEnderecos_InformaLimpaDados(false)
      frmCadEnderecos_HabilitaDados(true)
      frmCadastros_NovoDado(ConsSQL_Endereco("N", 
        frmCadastros_edtCodigo:GetValue(),"","","","",""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadEnderecos:ConnectEvent(ID_FRMCADASTROS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_PesquisarDados(ConsSQL_Endereco("S", 
        frmCadastros_edtCodigo:GetValue(),"","","","",""), STR_ENDNENC,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir) then
        frmCadEnderecos_InformaLimpaDados(true)
        frmCadEnderecos_HabilitaDados(true)
      end
      event:Skip()
    end )

  fCadEnderecos:ConnectEvent(ID_FRMCADASTROS_BTNANTERIOR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao) then
        frmCadEnderecos_InformaLimpaDados(true)
      end		
      event:Skip()
    end )

  fCadEnderecos:ConnectEvent(ID_FRMCADASTROS_BTNPROXIMO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_registroProximo(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao) then
        frmCadEnderecos_InformaLimpaDados(true)
      end		
      event:Skip()
    end )

  fCadEnderecos:ConnectEvent(ID_FRMCADASTROS_BTNSALVAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_SalvarDados(frmCadEnderecos_ValidaDados(true),
        ConsSQL_Endereco("S", frmCadastros_edtCodigo:GetValue(),"","","","",""),
        ConsSQL_Endereco("U", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue(),"","","",""),
        ConsSQL_Endereco("I", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue(),"","","",""), true,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir) then
        frmCadEnderecos_InformaLimpaDados(false)
        frmCadEnderecos_HabilitaDados(false)
      end
      event:Skip()
    end )

  fCadEnderecos:ConnectEvent(ID_FRMCADASTROS_BTNEXCLUIR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_ExcluirDados(frmCadEnderecos_ValidaDados(false),
        ConsSQL_Endereco("D", frmCadastros_edtCodigo:GetValue(),"","","","",""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir) then
        frmCadEnderecos_InformaLimpaDados(false)
        frmCadEnderecos_HabilitaDados(false)
      end
      event:Skip()
    end )

  fCadEnderecos:ConnectEvent(ID_FRMCADASTROS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fCadEnderecos:Close(true)
      event:Skip()
    end )

  fCadEnderecos:ConnectEvent(ID_FRMCADASTROS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao, frmCadastros_btnNovo, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      frmCadEnderecos_InformaLimpaDados(false)
      frmCadEnderecos_HabilitaDados(false)
      event:Skip()
    end )

  return fCadEnderecos
end

function frmCadEnderecos_FazLayout(parent)
  sizer_1 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_2 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_3 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_4 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_5 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_6 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_6 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_5 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_4 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_8 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_9 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_8 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_7 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_7 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_7:AddWindow(frmCadastros_labCodigo, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_7:AddWindow(frmCadastros_edtCodigo, 0, 0, 0)
  sizer_7:AddSizer(grid_sizer_7, 0, 0, 0)
  sizer_7:AddWindow(frmCadastros_btnNovo, 0, wx.wxLEFT + wx.wxALIGN_BOTTOM, 5)
  sizer_5:AddSizer(sizer_7, 1, 0, 0)
  grid_sizer_8:AddWindow(frmCadastros_labDescricao, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_8:AddWindow(frmCadastros_edtDescricao, 0, 0, 0)
  sizer_8:AddSizer(grid_sizer_8, 0, 0, 0)
  grid_sizer_9:AddWindow(frmCadEnderecos_labBairro, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_9:AddWindow(frmCadEnderecos_edtBairro, 0, 0, 0)
  sizer_8:AddSizer(grid_sizer_9, 0, wx.wxLEFT, 2)
  sizer_5:AddSizer(sizer_8, 1, wx.wxEXPAND, 0)
  grid_sizer_4:AddWindow(frmCadEnderecos_labCEP, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_4:AddWindow(frmCadEnderecos_edtCEP, 0, 0, 0)
  sizer_6:AddSizer(grid_sizer_4, 0, 0, 0)
  grid_sizer_5:AddWindow(frmCadEnderecos_labCidade, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_5:AddWindow(frmCadEnderecos_edtCidade, 0, 0, 0)
  sizer_6:AddSizer(grid_sizer_5, 0, wx.wxLEFT, 4)
  grid_sizer_6:AddWindow(frmCadEnderecos_labEstado, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_6:AddWindow(frmCadEnderecos_cmbEstado, 0, 0, 0)
  sizer_6:AddSizer(grid_sizer_6, 0, wx.wxLEFT, 5)
  sizer_5:AddSizer(sizer_6, 0, 0, 0)
  sizer_3:AddSizer(sizer_5, 0, 0, 0)
  sizer_4:AddWindow(frmCadastros_btnPesquisar, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_4:AddWindow(frmCadastros_btnAnterior, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_4:AddWindow(frmCadastros_btnProximo, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_3:AddSizer(sizer_4, 1, 0, 0)
  sizer_1:AddSizer(sizer_3, 1, wx.wxALL + wx.wxEXPAND, 4)
  sizer_2:AddWindow(frmCadastros_btnSalvar, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnExcluir, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnLimpar, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnFechar, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_1:AddSizer(sizer_2, 0, wx.wxRIGHT + wx.wxBOTTOM + wx.wxALIGN_RIGHT + 
    wx.wxALIGN_BOTTOM, 4)
  parent:SetAutoLayout(true)
  parent:SetSizer(sizer_1)
  sizer_1:Fit(parent)
  sizer_1:SetSizeHints(parent)
end

function frmCadEnderecos_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo:GetValue(),
    STR_CODNINF) then
    return false
  end
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao:GetValue(),
      STR_ENDNINF) then
    	return false
    end
    if Rotinas_ValidaCampo(frmCadEnderecos_edtBairro:GetValue(),
      STR_BAIRRONINF) then
    	return false
    end
    if Rotinas_ValidaCampo(frmCadEnderecos_edtCEP:GetValue(),
      STR_CEPNINF) then
    	return false
    end
    if Rotinas_ValidaCampo(frmCadEnderecos_edtCidade:GetValue(),
      STR_CIDADENINF) then
    	return false
    end
  end
	return true
end

function frmCadEnderecos_InformaLimpaDados(bInformar)
  if bInformar then
    frmCadEnderecos_edtBairro:SetValue("2")
    frmCadEnderecos_edtCEP:SetValue("3")
    frmCadEnderecos_edtCidade:SetValue("4")
    frmCadEnderecos_cmbEstado:SetStringSelection("Pernambuco")
  else
    frmCadEnderecos_edtBairro:Clear()
    frmCadEnderecos_edtCEP:Clear()
    frmCadEnderecos_edtCidade:Clear()
    frmCadEnderecos_cmbEstado:SetSelection(0)
  end
end

function frmCadEnderecos_HabilitaDados(bHabilita)
  frmCadEnderecos_edtBairro:Enable(bHabilita)
  frmCadEnderecos_edtCEP:Enable(bHabilita)  
  frmCadEnderecos_edtCidade:Enable(bHabilita)
  frmCadEnderecos_cmbEstado:Enable(bHabilita)  
end

function frmCadEnderecos_AdicionaCombo()
  frmCadEnderecos_cmbEstado:Append(STR_PE)
  frmCadEnderecos_cmbEstado:Append(STR_AC)
  frmCadEnderecos_cmbEstado:Append(STR_AL)
  frmCadEnderecos_cmbEstado:Append(STR_AP)
  frmCadEnderecos_cmbEstado:Append(STR_AM)
  frmCadEnderecos_cmbEstado:Append(STR_BA)
  frmCadEnderecos_cmbEstado:Append(STR_BR)
  frmCadEnderecos_cmbEstado:Append(STR_CE)
  frmCadEnderecos_cmbEstado:Append(STR_DF)
  frmCadEnderecos_cmbEstado:Append(STR_ES)
  frmCadEnderecos_cmbEstado:Append(STR_GO)
  frmCadEnderecos_cmbEstado:Append(STR_MT)
  frmCadEnderecos_cmbEstado:Append(STR_MS)
  frmCadEnderecos_cmbEstado:Append(STR_MG)
  frmCadEnderecos_cmbEstado:Append(STR_PA)
  frmCadEnderecos_cmbEstado:Append(STR_PB)
  frmCadEnderecos_cmbEstado:Append(STR_PR)
  frmCadEnderecos_cmbEstado:Append(STR_SC)
  frmCadEnderecos_cmbEstado:Append(STR_RN)
  frmCadEnderecos_cmbEstado:Append(STR_RS)
  frmCadEnderecos_cmbEstado:Append(STR_RJ)
  frmCadEnderecos_cmbEstado:Append(STR_RO)
  frmCadEnderecos_cmbEstado:Append(STR_RR)
  frmCadEnderecos_cmbEstado:Append(STR_SP)
  frmCadEnderecos_cmbEstado:Append(STR_SE)
  frmCadEnderecos_cmbEstado:Append(STR_TO)
end
