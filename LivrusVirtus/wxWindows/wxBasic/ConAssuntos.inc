option explicit

dim common frmConAssuntos

function frmConAssuntos_Criar(parent)
  dim fConAssuntos = frmConsultas_Criar(parent)

  fConAssuntos.SetTitle(STR_CONASSUNTO)
  frmConsultas_labDescricao.SetLabel("Assunto: ")
  frmConsultas_gridConsulta.DeleteColumn(1)
  frmConsultas_gridConsulta.InsertColumnInfo(1, "Assunto", 0, 220)

  Connect( fConAssuntos, wxEVT_CLOSE_WINDOW, "frmConAssuntos_OnClose" )
  Connect( fConAssuntos, ID_FRMCONSULTAS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConAssuntos_OnBtnPesquisar" )
  Connect( fConAssuntos, ID_FRMCONSULTAS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConAssuntos_OnBtnLimpar" )
  Connect( fConAssuntos, ID_FRMCONSULTAS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConAssuntos_OnBtnFechar" )
  'Connect( fConAssuntos, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_ITEM_SELECTED, "frmConAssuntos_OnListItemSelected" )
  'Connect( fConAssuntos, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, "frmConAssuntos_OnListColRightClick" )

  return fConAssuntos
end function

function frmConAssuntos_OnClose( event )
  frmConsultas_Fecha(frmConAssuntos, MNU_CON_ASSUNTOS)
  event.Skip()
end function

function frmConAssuntos_OnBtnFechar( event )
  frmConsultas_Fecha(frmConAssuntos, 0)
  event.Skip()
end function

function frmConAssuntos_OnBtnLimpar( event )
  frmConsultas_LimparDados()
  event.Skip()
end function

function frmConAssuntos_OnBtnPesquisar( event )
  frmConsultas_PesquisarDados(ConsSQL_Assunto("S","", 
    frmConsultas_edtDescricao.GetValue()), STR_ASSNENC, 2)
  event.Skip()
end function

function frmConAssuntos_OnListItemSelected( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function

function frmConAssuntos_OnListColRightClick( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function
