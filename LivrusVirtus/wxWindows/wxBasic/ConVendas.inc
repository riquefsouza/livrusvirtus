option explicit

Const ID_FRMCONVENDAS_BTNPESQUISAR = 3100
Const ID_FRMCONVENDAS_BTNLIMPAR = 3101 
Const ID_FRMCONVENDAS_BTNFECHAR = 3102 
Const ID_FRMCONVENDAS_BTNPCLIENTE = 3103
Const ID_FRMCONVENDAS_BTNPLIVRO = 3104 
Const ID_FRMCONVENDAS_GRIDVENDAS = 3105
Const ID_FRMCONVENDAS_EDTDTHRVENDA = 3106 
Const ID_FRMCONVENDAS_EDTISBN = 3107 
Const ID_FRMCONVENDAS_EDTLIVRO = 3108 
Const ID_FRMCONVENDAS_EDTPRECOTOTAL = 3109 
Const ID_FRMCONVENDAS_LABDTHRVENDA = 3110 
Const ID_FRMCONVENDAS_LABISBN = 3111 
Const ID_FRMCONVENDAS_LABLIVRO = 3112 
Const ID_FRMCONVENDAS_LABPRECOTOTAL = 3113
Const ID_FRMCONVENDAS_LABCPF = 3114 
Const ID_FRMCONVENDAS_EDTCPF = 3115 
Const ID_FRMCONVENDAS_LABCLIENTE = 3116 
Const ID_FRMCONVENDAS_EDTCLIENTE = 3117 
Const ID_FRMCONVENDAS_LABREGISTRO = 3118

dim common frmConVendas
dim common frmConVendas_labDtHrVenda
dim common frmConVendas_edtDtHrVenda
dim common frmConVendas_labCPF
dim common frmConVendas_edtCPF
dim common frmConVendas_labCliente
dim common frmConVendas_edtCliente
dim common frmConVendas_btnPCliente
dim common frmConVendas_labISBN
dim common frmConVendas_edtISBN
dim common frmConVendas_labLivro
dim common frmConVendas_edtLivro
dim common frmConVendas_btnPLivro
dim common frmConVendas_labRegistro
dim common frmConVendas_gridVendas
dim common frmConVendas_labPrecoTotal
dim common frmConVendas_edtPrecoTotal
dim common frmConVendas_btnPesquisar
dim common frmConVendas_btnLimpar
dim common frmConVendas_btnFechar

