ID_FRMVENDERLIVROS_BTNVENDER = 3000
ID_FRMVENDERLIVROS_BTNLIMPAR = 3001 
ID_FRMVENDERLIVROS_BTNFECHAR = 3002 
ID_FRMVENDERLIVROS_BTNPCLIENTE = 3003
ID_FRMVENDERLIVROS_BTNPLIVRO = 3004 
ID_FRMVENDERLIVROS_LSTLIVROS = 3005
ID_FRMVENDERLIVROS_EDTDTHRVENDA = 3006 
ID_FRMVENDERLIVROS_EDTISBN = 3007 
ID_FRMVENDERLIVROS_EDTLIVRO = 3008 
ID_FRMVENDERLIVROS_EDTPRECOTOTAL = 3009 
ID_FRMVENDERLIVROS_LABDTHRVENDA = 3010 
ID_FRMVENDERLIVROS_LABISBN = 3011 
ID_FRMVENDERLIVROS_LABLIVRO = 3012 
ID_FRMVENDERLIVROS_LABLIVROS = 3013 
ID_FRMVENDERLIVROS_LABPRECOTOTAL = 3014 
ID_FRMVENDERLIVROS_BTNADLIVROS = 3015
ID_FRMVENDERLIVROS = 3016

local frmVenderLivros
local frmVenderLivros_slPrecos
local frmVenderLivros_slISBNs
local frmVenderLivros_slQtdEstoque
local frmVenderLivros_nPrecoTotal
local frmVenderLivros_labDtHrVenda
local frmVenderLivros_edtDtHrVenda
local frmVenderLivros_btnPCliente
local frmVenderLivros_labISBN
local frmVenderLivros_edtISBN
local frmVenderLivros_labLivro
local frmVenderLivros_edtLivro
local frmVenderLivros_btnAdLivros
local frmVenderLivros_btnPLivro
local frmVenderLivros_labLivros
local frmVenderLivros_lstLivros
local frmVenderLivros_labPrecoTotal
local frmVenderLivros_edtPrecoTotal
local frmVenderLivros_btnVender

