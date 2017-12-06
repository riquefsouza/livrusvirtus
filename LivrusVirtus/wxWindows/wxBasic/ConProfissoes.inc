option explicit

dim common frmConProfissoes

function frmConProfissoes_Criar(parent)
  dim fConProfissoes = frmConsultas_Criar(parent)

  fConProfissoes.SetTitle(STR_CONPROFISS)
  frmConsultas_labDescricao.SetLabel("Profissão: ")
  frmConsultas_gridConsulta.DeleteColumn(1)
  frmConsultas_gridConsulta.InsertColumnInfo(1, "Profissão", 0, 220)

  Connect( fConProfissoes, wxEVT_CLOSE_WINDOW, "frmConProfissoes_OnClose" )
  Connect( fConProfissoes, ID_FRMCONSULTAS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConProfissoes_OnBtnPesquisar" )
  Connect( fConProfissoes, ID_FRMCONSULTAS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConProfissoes_OnBtnLimpar" )
  Connect( fConProfissoes, ID_FRMCONSULTAS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConProfissoes_OnBtnFechar" )
  'Connect( fConProfissoes, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_ITEM_SELECTED, "frmConProfissoes_OnListItemSelected" )
  'Connect( fConProfissoes, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, "frmConProfissoes_OnListColRightClick" )

  return fConProfissoes
end function

function frmConProfissoes_OnClose( event )
  frmConsultas_Fecha(frmConProfissoes, MNU_CON_PROFISSOES)
  event.Skip()
end function

function frmConProfissoes_OnBtnFechar( event )
  frmConsultas_Fecha(frmConProfissoes, 0)
  event.Skip()
end function

function frmConProfissoes_OnBtnLimpar( event )
  frmConsultas_LimparDados()
  event.Skip()
end function

function frmConProfissoes_OnBtnPesquisar( event )
  frmConsultas_PesquisarDados(ConsSQL_Profissao("S","", 
    frmConsultas_edtDescricao.GetValue()), STR_PROFNENC, 2)
  event.Skip()
end function

function frmConProfissoes_OnListItemSelected( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function

function frmConProfissoes_OnListColRightClick( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function
