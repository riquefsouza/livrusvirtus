ID_FRMCADLIVROS_BTNADASSUNTOS = 900
ID_FRMCADLIVROS_BTNADAUTORES = 901
ID_FRMCADLIVROS_BTNPASSUNTO = 902
ID_FRMCADLIVROS_BTNPAUTOR = 903
ID_FRMCADLIVROS_BTNPEDITORA = 904
ID_FRMCADLIVROS_CMBIDIOMA = 905
ID_FRMCADLIVROS_EDTANOPUBLI = 906
ID_FRMCADLIVROS_EDTASSUNTO = 907
ID_FRMCADLIVROS_EDTAUTOR = 908
ID_FRMCADLIVROS_EDTCODASSUNTO = 909
ID_FRMCADLIVROS_EDTCODAUTOR = 910
ID_FRMCADLIVROS_EDTCODEDITORA = 911
ID_FRMCADLIVROS_EDTEDICAO = 912
ID_FRMCADLIVROS_EDTEDITORA = 913
ID_FRMCADLIVROS_EDTNPAGINAS = 914
ID_FRMCADLIVROS_EDTPRECO = 915
ID_FRMCADLIVROS_EDTQTDESTOQUE = 916
ID_FRMCADLIVROS_EDTVOLUME = 917
ID_FRMCADLIVROS_LABANOPUBLI = 918
ID_FRMCADLIVROS_LABASSUNTO = 919
ID_FRMCADLIVROS_LABAUTOR = 920
ID_FRMCADLIVROS_LABEDICAO = 921
ID_FRMCADLIVROS_LABEDITORA = 922
ID_FRMCADLIVROS_LABIDIOMA = 923
ID_FRMCADLIVROS_LABNPAGINAS = 924
ID_FRMCADLIVROS_LABPRECO = 925
ID_FRMCADLIVROS_LABQTDESTOQUE = 926
ID_FRMCADLIVROS_LABVOLUME = 927
ID_FRMCADLIVROS_LSTASSUNTOS = 928
ID_FRMCADLIVROS_LSTAUTORES = 930
ID_FRMCADLIVROS = 931

local frmCadLivros
local frmCadLivros_slIdiomas
local frmCadLivros_slAssuntos
local frmCadLivros_slAutores
local frmCadLivros_labEdicao
local frmCadLivros_edtEdicao
local frmCadLivros_labAnoPubli
local frmCadLivros_edtAnoPubli
local frmCadLivros_labEditora
local frmCadLivros_edtCodEditora
local frmCadLivros_edtEditora
local frmCadLivros_btnPEditora
local frmCadLivros_labVolume
local frmCadLivros_edtVolume
local frmCadLivros_labIdioma
local frmCadLivros_cmbIdioma
local frmCadLivros_labNPaginas
local frmCadLivros_edtNPaginas
local frmCadLivros_labAssunto
local frmCadLivros_edtCodAssunto
local frmCadLivros_edtAssunto
local frmCadLivros_btnAdAssuntos
local frmCadLivros_btnPAssunto
local frmCadLivros_lstAssuntos
local frmCadLivros_labPreco
local frmCadLivros_edtPreco
local frmCadLivros_labQtdEstoque
local frmCadLivros_edtQtdEstoque
local frmCadLivros_labAutor
local frmCadLivros_edtCodAutor
local frmCadLivros_edtAutor
local frmCadLivros_btnAdAutores
local frmCadLivros_btnPAutor
local frmCadLivros_lstAutores
local frmCadLivros_vsIdiomas = {}

