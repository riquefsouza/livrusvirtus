package Livrus;

import org.wxwindows.*;
import java.sql.*;
import java.util.*;

public class frmCadLivros
    extends frmCadastros {

  private static int ID_FRMCADLIVROS_BTNADASSUNTOS = 900;
  private static int ID_FRMCADLIVROS_BTNADAUTORES = 901;
  private static int ID_FRMCADLIVROS_BTNPASSUNTO = 902;
  private static int ID_FRMCADLIVROS_BTNPAUTOR = 903;
  private static int ID_FRMCADLIVROS_BTNPEDITORA = 904;
  private static int ID_FRMCADLIVROS_CMBIDIOMA = 905;
  private static int ID_FRMCADLIVROS_EDTANOPUBLI = 906;
  private static int ID_FRMCADLIVROS_EDTASSUNTO = 907;
  private static int ID_FRMCADLIVROS_EDTAUTOR = 908;
  private static int ID_FRMCADLIVROS_EDTCODASSUNTO = 909;
  private static int ID_FRMCADLIVROS_EDTCODAUTOR = 910;
  private static int ID_FRMCADLIVROS_EDTCODEDITORA = 911;
  private static int ID_FRMCADLIVROS_EDTEDICAO = 912;
  private static int ID_FRMCADLIVROS_EDTEDITORA = 913;
  private static int ID_FRMCADLIVROS_EDTNPAGINAS = 914;
  private static int ID_FRMCADLIVROS_EDTPRECO = 915;
  private static int ID_FRMCADLIVROS_EDTQTDESTOQUE = 916;
  private static int ID_FRMCADLIVROS_EDTVOLUME = 917;
  private static int ID_FRMCADLIVROS_LABANOPUBLI = 918;
  private static int ID_FRMCADLIVROS_LABASSUNTO = 919;
  private static int ID_FRMCADLIVROS_LABAUTOR = 920;
  private static int ID_FRMCADLIVROS_LABEDICAO = 921;
  private static int ID_FRMCADLIVROS_LABEDITORA = 922;
  private static int ID_FRMCADLIVROS_LABIDIOMA = 923;
  private static int ID_FRMCADLIVROS_LABNPAGINAS = 924;
  private static int ID_FRMCADLIVROS_LABPRECO = 925;
  private static int ID_FRMCADLIVROS_LABQTDESTOQUE = 926;
  private static int ID_FRMCADLIVROS_LABVOLUME = 927;
  private static int ID_FRMCADLIVROS_LSTASSUNTOS = 928;
  private static int ID_FRMCADLIVROS_LSTAUTORES = 930;

  private ArrayList slIdiomas, slAssuntos, slAutores;
  private wxStaticText labEdicao;
  private wxTextCtrl edtEdicao;
  private wxStaticText labAnoPubli;
  private wxTextCtrl edtAnoPubli;
  private wxStaticText labEditora;
  private wxTextCtrl edtCodEditora;
  private wxTextCtrl edtEditora;
  private wxButton btnPEditora;
  private wxStaticText labVolume;
  private wxTextCtrl edtVolume;
  private wxStaticText labIdioma;
  private wxChoice cmbIdioma;
  private wxStaticText labNPaginas;
  private wxTextCtrl edtNPaginas;
  private wxStaticText labAssunto;
  private wxTextCtrl edtCodAssunto;
  private wxTextCtrl edtAssunto;
  private wxButton btnAdAssuntos;
  private wxButton btnPAssunto;
  private wxListBox lstAssuntos;
  private wxStaticText labPreco;
  private wxTextCtrl edtPreco;
  private wxStaticText labQtdEstoque;
  private wxTextCtrl edtQtdEstoque;
  private wxStaticText labAutor;
  private wxTextCtrl edtCodAutor;
  private wxTextCtrl edtAutor;
  private wxButton btnAdAutores;
  private wxButton btnPAutor;
  private wxListBox lstAutores;
  private String[] vsIdiomas;

  public frmCadLivros(wxWindow parent) {
    super(parent, TextValidator.FILTER_NONE, false);

    slIdiomas = new ArrayList();
    slAssuntos = new ArrayList();
    slAutores = new ArrayList();

    labCodigo.SetLabel("ISBN: ");
    labDescricao.SetLabel("Título: ");
    edtDescricao.SetSize(new wxSize(312, 21));
    edtCodigo.EVT_KILL_FOCUS(new OnEdtCodigo_Killfocus());

    labEdicao = new wxStaticText(this, ID_FRMCADLIVROS_LABEDICAO,
                                 "Edição: ", new wxPoint(326, 48),
                                 new wxSize(39, 13), 0);
    edtEdicao = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTEDICAO,
                               "1", new wxPoint(324, 64), new wxSize(92, 21), 0);
    edtEdicao.Disable();

    labAnoPubli = new wxStaticText(this, ID_FRMCADLIVROS_LABANOPUBLI,
                                   "Ano Publicação: ", new wxPoint(8, 88),
                                   new wxSize(81, 13), 0);
    edtAnoPubli = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTANOPUBLI,
                                 "1", new wxPoint(8, 104), new wxSize(92, 21),
                                 0);
    edtAnoPubli.Disable();

    labEditora = new wxStaticText(this, ID_FRMCADLIVROS_LABEDITORA,
                                  "Editora: ", new wxPoint(104, 88),
                                  new wxSize(39, 13), 0);
    edtCodEditora = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTCODEDITORA,
                                   "", new wxPoint(104, 104), new wxSize(78, 21),
                                   0);
    edtCodEditora.Disable();
    edtCodEditora.EVT_KILL_FOCUS(new OnEdtCodEditora_Killfocus());

    edtEditora = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTEDITORA,
                                "", new wxPoint(184, 104), new wxSize(216, 21),
                                0);
    edtEditora.Disable();

    btnPEditora = new wxButton(this, ID_FRMCADLIVROS_BTNPEDITORA,
                               "...", new wxPoint(400, 104), new wxSize(21, 21),
                               0);
    btnPEditora.Disable();

    labVolume = new wxStaticText(this, ID_FRMCADLIVROS_LABVOLUME,
                                 "Volume: ", new wxPoint(8, 128),
                                 new wxSize(41, 13), 0);
    edtVolume = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTVOLUME,
                               "1", new wxPoint(8, 144), new wxSize(92, 21), 0);
    edtVolume.Disable();

    labIdioma = new wxStaticText(this, ID_FRMCADLIVROS_LABIDIOMA,
                                 "Idioma: ", new wxPoint(104, 128),
                                 new wxSize(56, 13), 0);

    AdicionaCombo();
    cmbIdioma = new wxChoice(this, ID_FRMCADLIVROS_CMBIDIOMA,
                             new wxPoint(104, 144), new wxSize(320, 21),
                             vsIdiomas);
    cmbIdioma.Disable();

    labNPaginas = new wxStaticText(this, ID_FRMCADLIVROS_LABNPAGINAS,
                                   "Nº Páginas: ", new wxPoint(8, 168),
                                   new wxSize(59, 13), 0);

    edtNPaginas = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTNPAGINAS,
                                 "1", new wxPoint(8, 184), new wxSize(92, 21),
                                 0);
    edtNPaginas.Disable();

    labAssunto = new wxStaticText(this, ID_FRMCADLIVROS_LABASSUNTO,
                                  "Assunto: ", new wxPoint(104, 168),
                                  new wxSize(44, 13), 0);

    edtCodAssunto = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTCODASSUNTO,
                                   "", new wxPoint(104, 184), new wxSize(78, 21),
                                   0);
    edtCodAssunto.Disable();
    edtCodAssunto.EVT_KILL_FOCUS(new OnEdtCodAssunto_Killfocus());

    edtAssunto = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTASSUNTO,
                                "", new wxPoint(184, 184), new wxSize(192, 21),
                                0);
    edtAssunto.Disable();

    btnAdAssuntos = new wxButton(this, ID_FRMCADLIVROS_BTNADASSUNTOS,
                                 "+", new wxPoint(376, 184), new wxSize(21, 21),
                                 0);
    btnAdAssuntos.Disable();

    btnPAssunto = new wxButton(this, ID_FRMCADLIVROS_BTNPASSUNTO,
                               "...", new wxPoint(400, 184), new wxSize(21, 21),
                               0);
    btnPAssunto.Disable();

    lstAssuntos = new wxListBox(this, ID_FRMCADLIVROS_LSTASSUNTOS,
                                new wxPoint(104, 208), new wxSize(320, 48));
    lstAssuntos.Disable();

    labPreco = new wxStaticText(this, ID_FRMCADLIVROS_LABPRECO,
                                "Preço: ", new wxPoint(8, 216),
                                new wxSize(40, 13), 0);

    edtPreco = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTPRECO,
                              "", new wxPoint(7, 232), new wxSize(92, 21), 0);
    edtPreco.Disable();
    edtPreco.EVT_KILL_FOCUS(new OnEdtPreco_Killfocus());

    labQtdEstoque = new wxStaticText(this, ID_FRMCADLIVROS_LABQTDESTOQUE,
                                     "Qtd. Estoque: ", new wxPoint(6, 256),
                                     new wxSize(68, 13), 0);

    edtQtdEstoque = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTQTDESTOQUE,
                                   "0", new wxPoint(8, 272), new wxSize(92, 21),
                                   0);
    edtQtdEstoque.Disable();

    labAutor = new wxStaticText(this, ID_FRMCADLIVROS_LABAUTOR,
                                "Autor: ", new wxPoint(104, 256),
                                new wxSize(31, 13), 0);
    edtCodAutor = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTCODAUTOR,
                                 "", new wxPoint(104, 272), new wxSize(78, 21),
                                 0);
    edtCodAutor.Disable();
    edtCodAutor.EVT_KILL_FOCUS(new OnEdtCodAutor_Killfocus());

    edtAutor = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTAUTOR,
                              "", new wxPoint(184, 272), new wxSize(192, 21), 0);
    edtAutor.Disable();

    btnAdAutores = new wxButton(this, ID_FRMCADLIVROS_BTNADAUTORES,
                                "+", new wxPoint(376, 272), new wxSize(21, 21),
                                0);
    btnAdAutores.Disable();

    btnPAutor = new wxButton(this, ID_FRMCADLIVROS_BTNPAUTOR, "...",
                             new wxPoint(400, 272), new wxSize(21, 21), 0);
    btnPAutor.Disable();

    lstAutores = new wxListBox(this, ID_FRMCADLIVROS_LSTAUTORES,
                               new wxPoint(104, 296), new wxSize(320, 48));
    lstAutores.Disable();

    IniciaBotoes();
    btnPesquisar.SetSize(427, 8, 75, 25);
    btnAnterior.SetSize(427, 40, 75, 25);
    btnProximo.SetSize(427, 72, 75, 25);
    btnSalvar.SetSize(187, 352, 75, 25);
    btnExcluir.SetSize(267, 352, 75, 25);
    btnLimpar.SetSize(347, 352, 75, 25);
    btnFechar.SetSize(427, 352, 75, 25);

    FazLayout();

    edtCodigo.SetValidator(new TextValidator(edtCodigo,
                                             TextValidator.FILTER_NONE, 13));
    edtDescricao.SetValidator(new TextValidator(edtDescricao,
                                                TextValidator.FILTER_NONE, 50));
    edtCodEditora.SetValidator(new TextValidator(edtCodEditora,
                                                 TextValidator.FILTER_NUMERIC,
                                                 5));
    edtPreco.SetValidator(new TextValidator(edtPreco,
                                            TextValidator.FILTER_NONE, 7));
    edtEdicao.SetValidator(new TextValidator(edtEdicao,
                                             TextValidator.FILTER_NUMERIC, 4));
    edtAnoPubli.SetValidator(new TextValidator(edtAnoPubli,
                                             TextValidator.FILTER_NUMERIC, 4));
    edtVolume.SetValidator(new TextValidator(edtVolume,
                                             TextValidator.FILTER_NUMERIC, 4));
    edtNPaginas.SetValidator(new TextValidator(edtNPaginas,
                                             TextValidator.FILTER_NUMERIC, 4));
    edtQtdEstoque.SetValidator(new TextValidator(edtQtdEstoque,
                                             TextValidator.FILTER_NUMERIC, 4));

    EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, new OnBtnNovoClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, new OnBtnPesquisarClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, new OnBtnAnteriorClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, new OnBtnProximoClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, new OnBtnSalvarClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, new OnBtnExcluirClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, new OnBtnLimparClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, new OnBtnFecharClick());
    EVT_CLOSE(new OnClose());
    EVT_BUTTON(ID_FRMCADLIVROS_BTNPEDITORA, new OnBtnPEditora());
    EVT_BUTTON(ID_FRMCADLIVROS_BTNPASSUNTO, new OnBtnPAssunto());
    EVT_BUTTON(ID_FRMCADLIVROS_BTNADASSUNTOS, new OnBtnAdAssuntos());
    EVT_BUTTON(ID_FRMCADLIVROS_BTNPAUTOR, new OnBtnPAutor());
    EVT_BUTTON(ID_FRMCADLIVROS_BTNADAUTORES, new OnBtnAdAutores());
    EVT_LISTBOX_DCLICK(ID_FRMCADLIVROS_LSTASSUNTOS, new OnLstAssuntos_Dblclk());
    EVT_LISTBOX_DCLICK(ID_FRMCADLIVROS_LSTAUTORES, new OnLstAutores_Dblclk());
  }

  private void FazLayout() {
    wxBoxSizer sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_4 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_5 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_21 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_20 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_37 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_36 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_35 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_34 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_33 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_19 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_32 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_18 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_31 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_30 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_29 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_28 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_27 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_17 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_26 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_25 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_6 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_24 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_6 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_5 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_4 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_8 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_9 = new wxGridSizer(2, 1, 0, 0);
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
    grid_sizer_9.Add(labEdicao, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_9.Add(edtEdicao, 0, 0, 0);
    sizer_8.Add(grid_sizer_9, 0, wxLEFT, 2);
    sizer_5.Add(sizer_8, 1, wxEXPAND, 0);
    grid_sizer_4.Add(labAnoPubli, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_4.Add(edtAnoPubli, 0, 0, 0);
    sizer_6.Add(grid_sizer_4, 0, 0, 0);
    grid_sizer_5.Add(labEditora, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_5.Add(edtCodEditora, 0, 0, 0);
    sizer_6.Add(grid_sizer_5, 0, wxLEFT, 4);
    grid_sizer_6.Add(20, 20, 0, 0, 0);
    grid_sizer_6.Add(edtEditora, 0, 0, 0);
    sizer_6.Add(grid_sizer_6, 0, wxLEFT, 2);
    grid_sizer_24.Add(20, 20, 0, 0, 0);
    grid_sizer_24.Add(btnPEditora, 0, 0, 0);
    sizer_6.Add(grid_sizer_24, 0, 0, 0);
    sizer_5.Add(sizer_6, 0, 0, 0);
    grid_sizer_25.Add(labVolume, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_25.Add(edtVolume, 0, 0, 0);
    sizer_17.Add(grid_sizer_25, 0, wxEXPAND, 0);
    grid_sizer_26.Add(labIdioma, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_26.Add(cmbIdioma, 0, 0, 0);
    sizer_17.Add(grid_sizer_26, 0, wxLEFT | wxEXPAND, 4);
    sizer_5.Add(sizer_17, 1, 0, 0);
    grid_sizer_27.Add(labNPaginas, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_27.Add(edtNPaginas, 0, 0, 0);
    sizer_18.Add(grid_sizer_27, 0, 0, 0);
    grid_sizer_28.Add(labAssunto, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_28.Add(edtCodAssunto, 0, 0, 0);
    sizer_18.Add(grid_sizer_28, 0, wxLEFT, 4);
    grid_sizer_29.Add(20, 20, 0, 0, 0);
    grid_sizer_29.Add(edtAssunto, 0, 0, 0);
    sizer_18.Add(grid_sizer_29, 0, wxLEFT, 2);
    grid_sizer_30.Add(20, 20, 0, 0, 0);
    grid_sizer_30.Add(btnAdAssuntos, 0, 0, 0);
    sizer_18.Add(grid_sizer_30, 0, 0, 0);
    grid_sizer_31.Add(20, 20, 0, 0, 0);
    grid_sizer_31.Add(btnPAssunto, 0, 0, 0);
    sizer_18.Add(grid_sizer_31, 0, 0, 0);
    sizer_5.Add(sizer_18, 1, 0, 0);
    grid_sizer_32.Add(labPreco, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_32.Add(edtPreco, 0, 0, 0);
    sizer_19.Add(grid_sizer_32, 0, 0, 0);
    sizer_19.Add(lstAssuntos, 0, wxLEFT, 4);
    sizer_5.Add(sizer_19, 1, 0, 0);
    grid_sizer_33.Add(labQtdEstoque, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_33.Add(edtQtdEstoque, 0, 0, 0);
    sizer_20.Add(grid_sizer_33, 0, 0, 0);
    grid_sizer_34.Add(labAutor, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_34.Add(edtCodAutor, 0, 0, 0);
    sizer_20.Add(grid_sizer_34, 0, wxLEFT, 4);
    grid_sizer_35.Add(20, 20, 0, 0, 0);
    grid_sizer_35.Add(edtAutor, 0, 0, 0);
    sizer_20.Add(grid_sizer_35, 0, wxLEFT, 2);
    grid_sizer_36.Add(20, 20, 0, 0, 0);
    grid_sizer_36.Add(btnAdAutores, 0, 0, 0);
    sizer_20.Add(grid_sizer_36, 0, 0, 0);
    grid_sizer_37.Add(20, 20, 0, 0, 0);
    grid_sizer_37.Add(btnPAutor, 0, 0, 0);
    sizer_20.Add(grid_sizer_37, 0, 0, 0);
    sizer_5.Add(sizer_20, 1, 0, 0);
    sizer_21.Add(92, 20, 0, 0, 0);
    sizer_21.Add(lstAutores, 0, 0, 0);
    sizer_5.Add(sizer_21, 0, 0, 0);
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
  }

  private boolean ValidaDados(boolean bTodosDados) {
    if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.GetValue(),
                                           Resource.STR_CODNINF)) {
      return false;
    }
    if (bTodosDados) {
      if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.GetValue(),
                                             Resource.STR_LIVNINF)) {
        return false;
      }
      if (RotinasGlobais.Rotinas.ValidaCampo(edtEditora.GetValue(),
                                             Resource.STR_EDTNINF)) {
        return false;
      }
      if (lstAssuntos.GetCount() == 0) {
        wx.wxMessageBox(Resource.STR_ASSNINF, "Erro",
                        wx.wxOK | wx.wxICON_ERROR);
        return false;
      }
      if (lstAutores.GetCount() == 0) {
        wx.wxMessageBox(Resource.STR_AUTNINF, "Erro",
                        wx.wxOK | wx.wxICON_ERROR);
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

      if (PesquisarDados(ConsultasSQL.ConsSQL.Livro('S',
          edtCodigo.GetValue(), "", "", "", "", "", "", "", "", ""),
                         Resource.STR_LIVNENC, 12)) {
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
      String sCodIdioma, sSqlInsert, sSqlUpdate;
      int nPos;

      nPos = cmbIdioma.GetSelection();
      sCodIdioma = slIdiomas.get(nPos).toString();

      sSqlUpdate = ConsultasSQL.ConsSQL.Livro('U', edtCodigo.GetValue(),
                                              edtDescricao.GetValue(),
                                              edtEdicao.GetValue(),
                                              edtAnoPubli.GetValue(),
                                              edtVolume.GetValue(),
                                              edtCodEditora.GetValue(),
                                              sCodIdioma, edtNPaginas.GetValue(),
                                              RotinasGlobais.Rotinas.
                                              VirgulaParaPonto(edtPreco.
          GetValue(), false),
                                              edtQtdEstoque.GetValue());

      sSqlInsert = ConsultasSQL.ConsSQL.Livro('I', edtCodigo.GetValue(),
                                              edtDescricao.GetValue(),
                                              edtEdicao.GetValue(),
                                              edtAnoPubli.GetValue(),
                                              edtVolume.GetValue(),
                                              edtCodEditora.GetValue(),
                                              sCodIdioma, edtNPaginas.GetValue(),
                                              RotinasGlobais.Rotinas.
                                              VirgulaParaPonto(edtPreco.
          GetValue(), false),
                                              edtQtdEstoque.GetValue());

      if (SalvarDados(ValidaDados(true), ConsultasSQL.ConsSQL.Livro('S',
          edtCodigo.GetValue(), "", "", "", "", "", "", "", "", ""),
                      sSqlUpdate, sSqlInsert, false)) {
        SalvaLista('A');
        SalvaLista('B');
        btnLimparClick();
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
                       ConsultasSQL.ConsSQL.Livro('D', edtCodigo.GetValue(),
                                                  "", "", "", "", "", "", "",
                                                  "", ""))) {
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
      edtEdicao.SetValue(Campos.get(2).toString());
      edtAnoPubli.SetValue(Campos.get(3).toString());
      edtVolume.SetValue(Campos.get(4).toString());
      edtCodEditora.SetValue(Campos.get(5).toString());
      edtEditora.SetValue(Campos.get(6).toString());
      cmbIdioma.SetStringSelection(Campos.get(8).toString());
      edtNPaginas.SetValue(Campos.get(9).toString());
      edtPreco.SetValue(RotinasGlobais.Rotinas.VirgulaParaPonto(
          Campos.get(10).toString(), true));
      edtQtdEstoque.SetValue(Campos.get(11).toString());
      RotinasGlobais.Rotinas.AdicionaValoresLista(
          ConsultasSQL.ConsSQL.LivroAss('S',
                                        edtCodigo.GetValue(), ""), lstAssuntos,
          slAssuntos);
      RotinasGlobais.Rotinas.AdicionaValoresLista(
          ConsultasSQL.ConsSQL.LivroAut('S',
                                        edtCodigo.GetValue(), ""), lstAutores,
          slAutores);
    }
    else {
      edtEdicao.SetValue("1");
      edtAnoPubli.SetValue(
          RotinasGlobais.Rotinas.retDataHoraStr(true, false).substring(6, 10));
      edtVolume.SetValue("1");
      edtCodEditora.Clear();
      edtEditora.Clear();
      cmbIdioma.SetSelection(0);
      edtNPaginas.SetValue("1");
      edtPreco.SetValue("0,00");
      edtQtdEstoque.SetValue("1");
      edtCodAssunto.Clear();
      lstAssuntos.Clear();
      edtCodAutor.Clear();
      lstAutores.Clear();
      slAssuntos.clear();
      slAutores.clear();
    }
  }

  protected void HabilitaDados(boolean bHabilita) {
    super.HabilitaDados(bHabilita);
    if (bHabilita) {
      edtEdicao.Enable();
      edtAnoPubli.Enable();
      edtVolume.Enable();
      edtCodEditora.Enable();
      btnPEditora.Enable();
      cmbIdioma.Enable();
      edtNPaginas.Enable();
      edtPreco.Enable();
      edtQtdEstoque.Enable();
      edtCodAssunto.Enable();
      btnPAssunto.Enable();
      btnAdAssuntos.Enable();
      lstAssuntos.Enable();
      edtCodAutor.Enable();
      btnPAutor.Enable();
      btnAdAutores.Enable();
      lstAutores.Enable();
    }
    else {
      edtEdicao.Disable();
      edtAnoPubli.Disable();
      edtVolume.Disable();
      edtCodEditora.Disable();
      btnPEditora.Disable();
      cmbIdioma.Disable();
      edtNPaginas.Disable();
      edtPreco.Disable();
      edtQtdEstoque.Disable();
      edtCodAssunto.Disable();
      btnPAssunto.Disable();
      btnAdAssuntos.Disable();
      lstAssuntos.Disable();
      edtCodAutor.Disable();
      btnPAutor.Disable();
      btnAdAutores.Disable();
      lstAutores.Disable();
    }
  }

  class OnEdtCodigo_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      if (edtCodigo.GetValue().length() > 0) {
        if (RotinasGlobais.Rotinas.ValidaISBN(edtCodigo.GetValue()) == false) {
          wx.wxMessageBox(Resource.STR_ISBNINV, "Erro",
                          wxDialog.wxOK | wxDialog.wxICON_ERROR);
          edtCodigo.Clear();
          edtCodigo.SetFocus();
        }
      }
    }
  }

  private void AdicionaCombo() {
    int nLinha;
    ArrayList lstLinhas = new ArrayList();

    if (RotinasGlobais.Rotinas.ConsultaDadosLista(lstLinhas,
                                                  ConsultasSQL.ConsSQL.Idioma(
        'S', "", ""), 2)) {
      vsIdiomas = new String[lstLinhas.size()];
      for (nLinha = 0; nLinha < lstLinhas.size(); nLinha++) {
        Campos = (ArrayList) lstLinhas.get(nLinha);
        slIdiomas.add(Campos.get(0).toString());
        vsIdiomas[nLinha] = Campos.get(1).toString();
        //cmbIdioma.Append(Campos.get(1).toString());
      }
    }
  }

  private void SalvaLista(char sOpcao) {
    String sISBN;
    int nCont, nQtd;

    sISBN = edtCodigo.GetValue();
    if (sOpcao == 'A') {
      RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
                                           ConsultasSQL.ConsSQL.LivroAss('D',
          sISBN, ""));

      nQtd = slAssuntos.size();
      for (nCont = 0; nCont < nQtd; nCont++) {
        RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
                                             ConsultasSQL.ConsSQL.LivroAss('I',
            sISBN, slAssuntos.get(nCont).toString()));
      }
    }
    else if (sOpcao == 'B') {
      RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
                                           ConsultasSQL.ConsSQL.LivroAut('D',
          sISBN, ""));

      nQtd = slAutores.size();
      for (nCont = 0; nCont < nQtd; nCont++) {
        RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
                                             ConsultasSQL.ConsSQL.LivroAut('I',
            sISBN, slAutores.get(nCont).toString()));
      }
    }
  }

  class OnEdtCodEditora_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      try {
        if (edtCodEditora.GetValue().length() > 0) {
          Consulta = RotinasGlobais.Rotinas.ConsultaCampoDesc(
              ConsultasSQL.ConsSQL.Editora('S',
                                           edtCodEditora.GetValue(), ""),
              Resource.STR_EDTNENC);
          if (Consulta != null) {
            edtEditora.SetValue(Consulta.getObject(2).toString());
          }
          else {
            edtCodEditora.Clear();
            edtCodEditora.SetFocus();
          }
        }
        else {
          edtEditora.Clear();
        }
      }
      catch (SQLException se) {
        wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
      }
    }
  }

  class OnBtnPEditora
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      frmConEditoras fConEditoras = new frmConEditoras(null);
      fConEditoras.ShowModal();
      edtCodEditora.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado);
      OnEdtCodEditora_Killfocus kf = new OnEdtCodEditora_Killfocus();
      kf.handleEvent(null);
      event.Skip();
    }
  }

  class OnEdtPreco_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      if (RotinasGlobais.Rotinas.ValidaFloat(
          RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.GetValue(), false))) {
        edtPreco.SetValue(
            RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.GetValue(), true));
      }
      else {
        edtPreco.SetValue("0,01");
        edtPreco.SetFocus();
      }
    }
  }

  class OnEdtCodAssunto_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      try {
        if (edtCodAssunto.GetValue().length() > 0) {
          Consulta = RotinasGlobais.Rotinas.ConsultaCampoDesc(
              ConsultasSQL.ConsSQL.Assunto('S',
                                           edtCodAssunto.GetValue(), ""),
              Resource.STR_ASSNENC);
          if (Consulta != null) {
            edtAssunto.SetValue(Consulta.getObject(2).toString());
          }
          else {
            edtCodAssunto.Clear();
            edtCodAssunto.SetFocus();
          }
        }
        else {
          edtAssunto.Clear();
        }
      }
      catch (SQLException se) {
        wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
      }
    }
  }

  class OnBtnPAssunto
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      frmConAssuntos fConAssuntos = new frmConAssuntos(null);
      fConAssuntos.ShowModal();
      edtCodAssunto.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado);
      OnEdtCodAssunto_Killfocus kf = new OnEdtCodAssunto_Killfocus();
      kf.handleEvent(null);
      event.Skip();
    }
  }

  class OnEdtCodAutor_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      try {
        if (edtCodAutor.GetValue().length() > 0) {
          Consulta = RotinasGlobais.Rotinas.ConsultaCampoDesc(
              ConsultasSQL.ConsSQL.Autor('S',
                                         edtCodAutor.GetValue(), ""),
              Resource.STR_AUTNENC);
          if (Consulta != null) {
            edtAutor.SetValue(Consulta.getObject(2).toString());
          }
          else {
            edtCodAutor.Clear();
            edtCodAutor.SetFocus();
          }
        }
        else {
          edtAutor.Clear();
        }
      }
      catch (SQLException se) {
        wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
      }
    }
  }

  class OnBtnPAutor
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      frmConAutores fConAutores = new frmConAutores(null);
      fConAutores.ShowModal();
      edtCodAutor.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado);
      OnEdtCodAutor_Killfocus kf = new OnEdtCodAutor_Killfocus();
      kf.handleEvent(null);
      event.Skip();
    }
  }

  class OnBtnAdAssuntos
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      RotinasGlobais.Rotinas.AdicionaItemLista(lstAssuntos,
                                               slAssuntos, edtCodAssunto,
                                               edtAssunto);
    }
  }

  class OnLstAssuntos_Dblclk
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      RotinasGlobais.Rotinas.RemoveItemLista(lstAssuntos, slAssuntos);
    }
  }

  class OnBtnAdAutores
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      RotinasGlobais.Rotinas.AdicionaItemLista(lstAutores,
                                               slAutores, edtCodAutor, edtAutor);
    }
  }

  class OnLstAutores_Dblclk
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      RotinasGlobais.Rotinas.RemoveItemLista(lstAutores, slAutores);
    }
  }
}
