#include "stdafx.h"
#include "AlterarSenha.h"
#include "Resource.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmAlterarSenha::frmAlterarSenha( wx::Window* parent )
   : wx::Panel(parent, -1, System::Drawing::Point(424, 292), 
    System::Drawing::Size(257, 161), wxTAB_TRAVERSAL,""){

    ClientSize = System::Drawing::Size(249, 134);
    EVT_CLOSE(new wx::EventListener( this, OnClose ));

  	labLogin = new wx::StaticText(this, (int)idt::ID_FRMALTERARSENHA_LABLOGIN, 
      "Login: ", System::Drawing::Point(8, 8), System::Drawing::Size(29, 13) );
  	edtLogin = new wx::TextCtrl(this, (int)idt::ID_FRMALTERARSENHA_EDTLOGIN, "", 
      System::Drawing::Point(8, 24), System::Drawing::Size(100, 21) );
  	edtLogin->Enable(false);
  	labSenhaAtual = new wx::StaticText(this, (int)idt::ID_FRMALTERARSENHA_LABSENHAATUAL, 
      "Senha atual:", System::Drawing::Point(112, 8), System::Drawing::Size(60, 13) );
  	edtSenhaAtual = new wx::TextCtrl(this, (int)idt::ID_FRMALTERARSENHA_EDTSENHAATUAL, 
      "", System::Drawing::Point(112, 24), System::Drawing::Size(100, 21), 
      wx::TextCtrl::wxTE_PASSWORD );
  	labNovaSenha = new wx::StaticText(this, (int)idt::ID_FRMALTERARSENHA_LABNOVASENHA, 
      "Nova Senha:", System::Drawing::Point(8, 48), System::Drawing::Size(61, 13) );
  	edtNovaSenha = new wx::TextCtrl(this, (int)idt::ID_FRMALTERARSENHA_EDTNOVASENHA,
      "", System::Drawing::Point(8, 64), System::Drawing::Size(100, 21), 
      wx::TextCtrl::wxTE_PASSWORD );
  	labConfirmarSenha = new wx::StaticText(this, 
      (int)idt::ID_FRMALTERARSENHA_LABCONFIRMARSENHA, "Confirmar senha:", 
      System::Drawing::Point(112, 48), System::Drawing::Size(79, 13) );
  	edtConfirmarSenha = new wx::TextCtrl(this, 
      (int)idt::ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, "", 
      System::Drawing::Point(112, 64), System::Drawing::Size(100, 21), 
      wx::TextCtrl::wxTE_PASSWORD );
  	btnSalvar = new wx::Button(this, (int)idt::ID_FRMALTERARSENHA_BTNSALVAR, 
      "&Salvar", System::Drawing::Point(8, 104), System::Drawing::Size(75, 25));
  	btnLimpar = new wx::Button(this, (int)idt::ID_FRMALTERARSENHA_BTNLIMPAR, 
      "&Limpar", System::Drawing::Point(88, 104), System::Drawing::Size(75, 25));
  	btnFechar = new wx::Button(this, (int)idt::ID_FRMALTERARSENHA_BTNFECHAR, 
      "&Fechar", System::Drawing::Point(168, 104), System::Drawing::Size(75, 25)); 

    edtLogin->Value = RotinasGlobais::Rotinas->sUsuarioLogin;
    edtSenhaAtual->MaxLength = 10;
    edtNovaSenha->MaxLength = 10;
    edtConfirmarSenha->MaxLength = 10;

    EVT_BUTTON((int)idt::ID_FRMALTERARSENHA_BTNSALVAR, 
      new wx::EventListener( this, OnBtnSalvarClick ));
    EVT_BUTTON((int)idt::ID_FRMALTERARSENHA_BTNLIMPAR, 
      new wx::EventListener( this, OnBtnLimparClick ));
    EVT_BUTTON((int)idt::ID_FRMALTERARSENHA_BTNFECHAR, 
      new wx::EventListener( this, OnBtnFecharClick ));

  	FazLayout();
  	edtSenhaAtual->SetFocus();
  }

  System::Void frmAlterarSenha::FazLayout() {
    wx::BoxSizer *sizer_1 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer *sizer_2 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer *sizer_9 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer *grid_sizer_10 = new wx::GridSizer(4, 1, 0, 0);
    wx::GridSizer *grid_sizer_3 = new wx::GridSizer(4, 1, 0, 0);
    grid_sizer_3->Add(labLogin, 0, 
      wx::Direction::wxLEFT|wx::Alignment::wxALIGN_BOTTOM, 8);
    grid_sizer_3->Add(edtLogin, 0, wx::Direction::wxLEFT, 8);
    grid_sizer_3->Add(labNovaSenha, 0, 
      wx::Direction::wxLEFT|wx::Alignment::wxALIGN_BOTTOM, 8);
    grid_sizer_3->Add(edtNovaSenha, 0, wx::Direction::wxLEFT, 8);
    sizer_9->Add(grid_sizer_3, 0, 0, 0);
    grid_sizer_10->Add(labSenhaAtual, 0, 
      wx::Direction::wxLEFT|wx::Alignment::wxALIGN_BOTTOM, 4);
    grid_sizer_10->Add(edtSenhaAtual, 0, wx::Direction::wxLEFT, 4);
    grid_sizer_10->Add(labConfirmarSenha, 0, 
      wx::Direction::wxLEFT|wx::Alignment::wxALIGN_BOTTOM, 4);
    grid_sizer_10->Add(edtConfirmarSenha, 0, wx::Direction::wxLEFT, 4);
    sizer_9->Add(grid_sizer_10, 0, 0, 0);
    sizer_1->Add(sizer_9, 1, 0, 0);
    sizer_2->Add(btnSalvar, 0, wx::Direction::wxALL, 2);
    sizer_2->Add(btnLimpar, 0, wx::Direction::wxALL, 2);
    sizer_2->Add(btnFechar, 0, wx::Direction::wxALL, 2);
    sizer_1->Add(sizer_2, 0, wx::Direction::wxALL, 4);
    this->AutoLayout = true;
    this->SetSizer(sizer_1);
    sizer_1->Fit(this);
    sizer_1->SetSizeHints(this);
  }

  System::Void frmAlterarSenha::OnClose( System::Object* sender, 
    wx::Event* e ){
    Destroy();
	}

  System::Void frmAlterarSenha::OnBtnSalvarClick( System::Object* sender, 
    wx::Event* e ){
    OleDbCommand* Arquiva = new OleDbCommand();
    if (ValidaDados()) {
      if (RotinasGlobais::Rotinas->AtualizaDados(Arquiva, 
        ConsultasSQL::ConsSQL->Usuario('U', 
        edtLogin->Value, edtConfirmarSenha->Value))) {
        MessageDialog::MessageBox(Resource::STR_SENALTSUC, "Erro", 
          Dialog::wxOK|Dialog::wxICON_ERROR );
      }
    }
    e->Skip();
  }

  System::Void frmAlterarSenha::OnBtnLimparClick( System::Object* sender, 
    wx::Event* e ){
    edtSenhaAtual->Clear();
    edtNovaSenha->Clear();
    edtConfirmarSenha->Clear();
    edtSenhaAtual->SetFocus();
    e->Skip();
  }

  System::Void frmAlterarSenha::OnBtnFecharClick( System::Object* sender, 
    wx::Event* e ){
    this->Parent->Close(true);
    e->Skip();
  }

  Boolean frmAlterarSenha::ValidaDados(){
    if (edtSenhaAtual->Value != RotinasGlobais::Rotinas->sUsuarioSenha) {
      MessageDialog::MessageBox(Resource::STR_SENNCSU, "Erro", 
        Dialog::wxOK|Dialog::wxICON_ERROR );
      return false;
    }
    if (RotinasGlobais::Rotinas->ValidaCampo(edtNovaSenha->Value,
       Resource::STR_NSENNINF)) {
      return false;
    }
    if (edtNovaSenha->Value != edtConfirmarSenha->Value) {
      MessageDialog::MessageBox(Resource::STR_NSENNCCON, "Erro", 
        Dialog::wxOK|Dialog::wxICON_ERROR );
      return false;
    }
    return true;
  }
}
