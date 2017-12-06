ID_FRMCONSULTAS_BTNFECHAR = 500
ID_FRMCONSULTAS_BTNLIMPAR = 501
ID_FRMCONSULTAS_BTNPESQUISAR = 502
ID_FRMCONSULTAS_EDTDESCRICAO = 503
ID_FRMCONSULTAS_GRIDCONSULTA = 504
ID_FRMCONSULTAS_LABDESCRICAO = 505
ID_FRMCONSULTAS_LABREGISTRO = 506

local frmConsultas_Registros, frmConsultas_Campos
local frmConsultas_sSelecionado

frmConsultas_labDescricao = nil
frmConsultas_edtDescricao = nil
frmConsultas_btnPesquisar = nil
frmConsultas_labRegistro = nil
frmConsultas_gridConsulta = nil
frmConsultas_btnFechar = nil
frmConsultas_btnLimpar = nil

function frmConsultas_Criar(parent, nId)
  local fConsultas = wx.wxDialog(parent, nId, "Consulta de", wx.wxPoint(0, 0), 
      wx.wxSize(365, 263), wx.wxDEFAULT_DIALOG_STYLE + wx.wxRESIZE_BORDER +
      wx.wxMINIMIZE_BOX + wx.wxMAXIMIZE_BOX) 

  icone = wx.wxDefaultIcon()
  icone:CopyFromBitmap(wx.wxBitmapFromXPMData(livrus_xpm))
  fConsultas:SetIcon(icone)

  fConsultas:SetClientSize(wx.wxSize(365, 263))
  fConsultas:Centre()

  frmConsultas_labDescricao = wx.wxStaticText(fConsultas, ID_FRMCONSULTAS_LABDESCRICAO,
    "Descrição:", wx.wxPoint(8, 8), wx.wxSize(51, 13), 0)
  frmConsultas_edtDescricao = wx.wxTextCtrl(fConsultas, ID_FRMCONSULTAS_EDTDESCRICAO,
    "", wx.wxPoint(8, 24), wx.wxSize(257, 21), 0)
  frmConsultas_btnPesquisar = wx.wxButton(fConsultas, ID_FRMCONSULTAS_BTNPESQUISAR,
    "&Pesquisar", wx.wxPoint(272, 24), wx.wxSize(75, 25), 0)

  frmConsultas_gridConsulta = wx.wxGrid(fConsultas, ID_FRMCONSULTAS_GRIDCONSULTA, 
    wx.wxPoint(0, 56), wx.wxSize(365, 125), wx.wxBORDER_SUNKEN)
  frmConsultas_gridConsulta:CreateGrid(1, 2, wx.wxGridSelectRows)
  frmConsultas_gridConsulta:SetColLabelValue(0, "Código")
  frmConsultas_gridConsulta:SetColSize(0, 80)
  frmConsultas_gridConsulta:SetColLabelValue(1, "Descrição")
  frmConsultas_gridConsulta:SetColSize(1, 180)
  frmConsultas_gridConsulta:EnableEditing(false)
  frmConsultas_gridConsulta:HideCellEditControl()
  frmConsultas_gridConsulta:SetColLabelSize(21)
  
  frmConsultas_labRegistro = wx.wxStaticText(fConsultas, ID_FRMCONSULTAS_LABREGISTRO,
    "Registro 0 de 0", wx.wxPoint(8, 16), wx.wxSize(144, 13), 0)
  frmConsultas_btnLimpar = wx.wxButton(fConsultas, ID_FRMCONSULTAS_BTNLIMPAR,
    "&Limpar", wx.wxPoint(16, 13), wx.wxSize(75, 25), 0)
  frmConsultas_btnFechar = wx.wxButton(fConsultas, ID_FRMCONSULTAS_BTNFECHAR,
    "&Fechar", wx.wxPoint(75, 13), wx.wxSize(75, 25), 0)

  frmConsultas_FazLayout(fConsultas)
  --frmConsultas_Registros = new ArrayList()
  frmConsultas_sSelecionado = ""
  frmConsultas_edtDescricao:SetFocus()

  return fConsultas
