ID_FRMFILHA = 99
local frmFilha_nLocalTelaAtiva

function frmFilha_Criar( parent, nTelaAtiva )
  local fFilha = wx.wxMDIChildFrame(parent, ID_FRMFILHA, "Cadastro de ", wx.wxPoint(0, 0),
     wx.wxSize(342, 219), wx.wxDEFAULT_FRAME_STYLE)
  fFilha:SetClientSize(wx.wxSize(330, 136))

  icone = wx.wxDefaultIcon()
  icone:CopyFromBitmap(wx.wxBitmapFromXPMData(livrus_xpm))
  fFilha:SetIcon(icone)
  frmFilha_nLocalTelaAtiva = nTelaAtiva

  if nTelaAtiva == FRMCADASSUNTOS then
    fCadAssuntos = frmCadAssuntos_Criar(fFilha)
    fFilha:SetTitle(STR_CADASSUNTO)
  elseif nTelaAtiva == FRMCADAUTORES then
    fCadAutores = frmCadAutores_Criar(fFilha)
    fFilha:SetTitle(STR_CADAUTOR)
  elseif nTelaAtiva == FRMCADEDITORAS then
    fCadEditoras = frmCadEditoras_Criar(fFilha)
    fFilha:SetTitle(STR_CADEDITORA)
  elseif nTelaAtiva == FRMCADENDERECOS then
    fCadEnderecos = frmCadEnderecos_Criar(fFilha)
    fFilha:SetTitle(STR_CADENDERECO)
    fFilha:SetClientSize(wx.wxSize(525, 170))
  elseif nTelaAtiva == FRMCADIDIOMAS then
    fCadIdiomas = frmCadIdiomas_Criar(fFilha)
    fFilha:SetTitle(STR_CADIDIOMA)
  elseif nTelaAtiva == FRMCADPAISES then
    fCadPaises = frmCadPaises_Criar(fFilha)
    fFilha:SetTitle(STR_CADPAIS)
  elseif nTelaAtiva == FRMCADPROFISSOES then
    fCadProfissoes = frmCadProfissoes_Criar(fFilha)
    fFilha:SetTitle(STR_CADPROFISS)
  elseif nTelaAtiva == FRMCADCLIENTES then
    fCadClientes = frmCadClientes_Criar(fFilha)
    fFilha:SetTitle(STR_CADCLIENTE)
    fFilha:SetClientSize(wx.wxSize(525, 440))
  elseif nTelaAtiva == FRMCADLIVROS then
    fCadLivros = frmCadLivros_Criar(fFilha)
    fFilha:SetTitle(STR_CADLIVRO)
    fFilha:SetClientSize(wx.wxSize(510, 425))
  elseif nTelaAtiva == FRMVENDERLIVROS then
    fVenderLivros = frmVenderLivros_Criar(fFilha)
    fFilha:SetTitle(STR_VENLIVRO)
    fFilha:SetClientSize(wx.wxSize(480, 310))
  elseif nTelaAtiva == FRMCONVENDAS then
    fConVendas = frmConVendas_Criar(fFilha)
    fFilha:SetTitle(STR_CONVENLIVRO)
    fFilha:SetClientSize(wx.wxSize(480, 330))
  elseif nTelaAtiva == FRMALTERARSENHA then
    fAlterarSenha = frmAlterarSenha_Criar(fFilha)
    fFilha:SetTitle(STR_ALTSENHA)
    fFilha:SetClientSize(wx.wxSize(255, 134))
  end

  fFilha:ConnectEvent(ID_FRMFILHA,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      if frmFilha_nLocalTelaAtiva == FRMCADASSUNTOS then
        frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_ASSUNTOS, true)
      elseif frmFilha_nLocalTelaAtiva == FRMCADAUTORES then 
        frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_AUTORES, true)
      elseif frmFilha_nLocalTelaAtiva == FRMCADEDITORAS then
        frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_EDITORAS, true)    
      elseif frmFilha_nLocalTelaAtiva == FRMCADENDERECOS then
        frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_ENDERECOS, true)    
      elseif frmFilha_nLocalTelaAtiva == FRMCADIDIOMAS then
        frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_IDIOMAS, true)
      elseif frmFilha_nLocalTelaAtiva == FRMCADPAISES then 
        frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_PAISES, true)    
      elseif frmFilha_nLocalTelaAtiva == FRMCADPROFISSOES then 
        frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_PROFISSOES, true)
      elseif frmFilha_nLocalTelaAtiva == FRMCADCLIENTES then 
        frmPrincipal_barraFerra:EnableTool(MNU_CAD_CLIENTES, true)
        frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_CLIENTES, true)
      elseif frmFilha_nLocalTelaAtiva == FRMCADLIVROS then 
        frmPrincipal_barraFerra:EnableTool(MNU_CAD_LIVROS, true)
        frmPrincipal_barraMenu:GetMenu(0):Enable(MNU_CAD_LIVROS, true)
      elseif frmFilha_nLocalTelaAtiva == FRMVENDERLIVROS then 
       frmPrincipal_barraFerra:EnableTool(MNU_VEN_VENDERLIVROS, true)
        frmPrincipal_barraMenu:GetMenu(2):Enable(MNU_VEN_VENDERLIVROS, true)  
      elseif frmFilha_nLocalTelaAtiva == FRMCONVENDAS then 
        frmPrincipal_barraMenu:GetMenu(2):Enable(MNU_VEN_VENDASREALIZADAS, true)
      elseif frmFilha_nLocalTelaAtiva == FRMALTERARSENHA then
        frmPrincipal_barraMenu:GetMenu(3):Enable(MNU_OP_ALTERARSENHA, true)
      end
      event:Skip()
    end )

  return fFilha
end
