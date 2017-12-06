package Livrus;

import org.wxwindows.*;
import java.sql.Statement;

public class frmLogin
    extends wxDialog {
  public static frmLogin fLogin = null;

  private static int ID_FRMLOGIN_BMPLOGIN = 200;
  private static int ID_FRMLOGIN_LABLOGIN = 201;
  private static int ID_FRMLOGIN_EDTLOGIN = 202;
  private static int ID_FRMLOGIN_LABSENHA = 203;
  private static int ID_FRMLOGIN_EDTSENHA = 204;
  private static int ID_FRMLOGIN_BTNLOGIN = 205;
  private static int ID_FRMLOGIN_BTNCANCELAR = 206;

  private wxStaticBitmap bmpLogin;
  private wxStaticText labLogin;
  private wxTextCtrl edtLogin;
  private wxStaticText labSenha;
  private wxTextCtrl edtSenha;
  private wxButton btnLogin;
  private wxButton btnCancelar;
  private boolean bFechar;
  private Statement Consulta;

  public frmLogin(wxWindow parent) {
    super(parent, -1, "Login do Sistema");

    bmpLogin = new wxStaticBitmap(this, ID_FRMLOGIN_BMPLOGIN,
                                  new wxBitmap(Resource.XPM_LOGIN,
                                               wxBITMAP_TYPE_XPM),
                                  new wxPoint(8, 8), new wxSize(90, 90), 0);
    labLogin = new wxStaticText(this, ID_FRMLOGIN_LABLOGIN,
                                "Login:", new wxPoint(112, 8),
                                new wxSize(29, 13));
    edtLogin = new wxTextCtrl(this, ID_FRMLOGIN_EDTLOGIN, "",
                              new wxPoint(112, 24), new wxSize(80, 21));
    edtLogin.SetValidator(new TextValidator(edtLogin,TextValidator.FILTER_NONE,10));
    labSenha = new wxStaticText(this, ID_FRMLOGIN_LABSENHA,
                                "Senha:", new wxPoint(112, 56),
                                new wxSize(34, 13));
    edtSenha = new wxTextCtrl(this, ID_FRMLOGIN_EDTSENHA, "",
                              new wxPoint(112, 72), new wxSize(80, 21),
                              wxTextCtrl.wxTE_PASSWORD);
    edtSenha.SetValidator(new TextValidator(edtSenha,TextValidator.FILTER_NONE,10));
    btnLogin = new wxButton(this, ID_FRMLOGIN_BTNLOGIN, "&Login",
                            new wxPoint(24, 107), new wxSize(75, 25));
    btnCancelar = new wxButton(this, ID_FRMLOGIN_BTNCANCELAR, "&Cancelar",
                               new wxPoint(112, 107), new wxSize(75, 25));
    btnLogin.SetDefault();

    bFechar = false;
    FazLayout();

    EVT_CLOSE(new OnClose());
    EVT_BUTTON(ID_FRMLOGIN_BTNLOGIN, new OnBtnLoginClick());
    EVT_BUTTON(ID_FRMLOGIN_BTNCANCELAR, new OnBtnCancelarClick());
  }

  private void FazLayout() {
    wxBoxSizer sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_4 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_3 = new wxBoxSizer(wxVERTICAL);
    sizer_2.Add(bmpLogin, 0, wxALL, 6);
    sizer_3.Add(labLogin, 0, wxALL | wxALIGN_BOTTOM, 2);
    sizer_3.Add(edtLogin, 0, wxALL, 2);
    sizer_3.Add(labSenha, 0, wxALL | wxALIGN_BOTTOM, 2);
    sizer_3.Add(edtSenha, 0, wxALL, 2);
    sizer_2.Add(sizer_3, 0, wxALL, 6);
    sizer_1.Add(sizer_2, 0, 0, 3);
    sizer_4.Add(btnLogin, 0, wxLEFT | wxTOP |
                wxBOTTOM | wxALIGN_BOTTOM, 10);
    sizer_4.Add(btnCancelar, 0, wxALL | wxALIGN_BOTTOM,
                10);
    sizer_1.Add(sizer_4, 0,
                wxALL | wxALIGN_CENTER_HORIZONTAL, 1);
    this.SetSizer(sizer_1);
    sizer_1.Fit(this);
    sizer_1.SetSizeHints(this);
    this.Layout();
    this.Centre();
  }

  class OnClose
      implements wxCloseListener {
    public void handleEvent(wxCloseEvent event) {
      if (bFechar) {
        Destroy();
      }
      else {
        Destroy();
        frmPrincipal.fPrincipal.Destroy();
      }
    }
  }

  class OnBtnLoginClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      RotinasGlobais.Rotinas.sUsuarioLogin = edtLogin.GetValue();
      RotinasGlobais.Rotinas.sUsuarioSenha = edtSenha.GetValue();

      if (RotinasGlobais.Rotinas.ConsultaDados(Consulta,
                                               ConsultasSQL.ConsSQL.Usuario('S',
          RotinasGlobais.Rotinas.sUsuarioLogin,
          RotinasGlobais.Rotinas.sUsuarioSenha))) {
        RotinasGlobais.Rotinas.sBarraLogin = Resource.STR_USUARIO +
            RotinasGlobais.Rotinas.sUsuarioLogin;
        frmPrincipal.fPrincipal.SetStatusText(
            RotinasGlobais.Rotinas.sBarraLogin, 1);

        bFechar = true;
        Close(true);
        frmPrincipal.fPrincipal.Show(true);
      }
      else {
        wx.wxMessageBox(Resource.STR_LOGSENINC, "Erro",
                        wx.wxOK | wx.wxICON_INFORMATION);
      }
      event.Skip();
    }
  }

  class OnBtnCancelarClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      bFechar = false;
      Close(true);
      event.Skip();
    }
  }
}
