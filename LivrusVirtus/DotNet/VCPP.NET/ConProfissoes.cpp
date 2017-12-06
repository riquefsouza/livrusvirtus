#include "StdAfx.h"
#include "Consultas.h"
#include "ConProfissoes.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmConProfissoes::frmConProfissoes()
  {
  	InitializeComponent();
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmConProfissoes::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmConProfissoes::InitializeComponent()
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
  	this->labDescricao->Text = S"Profissão:";
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
  	this->dataGridTextBoxColumn2->HeaderText = S"Profissao";
  	this->dataGridTextBoxColumn2->MappingName = S"";
  	this->dataGridTextBoxColumn2->Width = 75;
  	// 
  	// frmConProfissoes
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->ClientSize = System::Drawing::Size(360, 237);
  	this->Name = S"frmConProfissoes";
  	this->Text = S"Consulta de Profissões";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmConProfissoes_Closing);
  	this->Load += new System::EventHandler(this,frmConProfissoes_Load);
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->gridConsulta))->EndInit();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->dsConsulta))->EndInit();
  }
  
  Void frmConProfissoes::frmConProfissoes_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	frmPrincipal::fPrincipal->mnuConProfissoes->Enabled=true;
  }
  
  Void frmConProfissoes::btnLimpar_Click(Object* sender, System::EventArgs* e)
  {
  	LimparDados(ConsultasSQL::ConsSQL->Profissao('S',S"0",S""));
  }
  
  Void frmConProfissoes::btnPesquisar_Click(Object* sender, System::EventArgs* e)
  {
  	PesquisarDados(ConsultasSQL::ConsSQL->Profissao('S',S"", edtDescricao->Text),
	S"Profissão não encontrada!");
  }
  
  Void frmConProfissoes::frmConProfissoes_Load(Object* sender, System::EventArgs* e)
  {
           btnLimpar_Click(this, System::EventArgs::Empty);
  }

}
