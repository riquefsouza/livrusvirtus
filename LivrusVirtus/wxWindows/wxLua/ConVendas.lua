ID_FRMCONVENDAS_BTNPESQUISAR = 3100
ID_FRMCONVENDAS_BTNLIMPAR = 3101 
ID_FRMCONVENDAS_BTNFECHAR = 3102 
ID_FRMCONVENDAS_BTNPCLIENTE = 3103
ID_FRMCONVENDAS_BTNPLIVRO = 3104 
ID_FRMCONVENDAS_GRIDVENDAS = 3105
ID_FRMCONVENDAS_EDTDTHRVENDA = 3106 
ID_FRMCONVENDAS_EDTISBN = 3107 
ID_FRMCONVENDAS_EDTLIVRO = 3108 
ID_FRMCONVENDAS_EDTPRECOTOTAL = 3109 
ID_FRMCONVENDAS_LABDTHRVENDA = 3110 
ID_FRMCONVENDAS_LABISBN = 3111 
ID_FRMCONVENDAS_LABLIVRO = 3112 
ID_FRMCONVENDAS_LABPRECOTOTAL = 3113
ID_FRMCONVENDAS_LABCPF = 3114 
ID_FRMCONVENDAS_EDTCPF = 3115 
ID_FRMCONVENDAS_LABCLIENTE = 3116 
ID_FRMCONVENDAS_EDTCLIENTE = 3117 
ID_FRMCONVENDAS_LABREGISTRO = 3118
ID_FRMCONVENDAS = 3119

local frmConVendas
local frmConVendas_labDtHrVenda
local frmConVendas_edtDtHrVenda
local frmConVendas_labCPF
local frmConVendas_edtCPF
local frmConVendas_labCliente
local frmConVendas_edtCliente
local frmConVendas_btnPCliente
local frmConVendas_labISBN
local frmConVendas_edtISBN
local frmConVendas_labLivro
local frmConVendas_edtLivro
local frmConVendas_btnPLivro
local frmConVendas_labRegistro
local frmConVendas_gridVendas
local frmConVendas_labPrecoTotal
local frmConVendas_edtPrecoTotal
local frmConVendas_btnPesquisar
local frmConVendas_btnLimpar
local frmConVendas_btnFechar

