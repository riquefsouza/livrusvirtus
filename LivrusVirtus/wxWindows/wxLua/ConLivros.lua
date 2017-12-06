ID_FRMCONLIVROS = 507

local frmConLivros

function frmConLivros_Criar(parent)
  local fConLivros = frmConsultas_Criar(parent, ID_FRMCONLIVROS)

  fConLivros:SetTitle(STR_CONLIVRO)
  frmConsultas_labDescricao:SetLabel("Livro: ")
  frmConsultas_gridConsulta:SetColLabelValue(0, "ISBN")
  frmConsultas_gridConsulta:SetColSize(0, 80)
  frmConsultas_gridConsulta:SetColLabelValue(1, "Título")
  frmConsultas_gridConsulta:SetColSize(1, 180)

  nLargura = { 80,90,80,80,100,80,100,80,80,80 }
  sRotulos = { "Edição", "AnoPublicação", 
    "Volume", "CodEditora", "Editora", "CodIdioma", "Idioma", 
    "NumPáginas", "Preço", "Estoque" }
  Rotinas_AdicionaColunasGrid(frmConsultas_gridConsulta, 2, 10,  
    nLargura, sRotulos)

  fConLivros:ConnectEvent(ID_FRMCADLIVROS, wx.wxEVT_CLOSE_WINDOW,
    function (event)
      frmConsultas_Fecha(fConLivros, MNU_CON_LIVROS)
      event:Skip()
    end )

  fConLivros:ConnectEvent(ID_FRMCONSULTAS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_Fecha(fConLivros, 0)
      event:Skip()
    end )

  fConLivros:ConnectEvent(ID_FRMCONSULTAS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_LimparDados()
      event:Skip()
    end )

  fConLivros:ConnectEvent(ID_FRMCONSULTAS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmConsultas_PesquisarDados(ConsSQL_Livro("S","", 
        frmConsultas_edtDescricao.GetValue(),
        "","","","","","","",""), STR_LIVNENC, 12)
      event:Skip()
    end )

  fConLivros:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_SELECT_CELL,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  fConLivros:ConnectEvent(ID_FRMCONSULTAS_GRIDCONSULTA,
    wx.wxEVT_GRID_LABEL_LEFT_CLICK,
    function (event)
      frmConsultas_setLabRegistros(event:GetRow())
      event:Skip()
    end )

  return fConLivros
end