function frmVenderLivros_Criar(parent)
  local fVenderLivros = frmCadastros_Criar(parent, ID_FRMVENDERLIVROS, 0, false)

  frmCadastros_btnNovo:Show(false)

  frmVenderLivros_labDtHrVenda = wx.wxStaticText(fVenderLivros, ID_FRMVENDERLIVROS_LABDTHRVENDA,
    "Data/Hora Venda: ", wx.wxPoint(8, 8), wx.wxSize(91, 13), 0)  
  frmVenderLivros_edtDtHrVenda = wx.wxTextCtrl(fVenderLivros, ID_FRMVENDERLIVROS_EDTDTHRVENDA,
    "", wx.wxPoint(8, 24), wx.wxSize(128, 21), 0)
  frmVenderLivros_edtDtHrVenda:Enable(false)

  frmCadastros_labCodigo:SetLabel("CPF: ")
  frmCadastros_labCodigo:SetDimensions(8, 48, 48, 13) 
  frmCadastros_edtCodigo:SetDimensions(8, 64, 128, 21)

  frmCadastros_labDescricao:SetLabel("Cliente: ")
  frmCadastros_labDescricao:SetDimensions(142, 48, 56, 13)  
  frmCadastros_edtDescricao:SetDimensions(142, 64, 306, 21)
  frmCadastros_edtDescricao:Enable(false)
 
  frmVenderLivros_btnPCliente = wx.wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNPCLIENTE,
    "...", wx.wxPoint(448, 64), wx.wxSize(21, 21), 0)
  
  frmVenderLivros_labISBN = wx.wxStaticText(fVenderLivros, ID_FRMVENDERLIVROS_LABISBN,
    "ISBN: ", wx.wxPoint(8, 88), wx.wxSize(48, 13), 0)  
  frmVenderLivros_edtISBN = wx.wxTextCtrl(fVenderLivros, ID_FRMVENDERLIVROS_EDTISBN,
    "", wx.wxPoint(8, 104), wx.wxSize(128, 21), 0)
  
  frmVenderLivros_labLivro = wx.wxStaticText(fVenderLivros, ID_FRMVENDERLIVROS_LABLIVRO,
    "Livro: ", wx.wxPoint(142, 88), wx.wxSize(40, 13), 0)  
  frmVenderLivros_edtLivro = wx.wxTextCtrl(fVenderLivros, ID_FRMVENDERLIVROS_EDTLIVRO,
    "", wx.wxPoint(142, 104), wx.wxSize(282, 21), 0)
  frmVenderLivros_edtLivro:Enable(false)

  frmVenderLivros_btnAdLivros = wx.wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNADLIVROS,
  "+", wx.wxPoint(424, 104), wx.wxSize(21, 21), 0)
  
  frmVenderLivros_btnPLivro = wx.wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNPLIVRO,
    "...", wx.wxPoint(448, 104), wx.wxSize(21, 21), 0)
  
  frmVenderLivros_labLivros = wx.wxStaticText(fVenderLivros, ID_FRMVENDERLIVROS_LABLIVROS,
    "Livros para vender: ", wx.wxPoint(8, 128), wx.wxSize(120, 13), 0)
  
  frmVenderLivros_lstLivros = wx.wxListBox(fVenderLivros, ID_FRMVENDERLIVROS_LSTLIVROS,
    wx.wxPoint(8, 144), wx.wxSize(464, 96))
  
  frmVenderLivros_labPrecoTotal = wx.wxStaticText(fVenderLivros, ID_FRMVENDERLIVROS_LABPRECOTOTAL,
    "Preço Total: ", wx.wxPoint(280, 248), wx.wxSize(61, 13), 0)  
  frmVenderLivros_edtPrecoTotal = wx.wxTextCtrl(fVenderLivros, ID_FRMVENDERLIVROS_EDTPRECOTOTAL,
    "R$ 0,00", wx.wxPoint(344, 246), wx.wxSize(127, 21), 0)
  frmVenderLivros_edtPrecoTotal:Enable(false)
  
  frmVenderLivros_btnVender = wx.wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNVENDER,
    "&Vender", wx.wxPoint(239, 275), wx.wxSize(75, 25), 0)  
  frmCadastros_btnLimpar = wx.wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNLIMPAR,
    "&Limpar", wx.wxPoint(319, 275), wx.wxSize(75, 25), 0)  
  frmCadastros_btnFechar = wx.wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNFECHAR,
    "&Fechar", wx.wxPoint(399, 275), wx.wxSize(75, 25), 0)

  frmVenderLivros_FazLayout(fVenderLivros)

  frmVenderLivros_edtDtHrVenda:SetValue(Rotinas_retDataHoraStr(true, true))
  --frmCadastros_edtCodigo:MaxLength = 14
  --frmVenderLivros_edtISBN:MaxLength = 13
  frmVenderLivros_nPrecoTotal = 0

  fVenderLivros:ConnectEvent(ID_FRMVENDERLIVROS,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fVenderLivros:GetParent():Close(true)
      event:Skip()
    end )

  fVenderLivros:ConnectEvent(ID_FRMVENDERLIVROS_BTNVENDER,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmVenderLivros_ValidaDados() then
        --if frmVenderLivros_SalvaLista() then
        --  wx.wxMessageBox(STR_VENRESUC, STR_TITULO, wx.wxOK + 
        --  wx.wxICON_INFORMATION)
        --  frmVenderLivros_LimpaDados()
        --end
      end	
      event:Skip()
    end )

  fVenderLivros:ConnectEvent(ID_FRMVENDERLIVROS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fVenderLivros:Close(true)
      event:Skip()
    end )

  fVenderLivros:ConnectEvent(ID_FRMVENDERLIVROS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmVenderLivros_LimpaDados()
      event:Skip()
    end )

  return fVenderLivros
end