function frmCadLivros_Criar(parent)
  local fCadLivros = frmCadastros_Criar(parent, ID_FRMCADLIVROS, 0, false)

  frmCadastros_labCodigo:SetLabel("ISBN: ")
  frmCadastros_labDescricao:SetLabel("Título: ")
  frmCadastros_edtDescricao:SetSize(312, 21)

  frmCadLivros_labEdicao = wx.wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABEDICAO,
    "Edição: ", wx.wxPoint(326, 48), wx.wxSize(39, 13), 0)
  frmCadLivros_edtEdicao = wx.wxSpinCtrl(fCadLivros, ID_FRMCADLIVROS_EDTEDICAO, 
    "1", wx.wxPoint(324, 64), wx.wxSize(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1)
  frmCadLivros_edtEdicao:Enable(false)

  frmCadLivros_labAnoPubli = wx.wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABANOPUBLI,
    "Ano Publicação: ", wx.wxPoint(8, 88), wx.wxSize(81, 13), 0)  
  frmCadLivros_edtAnoPubli = wx.wxSpinCtrl(fCadLivros, ID_FRMCADLIVROS_EDTANOPUBLI,
    "1", wx.wxPoint(8, 104), wx.wxSize(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1)
  frmCadLivros_edtAnoPubli:Enable(false)
  
  frmCadLivros_labEditora = wx.wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABEDITORA,
    "Editora: ", wx.wxPoint(104, 88), wx.wxSize(39, 13), 0)  
  frmCadLivros_edtCodEditora = wx.wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTCODEDITORA,
    "", wx.wxPoint(104, 104), wx.wxSize(78, 21), 0 )
  frmCadLivros_edtCodEditora:Enable(false)
  --Connect( fCadLivros, ID_FRMCADLIVROS_EDTCODEDITORA, 
  --  wxEVT_KILL_FOCUS, "frmCadLivros_OnEdtCodEditora_Killfocus" )
  
  frmCadLivros_edtEditora = wx.wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTEDITORA,
     "", wx.wxPoint(184, 104), wx.wxSize(216, 21), 0)
  frmCadLivros_edtEditora:Enable(false)
  
  frmCadLivros_btnPEditora = wx.wxButton(fCadLivros, ID_FRMCADLIVROS_BTNPEDITORA,
    "...", wx.wxPoint(400, 104), wx.wxSize(21, 21), 0)
  frmCadLivros_btnPEditora:Enable(false)
  
  frmCadLivros_labVolume = wx.wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABVOLUME,
    "Volume: ", wx.wxPoint(8, 128), wx.wxSize(41, 13), 0)  
  frmCadLivros_edtVolume = wx.wxSpinCtrl(fCadLivros, ID_FRMCADLIVROS_EDTVOLUME,
    "1", wx.wxPoint(8, 144), wx.wxSize(92, 21), wxSP_ARROW_KEYS,
    1, 9999, 1)
  frmCadLivros_edtVolume:Enable(false)
  
  frmCadLivros_labIdioma = wx.wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABIDIOMA,
    "Idioma: ", wx.wxPoint(104, 128), wx.wxSize(56, 13), 0)

  frmCadLivros_cmbIdioma = wx.wxChoice(fCadLivros, ID_FRMCADLIVROS_CMBIDIOMA,
    wx.wxPoint(104, 144), wx.wxSize(320, 21))
  frmCadLivros_cmbIdioma:Enable(false)
  --frmCadLivros_AdicionaCombo()
  
  frmCadLivros_labNPaginas = wx.wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABNPAGINAS,
    "Nº Páginas: ", wx.wxPoint(8, 168), wx.wxSize(59, 13), 0)
  
  frmCadLivros_edtNPaginas = wx.wxSpinCtrl(fCadLivros, ID_FRMCADLIVROS_EDTNPAGINAS,
    "1", wx.wxPoint(8, 184), wx.wxSize(92, 21), wxSP_ARROW_KEYS,
    1, 9999, 1)
  frmCadLivros_edtNPaginas:Enable(false)
  
  frmCadLivros_labAssunto = wx.wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABASSUNTO,
    "Assunto: ", wx.wxPoint(104, 168), wx.wxSize(44, 13), 0)
  
  frmCadLivros_edtCodAssunto = wx.wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTCODASSUNTO,
    "", wx.wxPoint(104, 184), wx.wxSize(78, 21), 0)
  frmCadLivros_edtCodAssunto:Enable(false)
  --Connect( fCadLivros, ID_FRMCADLIVROS_EDTCODASSUNTO, 
  --  wxEVT_KILL_FOCUS, "frmCadLivros_OnEdtCodAssunto_Killfocus" )
  
  frmCadLivros_edtAssunto = wx.wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTASSUNTO,
    "", wx.wxPoint(184, 184), wx.wxSize(192, 21), 0)
  frmCadLivros_edtAssunto:Enable(false)
  
  frmCadLivros_btnAdAssuntos = wx.wxButton(fCadLivros, ID_FRMCADLIVROS_BTNADASSUNTOS,
    "+", wx.wxPoint(376, 184), wx.wxSize(21, 21), 0)
  frmCadLivros_btnAdAssuntos:Enable(false)
  
  frmCadLivros_btnPAssunto = wx.wxButton(fCadLivros, ID_FRMCADLIVROS_BTNPASSUNTO,
    "...", wx.wxPoint(400, 184), wx.wxSize(21, 21), 0)
  frmCadLivros_btnPAssunto:Enable(false)

  frmCadLivros_lstAssuntos = wx.wxListBox(fCadLivros, ID_FRMCADLIVROS_LSTASSUNTOS,
    wx.wxPoint(104, 208), wx.wxSize(320, 48))
  frmCadLivros_lstAssuntos:Enable(false)
  
  frmCadLivros_labPreco = wx.wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABPRECO,
    "Preço: ", wx.wxPoint(8, 216), wx.wxSize(40, 13), 0)
  
  frmCadLivros_edtPreco = wx.wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTPRECO,
    "", wx.wxPoint(7, 232), wx.wxSize(92, 21), 0)
  frmCadLivros_edtPreco:Enable(false)
  --Connect( fCadLivros, ID_FRMCADLIVROS_EDTPRECO, 
  --  wxEVT_KILL_FOCUS, "frmCadLivros_OnEdtCodPreco_Killfocus" )
  
  frmCadLivros_labQtdEstoque = wx.wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABQTDESTOQUE,
    "Qtd. Estoque: ", wx.wxPoint(6, 256), wx.wxSize(68, 13), 0)
  
  frmCadLivros_edtQtdEstoque = wx.wxSpinCtrl(fCadLivros, ID_FRMCADLIVROS_EDTQTDESTOQUE,
    "0", wx.wxPoint(8, 272), wx.wxSize(92, 21), wxSP_ARROW_KEYS,
    0, 9999, 0)
  frmCadLivros_edtQtdEstoque:Enable(false)
  
  frmCadLivros_labAutor = wx.wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABAUTOR,
    "Autor: ", wx.wxPoint(104, 256), wx.wxSize(31, 13), 0)  
  frmCadLivros_edtCodAutor = wx.wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTCODAUTOR,
    "", wx.wxPoint(104, 272), wx.wxSize(78, 21), 0)
  frmCadLivros_edtCodAutor:Enable(false)
  --Connect( fCadLivros, ID_FRMCADLIVROS_EDTCODAUTOR, 
  --  wxEVT_KILL_FOCUS, "frmCadLivros_OnEdtCodAutor_Killfocus" )
  
  frmCadLivros_edtAutor = wx.wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTAUTOR,
    "", wx.wxPoint(184, 272), wx.wxSize(192, 21), 0)
  frmCadLivros_edtAutor:Enable(false)
  
  frmCadLivros_btnAdAutores = wx.wxButton(fCadLivros, ID_FRMCADLIVROS_BTNADAUTORES,
    "+", wx.wxPoint(376, 272), wx.wxSize(21, 21), 0)
  frmCadLivros_btnAdAutores:Enable(false)
  
  frmCadLivros_btnPAutor = wx.wxButton(fCadLivros, ID_FRMCADLIVROS_BTNPAUTOR, "...",
    wx.wxPoint(400, 272), wx.wxSize(21, 21), 0)
  frmCadLivros_btnPAutor:Enable(false)

  frmCadLivros_lstAutores = wx.wxListBox(fCadLivros, ID_FRMCADLIVROS_LSTAUTORES,
    wx.wxPoint(104, 296), wx.wxSize(320, 48))
  frmCadLivros_lstAutores:Enable(false)

  frmCadastros_IniciaBotoes(fCadLivros)
  frmCadastros_btnPesquisar:SetDimensions(427, 8, 75, 25)
  frmCadastros_btnAnterior:SetDimensions(427, 40, 75, 25)
  frmCadastros_btnProximo:SetDimensions(427, 72, 75, 25)
  frmCadastros_btnSalvar:SetDimensions(187, 352, 75, 25)
  frmCadastros_btnExcluir:SetDimensions(267, 352, 75, 25)
  frmCadastros_btnLimpar:SetDimensions(347, 352, 75, 25)
  frmCadastros_btnFechar:SetDimensions(427, 352, 75, 25)

  frmCadLivros_FazLayout(fCadLivros)

	--frmCadastros_edtCodigo:MaxLength = 13
  --frmCadastros_edtDescricao:MaxLength = 50
  --frmCadLivros_edtCodEditora:MaxLength = 5
  --frmCadLivros_edtPreco:MaxLength = 7

  fCadLivros:ConnectEvent(ID_FRMCADLIVROS,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fCadLivros:GetParent():Close(true)
      event:Skip()
    end )

  fCadLivros:ConnectEvent(ID_FRMCADASTROS_BTNNOVO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
      frmCadLivros_InformaLimpaDados(false)
      frmCadLivros_HabilitaDados(true)
      event:Skip()
    end )

  fCadLivros:ConnectEvent(ID_FRMCADASTROS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_PesquisarDados(ConsSQL_Livro("S", 
        frmCadastros_edtCodigo:GetValue(),"","","","","","","","","",""), STR_LIVNENC,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir) then
        frmCadLivros_InformaLimpaDados(true)
        frmCadLivros_HabilitaDados(true)
      end
      event:Skip()
    end )

  fCadLivros:ConnectEvent(ID_FRMCADASTROS_BTNANTERIOR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao) then
        frmCadLivros_InformaLimpaDados(true)
      end		
      event:Skip()
    end )

  fCadLivros:ConnectEvent(ID_FRMCADASTROS_BTNPROXIMO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_registroProximo(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao) then
        frmCadLivros_InformaLimpaDados(true)
      end		
      event:Skip()
    end )

  fCadLivros:ConnectEvent(ID_FRMCADASTROS_BTNSALVAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_SalvarDados(frmCadLivros_ValidaDados(true),
        ConsSQL_Livro("S", frmCadastros_edtCodigo:GetValue(),
          "","","","","","","","","",""),
        ConsSQL_Livro("U", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue(),"","","","","","","","",""),
        ConsSQL_Livro("I", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue(),"","","","","","","","",""), 
        true,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir) then
        frmCadLivros_InformaLimpaDados(false)
        frmCadLivros_HabilitaDados(false)
      end
      event:Skip()
    end )

  fCadLivros:ConnectEvent(ID_FRMCADASTROS_BTNEXCLUIR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      if frmCadastros_ExcluirDados(frmCadLivros_ValidaDados(false),
        ConsSQL_Livro("D", frmCadastros_edtCodigo:GetValue(),
        "","","","","","","","","",""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir) then
        frmCadLivros_InformaLimpaDados(false)
        frmCadLivros_HabilitaDados(false)
      end
      event:Skip()
    end )

  fCadLivros:ConnectEvent(ID_FRMCADASTROS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fCadLivros:Close(true)
      event:Skip()
    end )

  fCadLivros:ConnectEvent(ID_FRMCADASTROS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao, frmCadastros_btnNovo, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      frmCadLivros_InformaLimpaDados(false)
      frmCadLivros_HabilitaDados(false)
      event:Skip()
    end )

  fCadLivros:ConnectEvent(ID_FRMCADASTROS_EDTCODIGO,
    wx.wxEVT_KILL_FOCUS,
    function (event)
      if string.len(frmCadastros_edtCodigo:GetValue()) > 0 then
      	if Rotinas_ValidaISBN(frmCadastros_edtCodigo:GetValue())==false then
          wxMessageBox(STR_ISBNINV, "Erro", wxOK + wxICON_ERROR)
          frmCadastros_edtCodigo:Clear()
      		frmCadastros_edtCodigo:SetFocus()
      	end
      end	
    end )

  return fCadLivros
end

function frmCadLivros_FazLayout(parent)
  sizer_1 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_2 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_3 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_4 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_5 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_21 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_20 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_37 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_36 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_35 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_34 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_33 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_19 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_32 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_18 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_31 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_30 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_29 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_28 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_27 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_17 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_26 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_25 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_6 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_24 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_6 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_5 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_4 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_8 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_9 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_8 = wx.wxGridSizer(2, 1, 0, 0)
  sizer_7 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  grid_sizer_7 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_7:AddWindow(frmCadastros_labCodigo, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_7:AddWindow(frmCadastros_edtCodigo, 0, 0, 0)
  sizer_7:AddSizer(grid_sizer_7, 0, 0, 0)
  sizer_7:AddWindow(frmCadastros_btnNovo, 0, wx.wxLEFT + wx.wxALIGN_BOTTOM, 5)
  sizer_5:AddSizer(sizer_7, 1, 0, 0)
  grid_sizer_8:AddWindow(frmCadastros_labDescricao, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_8:AddWindow(frmCadastros_edtDescricao, 0, 0, 0)
  sizer_8:AddSizer(grid_sizer_8, 0, 0, 0)
  grid_sizer_9:AddWindow(frmCadLivros_labEdicao, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_9:AddWindow(frmCadLivros_edtEdicao, 0, 0, 0)
  sizer_8:AddSizer(grid_sizer_9, 0, wx.wxLEFT, 2)
  sizer_5:AddSizer(sizer_8, 1, wx.wxEXPAND, 0)
  grid_sizer_4:AddWindow(frmCadLivros_labAnoPubli, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_4:AddWindow(frmCadLivros_edtAnoPubli, 0, 0, 0)
  sizer_6:AddSizer(grid_sizer_4, 0, 0, 0)
  grid_sizer_5:AddWindow(frmCadLivros_labEditora, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_5:AddWindow(frmCadLivros_edtCodEditora, 0, 0, 0)
  sizer_6:AddSizer(grid_sizer_5, 0, wx.wxLEFT, 4)
  grid_sizer_6:Add(20, 20, 0, 0, 0)
  grid_sizer_6:AddWindow(frmCadLivros_edtEditora, 0, 0, 0)
  sizer_6:AddSizer(grid_sizer_6, 0, wx.wxLEFT, 2)
  grid_sizer_24:Add(20, 20, 0, 0, 0)
  grid_sizer_24:AddWindow(frmCadLivros_btnPEditora, 0, 0, 0)
  sizer_6:AddSizer(grid_sizer_24, 0, 0, 0)
  sizer_5:AddSizer(sizer_6, 0, 0, 0)
  grid_sizer_25:AddWindow(frmCadLivros_labVolume, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_25:AddWindow(frmCadLivros_edtVolume, 0, 0, 0)
  sizer_17:AddSizer(grid_sizer_25, 0, wx.wxEXPAND, 0)
  grid_sizer_26:AddWindow(frmCadLivros_labIdioma, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_26:AddWindow(frmCadLivros_cmbIdioma, 0, 0, 0)
  sizer_17:AddSizer(grid_sizer_26, 0, wx.wxLEFT + wx.wxEXPAND, 4)
  sizer_5:AddSizer(sizer_17, 1, 0, 0)
  grid_sizer_27:AddWindow(frmCadLivros_labNPaginas, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_27:AddWindow(frmCadLivros_edtNPaginas, 0, 0, 0)
  sizer_18:AddSizer(grid_sizer_27, 0, 0, 0)
  grid_sizer_28:AddWindow(frmCadLivros_labAssunto, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_28:AddWindow(frmCadLivros_edtCodAssunto, 0, 0, 0)
  sizer_18:AddSizer(grid_sizer_28, 0, wx.wxLEFT, 4)
  grid_sizer_29:Add(20, 20, 0, 0, 0)
  grid_sizer_29:AddWindow(frmCadLivros_edtAssunto, 0, 0, 0)
  sizer_18:AddSizer(grid_sizer_29, 0, wx.wxLEFT, 2)
  grid_sizer_30:Add(20, 20, 0, 0, 0)
  grid_sizer_30:AddWindow(frmCadLivros_btnAdAssuntos, 0, 0, 0)
  sizer_18:AddSizer(grid_sizer_30, 0, 0, 0)
  grid_sizer_31:Add(20, 20, 0, 0, 0)
  grid_sizer_31:AddWindow(frmCadLivros_btnPAssunto, 0, 0, 0)
  sizer_18:AddSizer(grid_sizer_31, 0, 0, 0)
  sizer_5:AddSizer(sizer_18, 1, 0, 0)
  grid_sizer_32:AddWindow(frmCadLivros_labPreco, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_32:AddWindow(frmCadLivros_edtPreco, 0, 0, 0)
  sizer_19:AddSizer(grid_sizer_32, 0, 0, 0)
  sizer_19:AddWindow(frmCadLivros_lstAssuntos, 0, wx.wxLEFT, 4)
  sizer_5:AddSizer(sizer_19, 1, 0, 0)
  grid_sizer_33:AddWindow(frmCadLivros_labQtdEstoque, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_33:AddWindow(frmCadLivros_edtQtdEstoque, 0, 0, 0)
  sizer_20:AddSizer(grid_sizer_33, 0, 0, 0)
  grid_sizer_34:AddWindow(frmCadLivros_labAutor, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_34:AddWindow(frmCadLivros_edtCodAutor, 0, 0, 0)
  sizer_20:AddSizer(grid_sizer_34, 0, wx.wxLEFT, 4)
  grid_sizer_35:Add(20, 20, 0, 0, 0)
  grid_sizer_35:AddWindow(frmCadLivros_edtAutor, 0, 0, 0)
  sizer_20:AddSizer(grid_sizer_35, 0, wx.wxLEFT, 2)
  grid_sizer_36:Add(20, 20, 0, 0, 0)
  grid_sizer_36:AddWindow(frmCadLivros_btnAdAutores, 0, 0, 0)
  sizer_20:AddSizer(grid_sizer_36, 0, 0, 0)
  grid_sizer_37:Add(20, 20, 0, 0, 0)
  grid_sizer_37:AddWindow(frmCadLivros_btnPAutor, 0, 0, 0)
  sizer_20:AddSizer(grid_sizer_37, 0, 0, 0)
  sizer_5:AddSizer(sizer_20, 1, 0, 0)
  sizer_21:Add(92, 20, 0, 0, 0)
  sizer_21:AddWindow(frmCadLivros_lstAutores, 0, wx.wxLEFT, 4)
  sizer_5:AddSizer(sizer_21, 1, 0, 0)
  sizer_3:AddSizer(sizer_5, 0, 0, 0)
  sizer_4:AddWindow(frmCadastros_btnPesquisar, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_4:AddWindow(frmCadastros_btnAnterior, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_4:AddWindow(frmCadastros_btnProximo, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_3:AddSizer(sizer_4, 1, 0, 0)
  sizer_1:AddSizer(sizer_3, 1, wx.wxALL + wx.wxEXPAND, 4)
  sizer_2:AddWindow(frmCadastros_btnSalvar, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnExcluir, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnLimpar, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnFechar, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_1:AddSizer(sizer_2, 0, wx.wxRIGHT + wx.wxBOTTOM +
    wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 4)
  parent:SetAutoLayout(true)
  parent:SetSizer(sizer_1)
end

function frmCadLivros_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo:GetValue(),
    STR_CODNINF) then
    return false
  end
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao:GetValue(),
      STR_LIVNINF) then
    	return false
    end
    if Rotinas_ValidaCampo(frmCadLivros_edtEditora:GetValue(),
      STR_EDTNINF) then
    	return false
    end
    if frmCadLivros_lstAssuntos:GetCount() == 0 then
      wx.wxMessageBox(STR_ASSNINF, "Erro", wx.wxOK + wx.wxICON_ERROR)
      return false
    end
    if frmCadLivros_lstAutores:GetCount() == 0 then
      wx.wxMessageBox(STR_AUTNINF, "Erro", wx.wxOK + wx.wxICON_ERROR)
      return false
    end
  end
	return true
end

function frmCadLivros_InformaLimpaDados(bInformar)
  if bInformar then
    frmCadLivros_edtEdicao:SetValue(0)
    frmCadLivros_edtAnoPubli:SetValue(2005)
    frmCadLivros_edtVolume:SetValue(0)
    frmCadLivros_edtCodEditora:SetValue("5")
    frmCadLivros_edtEditora:SetValue("6")
    frmCadLivros_cmbIdioma:SetStringSelection("8")
    frmCadLivros_edtNPaginas:SetValue("9")
    --frmCadLivros_edtPreco:Value = Rotinas:VirgulaParaPonto( "10", true)
    frmCadLivros_edtQtdEstoque:SetValue("11")
    --Rotinas_AdicionaValoresLista(ConsSQL_LivroAss("S", 
    --  frmCadastros_edtCodigo:GetValue(), ""), 
    --  frmCadLivros_lstAssuntos, frmCadLivros_slAssuntos)
    --Rotinas_AdicionaValoresLista(ConsSQL_LivroAut("S", 
    --  frmCadastros_edtCodigo:GetValue(), ""), 
    --  frmCadLivros_lstAutores, frmCadLivros_slAutores)
  else  
    frmCadLivros_edtEdicao:SetValue("1")
    --frmCadLivros_edtAnoPubli:SetValue( Mid$(Rotinas_retDataHoraStr(true,false),7,4))
    frmCadLivros_edtVolume:SetValue("1")
    frmCadLivros_edtCodEditora:Clear()
    frmCadLivros_edtEditora:Clear()
    frmCadLivros_cmbIdioma:SetSelection(0)
    frmCadLivros_edtNPaginas:SetValue("1")
    frmCadLivros_edtPreco:SetValue("0,00")
    frmCadLivros_edtQtdEstoque:SetValue("1")
    frmCadLivros_edtCodAssunto:Clear()
    frmCadLivros_lstAssuntos:Clear()
    frmCadLivros_edtCodAutor:Clear()
    frmCadLivros_lstAutores:Clear()
    --frmCadLivros_slAssuntos:Clear()
    --frmCadLivros_slAutores:Clear()
  end
end

function frmCadLivros_HabilitaDados(bHabilita)
  frmCadLivros_edtEdicao:Enable(bHabilita)
  frmCadLivros_edtAnoPubli:Enable(bHabilita)
  frmCadLivros_edtVolume:Enable(bHabilita)
  frmCadLivros_edtCodEditora:Enable(bHabilita)
  frmCadLivros_btnPEditora:Enable(bHabilita)
  frmCadLivros_cmbIdioma:Enable(bHabilita)
  frmCadLivros_edtNPaginas:Enable(bHabilita)
  frmCadLivros_edtPreco:Enable(bHabilita)
  frmCadLivros_edtQtdEstoque:Enable(bHabilita)
  frmCadLivros_edtCodAssunto:Enable(bHabilita)
  frmCadLivros_btnPAssunto:Enable(bHabilita)
  frmCadLivros_btnAdAssuntos:Enable(bHabilita)
  frmCadLivros_lstAssuntos:Enable(bHabilita)
  frmCadLivros_edtCodAutor:Enable(bHabilita)
  frmCadLivros_btnPAutor:Enable(bHabilita)
  frmCadLivros_btnAdAutores:Enable(bHabilita)
  frmCadLivros_lstAutores:Enable(bHabilita)
end

