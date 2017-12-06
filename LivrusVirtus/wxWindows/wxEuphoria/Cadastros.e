include livrus.xpm

constant ID_FRMCADASTROS_BTNANTERIOR = 400
constant ID_FRMCADASTROS_BTNEXCLUIR = 401
constant ID_FRMCADASTROS_BTNFECHAR = 402
constant ID_FRMCADASTROS_BTNLIMPAR = 403
constant ID_FRMCADASTROS_BTNNOVO = 404
constant ID_FRMCADASTROS_BTNPESQUISAR = 405
constant ID_FRMCADASTROS_BTNPROXIMO = 406
constant ID_FRMCADASTROS_BTNSALVAR = 407
constant ID_FRMCADASTROS_EDTCODIGO = 408
constant ID_FRMCADASTROS_EDTDESCRICAO = 409
constant ID_FRMCADASTROS_LABCODIGO = 410
constant ID_FRMCADASTROS_LABDESCRICAO = 411

atom frmCadastros_Registros, frmCadastros_Campos, frmCadastros_nLinhaRegistro,
  frmCadastros_labCodigo, frmCadastros_edtCodigo, frmCadastros_labDescricao,
  frmCadastros_edtDescricao, frmCadastros_btnNovo, frmCadastros_btnPesquisar,
  frmCadastros_btnAnterior, frmCadastros_btnProximo, frmCadastros_btnFechar,
  frmCadastros_btnLimpar, frmCadastros_btnExcluir, frmCadastros_btnSalvar,
  frmCadastros_Arquiva, frmCadastros_panel, icone


object void
global atom frmCadastros

-- Necessário por causa da tabulação dos campos
procedure frmCadastros_IniciaBotoes(atom parent)
  frmCadastros_btnPesquisar = create( wxButton,{parent, 
    ID_FRMCADASTROS_BTNPESQUISAR, "&Pesquisar", 248, 8, 75, 25, 0})  
  frmCadastros_btnAnterior = create( wxButton,{parent, 
    ID_FRMCADASTROS_BTNANTERIOR,"&Anterior", 248, 40, 75, 25, 0})  
  frmCadastros_btnProximo = create( wxButton,{parent, 
    ID_FRMCADASTROS_BTNPROXIMO,"Próxi&mo", 248, 72, 75, 25, 0})  
  frmCadastros_btnSalvar = create( wxButton,{parent, 
    ID_FRMCADASTROS_BTNSALVAR,"&Salvar", 8, 104, 75, 25, 0})  
  frmCadastros_btnExcluir = create( wxButton,{parent, 
    ID_FRMCADASTROS_BTNEXCLUIR,"&Excluir", 88, 104, 75, 25, 0})  
  frmCadastros_btnLimpar = create( wxButton,{parent, 
    ID_FRMCADASTROS_BTNLIMPAR, "&Limpar", 168, 104, 75, 25, 0}) 
  frmCadastros_btnFechar = create( wxButton,{parent, 
    ID_FRMCADASTROS_BTNFECHAR,"&Fechar", 248, 104, 75, 25, 0})  

--  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
--    frmCadastros_edtDescricao, frmCadastros_btnNovo, 
--    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
--    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
--    frmCadastros_btnExcluir)
end procedure