end

function frmConsultas_FazLayout( parent )
  sizer_1 = wx.wxBoxSizer(wx.wxVERTICAL)
  grid_sizer_2 = wx.wxGridSizer(1, 2, 0, 0)
  sizer_2 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_3 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_4 = wx.wxBoxSizer(wx.wxVERTICAL)
  grid_sizer_1 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_1:AddWindow(frmConsultas_labDescricao, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_1:AddWindow(frmConsultas_edtDescricao, 0, 0, 0)
  sizer_3:AddSizer(grid_sizer_1, 0, wx.wxALL, 2)
  sizer_4:Add(20, 20, 0, 0, 0)
  sizer_4:AddWindow(frmConsultas_btnPesquisar, 0, wx.wxLEFT + wx.wxTOP + wx.wxBOTTOM, 5)
  sizer_3:AddSizer(sizer_4, 0, 0, 0)
  sizer_1:AddSizer(sizer_3, 0, wx.wxALL, 4)
  sizer_1:AddWindow(frmConsultas_gridConsulta, 1, wx.wxEXPAND, 0)
  grid_sizer_2:AddWindow(frmConsultas_labRegistro, 0, wx.wxALL, 10)
  sizer_2:AddWindow(frmConsultas_btnLimpar, 0, wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 8)
  sizer_2:AddWindow(frmConsultas_btnFechar, 0, wx.wxLEFT + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 8)
  grid_sizer_2:AddSizer(sizer_2, 1, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 4)
  sizer_1:AddSizer(grid_sizer_2, 0, wx.wxALL + wx.wxEXPAND + wx.wxALIGN_BOTTOM, 0)
  parent:SetAutoLayout(true)
  parent:SetSizer(sizer_1)
  sizer_1:Fit(parent)
  sizer_1:SetSizeHints(parent)
  parent:Layout()
end

function frmConsultas_Fecha(form, nIndMenu)
  if string.len(frmConsultas_sSelecionado) > 0 then
    Rotinas_sCodigoSelecionado = frmConsultas_sSelecionado
  else
    Rotinas_sCodigoSelecionado = "" 
  end
  if nIndMenu == 0 then
    if form:IsModal() then
      form:EndModal(0)
    else
      form:Close()
    end
  else    
    frmPrincipal_barraMenu:GetMenu(1):Enable(nIndMenu, true)
  end
end

function frmConsultas_LimparDados()
  frmConsultas_labRegistro:SetLabel("Registro 0 de 0")
  frmConsultas_gridConsulta:ClearGrid()
  frmConsultas_gridConsulta:DeleteRows(0,
    frmConsultas_gridConsulta:GetNumberRows()-1,true)
  frmConsultas_edtDescricao:Clear()
  frmConsultas_edtDescricao:SetFocus()
end

function frmConsultas_PesquisarDados(sTextoSql, sMensagemErro, nQtdCol)
  --if Rotinas_ConsultaDadosLista(frmConsultas_Registros, sTextoSql) then
  --  Rotinas_AdicionaLinhasGrid(frmConsultas_gridConsulta, frmConsultas_Registros, nQtdCol)
  --else
    wx.wxMessageBox(sMensagemErro, "Erro", wx.wxOK + wx.wxICON_ERROR )
  --end if
end

function frmConsultas_setLabRegistros(nLinha)
  if nLinha >= 0 then
    frmConsultas_labRegistro:SetLabel("Registro " .. tonumber(nLinha+1) .. " de " .. 
      tonumber(frmConsultas_gridConsulta.GetNumberRows()))
    frmConsultas_sSelecionado = frmConsultas_gridConsulta:GetCellValue(nLinha, 0)
  end
end
