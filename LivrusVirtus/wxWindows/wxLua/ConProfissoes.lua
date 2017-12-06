ID_FRMCONPROFISSOES = 507

local frmConProfissoes

function frmConProfissoes_Criar(parent)
  local fConProfissoes = frmConsultas_Criar(parent, ID_FRMCONPROFISSOES)

  fConProfissoes:SetTitle(STR_CONPROFISS)
  frmConsultas_labDescricao:SetLabel("Profissão: ")
  frmConsultas_gridConsulta:SetColLabelValue(1, "Profissão")

  fConProfissoes:ConnectEvent(ID_FRMCADPROFISSOES, wx.wxEVT_CLOSE_WINDOW,
    function (event)
      frmConsultas_Fecha(fConProfissoes, MNU_CON_PROFISSOES)
      event:Skip()
    end )

  fConProfissoes:ConnectEvent(ID_FRMCONSULTAS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_Fecha(fConProfissoes, 0)
      event:Skip()
    end )

  fConProfissoes:ConnectEvent(ID_FRMCONSULTAS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_LimparDados()
      event:Skip()
    end )

  fConProfissoes:ConnectEvent(ID_FRMCONSULTAS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_PesquisarDados(ConsSQL_Profissao("S","", 
        frmConsultas_edtDescricao.GetValue()), STR_PROFNENC, 2)
      event:Skip()
    end )

  fConProfissoes:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_SELECT_CELL,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  fConProfissoes:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_LABEL_LEFT_CLICK,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  return fConProfissoes
end
