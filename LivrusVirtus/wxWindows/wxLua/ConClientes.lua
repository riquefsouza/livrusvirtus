ID_FRMCONCLIENTES = 507

local frmConClientes

function frmConClientes_Criar(parent)
  local fConClientes = frmConsultas_Criar(parent, ID_FRMCONCLIENTES)

  fConClientes:SetTitle(STR_CONCLIENTE)
  frmConsultas_labDescricao:SetLabel("Cliente: ")
  frmConsultas_gridConsulta:SetColLabelValue(1, "Cliente")
  frmConsultas_gridConsulta:SetColLabelValue(0, "CPF")
  frmConsultas_gridConsulta:SetColSize(0, 90)
  frmConsultas_gridConsulta:SetColLabelValue(1, "Nome")
  frmConsultas_gridConsulta:SetColSize(1, 220)
  
  nLargura = { 180,80,40,80,120,80,220,150, 
    80,100,100,80,180,80,100 }
  sRotulos = { "Email", "Identidade", "Sexo", 
   "Telefone", "DtNascimento", "CodEndereço", "Logradouro", 
   "Bairro", "CEP", "Cidade", "Estado", "CodPaís", "País", 
   "CodProfissão", "Profissão" }
  Rotinas_AdicionaColunasGrid( frmConsultas_gridConsulta, 2, 15, 
    nLargura, sRotulos)

  fConClientes:ConnectEvent(ID_FRMCADCLIENTES, wx.wxEVT_CLOSE_WINDOW,
    function (event)
      frmConsultas_Fecha(fConClientes, MNU_CON_CLIENTES)
      event:Skip()
    end )

  fConClientes:ConnectEvent(ID_FRMCONSULTAS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_Fecha(fConClientes, 0)
      event:Skip()
    end )

  fConClientes:ConnectEvent(ID_FRMCONSULTAS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_LimparDados()
      event:Skip()
    end )

  fConClientes:ConnectEvent(ID_FRMCONSULTAS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_PesquisarDados(ConsSQL_Cliente("S","", 
        frmConsultas_edtDescricao.GetValue()"","","","","","","",""),
        STR_CLINENC, 17)
      event:Skip()
    end )

  fConClientes:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_SELECT_CELL,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  fConClientes:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_LABEL_LEFT_CLICK,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  return fConClientes
end
