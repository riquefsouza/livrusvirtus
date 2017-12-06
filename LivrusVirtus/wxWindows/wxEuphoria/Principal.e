#!/euphoria/bin/exu

without warning
with trace
include wxEuphoria.e
include wxMenu.e
include wxGraphics.e
include wxToolBar.e
include wxStatusBar.e

include Resource.e
include Sobre.e
include Cadastros.e
include Consultas.e

include livrus.xpm
include cliente.xpm
include livro.xpm
include livros.xpm
include sobre.xpm
include sair.xpm
include dcliente.xpm
include dlivro.xpm
include dlivros.xpm
include dsobre.xpm
include dsair.xpm

atom icone, barraFerra, bmp_cliente, bmp_livro, bmp_venda, 
  bmp_sobre, bmp_sair, bmp_dcliente, bmp_dlivro, bmp_dvenda, bmp_dsobre, 
  bmp_dsair, tlbCliente, tlbLivro, tlbVenda, tlbSobre, tlbSair

atom barraMenu, mnuCadastros, mnuCadAssuntos, mnuCadAutores, mnuCadEditoras,
  mnuCadEnderecos, mnuCadIdiomas, mnuCadPaises, mnuCadProfissoes, mnuSep1,
  mnuCadClientes, mnuCadLivros, mnuPesquisas, mnuConAssuntos, mnuConAutores, 
  mnuConEditoras, mnuConEnderecos, mnuConIdiomas, mnuConPaises, 
  mnuConProfissoes, mnuSep2, mnuConClientes, mnuConLivros, mnuVendas, 
  mnuVenderLivros,	mnuVendasRealizadas, mnuOpcoes, mnuOpAltSenha, mnuSep3, 
  mnuOpSobre, mnuOpSair

object void
global constant frmPrincipal = create( wxFrame,{0, FRMPRINCIPAL, STR_TITULO, 
  -1, -1, 640, 480} )

global constant frmPrincipal_barraStatus = create( wxStatusBar, {frmPrincipal, 2 })

procedure frmPrincipal_IniciaControles()
icone = create( wxIcon, {Livrus_xpm})

barraFerra = create( wxToolBar, {frmPrincipal, -1, 0, 0, 450, 45, 
  wxTB_HORIZONTAL + wxNO_BORDER})

--frmPrincipal_barraStatus = create( wxStatusBar, {frmPrincipal, 2 })

bmp_cliente = create( wxBitmap, {BM_XPM, cliente_xpm})
bmp_livro = create( wxBitmap, {BM_XPM, livro_xpm})
bmp_venda = create( wxBitmap, {BM_XPM, livros_xpm})
bmp_sobre = create( wxBitmap, {BM_XPM, sobre_xpm})
bmp_sair = create( wxBitmap, {BM_XPM, sair_xpm})
bmp_dcliente = create( wxBitmap, {BM_XPM, dcliente_xpm})
bmp_dlivro = create( wxBitmap, {BM_XPM, dlivro_xpm})
bmp_dvenda = create( wxBitmap, {BM_XPM, dlivros_xpm})
bmp_dsobre = create( wxBitmap, {BM_XPM, dsobre_xpm})
bmp_dsair = create( wxBitmap, {BM_XPM, dsair_xpm})

tlbCliente = add_tool( barraFerra, MNU_CAD_CLIENTES, bmp_cliente, 
  bmp_dcliente, "", "", STR_CADCLIENTE, wxITEM_NORMAL )
tlbLivro   = add_tool( barraFerra, MNU_CAD_LIVROS, bmp_livro, 
  bmp_dlivro, "", "", STR_CADLIVRO, wxITEM_NORMAL )
tlbVenda   = add_tool( barraFerra, MNU_VEN_VENDERLIVROS, bmp_venda, 
  bmp_dvenda, "", "", STR_VENLIVRO, wxITEM_NORMAL )

add_separator( barraFerra )

tlbSobre   = add_tool( barraFerra, MNU_OP_SOBRE, bmp_sobre, bmp_dsobre, 
  "", "", STR_OPSOBRE, wxITEM_NORMAL )
tlbSair   = add_tool( barraFerra, MNU_OP_SAIR, bmp_sair, bmp_dsair, 
  "", "", STR_OPSAIR, wxITEM_NORMAL )

set_icon( frmPrincipal, icone )
set_tool_bitmap_size( barraFerra, 16, 16 )
set_status_fields(frmPrincipal_barraStatus,{-1, 100})
set_status_text(frmPrincipal_barraStatus, STR_USUARIO, 1) 
show_toolbar( barraFerra )

barraMenu = create( wxMenuBar, {frmPrincipal})

