#include "stdafx.h"
#include "Login.h"
#include "Principal.h"
#include "Resource.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmLogin::frmLogin( wx::Window* parent )
   : wx::Dialog(parent, -1, "Login do Sistema", 
     System::Drawing::Point(546, 346), 
     System::Drawing::Size(211, 168), wxDEFAULT_DIALOG_STYLE,"") {

    bmpLogin = new wx::StaticBitmap(this, (int)idt::ID_FRMLOGIN_BMPLOGIN, 
      new wx::Bitmap("xpms/login.xpm", wx::BitmapType::wxBITMAP_TYPE_XPM),
      System::Drawing::Point(8, 8), System::Drawing::Size(90, 90));
  	labLogin = new wx::StaticText(this, (int)idt::ID_FRMLOGIN_LABLOGIN, 
      "Login:", System::Drawing::Point(112, 8), System::Drawing::Size(29, 13) );
  	edtLogin = new wx::TextCtrl(this, (int)idt::ID_FRMLOGIN_EDTLOGIN, "", 
      System::Drawing::Point(112, 24), System::Drawing::Size(80, 21) );
    edtLogin->MaxLength = 10;
  	labSenha = new wx::StaticText(this, (int)idt::ID_FRMLOGIN_LABSENHA, 
      "Senha:", System::Drawing::Point(112, 56), System::Drawing::Size(34, 13) );
  	edtSenha = new wx::TextCtrl(this, (int)idt::ID_FRMLOGIN_EDTSENHA, "", 
      System::Drawing::Point(112, 72), System::Drawing::Size(80, 21), wx::TextCtrl::wxTE_PASSWORD );
    edtSenha->MaxLength = 10;
  	btnLogin = new wx::Button(this, (int)idt::ID_FRMLOGIN_BTNLOGIN, "&Login",
      System::Drawing::Point(24, 107), System::Drawing::Size(75, 25));
  	btnCancelar = new wx::Button(this, (int)idt::ID_FRMLOGIN_BTNCANCELAR, "&Cancelar",
      System::Drawing::Point(112, 107), System::Drawing::Size(75, 25));
  	btnLogin->SetDefault();

    bFechar = false;
    FazLayout();

		EVT_CLOSE( new wx::EventListener( this, OnClose ) );
    EVT_BUTTON((int)idt::ID_FRMLOGIN_BTNLOGIN, 
      new wx::EventListener( this, OnBtnLoginClick ) );
    EVT_BUTTON((int)idt::ID_FRMLOGIN_BTNCANCELAR, 
      new wx::EventListener( this, OnBtnCancelarClick ) );

  }

  System::Void frmLogin::FazLayout() {
  	wx::BoxSizer *sizer_1 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
  	wx::BoxSizer *sizer_4 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
  	wx::BoxSizer *sizer_2 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
  	wx::BoxSizer *sizer_3 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
  	sizer_2->Add(bmpLogin, 0, wx::Direction::wxALL, 6);
  	sizer_3->Add(labLogin, 0, wx::Direction::wxALL|wx::Alignment::wxALIGN_BOTTOM, 2);
  	sizer_3->Add(edtLogin, 0, wx::Direction::wxALL, 2);
  	sizer_3->Add(labSenha, 0, wx::Direction::wxALL|wx::Alignment::wxALIGN_BOTTOM, 2);
  	sizer_3->Add(edtSenha, 0, wx::Direction::wxALL, 2);
  	sizer_2->Add(sizer_3, 0, wx::Direction::wxALL, 6);
  	sizer_1->Add(sizer_2, 0, 0, 3);
  	sizer_4->Add(btnLogin, 0, wx::Direction::wxLEFT|wx::Direction::wxTOP|
      wx::Direction::wxBOTTOM|wx::Alignment::wxALIGN_BOTTOM, 10);
  	sizer_4->Add(btnCancelar, 0, wx::Direction::wxALL|wx::Alignment::wxALIGN_BOTTOM, 10);
  	sizer_1->Add(sizer_4, 0, 
      wx::Direction::wxALL|wx::Alignment::wxALIGN_CENTER_HORIZONTAL, 1);
  	this->SetSizer(sizer_1);
  	sizer_1->Fit(this);
  	sizer_1->SetSizeHints(this);
  	this->Layout();
  	this->Centre();
  }

  System::Void frmLogin::OnClose( System::Object* sender, wx::Event* e ){
    if (bFechar)
      Destroy();
    else {
      Destroy();
      frmPrincipal::fPrincipal->Destroy();
    }
  }

	System::Void frmLogin::OnBtnLoginClick( System::Object* sender, 
    wx::Event* e ){
    OleDbCommand* Consulta = new OleDbCommand();
    RotinasGlobais::Rotinas->sUsuarioLogin = edtLogin->Value;
    RotinasGlobais::Rotinas->sUsuarioSenha = edtSenha->Value;

    if (RotinasGlobais::Rotinas->ConsultaDados(Consulta, 
       ConsultasSQL::ConsSQL->Usuario('S',
       RotinasGlobais::Rotinas->sUsuarioLogin, 
       RotinasGlobais::Rotinas->sUsuarioSenha))) {
      RotinasGlobais::Rotinas->sBarraLogin = String::Concat(Resource::STR_USUARIO, 
      RotinasGlobais::Rotinas->sUsuarioLogin);
      frmPrincipal::fPrincipal->SetStatusText(
        RotinasGlobais::Rotinas->sBarraLogin, 0);

      bFechar = true;
      this->Close(true);
			frmPrincipal::fPrincipal->Show( true );
    } else
      MessageDialog::MessageBox(Resource::STR_LOGSENINC, "Erro", 
        Dialog::wxOK|Dialog::wxICON_ERROR );

    e->Skip();
  }

	System::Void frmLogin::OnBtnCancelarClick( System::Object* sender, 
    wx::Event* e ){
    bFechar = false;
    this->Close(true);
    e->Skip();
  }
}
