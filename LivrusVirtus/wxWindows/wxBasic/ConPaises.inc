option explicit

dim common frmConPaises

function frmConPaises_Criar(parent)
  dim fConPaises = frmConsultas_Criar(parent)

  fConPaises.SetTitle(STR_CONPAIS)
  frmConsultas_labDescricao.SetLabel("País: ")
  frmConsultas_gridConsulta.DeleteColumn(1)
  frmConsultas_gridConsulta.InsertColumnInfo(1, "País", 0, 220)

  Connect( fConPaises, wxEVT_CLOSE_WINDOW, "frmConPaises_OnClose" )
  Connect( fConPaises, ID_FRMCONSULTAS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConPaises_OnBtnPesquisar" )
  Connect( fConPaises, ID_FRMCONSULTAS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConPaises_OnBtnLimpar" )
  Connect( fConPaises, ID_FRMCONSULTAS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConPaises_OnBtnFechar" )
  'Connect( fConPaises, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_ITEM_SELECTED, "frmConPaises_OnListItemSelected" )
  'Connect( fConPaises, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, "frmConPaises_OnListColRightClick" )

  return fConPaises
end function

function frmConPaises_OnClose( event )
  frmConsultas_Fecha(frmConPaises, MNU_CON_PAISES)
  event.Skip()
end function

function frmConPaises_OnBtnFechar( event )
  frmConsultas_Fecha(frmConPaises, 0)
  event.Skip()
end function

function frmConPaises_OnBtnLimpar( event )
  frmConsultas_LimparDados()
  event.Skip()
end function

function frmConPaises_OnBtnPesquisar( event )
  frmConsultas_PesquisarDados(ConsSQL_Pais("S","", 
    frmConsultas_edtDescricao.GetValue()), STR_PAISNENC, 2)
  event.Skip()
end function

function frmConPaises_OnListItemSelected( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function

function frmConPaises_OnListColRightClick( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function