mnuCadastros = create( wxMenu, {barraMenu,"&Cadastros"})
  mnuCadAssuntos = create( wxMenuItem,{ mnuCadastros,MNU_CAD_ASSUNTOS,
    "&Assuntos",STR_CADASSUNTO})
  mnuCadAutores = create( wxMenuItem,{ mnuCadastros,MNU_CAD_AUTORES, 
    "A&utores", STR_CADAUTOR})
  mnuCadEditoras = create( wxMenuItem,{ mnuCadastros,MNU_CAD_EDITORAS, 
    "&Editoras", STR_CADEDITORA})
  mnuCadEnderecos = create( wxMenuItem,{ mnuCadastros,MNU_CAD_ENDERECOS, 
    "E&ndereços", STR_CADENDERECO})
  mnuCadIdiomas = create( wxMenuItem,{ mnuCadastros,MNU_CAD_IDIOMAS, 
    "&Idiomas", STR_CADIDIOMA})
  mnuCadPaises = create( wxMenuItem,{ mnuCadastros,MNU_CAD_PAISES, 
    "&Países", STR_CADPAIS})
  mnuCadProfissoes = create( wxMenuItem,{ mnuCadastros,MNU_CAD_PROFISSOES, 
    "P&rofissões", STR_CADPROFISS})
  mnuSep1  = create( wxMenuItem,{ mnuCadastros, wxID_SEPARATOR, "-"})
  mnuCadClientes = create( wxMenuItem,{ mnuCadastros,MNU_CAD_CLIENTES, 
    "&Clientes", STR_CADCLIENTE})
  mnuCadLivros = create( wxMenuItem,{ mnuCadastros,MNU_CAD_LIVROS, 
    "&Livros", STR_CADLIVRO})

mnuPesquisas = create( wxMenu, {barraMenu,"&Pesquisas"})
  mnuConAssuntos = create( wxMenuItem, {mnuPesquisas,MNU_CON_ASSUNTOS, 
    "&Assuntos", STR_CONASSUNTO})
  mnuConAutores = create( wxMenuItem, {mnuPesquisas,MNU_CON_AUTORES, 
    "A&utores", STR_CONAUTOR})
  mnuConEditoras = create( wxMenuItem, {mnuPesquisas,MNU_CON_EDITORAS, 
    "&Editoras", STR_CONEDITORA})
  mnuConEnderecos = create( wxMenuItem, {mnuPesquisas,MNU_CON_ENDERECOS, 
    "E&ndereços", STR_CONENDERECO})
  mnuConIdiomas = create( wxMenuItem, {mnuPesquisas,MNU_CON_IDIOMAS, 
    "&Idiomas", STR_CONIDIOMA})
  mnuConPaises = create( wxMenuItem, {mnuPesquisas,MNU_CON_PAISES, 
    "&Países", STR_CONPAIS})
  mnuConProfissoes = create( wxMenuItem, {mnuPesquisas,MNU_CON_PROFISSOES, 
    "P&rofissões", STR_CONPROFISS})
  mnuSep2  = create( wxMenuItem,{ mnuPesquisas, wxID_SEPARATOR, "-"})
  mnuConClientes = create( wxMenuItem, {mnuPesquisas,MNU_CON_CLIENTES, 
    "&Clientes", STR_CONCLIENTE})
  mnuConLivros = create( wxMenuItem, {mnuPesquisas,MNU_CON_LIVROS, 
    "&Livros", STR_CONLIVRO})

mnuVendas		= create( wxMenu, {barraMenu, "&Vendas" } )
	mnuVenderLivros = create(wxMenuItem,{mnuVendas,MNU_VEN_VENDERLIVROS, 
    "&Vender Livros", STR_VENLIVRO})
	mnuVendasRealizadas = create(wxMenuItem,{mnuVendas,MNU_VEN_VENDASREALIZADAS, 
    "Vendas &Realizadas", STR_CONVENLIVRO})

mnuOpcoes = create( wxMenu,{barraMenu, "&Opções" })
	mnuOpAltSenha = create( wxMenuItem, {mnuOpcoes, MNU_OP_ALTERARSENHA, 
    "&Alterar Senha", STR_ALTSENHA})
  mnuSep3 = create( wxMenuItem,{ mnuOpcoes, wxID_SEPARATOR, "-"})
	mnuOpSobre = create( wxMenuItem, {mnuOpcoes, MNU_OP_SOBRE, "&Sobre", 
    STR_OPSOBRE})
	mnuOpSair = create( wxMenuItem, {mnuOpcoes, MNU_OP_SAIR, "Sa&ir\tCtrl-S", 
    STR_OPSAIR})

end procedure

frmPrincipal_IniciaControles()

