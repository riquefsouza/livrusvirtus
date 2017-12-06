#ifndef LOGIN_H
#define LOGIN_H

class CfrmLogin: public wxDialog {
public:
  CfrmLogin(wxWindow *parent);
  ~CfrmLogin();

protected:
  wxStaticBitmap *bmpLogin;
  wxStaticText *labLogin;
  wxTextCtrl *edtLogin;
  wxStaticText *labSenha;
  wxTextCtrl *edtSenha;
  wxButton *btnLogin;
  wxButton *btnCancelar;

  void OnBtnLogin(wxCommandEvent& event);
  void OnBtnCancelar(wxCommandEvent& event);
  void OnClose(wxCloseEvent& event);

private:
	bool bFechar;
  void IniciaControles();
  void FazLayout();

  DECLARE_EVENT_TABLE();
};

enum {
  ID_FRMLOGIN_BMPLOGIN = 200, ID_FRMLOGIN_BTNCANCELAR, ID_FRMLOGIN_BTNLOGIN, 
  ID_FRMLOGIN_EDTLOGIN, ID_FRMLOGIN_EDTSENHA, ID_FRMLOGIN_LABLOGIN, 
  ID_FRMLOGIN_LABSENHA
};

extern CfrmLogin *frmLogin;

#endif


