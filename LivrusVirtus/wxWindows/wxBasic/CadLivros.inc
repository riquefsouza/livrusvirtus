option explicit

Const ID_FRMCADLIVROS_BTNADASSUNTOS = 900
Const ID_FRMCADLIVROS_BTNADAUTORES = 901
Const ID_FRMCADLIVROS_BTNPASSUNTO = 902
Const ID_FRMCADLIVROS_BTNPAUTOR = 903
Const ID_FRMCADLIVROS_BTNPEDITORA = 904
Const ID_FRMCADLIVROS_CMBIDIOMA = 905
Const ID_FRMCADLIVROS_EDTANOPUBLI = 906
Const ID_FRMCADLIVROS_EDTASSUNTO = 907
Const ID_FRMCADLIVROS_EDTAUTOR = 908
Const ID_FRMCADLIVROS_EDTCODASSUNTO = 909
Const ID_FRMCADLIVROS_EDTCODAUTOR = 910
Const ID_FRMCADLIVROS_EDTCODEDITORA = 911
Const ID_FRMCADLIVROS_EDTEDICAO = 912
Const ID_FRMCADLIVROS_EDTEDITORA = 913
Const ID_FRMCADLIVROS_EDTNPAGINAS = 914
Const ID_FRMCADLIVROS_EDTPRECO = 915
Const ID_FRMCADLIVROS_EDTQTDESTOQUE = 916
Const ID_FRMCADLIVROS_EDTVOLUME = 917
Const ID_FRMCADLIVROS_LABANOPUBLI = 918
Const ID_FRMCADLIVROS_LABASSUNTO = 919
Const ID_FRMCADLIVROS_LABAUTOR = 920
Const ID_FRMCADLIVROS_LABEDICAO = 921
Const ID_FRMCADLIVROS_LABEDITORA = 922
Const ID_FRMCADLIVROS_LABIDIOMA = 923
Const ID_FRMCADLIVROS_LABNPAGINAS = 924
Const ID_FRMCADLIVROS_LABPRECO = 925
Const ID_FRMCADLIVROS_LABQTDESTOQUE = 926
Const ID_FRMCADLIVROS_LABVOLUME = 927
Const ID_FRMCADLIVROS_LSTASSUNTOS = 928
Const ID_FRMCADLIVROS_LSTAUTORES = 930

dim common frmCadLivros
dim common frmCadLivros_slIdiomas
dim common frmCadLivros_slAssuntos
dim common frmCadLivros_slAutores
dim common frmCadLivros_labEdicao
dim common frmCadLivros_edtEdicao
dim common frmCadLivros_labAnoPubli
dim common frmCadLivros_edtAnoPubli
dim common frmCadLivros_labEditora
dim common frmCadLivros_edtCodEditora
dim common frmCadLivros_edtEditora
dim common frmCadLivros_btnPEditora
dim common frmCadLivros_labVolume
dim common frmCadLivros_edtVolume
dim common frmCadLivros_labIdioma
dim common frmCadLivros_cmbIdioma
dim common frmCadLivros_labNPaginas
dim common frmCadLivros_edtNPaginas
dim common frmCadLivros_labAssunto
dim common frmCadLivros_edtCodAssunto
dim common frmCadLivros_edtAssunto
dim common frmCadLivros_btnAdAssuntos
dim common frmCadLivros_btnPAssunto
dim common frmCadLivros_lstAssuntos
dim common frmCadLivros_labPreco
dim common frmCadLivros_edtPreco
dim common frmCadLivros_labQtdEstoque
dim common frmCadLivros_edtQtdEstoque
dim common frmCadLivros_labAutor
dim common frmCadLivros_edtCodAutor
dim common frmCadLivros_edtAutor
dim common frmCadLivros_btnAdAutores
dim common frmCadLivros_btnPAutor
dim common frmCadLivros_lstAutores
dim common frmCadLivros_vsIdiomas[]

