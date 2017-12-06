option explicit

Const ID_FRMVENDERLIVROS_BTNVENDER = 3000
Const ID_FRMVENDERLIVROS_BTNLIMPAR = 3001 
Const ID_FRMVENDERLIVROS_BTNFECHAR = 3002 
Const ID_FRMVENDERLIVROS_BTNPCLIENTE = 3003
Const ID_FRMVENDERLIVROS_BTNPLIVRO = 3004 
Const ID_FRMVENDERLIVROS_LSTLIVROS = 3005
Const ID_FRMVENDERLIVROS_EDTDTHRVENDA = 3006 
Const ID_FRMVENDERLIVROS_EDTISBN = 3007 
Const ID_FRMVENDERLIVROS_EDTLIVRO = 3008 
Const ID_FRMVENDERLIVROS_EDTPRECOTOTAL = 3009 
Const ID_FRMVENDERLIVROS_LABDTHRVENDA = 3010 
Const ID_FRMVENDERLIVROS_LABISBN = 3011 
Const ID_FRMVENDERLIVROS_LABLIVRO = 3012 
Const ID_FRMVENDERLIVROS_LABLIVROS = 3013 
Const ID_FRMVENDERLIVROS_LABPRECOTOTAL = 3014 
Const ID_FRMVENDERLIVROS_BTNADLIVROS = 3015

dim common frmVenderLivros
dim common frmVenderLivros_slPrecos
dim common frmVenderLivros_slISBNs
dim common frmVenderLivros_slQtdEstoque
dim common frmVenderLivros_nPrecoTotal
dim common frmVenderLivros_labDtHrVenda
dim common frmVenderLivros_edtDtHrVenda
dim common frmVenderLivros_btnPCliente
dim common frmVenderLivros_labISBN
dim common frmVenderLivros_edtISBN
dim common frmVenderLivros_labLivro
dim common frmVenderLivros_edtLivro
dim common frmVenderLivros_btnAdLivros
dim common frmVenderLivros_btnPLivro
dim common frmVenderLivros_labLivros
dim common frmVenderLivros_lstLivros
dim common frmVenderLivros_labPrecoTotal
dim common frmVenderLivros_edtPrecoTotal
dim common frmVenderLivros_btnVender

