option explicit

Const ID_FRMCADCLIENTES_BTNPENDERECO = 800
Const ID_FRMCADCLIENTES_SBENDERECO = 801
Const ID_FRMCADCLIENTES_BTNPPAIS = 802
Const ID_FRMCADCLIENTES_BTNPPROFISSAO = 803 
Const ID_FRMCADCLIENTES_EDTBAIRRO = 804 
Const ID_FRMCADCLIENTES_EDTCEP = 805 
Const ID_FRMCADCLIENTES_EDTCIDADE = 806 
Const ID_FRMCADCLIENTES_EDTCODENDERECO = 807 
Const ID_FRMCADCLIENTES_EDTCODPAIS = 808 
Const ID_FRMCADCLIENTES_EDTCODPROFISSAO = 809 
Const ID_FRMCADCLIENTES_EDTDTNASC = 810 
Const ID_FRMCADCLIENTES_EDTEMAIL = 811 
Const ID_FRMCADCLIENTES_EDTESTADO = 812 
Const ID_FRMCADCLIENTES_EDTIDENTIDADE = 813 
Const ID_FRMCADCLIENTES_EDTLOGRADOURO = 814 
Const ID_FRMCADCLIENTES_EDTPAIS = 815 
Const ID_FRMCADCLIENTES_EDTPROFISSAO = 816 
Const ID_FRMCADCLIENTES_EDTTELEFONE = 817 
Const ID_FRMCADCLIENTES_LABBAIRRO = 818 
Const ID_FRMCADCLIENTES_LABCEP = 819 
Const ID_FRMCADCLIENTES_LABCIDADE = 820 
Const ID_FRMCADCLIENTES_LABDTNASC = 821 
Const ID_FRMCADCLIENTES_LABEMAIL = 822 
Const ID_FRMCADCLIENTES_LABESTADO = 823 
Const ID_FRMCADCLIENTES_LABIDENTIDADE = 824 
Const ID_FRMCADCLIENTES_LABLOGRADOURO = 825 
Const ID_FRMCADCLIENTES_LABPAIS = 826 
Const ID_FRMCADCLIENTES_LABPROFISSAO = 827 
Const ID_FRMCADCLIENTES_LABTELEFONE = 828 
Const ID_FRMCADCLIENTES_RBSEXO = 829

dim common frmCadClientes
dim common frmCadClientes_labEmail
dim common frmCadClientes_edtEmail
dim common frmCadClientes_labIdentidade
dim common frmCadClientes_edtIdentidade
dim common frmCadClientes_rbSexo
dim common frmCadClientes_labTelefone
dim common frmCadClientes_edtTelefone
dim common frmCadClientes_labDtNasc
dim common frmCadClientes_edtDtNasc
dim common frmCadClientes_sbEndereco
dim common frmCadClientes_edtCodEndereco
dim common frmCadClientes_btnPEndereco
dim common frmCadClientes_labLogradouro
dim common frmCadClientes_edtLogradouro
dim common frmCadClientes_labBairro
dim common frmCadClientes_edtBairro
dim common frmCadClientes_labCEP
dim common frmCadClientes_edtCEP
dim common frmCadClientes_labCidade
dim common frmCadClientes_edtCidade
dim common frmCadClientes_labEstado
dim common frmCadClientes_edtEstado
dim common frmCadClientes_labPais
dim common frmCadClientes_edtCodPais
dim common frmCadClientes_edtPais
dim common frmCadClientes_btnPPais
dim common frmCadClientes_labProfissao
dim common frmCadClientes_edtCodProfissao
dim common frmCadClientes_edtProfissao
dim common frmCadClientes_btnPProfissao

