#pragma once

namespace Livrus
{
	public __gc class frmLogin : public wx::Dialog
	{
  	public:
      __value enum idt { ID_FRMLOGIN_BMPLOGIN = 200, ID_FRMLOGIN_LABLOGIN, 
      ID_FRMLOGIN_EDTLOGIN, ID_FRMLOGIN_LABSENHA, ID_FRMLOGIN_EDTSENHA, 
      ID_FRMLOGIN_BTNLOGIN, ID_FRMLOGIN_BTNCANCELAR };
  		static frmLogin* fLogin;

      frmLogin( wx::Window* parent );
      System::Void OnClose( System::Object* sender, wx::Event* e );
      System::Void OnBtnLoginClick( System::Object* sender, wx::Event* e );
      System::Void OnBtnCancelarClick( System::Object* sender, wx::Event* e );

    private:
      wx::StaticBitmap *bmpLogin;
      wx::StaticText *labLogin;
      wx::TextCtrl *edtLogin;
      wx::StaticText *labSenha;
      wx::TextCtrl *edtSenha;
      wx::Button *btnLogin;
      wx::Button *btnCancelar;
      Boolean bFechar;

      System::Void FazLayout();
  };
}
