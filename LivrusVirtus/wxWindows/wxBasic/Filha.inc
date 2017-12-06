option explicit

dim common frmPrincipal_barraMenu
dim common fPrincipal_tlbCliente
dim common fPrincipal_tlbLivro
dim common fPrincipal_tlbVenda
dim common frmPrincipal_barraFerra
dim common frmPrincipal_mnuCadastros
dim common frmPrincipal_mnuPesquisas
dim common frmPrincipal_mnuVendas
dim common frmPrincipal_mnuOpcoes

dim common frmFilha_nLocalTelaAtiva

function frmFilha_Criar( parent, nTelaAtiva )
  dim fFilha = new wxMDIChildFrame(parent, -1, "Cadastro de ", wxPoint(0, 0),
     wxSize(342, 219), wxDEFAULT_FRAME_STYLE,"")
  fFilha.SetClientSize(wxSize(330, 136))

	'fFilha.SetIcon(wxIcon( "xpms/livrus.xpm" ))
  frmFilha_nLocalTelaAtiva = nTelaAtiva

  if nTelaAtiva = FRMCADASSUNTOS then
    frmCadAssuntos = frmCadAssuntos_Criar(fFilha)
    fFilha.SetTitle(STR_CADASSUNTO)
  ElseIf nTelaAtiva = FRMCADAUTORES then
    frmCadAutores = frmCadAutores_Criar(fFilha)
    fFilha.SetTitle(STR_CADAUTOR)
  ElseIf nTelaAtiva = FRMCADEDITORAS then
    frmCadEditoras = frmCadEditoras_Criar(fFilha)
    fFilha.SetTitle(STR_CADEDITORA)
  ElseIf nTelaAtiva = FRMCADENDERECOS then
    frmCadEnderecos = frmCadEnderecos_Criar(fFilha)
    fFilha.SetTitle(STR_CADENDERECO)
    fFilha.SetClientSize(wxSize(525, 170))
  ElseIf nTelaAtiva = FRMCADIDIOMAS then
    frmCadIdiomas = frmCadIdiomas_Criar(fFilha)
    fFilha.SetTitle(STR_CADIDIOMA)
  ElseIf nTelaAtiva = FRMCADPAISES then
    frmCadPaises = frmCadPaises_Criar(fFilha)
    fFilha.SetTitle(STR_CADPAIS)
  ElseIf nTelaAtiva = FRMCADPROFISSOES then
    frmCadProfissoes = frmCadProfissoes_Criar(fFilha)
    fFilha.SetTitle(STR_CADPROFISS)
  ElseIf nTelaAtiva = FRMCADCLIENTES then
    frmCadClientes = frmCadClientes_Criar(fFilha)
    fFilha.SetTitle(STR_CADCLIENTE)
    fFilha.SetClientSize(wxSize(525, 440))
  ElseIf nTelaAtiva = FRMCADLIVROS then
    frmCadLivros = frmCadLivros_Criar(fFilha)
    fFilha.SetTitle(STR_CADLIVRO)
    fFilha.SetClientSize(wxSize(510, 385))
  ElseIf nTelaAtiva = FRMVENDERLIVROS then
    frmVenderLivros = frmVenderLivros_Criar(fFilha)
    fFilha.SetTitle(STR_VENLIVRO)
    fFilha.SetClientSize(wxSize(480, 310))
  ElseIf nTelaAtiva = FRMCONVENDAS then
    frmConVendas = frmConVendas_Criar(fFilha)
    fFilha.SetTitle(STR_CONVENLIVRO)
    fFilha.SetClientSize(wxSize(480, 315))
  ElseIf nTelaAtiva = FRMALTERARSENHA then
    frmAlterarSenha = frmAlterarSenha_Criar(fFilha)
    fFilha.SetTitle(STR_ALTSENHA)
    fFilha.SetClientSize(wxSize(255, 134))
  end if

  return fFilha
end function

Function frmFilha_OnClose( event )
  if frmFilha_nLocalTelaAtiva = FRMCADASSUNTOS then
    frmPrincipal_mnuCadastros.Enable(MNU_CAD_ASSUNTOS, True)
  ElseIf frmFilha_nLocalTelaAtiva = FRMCADAUTORES then 
    frmPrincipal_mnuCadastros.Enable(MNU_CAD_AUTORES, True)
  ElseIf frmFilha_nLocalTelaAtiva = FRMCADEDITORAS then
    frmPrincipal_mnuCadastros.Enable(MNU_CAD_EDITORAS, True)    
  ElseIf frmFilha_nLocalTelaAtiva = FRMCADENDERECOS then
    frmPrincipal_mnuCadastros.Enable(MNU_CAD_ENDERECOS, True)    
  ElseIf frmFilha_nLocalTelaAtiva = FRMCADIDIOMAS then
    frmPrincipal_mnuCadastros.Enable(MNU_CAD_IDIOMAS, True)
  ElseIf frmFilha_nLocalTelaAtiva = FRMCADPAISES then 
    frmPrincipal_mnuCadastros.Enable(MNU_CAD_PAISES, True)    
  ElseIf frmFilha_nLocalTelaAtiva = FRMCADPROFISSOES then 
    frmPrincipal_mnuCadastros.Enable(MNU_CAD_PROFISSOES, True)
  ElseIf frmFilha_nLocalTelaAtiva = FRMCADCLIENTES then 
    fPrincipal_tlbCliente.Enable(True)
    frmPrincipal_mnuCadastros.Enable(MNU_CAD_CLIENTES, True)
  ElseIf frmFilha_nLocalTelaAtiva = FRMCADLIVROS then 
    fPrincipal_tlbLivro.Enable(True)
    frmPrincipal_mnuCadastros.Enable(MNU_CAD_LIVROS, True)
  ElseIf frmFilha_nLocalTelaAtiva = FRMVENDERLIVROS then 
    fPrincipal_tlbVenda.Enable(True)
    frmPrincipal_mnuVendas.Enable(MNU_VEN_VENDERLIVROS, True)  
  ElseIf frmFilha_nLocalTelaAtiva = FRMCONVENDAS then 
    frmPrincipal_mnuVendas.Enable(MNU_VEN_VENDASREALIZADAS, True)
  ElseIf frmFilha_nLocalTelaAtiva = FRMALTERARSENHA then
    frmPrincipal_mnuOpcoes.Enable(MNU_OP_ALTERARSENHA, True)
  end if
  event.Skip()
End Function
'Connect( frmFilha, wxEVT_CLOSE_WINDOW, "frmFilha_OnClose" )
