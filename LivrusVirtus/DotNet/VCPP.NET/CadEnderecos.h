#pragma once

namespace Livrus
{
  public __gc class frmCadEnderecos : public Livrus::frmCadastros
  {
  public:
	static frmCadEnderecos* fCadEnderecos;
	frmCadEnderecos();
  private: 
	System::ComponentModel::IContainer* components;
	System::Windows::Forms::Label* labBairro;
	System::Windows::Forms::TextBox* edtBairro;
	System::Windows::Forms::TextBox* edtCEP;
	System::Windows::Forms::Label* labCEP;
	System::Windows::Forms::TextBox* edtCidade;
	System::Windows::Forms::Label* labCidade;
	System::Windows::Forms::Label* labEstado;
	System::Windows::Forms::ComboBox* cmbEstado;

  	Void InitializeComponent();
  	Void btnNovo_Click(Object* sender, System::EventArgs* e);
        Void btnLimpar_Click(Object* sender, System::EventArgs* e);
  	Void btnExcluir_Click(Object* sender, System::EventArgs* e);
  	Void btnPesquisar_Click(Object* sender, System::EventArgs* e);
  	Void btnAnterior_Click(Object* sender, System::EventArgs* e);
  	Void btnProximo_Click(Object* sender, System::EventArgs* e); 
  	Void btnSalvar_Click(Object* sender, System::EventArgs* e);
        Void edtCodigo_Leave(Object* sender, System::EventArgs* e);
  	Void frmCadEnderecos_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
	Void AdicionaCombo();
	Void RecuperaEstado(String* sEstado);
	Void frmCadEnderecos_Load(Object* sender, System::EventArgs* e);
  protected: 
	Void Dispose (Boolean disposing);
  	Boolean ValidaDados(Boolean bTodosDados);
	Void InformaLimpaDados(Boolean bInformar);
	Void HabilitaDados(Boolean bHabilita);
  };

}
