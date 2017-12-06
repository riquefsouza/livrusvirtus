option explicit

dim common frmConEditoras

function frmConEditoras_Criar(parent)
  dim fConEditoras = frmConsultas_Criar(parent)

  fConEditoras.SetTitle(STR_CONEDITORA)
  frmConsultas_labDescricao.SetLabel("Editora: ")
  frmConsultas_gridConsulta.DeleteColumn(1)
  frmConsultas_gridConsulta.InsertColumnInfo(1, "Editora", 0, 220)

  Connect( fConEditoras, wxEVT_CLOSE_WINDOW, "frmConEditoras_OnClose" )
  Connect( fConEditoras, ID_FRMCONSULTAS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConEditoras_OnBtnPesquisar" )
  Connect( fConEditoras, ID_FRMCONSULTAS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConEditoras_OnBtnLimpar" )
  Connect( fConEditoras, ID_FRMCONSULTAS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConEditoras_OnBtnFechar" )
  'Connect( fConEditoras, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_ITEM_SELECTED, "frmConEditoras_OnListItemSelected" )
  'Connect( fConEditoras, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, "frmConEditoras_OnListColRightClick" )

  return fConEditoras
end function

function frmConEditoras_OnClose( event )
  frmConsultas_Fecha(frmConEditoras, MNU_CON_EDITORAS)
  event.Skip()
end function

function frmConEditoras_OnBtnFechar( event )
  frmConsultas_Fecha(frmConEditoras, 0)
  event.Skip()
end function

function frmConEditoras_OnBtnLimpar( event )
  frmConsultas_LimparDados()
  event.Skip()
end function

function frmConEditoras_OnBtnPesquisar( event )
  frmConsultas_PesquisarDados(ConsSQL_Editora("S","", 
    frmConsultas_edtDescricao.GetValue()), STR_EDTNENC, 2)
  event.Skip()
end function

function frmConEditoras_OnListItemSelected( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function

function frmConEditoras_OnListColRightClick( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function
