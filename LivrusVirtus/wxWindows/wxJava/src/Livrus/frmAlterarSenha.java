package Livrus;

import org.wxwindows.*;
import java.sql.Statement;

public class frmAlterarSenha
    extends wxPanel {
  public static frmAlterarSenha fAlterarSenha = null;

  private static int ID_FRMALTERARSENHA_BTNFECHAR = 600;
  private static int ID_FRMALTERARSENHA_BTNLIMPAR = 601;
  private static int ID_FRMALTERARSENHA_BTNSALVAR = 602;
  private static int ID_FRMALTERARSENHA_EDTCONFIRMARSENHA = 603;
  private static int ID_FRMALTERARSENHA_EDTLOGIN = 604;
  private static int ID_FRMALTERARSENHA_EDTNOVASENHA = 605;
  private static int ID_FRMALTERARSENHA_EDTSENHAATUAL = 606;
  private static int ID_FRMALTERARSENHA_LABCONFIRMARSENHA = 607;
  private static int ID_FRMALTERARSENHA_LABLOGIN = 608;
  private static int ID_FRMALTERARSENHA_LABNOVASENHA = 609;
  private static int ID_FRMALTERARSENHA_LABSENHAATUAL = 610;

  Statement Arquiva;

  private wxStaticText labLogin;
  private wxTextCtrl edtLogin;
  private wxStaticText labSenhaAtual;
  private wxTextCtrl edtSenhaAtual;
  private wxStaticText labNovaSenha;
  private wxTextCtrl edtNovaSenha;
  private wxStaticText labConfirmarSenha;
  private wxTextCtrl edtConfirmarSenha;
  private wxButton btnSalvar;
  private wxButton btnLimpar;
  private wxButton btnFechar;

  public frmAlterarSenha(wxWindow parent) {
    super(parent, -1, new wxPoint(424, 292), new wxSize(257, 161), 0);
    //super(parent, -1, Resource.STR_ALTSENHA,
    //      new wxPoint(424, 292), new wxSize(257, 161));
    EVT_CLOSE( new OnClose() );

    labLogin = new wxStaticText(this, ID_FRMALTERARSENHA_LABLOGIN,
                                "Login: ", new wxPoint(8, 8), new wxSize(29, 13));
    edtLogin = new wxTextCtrl(this, ID_FRMALTERARSENHA_EDTLOGIN, "",
                              new wxPoint(8, 24), new wxSize(100, 21));
    edtLogin.Disable();
    labSenhaAtual = new wxStaticText(this, ID_FRMALTERARSENHA_LABSENHAATUAL,
                                     "Senha atual:", new wxPoint(112, 8),
                                     new wxSize(60, 13));
    edtSenhaAtual = new wxTextCtrl(this, ID_FRMALTERARSENHA_EDTSENHAATUAL,
                                   "", new wxPoint(112, 24), new wxSize(100, 21),
                                   wxTextCtrl.wxTE_PASSWORD);
    labNovaSenha = new wxStaticText(this, ID_FRMALTERARSENHA_LABNOVASENHA,
                                    "Nova Senha:", new wxPoint(8, 48),
                                    new wxSize(61, 13));
    edtNovaSenha = new wxTextCtrl(this, ID_FRMALTERARSENHA_EDTNOVASENHA,
                                  "", new wxPoint(8, 64), new wxSize(100, 21),
                                  wxTextCtrl.wxTE_PASSWORD);
    labConfirmarSenha = new wxStaticText(this,
                                         ID_FRMALTERARSENHA_LABCONFIRMARSENHA,
                                         "Confirmar senha:",
                                         new wxPoint(112, 48),
                                         new wxSize(79, 13));
    edtConfirmarSenha = new wxTextCtrl(this,
                                       ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, "",
                                       new wxPoint(112, 64), new wxSize(100, 21),
                                       wxTextCtrl.wxTE_PASSWORD);
    btnSalvar = new wxButton(this, ID_FRMALTERARSENHA_BTNSALVAR,
                             "&Salvar", new wxPoint(8, 104), new wxSize(75, 25));
    btnLimpar = new wxButton(this, ID_FRMALTERARSENHA_BTNLIMPAR,
                             "&Limpar", new wxPoint(88, 104), new wxSize(75, 25));
    btnFechar = new wxButton(this, ID_FRMALTERARSENHA_BTNFECHAR,
                             "&Fechar", new wxPoint(168, 104),
                             new wxSize(75, 25));

    edtLogin.SetValue(RotinasGlobais.Rotinas.sUsuarioLogin);
    edtSenhaAtual.SetValidator(new TextValidator(edtSenhaAtual,
                                                 TextValidator.FILTER_NONE, 10));
    edtNovaSenha.SetValidator(new TextValidator(edtNovaSenha,
                                                TextValidator.FILTER_NONE, 10));
    edtConfirmarSenha.SetValidator(new TextValidator(edtConfirmarSenha,
        TextValidator.FILTER_NONE, 10));

    EVT_BUTTON(ID_FRMALTERARSENHA_BTNSALVAR, new OnBtnSalvarClick());
    EVT_BUTTON(ID_FRMALTERARSENHA_BTNLIMPAR, new OnBtnLimparClick());
    EVT_BUTTON(ID_FRMALTERARSENHA_BTNFECHAR, new OnBtnFecharClick());

    FazLayout();
    edtSenhaAtual.SetFocus();
  }

  private void FazLayout() {
    wxBoxSizer sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_9 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_10 = new wxGridSizer(4, 1, 0, 0);
    wxGridSizer grid_sizer_3 = new wxGridSizer(4, 1, 0, 0);
    grid_sizer_3.Add(labLogin, 0,
                     wxLEFT | wxALIGN_BOTTOM, 8);
    grid_sizer_3.Add(edtLogin, 0, wxLEFT, 8);
    grid_sizer_3.Add(labNovaSenha, 0,
                     wxLEFT | wxALIGN_BOTTOM, 8);
    grid_sizer_3.Add(edtNovaSenha, 0, wxLEFT, 8);
    sizer_9.Add(grid_sizer_3, 0, 0, 0);
    grid_sizer_10.Add(labSenhaAtual, 0,
                      wxLEFT | wxALIGN_BOTTOM, 4);
    grid_sizer_10.Add(edtSenhaAtual, 0, wxLEFT, 4);
    grid_sizer_10.Add(labConfirmarSenha, 0,
                      wxLEFT | wxALIGN_BOTTOM, 4);
    grid_sizer_10.Add(edtConfirmarSenha, 0, wxLEFT, 4);
    sizer_9.Add(grid_sizer_10, 0, 0, 0);
    sizer_1.Add(sizer_9, 1, 0, 0);
    sizer_2.Add(btnSalvar, 0, wxALL, 2);
    sizer_2.Add(btnLimpar, 0, wxALL, 2);
    sizer_2.Add(btnFechar, 0, wxALL, 2);
    sizer_1.Add(sizer_2, 0, wxALL, 4);
    SetAutoLayout(true);
    SetSizer(sizer_1);
    sizer_1.Fit(this);
    sizer_1.SetSizeHints(this);
  }

  class OnClose
      implements wxCloseListener {
    public void handleEvent(wxCloseEvent event) {
      Destroy();
    }
  }

  class OnBtnSalvarClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      if (ValidaDados()) {
        if (RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
                                                 ConsultasSQL.ConsSQL.Usuario(
            'U', edtLogin.GetValue(),
            edtConfirmarSenha.GetValue()))) {
          wx.wxMessageBox(Resource.STR_SENALTSUC, "Erro",
                          wx.wxOK | wx.wxICON_ERROR);
        }
      }
      event.Skip();
    }
  }

  class OnBtnLimparClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      edtSenhaAtual.Clear();
      edtNovaSenha.Clear();
      edtConfirmarSenha.Clear();
      edtSenhaAtual.SetFocus();
      event.Skip();
    }
  }

  class OnBtnFecharClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      GetParent().Close(true);
      event.Skip();
    }
  }

  public boolean ValidaDados() {
    if (edtSenhaAtual.GetValue() != RotinasGlobais.Rotinas.sUsuarioSenha) {
      wx.wxMessageBox(Resource.STR_SENNCSU, "Erro",
                      wx.wxOK | wx.wxICON_ERROR);
      return false;
    }
    if (RotinasGlobais.Rotinas.ValidaCampo(edtNovaSenha.GetValue(),
                                           Resource.STR_NSENNINF)) {
      return false;
    }
    if (edtNovaSenha.GetValue() != edtConfirmarSenha.GetValue()) {
      wx.wxMessageBox(Resource.STR_NSENNCCON, "Erro",
                      wx.wxOK | wx.wxICON_ERROR);
      return false;
    }
    return true;
  }
}
