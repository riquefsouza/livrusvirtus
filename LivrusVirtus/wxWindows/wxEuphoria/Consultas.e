include livrus.xpm
include wxGrid.e

constant ID_FRMCONSULTAS_BTNFECHAR = 500
constant ID_FRMCONSULTAS_BTNLIMPAR = 501
constant ID_FRMCONSULTAS_BTNPESQUISAR = 502
constant ID_FRMCONSULTAS_EDTDESCRICAO = 503
constant ID_FRMCONSULTAS_GRIDCONSULTA = 504
constant ID_FRMCONSULTAS_LABDESCRICAO = 505
constant ID_FRMCONSULTAS_LABREGISTRO = 506

atom frmConsultas_Registros, frmConsultas_Campos, frmConsultas_sSelecionado,
  frmConsultas_labDescricao, frmConsultas_edtDescricao, 
  frmConsultas_btnPesquisar, frmConsultas_labRegistro, 
  frmConsultas_gridConsulta, frmConsultas_btnFechar, frmConsultas_btnLimpar,
  frmConsultas_panel, icone

object void
global atom frmConsultas

procedure frmConsultas_FazLayout(atom parent)
atom sizer_1, sizer_2, sizer_3, sizer_4, grid_sizer_1, grid_sizer_2

  sizer_1 = create( wxBoxSizer,{wxVERTICAL})
  grid_sizer_2 = create( wxGridSizer,{1, 2, 0, 0})
  sizer_2 = create( wxBoxSizer,{wxHORIZONTAL})
  sizer_3 = create( wxBoxSizer,{wxHORIZONTAL})
  sizer_4 = create( wxBoxSizer,{wxVERTICAL})
  grid_sizer_1 = create( wxGridSizer,{2, 1, 0, 0})
  add_window_to_sizer( grid_sizer_1, frmConsultas_labDescricao, 0, wxALIGN_BOTTOM, 0)
  add_window_to_sizer( grid_sizer_1, frmConsultas_edtDescricao, 0, 0, 0)
  add_sizer_to_sizer( sizer_3, grid_sizer_1, 0, wxALL, 2)
  space_sizer( sizer_4, 20, 20, 0, 0, 0)
  add_window_to_sizer( sizer_4, frmConsultas_btnPesquisar, 0, wxLEFT + wxTOP + wxBOTTOM, 5)
  add_sizer_to_sizer( sizer_3, sizer_4, 0, 0, 0)
  add_sizer_to_sizer( sizer_1, sizer_3, 0, wxALL, 4)
  add_window_to_sizer( sizer_1, frmConsultas_gridConsulta, 1, wxEXPAND, 0)
  add_window_to_sizer( grid_sizer_2, frmConsultas_labRegistro, 0, wxALL, 10)
  add_window_to_sizer( sizer_2, frmConsultas_btnLimpar, 0, wxALIGN_RIGHT + wxALIGN_BOTTOM, 8)
  add_window_to_sizer( sizer_2, frmConsultas_btnFechar, 0, wxLEFT + wxALIGN_RIGHT + wxALIGN_BOTTOM, 8)
  add_sizer_to_sizer( grid_sizer_2, sizer_2, 1, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 4)
  add_sizer_to_sizer( sizer_1, grid_sizer_2, 0, wxALL + wxEXPAND + wxALIGN_BOTTOM, 0)
 -- parent.SetAutoLayout(True)
  set_sizer(parent, sizer_1)
 --sizer_1.Fit(parent)
 -- sizer_1.SetSizeHints(parent)
 -- parent.Layout()
  refresh_window(parent)
end procedure

procedure frmConsultas_IniciaControles()
  frmConsultas = create( wxDialog,{0, FRMCONSULTAS, "Consulta de ", 0, 0,
        365, 253, wxDEFAULT_DIALOG_STYLE + wxRESIZE_BORDER + 
      wxMINIMIZE_BOX + wxMAXIMIZE_BOX} )
  frmConsultas_panel = create( wxPanel,{frmConsultas, -1, 0, 0, 360, 253}) 

  icone = create( wxIcon, {Livrus_xpm})
  set_icon( frmConsultas, icone )

  frmConsultas_labDescricao = create( wxStaticText,{frmConsultas_panel, 
    ID_FRMCONSULTAS_LABDESCRICAO, "Descrição:", 8, 8, 51, 13, 0})
  frmConsultas_edtDescricao = create( wxTextCtrl,{frmConsultas_panel, 
    ID_FRMCONSULTAS_EDTDESCRICAO, "", 8, 24, 257, 21, 0})
  frmConsultas_btnPesquisar = create( wxButton,{frmConsultas_panel, 
    ID_FRMCONSULTAS_BTNPESQUISAR, "&Pesquisar", 272, 24, 75, 25, 0})

  frmConsultas_gridConsulta = create( wxGrid,{frmConsultas_panel, 
    ID_FRMCONSULTAS_GRIDCONSULTA,0, 56, 365, 125, wxSUNKEN_BORDER,2,2})
  set_col_label(frmConsultas_gridConsulta, 0, "Código")
  set_col_size(frmConsultas_gridConsulta, 0, 80)
  set_col_label(frmConsultas_gridConsulta, 1, "Descrição")
  set_col_size(frmConsultas_gridConsulta, 1, 220)
  set_grid_editable(frmConsultas_gridConsulta,FALSE)
  set_col_label_size(frmConsultas_gridConsulta, 21)

  frmConsultas_labRegistro = create( wxStaticText,{frmConsultas_panel, 
    ID_FRMCONSULTAS_LABREGISTRO,"Registro 0 de 0", 8, 196, 144, 13, 0})
  frmConsultas_btnLimpar = create( wxButton,{frmConsultas_panel, 
    ID_FRMCONSULTAS_BTNLIMPAR,"&Limpar", 196, 193, 75, 25, 0})
  frmConsultas_btnFechar = create( wxButton,{frmConsultas_panel, 
    ID_FRMCONSULTAS_BTNFECHAR,"&Fechar", 275, 193, 75, 25, 0})

  frmConsultas_FazLayout(frmConsultas_panel)

end procedure

frmConsultas_IniciaControles()

