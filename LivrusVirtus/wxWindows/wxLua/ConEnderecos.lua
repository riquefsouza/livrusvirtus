ID_FRMCONENDERECOS = 507

local frmConEnderecos

function frmConEnderecos_Criar(parent)
  local fConEnderecos = frmConsultas_Criar(parent, ID_FRMCONENDERECOS)

  fConEnderecos:SetTitle(STR_CONENDERECO)
  frmConsultas_labDescricao:SetLabel("Endereço: ")
  frmConsultas_gridConsulta:SetColLabelValue(1, "Logradouro")
  frmConsultas_gridConsulta:SetColSize(1, 200)
 
  nLargura = { 150,80,100,80 }
  sRotulos = { "Bairro", "CEP", "Cidade", "Estado" }
  Rotinas_AdicionaColunasGrid(frmConsultas_gridConsulta, 2, 4, 
    nLargura, sRotulos)

  fConEnderecos:ConnectEvent(ID_FRMCADENDERECOS, wx.wxEVT_CLOSE_WINDOW,
    function (event)
      frmConsultas_Fecha(fConEnderecos, MNU_CON_ENDERECOS)
      event:Skip()
    end )

  fConEnderecos:ConnectEvent(ID_FRMCONSULTAS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_Fecha(fConEnderecos, 0)
      event:Skip()
    end )

  fConEnderecos:ConnectEvent(ID_FRMCONSULTAS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_LimparDados()
      event:Skip()
    end )

  fConEnderecos:ConnectEvent(ID_FRMCONSULTAS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_PesquisarDados(ConsSQL_Endereco("S","", 
        frmConsultas_edtDescricao.GetValue(),"","","",""), STR_ENDNENC, 6)
      event:Skip()
    end )

  fConEnderecos:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_SELECT_CELL,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  fConEnderecos:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_LABEL_LEFT_CLICK,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  return fConEnderecos
end
