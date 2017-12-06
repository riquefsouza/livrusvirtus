package Livrus;

import org.wxwindows.*;

public class frmCadEnderecos
    extends frmCadastros {

  private static int ID_FRMCADENDERECOS_CMBESTADO = 700;
  private static int ID_FRMCADENDERECOS_EDTBAIRRO = 701;
  private static int ID_FRMCADENDERECOS_EDTCEP = 702;
  private static int ID_FRMCADENDERECOS_EDTCIDADE = 703;
  private static int ID_FRMCADENDERECOS_LABBAIRRO = 704;
  private static int ID_FRMCADENDERECOS_LABCEP = 705;
  private static int ID_FRMCADENDERECOS_LABCIDADE = 706;
  private static int ID_FRMCADENDERECOS_LABESTADO = 707;

  private wxStaticText labBairro;
  private wxTextCtrl edtBairro;
  private wxTextCtrl edtCEP;
  private wxStaticText labCEP;
  private wxTextCtrl edtCidade;
  private wxStaticText labCidade;
  private wxStaticText labEstado;
  private wxChoice cmbEstado;
  private String[] vsEstados;

  public frmCadEnderecos(wxWindow parent) {
    super(parent, TextValidator.FILTER_NUMERIC, false);

    labDescricao.SetLabel("Logradouro:");
    labDescricao.SetSize(new wxSize(57, 13));
    edtDescricao.SetSize(new wxSize(264, 21));

    labBairro = new wxStaticText(this, ID_FRMCADENDERECOS_LABBAIRRO,
                                 "Bairro:", new wxPoint(280, 48),
                                 new wxSize(48, 13));
    edtBairro = new wxTextCtrl(this, ID_FRMCADENDERECOS_EDTBAIRRO,
                               "", new wxPoint(280, 64), new wxSize(144, 21));
    edtBairro.Disable();
    labCEP = new wxStaticText(this, ID_FRMCADENDERECOS_LABCEP,
                              "CEP: ", new wxPoint(8, 88), new wxSize(40, 13));
    edtCEP = new wxTextCtrl(this, ID_FRMCADENDERECOS_EDTCEP,
                            "", new wxPoint(8, 104), new wxSize(72, 21));
    edtCEP.Disable();
    labCidade = new wxStaticText(this, ID_FRMCADENDERECOS_LABCIDADE,
                                 "Cidade: ", new wxPoint(88, 88),
                                 new wxSize(39, 13));
    edtCidade = new wxTextCtrl(this, ID_FRMCADENDERECOS_EDTCIDADE,
                               "", new wxPoint(88, 104), new wxSize(184, 21));
    edtCidade.Disable();
    labEstado = new wxStaticText(this, ID_FRMCADENDERECOS_LABESTADO,
                                 "Estado: ", new wxPoint(280, 88),
                                 new wxSize(56, 13));
    AdicionaCombo();
    cmbEstado = new wxChoice(this, ID_FRMCADENDERECOS_CMBESTADO,
                             new wxPoint(280, 104), new wxSize(144, 21),
                             vsEstados);
    cmbEstado.Disable();
    IniciaBotoes();

    btnPesquisar.SetSize(440, 8, 75, 25);
    btnAnterior.SetSize(440, 40, 75, 25);
    btnProximo.SetSize(440, 72, 75, 25);
    btnSalvar.SetSize(200, 136, 75, 25);
    btnExcluir.SetSize(280, 136, 75, 25);
    btnLimpar.SetSize(360, 136, 75, 25);
    btnFechar.SetSize(440, 136, 75, 25);

    FazLayout();

    edtDescricao.SetValidator(new TextValidator(edtDescricao,
                                                TextValidator.FILTER_NONE, 40));
    edtBairro.SetValidator(new TextValidator(edtBairro,
                                             TextValidator.FILTER_NONE, 15));
    edtCEP.SetValidator(new TextValidator(edtCEP,
                                          TextValidator.FILTER_NONE, 8));
    edtCidade.SetValidator(new TextValidator(edtCidade,
                                             TextValidator.FILTER_NONE, 30));

    EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, new OnBtnNovoClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, new OnBtnPesquisarClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, new OnBtnAnteriorClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, new OnBtnProximoClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, new OnBtnSalvarClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, new OnBtnExcluirClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, new OnBtnLimparClick());
    EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, new OnBtnFecharClick());
    EVT_CLOSE(new OnClose());
  }

  private void FazLayout() {
    wxBoxSizer wxSizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer wxSizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer wxSizer_3 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer wxSizer_4 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer wxSizer_5 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer wxSizer_6 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_wxSizer_6 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_wxSizer_5 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_wxSizer_4 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer wxSizer_8 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_wxSizer_9 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_wxSizer_8 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer wxSizer_7 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_wxSizer_7 = new wxGridSizer(2, 1, 0, 0);
    grid_wxSizer_7.Add(labCodigo, 0, wxALIGN_BOTTOM, 0);
    grid_wxSizer_7.Add(edtCodigo, 0, 0, 0);
    wxSizer_7.Add(grid_wxSizer_7, 0, 0, 0);
    wxSizer_7.Add(btnNovo, 0, wxLEFT | wxALIGN_BOTTOM, 5);
    wxSizer_5.Add(wxSizer_7, 1, 0, 0);
    grid_wxSizer_8.Add(labDescricao, 0, wxALIGN_BOTTOM, 0);
    grid_wxSizer_8.Add(edtDescricao, 0, 0, 0);
    wxSizer_8.Add(grid_wxSizer_8, 0, 0, 0);
    grid_wxSizer_9.Add(labBairro, 0, wxALIGN_BOTTOM, 0);
    grid_wxSizer_9.Add(edtBairro, 0, 0, 0);
    wxSizer_8.Add(grid_wxSizer_9, 0, wxLEFT, 2);
    wxSizer_5.Add(wxSizer_8, 1, wxEXPAND, 0);
    grid_wxSizer_4.Add(labCEP, 0, wxALIGN_BOTTOM, 0);
    grid_wxSizer_4.Add(edtCEP, 0, 0, 0);
    wxSizer_6.Add(grid_wxSizer_4, 0, 0, 0);
    grid_wxSizer_5.Add(labCidade, 0, wxALIGN_BOTTOM, 0);
    grid_wxSizer_5.Add(edtCidade, 0, 0, 0);
    wxSizer_6.Add(grid_wxSizer_5, 0, wxLEFT, 4);
    grid_wxSizer_6.Add(labEstado, 0, wxALIGN_BOTTOM, 0);
    grid_wxSizer_6.Add(cmbEstado, 0, 0, 0);
    wxSizer_6.Add(grid_wxSizer_6, 0, wxLEFT, 5);
    wxSizer_5.Add(wxSizer_6, 0, 0, 0);
    wxSizer_3.Add(wxSizer_5, 0, 0, 0);
    wxSizer_4.Add(btnPesquisar, 0, wxALL |
                  wxALIGN_RIGHT, 2);
    wxSizer_4.Add(btnAnterior, 0, wxALL |
                  wxALIGN_RIGHT, 2);
    wxSizer_4.Add(btnProximo, 0, wxALL |
                  wxALIGN_RIGHT, 2);
    wxSizer_3.Add(wxSizer_4, 1, 0, 0);
    wxSizer_1.Add(wxSizer_3, 1, wxALL | wxEXPAND, 4);
    wxSizer_2.Add(btnSalvar, 0, wxALL |
                  wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    wxSizer_2.Add(btnExcluir, 0, wxALL |
                  wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    wxSizer_2.Add(btnLimpar, 0, wxALL |
                  wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    wxSizer_2.Add(btnFechar, 0, wxALL |
                  wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    wxSizer_1.Add(wxSizer_2, 0, wxRIGHT | wxBOTTOM |
                  wxALIGN_RIGHT | wxALIGN_BOTTOM, 4);
    SetAutoLayout(true);
    SetSizer(wxSizer_1);
    wxSizer_1.Fit(this);
    wxSizer_1.SetSizeHints(this);
  }

  private boolean ValidaDados(boolean bTodosDados) {
    if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.GetValue(),
                                           Resource.STR_CODNINF)) {
      return false;
    }
    if (bTodosDados) {
      if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.GetValue(),
                                             Resource.STR_ENDNINF)) {
        return false;
      }
      if (RotinasGlobais.Rotinas.ValidaCampo(edtBairro.GetValue(),
                                             Resource.STR_BAIRRONINF)) {
        return false;
      }
      if (RotinasGlobais.Rotinas.ValidaCampo(edtCEP.GetValue(),
                                             Resource.STR_CEPNINF)) {
        return false;
      }
      if (RotinasGlobais.Rotinas.ValidaCampo(edtCidade.GetValue(),
                                             Resource.STR_CIDADENINF)) {
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
      NovoDado(ConsultasSQL.ConsSQL.Endereco('N', edtCodigo.GetValue(), "", "",
                                             "", "", ""));
      event.Skip();
    }
  }

  class OnBtnPesquisarClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      if (PesquisarDados(ConsultasSQL.ConsSQL.Endereco('S',
          edtCodigo.GetValue(), "", "", "", "", ""),
                         Resource.STR_ENDNENC, 6)) {
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
      if (SalvarDados(ValidaDados(true),
                      ConsultasSQL.ConsSQL.Endereco('S', edtCodigo.GetValue(),
          "", "", "", "", ""),
                      ConsultasSQL.ConsSQL.Endereco('U', edtCodigo.GetValue(),
          edtDescricao.GetValue(), edtBairro.GetValue(), edtCEP.GetValue(),
          edtCidade.GetValue(), cmbEstado.GetStringSelection()),
                      ConsultasSQL.ConsSQL.Endereco('I', edtCodigo.GetValue(),
          edtDescricao.GetValue(), edtBairro.GetValue(), edtCEP.GetValue(),
          edtCidade.GetValue(), cmbEstado.GetStringSelection()), true)) {
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
                       ConsultasSQL.ConsSQL.Endereco('D', edtCodigo.GetValue(),
          "", "", "", "", ""))) {
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
      edtBairro.SetValue(Campos.get(2).toString());
      edtCEP.SetValue(Campos.get(3).toString());
      edtCidade.SetValue(Campos.get(4).toString());
      cmbEstado.SetStringSelection(Campos.get(5).toString());
    }
    else {
      edtBairro.Clear();
      edtCEP.Clear();
      edtCidade.Clear();
      cmbEstado.SetSelection(0);
    }
  }

  protected void HabilitaDados(boolean bHabilita) {
    super.HabilitaDados(bHabilita);
    if (bHabilita) {
      edtBairro.Enable();
      edtCEP.Enable();
      edtCidade.Enable();
      cmbEstado.Enable();
    }
    else {
      edtBairro.Disable();
      edtCEP.Disable();
      edtCidade.Disable();
      cmbEstado.Disable();
    }
  }

  private void AdicionaCombo() {
    vsEstados = new String[26];
    vsEstados[0] = Resource.STR_PE;
    vsEstados[1] = Resource.STR_AC;
    vsEstados[2] = Resource.STR_AL;
    vsEstados[3] = Resource.STR_AP;
    vsEstados[4] = Resource.STR_AM;
    vsEstados[5] = Resource.STR_BA;
    vsEstados[6] = Resource.STR_BR;
    vsEstados[7] = Resource.STR_CE;
    vsEstados[8] = Resource.STR_DF;
    vsEstados[9] = Resource.STR_ES;
    vsEstados[10] = Resource.STR_GO;
    vsEstados[11] = Resource.STR_MT;
    vsEstados[12] = Resource.STR_MS;
    vsEstados[13] = Resource.STR_MG;
    vsEstados[14] = Resource.STR_PA;
    vsEstados[15] = Resource.STR_PB;
    vsEstados[16] = Resource.STR_PR;
    vsEstados[17] = Resource.STR_SC;
    vsEstados[18] = Resource.STR_RN;
    vsEstados[19] = Resource.STR_RS;
    vsEstados[20] = Resource.STR_RJ;
    vsEstados[21] = Resource.STR_RO;
    vsEstados[22] = Resource.STR_RR;
    vsEstados[23] = Resource.STR_SP;
    vsEstados[24] = Resource.STR_SE;
    vsEstados[25] = Resource.STR_TO;
  }
}
