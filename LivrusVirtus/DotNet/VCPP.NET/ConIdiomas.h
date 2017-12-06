#pragma once

namespace Livrus
{
  public __gc class frmConIdiomas : public Livrus::frmConsultas
  {
  public: 
	static frmConIdiomas* fConIdiomas;
	frmConIdiomas();
  private:
	System::ComponentModel::IContainer* components;
    	System::Windows::Forms::DataGridTableStyle* dataGridTableStyle1;
    	System::Windows::Forms::DataGridTextBoxColumn* dataGridTextBoxColumn1;
    	System::Windows::Forms::DataGridTextBoxColumn* dataGridTextBoxColumn2; 
    	Void InitializeComponent();
    	Void frmConIdiomas_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
    	Void btnLimpar_Click(Object* sender, System::EventArgs* e);
    	Void btnPesquisar_Click(Object* sender, System::EventArgs* e);
    	Void frmConIdiomas_Load(Object* sender, System::EventArgs* e);
  protected: 
	Void Dispose (Boolean disposing);
  };
}
