frmPrincipal_barraMenu = nil
frmPrincipal_barraFerra = nil

function frmPrincipal_Criar()

  local fPrincipal = wx.wxMDIParentFrame( wx.wxNull, -1, STR_TITULO, 
    wx.wxPoint(-1, -1), wx.wxSize(640, 480), wx.wxDEFAULT_FRAME_STYLE )
  fPrincipal:Centre()
                            
  icone = wx.wxDefaultIcon()
  icone:CopyFromBitmap(wx.wxBitmapFromXPMData(livrus_xpm))
  fPrincipal:SetIcon(icone)

  --Barra de Menu
  local mnuCadastros = wx.wxMenu()
  mnuCadastros:Append(MNU_CAD_ASSUNTOS, "&Assuntos", STR_CADASSUNTO)
  mnuCadastros:Append(MNU_CAD_AUTORES, "A&utores", STR_CADAUTOR)
  mnuCadastros:Append(MNU_CAD_EDITORAS, "&Editoras", STR_CADEDITORA)
  mnuCadastros:Append(MNU_CAD_ENDERECOS, "E&ndereços", STR_CADENDERECO)
  mnuCadastros:Append(MNU_CAD_IDIOMAS, "&Idiomas", STR_CADIDIOMA)
  mnuCadastros:Append(MNU_CAD_PAISES, "&Países", STR_CADPAIS)
  mnuCadastros:Append(MNU_CAD_PROFISSOES, "P&rofissões", STR_CADPROFISS)
  mnuCadastros:AppendSeparator()
  mnuCadastros:Append(MNU_CAD_CLIENTES, "&Clientes", STR_CADCLIENTE)
  mnuCadastros:Append(MNU_CAD_LIVROS, "&Livros", STR_CADLIVRO)

  local mnuPesquisas = wx.wxMenu()
  mnuPesquisas:Append(MNU_CON_ASSUNTOS, "&Assuntos", STR_CONASSUNTO)
  mnuPesquisas:Append(MNU_CON_AUTORES, "A&utores", STR_CONAUTOR)
  mnuPesquisas:Append(MNU_CON_EDITORAS, "&Editoras", STR_CONEDITORA)
  mnuPesquisas:Append(MNU_CON_ENDERECOS, "E&ndereços", STR_CONENDERECO)
  mnuPesquisas:Append(MNU_CON_IDIOMAS, "&Idiomas", STR_CONIDIOMA)
  mnuPesquisas:Append(MNU_CON_PAISES, "&Países", STR_CONPAIS)
  mnuPesquisas:Append(MNU_CON_PROFISSOES, "P&rofissões", STR_CONPROFISS)
  mnuPesquisas:AppendSeparator()
  mnuPesquisas:Append(MNU_CON_CLIENTES, "&Clientes", STR_CONCLIENTE)
  mnuPesquisas:Append(MNU_CON_LIVROS, "&Livros", STR_CONLIVRO)
  
  local mnuVendas = wx.wxMenu()
  mnuVendas:Append(MNU_VEN_VENDERLIVROS, "&Vender Livros", STR_VENLIVRO)
  mnuVendas:Append(MNU_VEN_VENDASREALIZADAS, "Vendas &Realizadas", STR_CONVENLIVRO)
  
  local mnuOpcoes = wx.wxMenu()
  mnuOpcoes:Append(MNU_OP_ALTERARSENHA, "&Alterar Senha", STR_ALTSENHA)
  mnuOpcoes:AppendSeparator()
  mnuOpcoes:Append(MNU_OP_SOBRE, "&Sobre", STR_OPSOBRE)
  mnuOpcoes:Append(MNU_OP_SAIR, "Sa&ir\tCtrl-S", STR_OPSAIR)  
  
  frmPrincipal_barraMenu = wx.wxMenuBar()
  frmPrincipal_barraMenu:Append(mnuCadastros, "&Cadastros")
  frmPrincipal_barraMenu:Append(mnuPesquisas, "&Pesquisas")
  frmPrincipal_barraMenu:Append(mnuVendas, "&Vendas")
  frmPrincipal_barraMenu:Append(mnuOpcoes, "&Opções")
  
  fPrincipal:SetMenuBar(frmPrincipal_barraMenu)
  
  --Barra de ferramentas    
  frmPrincipal_barraFerra = wx.wxToolBar(fPrincipal, -1, wx.wxPoint(0,0), wx.wxSize(-1,-1),
    wx.wxTB_HORIZONTAL + wx.wxNO_BORDER)
  fPrincipal:SetToolBar(frmPrincipal_barraFerra)
  bmp_cliente = wx.wxBitmapFromXPMData(cliente_xpm)
  bmp_livro = wx.wxBitmapFromXPMData(livro_xpm)
  bmp_venda = wx.wxBitmapFromXPMData(venda_xpm)
  bmp_sobre = wx.wxBitmapFromXPMData(sobre_xpm)
  bmp_sair = wx.wxBitmapFromXPMData(sair_xpm)
  
  frmPrincipal_barraFerra:AddTool(MNU_CAD_CLIENTES, bmp_cliente, 
    wx.wxNullBitmap, wx.FALSE, wx.wxNull, STR_CADCLIENTE) 
  frmPrincipal_barraFerra:AddTool(MNU_CAD_LIVROS, bmp_livro, 
    wx.wxNullBitmap, wx.FALSE, wx.wxNull, STR_CADLIVRO) 
  frmPrincipal_barraFerra:AddTool(MNU_VEN_VENDERLIVROS, bmp_venda, 
    wx.wxNullBitmap, wx.FALSE, wx.wxNull, STR_VENLIVRO) 
  frmPrincipal_barraFerra:AddSeparator()
  frmPrincipal_barraFerra:AddTool(MNU_OP_SOBRE, bmp_sobre, wx.wxNullBitmap, 
    wx.FALSE, wx.wxNull, STR_OPSOBRE) 
  frmPrincipal_barraFerra:AddTool(MNU_OP_SAIR, bmp_sair, wx.wxNullBitmap, 
    wx.FALSE, wx.wxNull, STR_OPSAIR) 
  frmPrincipal_barraFerra:Realize()
  
  local barraStatus = fPrincipal:CreateStatusBar(2)
  --fPrincipal:SetStatusBarPane(1)    
  local nLarguras = {}
  nLarguras[1] = -1
  nLarguras[2] = 100
  barraStatus:SetStatusWidths(nLarguras)
  barraStatus:SetStatusText(STR_USUARIO,1) 
  
  fPrincipal:ConnectEvent(MNU_CAD_ASSUNTOS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_ASSUNTOS, false)
      frmFilha_Criar(fPrincipal, FRMCADASSUNTOS)
    end )

  fPrincipal:ConnectEvent(MNU_CAD_AUTORES, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_AUTORES, false)
      frmFilha_Criar(fPrincipal, FRMCADAUTORES)
    end )

  fPrincipal:ConnectEvent(MNU_CAD_EDITORAS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_EDITORAS, false)
      frmFilha_Criar(fPrincipal, FRMCADEDITORAS)
    end )

  fPrincipal:ConnectEvent(MNU_CAD_ENDERECOS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_ENDERECOS, false)
      frmFilha_Criar(fPrincipal, FRMCADENDERECOS)
    end )

  fPrincipal:ConnectEvent(MNU_CAD_IDIOMAS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_IDIOMAS, false)
      frmFilha_Criar(fPrincipal, FRMCADIDIOMAS)
    end )

  fPrincipal:ConnectEvent(MNU_CAD_PAISES, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_PAISES, false)
      frmFilha_Criar(fPrincipal, FRMCADPAISES)
    end )

  fPrincipal:ConnectEvent(MNU_CAD_PROFISSOES, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_PROFISSOES, false)
      frmFilha_Criar(fPrincipal, FRMCADPROFISSOES)
    end )

  fPrincipal:ConnectEvent(MNU_CAD_CLIENTES, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_CLIENTES, false)
      frmPrincipal_barraFerra:EnableTool(MNU_CAD_CLIENTES, false)
      frmFilha_Criar(fPrincipal, FRMCADCLIENTES)
    end )

  fPrincipal:ConnectEvent(MNU_CAD_LIVROS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_LIVROS, false)
      frmPrincipal_barraFerra:EnableTool(MNU_CAD_LIVROS, false)
      frmFilha_Criar(fPrincipal, FRMCADLIVROS)
    end )
 
  fPrincipal:ConnectEvent(MNU_CON_ASSUNTOS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(1):Enable(MNU_CON_ASSUNTOS, false)
      fConAssuntos = frmConAssuntos_Criar(fPrincipal)
      fConAssuntos:Show(wx.TRUE)
    end )

  fPrincipal:ConnectEvent(MNU_CON_AUTORES, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(1):Enable(MNU_CON_AUTORES, false)
      fConAutores = frmConAssuntos_Criar(fPrincipal)
      fConAutores:Show(wx.TRUE)
    end )

  fPrincipal:ConnectEvent(MNU_CON_EDITORAS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(1):Enable(MNU_CON_EDITORAS, false)
      fConEditoras = frmConEditoras_Criar(fPrincipal)
      fConEditoras:Show(wx.TRUE)
    end )

  fPrincipal:ConnectEvent(MNU_CON_ENDERECOS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(1):Enable(MNU_CON_ENDERECOS, false)
      fConEnderecos = frmConEnderecos_Criar(fPrincipal)
      fConEnderecos:Show(wx.TRUE)
    end )

  fPrincipal:ConnectEvent(MNU_CON_IDIOMAS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(1):Enable(MNU_CON_IDIOMAS, false)
      fConIdiomas = frmConIdiomas_Criar(fPrincipal)
      fConIdiomas:Show(wx.TRUE)
    end )

  fPrincipal:ConnectEvent(MNU_CON_PAISES, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(1):Enable(MNU_CON_PAISES, false)
      fConPaises = frmConPaises_Criar(fPrincipal)
      fConPaises:Show(wx.TRUE)
    end )

  fPrincipal:ConnectEvent(MNU_CON_PROFISSOES, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(1):Enable(MNU_CON_PROFISSOES, false)
      fConProfissoes = frmConProfissoes_Criar(fPrincipal)
      fConProfissoes:Show(wx.TRUE)
    end )

  fPrincipal:ConnectEvent(MNU_CON_CLIENTES, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(1):Enable(MNU_CON_CLIENTES, false)
      fConClientes = frmConClientes_Criar(fPrincipal)
      fConClientes:Show(wx.TRUE)
    end )

  fPrincipal:ConnectEvent(MNU_CON_LIVROS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(1):Enable(MNU_CON_LIVROS, false)
      fConLivros = frmConLivros_Criar(fPrincipal)
      fConLivros:Show(wx.TRUE)
    end )

  fPrincipal:ConnectEvent(MNU_VEN_VENDERLIVROS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(2):Enable(MNU_VEN_VENDERLIVROS, false)
      frmPrincipal_barraFerra:EnableTool(MNU_VEN_VENDERLIVROS, false)
      frmFilha_Criar(fPrincipal, FRMVENDERLIVROS)
    end )

  fPrincipal:ConnectEvent(MNU_VEN_VENDASREALIZADAS, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(2):Enable(MNU_VEN_VENDASREALIZADAS, false)
      frmFilha_Criar(fPrincipal, FRMCONVENDAS)
    end )

  fPrincipal:ConnectEvent(MNU_OP_ALTERARSENHA, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      frmPrincipal_barraMenu:GetMenu(3):Enable(MNU_OP_ALTERARSENHA, false)
      frmFilha_Criar(fPrincipal, FRMALTERARSENHA)
    end )

  fPrincipal:ConnectEvent(MNU_OP_SOBRE, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      local frmSobre = frmSobre_Criar()
      frmSobre:ShowModal()
    end )

  fPrincipal:ConnectEvent(MNU_OP_SAIR, wx.wxEVT_COMMAND_MENU_SELECTED, 
    function (event)
      local mens = wx.wxMessageDialog(fPrincipal, STR_SAIRSIS, "Confirma", 
       wx.wxNO_DEFAULT + wx.wxYES_NO + wx.wxICON_QUESTION)
      if mens:ShowModal() == wx.wxID_YES then
        fPrincipal:Close()
        --fPrincipal:Destroy()
        os.exit(0)
      end 
    end )

  return fPrincipal
end

frmPrincipal = frmPrincipal_Criar()