function frmCadClientes_Criar(parent)
  dim fCadClientes = frmCadastros_Criar(parent, 0, False)

  frmCadastros_labDescricao.SetLabel("Nome: ")
  frmCadastros_edtDescricao.SetSize(312, 21)
  Connect( fCadClientes, ID_FRMCADASTROS_EDTCODIGO, 
    wxEVT_KILL_FOCUS, "frmCadClientes_OnEdtCodigo_Killfocus" )

  frmCadClientes_labEmail = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABEMAIL,
             "E-mail: ", wxPoint(8, 88), wxSize(34, 13), 0)
  frmCadClientes_edtEmail = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTEMAIL,
             "", wxPoint(8, 104), wxSize(312, 21), 0)
  frmCadClientes_edtEmail.Enable(False)

  frmCadClientes_labIdentidade = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABIDENTIDADE,
              "Identidade: ", wxPoint(322, 88), wxSize(56, 13), 0)
  frmCadClientes_edtIdentidade = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTIDENTIDADE,
              "", wxPoint(322, 104), wxSize(100, 21), 0)
  frmCadClientes_edtIdentidade.Enable(False)  

  dim sItems[2] 
  sItems[0] = "Masculino"
  sItems[1] = "Feminino"
  frmCadClientes_rbSexo = new wxRadioBox(fCadClientes, ID_FRMCADCLIENTES_RBSEXO, "Sexo",
              wxPoint(9, 128), wxSize(200, 44), 2, sItems[], 2, wxRA_SPECIFY_COLS)
  'frmCadClientes_rbSexo.SetItemLabel(0,"Masculino")
  'frmCadClientes_rbSexo.SetItemLabel(1,"Feminino")
  frmCadClientes_rbSexo.Enable(False)

  frmCadClientes_labTelefone = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABTELEFONE,
              "Telefone: ", wxPoint(216, 128), wxSize(48, 13), 0)
  frmCadClientes_edtTelefone = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTTELEFONE,
              "", wxPoint(216, 144), wxSize(104, 21), 0)
  frmCadClientes_edtTelefone.Enable(False)

  frmCadClientes_labDtNasc = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABDTNASC,
              "Dt. Nascimento", wxPoint(322, 128), wxSize(73, 13), 0)
  frmCadClientes_edtDtNasc = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTDTNASC,
            "", wxPoint(322, 144), wxSize(100, 21), 0)
  frmCadClientes_edtDtNasc.Enable(False)
  'Connect( fCadClientes, ID_FRMCADCLIENTES_EDTDTNASC, 
  '  wxEVT_KILL_FOCUS, "frmCadClientes_OnEdtDtNasc_Killfocus" )

  frmCadClientes_sbEndereco = new wxStaticBox(fCadClientes, ID_FRMCADCLIENTES_SBENDERECO,
    "Endereço", wxPoint(8, 176), wxSize(432, 136), 0)

  frmCadClientes_edtCodEndereco = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTCODENDERECO, 
    "", wxPoint(16, 200), wxSize(88, 21), 0)
  frmCadClientes_edtCodEndereco.Enable(False)
  'Connect( fCadClientes, ID_FRMCADCLIENTES_EDTCODENDERECO, 
  '  wxEVT_KILL_FOCUS, "frmCadClientes_OnEdtCodEndereco_Killfocus" )

  frmCadClientes_btnPEndereco = new wxButton(fCadClientes, ID_FRMCADCLIENTES_BTNPENDERECO,
              "...", wxPoint(104, 200), wxSize(21, 21), 0)
  frmCadClientes_btnPEndereco.Enable(False)

  frmCadClientes_labLogradouro = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABLOGRADOURO,
              "Logradouro: ", wxPoint(16, 224), wxSize(60, 13), 0)
  frmCadClientes_edtLogradouro = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTLOGRADOURO,
              "", wxPoint(16, 240), wxSize(264, 21), 0)
  frmCadClientes_edtLogradouro.Enable(False)

  frmCadClientes_labBairro = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABBAIRRO,
              "Bairro:", wxPoint(284, 224), wxSize(48, 13), 0)
  frmCadClientes_edtBairro = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTBAIRRO,
              "", wxPoint(284, 240), wxSize(144, 21), 0)
  frmCadClientes_edtBairro.Enable(False)

  frmCadClientes_labCEP = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABCEP, "CEP: ",
              wxPoint(16, 264), wxSize(40, 13), 0)
  frmCadClientes_edtCEP = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTCEP, "",
              wxPoint(16, 280), wxSize(78, 21), 0)
  frmCadClientes_edtCEP.Enable(False)

  frmCadClientes_labCidade = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABCIDADE,
              "Cidade: ", wxPoint(96, 264), wxSize(39, 13), 0)
  frmCadClientes_edtCidade = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTCIDADE,
              "", wxPoint(96, 280), wxSize(184, 21), 0)
  frmCadClientes_edtCidade.Enable(False)

  frmCadClientes_labEstado = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABESTADO,
              "Estado: ", wxPoint(284, 264), wxSize(56, 13), 0)
  frmCadClientes_edtEstado = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTESTADO,
              "", wxPoint(284, 280), wxSize(144, 21), 0)
  frmCadClientes_edtEstado.Enable(False)

  frmCadClientes_labPais = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABPAIS,
    "País de origem: ", wxPoint(8, 320), wxSize(77, 16), 0)
  frmCadClientes_edtCodPais = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTCODPAIS,
    "", wxPoint(8, 336), wxSize(78, 21), 0)
  frmCadClientes_edtCodPais.Enable(False)
  'Connect( fCadClientes, ID_FRMCADCLIENTES_EDTCODPAIS, 
  '  wxEVT_KILL_FOCUS, "frmCadClientes_OnEdtCodPais_Killfocus" )

  frmCadClientes_edtPais = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTPAIS,
              "", wxPoint(88, 336), wxSize(240, 21), 0)
  frmCadClientes_edtPais.Enable(False)
  frmCadClientes_btnPPais = new wxButton(fCadClientes, ID_FRMCADCLIENTES_BTNPPAIS, "...",
               wxPoint(328, 336), wxSize(21, 21), 0)
  frmCadClientes_btnPPais.Enable(False)

  frmCadClientes_labProfissao = new wxStaticText(fCadClientes, ID_FRMCADCLIENTES_LABPROFISSAO,
              "Profissão: ", wxPoint(8, 360), wxSize(56, 13), 0)
  frmCadClientes_edtCodProfissao = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTCODPROFISSAO,
    "", wxPoint(8, 376), wxSize(78, 21), 0)
  frmCadClientes_edtCodProfissao.Enable(False)
  'Connect( fCadClientes, ID_FRMCADCLIENTES_EDTCODPROFISSAO, 
  '  wxEVT_KILL_FOCUS, "frmCadClientes_OnEdtCodProfissao_Killfocus" )

  frmCadClientes_edtProfissao = new wxTextCtrl(fCadClientes, ID_FRMCADCLIENTES_EDTPROFISSAO,
              "", wxPoint(88, 376), wxSize(240, 21), 0)
  frmCadClientes_edtProfissao.Enable(False)
  frmCadClientes_btnPProfissao = new wxButton(fCadClientes, ID_FRMCADCLIENTES_BTNPPROFISSAO,
              "...", wxPoint(328, 376), wxSize(21, 21), 0)
  frmCadClientes_btnPProfissao.Enable(False)

  frmCadastros_IniciaBotoes(fCadClientes)
  frmCadastros_btnPesquisar.SetDimensions(440, 8, 75, 25)
  frmCadastros_btnAnterior.SetDimensions(440, 40, 75, 25)
  frmCadastros_btnProximo.SetDimensions(440, 72, 75, 25)
  frmCadastros_btnSalvar.SetDimensions(200, 408, 75, 25)
  frmCadastros_btnExcluir.SetDimensions(280, 408, 75, 25)
  frmCadastros_btnLimpar.SetDimensions(360, 408, 75, 25)
  frmCadastros_btnFechar.SetDimensions(440, 408, 75, 25)

  frmCadClientes_FazLayout(fCadClientes)

	'frmCadastros_edtCodigo.MaxLength = 14
  'frmCadastros_edtDescricao.MaxLength = 30
  'frmCadClientes_edtEmail.MaxLength = 30
  'frmCadClientes_edtIdentidade.MaxLength = 10
  'frmCadClientes_edtCodEndereco.MaxLength = 10
  'frmCadClientes_edtTelefone.MaxLength = 17
  'frmCadClientes_edtCodPais.MaxLength = 3
  'frmCadClientes_edtCodProfissao.MaxLength = 10

  Connect( fCadClientes, wxEVT_CLOSE_WINDOW, "frmCadClientes_OnClose" )
  Connect( fCadClientes, ID_FRMCADASTROS_BTNNOVO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnNovo" )
  Connect( fCadClientes, ID_FRMCADASTROS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnPesquisar" )
  Connect( fCadClientes, ID_FRMCADASTROS_BTNANTERIOR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnAnterior" )
  Connect( fCadClientes, ID_FRMCADASTROS_BTNPROXIMO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnProximo" )
  Connect( fCadClientes, ID_FRMCADASTROS_BTNSALVAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnSalvar" )
  Connect( fCadClientes, ID_FRMCADASTROS_BTNEXCLUIR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnExcluir" )
  Connect( fCadClientes, ID_FRMCADASTROS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnFechar" )
  Connect( fCadClientes, ID_FRMCADASTROS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnLimpar" )
  Connect( fCadClientes, ID_FRMCADCLIENTES_BTNPENDERECO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnPEndereco" )
  Connect( fCadClientes, ID_FRMCADCLIENTES_BTNPPAIS, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnPPais" )
  Connect( fCadClientes, ID_FRMCADCLIENTES_BTNPPROFISSAO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadClientes_OnBtnPProfissao" )

  return fCadClientes
end function

sub frmCadClientes_FazLayout(parent)
  dim sizer_1 = new wxBoxSizer(wxVERTICAL)
  dim sizer_2 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_3 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_4 = new wxBoxSizer(wxVERTICAL)
  dim sizer_5 = new wxBoxSizer(wxVERTICAL)
  dim sizer_16 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_23 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_22 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_19 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_15 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_21 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_20 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_18 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_end = new wxStaticBox(parent, -1, "Endereço")
  dim sizer_11 = new wxStaticBoxSizer(sizer_end, wxVERTICAL)
  dim sizer_14 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_17 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_16 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_15 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_13 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_14 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_13 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_12 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_10 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_12 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_11 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_6 = new wxBoxSizer(wxHORIZONTAL)
  dim grid_sizer_5 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_4 = new wxGridSizer(2, 1, 0, 0)
  dim sizer_8 = new wxBoxSizer(wxHORIZONTAL)
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
  sizer_5.Add(sizer_8, 1, wxEXPAND, 0)
  grid_sizer_4.Add(frmCadClientes_labEmail, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_4.Add(frmCadClientes_edtEmail, 0, 0, 0)
  sizer_6.Add(grid_sizer_4, 0, 0, 0)
  grid_sizer_5.Add(frmCadClientes_labIdentidade, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_5.Add(frmCadClientes_edtIdentidade, 0, 0, 0)
  sizer_6.Add(grid_sizer_5, 0, wxLEFT, 4)
  sizer_5.Add(sizer_6, 0, 0, 0)
  sizer_10.Add(frmCadClientes_rbSexo, 0, 0, 0)
  grid_sizer_11.Add(frmCadClientes_labTelefone, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_11.Add(frmCadClientes_edtTelefone, 0, 0, 0)
  sizer_10.Add(grid_sizer_11, 1, wxLEFT + wxEXPAND, 4)
  grid_sizer_12.Add(frmCadClientes_labDtNasc, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_12.Add(frmCadClientes_edtDtNasc, 0, 0, 0)
  sizer_10.Add(grid_sizer_12, 1, wxLEFT + wxEXPAND, 4)
  sizer_5.Add(sizer_10, 1, wxEXPAND, 0)
  sizer_12.Add(frmCadClientes_edtCodEndereco, 0, 0, 0)
  sizer_12.Add(frmCadClientes_btnPEndereco, 0, 0, 0)
  sizer_11.Add(sizer_12, 0, wxALL, 2)
  grid_sizer_13.Add(frmCadClientes_labLogradouro, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_13.Add(frmCadClientes_edtLogradouro, 0, 0, 0)
  sizer_13.Add(grid_sizer_13, 0, 0, 0)
  grid_sizer_14.Add(frmCadClientes_labBairro, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_14.Add(frmCadClientes_edtBairro, 0, 0, 0)
  sizer_13.Add(grid_sizer_14, 0, wxLEFT, 4)
  sizer_11.Add(sizer_13, 0, 0, 0)
  grid_sizer_15.Add(frmCadClientes_labCEP, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_15.Add(frmCadClientes_edtCEP, 0, 0, 0)
  sizer_14.Add(grid_sizer_15, 0, 0, 0)
  grid_sizer_16.Add(frmCadClientes_labCidade, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_16.Add(frmCadClientes_edtCidade, 0, 0, 0)
  sizer_14.Add(grid_sizer_16, 0, wxLEFT, 4)
  grid_sizer_17.Add(frmCadClientes_labEstado, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_17.Add(frmCadClientes_edtEstado, 0, 0, 0)
  sizer_14.Add(grid_sizer_17, 0, wxLEFT, 4)
  sizer_11.Add(sizer_14, 1, 0, 0)
  sizer_5.Add(sizer_11, 0, 0, 0)
  grid_sizer_18.Add(frmCadClientes_labPais, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_18.Add(frmCadClientes_edtCodPais, 0, 0, 0)
  sizer_15.Add(grid_sizer_18, 0, 0, 0)
  grid_sizer_20.Add(20, 20, 0, 0, 0)
  grid_sizer_20.Add(frmCadClientes_edtPais, 0, 0, 0)
  sizer_15.Add(grid_sizer_20, 0, wxLEFT, 2)
  grid_sizer_21.Add(20, 20, 0, 0, 0)
  grid_sizer_21.Add(frmCadClientes_btnPPais, 0, 0, 0)
  sizer_15.Add(grid_sizer_21, 0, 0, 0)
  sizer_5.Add(sizer_15, 0, 0, 0)
  grid_sizer_19.Add(frmCadClientes_labProfissao, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_19.Add(frmCadClientes_edtCodProfissao, 0, 0, 0)
  sizer_16.Add(grid_sizer_19, 0, 0, 0)
  grid_sizer_22.Add(20, 20, 0, 0, 0)
  grid_sizer_22.Add(frmCadClientes_edtProfissao, 0, 0, 0)
  sizer_16.Add(grid_sizer_22, 0, wxLEFT, 2)
  grid_sizer_23.Add(20, 20, 0, 0, 0)
  grid_sizer_23.Add(frmCadClientes_btnPProfissao, 0, 0, 0)
  sizer_16.Add(grid_sizer_23, 0, 0, 0)
  sizer_5.Add(sizer_16, 0, 0, 0)
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
  sizer_1.Add(sizer_2, 0, wxRIGHT + wxBOTTOM + wxALIGN_RIGHT + 
    wxALIGN_BOTTOM, 4)
  parent.SetAutoLayout(True)
  parent.SetSizer(sizer_1)
  sizer_1.Fit(parent)
  sizer_1.SetSizeHints(parent)
end sub


function frmCadClientes_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo.GetValue(),
    STR_CODNINF) then
    return False
  end if
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao.GetValue(),
      STR_CLININF) then
    	return False
    end if
    if Rotinas_ValidaCampo(frmCadClientes_edtEmail.GetValue(),
      STR_EMAILNINF) then
    	return False
    end if
	  if Rotinas_ValidaCampo(frmCadClientes_edtTelefone.GetValue(),
      STR_TELNINF) then
    	return False
    end if
	  if Rotinas_ValidaCampo(frmCadClientes_edtCodEndereco.GetValue(),
      STR_ENDNINF) then
    	return False
    end if
	  if Rotinas_ValidaCampo(frmCadClientes_edtCodPais.GetValue(),
      STR_PAISNINF) then
    	return False
    end if
	  if Rotinas_ValidaCampo(frmCadClientes_edtCodProfissao.GetValue(),
      STR_PROFNINF) then
    	return False
    end if
  end if
	return True
end function

Function frmCadClientes_OnClose( event )
  frmCadClientes.GetParent().Close(True)
	event.Skip()
End Function

function frmCadClientes_OnBtnNovo( event )
  frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadClientes_InformaLimpaDados(False)
  frmCadClientes_HabilitaDados(True)
  event.Skip()
end function

function frmCadClientes_OnBtnPesquisar( event )
  if frmCadastros_PesquisarDados(ConsSQL_Cliente("S", 
    frmCadastros_edtCodigo.GetValue(),"","","","","","","","",""), 
    STR_CLINENC, frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir) then
    frmCadClientes_InformaLimpaDados(True)
    frmCadClientes_HabilitaDados(True)
  end if
  event.Skip()
end function

function frmCadClientes_OnBtnAnterior( event )
  if frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao) then
    frmCadClientes_InformaLimpaDados(True)
  end if
  event.Skip()
end function

function frmCadClientes_OnBtnProximo( event )
  if frmCadastros_registroProximo(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao) then
    frmCadClientes_InformaLimpaDados(True)
  end if
  event.Skip()
end function

function frmCadClientes_OnBtnSalvar( event )
  if frmCadastros_SalvarDados(frmCadClientes_ValidaDados(True),
    ConsSQL_Cliente("S", frmCadastros_edtCodigo.GetValue(),
    "","","","","","","","",""),
    ConsSQL_Cliente("U", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue(),"","","","","","","",""),
    ConsSQL_Cliente("I", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue(),"","","","","","","",""), True,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir) then
    frmCadClientes_InformaLimpaDados(False)
    frmCadClientes_HabilitaDados(False)
  end if
  event.Skip()
end function

function frmCadClientes_OnBtnExcluir( event )
  if frmCadastros_ExcluirDados(frmCadClientes_ValidaDados(False),
    ConsSQL_Cliente("D", frmCadastros_edtCodigo.GetValue(),
    "","","","","","","","",""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir) then
    frmCadClientes_InformaLimpaDados(False)
    frmCadClientes_HabilitaDados(False)
  end if
  event.Skip()
end function

function frmCadClientes_OnBtnFechar( event )
  frmCadClientes.Close(True)
  event.Skip()
end function

function frmCadClientes_OnBtnLimpar( event )
  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadClientes_InformaLimpaDados(False)
  frmCadClientes_HabilitaDados(False)
  event.Skip()
end function

sub frmCadClientes_InformaLimpaDados(bInformar)
  if bInformar then
    frmCadClientes_edtEmail.SetValue("2")
    frmCadClientes_edtIdentidade.SetValue("3")
    'if Campos(4) = "M" then
      frmCadClientes_rbSexo.SetSelection(0)
    'else
    '  frmCadClientes_rbSexo.SetSelection(1)
    'end if
    frmCadClientes_edtTelefone.SetValue("5")
    frmCadClientes_edtDtNasc.SetValue("25/05/2005")
    frmCadClientes_edtCodEndereco.SetValue("7")
    frmCadClientes_edtLogradouro.SetValue("8")
    frmCadClientes_edtBairro.SetValue("9")
    frmCadClientes_edtCEP.SetValue("10")
    frmCadClientes_edtCidade.SetValue("11")
    frmCadClientes_edtEstado.SetValue("12")
    frmCadClientes_edtCodPais.SetValue("13")
    frmCadClientes_edtPais.SetValue("14")
    frmCadClientes_edtCodProfissao.SetValue("15")
    frmCadClientes_edtProfissao.SetValue("16")
  else
    frmCadClientes_edtEmail.Clear()
    frmCadClientes_edtIdentidade.Clear()
    frmCadClientes_rbSexo.SetSelection(0)
    frmCadClientes_edtTelefone.Clear()
    frmCadClientes_edtDtNasc.Clear()
    frmCadClientes_edtCodEndereco.Clear()
    frmCadClientes_edtLogradouro.Clear()
    frmCadClientes_edtBairro.Clear()
    frmCadClientes_edtCEP.Clear()
    frmCadClientes_edtCidade.Clear()
    frmCadClientes_edtEstado.Clear()
    frmCadClientes_edtCodPais.Clear()
    frmCadClientes_edtPais.Clear()
    frmCadClientes_edtCodProfissao.Clear()
    frmCadClientes_edtProfissao.Clear()
    frmCadastros_edtCodigo.SetFocus()
  end if
end sub 

sub frmCadClientes_HabilitaDados(bHabilita)
  frmCadClientes_edtEmail.Enable(bHabilita)
  frmCadClientes_edtIdentidade.Enable(bHabilita)
  frmCadClientes_rbSexo.Enable(bHabilita)
  frmCadClientes_edtTelefone.Enable(bHabilita)
  frmCadClientes_edtDtNasc.Enable(bHabilita)
  frmCadClientes_edtCodEndereco.Enable(bHabilita)
  frmCadClientes_btnPEndereco.Enable(bHabilita)
  frmCadClientes_edtCodPais.Enable(bHabilita)
  frmCadClientes_btnPPais.Enable(bHabilita)
  frmCadClientes_edtCodProfissao.Enable(bHabilita)
  frmCadClientes_btnPProfissao.Enable(bHabilita)
end sub

function frmCadClientes_OnEdtCodigo_Killfocus( event )
  if Length(frmCadastros_edtCodigo.GetValue()) > 0 then
  	if Rotinas_ValidaCPF(frmCadastros_edtCodigo.GetValue()) = False then
      wxMessageBox(STR_CPFINV, "Erro", wxOK + wxICON_ERROR)
      frmCadastros_edtCodigo.Clear()
  		frmCadastros_edtCodigo.SetFocus()
  	end if
  end if	
end function

function frmCadClientes_OnBtnPEndereco( event )
  'dim fConEnderecos = new frmConEnderecos(frmCadClientes)
  'fConEnderecos.ShowModal()
  'edtCodEndereco.SetValue(Rotinas_sCodigoSelecionado)
  'OnEdtCodEndereco_Killfocus(0)
  event.Skip()
end function

function frmCadClientes_OnBtnPPais( event )
  'dim fConPaises = new frmConPaises(frmCadClientes)
  'fConPaises.ShowModal()
  'edtCodPais.SetValue(Rotinas_sCodigoSelecionado)
  'OnEdtCodPais_Killfocus(0)
  event.Skip()
end function

function frmCadClientes_OnBtnPProfissao( event )
  'dim fConProfissoes = new frmConProfissoes(frmCadClientes)
  'fConProfissoes.ShowModal()
  'edtCodProfissao.SetValue(Rotinas_sCodigoSelecionado)
  'OnEdtCodProfissao_Killfocus(0)
  event.Skip()
end function