function frmCadLivros_Criar(parent)
  dim fCadLivros = frmCadastros_Criar(parent, 0, False)

  frmCadastros_labCodigo.SetLabel("ISBN: ")
  frmCadastros_labDescricao.SetLabel("Título: ")
  frmCadastros_edtDescricao.SetSize(312, 21)
  Connect( fCadLivros, ID_FRMCADASTROS_EDTCODIGO, 
    wxEVT_KILL_FOCUS, "frmCadLivros_OnEdtCodigo_Killfocus" )

  frmCadLivros_labEdicao = new wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABEDICAO,
    "Edição: ", wxPoint(326, 48), wxSize(39, 13), 0)
  frmCadLivros_edtEdicao = new wxSpinCtrl(fCadLivros, ID_FRMCADLIVROS_EDTEDICAO, 
    "1", wxPoint(324, 64), wxSize(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1)
  frmCadLivros_edtEdicao.Enable(False)

  frmCadLivros_labAnoPubli = new wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABANOPUBLI,
    "Ano Publicação: ", wxPoint(8, 88), wxSize(81, 13), 0)  
  frmCadLivros_edtAnoPubli = new wxSpinCtrl(fCadLivros, ID_FRMCADLIVROS_EDTANOPUBLI,
    "1", wxPoint(8, 104), wxSize(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1)
  frmCadLivros_edtAnoPubli.Enable(False)
  
  frmCadLivros_labEditora = new wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABEDITORA,
    "Editora: ", wxPoint(104, 88), wxSize(39, 13), 0)  
  frmCadLivros_edtCodEditora = new wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTCODEDITORA,
    "", wxPoint(104, 104), wxSize(78, 21), 0 )
  frmCadLivros_edtCodEditora.Enable(False)
  'Connect( fCadLivros, ID_FRMCADLIVROS_EDTCODEDITORA, 
  '  wxEVT_KILL_FOCUS, "frmCadLivros_OnEdtCodEditora_Killfocus" )
  
  frmCadLivros_edtEditora = new wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTEDITORA,
     "", wxPoint(184, 104), wxSize(216, 21), 0)
  frmCadLivros_edtEditora.Enable(False)
  
  frmCadLivros_btnPEditora = new wxButton(fCadLivros, ID_FRMCADLIVROS_BTNPEDITORA,
    "...", wxPoint(400, 104), wxSize(21, 21), 0)
  frmCadLivros_btnPEditora.Enable(False)
  
  frmCadLivros_labVolume = new wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABVOLUME,
    "Volume: ", wxPoint(8, 128), wxSize(41, 13), 0)  
  frmCadLivros_edtVolume = new wxSpinCtrl(fCadLivros, ID_FRMCADLIVROS_EDTVOLUME,
    "1", wxPoint(8, 144), wxSize(92, 21), wxSP_ARROW_KEYS,
    1, 9999, 1)
  frmCadLivros_edtVolume.Enable(False)
  
  frmCadLivros_labIdioma = new wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABIDIOMA,
    "Idioma: ", wxPoint(104, 128), wxSize(56, 13), 0)

  frmCadLivros_cmbIdioma = new wxChoice(fCadLivros, ID_FRMCADLIVROS_CMBIDIOMA,
    wxPoint(104, 144), wxSize(320, 21))
  frmCadLivros_cmbIdioma.Enable(False)
  'frmCadLivros_AdicionaCombo()
  
  frmCadLivros_labNPaginas = new wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABNPAGINAS,
    "Nº Páginas: ", wxPoint(8, 168), wxSize(59, 13), 0)
  
  frmCadLivros_edtNPaginas = new wxSpinCtrl(fCadLivros, ID_FRMCADLIVROS_EDTNPAGINAS,
    "1", wxPoint(8, 184), wxSize(92, 21), wxSP_ARROW_KEYS,
    1, 9999, 1)
  frmCadLivros_edtNPaginas.Enable(False)
  
  frmCadLivros_labAssunto = new wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABASSUNTO,
    "Assunto: ", wxPoint(104, 168), wxSize(44, 13), 0)
  
  frmCadLivros_edtCodAssunto = new wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTCODASSUNTO,
    "", wxPoint(104, 184), wxSize(78, 21), 0)
  frmCadLivros_edtCodAssunto.Enable(False)
  'Connect( fCadLivros, ID_FRMCADLIVROS_EDTCODASSUNTO, 
  '  wxEVT_KILL_FOCUS, "frmCadLivros_OnEdtCodAssunto_Killfocus" )
  
  frmCadLivros_edtAssunto = new wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTASSUNTO,
    "", wxPoint(184, 184), wxSize(192, 21), 0)
  frmCadLivros_edtAssunto.Enable(False)
  
  frmCadLivros_btnAdAssuntos = new wxButton(fCadLivros, ID_FRMCADLIVROS_BTNADASSUNTOS,
    "+", wxPoint(376, 184), wxSize(21, 21), 0)
  frmCadLivros_btnAdAssuntos.Enable(False)
  
  frmCadLivros_btnPAssunto = new wxButton(fCadLivros, ID_FRMCADLIVROS_BTNPASSUNTO,
    "...", wxPoint(400, 184), wxSize(21, 21), 0)
  frmCadLivros_btnPAssunto.Enable(False)

  frmCadLivros_lstAssuntos = new wxListBox(fCadLivros, ID_FRMCADLIVROS_LSTASSUNTOS,
    wxPoint(104, 208), wxSize(320, 48))
  frmCadLivros_lstAssuntos.Enable(False)
  
  frmCadLivros_labPreco = new wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABPRECO,
    "Preço: ", wxPoint(8, 216), wxSize(40, 13), 0)
  
  frmCadLivros_edtPreco = new wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTPRECO,
    "", wxPoint(7, 232), wxSize(92, 21), 0)
  frmCadLivros_edtPreco.Enable(False)
  'Connect( fCadLivros, ID_FRMCADLIVROS_EDTPRECO, 
  '  wxEVT_KILL_FOCUS, "frmCadLivros_OnEdtCodPreco_Killfocus" )
  
  frmCadLivros_labQtdEstoque = new wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABQTDESTOQUE,
    "Qtd. Estoque: ", wxPoint(6, 256), wxSize(68, 13), 0)
  
  frmCadLivros_edtQtdEstoque = new wxSpinCtrl(fCadLivros, ID_FRMCADLIVROS_EDTQTDESTOQUE,
    "0", wxPoint(8, 272), wxSize(92, 21), wxSP_ARROW_KEYS,
    0, 9999, 0)
  frmCadLivros_edtQtdEstoque.Enable(False)
  
  frmCadLivros_labAutor = new wxStaticText(fCadLivros, ID_FRMCADLIVROS_LABAUTOR,
    "Autor: ", wxPoint(104, 256), wxSize(31, 13), 0)  
  frmCadLivros_edtCodAutor = new wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTCODAUTOR,
    "", wxPoint(104, 272), wxSize(78, 21), 0)
  frmCadLivros_edtCodAutor.Enable(False)
  'Connect( fCadLivros, ID_FRMCADLIVROS_EDTCODAUTOR, 
  '  wxEVT_KILL_FOCUS, "frmCadLivros_OnEdtCodAutor_Killfocus" )
  
  frmCadLivros_edtAutor = new wxTextCtrl(fCadLivros, ID_FRMCADLIVROS_EDTAUTOR,
    "", wxPoint(184, 272), wxSize(192, 21), 0)
  frmCadLivros_edtAutor.Enable(False)
  
  frmCadLivros_btnAdAutores = new wxButton(fCadLivros, ID_FRMCADLIVROS_BTNADAUTORES,
    "+", wxPoint(376, 272), wxSize(21, 21), 0)
  frmCadLivros_btnAdAutores.Enable(False)
  
  frmCadLivros_btnPAutor = new wxButton(fCadLivros, ID_FRMCADLIVROS_BTNPAUTOR, "...",
    wxPoint(400, 272), wxSize(21, 21), 0)
  frmCadLivros_btnPAutor.Enable(False)

  frmCadLivros_lstAutores = new wxListBox(fCadLivros, ID_FRMCADLIVROS_LSTAUTORES,
    wxPoint(104, 296), wxSize(320, 48))
  frmCadLivros_lstAutores.Enable(False)

  frmCadastros_IniciaBotoes(fCadLivros)
  frmCadastros_btnPesquisar.SetDimensions(427, 8, 75, 25)
  frmCadastros_btnAnterior.SetDimensions(427, 40, 75, 25)
  frmCadastros_btnProximo.SetDimensions(427, 72, 75, 25)
  frmCadastros_btnSalvar.SetDimensions(187, 352, 75, 25)
  frmCadastros_btnExcluir.SetDimensions(267, 352, 75, 25)
  frmCadastros_btnLimpar.SetDimensions(347, 352, 75, 25)
  frmCadastros_btnFechar.SetDimensions(427, 352, 75, 25)

  frmCadastros_FazLayout(fCadLivros)

	'frmCadastros_edtCodigo.MaxLength = 13
  'frmCadastros_edtDescricao.MaxLength = 50
  'frmCadLivros_edtCodEditora.MaxLength = 5
  'frmCadLivros_edtPreco.MaxLength = 7

  Connect( fCadLivros, wxEVT_CLOSE_WINDOW, "frmCadLivros_OnClose" )
  Connect( fCadLivros, ID_FRMCADASTROS_BTNNOVO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnNovo" )
  Connect( fCadLivros, ID_FRMCADASTROS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnPesquisar" )
  Connect( fCadLivros, ID_FRMCADASTROS_BTNANTERIOR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnAnterior" )
  Connect( fCadLivros, ID_FRMCADASTROS_BTNPROXIMO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnProximo" )
  Connect( fCadLivros, ID_FRMCADASTROS_BTNSALVAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnSalvar" )
  Connect( fCadLivros, ID_FRMCADASTROS_BTNEXCLUIR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnExcluir" )
  Connect( fCadLivros, ID_FRMCADASTROS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnFechar" )
  Connect( fCadLivros, ID_FRMCADASTROS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnLimpar" )
  'Connect( fCadLivros, ID_FRMCADLIVROS_BTNPEDITORA,
  '  wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnPEditora" )
  'Connect( fCadLivros, ID_FRMCADLIVROS_BTNPASSUNTO, 
  '  wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnPAssunto" )
  'Connect( fCadLivros, ID_FRMCADLIVROS_BTNADASSUNTOS, 
  '  wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnAdAssuntos" )
  'Connect( fCadLivros, ID_FRMCADLIVROS_BTNPAUTOR,
  '  wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnPAutor" )
  'Connect( fCadLivros, ID_FRMCADLIVROS_BTNADAUTORES,
  '  wxEVT_COMMAND_BUTTON_CLICKED, "frmCadLivros_OnBtnAdAutores" )
  'Connect( fCadLivros, ID_FRMCADLIVROS_LSTASSUNTOS,
  '  wxEVT_LISTBOX_DCLICK, "frmCadLivros_OnLstAssuntos_Dblclk" )
  'Connect( fCadLivros, ID_FRMCADLIVROS_LSTAUTORES,
  '  wxEVT_LISTBOX_DCLICK, "frmCadLivros_OnLstAutores_Dblclk" )

  return fCadLivros
end function

sub frmCadLivros_FazLayout(parent)
  dim sizer_1 = new wxBoxSizer(wxVERTICAL)
  dim sizer_2 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_3 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_4 = new wxBoxSizer(wxVERTICAL)
  dim sizer_5 = new wxBoxSizer(wxVERTICAL)
  dim sizer_21 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_20 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_37 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_36 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_35 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_34 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_33 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_19 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_32 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_18 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_31 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_30 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_29 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_28 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_27 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_17 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_26 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_25 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_6 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_24 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_6 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_5 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_4 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_8 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_9 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_8 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_7 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_7 = new wxGridSizer(2, 1, 0, 0)
  grid_sizer_7.Add(frmCadastros_labCodigo, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_7.Add(frmCadastros_edtCodigo, 0, 0, 0)
  sizer_7.Add(grid_sizer_7, 0, 0, 0)
  sizer_7.Add(frmCadastros_btnNovo, 0, wxLEFT + wxALIGN_BOTTOM, 5)
  sizer_5.Add(sizer_7, 1, 0, 0)
  grid_sizer_8.Add(frmCadastros_labDescricao, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_8.Add(frmCadastros_edtDescricao, 0, 0, 0)
  sizer_8.Add(grid_sizer_8, 0, 0, 0)
  grid_sizer_9.Add(frmCadLivros_labEdicao, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_9.Add(frmCadLivros_edtEdicao, 0, 0, 0)
  sizer_8.Add(grid_sizer_9, 0, wxLEFT, 2)
  sizer_5.Add(sizer_8, 1, wxEXPAND, 0)
  grid_sizer_4.Add(frmCadLivros_labAnoPubli, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_4.Add(frmCadLivros_edtAnoPubli, 0, 0, 0)
  sizer_6.Add(grid_sizer_4, 0, 0, 0)
  grid_sizer_5.Add(frmCadLivros_labEditora, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_5.Add(frmCadLivros_edtCodEditora, 0, 0, 0)
  sizer_6.Add(grid_sizer_5, 0, wxLEFT, 4)
  grid_sizer_6.Add(20, 20, 0, 0, 0)
  grid_sizer_6.Add(frmCadLivros_edtEditora, 0, 0, 0)
  sizer_6.Add(grid_sizer_6, 0, wxLEFT, 2)
  grid_sizer_24.Add(20, 20, 0, 0, 0)
  grid_sizer_24.Add(frmCadLivros_btnPEditora, 0, 0, 0)
  sizer_6.Add(grid_sizer_24, 0, 0, 0)
  sizer_5.Add(sizer_6, 0, 0, 0)
  grid_sizer_25.Add(frmCadLivros_labVolume, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_25.Add(frmCadLivros_edtVolume, 0, 0, 0)
  sizer_17.Add(grid_sizer_25, 0, wxEXPAND, 0)
  grid_sizer_26.Add(frmCadLivros_labIdioma, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_26.Add(frmCadLivros_cmbIdioma, 0, 0, 0)
  sizer_17.Add(grid_sizer_26, 0, wxLEFT + wxEXPAND, 4)
  sizer_5.Add(sizer_17, 1, 0, 0)
  grid_sizer_27.Add(frmCadLivros_labNPaginas, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_27.Add(frmCadLivros_edtNPaginas, 0, 0, 0)
  sizer_18.Add(grid_sizer_27, 0, 0, 0)
  grid_sizer_28.Add(frmCadLivros_labAssunto, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_28.Add(frmCadLivros_edtCodAssunto, 0, 0, 0)
  sizer_18.Add(grid_sizer_28, 0, wxLEFT, 4)
  grid_sizer_29.Add(20, 20, 0, 0, 0)
  grid_sizer_29.Add(frmCadLivros_edtAssunto, 0, 0, 0)
  sizer_18.Add(grid_sizer_29, 0, wxLEFT, 2)
  grid_sizer_30.Add(20, 20, 0, 0, 0)
  grid_sizer_30.Add(frmCadLivros_btnAdAssuntos, 0, 0, 0)
  sizer_18.Add(grid_sizer_30, 0, 0, 0)
  grid_sizer_31.Add(20, 20, 0, 0, 0)
  grid_sizer_31.Add(frmCadLivros_btnPAssunto, 0, 0, 0)
  sizer_18.Add(grid_sizer_31, 0, 0, 0)
  sizer_5.Add(sizer_18, 1, 0, 0)
  grid_sizer_32.Add(frmCadLivros_labPreco, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_32.Add(frmCadLivros_edtPreco, 0, 0, 0)
  sizer_19.Add(grid_sizer_32, 0, 0, 0)
  sizer_19.Add(frmCadLivros_lstAssuntos, 0, wxLEFT, 4)
  sizer_5.Add(sizer_19, 1, 0, 0)
  grid_sizer_33.Add(frmCadLivros_labQtdEstoque, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_33.Add(frmCadLivros_edtQtdEstoque, 0, 0, 0)
  sizer_20.Add(grid_sizer_33, 0, 0, 0)
  grid_sizer_34.Add(frmCadLivros_labAutor, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_34.Add(frmCadLivros_edtCodAutor, 0, 0, 0)
  sizer_20.Add(grid_sizer_34, 0, 0, 0)
  grid_sizer_35.Add(20, 20, 0, 0, 0)
  grid_sizer_35.Add(frmCadLivros_edtAutor, 0, 0, 0)
  sizer_20.Add(grid_sizer_35, 0, wxLEFT, 2)
  grid_sizer_36.Add(20, 20, 0, 0, 0)
  grid_sizer_36.Add(frmCadLivros_btnAdAutores, 0, 0, 0)
  sizer_20.Add(grid_sizer_36, 0, 0, 0)
  grid_sizer_37.Add(20, 20, 0, 0, 0)
  grid_sizer_37.Add(frmCadLivros_btnPAutor, 0, 0, 0)
  sizer_20.Add(grid_sizer_37, 0, 0, 0)
  sizer_5.Add(sizer_20, 1, 0, 0)
  sizer_21.Add(92, 20, 0, 0, 0)
  sizer_21.Add(frmCadLivros_lstAutores, 0, 0, 0)
  sizer_5.Add(sizer_21, 0, 0, 0)
  sizer_3.Add(sizer_5, 0, 0, 0)
  sizer_4.Add(frmCadastros_btnPesquisar, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_4.Add(frmCadastros_btnAnterior, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_4.Add(frmCadastros_btnProximo, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_3.Add(sizer_4, 1, 0, 0)
  sizer_1.Add(sizer_3, 1, wxALL + wxEXPAND, 4)
  sizer_2.Add(frmCadastros_btnSalvar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_2.Add(frmCadastros_btnExcluir, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_2.Add(frmCadastros_btnLimpar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_2.Add(frmCadastros_btnFechar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_1.Add(sizer_2, 0, wxRIGHT + wxBOTTOM +
    wxALIGN_RIGHT + wxALIGN_BOTTOM, 4)
  parent.AutoLayout(True)
  parent.SetSizer(sizer_1)
end sub

function frmCadLivros_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo.GetValue(),
    STR_CODNINF) then
    return False
  end if
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao.GetValue(),
      STR_LIVNINF) then
    	return False
    end if
    if Rotinas_ValidaCampo(frmCadLivros_edtEditora.GetValue(),
      STR_EDTNINF) then
    	return False
    end if
    if frmCadLivros_lstAssuntos.GetCount() = 0 then
      wxMessageBox(STR_ASSNINF, "Erro", wxOK + wxICON_ERROR)
      return False
    end if
    if frmCadLivros_lstAutores.GetCount() = 0 then
      wxMessageBox(STR_AUTNINF, "Erro", wxOK + wxICON_ERROR)
      return False
    end if
  end if
	return True
end function

Function frmCadLivros_OnClose( event )
  frmCadLivros.GetParent().Close(True)
	event.Skip()
End Function

function frmCadLivros_OnBtnNovo( event )
  frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadLivros_InformaLimpaDados(False)
  frmCadLivros_HabilitaDados(True)
  event.Skip()
end function

function frmCadLivros_OnBtnPesquisar( event )
  if frmCadastros_PesquisarDados(ConsSQL_Livro("S", 
    frmCadastros_edtCodigo.GetValue(),"","","","","","","","",""), STR_LIVNENC,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir) then
    frmCadLivros_InformaLimpaDados(True)
    frmCadLivros_HabilitaDados(True)
  end if
  event.Skip()
end function

function frmCadLivros_OnBtnAnterior( event )
  if frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao) then
    frmCadLivros_InformaLimpaDados(True)
  end if	
  event.Skip()
end function

function frmCadLivros_OnBtnProximo( event )
  if frmCadastros_registroProximo(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao) then
    frmCadLivros_InformaLimpaDados(True)
  end if	
  event.Skip()
end function

function frmCadLivros_OnBtnSalvar( event )
  if frmCadastros_SalvarDados(frmCadLivros_ValidaDados(True),
    ConsSQL_Livro("S", frmCadastros_edtCodigo.GetValue(),
    "","","","","","","","",""),
    ConsSQL_Livro("U", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue(),"","","","","","","",""),
    ConsSQL_Livro("I", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue(),"","","","","","","",""), True,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir) then
    frmCadLivros_InformaLimpaDados(False)
    frmCadLivros_HabilitaDados(False)
  end if
  event.Skip()
end function

function frmCadLivros_OnBtnExcluir( event )
  if frmCadastros_ExcluirDados(frmCadLivros_ValidaDados(False),
    ConsSQL_Livro("D", frmCadastros_edtCodigo.GetValue(),
    "","","","","","","","",""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir) then
    frmCadLivros_InformaLimpaDados(False)
    frmCadLivros_HabilitaDados(False)
  end if
  event.Skip()
end function

function frmCadLivros_OnBtnFechar( event )
  frmCadLivros.Close(True)
  event.Skip()
end function

function frmCadLivros_OnBtnLimpar( event )
  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadLivros_InformaLimpaDados(False)
  frmCadLivros_HabilitaDados(False)
  event.Skip()
end function

sub frmCadLivros_InformaLimpaDados(bInformar) 
  if bInformar then
    frmCadLivros_edtEdicao.SetValue(0)
    frmCadLivros_edtAnoPubli.SetValue(2005)
    frmCadLivros_edtVolume.SetValue(0)
    frmCadLivros_edtCodEditora.SetValue("5")
    frmCadLivros_edtEditora.SetValue("6")
    frmCadLivros_cmbIdioma.SetStringSelection("8")
    frmCadLivros_edtNPaginas.SetValue("9")
    'frmCadLivros_edtPreco.Value = Rotinas.VirgulaParaPonto( "10", True)
    frmCadLivros_edtQtdEstoque.SetValue("11")
    'Rotinas_AdicionaValoresLista(ConsSQL_LivroAss("S", 
    '  frmCadastros_edtCodigo.GetValue(), ""), 
    '  frmCadLivros_lstAssuntos, frmCadLivros_slAssuntos)
    'Rotinas_AdicionaValoresLista(ConsSQL_LivroAut("S", 
    '  frmCadastros_edtCodigo.GetValue(), ""), 
    '  frmCadLivros_lstAutores, frmCadLivros_slAutores)
  else  
    frmCadLivros_edtEdicao.SetValue("1")
    'frmCadLivros_edtAnoPubli.SetValue( Mid$(Rotinas_retDataHoraStr(True,False),7,4))
    frmCadLivros_edtVolume.SetValue("1")
    frmCadLivros_edtCodEditora.Clear()
    frmCadLivros_edtEditora.Clear()
    frmCadLivros_cmbIdioma.SetSelection(0)
    frmCadLivros_edtNPaginas.SetValue("1")
    frmCadLivros_edtPreco.SetValue("0,00")
    frmCadLivros_edtQtdEstoque.SetValue("1")
    frmCadLivros_edtCodAssunto.Clear()
    frmCadLivros_lstAssuntos.Clear()
    frmCadLivros_edtCodAutor.Clear()
    frmCadLivros_lstAutores.Clear()
    'frmCadLivros_slAssuntos.Clear()
    'frmCadLivros_slAutores.Clear()
  end if
end sub 

sub frmCadLivros_HabilitaDados(bHabilita)
  frmCadLivros_edtEdicao.Enable(bHabilita)
  frmCadLivros_edtAnoPubli.Enable(bHabilita)
  frmCadLivros_edtVolume.Enable(bHabilita)
  frmCadLivros_edtCodEditora.Enable(bHabilita)
  frmCadLivros_btnPEditora.Enable(bHabilita)
  frmCadLivros_cmbIdioma.Enable(bHabilita)
  frmCadLivros_edtNPaginas.Enable(bHabilita)
  frmCadLivros_edtPreco.Enable(bHabilita)
  frmCadLivros_edtQtdEstoque.Enable(bHabilita)
  frmCadLivros_edtCodAssunto.Enable(bHabilita)
  frmCadLivros_btnPAssunto.Enable(bHabilita)
  frmCadLivros_btnAdAssuntos.Enable(bHabilita)
  frmCadLivros_lstAssuntos.Enable(bHabilita)
  frmCadLivros_edtCodAutor.Enable(bHabilita)
  frmCadLivros_btnPAutor.Enable(bHabilita)
  frmCadLivros_btnAdAutores.Enable(bHabilita)
  frmCadLivros_lstAutores.Enable(bHabilita)
end sub

function frmCadLivros_OnEdtCodigo_Killfocus( event )
  if Length(frmCadastros_edtCodigo.GetValue()) > 0 then
  	if Rotinas_ValidaISBN(frmCadastros_edtCodigo.GetValue())=False then
      wxMessageBox(STR_ISBNINV, "Erro", wxOK + wxICON_ERROR)
      frmCadastros_edtCodigo.Clear()
  		frmCadastros_edtCodigo.SetFocus()
  	end if
  end if	
end function
