ID_FRMCONASSUNTOS = 507

local frmConAssuntos

function frmConAssuntos_Criar(parent)
  local fConAssuntos = frmConsultas_Criar(parent, ID_FRMCONASSUNTOS)

  fConAssuntos:SetTitle(STR_CONASSUNTO)
  frmConsultas_labDescricao:SetLabel("Assunto: ")
  frmConsultas_gridConsulta:SetColLabelValue(1, "Assunto")

  fConAssuntos:ConnectEvent(ID_FRMCADASSUNTOS, wx.wxEVT_CLOSE_WINDOW,
    function (event)
      frmConsultas_Fecha(fConAssuntos, MNU_CON_ASSUNTOS)
      event:Skip()
    end )

  fConAssuntos:ConnectEvent(ID_FRMCONSULTAS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_Fecha(fConAssuntos, 0)
      event:Skip()
    end )

  fConAssuntos:ConnectEvent(ID_FRMCONSULTAS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_LimparDados()
      event:Skip()
    end )

  fConAssuntos:ConnectEvent(ID_FRMCONSULTAS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_PesquisarDados(ConsSQL_Assunto("S","", 
        frmConsultas_edtDescricao.GetValue()), STR_ASSNENC, 2)
      event:Skip()
    end )

  fConAssuntos:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_SELECT_CELL,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  fConAssuntos:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_LABEL_LEFT_CLICK,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  return fConAssuntos
end
