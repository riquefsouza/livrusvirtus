option explicit

function frmPrincipal_Criar()
  dim fPrincipal = new wxMDIParentFrame( 0, -1, STR_TITULO, 
    wxPoint( -1, -1 ), wxSize( 640, 480 ) )
  fPrincipal.Centre()

  'fPrincipal.SetIcon(bmp_livrus)
 
  'Barra de Menu
  frmPrincipal_mnuCadastros = new wxMenu()
  frmPrincipal_mnuCadastros.Append(MNU_CAD_ASSUNTOS, "&Assuntos", STR_CADASSUNTO)
  frmPrincipal_mnuCadastros.Append(MNU_CAD_AUTORES, "A&utores", STR_CADAUTOR)
  frmPrincipal_mnuCadastros.Append(MNU_CAD_EDITORAS, "&Editoras", STR_CADEDITORA)
  frmPrincipal_mnuCadastros.Append(MNU_CAD_ENDERECOS, "E&ndereços", STR_CADENDERECO)
  frmPrincipal_mnuCadastros.Append(MNU_CAD_IDIOMAS, "&Idiomas", STR_CADIDIOMA)
  frmPrincipal_mnuCadastros.Append(MNU_CAD_PAISES, "&Países", STR_CADPAIS)
  frmPrincipal_mnuCadastros.Append(MNU_CAD_PROFISSOES, "P&rofissões", STR_CADPROFISS)
  frmPrincipal_mnuCadastros.AppendSeparator()
  frmPrincipal_mnuCadastros.Append(MNU_CAD_CLIENTES, "&Clientes", STR_CADCLIENTE)
  frmPrincipal_mnuCadastros.Append(MNU_CAD_LIVROS, "&Livros", STR_CADLIVRO)

	frmPrincipal_mnuPesquisas = new wxMenu()
	frmPrincipal_mnuPesquisas.Append(MNU_CON_ASSUNTOS, "&Assuntos", STR_CONASSUNTO)
	frmPrincipal_mnuPesquisas.Append(MNU_CON_AUTORES, "A&utores", STR_CONAUTOR)
	frmPrincipal_mnuPesquisas.Append(MNU_CON_EDITORAS, "&Editoras", STR_CONEDITORA)
	frmPrincipal_mnuPesquisas.Append(MNU_CON_ENDERECOS, "E&ndereços", STR_CONENDERECO)
	frmPrincipal_mnuPesquisas.Append(MNU_CON_IDIOMAS, "&Idiomas", STR_CONIDIOMA)
	frmPrincipal_mnuPesquisas.Append(MNU_CON_PAISES, "&Países", STR_CONPAIS)
	frmPrincipal_mnuPesquisas.Append(MNU_CON_PROFISSOES, "P&rofissões", STR_CONPROFISS)
	frmPrincipal_mnuPesquisas.AppendSeparator()
	frmPrincipal_mnuPesquisas.Append(MNU_CON_CLIENTES, "&Clientes", STR_CONCLIENTE)
	frmPrincipal_mnuPesquisas.Append(MNU_CON_LIVROS, "&Livros", STR_CONLIVRO)

	frmPrincipal_mnuVendas = new wxMenu()
	frmPrincipal_mnuVendas.Append(MNU_VEN_VENDERLIVROS, "&Vender Livros", STR_VENLIVRO)
	frmPrincipal_mnuVendas.Append(MNU_VEN_VENDASREALIZADAS, "Vendas &Realizadas", STR_CONVENLIVRO)

	frmPrincipal_mnuOpcoes = new wxMenu()
	frmPrincipal_mnuOpcoes.Append(MNU_OP_ALTERARSENHA, "&Alterar Senha", STR_ALTSENHA)
	frmPrincipal_mnuOpcoes.AppendSeparator()
	frmPrincipal_mnuOpcoes.Append(MNU_OP_SOBRE, "&Sobre", STR_OPSOBRE)
	frmPrincipal_mnuOpcoes.Append(MNU_OP_SAIR, "Sa&ir"+chr(9)+"Ctrl-S", STR_OPSAIR)

	frmPrincipal_barraMenu = new wxMenuBar()
	frmPrincipal_barraMenu.Append(frmPrincipal_mnuCadastros, "&Cadastros")
	frmPrincipal_barraMenu.Append(frmPrincipal_mnuPesquisas, "&Pesquisas")
	frmPrincipal_barraMenu.Append(frmPrincipal_mnuVendas, "&Vendas")
	frmPrincipal_barraMenu.Append(frmPrincipal_mnuOpcoes, "&Opções")

  fPrincipal.SetMenuBar(frmPrincipal_barraMenu)

  dim bmp_cliente = new wxEmptyBitmap(0,0)
  bmp_cliente.LoadFile("xpms/cliente.xpm", wxBITMAP_TYPE_XPM)
  fPrincipal_tlbCliente = new wxBitmapButton(fPrincipal, MNU_CAD_CLIENTES, 
    bmp_cliente, wxPoint(2,4), wxSize(21,21))

  dim bmp_livro = new wxEmptyBitmap(0,0)
  bmp_livro.LoadFile("xpms/livro.xpm", wxBITMAP_TYPE_XPM)
  fPrincipal_tlbLivro = new wxBitmapButton(fPrincipal, MNU_CAD_LIVROS, 
    bmp_livro, wxPoint(24,4), wxSize(21,21))

  dim bmp_venda = new wxEmptyBitmap(0,0)
  bmp_venda.LoadFile("xpms/livros.xpm", wxBITMAP_TYPE_XPM)
  fPrincipal_tlbVenda = new wxBitmapButton(fPrincipal, MNU_VEN_VENDERLIVROS, 
    bmp_venda, wxPoint(46,4), wxSize(21,21))

  dim bmp_sobre = new wxEmptyBitmap(0,0)
  bmp_sobre.LoadFile("xpms/sobre.xpm", wxBITMAP_TYPE_XPM)
  dim tlbSobre = new wxBitmapButton(fPrincipal, MNU_OP_SOBRE, 
    bmp_sobre, wxPoint(70,4), wxSize(21,21))

  dim bmp_sair = new wxEmptyBitmap(0,0)
  bmp_sair.LoadFile("xpms/sair.xpm", wxBITMAP_TYPE_XPM)
  dim tlbSair = new wxBitmapButton(fPrincipal, MNU_OP_SAIR, 
    bmp_sair, wxPoint(92,4), wxSize(21,21))

  'Barra de ferramentas    
  frmPrincipal_barraFerra = new wxToolBar(fPrincipal, -1, wxPoint(0,0), 
    wxSize(-1,-1), wxTB_HORIZONTAL + wxNO_BORDER)
  fPrincipal.SetToolBar(frmPrincipal_barraFerra)
  frmPrincipal_barraFerra.AddControl(fPrincipal_tlbCliente)
	frmPrincipal_barraFerra.AddControl(fPrincipal_tlbLivro)
	frmPrincipal_barraFerra.AddControl(fPrincipal_tlbVenda)
  frmPrincipal_barraFerra.AddSeparator()
	frmPrincipal_barraFerra.AddControl(tlbSobre)
	frmPrincipal_barraFerra.AddControl(tlbSair)
  frmPrincipal_barraFerra.Realize()

  dim barraStatus = fPrincipal.CreateStatusBar(2)
  dim nLarguras[2]
  nLarguras[0] = 100
  nLarguras[1] = -1
