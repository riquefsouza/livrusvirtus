ID_FRMCONIDIOMAS = 507

local frmConIdiomas

function frmConIdiomas_Criar(parent)
  local fConIdiomas = frmConsultas_Criar(parent, ID_FRMCONIDIOMAS)

  fConIdiomas:SetTitle(STR_CONIDIOMA)
  frmConsultas_labDescricao:SetLabel("Idioma: ")
  frmConsultas_gridConsulta:SetColLabelValue(1, "Idioma")

  fConIdiomas:ConnectEvent(ID_FRMCADIDIOMAS, wx.wxEVT_CLOSE_WINDOW,
    function (event)
      frmConsultas_Fecha(fConIdiomas, MNU_CON_IDIOMAS)
      event:Skip()
    end )

  fConIdiomas:ConnectEvent(ID_FRMCONSULTAS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_Fecha(fConIdiomas, 0)
      event:Skip()
    end )

  fConIdiomas:ConnectEvent(ID_FRMCONSULTAS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_LimparDados()
      event:Skip()
    end )

  fConIdiomas:ConnectEvent(ID_FRMCONSULTAS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_PesquisarDados(ConsSQL_Idioma("S","", 
        frmConsultas_edtDescricao.GetValue()), STR_IDINENC, 2)
      event:Skip()
    end )

  fConIdiomas:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_SELECT_CELL,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  fConIdiomas:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_LABEL_LEFT_CLICK,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  return fConIdiomas
end
