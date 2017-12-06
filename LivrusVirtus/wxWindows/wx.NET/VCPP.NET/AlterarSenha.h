#pragma once

namespace Livrus
{
	public __gc class frmAlterarSenha : public wx::Panel
	{
  	public:
      __value enum idt { 
      ID_FRMALTERARSENHA_BTNFECHAR = 600, ID_FRMALTERARSENHA_BTNLIMPAR, 
      ID_FRMALTERARSENHA_BTNSALVAR, ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, 
      ID_FRMALTERARSENHA_EDTLOGIN, ID_FRMALTERARSENHA_EDTNOVASENHA, 
      ID_FRMALTERARSENHA_EDTSENHAATUAL, ID_FRMALTERARSENHA_LABCONFIRMARSENHA, 
      ID_FRMALTERARSENHA_LABLOGIN, ID_FRMALTERARSENHA_LABNOVASENHA, 
      ID_FRMALTERARSENHA_LABSENHAATUAL };
  		static frmAlterarSenha* fAlterarSenha;
      frmAlterarSenha( wx::Window* parent );
      System::Void OnClose( System::Object* sender, wx::Event* e );
      System::Void OnBtnSalvarClick( System::Object* sender, wx::Event* e );
      System::Void OnBtnLimparClick( System::Object* sender, wx::Event* e );
      System::Void OnBtnFecharClick( System::Object* sender, wx::Event* e );

    private:
      wx::StaticText *labLogin;
      wx::TextCtrl *edtLogin;
      wx::StaticText *labSenhaAtual;
      wx::TextCtrl *edtSenhaAtual;
      wx::StaticText *labNovaSenha;
      wx::TextCtrl *edtNovaSenha;
      wx::StaticText *labConfirmarSenha;
      wx::TextCtrl *edtConfirmarSenha;
      wx::Button *btnSalvar;
      wx::Button *btnLimpar;
      wx::Button *btnFechar;
      System::Void FazLayout();
      Boolean ValidaDados();
  };
}
