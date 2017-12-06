#include "resource.h"
#include "AlterarSenha.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

BEGIN_EVENT_TABLE(CfrmAlterarSenha, wxPanel)
    EVT_BUTTON(ID_FRMALTERARSENHA_BTNSALVAR, CfrmAlterarSenha::OnBtnSalvar)
    EVT_BUTTON(ID_FRMALTERARSENHA_BTNLIMPAR, CfrmAlterarSenha::OnBtnLimpar)
    EVT_BUTTON(ID_FRMALTERARSENHA_BTNFECHAR, CfrmAlterarSenha::OnBtnFechar)
    EVT_CLOSE(CfrmAlterarSenha::OnClose)
END_EVENT_TABLE()

CfrmAlterarSenha::CfrmAlterarSenha(wxWindow *parent)
  : wxPanel(parent, -1, wxPoint(0, 0), wxSize(257, 161)) {
	IniciaControles();
}

CfrmAlterarSenha::~CfrmAlterarSenha() { }

void CfrmAlterarSenha::IniciaControles() {

  this->SetClientSize(wxSize(249, 134));
  this->labLogin = new wxStaticText(this, ID_FRMALTERARSENHA_LABLOGIN,
       wxT("Login:"), wxPoint(8, 8), wxSize(29, 13), 0);
  this->edtLogin = new wxTextCtrl(this, ID_FRMALTERARSENHA_EDTLOGIN,
       wxT(""), wxPoint(8, 24), wxSize(100, 21), 0);
  this->edtLogin->Enable(false);
  this->labSenhaAtual = new wxStaticText(this, ID_FRMALTERARSENHA_LABSENHAATUAL,
       wxT("Senha atual:"), wxPoint(112, 8), wxSize(60, 13), 0);
  this->edtSenhaAtual = new wxTextCtrl(this, ID_FRMALTERARSENHA_EDTSENHAATUAL,
       wxT(""), wxPoint(112, 24), wxSize(100, 21), wxTE_PASSWORD);
  this->labNovaSenha = new wxStaticText(this, ID_FRMALTERARSENHA_LABNOVASENHA,
       wxT("Nova senha:"), wxPoint(8, 48), wxSize(61, 13), 0);
  this->edtNovaSenha = new wxTextCtrl(this, ID_FRMALTERARSENHA_EDTNOVASENHA,
       wxT(""), wxPoint(8, 64), wxSize(100, 21), wxTE_PASSWORD);
  this->labConfirmarSenha = new wxStaticText(this, ID_FRMALTERARSENHA_LABCONFIRMARSENHA,
       wxT("Confirmar senha:"), wxPoint(112, 48), wxSize(79, 13), 0);
  this->edtConfirmaSenha = new wxTextCtrl(this, ID_FRMALTERARSENHA_EDTCONFIRMARSENHA,
       wxT(""), wxPoint(112, 64), wxSize(100, 21), wxTE_PASSWORD);
  this->btnSalvar = new wxButton(this, ID_FRMALTERARSENHA_BTNSALVAR,
       wxT("&Salvar"), wxPoint(8, 104), wxSize(75, 23), 0);
  this->btnLimpar = new wxButton(this, ID_FRMALTERARSENHA_BTNLIMPAR,
       wxT("&Limpar"), wxPoint(88, 104), wxSize(75, 23), 0);
  this->btnFechar = new wxButton(this, ID_FRMALTERARSENHA_BTNFECHAR,
       wxT("&Fechar"), wxPoint(168, 104), wxSize(75, 23), 0);   
  
  FazLayout();

  this->edtLogin->SetValue(Rotinas_sUsuarioLogin);
  this->edtSenhaAtual->SetMaxLength(10);
  this->edtNovaSenha->SetMaxLength(10);
  this->edtConfirmaSenha->SetMaxLength(10);  
  this->edtSenhaAtual->SetFocus();
}

void CfrmAlterarSenha::FazLayout()
{
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_9 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_10 = new wxGridSizer(4, 1, 0, 0);
  wxGridSizer* grid_sizer_3 = new wxGridSizer(4, 1, 0, 0);
  grid_sizer_3->Add(labLogin, 0, wxLEFT|wxALIGN_BOTTOM, 8);
  grid_sizer_3->Add(edtLogin, 0, wxLEFT, 8);
  grid_sizer_3->Add(labNovaSenha, 0, wxLEFT|wxALIGN_BOTTOM, 8);
  grid_sizer_3->Add(edtNovaSenha, 0, wxLEFT, 8);
  sizer_9->Add(grid_sizer_3, 0, 0, 0);
  grid_sizer_10->Add(labSenhaAtual, 0, wxLEFT|wxALIGN_BOTTOM, 4);
  grid_sizer_10->Add(edtSenhaAtual, 0, wxLEFT, 4);
  grid_sizer_10->Add(labConfirmarSenha, 0, wxLEFT|wxALIGN_BOTTOM, 4);
  grid_sizer_10->Add(edtConfirmaSenha, 0, wxLEFT, 4);
  sizer_9->Add(grid_sizer_10, 0, 0, 0);
  sizer_1->Add(sizer_9, 1, 0, 0);
  sizer_2->Add(btnSalvar, 0, wxALL, 2);
  sizer_2->Add(btnLimpar, 0, wxALL, 2);
  sizer_2->Add(btnFechar, 0, wxALL, 2);
  sizer_1->Add(sizer_2, 0, wxALL, 4);
  SetAutoLayout(true);
  SetSizer(sizer_1);
  sizer_1->Fit(this);
  sizer_1->SetSizeHints(this);
}

void CfrmAlterarSenha::OnClose(wxCloseEvent& event) {
  this->GetParent()->Destroy();
  event.Skip();
}

void CfrmAlterarSenha::OnBtnSalvar(wxCommandEvent& event) {

  if (ValidaDados()) {
    if (Rotinas->AtualizaDados(wxBanco, ConsSQL->Usuario('U', 
      edtLogin->GetValue(), edtConfirmaSenha->GetValue()))) {              
      wxMessageBox(STR_SENALTSUC, wxT("Erro"), wxOK | wxICON_ERROR);
    }         
  }	

  event.Skip();
}

void CfrmAlterarSenha::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmAlterarSenha::OnBtnLimpar(wxCommandEvent& event) {
  edtSenhaAtual->Clear();
  edtNovaSenha->Clear();
  edtConfirmaSenha->Clear();
  edtSenhaAtual->SetFocus();
  event.Skip();
}

bool CfrmAlterarSenha::ValidaDados()
{
  if (edtSenhaAtual->GetValue().Cmp(Rotinas_sUsuarioSenha.c_str())!=0) {
     wxMessageBox(STR_SENNCSU, wxT("Erro"), wxOK | wxICON_ERROR);
     return FALSE;
  }
  if (Rotinas->ValidaCampo(edtNovaSenha->GetValue(),STR_NSENNINF)) {
  	  return FALSE;
  }
  if (edtNovaSenha->GetValue().Cmp(
              edtConfirmaSenha->GetValue().c_str())!=0) {
   wxMessageBox(STR_NSENNCCON, wxT("Erro"), wxOK | wxICON_ERROR);
   return FALSE;
  } 
 return TRUE;
}
