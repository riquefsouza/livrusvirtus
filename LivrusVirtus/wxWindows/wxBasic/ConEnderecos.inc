option explicit

dim common frmConEnderecos

function frmConEnderecos_Criar(parent)
  dim fConEnderecos = frmConsultas_Criar(parent)

  fConEnderecos.SetTitle(STR_CONENDERECO)
  frmConsultas_labDescricao.SetLabel("Endereço: ")
  frmConsultas_gridConsulta.DeleteColumn(1)
  frmConsultas_gridConsulta.InsertColumnInfo(1, "Logradouro", 0, 220)

  dim nLargura[4] 
  nLargura[0] = 150
  nLargura[1] = 80
  nLargura[2] = 100
  nLargura[3] = 80
  dim sRotulos[4] 
  sRotulos[0] = "Bairro"
  sRotulos[1] = "CEP"
  sRotulos[2] = "Cidade"
  sRotulos[3] = "Estado"
  Rotinas_AdicionaColunasGrid(frmConsultas_gridConsulta, 2, 4, 
    nLargura[], sRotulos[])

  Connect( fConEnderecos, wxEVT_CLOSE_WINDOW, "frmConEnderecos_OnClose" )
  Connect( fConEnderecos, ID_FRMCONSULTAS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConEnderecos_OnBtnPesquisar" )
  Connect( fConEnderecos, ID_FRMCONSULTAS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConEnderecos_OnBtnLimpar" )
  Connect( fConEnderecos, ID_FRMCONSULTAS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConEnderecos_OnBtnFechar" )
  'Connect( fConEnderecos, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_ITEM_SELECTED, "frmConEnderecos_OnListItemSelected" )
  'Connect( fConEnderecos, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, "frmConEnderecos_OnListColRightClick" )

  return fConEnderecos
end function

function frmConEnderecos_OnClose( event )
  frmConsultas_Fecha(frmConEnderecos, MNU_CON_ENDERECOS)
  event.Skip()
end function

function frmConEnderecos_OnBtnFechar( event )
  frmConsultas_Fecha(frmConEnderecos, 0)
  event.Skip()
end function

function frmConEnderecos_OnBtnLimpar( event )
  frmConsultas_LimparDados()
  event.Skip()
end function

function frmConEnderecos_OnBtnPesquisar( event )
  frmConsultas_PesquisarDados(ConsSQL_Endereco("S","", 
    frmConsultas_edtDescricao.GetValue(),"","","",""), STR_ENDNENC, 6)
  event.Skip()
end function

function frmConEnderecos_OnListItemSelected( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function

function frmConEnderecos_OnListColRightClick( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function
