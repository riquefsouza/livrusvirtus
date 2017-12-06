#include "StdAfx.h"
#include "AlterarSenha.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{

  frmAlterarSenha::frmAlterarSenha()
  {
  	InitializeComponent();
  }
  
  System::Void frmAlterarSenha::Dispose(System::Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);
  }
  
  System::Void frmAlterarSenha::InitializeComponent()
  {
  	this->btnSalvar = new System::Windows::Forms::Button();
  	this->btnLimpar = new System::Windows::Forms::Button();
  	this->btnFechar = new System::Windows::Forms::Button();
  	this->label3 = new System::Windows::Forms::Label();
  	this->edtNovaSenha = new System::Windows::Forms::TextBox();
  	this->edtLogin = new System::Windows::Forms::TextBox();
  	this->label2 = new System::Windows::Forms::Label();
  	this->label1 = new System::Windows::Forms::Label();
  	this->edtConfirmarSenha = new System::Windows::Forms::TextBox();
  	this->edtSenhaAtual = new System::Windows::Forms::TextBox();
  	this->label4 = new System::Windows::Forms::Label();
  	this->Arquiva = new System::Data::OleDb::OleDbCommand();
  	this->SuspendLayout();
  	// 
  	// btnSalvar
  	// 
  	this->btnSalvar->Location = System::Drawing::Point(8, 104);
  	this->btnSalvar->Name = S"btnSalvar";
  	this->btnSalvar->TabIndex = 8;
  	this->btnSalvar->Text = S"&Salvar";
  	this->btnSalvar->Click += new System::EventHandler(this,btnSalvar_Click);
  	// 
  	// btnLimpar
  	// 
  	this->btnLimpar->Location = System::Drawing::Point(88, 104);
  	this->btnLimpar->Name = S"btnLimpar";
  	this->btnLimpar->TabIndex = 9;
  	this->btnLimpar->Text = S"&Limpar";
  	this->btnLimpar->Click += new System::EventHandler(this,btnLimpar_Click);
  	// 
  	// btnFechar
  	// 
  	this->btnFechar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
  	this->btnFechar->Location = System::Drawing::Point(168, 104);
  	this->btnFechar->Name = S"btnFechar";
  	this->btnFechar->TabIndex = 10;
  	this->btnFechar->Text = S"&Fechar";
  	this->btnFechar->Click += new System::EventHandler(this,btnFechar_Click);
  	// 
  	// label3
  	// 
  	this->label3->Location = System::Drawing::Point(16, 56);
  	this->label3->Name = S"label3";
  	this->label3->Size = System::Drawing::Size(80, 16);
  	this->label3->TabIndex = 4;
  	this->label3->Text = S"Nova senha:";
  	// 
  	// edtNovaSenha
  	// 
  	this->edtNovaSenha->Location = System::Drawing::Point(16, 72);
  	this->edtNovaSenha->MaxLength = 10;
  	this->edtNovaSenha->Name = S"edtNovaSenha";
  	this->edtNovaSenha->PasswordChar = '*';
  	this->edtNovaSenha->Size = System::Drawing::Size(96, 20);
  	this->edtNovaSenha->TabIndex = 5;
  	this->edtNovaSenha->Text = S"";
  	// 
  	// edtLogin
  	// 
  	this->edtLogin->Enabled = false;
  	this->edtLogin->Location = System::Drawing::Point(16, 24);
  	this->edtLogin->MaxLength = 10;
  	this->edtLogin->Name = S"edtLogin";
  	this->edtLogin->Size = System::Drawing::Size(96, 20);
  	this->edtLogin->TabIndex = 1;
  	this->edtLogin->Text = S"";
  	// 
  	// label2
  	// 
  	this->label2->Location = System::Drawing::Point(16, 8);
  	this->label2->Name = S"label2";
  	this->label2->Size = System::Drawing::Size(64, 16);
  	this->label2->TabIndex = 0;
  	this->label2->Text = S"Login:";
  	// 
  	// label1
  	// 
  	this->label1->Location = System::Drawing::Point(128, 56);
  	this->label1->Name = S"label1";
  	this->label1->Size = System::Drawing::Size(96, 16);
  	this->label1->TabIndex = 6;
  	this->label1->Text = S"Confirmar senha:";
  	// 
  	// edtConfirmarSenha
  	// 
  	this->edtConfirmarSenha->Location = System::Drawing::Point(128, 72);
  	this->edtConfirmarSenha->MaxLength = 10;
  	this->edtConfirmarSenha->Name = S"edtConfirmarSenha";
  	this->edtConfirmarSenha->PasswordChar = '*';
  	this->edtConfirmarSenha->Size = System::Drawing::Size(96, 20);
  	this->edtConfirmarSenha->TabIndex = 7;
  	this->edtConfirmarSenha->Text = S"";
  	// 
  	// edtSenhaAtual
  	// 
  	this->edtSenhaAtual->Location = System::Drawing::Point(128, 24);
  	this->edtSenhaAtual->MaxLength = 10;
  	this->edtSenhaAtual->Name = S"edtSenhaAtual";
  	this->edtSenhaAtual->PasswordChar = '*';
  	this->edtSenhaAtual->Size = System::Drawing::Size(96, 20);
  	this->edtSenhaAtual->TabIndex = 3;
  	this->edtSenhaAtual->Text = S"";
  	// 
  	// label4
  	// 
  	this->label4->Location = System::Drawing::Point(128, 8);
  	this->label4->Name = S"label4";
  	this->label4->Size = System::Drawing::Size(80, 16);
  	this->label4->TabIndex = 2;
  	this->label4->Text = S"Senha atual:";
  	// 
  	// frmAlterarSenha
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->ClientSize = System::Drawing::Size(248, 133);
  	this->Controls->Add(this->label1);
  	this->Controls->Add(this->edtConfirmarSenha);
  	this->Controls->Add(this->edtSenhaAtual);
  	this->Controls->Add(this->label4);
  	this->Controls->Add(this->label3);
  	this->Controls->Add(this->edtNovaSenha);
  	this->Controls->Add(this->edtLogin);
  	this->Controls->Add(this->label2);
  	this->Controls->Add(this->btnSalvar);
  	this->Controls->Add(this->btnLimpar);
  	this->Controls->Add(this->btnFechar);
  	this->Name = S"frmAlterarSenha";
  	this->Text = S"Alteração de Senha";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmAlterarSenha_Closing);
  	this->Load += new System::EventHandler(this,frmAlterarSenha_Load);
  	this->MouseMove += new System::Windows::Forms::MouseEventHandler(this,frmAlterarSenha_MouseMove);
  	this->ResumeLayout(false);
  }
  
  System::Void frmAlterarSenha::frmAlterarSenha_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	frmPrincipal::fPrincipal->mnuAlterarSenha->Enabled=true;
  	frmPrincipal::fPrincipal->statusBar1->Panels->Item[1]->Text=S"";
  }
  
  System::Void frmAlterarSenha::btnFechar_Click(Object* sender, System::EventArgs* e)
  {
  	Close();
  }
  
  System::Void frmAlterarSenha::btnLimpar_Click(Object* sender, System::EventArgs* e)
  {
  	edtNovaSenha->Text=S"";
  	edtConfirmarSenha->Text=S"";
  	edtSenhaAtual->Focus();
  }
  
  System::Boolean frmAlterarSenha::ValidaDados()
  {
    if (edtSenhaAtual->Text->Trim()->Equals(
  	 RotinasGlobais::Rotinas->sUsuarioSenha->Trim())==false) {
  	MessageBox::Show(this,S"A Senha atual não confere com a senha do usuário!",
  	frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  	MessageBoxIcon::Error);
  	return false;
    }
    if (RotinasGlobais::Rotinas->ValidaCampo(edtNovaSenha->Text,
  		S"Nova senha não informada!")) {
  	return false;
    }
    if (edtNovaSenha->Text->Trim()->Equals(edtConfirmarSenha->Text->Trim())==false) {
  	MessageBox::Show(this,S"A Nova senha não confere com a senha a confirmar!",
  	frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  	MessageBoxIcon::Error);
  	return false;
    }
  
    return true;
  }
  
  System::Void frmAlterarSenha::btnSalvar_Click(Object* sender, System::EventArgs* e)
  {
  	if (ValidaDados()) {
  	  Arquiva = frmPrincipal::fPrincipal->db->CreateCommand();
  
  	  Arquiva->CommandText=ConsultasSQL::ConsSQL->Usuario('U',
  	  RotinasGlobais::Rotinas->sUsuarioLogin, edtConfirmarSenha->Text);
  	  Arquiva->ExecuteNonQuery();
  	  Arquiva->Dispose();
  	  RotinasGlobais::Rotinas->sUsuarioSenha=edtNovaSenha->Text;
  	  MessageBox::Show(this,S"Senha alterada com sucesso!",
  	  frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  	  MessageBoxIcon::Information);
  	}
  }
  
  System::Void frmAlterarSenha::frmAlterarSenha_Load(Object* sender, System::EventArgs* e)
  {
  	edtLogin->Text=RotinasGlobais::Rotinas->sUsuarioLogin;
  }
  
  System::Void frmAlterarSenha::frmAlterarSenha_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e)
  {
  	frmPrincipal::fPrincipal->statusBar1->Panels->Item[1]->Text=Text;
  }

}
