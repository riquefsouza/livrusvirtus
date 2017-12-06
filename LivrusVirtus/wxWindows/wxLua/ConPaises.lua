ID_FRMCONPAISES = 507

local frmConPaises

function frmConPaises_Criar(parent)
  local fConPaises = frmConsultas_Criar(parent, ID_FRMCONPAISES)

  fConPaises:SetTitle(STR_CONPAIS)
  frmConsultas_labDescricao:SetLabel("País: ")
  frmConsultas_gridConsulta:SetColLabelValue(1, "País")

  fConPaises:ConnectEvent(ID_FRMCADPAISES, wx.wxEVT_CLOSE_WINDOW,
    function (event)
      frmConsultas_Fecha(fConPaises, MNU_CON_PAISES)
      event:Skip()
    end )

  fConPaises:ConnectEvent(ID_FRMCONSULTAS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_Fecha(fConPaises, 0)
      event:Skip()
    end )

  fConPaises:ConnectEvent(ID_FRMCONSULTAS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_LimparDados()
      event:Skip()
    end )

  fConPaises:ConnectEvent(ID_FRMCONSULTAS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_PesquisarDados(ConsSQL_Pais("S","", 
        frmConsultas_edtDescricao.GetValue()), STR_PAISNENC, 2)
      event:Skip()
    end )

  fConPaises:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_SELECT_CELL,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  fConPaises:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_LABEL_LEFT_CLICK,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  return fConPaises
end
