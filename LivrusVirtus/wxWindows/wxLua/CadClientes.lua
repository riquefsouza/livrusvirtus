ID_FRMCADCLIENTES_BTNPENDERECO = 800
ID_FRMCADCLIENTES_SBENDERECO = 801
ID_FRMCADCLIENTES_BTNPPAIS = 802
ID_FRMCADCLIENTES_BTNPPROFISSAO = 803 
ID_FRMCADCLIENTES_EDTBAIRRO = 804 
ID_FRMCADCLIENTES_EDTCEP = 805 
ID_FRMCADCLIENTES_EDTCIDADE = 806 
ID_FRMCADCLIENTES_EDTCODENDERECO = 807 
ID_FRMCADCLIENTES_EDTCODPAIS = 808 
ID_FRMCADCLIENTES_EDTCODPROFISSAO = 809 
ID_FRMCADCLIENTES_EDTDTNASC = 810 
ID_FRMCADCLIENTES_EDTEMAIL = 811 
ID_FRMCADCLIENTES_EDTESTADO = 812 
ID_FRMCADCLIENTES_EDTIDENTIDADE = 813 
ID_FRMCADCLIENTES_EDTLOGRADOURO = 814 
ID_FRMCADCLIENTES_EDTPAIS = 815 
ID_FRMCADCLIENTES_EDTPROFISSAO = 816 
ID_FRMCADCLIENTES_EDTTELEFONE = 817 
ID_FRMCADCLIENTES_LABBAIRRO = 818 
ID_FRMCADCLIENTES_LABCEP = 819 
ID_FRMCADCLIENTES_LABCIDADE = 820 
ID_FRMCADCLIENTES_LABDTNASC = 821 
ID_FRMCADCLIENTES_LABEMAIL = 822 
ID_FRMCADCLIENTES_LABESTADO = 823 
ID_FRMCADCLIENTES_LABIDENTIDADE = 824 
ID_FRMCADCLIENTES_LABLOGRADOURO = 825 
ID_FRMCADCLIENTES_LABPAIS = 826 
ID_FRMCADCLIENTES_LABPROFISSAO = 827 
ID_FRMCADCLIENTES_LABTELEFONE = 828 
ID_FRMCADCLIENTES_RBSEXO = 829
ID_FRMCADCLIENTES = 830

local frmCadClientes
local frmCadClientes_labEmail
local frmCadClientes_edtEmail
local frmCadClientes_labIdentidade
local frmCadClientes_edtIdentidade
local frmCadClientes_rbSexo
local frmCadClientes_labTelefone
local frmCadClientes_edtTelefone
local frmCadClientes_labDtNasc
local frmCadClientes_edtDtNasc
local frmCadClientes_sbEndereco
local frmCadClientes_edtCodEndereco
local frmCadClientes_btnPEndereco
local frmCadClientes_labLogradouro
local frmCadClientes_edtLogradouro
local frmCadClientes_labBairro
local frmCadClientes_edtBairro
local frmCadClientes_labCEP
local frmCadClientes_edtCEP
local frmCadClientes_labCidade
local frmCadClientes_edtCidade
local frmCadClientes_labEstado
local frmCadClientes_edtEstado
local frmCadClientes_labPais
local frmCadClientes_edtCodPais
local frmCadClientes_edtPais
local frmCadClientes_btnPPais
local frmCadClientes_labProfissao
local frmCadClientes_edtCodProfissao
local frmCadClientes_edtProfissao
local frmCadClientes_btnPProfissao

