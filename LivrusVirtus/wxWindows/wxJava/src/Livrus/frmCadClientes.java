package Livrus;

import org.wxwindows.*;
import java.sql.*;

public class frmCadClientes
    extends frmCadastros {

  private static int ID_FRMCADCLIENTES_BTNPENDERECO = 800;
  private static int ID_FRMCADCLIENTES_SBENDERECO = 801;
  private static int ID_FRMCADCLIENTES_BTNPPAIS = 802;
  private static int ID_FRMCADCLIENTES_BTNPPROFISSAO = 803;
  private static int ID_FRMCADCLIENTES_EDTBAIRRO = 804;
  private static int ID_FRMCADCLIENTES_EDTCEP = 805;
  private static int ID_FRMCADCLIENTES_EDTCIDADE = 806;
  private static int ID_FRMCADCLIENTES_EDTCODENDERECO = 807;
  private static int ID_FRMCADCLIENTES_EDTCODPAIS = 808;
  private static int ID_FRMCADCLIENTES_EDTCODPROFISSAO = 809;
  private static int ID_FRMCADCLIENTES_EDTDTNASC = 810;
  private static int ID_FRMCADCLIENTES_EDTEMAIL = 811;
  private static int ID_FRMCADCLIENTES_EDTESTADO = 812;
  private static int ID_FRMCADCLIENTES_EDTIDENTIDADE = 813;
  private static int ID_FRMCADCLIENTES_EDTLOGRADOURO = 814;
  private static int ID_FRMCADCLIENTES_EDTPAIS = 815;
  private static int ID_FRMCADCLIENTES_EDTPROFISSAO = 816;
  private static int ID_FRMCADCLIENTES_EDTTELEFONE = 817;
  private static int ID_FRMCADCLIENTES_LABBAIRRO = 818;
  private static int ID_FRMCADCLIENTES_LABCEP = 819;
  private static int ID_FRMCADCLIENTES_LABCIDADE = 820;
  private static int ID_FRMCADCLIENTES_LABDTNASC = 821;
  private static int ID_FRMCADCLIENTES_LABEMAIL = 822;
  private static int ID_FRMCADCLIENTES_LABESTADO = 823;
  private static int ID_FRMCADCLIENTES_LABIDENTIDADE = 824;
  private static int ID_FRMCADCLIENTES_LABLOGRADOURO = 825;
  private static int ID_FRMCADCLIENTES_LABPAIS = 826;
  private static int ID_FRMCADCLIENTES_LABPROFISSAO = 827;
  private static int ID_FRMCADCLIENTES_LABTELEFONE = 828;
  private static int ID_FRMCADCLIENTES_RBSEXO = 829;

  private wxStaticText labEmail;
  private wxTextCtrl edtEmail;
  private wxStaticText labIdentidade;
  private wxTextCtrl edtIdentidade;
  private wxRadioBox rbSexo;
  private wxStaticText labTelefone;
  private wxTextCtrl edtTelefone;
  private wxStaticText labDtNasc;
  private wxTextCtrl edtDtNasc;
  private wxStaticBox sbEndereco;
  private wxTextCtrl edtCodEndereco;
  private wxButton btnPEndereco;
  private wxStaticText labLogradouro;
  private wxTextCtrl edtLogradouro;
  private wxStaticText labBairro;
  private wxTextCtrl edtBairro;
  private wxStaticText labCEP;
  private wxTextCtrl edtCEP;
  private wxStaticText labCidade;
  private wxTextCtrl edtCidade;
  private wxStaticText labEstado;
  private wxTextCtrl edtEstado;
  private wxStaticText labPais;
  private wxTextCtrl edtCodPais;
  private wxTextCtrl edtPais;
  private wxButton btnPPais;
  private wxStaticText labProfissao;
  private wxTextCtrl edtCodProfissao;
  private wxTextCtrl edtProfissao;
  private wxButton btnPProfissao;

  public frmCadClientes(wxWindow parent) {
    super(parent, TextValidator.FILTER_NONE, false);

    labDescricao.SetLabel("Nome: ");
    edtDescricao.SetSize(new wxSize(312, 21));
    edtCodigo.EVT_KILL_FOCUS(new OnEdtCodigo_Killfocus());

    labEmail = new wxStaticText(this, ID_FRMCADCLIENTES_LABEMAIL,
                                "E-mail: ", new wxPoint(8, 88),
                                new wxSize(34, 13), 0);
    edtEmail = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTEMAIL,
                              "", new wxPoint(8, 104), new wxSize(312, 21), 0);
    edtEmail.Disable();

    labIdentidade = new wxStaticText(this, ID_FRMCADCLIENTES_LABIDENTIDADE,
                                     "Identidade: ", new wxPoint(322, 88),
                                     new wxSize(56, 13), 0);
    edtIdentidade = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTIDENTIDADE,
                                   "", new wxPoint(322, 104),
                                   new wxSize(100, 21), 0);
    edtIdentidade.Disable();

    String[] sItems = {
        "Masculino", "Feminino"};
    rbSexo = new wxRadioBox(this, ID_FRMCADCLIENTES_RBSEXO, "Sexo",
                            new wxPoint(9, 128), new wxSize(200, 44), sItems, 2,
                            wxRadioBox.wxRA_SPECIFY_COLS);
    rbSexo.Disable();

    labTelefone = new wxStaticText(this, ID_FRMCADCLIENTES_LABTELEFONE,
                                   "Telefone: ", new wxPoint(216, 128),
                                   new wxSize(48, 13), 0);
    edtTelefone = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTTELEFONE,
                                 "", new wxPoint(216, 144), new wxSize(104, 21),
                                 0);
    edtTelefone.Disable();

    labDtNasc = new wxStaticText(this, ID_FRMCADCLIENTES_LABDTNASC,
                                 "Dt. Nascimento", new wxPoint(322, 128),
                                 new wxSize(73, 13), 0);
    edtDtNasc = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTDTNASC,
                               "", new wxPoint(322, 144), new wxSize(100, 21),
                               0);
    edtDtNasc.EVT_KILL_FOCUS(new OnEdtDtNasc_Killfocus());
    edtDtNasc.Disable();
