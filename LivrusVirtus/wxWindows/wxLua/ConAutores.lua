ID_FRMCONAUTORES = 507

local frmConAutores

function frmConAutores_Criar(parent)
  local fConAutores = frmConsultas_Criar(parent, ID_FRMCONAUTORES)

  fConAutores:SetTitle(STR_CONAUTOR)
  frmConsultas_labDescricao:SetLabel("Autor: ")
  frmConsultas_gridConsulta:SetColLabelValue(1, "Autor")

  fConAutores:ConnectEvent(ID_FRMCADAUTORES, wx.wxEVT_CLOSE_WINDOW,
    function (event)
      frmConsultas_Fecha(fConAutores, MNU_CON_AUTORES)
      event:Skip()
    end )

  fConAutores:ConnectEvent(ID_FRMCONSULTAS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_Fecha(fConAutores, 0)
      event:Skip()
    end )

  fConAutores:ConnectEvent(ID_FRMCONSULTAS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_LimparDados()
      event:Skip()
    end )

  fConAutores:ConnectEvent(ID_FRMCONSULTAS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_PesquisarDados(ConsSQL_Autor("S","", 
        frmConsultas_edtDescricao.GetValue()), STR_AUTNENC, 2)
      event:Skip()
    end )

  fConAutores:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_SELECT_CELL,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  fConAutores:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_LABEL_LEFT_CLICK,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  return fConAutores
end
