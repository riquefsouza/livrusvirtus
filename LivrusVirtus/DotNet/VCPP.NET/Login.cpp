#include "StdAfx.h"
#include "Login.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmLogin::frmLogin()
  {
  	//
  	// Required for Windows Form Designer support
  	//
  	InitializeComponent();
  
  	//
  	// TODO: Add any constructor code after InitializeComponent call
  	//
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmLogin::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmLogin::InitializeComponent()
  {
  	System::Resources::ResourceManager* resources = new System::Resources::ResourceManager(__typeof(frmLogin));
  	this->edtLogin = new System::Windows::Forms::TextBox();
  	this->label1 = new System::Windows::Forms::Label();
  	this->label2 = new System::Windows::Forms::Label();
  	this->label3 = new System::Windows::Forms::Label();
  	this->edtSenha = new System::Windows::Forms::TextBox();
  	this->btnLogin = new System::Windows::Forms::Button();
  	this->btnCancelar = new System::Windows::Forms::Button();
  	this->Consulta = new System::Data::OleDb::OleDbCommand();
  	this->SuspendLayout();
  	// 
  	// edtLogin
  	// 
  	this->edtLogin->Location = System::Drawing::Point(112, 32);
  	this->edtLogin->MaxLength = 10;
  	this->edtLogin->Name = S"edtLogin";
  	this->edtLogin->Size = System::Drawing::Size(80, 20);
  	this->edtLogin->TabIndex = 2;
  	this->edtLogin->Text = S"";
  	// 
  	// label1
  	// 
  	this->label1->BackColor = System::Drawing::Color::Transparent;
  	this->label1->Image = dynamic_cast<System::Drawing::Image*>(resources->GetObject(S"label1.Image"));
  	this->label1->Location = System::Drawing::Point(8, 8);
  	this->label1->Name = S"label1";
  	this->label1->Size = System::Drawing::Size(96, 96);
  	this->label1->TabIndex = 0;
  	// 
  	// label2
  	// 
  	this->label2->Location = System::Drawing::Point(112, 16);
  	this->label2->Name = S"label2";
  	this->label2->Size = System::Drawing::Size(64, 16);
  	this->label2->TabIndex = 1;
  	this->label2->Text = S"Login:";
  	// 
  	// label3
  	// 
  	this->label3->Location = System::Drawing::Point(112, 64);
  	this->label3->Name = S"label3";
  	this->label3->Size = System::Drawing::Size(64, 16);
  	this->label3->TabIndex = 3;
  	this->label3->Text = S"Senha:";
  	// 
  	// edtSenha
  	// 
  	this->edtSenha->Location = System::Drawing::Point(112, 80);
  	this->edtSenha->MaxLength = 10;
  	this->edtSenha->Name = S"edtSenha";
  	this->edtSenha->PasswordChar = '*';
  	this->edtSenha->Size = System::Drawing::Size(80, 20);
  	this->edtSenha->TabIndex = 4;
  	this->edtSenha->Text = S"";
  	// 
  	// btnLogin
  	// 
  	this->btnLogin->Location = System::Drawing::Point(24, 112);
  	this->btnLogin->Name = S"btnLogin";
  	this->btnLogin->TabIndex = 5;
  	this->btnLogin->Text = S"&Login";
  	this->btnLogin->Click += new System::EventHandler(this,btnLogin_Click);
  	// 
  	// btnCancelar
  	// 
  	this->btnCancelar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
  	this->btnCancelar->Location = System::Drawing::Point(104, 112);
  	this->btnCancelar->Name = S"btnCancelar";
  	this->btnCancelar->TabIndex = 6;
  	this->btnCancelar->Text = S"&Cancelar";
  	this->btnCancelar->Click += new System::EventHandler(this,btnCancelar_Click);
  	// 
  	// frmLogin
  	// 
  	this->AcceptButton = this->btnLogin;
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->CancelButton = this->btnCancelar;
  	this->ClientSize = System::Drawing::Size(202, 143);
  	this->Controls->Add(this->btnCancelar);
  	this->Controls->Add(this->btnLogin);
  	this->Controls->Add(this->label3);
  	this->Controls->Add(this->edtSenha);
  	this->Controls->Add(this->edtLogin);
  	this->Controls->Add(this->label2);
  	this->Controls->Add(this->label1);
  	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
  	this->MaximizeBox = false;
  	this->MinimizeBox = false;
  	this->Name = S"frmLogin";
  	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
  	this->Text = S"Login do sistema";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmLogin_Closing);
  	this->Load += new System::EventHandler(this,frmLogin_Load);
  	this->ResumeLayout(false);
  }
  
  Void frmLogin::frmLogin_Load(Object* sender, System::EventArgs* e)
  {
  	bFecharOuTerminar=false;
  }
  
  Void frmLogin::frmLogin_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	if (bFecharOuTerminar)
  	  e->Cancel=false;
  	else
  	  Application::Exit();
  
  }
  
  Void frmLogin::btnLogin_Click(Object* sender, System::EventArgs* e)
  {
  	if (RotinasGlobais::Rotinas->ConsultaDados(Consulta,
  	 ConsultasSQL::ConsSQL->Usuario('S',edtLogin->Text,edtSenha->Text))) {
  	 RotinasGlobais::Rotinas->sUsuarioLogin=edtLogin->Text;
  	 RotinasGlobais::Rotinas->sUsuarioSenha=edtSenha->Text;
  	 frmPrincipal::fPrincipal->statusBar1->Panels->Item[0]->Text=String::Concat(
  		S"Usuário: ",edtLogin->Text);
  	 bFecharOuTerminar=true;
  	 Close();
  	} else
  	  MessageBox::Show(S"Login ou senha incorretos!",
  	  frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  	  MessageBoxIcon::Information);
  
  }
  
  Void frmLogin::btnCancelar_Click(Object* sender, System::EventArgs* e)
  {
  	bFecharOuTerminar=false;
  	Close();
  }

}
