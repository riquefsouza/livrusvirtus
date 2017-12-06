#pragma once

namespace Livrus
{
  public __gc class frmConProfissoes : public Livrus::frmConsultas
  {
  public: 
	static frmConProfissoes* fConProfissoes;
	frmConProfissoes();
  private:
	System::ComponentModel::IContainer* components;
    	System::Windows::Forms::DataGridTableStyle* dataGridTableStyle1;
    	System::Windows::Forms::DataGridTextBoxColumn* dataGridTextBoxColumn1;
    	System::Windows::Forms::DataGridTextBoxColumn* dataGridTextBoxColumn2; 
    	Void InitializeComponent();
    	Void frmConProfissoes_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
    	Void btnLimpar_Click(Object* sender, System::EventArgs* e);
    	Void btnPesquisar_Click(Object* sender, System::EventArgs* e);
    	Void frmConProfissoes_Load(Object* sender, System::EventArgs* e);
  protected: 
	Void Dispose (Boolean disposing);
  };
}