function frmCadClientes_Criar(parent)
  local fCadClientes = frmCadastros_Criar(parent, ID_FRMCADCLIENTES, 0, false)

  frmCadastros_labDescricao:SetLabel("Nome: ")
  frmCadastros_edtDescricao:SetSize(312, 21)

  frmCadClientes_labEmail = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABEMAIL,
             "E-mail: ", wx.wxPoint(8, 88), wx.wxSize(34, 13), 0)
  frmCadClientes_edtEmail = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTEMAIL,
             "", wx.wxPoint(8, 104), wx.wxSize(312, 21), 0)
  frmCadClientes_edtEmail:Enable(false)

  frmCadClientes_labIdentidade = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABIDENTIDADE,
              "Identidade: ", wx.wxPoint(322, 88), wx.wxSize(56, 13), 0)
  frmCadClientes_edtIdentidade = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTIDENTIDADE,
              "", wx.wxPoint(322, 104), wx.wxSize(100, 21), 0)
  frmCadClientes_edtIdentidade:Enable(false)  

  local sItems = {"Masculino", "Feminino"}
  frmCadClientes_rbSexo = wx.wxRadioBox(fCadClientes, ID_FRMCADCLIENTES_RBSEXO, "Sexo",
              wx.wxPoint(9, 128), wx.wxSize(200, 44), sItems, 2, wx.wxRA_SPECIFY_COLS)
  frmCadClientes_rbSexo:Enable(false)

  frmCadClientes_labTelefone = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABTELEFONE,
              "Telefone: ", wx.wxPoint(216, 128), wx.wxSize(48, 13), 0)
  frmCadClientes_edtTelefone = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTTELEFONE,
              "", wx.wxPoint(216, 144), wx.wxSize(104, 21), 0)
  frmCadClientes_edtTelefone:Enable(false)

  frmCadClientes_labDtNasc = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABDTNASC,
              "Dt. Nascimento", wx.wxPoint(322, 128), wx.wxSize(73, 13), 0)
  frmCadClientes_edtDtNasc = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTDTNASC,
            "", wx.wxPoint(322, 144), wx.wxSize(100, 21), 0)
  frmCadClientes_edtDtNasc:Enable(false)

  --frmCadClientes_sbEndereco = wx.wxStaticBox(fCadClientes, ID_FRMCADCLIENTES_SBENDERECO,
  --  "Endereço", wx.wxPoint(8, 176), wx.wxSize(432, 136), 0)

  frmCadClientes_edtCodEndereco = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTCODENDERECO, 
    "", wx.wxPoint(16, 200), wx.wxSize(88, 21), 0)
  frmCadClientes_edtCodEndereco:Enable(false)

  frmCadClientes_btnPEndereco = wx.wxButton(fCadClientes, ID_FRMCADCLIENTES_BTNPENDERECO,
              "...", wx.wxPoint(104, 200), wx.wxSize(21, 21), 0)
  frmCadClientes_btnPEndereco:Enable(false)

  frmCadClientes_labLogradouro = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABLOGRADOURO,
              "Logradouro: ", wx.wxPoint(16, 224), wx.wxSize(60, 13), 0)
  frmCadClientes_edtLogradouro = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTLOGRADOURO,
              "", wx.wxPoint(16, 240), wx.wxSize(264, 21), 0)
  frmCadClientes_edtLogradouro:Enable(false)

  frmCadClientes_labBairro = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABBAIRRO,
              "Bairro:", wx.wxPoint(284, 224), wx.wxSize(48, 13), 0)
  frmCadClientes_edtBairro = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTBAIRRO,
              "", wx.wxPoint(284, 240), wx.wxSize(144, 21), 0)
  frmCadClientes_edtBairro:Enable(false)

  frmCadClientes_labCEP = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABCEP, "CEP: ",
              wx.wxPoint(16, 264), wx.wxSize(40, 13), 0)
  frmCadClientes_edtCEP = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTCEP, "",
              wx.wxPoint(16, 280), wx.wxSize(78, 21), 0)
  frmCadClientes_edtCEP:Enable(false)

  frmCadClientes_labCidade = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABCIDADE,
              "Cidade: ", wx.wxPoint(96, 264), wx.wxSize(39, 13), 0)
  frmCadClientes_edtCidade = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTCIDADE,
              "", wx.wxPoint(96, 280), wx.wxSize(184, 21), 0)
  frmCadClientes_edtCidade:Enable(false)

  frmCadClientes_labEstado = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABESTADO,
              "Estado: ", wx.wxPoint(284, 264), wx.wxSize(56, 13), 0)
  frmCadClientes_edtEstado = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTESTADO,
              "", wx.wxPoint(284, 280), wx.wxSize(144, 21), 0)
  frmCadClientes_edtEstado:Enable(false)

  frmCadClientes_labPais = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABPAIS,
    "País de origem: ", wx.wxPoint(8, 320), wx.wxSize(77, 16), 0)
  frmCadClientes_edtCodPais = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTCODPAIS,
    "", wx.wxPoint(8, 336), wx.wxSize(78, 21), 0)
  frmCadClientes_edtCodPais:Enable(false)

  frmCadClientes_edtPais = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTPAIS,
              "", wx.wxPoint(88, 336), wx.wxSize(240, 21), 0)
  frmCadClientes_edtPais:Enable(false)
  frmCadClientes_btnPPais = wx.wxButton(fCadClientes, ID_FRMCADCLIENTES_BTNPPAIS, "...",
               wx.wxPoint(328, 336), wx.wxSize(21, 21), 0)
  frmCadClientes_btnPPais:Enable(false)

  frmCadClientes_labProfissao = wx.wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABPROFISSAO,
              "Profissão: ", wx.wxPoint(8, 360), wx.wxSize(56, 13), 0)
  frmCadClientes_edtCodProfissao = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTCODPROFISSAO,
    "", wx.wxPoint(8, 376), wx.wxSize(78, 21), 0)
  frmCadClientes_edtCodProfissao:Enable(false)

  frmCadClientes_edtProfissao = wx.wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTPROFISSAO,
              "", wx.wxPoint(88, 376), wx.wxSize(240, 21), 0)
  frmCadClientes_edtProfissao:Enable(false)
  frmCadClientes_btnPProfissao = wx.wxButton(fCadClientes, ID_FRMCADCLIENTES_BTNPPROFISSAO,
              "...", wx.wxPoint(328, 376), wx.wxSize(21, 21), 0)
  frmCadClientes_btnPProfissao:Enable(false)

  frmCadastros_IniciaBotoes(fCadClientes)
  frmCadastros_btnPesquisar:SetDimensions(440, 8, 75, 25)
  frmCadastros_btnAnterior:SetDimensions(440, 40, 75, 25)
  frmCadastros_btnProximo:SetDimensions(440, 72, 75, 25)
  frmCadastros_btnSalvar:SetDimensions(200, 408, 75, 25)
  frmCadastros_btnExcluir:SetDimensions(280, 408, 75, 25)
  frmCadastros_btnLimpar:SetDimensions(360, 408, 75, 25)
  frmCadastros_btnFechar:SetDimensions(440, 408, 75, 25)

  frmCadClientes_FazLayout(fCadClientes)

  --frmCadastros_edtCodigo:MaxLength = 14
  --frmCadastros_edtDescricao:MaxLength = 30
  --frmCadClientes_edtEmail:MaxLength = 30
  --frmCadClientes_edtIdentidade:MaxLength = 10
  --frmCadClientes_edtCodEndereco:MaxLength = 10
  --frmCadClientes_edtTelefone:MaxLength = 17
  --frmCadClientes_edtCodPais:MaxLength = 3
  --frmCadClientes_edtCodProfissao:MaxLength = 10

  fCadClientes:ConnectEvent(ID_FRMCADCLIENTES,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fCadClientes:GetParent():Close(true)
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADASTROS_BTNNOVO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
      frmCadClientes_InformaLimpaDados(false)
      frmCadClientes_HabilitaDados(true)
      frmCadastros_NovoDado(ConsSQL_Cliente("N", 
        frmCadastros_edtCodigo:GetValue(),"","","","","","","","",""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADASTROS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_PesquisarDados(ConsSQL_Cliente("S", 
        frmCadastros_edtCodigo:GetValue(),"","","","","","","","",""), STR_CLINENC,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir) then
        frmCadClientes_InformaLimpaDados(true)
        frmCadClientes_HabilitaDados(true)
      end
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADASTROS_BTNANTERIOR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao) then
        frmCadClientes_InformaLimpaDados(true)
      end		
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADASTROS_BTNPROXIMO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_registroProximo(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao) then
        frmCadClientes_InformaLimpaDados(true)
      end		
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADASTROS_BTNSALVAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_SalvarDados(frmCadClientes_ValidaDados(true),
        ConsSQL_Cliente("S", frmCadastros_edtCodigo:GetValue(),
	"","","","","","","","",""),
        ConsSQL_Cliente("U", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue(),"","","","","","","","",""),
        ConsSQL_Cliente("I", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue(),"","","","","","","","",""), true,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir) then
        frmCadClientes_InformaLimpaDados(false)
        frmCadClientes_HabilitaDados(false)
      end
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADASTROS_BTNEXCLUIR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_ExcluirDados(frmCadClientes_ValidaDados(false),
        ConsSQL_Cliente("D", frmCadastros_edtCodigo:GetValue(),
	"","","","","","","","",""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir) then
        frmCadClientes_InformaLimpaDados(false)
        frmCadClientes_HabilitaDados(false)
      end
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADASTROS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fCadClientes:Close(true)
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADASTROS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao, frmCadastros_btnNovo, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      frmCadClientes_InformaLimpaDados(false)
      frmCadClientes_HabilitaDados(false)
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADASTROS_EDTCODIGO,
    wx.wxEVT_KILL_FOCUS,
    function (event)
      if string.len(frmCadastros_edtCodigo:GetValue()) > 0 then
  	if Rotinas_ValidaCPF(frmCadastros_edtCodigo:GetValue()) == false then
          wx.wxMessageBox(STR_CPFINV, "Erro", wx.wxOK + wx.wxICON_ERROR)
          frmCadastros_edtCodigo:Clear()
  	  frmCadastros_edtCodigo:SetFocus()
  	end
      end	
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADCLIENTES_BTNPENDERECO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADCLIENTES_BTNPPAIS,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      event:Skip()
    end )

  fCadClientes:ConnectEvent(ID_FRMCADCLIENTES_BTNPPROFISSAO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      event:Skip()
    end )

  return fCadClientes
end

function frmCadClientes_FazLayout(parent)
  sizer_1 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_2 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_3 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_4 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_5 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_16 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_23 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_22 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_19 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_15 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_21 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_20 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_18 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_end = wx.wxStaticBox(parent, -1, "Endereço")
  sizer_11 = wx.wxStaticBoxSizer(sizer_end, wx.wxVERTICAL)
  sizer_14 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_17 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_16 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_15 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_13 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_14 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_13 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_12 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_10 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_12 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_11 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_6 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_5 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_4 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_8 = wx.wxBoxSizer(wx.wxHORIZONTAL)
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
  sizer_5:AddSizer(sizer_8, 1, wx.wxEXPAND, 0)
  grid_sizer_4:AddWindow(frmCadClientes_labEmail, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_4:AddWindow(frmCadClientes_edtEmail, 0, 0, 0)
  sizer_6:AddSizer(grid_sizer_4, 0, 0, 0)
  grid_sizer_5:AddWindow(frmCadClientes_labIdentidade, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_5:AddWindow(frmCadClientes_edtIdentidade, 0, 0, 0)
  sizer_6:AddSizer(grid_sizer_5, 0, wx.wxLEFT, 4)
  sizer_5:AddSizer(sizer_6, 0, 0, 0)
  sizer_10:AddWindow(frmCadClientes_rbSexo, 0, 0, 0)
  grid_sizer_11:AddWindow(frmCadClientes_labTelefone, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_11:AddWindow(frmCadClientes_edtTelefone, 0, 0, 0)
  sizer_10:AddSizer(grid_sizer_11, 1, wx.wxLEFT + wx.wxEXPAND, 4)
  grid_sizer_12:AddWindow(frmCadClientes_labDtNasc, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_12:AddWindow(frmCadClientes_edtDtNasc, 0, 0, 0)
  sizer_10:AddSizer(grid_sizer_12, 1, wx.wxLEFT + wx.wxEXPAND, 4)
  sizer_5:AddSizer(sizer_10, 1, wx.wxEXPAND, 0)
  sizer_12:AddWindow(frmCadClientes_edtCodEndereco, 0, 0, 0)
  sizer_12:AddWindow(frmCadClientes_btnPEndereco, 0, 0, 0)
  sizer_11:AddSizer(sizer_12, 0, wx.wxALL, 2)
  grid_sizer_13:AddWindow(frmCadClientes_labLogradouro, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_13:AddWindow(frmCadClientes_edtLogradouro, 0, 0, 0)
  sizer_13:AddSizer(grid_sizer_13, 0, 0, 0)
  grid_sizer_14:AddWindow(frmCadClientes_labBairro, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_14:AddWindow(frmCadClientes_edtBairro, 0, 0, 0)
  sizer_13:AddSizer(grid_sizer_14, 0, wx.wxLEFT, 4)
  sizer_11:AddSizer(sizer_13, 0, 0, 0)
  grid_sizer_15:AddWindow(frmCadClientes_labCEP, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_15:AddWindow(frmCadClientes_edtCEP, 0, 0, 0)
  sizer_14:AddSizer(grid_sizer_15, 0, 0, 0)
  grid_sizer_16:AddWindow(frmCadClientes_labCidade, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_16:AddWindow(frmCadClientes_edtCidade, 0, 0, 0)
  sizer_14:AddSizer(grid_sizer_16, 0, wx.wxLEFT, 4)
  grid_sizer_17:AddWindow(frmCadClientes_labEstado, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_17:AddWindow(frmCadClientes_edtEstado, 0, 0, 0)
  sizer_14:AddSizer(grid_sizer_17, 0, wx.wxLEFT, 4)
  sizer_11:AddSizer(sizer_14, 1, 0, 0)
  sizer_5:AddSizer(sizer_11, 0, 0, 0)
  grid_sizer_18:AddWindow(frmCadClientes_labPais, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_18:AddWindow(frmCadClientes_edtCodPais, 0, 0, 0)
  sizer_15:AddSizer(grid_sizer_18, 0, 0, 0)
  grid_sizer_20:Add(20, 20, 0, 0, 0)
  grid_sizer_20:AddWindow(frmCadClientes_edtPais, 0, 0, 0)
  sizer_15:AddSizer(grid_sizer_20, 0, wx.wxLEFT, 2)
  grid_sizer_21:Add(20, 20, 0, 0, 0)
  grid_sizer_21:AddWindow(frmCadClientes_btnPPais, 0, 0, 0)
  sizer_15:AddSizer(grid_sizer_21, 0, 0, 0)
  sizer_5:AddSizer(sizer_15, 0, 0, 0)
  grid_sizer_19:AddWindow(frmCadClientes_labProfissao, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_19:AddWindow(frmCadClientes_edtCodProfissao, 0, 0, 0)
  sizer_16:AddSizer(grid_sizer_19, 0, 0, 0)
  grid_sizer_22:Add(20, 20, 0, 0, 0)
  grid_sizer_22:AddWindow(frmCadClientes_edtProfissao, 0, 0, 0)
  sizer_16:AddSizer(grid_sizer_22, 0, wx.wxLEFT, 2)
  grid_sizer_23:Add(20, 20, 0, 0, 0)
  grid_sizer_23:AddWindow(frmCadClientes_btnPProfissao, 0, 0, 0)
  sizer_16:AddSizer(grid_sizer_23, 0, 0, 0)
  sizer_5:AddSizer(sizer_16, 0, 0, 0)
  sizer_3:AddSizer(sizer_5, 0, 0, 0)
  sizer_4:AddWindow(frmCadastros_btnPesquisar, 0, wx.wxALL + 
    wx.wxALIGN_RIGHT, 2)
  sizer_4:AddWindow(frmCadastros_btnAnterior, 0, wx.wxALL + 
    wx.wxALIGN_RIGHT, 2)
  sizer_4:AddWindow(frmCadastros_btnProximo, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_3:AddSizer(sizer_4, 1, 0, 0)
  sizer_1:AddSizer(sizer_3, 1, wx.wxALL + wx.wxEXPAND, 4)
  sizer_2:AddWindow(frmCadastros_btnSalvar, 0, wx.wxALL + wx.wxALIGN_RIGHT + 
    wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnExcluir, 0, wx.wxALL + wx.wxALIGN_RIGHT + 
    wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnLimpar, 0, wx.wxALL + wx.wxALIGN_RIGHT + 
    wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnFechar, 0, wx.wxALL + wx.wxALIGN_RIGHT + 
    wx.wxALIGN_BOTTOM, 2)
  sizer_1:AddSizer(sizer_2, 0, wx.wxRIGHT + wx.wxBOTTOM + wx.wxALIGN_RIGHT + 
    wx.wxALIGN_BOTTOM, 4)
  parent:SetAutoLayout(true)
  parent:SetSizer(sizer_1)
  sizer_1:Fit(parent)
  sizer_1:SetSizeHints(parent)
end

function frmCadClientes_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo:GetValue(),
    STR_CODNINF) then
    return false
  end
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao:GetValue(),
      STR_CLININF) then
    	return false
    end
    if Rotinas_ValidaCampo(frmCadClientes_edtEmail:GetValue(),
      STR_EMAILNINF) then
    	return false
    end
    if Rotinas_ValidaCampo(frmCadClientes_edtTelefone:GetValue(),
      STR_TELNINF) then
    	return false
    end
    if Rotinas_ValidaCampo(frmCadClientes_edtCodEndereco:GetValue(),
      STR_ENDNINF) then
    	return false
    end
    if Rotinas_ValidaCampo(frmCadClientes_edtCodPais:GetValue(),
      STR_PAISNINF) then
    	return false
    end
    if Rotinas_ValidaCampo(frmCadClientes_edtCodProfissao:GetValue(),
      STR_PROFNINF) then
    	return false
    end
  end
	return True
end

function frmCadClientes_InformaLimpaDados(bInformar)
  if bInformar then
    frmCadClientes_edtEmail:SetValue("2")
    frmCadClientes_edtIdentidade:SetValue("3")
    --if Campos(4) = "M" then
      frmCadClientes_rbSexo:SetSelection(0)
    --else
    --  frmCadClientes_rbSexo:SetSelection(1)
    --end
    frmCadClientes_edtTelefone:SetValue("5")
    frmCadClientes_edtDtNasc:SetValue("25/05/2005")
    frmCadClientes_edtCodEndereco:SetValue("7")
    frmCadClientes_edtLogradouro:SetValue("8")
    frmCadClientes_edtBairro:SetValue("9")
    frmCadClientes_edtCEP:SetValue("10")
    frmCadClientes_edtCidade:SetValue("11")
    frmCadClientes_edtEstado:SetValue("12")
    frmCadClientes_edtCodPais:SetValue("13")
    frmCadClientes_edtPais:SetValue("14")
    frmCadClientes_edtCodProfissao:SetValue("15")
    frmCadClientes_edtProfissao:SetValue("16")
  else
    frmCadClientes_edtEmail:Clear()
    frmCadClientes_edtIdentidade:Clear()
    frmCadClientes_rbSexo:SetSelection(0)
    frmCadClientes_edtTelefone:Clear()
    frmCadClientes_edtDtNasc:Clear()
    frmCadClientes_edtCodEndereco:Clear()
    frmCadClientes_edtLogradouro:Clear()
    frmCadClientes_edtBairro:Clear()
    frmCadClientes_edtCEP:Clear()
    frmCadClientes_edtCidade:Clear()
    frmCadClientes_edtEstado:Clear()
    frmCadClientes_edtCodPais:Clear()
    frmCadClientes_edtPais:Clear()
    frmCadClientes_edtCodProfissao:Clear()
    frmCadClientes_edtProfissao:Clear()
    frmCadastros_edtCodigo:SetFocus()
  end
end 

function frmCadClientes_HabilitaDados(bHabilita)
  frmCadClientes_edtEmail:Enable(bHabilita)
  frmCadClientes_edtIdentidade:Enable(bHabilita)
  frmCadClientes_rbSexo:Enable(bHabilita)
  frmCadClientes_edtTelefone:Enable(bHabilita)
  frmCadClientes_edtDtNasc:Enable(bHabilita)
  frmCadClientes_edtCodEndereco:Enable(bHabilita)
  frmCadClientes_btnPEndereco:Enable(bHabilita)
  frmCadClientes_edtCodPais:Enable(bHabilita)
  frmCadClientes_btnPPais:Enable(bHabilita)
  frmCadClientes_edtCodProfissao:Enable(bHabilita)
  frmCadClientes_btnPProfissao:Enable(bHabilita)
end
