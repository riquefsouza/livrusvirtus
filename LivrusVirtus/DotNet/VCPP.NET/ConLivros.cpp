#include "StdAfx.h"
#include "Consultas.h"
#include "ConLivros.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmConLivros::frmConLivros()
  {
  	InitializeComponent();
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmConLivros::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmConLivros::InitializeComponent()
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
  	this->labDescricao->Text = S"Livro:";
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
  	this->dataGridTextBoxColumn2->HeaderText = S"Livro";
  	this->dataGridTextBoxColumn2->MappingName = S"";
  	this->dataGridTextBoxColumn2->Width = 75;
  	// 
  	// frmConLivros
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->ClientSize = System::Drawing::Size(360, 237);
  	this->Name = S"frmConLivros";
  	this->Text = S"Consulta de Livros";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmConLivros_Closing);
  	this->Load += new System::EventHandler(this,frmConLivros_Load);
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->gridConsulta))->EndInit();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->dsConsulta))->EndInit();
  }
  
  Void frmConLivros::frmConLivros_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	if (dsConsulta->Tables->Item[0]->Rows->Count > 0) {
	   Campos = dynamic_cast<ArrayList*>(Registros->
			Item[gridConsulta->CurrentCell.RowNumber]);
  	   RotinasGlobais::Rotinas->sCodigoSelecionado=Campos->Item[0]->ToString();
           RotinasGlobais::Rotinas->sPreco=Campos->Item[2]->ToString();
           RotinasGlobais::Rotinas->sQtdEstoque=Campos->Item[3]->ToString();
	}
  	frmPrincipal::fPrincipal->mnuConLivros->Enabled=true;
  }
  
  Void frmConLivros::btnLimpar_Click(Object* sender, System::EventArgs* e)
  {
  	LimparDados(ConsultasSQL::ConsSQL->Livro('S',S"0",S"",
	S"",S"",S"",S"",S"",S"",S"",S""));
  }
  
  Void frmConLivros::btnPesquisar_Click(Object* sender, System::EventArgs* e)
  {
  	PesquisarDados(ConsultasSQL::ConsSQL->Livro('S',S"", edtDescricao->Text,
	S"",S"",S"",S"",S"",S"",S"",S""),S"Livro não encontrado!");
  }
  
  Void frmConLivros::frmConLivros_Load(Object* sender, System::EventArgs* e)
  {
           btnLimpar_Click(this, System::EventArgs::Empty);
  }

}