'  barraStatus.SetFieldsCount(2,100)
'  barraStatus.SetStatusWidths(0,100)
'  barraStatus.SetStatusWidths(1,-1)
  barraStatus.SetStatusText(STR_USUARIO, 1)

  return fPrincipal
end function

dim common frmPrincipal = frmPrincipal_Criar()

function frmPrincipal_OnMnuCadAssuntos( event )
  frmPrincipal_mnuCadastros.Enable(MNU_CAD_ASSUNTOS, False)
  dim fCadAssuntos = frmFilha_Criar(frmPrincipal, FRMCADASSUNTOS)
  Connect( fCadAssuntos, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_CAD_ASSUNTOS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuCadAssuntos" )

function frmPrincipal_OnMnuCadAutores( event )
  frmPrincipal_mnuCadastros.Enable(MNU_CAD_AUTORES, False)
  dim fCadAutores = frmFilha_Criar(frmPrincipal, FRMCADAUTORES)
  Connect( fCadAutores, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_CAD_AUTORES, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuCadAutores" )

function frmPrincipal_OnMnuCadEditoras( event )
  frmPrincipal_mnuCadastros.Enable(MNU_CAD_EDITORAS, False)
  dim fCadEditoras = frmFilha_Criar(frmPrincipal, FRMCADEDITORAS)
  Connect( fCadEditoras, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_CAD_EDITORAS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuCadEditoras" )

function frmPrincipal_OnMnuCadEnderecos( event )
  frmPrincipal_mnuCadastros.Enable(MNU_CAD_ENDERECOS, False)
  dim fCadEnderecos = frmFilha_Criar(frmPrincipal, FRMCADENDERECOS)
  Connect( fCadEnderecos, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_CAD_ENDERECOS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuCadEnderecos" )

function frmPrincipal_OnMnuCadIdiomas( event )
  frmPrincipal_mnuCadastros.Enable(MNU_CAD_IDIOMAS, False)
  dim fCadIdiomas = frmFilha_Criar(frmPrincipal, FRMCADIDIOMAS)
  Connect( fCadIdiomas, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_CAD_IDIOMAS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuCadIdiomas" )

function frmPrincipal_OnMnuCadPaises( event )
  frmPrincipal_mnuCadastros.Enable(MNU_CAD_PAISES, False)
  dim fCadPaises = frmFilha_Criar(frmPrincipal, FRMCADPAISES)
  Connect( fCadPaises, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_CAD_PAISES, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuCadPaises" )

function frmPrincipal_OnMnuCadProfissoes( event )
  frmPrincipal_mnuCadastros.Enable(MNU_CAD_PROFISSOES, False)
  dim fCadProfissoes = frmFilha_Criar(frmPrincipal, FRMCADPROFISSOES)
  Connect( fCadProfissoes, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_CAD_PROFISSOES, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuCadProfissoes" )

function frmPrincipal_OnMnuCadClientes( event )
  frmPrincipal_mnuCadastros.Enable(MNU_CAD_CLIENTES, False)
  fPrincipal_tlbCliente.Enable(False)
  dim fCadClientes = frmFilha_Criar(frmPrincipal, FRMCADCLIENTES)
  Connect( fCadClientes, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_CAD_CLIENTES, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuCadClientes" )
connect( frmPrincipal, MNU_CAD_CLIENTES, wxEVT_COMMAND_BUTTON_CLICKED, 
  "frmPrincipal_OnMnuCadClientes" )

function frmPrincipal_OnMnuCadLivros( event )
  frmPrincipal_mnuCadastros.Enable(MNU_CAD_CLIENTES, False)
  fPrincipal_tlbLivro.Enable(False)
  dim fCadLivros = frmFilha_Criar(frmPrincipal, FRMCADLIVROS)
  Connect( fCadLivros, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_CAD_LIVROS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuCadLivros" )
connect( frmPrincipal, MNU_CAD_LIVROS, wxEVT_COMMAND_BUTTON_CLICKED, 
  "frmPrincipal_OnMnuCadLivros" )

function frmPrincipal_OnMnuConAssuntos( event )
  frmPrincipal_mnuPesquisas.Enable(MNU_CON_ASSUNTOS, False)
  frmConAssuntos = frmConAssuntos_Criar(frmPrincipal)
  frmConAssuntos.Show(True)
  event.Skip()
end function
connect( frmPrincipal, MNU_CON_ASSUNTOS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuConAssuntos" )

function frmPrincipal_OnMnuConAutores( event )
  frmPrincipal_mnuPesquisas.Enable(MNU_CON_AUTORES, False)
  frmConAutores = frmConAutores_Criar(frmPrincipal)
  frmConAutores.Show(True)
  event.Skip()
end function
connect( frmPrincipal, MNU_CON_AUTORES, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuConAutores" )

function frmPrincipal_OnMnuConEditoras( event )
  frmPrincipal_mnuPesquisas.Enable(MNU_CON_EDITORAS, False)
  frmConEditoras = frmConEditoras_Criar(frmPrincipal)
  frmConEditoras.Show(True)
  event.Skip()
end function
connect( frmPrincipal, MNU_CON_EDITORAS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuConEditoras" )

function frmPrincipal_OnMnuConEnderecos( event )
  frmPrincipal_mnuPesquisas.Enable(MNU_CON_ENDERECOS, False)
  frmConEnderecos = frmConEnderecos_Criar(frmPrincipal)
  frmConEnderecos.Show(True)
  event.Skip()
end function
connect( frmPrincipal, MNU_CON_ENDERECOS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuConEnderecos" )

function frmPrincipal_OnMnuConIdiomas( event )
  frmPrincipal_mnuPesquisas.Enable(MNU_CON_IDIOMAS, False)
  frmConIdiomas = frmConIdiomas_Criar(frmPrincipal)
  frmConIdiomas.Show(True)
  event.Skip()
end function
connect( frmPrincipal, MNU_CON_IDIOMAS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuConIdiomas" )

function frmPrincipal_OnMnuConPaises( event )
  frmPrincipal_mnuPesquisas.Enable(MNU_CON_PAISES, False)
  frmConPaises = frmConPaises_Criar(frmPrincipal)
  frmConPaises.Show(True)
  event.Skip()
end function
connect( frmPrincipal, MNU_CON_PAISES, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuConPaises" )

function frmPrincipal_OnMnuConProfissoes( event )
  frmPrincipal_mnuPesquisas.Enable(MNU_CON_PROFISSOES, False)
  frmConProfissoes = frmConProfissoes_Criar(frmPrincipal)
  frmConProfissoes.Show(True)
  event.Skip()
end function
connect( frmPrincipal, MNU_CON_PROFISSOES, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuConProfissoes" )

function frmPrincipal_OnMnuConClientes( event )
  frmPrincipal_mnuPesquisas.Enable(MNU_CON_CLIENTES, False)
  frmConClientes = frmConClientes_Criar(frmPrincipal)
  frmConClientes.Show(True)
  event.Skip()
end function
connect( frmPrincipal, MNU_CON_CLIENTES, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuConClientes" )

function frmPrincipal_OnMnuConLivros( event )
  frmPrincipal_mnuPesquisas.Enable(MNU_CON_LIVROS, False)
  frmConLivros = frmConLivros_Criar(frmPrincipal)
  frmConLivros.Show(True)
  event.Skip()
end function
connect( frmPrincipal, MNU_CON_LIVROS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuConLivros" )

function frmPrincipal_OnMnuVenderLivros( event )
  frmPrincipal_mnuVendas.Enable(MNU_VEN_VENDERLIVROS, False)
  fPrincipal_tlbVenda.Enable(False)
  dim fVenderLivros = frmFilha_Criar(frmPrincipal, FRMVENDERLIVROS)
  Connect( fVenderLivros, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_VEN_VENDERLIVROS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuVenderLivros" )
connect( frmPrincipal, MNU_VEN_VENDERLIVROS, wxEVT_COMMAND_BUTTON_CLICKED, 
  "frmPrincipal_OnMnuVenderLivros" )

function frmPrincipal_OnMnuVendasRealizadas( event )
  frmPrincipal_mnuVendas.Enable(MNU_VEN_VENDASREALIZADAS, False)
  dim fConVendas = frmFilha_Criar(frmPrincipal, FRMCONVENDAS)
  Connect( fConVendas, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_VEN_VENDASREALIZADAS, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuVendasRealizadas" )

function frmPrincipal_OnMnuAlterarSenha( event )
  frmPrincipal_mnuOpcoes.Enable(MNU_OP_ALTERARSENHA, False)
  dim fAlterarSenha = frmFilha_Criar(frmPrincipal, FRMALTERARSENHA)
  Connect( fAlterarSenha, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
  event.Skip()
end function
connect( frmPrincipal, MNU_OP_ALTERARSENHA, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuAlterarSenha" )

function frmPrincipal_OnMnuSobre( event )
  frmSobre.ShowModal()
end function
connect( frmPrincipal, MNU_OP_SOBRE, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuSobre" )
connect( frmPrincipal, MNU_OP_SOBRE, wxEVT_COMMAND_BUTTON_CLICKED, 
  "frmPrincipal_OnMnuSobre" )

function frmPrincipal_OnMnuSair( event )
  dim mens = new wxMessageDialog(frmPrincipal, STR_SAIRSIS, "Confirma", 
   wxNO_DEFAULT + wxYES_NO + wxICON_QUESTION)
  if mens.ShowModal() = wxID_YES then
    frmPrincipal.Destroy()
    End
  end if
end function
connect( frmPrincipal, MNU_OP_SAIR, wxEVT_COMMAND_MENU_SELECTED, 
  "frmPrincipal_OnMnuSair" )
connect( frmPrincipal, MNU_OP_SAIR, wxEVT_COMMAND_BUTTON_CLICKED, 
  "frmPrincipal_OnMnuSair" )
