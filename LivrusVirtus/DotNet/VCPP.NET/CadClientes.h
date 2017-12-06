#pragma once

namespace Livrus
{
  public __gc class frmCadClientes : public Livrus::frmCadastros
  {
  public:
	static frmCadClientes* fCadClientes;
	frmCadClientes();
  private: 
	ArrayList* ConsCampo;
	String* sSexo;
	System::ComponentModel::IContainer* components;
	System::Windows::Forms::Label* labEmail;
	System::Windows::Forms::TextBox* edtEmail;
	System::Windows::Forms::TextBox* edtIdentidade;
	System::Windows::Forms::Label* labIdentidade;
	System::Windows::Forms::GroupBox* rdgSexo;
	System::Windows::Forms::RadioButton* rbMasculino;
	System::Windows::Forms::RadioButton* rbFeminino;
	System::Windows::Forms::TextBox* edtTelefone;
	System::Windows::Forms::Label* labTelefone;
	System::Windows::Forms::DateTimePicker* edtDtNascimento;
	System::Windows::Forms::Label* labDtNascimento;
	System::Windows::Forms::GroupBox* grpEndereco;
	System::Windows::Forms::TextBox* edtCodEndereco;
	System::Windows::Forms::Button* btnPEndereco;
	System::Windows::Forms::TextBox* edtBairro;
	System::Windows::Forms::Label* labBairro;
	System::Windows::Forms::TextBox* edtLogradouro;
	System::Windows::Forms::Label* labLogradouro;
	System::Windows::Forms::Label* labEstado;
	System::Windows::Forms::TextBox* edtCidade;
	System::Windows::Forms::Label* labCidade;
	System::Windows::Forms::TextBox* edtCEP;
	System::Windows::Forms::Label* labCEP;
	System::Windows::Forms::TextBox* edtEstado;
	System::Windows::Forms::TextBox* edtPais;
	System::Windows::Forms::TextBox* edtCodPais;
	System::Windows::Forms::Label* labPais;
	System::Windows::Forms::Button* btnPPais;
	System::Windows::Forms::Button* btnPProfissao;
	System::Windows::Forms::TextBox* edtProfissao;
	System::Windows::Forms::TextBox* edtCodProfissao;
	System::Windows::Forms::Label* labProfissao;
  	Void InitializeComponent();
        Void btnLimpar_Click(Object* sender, System::EventArgs* e);
  	Void btnExcluir_Click(Object* sender, System::EventArgs* e);
  	Void btnPesquisar_Click(Object* sender, System::EventArgs* e);
  	Void btnAnterior_Click(Object* sender, System::EventArgs* e);
  	Void btnProximo_Click(Object* sender, System::EventArgs* e); 
  	Void btnSalvar_Click(Object* sender, System::EventArgs* e);
  	Void frmCadClientes_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
	Void edtCodEndereco_Leave(Object* sender, System::EventArgs* e);
	Void edtCodPais_Leave(Object* sender, System::EventArgs* e);
	Void edtCodProfissao_Leave(Object* sender, System::EventArgs* e);
	Void btnPEndereco_Click(Object* sender, System::EventArgs* e);
	Void btnPPais_Click(Object* sender, System::EventArgs* e);
	Void btnPProfissao_Click(Object* sender, System::EventArgs* e);
  protected: 
	Void Dispose (Boolean disposing);
  	Boolean ValidaDados(Boolean bTodosDados);
	Void InformaLimpaDados(Boolean bInformar);
	Void HabilitaDados(Boolean bHabilita);
	Void edtCodigo_Leave(Object* sender, System::EventArgs* e);
	Void btnNovo_Click(Object* sender, System::EventArgs* e);
  };

}