/*
    sbEndereco = new wxStaticBox(this, ID_FRMCADCLIENTES_SBENDERECO,
                                 "Endereço", new wxPoint(8, 176),
                                 new wxSize(432, 136), 0);
*/
    edtCodEndereco = new wxTextCtrl(this,
                                    ID_FRMCADCLIENTES_EDTCODENDERECO,
                                    "", new wxPoint(16, 200), new wxSize(88, 21),
                                    0);
    edtCodEndereco.Disable();
    edtCodEndereco.EVT_KILL_FOCUS(new OnEdtCodEndereco_Killfocus());

    btnPEndereco = new wxButton(this, ID_FRMCADCLIENTES_BTNPENDERECO,
                                "...", new wxPoint(104, 200), new wxSize(21, 21),
                                0);
    btnPEndereco.Disable();

    labLogradouro = new wxStaticText(this, ID_FRMCADCLIENTES_LABLOGRADOURO,
                                     "Logradouro: ", new wxPoint(16, 224),
                                     new wxSize(60, 13), 0);
    edtLogradouro = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTLOGRADOURO,
                                   "", new wxPoint(16, 240), new wxSize(264, 21),
                                   0);
    edtLogradouro.Disable();

    labBairro = new wxStaticText(this, ID_FRMCADCLIENTES_LABBAIRRO,
                                 "Bairro:", new wxPoint(284, 224),
                                 new wxSize(48, 13), 0);
    edtBairro = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTBAIRRO,
                               "", new wxPoint(284, 240), new wxSize(144, 21),
                               0);
    edtBairro.Disable();

    labCEP = new wxStaticText(this, ID_FRMCADCLIENTES_LABCEP, "CEP: ",
                              new wxPoint(16, 264), new wxSize(40, 13), 0);
    edtCEP = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTCEP, "",
                            new wxPoint(16, 280), new wxSize(78, 21), 0);
    edtCEP.Disable();

    labCidade = new wxStaticText(this, ID_FRMCADCLIENTES_LABCIDADE,
                                 "Cidade: ", new wxPoint(96, 264),
                                 new wxSize(39, 13), 0);
    edtCidade = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTCIDADE,
                               "", new wxPoint(96, 280), new wxSize(184, 21), 0);
    edtCidade.Disable();

    labEstado = new wxStaticText(this, ID_FRMCADCLIENTES_LABESTADO,
                                 "Estado: ", new wxPoint(284, 264),
                                 new wxSize(56, 13), 0);
    edtEstado = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTESTADO,
                               "", new wxPoint(284, 280), new wxSize(144, 21),
                               0);
    edtEstado.Disable();

    labPais = new wxStaticText(this, ID_FRMCADCLIENTES_LABPAIS,
                               "País de origem: ", new wxPoint(8, 320),
                               new wxSize(77, 16), 0);
    edtCodPais = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTCODPAIS,
                                "", new wxPoint(8, 336), new wxSize(78, 21), 0);
    edtCodPais.Disable();
    edtCodPais.EVT_KILL_FOCUS(new OnEdtCodPais_Killfocus());
    edtPais = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTPAIS,
                             "", new wxPoint(88, 336), new wxSize(240, 21), 0);
    edtPais.Disable();
    btnPPais = new wxButton(this, ID_FRMCADCLIENTES_BTNPPAIS, "...",
                            new wxPoint(328, 336), new wxSize(21, 21), 0);
    btnPPais.Disable();

    labProfissao = new wxStaticText(this, ID_FRMCADCLIENTES_LABPROFISSAO,
                                    "Profissão: ", new wxPoint(8, 360),
                                    new wxSize(56, 13), 0);
    edtCodProfissao = new wxTextCtrl(this,
                                     ID_FRMCADCLIENTES_EDTCODPROFISSAO,
                                     "", new wxPoint(8, 376), new wxSize(78, 21),
                                     0);
    edtCodProfissao.Disable();
    edtCodProfissao.EVT_KILL_FOCUS(new OnEdtCodProfissao_Killfocus());
    edtProfissao = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTPROFISSAO,
                                  "", new wxPoint(88, 376), new wxSize(240, 21),
                                  0);
    edtProfissao.Disable();
    btnPProfissao = new wxButton(this, ID_FRMCADCLIENTES_BTNPPROFISSAO,
                                 "...", new wxPoint(328, 376),
                                 new wxSize(21, 21), 0);
    btnPProfissao.Disable();

    IniciaBotoes();
    btnPesquisar.SetSize(440, 8, 75, 25);
    btnAnterior.SetSize(440, 40, 75, 25);
    btnProximo.SetSize(440, 72, 75, 25);
    btnSalvar.SetSize(200, 408, 75, 25);
    btnExcluir.SetSize(280, 408, 75, 25);
    btnLimpar.SetSize(360, 408, 75, 25);
    btnFechar.SetSize(440, 408, 75, 25);

    FazLayout();

    edtCodigo.SetValidator(new TextValidator(edtCodigo,
                                             TextValidator.FILTER_NONE, 14));
    edtDescricao.SetValidator(new TextValidator(edtDescricao,
                                                TextValidator.FILTER_NONE, 30));
    edtEmail.SetValidator(new TextValidator(edtEmail,
                                            TextValidator.FILTER_NONE, 30));
    edtIdentidade.SetValidator(new TextValidator(edtIdentidade,
                                                 TextValidator.FILTER_NONE, 10));
    edtCodEndereco.SetValidator(new TextValidator(edtCodEndereco,
                                                  TextValidator.FILTER_NUMERIC,
                                                  10));
    edtTelefone.SetValidator(new TextValidator(edtTelefone,
                                               TextValidator.FILTER_NONE, 17));
    edtCodPais.SetValidator(new TextValidator(edtCodPais,
                                              TextValidator.FILTER_ALPHA, 3));
    edtCodProfissao.SetValidator(new TextValidator(edtCodProfissao,
        TextValidator.FILTER_NUMERIC, 10));

    EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, new OnBtnNovoClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, new OnBtnPesquisarClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, new OnBtnAnteriorClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, new OnBtnProximoClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, new OnBtnSalvarClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, new OnBtnExcluirClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, new OnBtnLimparClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, new OnBtnFecharClick());
    EVT_CLOSE(new OnClose());
    EVT_BUTTON(ID_FRMCADCLIENTES_BTNPENDERECO, new OnBtnPEndereco());
    EVT_BUTTON(ID_FRMCADCLIENTES_BTNPPAIS, new OnBtnPPais());
    EVT_BUTTON(ID_FRMCADCLIENTES_BTNPPROFISSAO, new OnBtnPProfissao());
  }

  private void FazLayout() {
    wxBoxSizer sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_4 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_5 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_16 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_23 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_22 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_19 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_15 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_21 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_20 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_18 = new wxGridSizer(2, 1, 0, 0);
    wxStaticBoxSizer sizer_11 = new wxStaticBoxSizer(
        new wxStaticBox(this, -1, "Endereço"), wxVERTICAL);
    wxBoxSizer sizer_14 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_17 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_16 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_15 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_13 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_14 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_13 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_12 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_10 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_12 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_11 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_6 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_5 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_4 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_8 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_8 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_7 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_7 = new wxGridSizer(2, 1, 0, 0);
    grid_sizer_7.Add(labCodigo, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_7.Add(edtCodigo, 0, 0, 0);
    sizer_7.Add(grid_sizer_7, 0, 0, 0);
    sizer_7.Add(btnNovo, 0, wxLEFT | wxALIGN_BOTTOM, 5);
    sizer_5.Add(sizer_7, 1, 0, 0);
    grid_sizer_8.Add(labDescricao, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_8.Add(edtDescricao, 0, 0, 0);
    sizer_8.Add(grid_sizer_8, 0, 0, 0);
    sizer_5.Add(sizer_8, 1, wxEXPAND, 0);
    grid_sizer_4.Add(labEmail, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_4.Add(edtEmail, 0, 0, 0);
    sizer_6.Add(grid_sizer_4, 0, 0, 0);
    grid_sizer_5.Add(labIdentidade, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_5.Add(edtIdentidade, 0, 0, 0);
    sizer_6.Add(grid_sizer_5, 0, wxLEFT, 4);
    sizer_5.Add(sizer_6, 0, 0, 0);
    sizer_10.Add(rbSexo, 0, 0, 0);
    grid_sizer_11.Add(labTelefone, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_11.Add(edtTelefone, 0, 0, 0);
    sizer_10.Add(grid_sizer_11, 1, wxLEFT | wxEXPAND, 4);
    grid_sizer_12.Add(labDtNasc, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_12.Add(edtDtNasc, 0, 0, 0);
    sizer_10.Add(grid_sizer_12, 1, wxLEFT | wxEXPAND, 4);
    sizer_5.Add(sizer_10, 1, wxEXPAND, 0);
    sizer_12.Add(edtCodEndereco, 0, 0, 0);
    sizer_12.Add(btnPEndereco, 0, 0, 0);
    sizer_11.Add(sizer_12, 0, wxALL, 2);
    grid_sizer_13.Add(labLogradouro, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_13.Add(edtLogradouro, 0, 0, 0);
    sizer_13.Add(grid_sizer_13, 0, 0, 0);
    grid_sizer_14.Add(labBairro, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_14.Add(edtBairro, 0, 0, 0);
    sizer_13.Add(grid_sizer_14, 0, wxLEFT, 4);
    sizer_11.Add(sizer_13, 0, 0, 0);
    grid_sizer_15.Add(labCEP, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_15.Add(edtCEP, 0, 0, 0);
    sizer_14.Add(grid_sizer_15, 0, 0, 0);
    grid_sizer_16.Add(labCidade, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_16.Add(edtCidade, 0, 0, 0);
    sizer_14.Add(grid_sizer_16, 0, wxLEFT, 4);
    grid_sizer_17.Add(labEstado, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_17.Add(edtEstado, 0, 0, 0);
    sizer_14.Add(grid_sizer_17, 0, wxLEFT, 4);
    sizer_11.Add(sizer_14, 1, 0, 0);
    sizer_5.Add(sizer_11, 0, 0, 0);
    grid_sizer_18.Add(labPais, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_18.Add(edtCodPais, 0, 0, 0);
    sizer_15.Add(grid_sizer_18, 0, 0, 0);
    grid_sizer_20.Add(20, 20, 0, 0, 0);
    grid_sizer_20.Add(edtPais, 0, 0, 0);
    sizer_15.Add(grid_sizer_20, 0, wxLEFT, 2);
    grid_sizer_21.Add(20, 20, 0, 0, 0);
    grid_sizer_21.Add(btnPPais, 0, 0, 0);
    sizer_15.Add(grid_sizer_21, 0, 0, 0);
    sizer_5.Add(sizer_15, 0, 0, 0);
    grid_sizer_19.Add(labProfissao, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_19.Add(edtCodProfissao, 0, 0, 0);
    sizer_16.Add(grid_sizer_19, 0, 0, 0);
    grid_sizer_22.Add(20, 20, 0, 0, 0);
    grid_sizer_22.Add(edtProfissao, 0, 0, 0);
    sizer_16.Add(grid_sizer_22, 0, wxLEFT, 2);
    grid_sizer_23.Add(20, 20, 0, 0, 0);
    grid_sizer_23.Add(btnPProfissao, 0, 0, 0);
    sizer_16.Add(grid_sizer_23, 0, 0, 0);
    sizer_5.Add(sizer_16, 0, 0, 0);
    sizer_3.Add(sizer_5, 0, 0, 0);
    sizer_4.Add(btnPesquisar, 0, wxALL |
                wxALIGN_RIGHT, 2);
    sizer_4.Add(btnAnterior, 0, wxALL |
                wxALIGN_RIGHT, 2);
    sizer_4.Add(btnProximo, 0, wxALL |
                wxALIGN_RIGHT, 2);
    sizer_3.Add(sizer_4, 1, 0, 0);
    sizer_1.Add(sizer_3, 1, wxALL | wxEXPAND, 4);
    sizer_2.Add(btnSalvar, 0, wxALL |
                wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    sizer_2.Add(btnExcluir, 0, wxALL |
                wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    sizer_2.Add(btnLimpar, 0, wxALL |
                wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    sizer_2.Add(btnFechar, 0, wxALL |
                wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    sizer_1.Add(sizer_2, 0, wxRIGHT | wxBOTTOM |
                wxALIGN_RIGHT | wxALIGN_BOTTOM, 4);
    SetAutoLayout(true);
    SetSizer(sizer_1);
    sizer_1.Fit(this);
    sizer_1.SetSizeHints(this);
  }

  private boolean ValidaDados(boolean bTodosDados) {
    if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.GetValue(),
                                           Resource.STR_CODNINF)) {
      return false;
    }
    if (bTodosDados) {
      if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.GetValue(),
                                             Resource.STR_CLININF)) {
        return false;
      }
      if (RotinasGlobais.Rotinas.ValidaCampo(edtEmail.GetValue(),
                                             Resource.STR_EMAILNINF)) {
        return false;
      }
      if (RotinasGlobais.Rotinas.ValidaCampo(edtTelefone.GetValue(),
                                             Resource.STR_TELNINF)) {
        return false;
      }
      if (RotinasGlobais.Rotinas.ValidaCampo(edtCodEndereco.GetValue(),
                                             Resource.STR_ENDNINF)) {
        return false;
      }
      if (RotinasGlobais.Rotinas.ValidaCampo(edtCodPais.GetValue(),
                                             Resource.STR_PAISNINF)) {
        return false;
      }
      if (RotinasGlobais.Rotinas.ValidaCampo(edtCodProfissao.GetValue(),
                                             Resource.STR_PROFNINF)) {
        return false;
      }
    }
    return true;
  }

  class OnClose
      implements wxCloseListener {
    public void handleEvent(wxCloseEvent event) {
      GetParent().Close();
      event.Skip();
    }
  }

  class OnBtnNovoClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      btnNovoClick();
      InformaLimpaDados(false);
      HabilitaDados(true);
      event.Skip();
    }
  }

  class OnBtnPesquisarClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      if (PesquisarDados(ConsultasSQL.ConsSQL.Cliente('S',
          edtCodigo.GetValue(), "", "", "", "", "", "", "", "", ""),
                         Resource.STR_CLINENC, 17)) {
        InformaLimpaDados(true);
        HabilitaDados(true);
      }
      event.Skip();
    }
  }

  class OnBtnAnteriorClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      if (registroAnterior()) {
        InformaLimpaDados(true);
      }
      event.Skip();
    }
  }

  class OnBtnProximoClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      if (registroProximo()) {
        InformaLimpaDados(true);
      }
      event.Skip();
    }
  }

  class OnBtnSalvarClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      String sSexo, sDtNasc, sSqlInsert, sSqlUpdate;

      if (rbSexo.GetSelection() == 0) {
        sSexo = "M";
      }
      else {
        sSexo = "F";

      }
      sDtNasc = RotinasGlobais.Rotinas.ConverteDataHoraStr(
          edtDtNasc.GetValue(), "dd/MM/yyyy", "yyyy-MM-dd HH:mm:ss.S");

      sSqlUpdate = ConsultasSQL.ConsSQL.Cliente('U', edtCodigo.GetValue(),
                                                edtDescricao.GetValue(),
                                                edtEmail.GetValue(),
                                                edtIdentidade.GetValue(), sSexo,
                                                edtTelefone.GetValue(),
                                                sDtNasc,
                                                edtCodEndereco.GetValue(),
                                                edtCodPais.GetValue(),
                                                edtCodProfissao.GetValue());

      sSqlInsert = ConsultasSQL.ConsSQL.Cliente('I', edtCodigo.GetValue(),
                                                edtDescricao.GetValue(),
                                                edtEmail.GetValue(),
                                                edtIdentidade.GetValue(), sSexo,
                                                edtTelefone.GetValue(),
                                                sDtNasc,
                                                edtCodEndereco.GetValue(),
                                                edtCodPais.GetValue(),
                                                edtCodProfissao.GetValue());

      if (SalvarDados(ValidaDados(true),
                      ConsultasSQL.ConsSQL.Cliente('S', edtCodigo.GetValue(),
          "", "", "", "", "", "", "", "", ""), sSqlUpdate, sSqlInsert, true)) {
        InformaLimpaDados(false);
        HabilitaDados(false);
      }
      event.Skip();
    }
  }

  class OnBtnExcluirClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      if (ExcluirDados(ValidaDados(false),
                       ConsultasSQL.ConsSQL.Cliente('D', edtCodigo.GetValue(),
          "", "", "", "", "", "", "", "", ""))) {
        InformaLimpaDados(false);
        HabilitaDados(false);
      }
      event.Skip();
    }
  }

  class OnBtnFecharClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      Close(true);
      event.Skip();
    }
  }

  class OnBtnLimparClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      btnLimparClick();
      InformaLimpaDados(false);
      HabilitaDados(false);
      event.Skip();
    }
  }

  protected void InformaLimpaDados(boolean bInformar) {
    super.InformaLimpaDados(bInformar);

    if (bInformar) {
      edtEmail.SetValue(Campos.get(2).toString());
      edtIdentidade.SetValue(Campos.get(3).toString());
      if (Campos.get(4).toString() == "M") {
        rbSexo.SetSelection(0);
      }
      else {
        rbSexo.SetSelection(1);
      }
      edtTelefone.SetValue(Campos.get(5).toString());
      edtDtNasc.SetValue(RotinasGlobais.Rotinas.ConverteDataHoraStr(
        Campos.get(6).toString(),"yyyy-MM-dd HH:mm:ss.S","dd/MM/yyyy"));
      edtCodEndereco.SetValue(Campos.get(7).toString());
      edtLogradouro.SetValue(Campos.get(8).toString());
      edtBairro.SetValue(Campos.get(9).toString());
      edtCEP.SetValue(Campos.get(10).toString());
      edtCidade.SetValue(Campos.get(11).toString());
      edtEstado.SetValue(Campos.get(12).toString());
      edtCodPais.SetValue(Campos.get(13).toString());
      edtPais.SetValue(Campos.get(14).toString());
      edtCodProfissao.SetValue(Campos.get(15).toString());
      edtProfissao.SetValue(Campos.get(16).toString());
    }
    else {
      edtEmail.Clear();
      edtIdentidade.Clear();
      rbSexo.SetSelection(0);
      edtTelefone.Clear();
      edtDtNasc.Clear();
      edtCodEndereco.Clear();
      edtLogradouro.Clear();
      edtBairro.Clear();
      edtCEP.Clear();
      edtCidade.Clear();
      edtEstado.Clear();
      edtCodPais.Clear();
      edtPais.Clear();
      edtCodProfissao.Clear();
      edtProfissao.Clear();
      edtCodigo.SetFocus();
    }
  }

  protected void HabilitaDados(boolean bHabilita) {
    super.HabilitaDados(bHabilita);
    if (bHabilita) {
      edtEmail.Enable();
      edtIdentidade.Enable();
      rbSexo.Enable();
      edtTelefone.Enable();
      edtDtNasc.Enable();
      edtCodEndereco.Enable();
      btnPEndereco.Enable();
      edtCodPais.Enable();
      btnPPais.Enable();
      edtCodProfissao.Enable();
      btnPProfissao.Enable();
    }
    else {
      edtEmail.Disable();
      edtIdentidade.Disable();
      rbSexo.Disable();
      edtTelefone.Disable();
      edtDtNasc.Disable();
      edtCodEndereco.Disable();
      btnPEndereco.Disable();
      edtCodPais.Disable();
      btnPPais.Disable();
      edtCodProfissao.Disable();
      btnPProfissao.Disable();
    }
  }

  class OnEdtCodigo_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      if (edtCodigo.GetValue().length() > 0) {
        if (RotinasGlobais.Rotinas.ValidaCPF(edtCodigo.GetValue()) == false) {
          wx.wxMessageBox(Resource.STR_CPFINV, "Erro",
                          wx.wxOK | wx.wxICON_ERROR);
          edtCodigo.Clear();
          edtCodigo.SetFocus();
        }
      }
    }
  }

  class OnEdtDtNasc_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      if (edtDtNasc.GetValue().length() > 0) {
        if (!RotinasGlobais.Rotinas.validaDataHora(edtDtNasc.GetValue(),
            true)) {
          wx.wxMessageBox(Resource.STR_DTHRINV, "Erro",
                          wx.wxOK | wx.wxICON_ERROR);
          edtDtNasc.SetValue(RotinasGlobais.Rotinas.retDataHoraStr(
            true, false));
          edtDtNasc.SetFocus();
        }
      }
      else {
        edtDtNasc.SetValue(RotinasGlobais.Rotinas.retDataHoraStr(
            true, false));
      }
      event.Skip();
    }
  }

  class OnEdtCodEndereco_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      try {
        if (edtCodEndereco.GetValue().length() > 0) {
          Consulta = RotinasGlobais.Rotinas.ConsultaCampoDesc(
              ConsultasSQL.ConsSQL.Endereco('S',
                                            edtCodEndereco.GetValue(), "", "",
                                            "",
                                            "", ""), Resource.STR_ENDNENC);
          if (Consulta != null) {
            edtLogradouro.SetValue(Consulta.getObject(2).toString());
            edtBairro.SetValue(Consulta.getObject(3).toString());
            edtCEP.SetValue(Consulta.getObject(4).toString());
            edtCidade.SetValue(Consulta.getObject(5).toString());
            edtEstado.SetValue(Consulta.getObject(6).toString());
          }
          else {
            edtCodEndereco.SetFocus();
            edtLogradouro.Clear();
            edtBairro.Clear();
            edtCEP.Clear();
            edtCidade.Clear();
            edtEstado.Clear();
          }
        }
        else {
          edtLogradouro.Clear();
          edtBairro.Clear();
          edtCEP.Clear();
          edtCidade.Clear();
          edtEstado.Clear();
        }
      }
      catch (SQLException se) {
        wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);

      }

    }
  }

  class OnEdtCodPais_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      try {
        if (edtCodPais.GetValue().length() > 0) {
          Consulta = RotinasGlobais.Rotinas.ConsultaCampoDesc(
              ConsultasSQL.ConsSQL.Pais('S',
                                        edtCodPais.GetValue(), ""),
              Resource.STR_PAISNENC);
          if (Consulta != null) {
            edtPais.SetValue(Consulta.getObject(2).toString());
          }
          else {
            edtCodPais.Clear();
            edtCodPais.SetFocus();
          }
        }
        else {
          edtPais.Clear();
        }
      }
      catch (SQLException se) {
        wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);

      }

    }
  }

  class OnEdtCodProfissao_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      try {
        if (edtCodProfissao.GetValue().length() > 0) {
          Consulta = RotinasGlobais.Rotinas.ConsultaCampoDesc(
              ConsultasSQL.ConsSQL.Profissao('S',
                                             edtCodProfissao.GetValue(), ""),
              Resource.STR_PROFNENC);

          if (Consulta != null) {
            edtProfissao.SetValue(Consulta.getObject(2).toString());
          }
          else {
            edtCodProfissao.Clear();
            edtCodProfissao.SetFocus();
          }
        }
        else {
          edtProfissao.Clear();
        }
      }
      catch (SQLException se) {
        wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
      }
    }
  }

  class OnBtnPEndereco
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      frmConEnderecos fConEnderecos = new frmConEnderecos(null);
      fConEnderecos.ShowModal();
      edtCodEndereco.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado);
      OnEdtCodEndereco_Killfocus kf = new OnEdtCodEndereco_Killfocus();
      kf.handleEvent(null);
      event.Skip();
    }
  }

  class OnBtnPPais
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      frmConPaises fConPaises = new frmConPaises(null);
      fConPaises.ShowModal();
      edtCodPais.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado);
      OnEdtCodPais_Killfocus kf = new OnEdtCodPais_Killfocus();
      kf.handleEvent(null);
      event.Skip();
    }
  }

  class OnBtnPProfissao
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      frmConProfissoes fConProfissoes = new frmConProfissoes(null);
      fConProfissoes.ShowModal();
      edtCodProfissao.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado);
      OnEdtCodProfissao_Killfocus kf = new OnEdtCodProfissao_Killfocus();
      kf.handleEvent(null);
      event.Skip();
    }
  }
}
