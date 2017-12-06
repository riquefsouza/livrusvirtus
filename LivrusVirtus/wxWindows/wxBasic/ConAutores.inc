option explicit

dim common frmConAutores

function frmConAutores_Criar(parent)
  dim fConAutores = frmConsultas_Criar(parent)

  fConAutores.SetTitle(STR_CONAUTOR)
  frmConsultas_labDescricao.SetLabel("Autor: ")
  frmConsultas_gridConsulta.DeleteColumn(1)
  frmConsultas_gridConsulta.InsertColumnInfo(1, "Autor", 0, 220)

  Connect( fConAutores, wxEVT_CLOSE_WINDOW, "frmConAutores_OnClose" )
  Connect( fConAutores, ID_FRMCONSULTAS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConAutores_OnBtnPesquisar" )
  Connect( fConAutores, ID_FRMCONSULTAS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConAutores_OnBtnLimpar" )
  Connect( fConAutores, ID_FRMCONSULTAS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConAutores_OnBtnFechar" )
  'Connect( fConAutores, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_ITEM_SELECTED, "frmConAutores_OnListItemSelected" )
  'Connect( fConAutores, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, "frmConAutores_OnListColRightClick" )

  return fConAutores
end function

function frmConAutores_OnClose( event )
  frmConsultas_Fecha(frmConAutores, MNU_CON_AUTORES)
  event.Skip()
end function

function frmConAutores_OnBtnFechar( event )
  frmConsultas_Fecha(frmConAutores, 0)
  event.Skip()
end function

function frmConAutores_OnBtnLimpar( event )
  frmConsultas_LimparDados()
  event.Skip()
end function

function frmConAutores_OnBtnPesquisar( event )
  frmConsultas_PesquisarDados(ConsSQL_Autor("S","", 
    frmConsultas_edtDescricao.GetValue()), STR_AUTNENC, 2)
  event.Skip()
end function

function frmConAutores_OnListItemSelected( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function

function frmConAutores_OnListColRightClick( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function