function frmVenderLivros_FazLayout(parent)
  sizer_1 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_6 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_8 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_7 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_5 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_4 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_8 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_7 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_6 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_5 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_3 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_4 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_3 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_2 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_2 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_1 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_1:AddWindow(frmVenderLivros_labDtHrVenda, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_1:AddWindow(frmVenderLivros_edtDtHrVenda, 0, 0, 0)
  sizer_2:AddSizer(grid_sizer_1, 0, wx.wxLEFT, 2)
  sizer_2:Add(20, 20, 0, 0, 0)
  sizer_1:AddSizer(sizer_2, 0, 0, 0)
  grid_sizer_2:AddWindow(frmCadastros_labCodigo, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_2:AddWindow(frmCadastros_edtCodigo, 0, 0, 0)
  sizer_3:AddSizer(grid_sizer_2, 0, wx.wxLEFT, 2)
  grid_sizer_3:AddWindow(frmCadastros_labDescricao, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_3:AddWindow(frmCadastros_edtDescricao, 0, 0, 0)
  sizer_3:AddSizer(grid_sizer_3, 0, wx.wxLEFT, 2)
  grid_sizer_4:Add(20, 20, 0, 0, 0)
  grid_sizer_4:AddWindow(frmVenderLivros_btnPCliente, 0, 0, 0)
  sizer_3:AddSizer(grid_sizer_4, 0, 0, 0)
  sizer_1:AddSizer(sizer_3, 0, 0, 0)
  grid_sizer_5:AddWindow(frmVenderLivros_labISBN, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_5:AddWindow(frmVenderLivros_edtISBN, 0, 0, 0)
  sizer_4:AddSizer(grid_sizer_5, 0, wx.wxLEFT, 2)
  grid_sizer_6:AddWindow(frmVenderLivros_labLivro, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_6:AddWindow(frmVenderLivros_edtLivro, 0, 0, 0)
  sizer_4:AddSizer(grid_sizer_6, 0, wx.wxLEFT, 2)
  grid_sizer_7:Add(20, 20, 0, 0, 0)
  grid_sizer_7:AddWindow(frmVenderLivros_btnAdLivros, 0, 0, 0)
  sizer_4:AddSizer(grid_sizer_7, 1, wx.wxEXPAND, 0)
  grid_sizer_8:Add(20, 20, 0, 0, 0)
  grid_sizer_8:AddWindow(frmVenderLivros_btnPLivro, 0, 0, 0)
  sizer_4:AddSizer(grid_sizer_8, 0, 0, 0)
  sizer_1:AddSizer(sizer_4, 0, 0, 0)
  sizer_5:AddWindow(frmVenderLivros_labLivros, 0, wx.wxALIGN_BOTTOM, 0)
  sizer_5:AddWindow(frmVenderLivros_lstLivros, 1, wx.wxALL + wx.wxEXPAND, 1)
  sizer_1:AddSizer(sizer_5, 1, wx.wxEXPAND, 0)
  sizer_7:AddWindow(frmVenderLivros_labPrecoTotal, 0, wx.wxALL, 2)
  sizer_7:AddWindow(frmVenderLivros_edtPrecoTotal, 0, wx.wxALL, 2)
  sizer_6:AddSizer(sizer_7, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_8:AddWindow(frmVenderLivros_btnVender, 0, wx.wxALL + 
    wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_8:AddWindow(frmCadastros_btnLimpar, 0, wx.wxALL + 
    wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_8:AddWindow(frmCadastros_btnFechar, 0, wx.wxALL + 
    wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_6:AddSizer(sizer_8, 0, wx.wxALL, 2)
  sizer_1:AddSizer(sizer_6, 0, wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 0)
  parent:SetAutoLayout(true)
  parent:SetSizer(sizer_1)
  sizer_1:Fit(parent)
  sizer_1:SetSizeHints(parent)
end

function frmVenderLivros_LimpaDados()
  frmVenderLivros_edtDtHrVenda:SetValue(Rotinas_retDataHoraStr(true, true))
  frmCadastros_edtCodigo:Clear()
  frmCadastros_edtDescricao:Clear()
  frmVenderLivros_edtISBN:Clear()
  frmVenderLivros_edtLivro:Clear()
  frmVenderLivros_lstLivros:Clear()
  frmVenderLivros_nPrecoTotal = 0
  frmVenderLivros_edtPrecoTotal:SetValue("R$ 0,00")
  frmCadastros_edtCodigo:SetFocus()
end

function frmVenderLivros_ValidaDados()
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo:GetValue(), 
    STR_CPFNINF) then
    return false
  end
  if frmVenderLivros_lstLivros:GetCount() == 0 then
    wx.wxMessageBox(STR_LIVVENNINF, "Erro", wx.wxOK + wx.wxICON_ERROR)
    return false
  end
	return true
end