function frmVenderLivros_Criar(parent)
  dim fVenderLivros = frmCadastros_Criar(parent, 0, False)

  frmCadastros_btnNovo.Show(False)

  frmVenderLivros_labDtHrVenda = new wxStaticText(fVenderLivros, ID_FRMVENDERLIVROS_LABDTHRVENDA,
    "Data/Hora Venda: ", wxPoint(8, 8), wxSize(91, 13), 0)  
  frmVenderLivros_edtDtHrVenda = new wxTextCtrl(fVenderLivros, ID_FRMVENDERLIVROS_EDTDTHRVENDA,
    "", wxPoint(8, 24), wxSize(128, 21), 0)
  frmVenderLivros_edtDtHrVenda.Enable(False)

  frmCadastros_labCodigo.SetLabel("CPF: ")
  frmCadastros_labCodigo.SetDimensions(8, 48, 48, 13) 
  frmCadastros_edtCodigo.SetDimensions(8, 64, 128, 21)
  'Connect( fVenderLivros, ID_FRMCADASTROS_EDTCODIGO, 
  '  wxEVT_KILL_FOCUS, "frmVenderLivros_OnEdtCodigo_Killfocus" )

  frmCadastros_labDescricao.SetLabel("Cliente: ")
  frmCadastros_labDescricao.SetDimensions(142, 48, 56, 13)  
  frmCadastros_edtDescricao.SetDimensions(142, 64, 306, 21)
  frmCadastros_edtDescricao.Enable(False)
 
  frmVenderLivros_btnPCliente = new wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNPCLIENTE,
    "...", wxPoint(448, 64), wxSize(21, 21), 0)
  
  frmVenderLivros_labISBN = new wxStaticText(fVenderLivros, ID_FRMVENDERLIVROS_LABISBN,
    "ISBN: ", wxPoint(8, 88), wxSize(48, 13), 0)  
  frmVenderLivros_edtISBN = new wxTextCtrl(fVenderLivros, ID_FRMVENDERLIVROS_EDTISBN,
    "", wxPoint(8, 104), wxSize(128, 21), 0)
  'Connect( fVenderLivros, ID_FRMVENDERLIVROS_EDTISBN, 
  '  wxEVT_KILL_FOCUS, "frmVenderLivros_OnEdtISBN_Killfocus" )
  
  frmVenderLivros_labLivro = new wxStaticText(fVenderLivros, ID_FRMVENDERLIVROS_LABLIVRO,
    "Livro: ", wxPoint(142, 88), wxSize(40, 13), 0)  
  frmVenderLivros_edtLivro = new wxTextCtrl(fVenderLivros, ID_FRMVENDERLIVROS_EDTLIVRO,
    "", wxPoint(142, 104), wxSize(282, 21), 0)
  frmVenderLivros_edtLivro.Enable(False)

  frmVenderLivros_btnAdLivros = new wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNADLIVROS,
  "+", wxPoint(424, 104), wxSize(21, 21), 0)
  
  frmVenderLivros_btnPLivro = new wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNPLIVRO,
    "...", wxPoint(448, 104), wxSize(21, 21), 0)
  
  frmVenderLivros_labLivros = new wxStaticText(fVenderLivros, ID_FRMVENDERLIVROS_LABLIVROS,
    "Livros para vender: ", wxPoint(8, 128), wxSize(120, 13), 0)
  
  frmVenderLivros_lstLivros = new wxListBox(fVenderLivros, ID_FRMVENDERLIVROS_LSTLIVROS,
    wxPoint(8, 144), wxSize(464, 96))
  
  frmVenderLivros_labPrecoTotal = new wxStaticText(fVenderLivros, ID_FRMVENDERLIVROS_LABPRECOTOTAL,
    "Preço Total: ", wxPoint(280, 248), wxSize(61, 13), 0)  
  frmVenderLivros_edtPrecoTotal = new wxTextCtrl(fVenderLivros, ID_FRMVENDERLIVROS_EDTPRECOTOTAL,
    "R$ 0,00", wxPoint(344, 246), wxSize(127, 21), 0)
  frmVenderLivros_edtPrecoTotal.Enable(False)
  
  frmVenderLivros_btnVender = new wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNVENDER,
    "&Vender", wxPoint(239, 275), wxSize(75, 25), 0)  
  frmCadastros_btnLimpar = new wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNLIMPAR,
    "&Limpar", wxPoint(319, 275), wxSize(75, 25), 0)  
  frmCadastros_btnFechar = new wxButton(fVenderLivros, ID_FRMVENDERLIVROS_BTNFECHAR,
    "&Fechar", wxPoint(399, 275), wxSize(75, 25), 0)

  frmVenderLivros_FazLayout(fVenderLivros)

  frmVenderLivros_edtDtHrVenda.SetValue(Rotinas_retDataHoraStr(True, True))
  'frmCadastros_edtCodigo.MaxLength = 14
  'frmVenderLivros_edtISBN.MaxLength = 13
  frmVenderLivros_nPrecoTotal = 0

  Connect( fVenderLivros, wxEVT_CLOSE_WINDOW, "frmVenderLivros_OnClose" )
  Connect( fVenderLivros, ID_FRMVENDERLIVROS_BTNVENDER, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmVenderLivros_OnBtnVender" )
  Connect( fVenderLivros, ID_FRMVENDERLIVROS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmVenderLivros_OnBtnFechar" )
  Connect( fVenderLivros, ID_FRMVENDERLIVROS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmVenderLivros_OnBtnLimpar" )
  'Connect( fVenderLivros, ID_FRMVENDERLIVROS_BTNPCLIENTE,
  '  wxEVT_COMMAND_BUTTON_CLICKED, "frmVenderLivros_OnBtnPCliente" )
  'Connect( fVenderLivros, ID_FRMVENDERLIVROS_BTNPLIVRO, 
  '  wxEVT_COMMAND_BUTTON_CLICKED, "frmVenderLivros_OnBtnPLivro" )
  'Connect( fVenderLivros, ID_FRMVENDERLIVROS_BTNADLIVROS, 
  '  wxEVT_COMMAND_BUTTON_CLICKED, "frmVenderLivros_OnBtnAdLivros" )
  'Connect( fVenderLivros, ID_FRMVENDERLIVROS_LSTLIVROS, _
  '  wxEVT_LISTBOX_DCLICK, "frmVenderLivros_OnLstLivros_Dblclk" )

  return fVenderLivros
end function

sub frmVenderLivros_FazLayout(parent)
  dim sizer_1 = new wxBoxSizer(wxVERTICAL)
  dim sizer_6 = new wxBoxSizer(wxVERTICAL)
  dim sizer_8 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_7 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_5 = new wxBoxSizer(wxVERTICAL)
  dim sizer_4 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_8 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_7 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_6 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_5 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_3 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_4 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_3 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_2 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_2 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_1 = new wxGridSizer(2, 1, 0, 0)
  grid_sizer_1.Add(frmVenderLivros_labDtHrVenda, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_1.Add(frmVenderLivros_edtDtHrVenda, 0, 0, 0)
  sizer_2.Add(grid_sizer_1, 0, wxLEFT, 2)
  sizer_2.Add(20, 20, 0, 0, 0)
  sizer_1.Add(sizer_2, 0, 0, 0)
  grid_sizer_2.Add(frmCadastros_labCodigo, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_2.Add(frmCadastros_edtCodigo, 0, 0, 0)
  sizer_3.Add(grid_sizer_2, 0, wxLEFT, 2)
  grid_sizer_3.Add(frmCadastros_labDescricao, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_3.Add(frmCadastros_edtDescricao, 0, 0, 0)
  sizer_3.Add(grid_sizer_3, 0, wxLEFT, 2)
  grid_sizer_4.Add(20, 20, 0, 0, 0)
  grid_sizer_4.Add(frmVenderLivros_btnPCliente, 0, 0, 0)
  sizer_3.Add(grid_sizer_4, 0, 0, 0)
  sizer_1.Add(sizer_3, 0, 0, 0)
  grid_sizer_5.Add(frmVenderLivros_labISBN, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_5.Add(frmVenderLivros_edtISBN, 0, 0, 0)
  sizer_4.Add(grid_sizer_5, 0, wxLEFT, 2)
  grid_sizer_6.Add(frmVenderLivros_labLivro, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_6.Add(frmVenderLivros_edtLivro, 0, 0, 0)
  sizer_4.Add(grid_sizer_6, 0, wxLEFT, 2)
  grid_sizer_7.Add(20, 20, 0, 0, 0)
  grid_sizer_7.Add(frmVenderLivros_btnAdLivros, 0, 0, 0)
  sizer_4.Add(grid_sizer_7, 1, wxEXPAND, 0)
  grid_sizer_8.Add(20, 20, 0, 0, 0)
  grid_sizer_8.Add(frmVenderLivros_btnPLivro, 0, 0, 0)
  sizer_4.Add(grid_sizer_8, 0, 0, 0)
  sizer_1.Add(sizer_4, 0, 0, 0)
  sizer_5.Add(frmVenderLivros_labLivros, 0, wxALIGN_BOTTOM, 0)
  sizer_5.Add(frmVenderLivros_lstLivros, 1, wxALL + wxEXPAND, 1)
  sizer_1.Add(sizer_5, 1, wxEXPAND, 0)
  sizer_7.Add(frmVenderLivros_labPrecoTotal, 0, wxALL, 2)
  sizer_7.Add(frmVenderLivros_edtPrecoTotal, 0, wxALL, 2)
  sizer_6.Add(sizer_7, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_8.Add(frmVenderLivros_btnVender, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_8.Add(frmCadastros_btnLimpar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_8.Add(frmCadastros_btnFechar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_6.Add(sizer_8, 0, wxALL, 2)
  sizer_1.Add(sizer_6, 0, wxALIGN_RIGHT + wxALIGN_BOTTOM, 0)
  parent.SetAutoLayout(True)
  parent.SetSizer(sizer_1)
  sizer_1.Fit(parent)
  sizer_1.SetSizeHints(parent)
end sub

sub frmVenderLivros_LimpaDados()
  frmVenderLivros_edtDtHrVenda.SetValue(Rotinas_retDataHoraStr(True, True))
  frmCadastros_edtCodigo.Clear()
  frmCadastros_edtDescricao.Clear()
  frmVenderLivros_edtISBN.Clear()
  frmVenderLivros_edtLivro.Clear()
  frmVenderLivros_lstLivros.Clear()
  frmVenderLivros_nPrecoTotal = 0
  frmVenderLivros_edtPrecoTotal.SetValue("R$ 0,00")
  frmCadastros_edtCodigo.SetFocus()
end sub

function frmVenderLivros_ValidaDados()
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo.GetValue(), 
    STR_CPFNINF) then
    return False
  end if
  if frmVenderLivros_lstLivros.GetCount() = 0 then
    wxMessageBox(STR_LIVVENNINF, "Erro", wxOK + wxICON_ERROR)
    return False
  end if
	return True
end function


function frmVenderLivros_OnClose( event )
  frmVenderLivros.GetParent().Close(True)
	event.Skip()
end function

function frmVenderLivros_OnBtnFechar( event )
  frmVenderLivros.Close(True)
  event.Skip()
end function

function frmVenderLivros_OnBtnVender( event )
  if frmVenderLivros_ValidaDados() then
    'if frmVenderLivros_SalvaLista() then
    '  wxMessageBox(STR_VENRESUC, STR_TITULO, wxOK + wxICON_INFORMATION)
    '  frmVenderLivros_LimpaDados()
    'end if
  end if	
  event.Skip()
end function

function frmVenderLivros_OnBtnLimpar( event )
  frmVenderLivros_LimpaDados()
  event.Skip()
end function