procedure frmCadastros_FazLayout(atom parent)
atom sizer_1,sizer_2,sizer_3,sizer_4,sizer_5,grid_sizer_1,grid_sizer_2

  sizer_1 = create( wxBoxSizer,{wxVERTICAL})
  sizer_2 = create( wxBoxSizer,{wxHORIZONTAL})
  sizer_3 = create( wxBoxSizer,{wxHORIZONTAL})
  sizer_4 = create( wxBoxSizer,{wxVERTICAL})
  sizer_5 = create( wxBoxSizer,{wxVERTICAL})
  grid_sizer_2 = create( wxGridSizer,{2, 1, 0, 0})
  grid_sizer_1 = create( wxGridSizer,{2, 2, 0, 1})
  add_window_to_sizer( grid_sizer_1, frmCadastros_labCodigo, 0, wxALIGN_BOTTOM, 0)
  space_sizer( grid_sizer_1, 20, 10, 0, 0, 0)
  add_window_to_sizer( grid_sizer_1, frmCadastros_edtCodigo, 0, 0, 0)
  add_window_to_sizer( grid_sizer_1, frmCadastros_btnNovo, 0, wxLEFT, 6)
  add_sizer_to_sizer( sizer_5, grid_sizer_1, 0, 0, 0)
  add_window_to_sizer( grid_sizer_2, frmCadastros_labDescricao, 0, wxALIGN_BOTTOM, 0)
  add_window_to_sizer( grid_sizer_2, frmCadastros_edtDescricao, 0, 0, 2)
  add_sizer_to_sizer( sizer_5, grid_sizer_2, 0, 0, 0)
  add_sizer_to_sizer( sizer_3, sizer_5, 1, 0, 0)
  add_window_to_sizer( sizer_4, frmCadastros_btnPesquisar, 0, wxALL + wxALIGN_RIGHT, 2)
  add_window_to_sizer( sizer_4, frmCadastros_btnAnterior, 0, wxALL + wxALIGN_RIGHT, 2)
  add_window_to_sizer( sizer_4, frmCadastros_btnProximo, 0, wxALL + wxALIGN_RIGHT, 2)
  add_sizer_to_sizer( sizer_3, sizer_4, 0, wxALIGN_RIGHT, 0)
  add_sizer_to_sizer( sizer_1, sizer_3, 1, wxALL + wxEXPAND, 4)
  add_window_to_sizer( sizer_2, frmCadastros_btnSalvar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  add_window_to_sizer( sizer_2, frmCadastros_btnExcluir, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  add_window_to_sizer( sizer_2, frmCadastros_btnLimpar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  add_window_to_sizer( sizer_2, frmCadastros_btnFechar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  add_sizer_to_sizer( sizer_1, sizer_2, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 4)
--  parent.SetAutoLayout(True)
  set_sizer(parent, sizer_1)
--  sizer_1.Fit(parent)
--  sizer_1.SetSizeHints(parent)
end procedure

procedure frmCadastros_IniciaControles(atom nFiltroCodigo, atom bIniciaBotoes)
  frmCadastros = create( wxFrame,{0, FRMCADASTROS, "Cadastro de ", 0, 0,
        342, 162, wxDEFAULT_DIALOG_STYLE, ""} )
  frmCadastros_panel = create( wxPanel,{frmCadastros, -1, 0, 0, 330, 140}) 

  icone = create( wxIcon, {Livrus_xpm})
  set_icon( frmCadastros, icone )
  
  frmCadastros_labCodigo = create( wxStaticText, {frmCadastros_panel, 
    ID_FRMCADASTROS_LABCODIGO,"Código:", 8, 8, 36, 13, 0} )
  frmCadastros_edtCodigo = create( wxTextCtrl, {frmCadastros_panel, 
    ID_FRMCADASTROS_EDTCODIGO,"", 8, 24, 121, 21, 0})  
  frmCadastros_btnNovo = create( wxButton, {frmCadastros_panel, 
    ID_FRMCADASTROS_BTNNOVO, "&Novo", 144, 24, 75, 25, 0})
  frmCadastros_labDescricao = create( wxStaticText,{frmCadastros_panel, 
    ID_FRMCADASTROS_LABDESCRICAO, "Descrição:", 8, 48, 51, 13, 0})  
  frmCadastros_edtDescricao = create( wxTextCtrl,{frmCadastros_panel, 
    ID_FRMCADASTROS_EDTDESCRICAO, "", 8, 64, 217, 21, 0})

  if bIniciaBotoes then
    frmCadastros_IniciaBotoes(frmCadastros_panel)
    frmCadastros_FazLayout(frmCadastros_panel)
  end if
  --frmCadastros_edtCodigo.MaxLength = 10
  --frmCadastros_edtDescricao.MaxLength = 30
  --frmCadastros_Registros = create( ArrayList())
  frmCadastros_nLinhaRegistro = 0
end procedure

frmCadastros_IniciaControles(0, TRUE)
