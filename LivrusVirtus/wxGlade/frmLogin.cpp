// -*- C++ -*- generated by wxGlade 0.3.1 on Mon Dec 27 07:02:26 2004

#include "frmLogin.h"


frmLogin::frmLogin(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE)
{
    // begin wxGlade: frmLogin::frmLogin
    bmpLogin = new wxStaticBitmap(this, ID_FRMLOGIN_BMPLOGIN, wxBitmap(wxT("C:\\LivrusVirtus\\VCPP6\\wxWin\\wxODBC\\xpms\\login.xpm"), wxBITMAP_TYPE_ANY));
    labLogin = new wxStaticText(this, ID_FRMLOGIN_LABLOGIN, wxT("Login:"));
    edtLogin = new wxTextCtrl(this, ID_FRMLOGIN_EDTLOGIN, wxT(""));
    labSenha = new wxStaticText(this, ID_FRMLOGIN_LABSENHA, wxT("Senha:"));
    edtSenha = new wxTextCtrl(this, ID_FRMLOGIN_EDTSENHA, wxT(""));
    btnLogin = new wxButton(this, ID_FRMLOGIN_BTNLOGIN, wxT("&Login"));
    btnCancelar = new wxButton(this, ID_FRMLOGIN_BTNCANCELAR, wxT("&Cancelar"));

    set_properties();
    do_layout();
    // end wxGlade
}


void frmLogin::set_properties()
{
    // begin wxGlade: frmLogin::set_properties
    SetTitle(wxT("Login do Sistema"));
    edtLogin->SetSize(wxSize(80, 21));
    edtSenha->SetSize(wxSize(80, 21));
    btnLogin->SetSize(wxSize(75, 25));
    btnLogin->SetDefault();
    btnCancelar->SetSize(wxSize(75, 25));
    // end wxGlade
}


void frmLogin::do_layout()
{
    // begin wxGlade: frmLogin::do_layout
    wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_4 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_3 = new wxBoxSizer(wxVERTICAL);
    sizer_2->Add(bmpLogin, 0, wxALL, 6);
    sizer_3->Add(labLogin, 0, wxALL|wxALIGN_BOTTOM, 2);
    sizer_3->Add(edtLogin, 0, wxALL, 2);
    sizer_3->Add(labSenha, 0, wxALL|wxALIGN_BOTTOM, 2);
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
    Centre();
    // end wxGlade
}