procedure frmPrincipal_mnuCadAssuntos(atom this, atom event_type, atom id, 
  atom event)
  void = call_member( wxMenuItem_Enable, mnuCadAssuntos, {0})
  show_window( frmCadastros, TRUE )
end procedure
set_event_handler( {frmPrincipal, mnuCadastros}, MNU_CAD_ASSUNTOS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuCadAssuntos" ))

procedure frmPrincipal_mnuCadAutores(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuCadastros}, MNU_CAD_AUTORES, 
 wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuCadAutores" ))

procedure frmPrincipal_mnuCadEditoras(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuCadastros}, MNU_CAD_EDITORAS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuCadEditoras" ))

procedure frmPrincipal_mnuCadEnderecos(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuCadastros}, MNU_CAD_ENDERECOS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuCadEnderecos" ))

procedure frmPrincipal_mnuCadIdiomas(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuCadastros}, MNU_CAD_IDIOMAS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuCadIdiomas" ))

procedure frmPrincipal_mnuCadPaises(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuCadastros}, MNU_CAD_PAISES, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuCadPaises" ))

procedure frmPrincipal_mnuCadProfissoes(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuCadastros}, MNU_CAD_PROFISSOES, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuCadProfissoes" ))

procedure frmPrincipal_mnuCadClientes(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuCadastros}, MNU_CAD_CLIENTES, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuCadClientes" ))

procedure frmPrincipal_mnuCadLivros(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuCadastros}, MNU_CAD_LIVROS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuCadLivros" ))

procedure frmPrincipal_mnuConAssuntos(atom this, atom event_type, atom id, 
  atom event)
  void = show_modal( frmConsultas )
end procedure
set_event_handler( {frmPrincipal, mnuPesquisas}, MNU_CON_ASSUNTOS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuConAssuntos" ))

procedure frmPrincipal_mnuConAutores(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuPesquisas}, MNU_CON_AUTORES, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuConAutores" ))

procedure frmPrincipal_mnuConEditoras(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuPesquisas}, MNU_CON_EDITORAS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuConEditoras" ))

procedure frmPrincipal_mnuConEnderecos(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuPesquisas}, MNU_CON_ENDERECOS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuConEnderecos" ))

procedure frmPrincipal_mnuConIdiomas(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuPesquisas}, MNU_CON_IDIOMAS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuConIdiomas" ))

procedure frmPrincipal_mnuConPaises(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuPesquisas}, MNU_CON_PAISES, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuConPaises" ))

procedure frmPrincipal_mnuConProfissoes(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuPesquisas}, MNU_CON_PROFISSOES, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuConProfissoes" ))

procedure frmPrincipal_mnuConClientes(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuPesquisas}, MNU_CON_CLIENTES, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuConClientes" ))

procedure frmPrincipal_mnuConLivros(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuPesquisas}, MNU_CON_LIVROS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuConLivros" ))

procedure frmPrincipal_mnuVenderLivros(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuVendas}, MNU_VEN_VENDERLIVROS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuVenderLivros" ))

procedure frmPrincipal_mnuVendasRealizadas(atom this, atom event_type, atom id, 
  atom event)
--
end procedure
set_event_handler( {frmPrincipal, mnuVendas}, MNU_VEN_VENDASREALIZADAS, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuVendasRealizadas" ))

procedure frmPrincipal_mnuOpAltSenha(atom this, atom event_type, atom id, 
  atom event)
    exit_main()
end procedure
set_event_handler( {frmPrincipal,mnuOpcoes}, MNU_OP_ALTERARSENHA, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuOpAltSenha" ))

procedure frmPrincipal_mnuOpSobre(atom this, atom event_type, atom id, 
  atom event)
  void = show_modal( frmSobre )
end procedure
set_event_handler( {frmPrincipal, mnuOpcoes}, MNU_OP_SOBRE, 
  wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuOpSobre" ))

procedure frmPrincipal_OnClose(atom this, atom event_type, atom id, 
  atom event)
integer resultado
  resultado = message_box(STR_SAIRSIS, "Confirma",
    wxNO_DEFAULT + wxYES_NO + wxICON_QUESTION)

  if resultado = wxYES then
    exit_main()
  end if
end procedure
set_event_handler( {frmPrincipal}, FRMPRINCIPAL, wxEVT_CLOSE_WINDOW,
    routine_id( "frmPrincipal_OnClose" ))

procedure frmPrincipal_mnuOpSair(atom this, atom event_type, atom id, 
  atom event)
  frmPrincipal_OnClose(this, event_type, id, event)
end procedure
set_event_handler( {frmPrincipal,mnuOpcoes}, MNU_OP_SAIR, 
 wxEVT_COMMAND_MENU_SELECTED, routine_id( "frmPrincipal_mnuOpSair" ))
