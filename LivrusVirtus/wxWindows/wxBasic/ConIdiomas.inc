option explicit

dim common frmConIdiomas

function frmConIdiomas_Criar(parent)
  dim fConIdiomas = frmConsultas_Criar(parent)

  fConIdiomas.SetTitle(STR_CONIDIOMA)
  frmConsultas_labDescricao.SetLabel("Idioma: ")
  frmConsultas_gridConsulta.DeleteColumn(1)
  frmConsultas_gridConsulta.InsertColumnInfo(1, "Idioma", 0, 220)

  Connect( fConIdiomas, wxEVT_CLOSE_WINDOW, "frmConIdiomas_OnClose" )
  Connect( fConIdiomas, ID_FRMCONSULTAS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConIdiomas_OnBtnPesquisar" )
  Connect( fConIdiomas, ID_FRMCONSULTAS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConIdiomas_OnBtnLimpar" )
  Connect( fConIdiomas, ID_FRMCONSULTAS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConIdiomas_OnBtnFechar" )
  'Connect( fConIdiomas, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_ITEM_SELECTED, "frmConIdiomas_OnListItemSelected" )
  'Connect( fConIdiomas, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, "frmConIdiomas_OnListColRightClick" )

  return fConIdiomas
end function

function frmConIdiomas_OnClose( event )
  frmConsultas_Fecha(frmConIdiomas, MNU_CON_IDIOMAS)
  event.Skip()
end function

function frmConIdiomas_OnBtnFechar( event )
  frmConsultas_Fecha(frmConIdiomas, 0)
  event.Skip()
end function

function frmConIdiomas_OnBtnLimpar( event )
  frmConsultas_LimparDados()
  event.Skip()
end function

function frmConIdiomas_OnBtnPesquisar( event )
  frmConsultas_PesquisarDados(ConsSQL_Idioma("S","", 
    frmConsultas_edtDescricao.GetValue()), STR_IDINENC, 2)
  event.Skip()
end function

function frmConIdiomas_OnListItemSelected( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function

function frmConIdiomas_OnListColRightClick( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function
