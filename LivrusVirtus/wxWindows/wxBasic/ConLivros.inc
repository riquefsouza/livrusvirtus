option explicit

dim common frmConLivros

function frmConLivros_Criar(parent)
  dim fConLivros = frmConsultas_Criar(parent)

  fConLivros.SetTitle(STR_CONLIVRO)
  frmConsultas_labDescricao.SetLabel("Livro: ")
  frmConsultas_gridConsulta.DeleteColumn(0)
  frmConsultas_gridConsulta.InsertColumnInfo(0, "ISBN", 0, 100)
  frmConsultas_gridConsulta.DeleteColumn(1)
  frmConsultas_gridConsulta.InsertColumnInfo(1, "Título", 0, 220)

  dim nLargura[10] 
  nLargura[0] = 80
  nLargura[1] = 90
  nLargura[2] = 80
  nLargura[3] = 80
  nLargura[4] = 100
  nLargura[5] = 80
  nLargura[6] = 100
  nLargura[7] = 80
  nLargura[8] = 80
  nLargura[9] = 80 
  dim sRotulos[10]
  sRotulos[0] = "Edição"
  sRotulos[1] = "AnoPublicação"
  sRotulos[2] = "Volume"
  sRotulos[3] = "CodEditora"
  sRotulos[4] = "Editora"
  sRotulos[5] = "CodIdioma"
  sRotulos[6] = "Idioma"
  sRotulos[7] = "NumPáginas"
  sRotulos[8] = "Preço"
  sRotulos[9] = "Estoque" 
  Rotinas_AdicionaColunasGrid(frmConsultas_gridConsulta, 2, 10,  
    nLargura[], sRotulos[])

  Connect( fConLivros, wxEVT_CLOSE_WINDOW, "frmConLivros_OnClose" )
  Connect( fConLivros, ID_FRMCONSULTAS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConLivros_OnBtnPesquisar" )
  Connect( fConLivros, ID_FRMCONSULTAS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConLivros_OnBtnLimpar" )
  Connect( fConLivros, ID_FRMCONSULTAS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConLivros_OnBtnFechar" )
  'Connect( fConLivros, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_ITEM_SELECTED, "frmConLivros_OnListItemSelected" )
  'Connect( fConLivros, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, "frmConLivros_OnListColRightClick" )

  return fConLivros
end function

function frmConLivros_OnClose( event )
  frmConsultas_Fecha(frmConLivros, MNU_CON_LIVROS)
  event.Skip()
end function

function frmConLivros_OnBtnFechar( event )
  frmConsultas_Fecha(frmConLivros, 0)
  event.Skip()
end function

function frmConLivros_OnBtnLimpar( event )
  frmConsultas_LimparDados()
  event.Skip()
end function

function frmConLivros_OnBtnPesquisar( event )
  frmConsultas_PesquisarDados(ConsSQL_Livro("S","", 
    frmConsultas_edtDescricao.GetValue(),
    "","","","","","","",""), STR_LIVNENC, 12)
  event.Skip()
end function

function frmConLivros_OnListItemSelected( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function

function frmConLivros_OnListColRightClick( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function