function frmConVendas_Criar(parent)
  dim fConVendas = new wxPanel(parent, -1, wxPoint(0, 0), wxSize(480, 310))

  frmConVendas_labDtHrVenda = new wxStaticText(fConVendas, ID_FRMCONVENDAS_LABDTHRVENDA,
    "Data/Hora Venda: ", wxPoint(8, 8), wxSize(91, 13), 0)  
  frmConVendas_edtDtHrVenda = new wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTDTHRVENDA,
    "", wxPoint(8, 24), wxSize(128, 21), 0)
  Connect( fConVendas, ID_FRMCONVENDAS_EDTDTHRVENDA, 
    wxEVT_KILL_FOCUS, "frmConVendas_OnEdtDtHrVenda_Killfocus" )

  frmConVendas_btnPesquisar = new wxButton(fConVendas, ID_FRMCONVENDAS_BTNPESQUISAR,
    "&Pesquisar", wxPoint(144, 22), wxSize(75, 25), 0)

  frmConVendas_labCPF = new wxStaticText(fConVendas, ID_FRMCONVENDAS_LABCPF,
    "CPF: ", wxPoint(8, 48), wxSize(48, 13), 0)  
  frmConVendas_edtCPF = new wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTCPF,
    "", wxPoint(8, 64), wxSize(128, 21), 0)
  Connect( fConVendas, ID_FRMCONVENDAS_EDTCPF, 
    wxEVT_KILL_FOCUS, "frmConVendas_OnEdtCPF_Killfocus" )

  frmConVendas_labCliente = new wxStaticText(fConVendas, ID_FRMCONVENDAS_LABCLIENTE,
    "Cliente: ", wxPoint(142, 48), wxSize(56, 13), 0)  
  frmConVendas_edtCliente = new wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTCLIENTE,
    "", wxPoint(142, 64), wxSize(306, 21), 0)
  frmConVendas_edtCliente.Enable(False)
 
  frmConVendas_btnPCliente = new wxButton(fConVendas, ID_FRMCONVENDAS_BTNPCLIENTE,
    "...", wxPoint(448, 64), wxSize(21, 21), 0)
  
  frmConVendas_labISBN = new wxStaticText(fConVendas, ID_FRMCONVENDAS_LABISBN,
    "ISBN: ", wxPoint(8, 88), wxSize(48, 13), 0)  
  frmConVendas_edtISBN = new wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTISBN,
    "", wxPoint(8, 104), wxSize(128, 21), 0)
  Connect( fConVendas, ID_FRMCONVENDAS_EDTISBN, 
    wxEVT_KILL_FOCUS, "frmConVendas_OnEdtISBN_Killfocus" )
  
  frmConVendas_labLivro = new wxStaticText(fConVendas, ID_FRMCONVENDAS_LABLIVRO,
    "Livro: ", wxPoint(142, 88), wxSize(40, 13), 0)  
  frmConVendas_edtLivro = new wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTLIVRO,
    "", wxPoint(142, 104), wxSize(306, 21), 0)
  frmConVendas_edtLivro.Enable(False)

  frmConVendas_btnPLivro = new wxButton(fConVendas, ID_FRMCONVENDAS_BTNPLIVRO,
    "...", wxPoint(448, 104), wxSize(21, 21), 0)

  'frmConVendas_gridVendas = new wxGrid(fConVendas, ID_FRMCONVENDAS_GRIDVENDAS,
  '  wxPoint(0, 136), wxSize(355, 122), wxSUNKEN_BORDER)
  'frmConVendas_gridVendas.CreateGrid(1, 6, wxGridSelectRows)
  'frmConVendas_gridVendas.HideCellEditControl()
  'frmConVendas_gridVendas.ColLabelSize = 21
  frmConVendas_gridVendas = new wxListCtrl(fConVendas, ID_FRMCONVENDAS_GRIDVENDAS,
                       wxPoint(0, 126), wxSize(475, 125), wxLC_REPORT + wxSUNKEN_BORDER)
  'frmConVendas_gridVendas.InsertColumnInfo(0, "Data/Hora Venda", 0, 120)
  'frmConVendas_gridVendas.InsertColumnInfo(1, "CPF", 0, 100)
  'frmConVendas_gridVendas.InsertColumnInfo(2, "Cliente", 0, 220)
  'frmConVendas_gridVendas.InsertColumnInfo(3, "ISBN", 0, 100)
  'frmConVendas_gridVendas.InsertColumnInfo(4, "Livro", 0, 280)
  'frmConVendas_gridVendas.InsertColumnInfo(5, "Preço", 0, 80)

  frmConVendas_labRegistro = new wxStaticText(fConVendas, ID_FRMCONVENDAS_LABREGISTRO,
    "Registro 0 de 0", wxPoint(8, 258), wxSize(144, 13), 0)
  frmConVendas_labPrecoTotal = new wxStaticText(fConVendas, ID_FRMCONVENDAS_LABPRECOTOTAL,
    "Preço Total: ", wxPoint(280, 258), wxSize(61, 13), 0)  
  frmConVendas_edtPrecoTotal = new wxTextCtrl(fConVendas, ID_FRMCONVENDAS_EDTPRECOTOTAL,
    "", wxPoint(344, 256), wxSize(127, 21), 0)
  frmConVendas_edtPrecoTotal.Enable(False)

  frmConVendas_btnLimpar = new wxButton(fConVendas, ID_FRMCONVENDAS_BTNLIMPAR,
    "&Limpar", wxPoint(319, 283), wxSize(75, 25), 0)
  frmConVendas_btnFechar = new wxButton(fConVendas, ID_FRMCONVENDAS_BTNFECHAR,
    "&Fechar", wxPoint(399, 283), wxSize(75, 25), 0)

  'frmConVendas_FazLayout(fConVendas)

  dim nLargura[6]
  nLargura[0] = 120
  nLargura[1] = 100
  nLargura[2] = 220
  nLargura[3] = 100
  nLargura[4] = 280
  nLargura[5] = 80
  dim sRotulos[6]
  sRotulos[0] = "Data/Hora Venda"
  sRotulos[1] = "CPF"
  sRotulos[2] = "Cliente"
  sRotulos[3] = "ISBN" 
  sRotulos[4] = "Livro"
  sRotulos[5] = "Preço"

  Rotinas_AdicionaColunasGrid(frmConVendas_gridVendas, 0, 6, nLargura[], sRotulos[])
  'frmConVendas_gridVendas.EnableEditing(False)
  'frmConVendas_edtCPF.MaxLength = 14
  'frmConVendas_edtISBN.MaxLength = 13
  frmConVendas_edtPrecoTotal.SetValue("R$ 0,00")
  frmConVendas_edtDtHrVenda.SetValue(Rotinas_retDataHoraStr(True,True))

  Connect( fConVendas, wxEVT_CLOSE_WINDOW, "frmConVendas_OnClose" )
  Connect( fConVendas, ID_FRMCONVENDAS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConVendas_OnBtnPesquisar" )
  Connect( fConVendas, ID_FRMCONVENDAS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConVendas_OnBtnLimpar" )
  Connect( fConVendas, ID_FRMCONVENDAS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConVendas_OnBtnFechar" )
  Connect( fConVendas, ID_FRMCONVENDAS_BTNPCLIENTE, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConVendas_OnBtnPCliente" )
  Connect( fConVendas, ID_FRMCONVENDAS_BTNPLIVRO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmConVendas_OnBtnPLivro" )
  'Connect( fConVendas, ID_FRMCONVENDAS_GRIDVENDAS, 
  '  wxEVT_GRID_SELECT_CELL, "frmConVendas_OnGridSelectCell" )
  'Connect( fConVendas, ID_FRMCONVENDAS_GRIDVENDAS, 
  '  wxEVT_GRID_LABEL_LEFT_CLICK, "frmConVendas_OnGridLabelLeftClick" )

  return fConVendas
end function

sub frmConVendas_FazLayout(parent)
  dim sizer_1 = new wxBoxSizer(wxVERTICAL)
  dim sizer_6 = new wxBoxSizer(wxVERTICAL)
  dim sizer_22 = new wxGridSizer(1, 2, 0, 0)
  dim sizer_23 = new wxBoxSizer(wxVERTICAL)
  dim sizer_8 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_7 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_24 = new wxBoxSizer(wxVERTICAL)
  dim sizer_4 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_8 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_6 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_5 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_3 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_4 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_3 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_2 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_2 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_1 = new wxGridSizer(2, 1, 0, 0)
  grid_sizer_1.Add(frmConVendas_labDtHrVenda, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_1.Add(frmConVendas_edtDtHrVenda, 0, 0, 0)
  sizer_2.Add(grid_sizer_1, 0, wxLEFT, 2)
  sizer_2.Add(frmConVendas_btnPesquisar, 0, wxLEFT +
    wxTOP + wxALIGN_BOTTOM, 10)
  sizer_1.Add(sizer_2, 0, 0, 0)
  grid_sizer_2.Add(frmConVendas_labCPF, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_2.Add(frmConVendas_edtCPF, 0, 0, 0)
  sizer_3.Add(grid_sizer_2, 0, wxLEFT, 2)
  grid_sizer_3.Add(frmConVendas_labCliente, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_3.Add(frmConVendas_edtCliente, 0, 0, 0)
  sizer_3.Add(grid_sizer_3, 0, wxLEFT, 2)
  grid_sizer_4.Add(20, 20, 0, 0, 0)
  grid_sizer_4.Add(frmConVendas_btnPCliente, 0, 0, 0)
  sizer_3.Add(grid_sizer_4, 0, 0, 0)
  sizer_1.Add(sizer_3, 0, 0, 0)
  grid_sizer_5.Add(frmConVendas_labISBN, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_5.Add(frmConVendas_edtISBN, 0, 0, 0)
  sizer_4.Add(grid_sizer_5, 0, wxLEFT, 2)
  grid_sizer_6.Add(frmConVendas_labLivro, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_6.Add(frmConVendas_edtLivro, 0, 0, 0)
  sizer_4.Add(grid_sizer_6, 0, wxLEFT, 2)
  grid_sizer_8.Add(20, 20, 0, 0, 0)
  grid_sizer_8.Add(frmConVendas_btnPLivro, 0, 0, 0)
  sizer_4.Add(grid_sizer_8, 0, 0, 0)
  sizer_1.Add(sizer_4, 0, 0, 0)
  sizer_1.Add(frmConVendas_gridVendas, 1, wxALL + wxEXPAND, 2)
  sizer_24.Add(frmConVendas_labRegistro, 0, wxALL, 4)
  sizer_24.Add(20, 20, 0, 0, 0)
  sizer_22.Add(sizer_24, 0, 0, 0)
  sizer_7.Add(frmConVendas_labPrecoTotal, 0, wxALL, 2)
  sizer_7.Add(frmConVendas_edtPrecoTotal, 0, wxALL, 2)
  sizer_23.Add(sizer_7, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_8.Add(frmConVendas_btnLimpar, 0, wxALL +
    wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_8.Add(frmConVendas_btnFechar, 0, wxALL +
    wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_23.Add(sizer_8, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_22.Add(sizer_23, 1, wxALIGN_RIGHT + wxALIGN_BOTTOM, 0)
  sizer_6.Add(sizer_22, 0, wxEXPAND, 0)
  sizer_1.Add(sizer_6, 0, wxEXPAND, 0)
  parent.SetAutoLayout(True)
  parent.SetSizer(sizer_1)
  sizer_1.Fit(parent)
  sizer_1.SetSizeHints(parent)
  parent.Layout()
end sub

function frmConVendas_OnBtnLimpar( event )
  frmConVendas_edtCPF.Clear()
  frmConVendas_edtCliente.Clear()
  frmConVendas_edtISBN.Clear()
  frmConVendas_edtLivro.Clear()
  frmConVendas_gridVendas.ClearGrid()
  frmConVendas_gridVendas.DeleteRows(0, frmConVendas_gridVendas.GetNumberRows()-1,True)
  frmConVendas_edtPrecoTotal.SetValue("R$ 0,00")
  frmConVendas_edtDtHrVenda.SetValue(Rotinas_retDataHoraStr(True,True))
  frmConVendas_labRegistro.SetLabel("Registro 0 de 0")
  frmConVendas_edtDtHrVenda.SetFocus()
  event.Skip()
end function

function frmConVendas_ConsVenda(sOpcao)
  dim sISBN, sCPF, sDataHora, sret

  'if Length(frmConVendas_edtDtHrVenda.GetValue()) > 0 then
    'sDataHora = Rotinas_ConverteDataHoraStr(
    '  frmConVendas_edtDtHrVenda.GetValue(), "MM/dd/yyyy hh:mm:ss")
  'else
  '  sDataHora = ""
  'end if

  sISBN = frmConVendas_edtISBN.GetValue()
  sCPF = frmConVendas_edtCPF.GetValue()

  if sOpcao = "L" then
    sret = ConsSQL_Venda("S","ZERO","","","","")
  else
    sret = ConsSQL_Venda(sOpcao, sISBN, sCPF, sDataHora, "", "")
  end if
  return sret
end function

Function frmConVendas_OnClose( event )
  frmConVendas.GetParent().Close(True)
	event.Skip()
End Function

function frmConVendas_OnBtnPesquisar( event )
  'dim ConsTotal
  'dim lstLinhas
  'dim lstTotal
  dim sPrecoTotal
  dim nTemp

  'if Rotinas_ConsultaDadosLista(lstLinhas, frmConVendas_ConsVenda("S")) then
    'Rotinas_AdicionaLinhasGrid(frmConVendas_gridVendas, lstLinhas, 6)

    'if Rotinas_ConsultaDadosLista(ConsTotal, frmConVendas_ConsVenda("P")) then
      'if ConsTotal.GetCount() > 0 then
        'nTemp = lstTotal(0).ToString()
        'sPrecoTotal = nTemp.ToString("C") 
        'edtPrecoTotal.Value = sPrecoTotal
      'end if
    'end if    
  'else
  '   wxMessageBox(STR_VENNENC, "Erro", wxOK + wxICON_ERROR)
  'end if
  event.Skip()
end function

function frmConVendas_OnBtnFechar( event )
  frmConVendas.Close(True)
  event.Skip()
end function

sub frmConVendas_OnEdtCPF_Killfocus( event )
  event.Skip()
end sub

sub frmConVendas_OnBtnPCliente( event )
  'dim fConClientes = new frmConClientes(frmConVendas)
  'fConClientes.ShowModal()
  'frmConVendas_edtCPF.SetValue(Rotinas_sCodigoSelecionado)
  'frmConVendas_OnEdtCPF_Killfocus(0)
  event.Skip()
end sub

sub frmConVendas_OnEdtISBN_Killfocus( event )
  event.Skip()
end sub

sub frmConVendas_OnBtnPLivro( event )
  'dim fConLivros = new frmConLivros(frmConVendas)
  'fConLivros.ShowModal()
  'frmConVendas_edtISBN.SetValue(Rotinas_sCodigoSelecionado)
  'frmConVendas_OnEdtISBN_Killfocus(0)	
  event.Skip()
end sub

sub frmConVendas_setLabRegistros(nLinha)
  if nLinha >= 0 then
    'frmConVendas_labRegistro.SetLabel("Registro " & Str(nLinha+1) & 
    '  " de " & Str(frmConVendas_gridVendas.GetNumberRows()))
  end if
end sub

sub frmConVendas_OnGridSelectCell( event )  
  'setLabRegistros(event.GetRow())
  event.Skip()
end sub

sub frmConVendas_OnGridLabelLeftClick( event )
  'setLabRegistros(event.GetRow())
  event.Skip()
end sub

sub frmConVendas_OnEdtDtHrVenda_Killfocus( event )
  if Length(frmConVendas_edtDtHrVenda.GetValue()) > 0 then
    if not Rotinas_validaDataHora(frmConVendas_edtDtHrVenda.GetValue(), 
      False) then
      wxMessageBox(STR_DTHRINV, "Erro", wxOK + wxICON_ERROR)
  		frmConVendas_edtDtHrVenda.SetFocus()
    end if
  end if 
end sub
