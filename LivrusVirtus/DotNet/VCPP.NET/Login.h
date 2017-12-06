#pragma once

namespace Livrus
{
  public __gc class frmLogin : public System::Windows::Forms::Form
  {
  public:
	static frmLogin* fLogin;
  private:
	Boolean bFecharOuTerminar;
  	System::ComponentModel::IContainer* components;
  	System::Windows::Forms::TextBox* edtLogin;
  	System::Windows::Forms::Label* label1;
  	System::Windows::Forms::Label* label2;
  	System::Windows::Forms::Label* label3;
  	System::Windows::Forms::TextBox* edtSenha;
  	System::Windows::Forms::Button* btnLogin;
  	System::Windows::Forms::Button* btnCancelar;
  	System::Data::OleDb::OleDbCommand* Consulta;
  
  public: 
	frmLogin(void);
  protected: 
	Void Dispose (Boolean disposing);
  private: 
	Void InitializeComponent();
  	Void frmLogin_Load(Object* sender, System::EventArgs* e);
  	Void frmLogin_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
  	Void btnLogin_Click(Object* sender, System::EventArgs* e);
  	Void btnCancelar_Click(Object* sender, System::EventArgs* e);
  };
}