function frmConVendas_Criar(parent)
  local fConVendas =  wx.wxPanel(parent, ID_FRMCONVENDAS, wx.wxPoint(0, 0), 
    wx.wxSize(480, 310))

  frmConVendas_labDtHrVenda = wx.wxStaticText(fConVendas, ID_FRMCONVENDAS_LABDTHRVENDA,
    "Data/Hora Venda: ", wx.wxPoint(8, 8), wx.wxSize(91, 13), 0)  
  frmConVendas_edtDtHrVenda = wx.wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTDTHRVENDA,
    "", wx.wxPoint(8, 24), wx.wxSize(128, 21), 0)

  frmConVendas_btnPesquisar = wx.wxButton(fConVendas, ID_FRMCONVENDAS_BTNPESQUISAR,
    "&Pesquisar", wx.wxPoint(144, 22), wx.wxSize(75, 25), 0)

  frmConVendas_labCPF = wx.wxStaticText(fConVendas, ID_FRMCONVENDAS_LABCPF,
    "CPF: ", wx.wxPoint(8, 48), wx.wxSize(48, 13), 0)  
  frmConVendas_edtCPF = wx.wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTCPF,
    "", wx.wxPoint(8, 64), wx.wxSize(128, 21), 0)

  frmConVendas_labCliente = wx.wxStaticText(fConVendas, ID_FRMCONVENDAS_LABCLIENTE,
    "Cliente: ", wx.wxPoint(142, 48), wx.wxSize(56, 13), 0)  
  frmConVendas_edtCliente = wx.wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTCLIENTE,
    "", wx.wxPoint(142, 64), wx.wxSize(306, 21), 0)
  frmConVendas_edtCliente:Enable(false)
 
  frmConVendas_btnPCliente = wx.wxButton(fConVendas, ID_FRMCONVENDAS_BTNPCLIENTE,
    "...", wx.wxPoint(448, 64), wx.wxSize(21, 21), 0)
  
  frmConVendas_labISBN = wx.wxStaticText(fConVendas, ID_FRMCONVENDAS_LABISBN,
    "ISBN: ", wx.wxPoint(8, 88), wx.wxSize(48, 13), 0)  
  frmConVendas_edtISBN = wx.wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTISBN,
    "", wx.wxPoint(8, 104), wx.wxSize(128, 21), 0)
  
  frmConVendas_labLivro = wx.wxStaticText(fConVendas, ID_FRMCONVENDAS_LABLIVRO,
    "Livro: ", wx.wxPoint(142, 88), wx.wxSize(40, 13), 0)  
  frmConVendas_edtLivro = wx.wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTLIVRO,
    "", wx.wxPoint(142, 104), wx.wxSize(306, 21), 0)
  frmConVendas_edtLivro:Enable(false)

  frmConVendas_btnPLivro = wx.wxButton(fConVendas, ID_FRMCONVENDAS_BTNPLIVRO,
    "...", wx.wxPoint(448, 104), wx.wxSize(21, 21), 0)

  frmConVendas_gridVendas = wx.wxGrid(fConVendas, ID_FRMCONVENDAS_GRIDVENDAS,
    wx.wxPoint(0, 136), wx.wxSize(355, 122), wx.wxSUNKEN_BORDER)
  frmConVendas_gridVendas:CreateGrid(1, 6, wx.wxGridSelectRows)
  frmConVendas_gridVendas:HideCellEditControl()
  frmConVendas_gridVendas:SetColLabelSize(21)

  frmConVendas_labRegistro = wx.wxStaticText(fConVendas, ID_FRMCONVENDAS_LABREGISTRO,
    "Registro 0 de 0", wx.wxPoint(8, 258), wx.wxSize(144, 13), 0)
  frmConVendas_labPrecoTotal = wx.wxStaticText(fConVendas, ID_FRMCONVENDAS_LABPRECOTOTAL,
    "Preço Total: ", wx.wxPoint(280, 258), wx.wxSize(61, 13), 0)  
  frmConVendas_edtPrecoTotal = wx.wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTPRECOTOTAL,
    "", wx.wxPoint(344, 256), wx.wxSize(127, 21), 0)
  frmConVendas_edtPrecoTotal:Enable(false)

  frmConVendas_btnLimpar = wx.wxButton(fConVendas, ID_FRMCONVENDAS_BTNLIMPAR,
    "&Limpar", wx.wxPoint(319, 283), wx.wxSize(75, 25), 0)
  frmConVendas_btnFechar = wx.wxButton(fConVendas, ID_FRMCONVENDAS_BTNFECHAR,
    "&Fechar", wx.wxPoint(399, 283), wx.wxSize(75, 25), 0)

  frmConVendas_FazLayout(fConVendas)

  nLargura = { 120, 100, 220, 100, 280, 80 }
  sRotulos = { "Data/Hora Venda", "CPF", "Cliente", "ISBN", "Livro", "Preço" }

  Rotinas_AdicionaColunasGrid(frmConVendas_gridVendas, 0, 6, nLargura, sRotulos)
  frmConVendas_gridVendas:EnableEditing(false)
  --frmConVendas_edtCPF:MaxLength = 14
  --frmConVendas_edtISBN:MaxLength = 13
  frmConVendas_edtPrecoTotal:SetValue("R$ 0,00")
  frmConVendas_edtDtHrVenda:SetValue(Rotinas_retDataHoraStr(true,true))

  fConVendas:ConnectEvent(ID_FRMCONVENDAS,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fConVendas:GetParent():Close(true)
      event:Skip()
    end )

  fConVendas:ConnectEvent(ID_FRMCONVENDAS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      event:Skip()
    end )

  fConVendas:ConnectEvent(ID_FRMCONVENDAS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fConVendas:Close(true)
      event:Skip()
    end )

  fConVendas:ConnectEvent(ID_FRMCONVENDAS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConVendas_edtCPF:Clear()
      frmConVendas_edtCliente:Clear()
      frmConVendas_edtISBN:Clear()
      frmConVendas_edtLivro:Clear()
      frmConVendas_gridVendas:ClearGrid()
      frmConVendas_gridVendas:DeleteRows(0, frmConVendas_gridVendas:GetNumberRows()-1,true)
      frmConVendas_edtPrecoTotal:SetValue("R$ 0,00")
      frmConVendas_edtDtHrVenda:SetValue(Rotinas_retDataHoraStr(true,true))
      frmConVendas_labRegistro:SetLabel("Registro 0 de 0")
      frmConVendas_edtDtHrVenda:SetFocus()
      event:Skip()
    end )

  fConVendas:ConnectEvent(ID_FRMCONVENDAS_EDTCPF,
    wx.wxEVT_KILL_FOCUS,
    function (event)
      event:Skip()
    end )

  fConVendas:ConnectEvent(ID_FRMCONVENDAS_BTNPCLIENTE,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      --local fConClientes = frmConClientes_Criar(frmConVendas)
      --fConClientes:ShowModal()
      --frmConVendas_edtCPF:SetValue(Rotinas_sCodigoSelecionado)
      --frmConVendas_OnEdtCPF_Killfocus(0)
      event:Skip()
    end )
 
  fConVendas:ConnectEvent(ID_FRMCONVENDAS_EDTISBN,
    wx.wxEVT_KILL_FOCUS,
    function (event)
      event:Skip()
    end )
  
  fConVendas:ConnectEvent(ID_FRMCONVENDAS_BTNPLIVRO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      --local fConLivros = frmConLivros_Criar(frmConVendas)
      --fConLivros:ShowModal()
      --frmConVendas_edtISBN:SetValue(Rotinas_sCodigoSelecionado)
      --frmConVendas_OnEdtISBN_Killfocus(0)
      event:Skip()
    end )
  
  fConVendas:ConnectEvent(ID_FRMCONVENDAS_GRIDVENDAS,
    wx.wxEVT_GRID_SELECT_CELL,
    function (event)
      frmConVendas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  fConVendas:ConnectEvent(ID_FRMCONVENDAS_GRIDVENDAS,
    wx.wxEVT_GRID_LABEL_LEFT_CLICK,
    function (event)
      frmConVendas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  frmConVendas_edtDtHrVenda:ConnectEvent(ID_FRMCONVENDAS_EDTDTHRVENDA,
    wx.wxEVT_KILL_FOCUS,
    function (event)
      if string.len(frmConVendas_edtDtHrVenda:GetValue()) > 0 then
        if not Rotinas_validaDataHora(frmConVendas_edtDtHrVenda:GetValue(), 
          false) then
          wx.wxMessageBox(STR_DTHRINV, "Erro", wx.wxOK + wx.wxICON_ERROR)
      		frmConVendas_edtDtHrVenda:SetFocus()
        end
      end
    end ) 

  return fConVendas
end

function frmConVendas_FazLayout(parent)
  sizer_1 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_6 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_22 = wx.wxGridSizer(1, 2, 0, 0)
  sizer_23 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_8 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_7 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_24 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_4 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_8 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_6 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_5 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_3 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_4 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_3 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_2 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_2 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_1 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_1:AddWindow(frmConVendas_labDtHrVenda, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_1:AddWindow(frmConVendas_edtDtHrVenda, 0, 0, 0)
  sizer_2:AddSizer(grid_sizer_1, 0, wx.wxLEFT, 2)
  sizer_2:AddWindow(frmConVendas_btnPesquisar, 0, wx.wxLEFT +
    wx.wxTOP + wx.wxALIGN_BOTTOM, 10)
  sizer_1:AddSizer(sizer_2, 0, 0, 0)
  grid_sizer_2:AddWindow(frmConVendas_labCPF, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_2:AddWindow(frmConVendas_edtCPF, 0, 0, 0)
  sizer_3:AddSizer(grid_sizer_2, 0, wx.wxLEFT, 2)
  grid_sizer_3:AddWindow(frmConVendas_labCliente, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_3:AddWindow(frmConVendas_edtCliente, 0, 0, 0)
  sizer_3:AddSizer(grid_sizer_3, 0, wx.wxLEFT, 2)
  grid_sizer_4:Add(20, 20, 0, 0, 0)
  grid_sizer_4:AddWindow(frmConVendas_btnPCliente, 0, 0, 0)
  sizer_3:AddSizer(grid_sizer_4, 0, 0, 0)
  sizer_1:AddSizer(sizer_3, 0, 0, 0)
  grid_sizer_5:AddWindow(frmConVendas_labISBN, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_5:AddWindow(frmConVendas_edtISBN, 0, 0, 0)
  sizer_4:AddSizer(grid_sizer_5, 0, wx.wxLEFT, 2)
  grid_sizer_6:AddWindow(frmConVendas_labLivro, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_6:AddWindow(frmConVendas_edtLivro, 0, 0, 0)
  sizer_4:AddSizer(grid_sizer_6, 0, wx.wxLEFT, 2)
  grid_sizer_8:Add(20, 20, 0, 0, 0)
  grid_sizer_8:AddWindow(frmConVendas_btnPLivro, 0, 0, 0)
  sizer_4:AddSizer(grid_sizer_8, 0, 0, 0)
  sizer_1:AddSizer(sizer_4, 0, 0, 0)
  sizer_1:AddWindow(frmConVendas_gridVendas, 1, wx.wxALL + wx.wxEXPAND, 2)
  sizer_24:AddWindow(frmConVendas_labRegistro, 0, wx.wxALL, 4)
  sizer_24:Add(20, 20, 0, 0, 0)
  sizer_22:AddSizer(sizer_24, 0, 0, 0)
  sizer_7:AddWindow(frmConVendas_labPrecoTotal, 0, wx.wxALL, 2)
  sizer_7:AddWindow(frmConVendas_edtPrecoTotal, 0, wx.wxALL, 2)
  sizer_23:AddSizer(sizer_7, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_8:AddWindow(frmConVendas_btnLimpar, 0, wx.wxALL +
    wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_8:AddWindow(frmConVendas_btnFechar, 0, wx.wxALL +
    wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_23:AddSizer(sizer_8, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_22:AddSizer(sizer_23, 1, wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 0)
  sizer_6:AddSizer(sizer_22, 0, wx.wxEXPAND, 0)
  sizer_1:AddSizer(sizer_6, 0, wx.wxEXPAND, 0)
  parent:SetAutoLayout(true)
  parent:SetSizer(sizer_1)
  sizer_1:Fit(parent)
  sizer_1:SetSizeHints(parent)
  parent:Layout()
end

function frmConVendas_ConsVenda(sOpcao)
  local sISBN, sCPF, sDataHora, sret

  --if string.len(frmConVendas_edtDtHrVenda:GetValue()) > 0 then
    --sDataHora = Rotinas_ConverteDataHoraStr(
    --  frmConVendas_edtDtHrVenda:GetValue(), "MM/dd/yyyy hh:mm:ss")
  --else
  --  sDataHora = ""
  --end

  sISBN = frmConVendas_edtISBN:GetValue()
  sCPF = frmConVendas_edtCPF:GetValue()

  if sOpcao == "L" then
    sret = ConsSQL_Venda("S","ZERO","","","","")
  else
    sret = ConsSQL_Venda(sOpcao, sISBN, sCPF, sDataHora, "", "")
  end
  return sret
end

function frmConVendas_setLabRegistros(nLinha)
  if nLinha >= 0 then
    frmConVendas_labRegistro.SetLabel("Registro " .. tonumber(nLinha+1) .. 
      " de " .. tonumber(frmConVendas_gridVendas:GetNumberRows()))
  end
end
