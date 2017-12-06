#pragma once

namespace Livrus
{
	/// <summary>
	/// Summary description for WinForm.
	/// </summary>
	public __gc class frmAlterarSenha : public System::Windows::Forms::Form
	{
	public:
		static frmAlterarSenha* fAlterarSenha;
	private:
		System::ComponentModel::IContainer* components;
		System::Windows::Forms::Button* btnSalvar;
		System::Windows::Forms::Button* btnLimpar;
		System::Windows::Forms::Button* btnFechar;
		System::Windows::Forms::Label* label3;
		System::Windows::Forms::TextBox* edtNovaSenha;
		System::Windows::Forms::TextBox* edtLogin;
		System::Windows::Forms::Label* label2;
		System::Windows::Forms::Label* label1;
		System::Windows::Forms::TextBox* edtConfirmarSenha;
		System::Windows::Forms::TextBox* edtSenhaAtual;
		System::Windows::Forms::Label* label4;
		System::Data::OleDb::OleDbCommand* Arquiva;
	public:
		frmAlterarSenha();
	protected:
		System::Void Dispose(System::Boolean disposing);
	private:
		System::Void InitializeComponent();
		System::Void frmAlterarSenha_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
		System::Void btnFechar_Click(Object* sender, System::EventArgs* e);
		System::Void btnLimpar_Click(Object* sender, System::EventArgs* e);
		System::Boolean ValidaDados();
		System::Void btnSalvar_Click(Object* sender, System::EventArgs* e);
		System::Void frmAlterarSenha_Load(Object* sender, System::EventArgs* e);
		System::Void frmAlterarSenha_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e);

	};
}
