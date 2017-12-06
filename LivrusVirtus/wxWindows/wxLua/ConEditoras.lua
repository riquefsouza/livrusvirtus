ID_FRMCONEDITORAS = 507

local frmConEditoras

function frmConEditoras_Criar(parent)
  local fConEditoras = frmConsultas_Criar(parent, ID_FRMCONEDITORAS)

  fConEditoras:SetTitle(STR_CONEDITORA)
  frmConsultas_labDescricao:SetLabel("Editora: ")
  frmConsultas_gridConsulta:SetColLabelValue(1, "Editora")

  fConEditoras:ConnectEvent(ID_FRMCADEDITORAS, wx.wxEVT_CLOSE_WINDOW,
    function (event)
      frmConsultas_Fecha(fConEditoras, MNU_CON_EDITORAS)
      event:Skip()
    end )

  fConEditoras:ConnectEvent(ID_FRMCONSULTAS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_Fecha(fConEditoras, 0)
      event:Skip()
    end )

  fConEditoras:ConnectEvent(ID_FRMCONSULTAS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_LimparDados()
      event:Skip()
    end )

  fConEditoras:ConnectEvent(ID_FRMCONSULTAS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_PesquisarDados(ConsSQL_Editora("S","", 
        frmConsultas_edtDescricao.GetValue()), STR_EDTNENC, 2)
      event:Skip()
    end )

  fConEditoras:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_SELECT_CELL,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  fConEditoras:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_LABEL_LEFT_CLICK,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  return fConEditoras
end
