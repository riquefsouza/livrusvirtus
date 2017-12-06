option explicit

dim common frmConClientes

function frmConClientes_Criar(parent)
  dim fConClientes = frmConsultas_Criar(parent)

  fConClientes.SetTitle(STR_CONCLIENTE)
  frmConsultas_labDescricao.SetLabel("Cliente: ")
  frmConsultas_gridConsulta.DeleteColumn(0)
  frmConsultas_gridConsulta.InsertColumnInfo(0, "CPF", 0, 100)
  frmConsultas_gridConsulta.DeleteColumn(1)
  frmConsultas_gridConsulta.InsertColumnInfo(1, "Nome", 0, 220)

  dim nLargura[15] 
  nLargura[0] = 180
  nLargura[1] = 80
  nLargura[2] = 40
  nLargura[3] = 80
  nLargura[4] = 120
  nLargura[5] = 80
  nLargura[6] = 220
  nLargura[7] = 150
  nLargura[8] = 80
  nLargura[9] = 100
  nLargura[10] = 100
  nLargura[11] = 80
  nLargura[12] = 180
  nLargura[13] = 80
  nLargura[14] = 100

  dim sRotulos[15] 
  sRotulos[0] = "Email"
  sRotulos[1] = "Identidade"
  sRotulos[2] = "Sexo"
  sRotulos[3] = "Telefone"
  sRotulos[4] = "DtNascimento"
  sRotulos[5] = "CodEndereço"
  sRotulos[6] = "Logradouro"
  sRotulos[7] = "Bairro"
  sRotulos[8] = "CEP"
  sRotulos[9] = "Cidade"
  sRotulos[10] = "Estado"
  sRotulos[11] = "CodPaís"
  sRotulos[12] = "País"
  sRotulos[13] = "CodProfissão"
  sRotulos[14] = "Profissão"

  Rotinas_AdicionaColunasGrid(frmConsultas_gridConsulta, 2, 15, 
    nLargura[], sRotulos[])

  Connect( fConClientes, wxEVT_CLOSE_WINDOW, "frmConClientes_OnClose" )
  Connect( fConClientes, ID_FRMCONSULTAS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConClientes_OnBtnPesquisar" )
  Connect( fConClientes, ID_FRMCONSULTAS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConClientes_OnBtnLimpar" )
  Connect( fConClientes, ID_FRMCONSULTAS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConClientes_OnBtnFechar" )
  'Connect( fConClientes, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_ITEM_SELECTED, "frmConClientes_OnListItemSelected" )
  'Connect( fConClientes, ID_FRMCONSULTAS_GRIDCONSULTA, 
  '  wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, "frmConClientes_OnListColRightClick" )

  return fConClientes
end function

function frmConClientes_OnClose( event )
  frmConsultas_Fecha(frmConClientes, MNU_CON_CLIENTES)
  event.Skip()
end function

function frmConClientes_OnBtnFechar( event )
  frmConsultas_Fecha(frmConClientes, 0)
  event.Skip()
end function

function frmConClientes_OnBtnLimpar( event )
  frmConsultas_LimparDados()
  event.Skip()
end function

function frmConClientes_OnBtnPesquisar( event )
  frmConsultas_PesquisarDados(ConsSQL_Cliente("S","", 
    frmConsultas_edtDescricao.GetValue(),"","","","","","","",""), 
    STR_CLINENC, 17)
  event.Skip()
end function

function frmConClientes_OnListItemSelected( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function

function frmConClientes_OnListColRightClick( event )
  frmConsultas_setLabRegistros(event.GetIndex())
  event.Skip()
end function
