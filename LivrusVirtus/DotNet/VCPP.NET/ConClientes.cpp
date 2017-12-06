#include "StdAfx.h"
#include "Consultas.h"
#include "ConClientes.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmConClientes::frmConClientes()
  {
  	InitializeComponent();
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmConClientes::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmConClientes::InitializeComponent()
  {
  	this->dataGridTableStyle1 = new System::Windows::Forms::DataGridTableStyle();
  	this->dataGridTextBoxColumn1 = new System::Windows::Forms::DataGridTextBoxColumn();
  	this->dataGridTextBoxColumn2 = new System::Windows::Forms::DataGridTextBoxColumn();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->gridConsulta))->BeginInit();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->dsConsulta))->BeginInit();
  	// 
  	// btnPesquisar
  	// 
  	this->btnPesquisar->Name = S"btnPesquisar";
  	this->btnPesquisar->Click += new System::EventHandler(this,btnPesquisar_Click);
  	// 
  	// labDescricao
  	// 
  	this->labDescricao->Name = S"labDescricao";
  	this->labDescricao->Text = S"Cliente:";
  	// 
  	// edtDescricao
  	// 
  	this->edtDescricao->Name = S"edtDescricao";
  	// 
  	// gridConsulta
  	// 
  	this->gridConsulta->Name = S"gridConsulta";
	System::Windows::Forms::DataGridTableStyle* tableStyleTemp[] = new System::Windows::Forms::DataGridTableStyle*[1];
	tableStyleTemp[0] = this->dataGridTableStyle1;
  	this->gridConsulta->TableStyles->AddRange(tableStyleTemp);
  	// 
  	// btnLimpar
  	// 
  	this->btnLimpar->Name = S"btnLimpar";
  	this->btnLimpar->Click += new System::EventHandler(this,btnLimpar_Click);
  	// 
  	// dsConsulta
  	// 
  	this->dsConsulta->DataSetName = S"Consulta";
  	this->dsConsulta->Locale = new System::Globalization::CultureInfo("pt-BR");
  	// 
  	// dataGridTableStyle1
  	// 
  	this->dataGridTableStyle1->DataGrid = this->gridConsulta;
	System::Windows::Forms::DataGridColumnStyle* colStyleTemp[] = new System::Windows::Forms::DataGridColumnStyle*[2];
	colStyleTemp[0] = this->dataGridTextBoxColumn1;
	colStyleTemp[1] = this->dataGridTextBoxColumn2;
  	this->dataGridTableStyle1->GridColumnStyles->AddRange(colStyleTemp);
  	this->dataGridTableStyle1->HeaderForeColor = System::Drawing::SystemColors::ControlText;
  	this->dataGridTableStyle1->MappingName = S"";
  	this->dataGridTableStyle1->ReadOnly = true;
  	// 
  	// dataGridTextBoxColumn1
  	// 
  	this->dataGridTextBoxColumn1->Format = S"";
  	//this->dataGridTextBoxColumn1->FormatInfo = IFormatProvider::GetFormat::Empty;
  	this->dataGridTextBoxColumn1->HeaderText = S"Código";
  	this->dataGridTextBoxColumn1->MappingName = S"";
  	this->dataGridTextBoxColumn1->Width = 75;
  	// 
  	// dataGridTextBoxColumn2
  	// 
  	this->dataGridTextBoxColumn2->Format = S"";
  	//this->dataGridTextBoxColumn2->FormatInfo = IFormatProvider::GetFormat::Empty;
  	this->dataGridTextBoxColumn2->HeaderText = S"Cliente";
  	this->dataGridTextBoxColumn2->MappingName = S"";
  	this->dataGridTextBoxColumn2->Width = 75;
  	// 
  	// frmConClientes
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->ClientSize = System::Drawing::Size(360, 237);
  	this->Name = S"frmConClientes";
  	this->Text = S"Consulta de Clientes";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmConClientes_Closing);
  	this->Load += new System::EventHandler(this,frmConClientes_Load);
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->gridConsulta))->EndInit();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->dsConsulta))->EndInit();
  }
  
  Void frmConClientes::frmConClientes_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	frmPrincipal::fPrincipal->mnuConClientes->Enabled=true;
  }
  
  Void frmConClientes::btnLimpar_Click(Object* sender, System::EventArgs* e)
  {
  	LimparDados(ConsultasSQL::ConsSQL->Cliente('S',S"0",
	S"",S"",S"",S"",S"",S"",S"",S"",S""));
  }
  
  Void frmConClientes::btnPesquisar_Click(Object* sender, System::EventArgs* e)
  {
  	PesquisarDados(ConsultasSQL::ConsSQL->Cliente('S',S"",S"",S"",S"",
	S"",S"",S"",S"",S"", edtDescricao->Text),S"Cliente não encontrado!");
  }
  
  Void frmConClientes::frmConClientes_Load(Object* sender, System::EventArgs* e)
  {
           btnLimpar_Click(this, System::EventArgs::Empty);
  }

}
