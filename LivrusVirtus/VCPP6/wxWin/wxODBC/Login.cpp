#include "resource.h"
#include "Login.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

#ifndef __WXMOTIF__
  #include "xpms/livrus.xpm"
#endif  
#include "xpms/login.xpm"

CfrmLogin *frmLogin = (CfrmLogin *) NULL;

BEGIN_EVENT_TABLE(CfrmLogin, wxDialog)
  EVT_BUTTON(ID_FRMLOGIN_BTNLOGIN, CfrmLogin::OnBtnLogin)
  EVT_BUTTON(ID_FRMLOGIN_BTNCANCELAR, CfrmLogin::OnBtnCancelar)
	EVT_CLOSE(CfrmLogin::OnClose)
END_EVENT_TABLE()

CfrmLogin::CfrmLogin(wxWindow *parent) 
	: wxDialog(parent, -1, wxT("Login do Sistema"), 
    wxPoint(546, 346), wxSize(211, 148),
	  wxDEFAULT_DIALOG_STYLE, wxT("frmLogin"))
{
	IniciaControles();
}

CfrmLogin::~CfrmLogin() { }

void CfrmLogin::IniciaControles() {

#ifdef __WXMSW__
  this->SetIcon(wxIcon(ICO_LIVRUS));
  this->SetBackgroundColour(wxColour(212,208,200));
#else
  #ifndef __WXMOTIF__
    this->SetIcon(wxIcon( Livrus_xpm ));
  #endif
#endif

  this->SetClientSize(wxSize(211, 138));
  this->Centre(wxBOTH);   

  this->bmpLogin = new wxStaticBitmap(this, ID_FRMLOGIN_BMPLOGIN, 
    //wxBitmap(BMP_LOGIN, wxBITMAP_TYPE_BMP), 
    wxBitmap(login_xpm),
    wxPoint(8, 8), wxSize(88, 90), 0);
  this->labLogin = new wxStaticText(this, ID_FRMLOGIN_LABLOGIN, 
    wxT("Login:"), wxPoint(112, 8), wxSize(29, 13), 0);
  this->edtLogin = new wxTextCtrl(this, ID_FRMLOGIN_EDTLOGIN, 
    wxT(""), wxPoint(112, 24), wxSize(80, 21), 0);  
  this->labSenha = new wxStaticText(this, ID_FRMLOGIN_LABSENHA, 
    wxT("Senha:"), wxPoint(112, 56), wxSize(34, 13), 0);
  this->edtSenha = new wxTextCtrl(this, ID_FRMLOGIN_EDTSENHA, 
    wxT(""), wxPoint(112, 72), wxSize(80, 21), wxTE_PASSWORD);
  this->btnLogin = new wxButton(this, ID_FRMLOGIN_BTNLOGIN, wxT("&Login"),
    wxPoint(24, 107), wxSize(75, 25), 0);
  this->btnCancelar = new wxButton(this, ID_FRMLOGIN_BTNCANCELAR,
    wxT("&Cancelar"), wxPoint(112, 107), wxSize(75, 25), 0);

  FazLayout();

  this->edtLogin->SetMaxLength(10);
  this->edtSenha->SetMaxLength(10);  
}

void CfrmLogin::FazLayout()
{
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_4 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_3 = new wxBoxSizer(wxVERTICAL);
  sizer_2->Add(bmpLogin, 0, wxALL, 6);
  sizer_3->Add(labLogin, 0, wxALL, 2);
  sizer_3->Add(edtLogin, 0, wxALL, 2);
  sizer_3->Add(labSenha, 0, wxALL, 2);
  sizer_3->Add(edtSenha, 0, wxALL, 2);
  sizer_2->Add(sizer_3, 0, wxALL, 6);
  sizer_1->Add(sizer_2, 0, 0, 3);
  sizer_4->Add(btnLogin, 0, wxLEFT|wxTOP|wxBOTTOM|wxALIGN_BOTTOM, 10);
  sizer_4->Add(btnCancelar, 0, wxALL|wxALIGN_BOTTOM, 10);
  sizer_1->Add(sizer_4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 1);
  SetAutoLayout(true);
  SetSizer(sizer_1);
  sizer_1->Fit(this);
  sizer_1->SetSizeHints(this);
  Layout();
}

void CfrmLogin::OnBtnLogin(wxCommandEvent& event) {
  
  Rotinas_sUsuarioLogin = edtLogin->GetValue();
  Rotinas_sUsuarioSenha = edtSenha->GetValue();

  if (Rotinas->ConsultaDados(gConexao, 
     ConsSQL->Usuario('S',Rotinas_sUsuarioLogin, Rotinas_sUsuarioSenha)) ) {
                
     Rotinas_sBarraLogin = 
       wxString::Format("%s%s", STR_USUARIO, Rotinas_sUsuarioLogin.c_str());     

     frmPrincipal->SetStatusText(Rotinas_sBarraLogin, 0);

     bFechar=false;
     Close();	
     frmPrincipal->Show();
     
  } else
     wxMessageBox(wxT(STR_LOGSENINC), wxT("Erro"), wxOK | wxICON_ERROR);
  
	event.Skip();    
}

void CfrmLogin::OnBtnCancelar(wxCommandEvent& event) {
	bFechar=true;
	Close();
  event.Skip();
}

void CfrmLogin::OnClose(wxCloseEvent& event) {
  if (bFechar)
	  frmPrincipal->Destroy();
  this->Destroy();
  event.Skip();
}
