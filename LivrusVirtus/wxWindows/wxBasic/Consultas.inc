option explicit

Const ID_FRMCONSULTAS_BTNFECHAR = 500
Const ID_FRMCONSULTAS_BTNLIMPAR = 501
Const ID_FRMCONSULTAS_BTNPESQUISAR = 502
Const ID_FRMCONSULTAS_EDTDESCRICAO = 503
Const ID_FRMCONSULTAS_GRIDCONSULTA = 504
Const ID_FRMCONSULTAS_LABDESCRICAO = 505
Const ID_FRMCONSULTAS_LABREGISTRO = 506

dim common frmConsultas_Registros, frmConsultas_Campos
dim common frmConsultas_sSelecionado

dim common frmConsultas_labDescricao
dim common frmConsultas_edtDescricao
dim common frmConsultas_btnPesquisar
dim common frmConsultas_labRegistro
dim common frmConsultas_gridConsulta
dim common frmConsultas_btnFechar
dim common frmConsultas_btnLimpar

function frmConsultas_Criar(parent)
  dim fConsultas = new wxDialog(parent, -1, "Consulta de", wxPoint(0, 0), 
      wxSize(365, 233), wxDEFAULT_DIALOG_STYLE + wxRESIZE_BORDER + 
      wxMINIMIZE_BOX + wxMAXIMIZE_BOX) 

  'dim bmp_cons = new wxEmptyBitmap( 0, 0 ) 
  'bmp_cons.LoadFile( "xpms/livrus.xpm", wxBITMAP_TYPE_XPM ) 

	'fConsultas.SetIcon(bmp_cons)
  fConsultas.SetClientSize(wxSize(365, 233))
  fConsultas.Centre()

  frmConsultas_labDescricao = new wxStaticText(fConsultas, ID_FRMCONSULTAS_LABDESCRICAO,
    "Descrição:", wxPoint(8, 8), wxSize(51, 13), 0)
  frmConsultas_edtDescricao = new wxTextCtrl(fConsultas, ID_FRMCONSULTAS_EDTDESCRICAO,
    "", wxPoint(8, 24), wxSize(257, 21), 0)
  frmConsultas_btnPesquisar = new wxButton(fConsultas, ID_FRMCONSULTAS_BTNPESQUISAR,
    "&Pesquisar", wxPoint(272, 24), wxSize(75, 25), 0)

  frmConsultas_gridConsulta = new wxListCtrl(fConsultas, ID_FRMCONSULTAS_GRIDCONSULTA,
                       wxPoint(0, 56), wxSize(355, 125), wxLC_REPORT + wxSUNKEN_BORDER)
  frmConsultas_gridConsulta.InsertColumnInfo(0, "Código", 0, 80)
  frmConsultas_gridConsulta.InsertColumnInfo(1, "Descrição", 0, 220)

  frmConsultas_labRegistro = new wxStaticText(fConsultas, ID_FRMCONSULTAS_LABREGISTRO,
    "Registro 0 de 0", wxPoint(8, 196), wxSize(144, 13), 0)
  frmConsultas_btnLimpar = new wxButton(fConsultas, ID_FRMCONSULTAS_BTNLIMPAR,
    "&Limpar", wxPoint(196, 193), wxSize(75, 25), 0)
  frmConsultas_btnFechar = new wxButton(fConsultas, ID_FRMCONSULTAS_BTNFECHAR,
    "&Fechar", wxPoint(275, 193), wxSize(75, 25), 0)

  frmConsultas_FazLayout(fConsultas)
  'frmConsultas_Registros = new ArrayList()
  frmConsultas_sSelecionado = ""
  frmConsultas_edtDescricao.SetFocus()

  return fConsultas
end function

sub frmConsultas_FazLayout(parent)
  dim sizer_1 = new wxBoxSizer(wxVERTICAL)
  dim grid_sizer_2 = new wxGridSizer(1, 2, 0, 0)
  dim sizer_2 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_3 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_4 = new wxBoxSizer(wxVERTICAL)
  dim grid_sizer_1 = new wxGridSizer(2, 1, 0, 0)
  grid_sizer_1.Add(frmConsultas_labDescricao, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_1.Add(frmConsultas_edtDescricao, 0, 0, 0)
  sizer_3.Add(grid_sizer_1, 0, wxALL, 2)
  sizer_4.Add(20, 20, 0, 0, 0)
  sizer_4.Add(frmConsultas_btnPesquisar, 0, wxLEFT + wxTOP + wxBOTTOM, 5)
  sizer_3.Add(sizer_4, 0, 0, 0)
  sizer_1.Add(sizer_3, 0, wxALL, 4)
  sizer_1.Add(frmConsultas_gridConsulta, 1, wxEXPAND, 0)
  grid_sizer_2.Add(frmConsultas_labRegistro, 0, wxALL, 10)
  sizer_2.Add(frmConsultas_btnLimpar, 0, wxALIGN_RIGHT + wxALIGN_BOTTOM, 8)
  sizer_2.Add(frmConsultas_btnFechar, 0, wxLEFT + wxALIGN_RIGHT + wxALIGN_BOTTOM, 8)
  grid_sizer_2.Add(sizer_2, 1, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 4)
  sizer_1.Add(grid_sizer_2, 0, wxALL + wxEXPAND + wxALIGN_BOTTOM, 0)
  parent.SetAutoLayout(True)
  parent.SetSizer(sizer_1)
  'sizer_1.Fit(parent)
  sizer_1.SetSizeHints(parent)
  parent.Layout()
end sub

sub frmConsultas_Fecha(form, nIndMenu)
  if Length(frmConsultas_sSelecionado) > 0 then
    Rotinas_sCodigoSelecionado = frmConsultas_sSelecionado
  else
    Rotinas_sCodigoSelecionado = "" 
  end if
  if nIndMenu = 0 then
    if form.IsModal() then
      form.EndModal(0)
    else
      form.Close()
    end if
  else
    frmPrincipal_mnuPesquisas.Enable(nIndMenu, True)    
  end if
end sub

sub frmConsultas_LimparDados()
  frmConsultas_labRegistro.SetLabel("Registro 0 de 0")
  frmConsultas_gridConsulta.ClearGrid()
  frmConsultas_gridConsulta.DeleteRows(0,
    frmConsultas_gridConsulta.GetNumberRows()-1,True)
  frmConsultas_edtDescricao.Clear()
  frmConsultas_edtDescricao.SetFocus()
end sub

sub frmConsultas_PesquisarDados(sTextoSql, sMensagemErro, nQtdCol)
  'if Rotinas_ConsultaDadosLista(frmConsultas_Registros, sTextoSql) then
  '  Rotinas_AdicionaLinhasGrid(frmConsultas_gridConsulta, frmConsultas_Registros, nQtdCol)
  'else
    wxMessageBox(sMensagemErro, "Erro", wxOK + wxICON_ERROR )
  'end if
end sub

sub frmConsultas_setLabRegistros(nLinha)
  if nLinha >= 0 then
    frmConsultas_labRegistro.SetLabel("Registro " + Val(nLinha+1) + " de " + 
      Val(frmConsultas_gridConsulta.GetNumberRows()))
    frmConsultas_sSelecionado = frmConsultas_gridConsulta.GetCellValue(nLinha, 0)
  end if
end sub
