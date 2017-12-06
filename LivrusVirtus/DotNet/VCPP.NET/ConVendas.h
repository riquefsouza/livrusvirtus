#pragma once

namespace Livrus
{
  public __gc class frmConVendas : public Livrus::frmConsultas
  {
  public: 
	static frmConVendas* fConVendas;
	frmConVendas();
  private:
	ArrayList* ConsTotal;
	ArrayList* ConsCampo;
	System::ComponentModel::IContainer* components;
	System::Windows::Forms::Button* btnPLivro;
	System::Windows::Forms::TextBox* edtLivro;
	System::Windows::Forms::TextBox* edtISBN;
	System::Windows::Forms::Label* labISBN;
	System::Windows::Forms::Label* labDtHrVenda;
	System::Windows::Forms::DateTimePicker* edtDtVenda;
	System::Windows::Forms::DateTimePicker* edtHrVenda;
	System::Windows::Forms::Button* btnPCliente;
	System::Windows::Forms::TextBox* edtCliente;
	System::Windows::Forms::Label* labCLiente;
	System::Windows::Forms::Label* labLivro;
	System::Windows::Forms::TextBox* edtPrecoTotal;
	System::Windows::Forms::Label* labPrecoTotal;
    	Void InitializeComponent();
    	Void btnLimpar_Click(Object* sender, System::EventArgs* e);
	String* ConsVenda(char sOpcao);
	Void btnPesquisar_Click(Object* sender, System::EventArgs* e);
	Void frmConVendas_Load(Object* sender, System::EventArgs* e);
	Void edtDescricao_Leave(Object* sender, System::EventArgs* e);
	Void edtISBN_Leave(Object* sender, System::EventArgs* e);
	Void btnPCliente_Click(Object* sender, System::EventArgs* e);
	Void btnPLivro_Click(Object* sender, System::EventArgs* e);
	Void frmConVendas_Closing(Object* sender,
				System::ComponentModel::CancelEventArgs* e);
  protected: 
	Void Dispose (Boolean disposing);
  };
}
