#ifndef ALTERARSENHA_H
#define ALTERARSENHA_H

class CfrmAlterarSenha: public wxPanel {
public:
  CfrmAlterarSenha(wxWindow *parent);
  ~CfrmAlterarSenha();

protected:
  wxPanel *m_Panel;
  wxStaticText *labLogin;
  wxStaticText *labNovaSenha;
  wxTextCtrl *edtLogin;
  wxTextCtrl *edtSenhaAtual;
  wxStaticText *labConfirmarSenha;
  wxTextCtrl *edtNovaSenha;
  wxStaticText *labSenhaAtual;
  wxTextCtrl *edtConfirmaSenha;
  wxButton *btnSalvar;
  wxButton *btnLimpar;
  wxButton *btnFechar;

  void OnBtnSalvar(wxCommandEvent& event);
  void OnBtnLimpar(wxCommandEvent& event);
  void OnBtnFechar(wxCommandEvent& event);
  void OnClose(wxCloseEvent& event);

private:
	void IniciaControles();
  bool ValidaDados();
  void FazLayout();

  DECLARE_EVENT_TABLE();
};

enum {
 ID_FRMALTERARSENHA_BTNFECHAR = 600, ID_FRMALTERARSENHA_BTNLIMPAR, 
 ID_FRMALTERARSENHA_BTNSALVAR, ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, 
 ID_FRMALTERARSENHA_EDTLOGIN, ID_FRMALTERARSENHA_EDTNOVASENHA, 
 ID_FRMALTERARSENHA_EDTSENHAATUAL, ID_FRMALTERARSENHA_LABCONFIRMARSENHA, 
 ID_FRMALTERARSENHA_LABLOGIN, ID_FRMALTERARSENHA_LABNOVASENHA, 
 ID_FRMALTERARSENHA_LABSENHAATUAL
};

#endif


