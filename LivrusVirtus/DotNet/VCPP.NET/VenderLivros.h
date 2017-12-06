#pragma once

namespace Livrus
{
  public __gc class frmVenderLivros : public System::Windows::Forms::Form
  {
  public:
	frmVenderLivros();
	static frmVenderLivros* fVenderLivros;
  private: 
	float nPrecoTotal;
	ArrayList* slISBNs;
	ArrayList* slPrecos;
	ArrayList* slQtdEstoque;
	ArrayList* ConsCampo;
	System::Data::OleDb::OleDbCommand* Arquiva;
	System::ComponentModel::IContainer* components;
	System::Windows::Forms::Label* labDtHrVenda;
	System::Windows::Forms::TextBox* edtDtHrVenda;
	System::Windows::Forms::Label* labLivrosVender;
	System::Windows::Forms::ListBox* lstLivros;
	System::Windows::Forms::Label* labLivro;
	System::Windows::Forms::Button* btnPCliente;
	System::Windows::Forms::TextBox* edtCliente;
	System::Windows::Forms::Button* btnPLivro;
	System::Windows::Forms::TextBox* edtLivro;
	System::Windows::Forms::TextBox* edtISBN;
	System::Windows::Forms::Label* labISBN;
	System::Windows::Forms::Label* labCLiente;
	System::Windows::Forms::TextBox* edtCPF;
	System::Windows::Forms::Label* labCPF;
	System::Windows::Forms::Button* btnAdLivros;
	System::Windows::Forms::TextBox* edtPrecoTotal;
	System::Windows::Forms::Label* labPrecoTotal;
	System::Windows::Forms::Button* btnVender;
	System::Windows::Forms::Button* btnLimpar;
	System::Windows::Forms::Button* btnFechar;
  	Void InitializeComponent();
	Void LimpaDados();
	Boolean ValidaDados();
	Boolean SalvaLista();
	Void edtCPF_Leave(Object* sender, System::EventArgs* e);
	Void btnPCliente_Click(Object* sender, System::EventArgs* e);
	Void edtISBN_Leave(Object* sender, System::EventArgs* e);
	Void btnPLivro_Click(Object* sender, System::EventArgs* e);
	Void btnAdLivros_Click(Object* sender, System::EventArgs* e);
	Void lstLivros_DoubleClick(Object* sender, System::EventArgs* e);
	Void btnVender_Click(Object* sender, System::EventArgs* e);
	Void btnLimpar_Click(Object* sender, System::EventArgs* e);
	Void btnFechar_Click(Object* sender, System::EventArgs* e);
	Void frmVenderLivros_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
	Void frmVenderLivros_Load(Object* sender, System::EventArgs* e);
	Void frmVenderLivros_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e);
  protected: 
	Void Dispose (Boolean disposing);
  };

}
