#include "StdAfx.h"
#include "Consultas.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmConsultas::frmConsultas()
  {
  	//
  	// Required for Windows Form Designer support
  	//
  	InitializeComponent();
  
  	//
  	// TODO: Add any constructor code after InitializeComponent call
  	//
	Registros = new ArrayList();
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmConsultas::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmConsultas::InitializeComponent()
  {
  	this->panel1 = new System::Windows::Forms::Panel();
  	this->btnPesquisar = new System::Windows::Forms::Button();
  	this->edtDescricao = new System::Windows::Forms::TextBox();
  	this->labDescricao = new System::Windows::Forms::Label();
  	this->gridConsulta = new System::Windows::Forms::DataGrid();
  	this->dsConsulta = new System::Data::DataSet();
  	this->panel2 = new System::Windows::Forms::Panel();
  	this->labRegistros = new System::Windows::Forms::Label();
  	this->btnLimpar = new System::Windows::Forms::Button();
  	this->btnFechar = new System::Windows::Forms::Button();
  	this->panel1->SuspendLayout();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->gridConsulta))->BeginInit();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->dsConsulta))->BeginInit();
  	this->panel2->SuspendLayout();
  	this->SuspendLayout();
  	// 
  	// panel1
  	// 
  	this->panel1->Controls->Add(this->btnPesquisar);
  	this->panel1->Controls->Add(this->edtDescricao);
  	this->panel1->Controls->Add(this->labDescricao);
  	this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
  	this->panel1->Location = System::Drawing::Point(0, 0);
  	this->panel1->Name = S"panel1";
  	this->panel1->Size = System::Drawing::Size(360, 56);
  	this->panel1->TabIndex = 0;
  	// 
  	// btnPesquisar
  	// 
  	this->btnPesquisar->Location = System::Drawing::Point(280, 24);
  	this->btnPesquisar->Name = S"btnPesquisar";
  	this->btnPesquisar->TabIndex = 2;
  	this->btnPesquisar->Text = S"&Pesquisar";
  	// 
  	// edtDescricao
  	// 
  	this->edtDescricao->Location = System::Drawing::Point(8, 24);
  	this->edtDescricao->Name = S"edtDescricao";
  	this->edtDescricao->Size = System::Drawing::Size(264, 20);
  	this->edtDescricao->TabIndex = 1;
  	this->edtDescricao->Text = S"";
  	// 
  	// labDescricao
  	// 
  	this->labDescricao->Location = System::Drawing::Point(8, 8);
  	this->labDescricao->Name = S"labDescricao";
  	this->labDescricao->Size = System::Drawing::Size(64, 16);
  	this->labDescricao->TabIndex = 0;
  	this->labDescricao->Text = S"Descrição:";
  	// 
  	// gridConsulta
  	// 
  	this->gridConsulta->Anchor = ((System::Windows::Forms::AnchorStyles)(((
			(System::Windows::Forms::AnchorStyles::Top 
			| System::Windows::Forms::AnchorStyles::Bottom) 
  			| System::Windows::Forms::AnchorStyles::Left) 
  			| System::Windows::Forms::AnchorStyles::Right)));
  	this->gridConsulta->CaptionVisible = false;
  	this->gridConsulta->DataMember = S"";
  	this->gridConsulta->DataSource = this->dsConsulta;
  	this->gridConsulta->HeaderForeColor = System::Drawing::SystemColors::ControlText;
  	this->gridConsulta->Location = System::Drawing::Point(0, 56);
  	this->gridConsulta->Name = S"gridConsulta";
  	this->gridConsulta->ParentRowsVisible = false;
  	this->gridConsulta->ReadOnly = true;
  	this->gridConsulta->Size = System::Drawing::Size(360, 144);
  	this->gridConsulta->TabIndex = 1;
  	this->gridConsulta->CurrentCellChanged += new System::EventHandler(this,gridConsulta_CurrentCellChanged);
  	this->gridConsulta->MouseMove += new System::Windows::Forms::MouseEventHandler(this,gridConsulta_MouseMove);
  	// 
  	// dsConsulta
  	// 
  	this->dsConsulta->DataSetName = S"Consulta";
  	this->dsConsulta->Locale = new System::Globalization::CultureInfo(S"pt-BR");
  	// 
  	// panel2
  	// 
  	this->panel2->Anchor = ((System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
  				| System::Windows::Forms::AnchorStyles::Right)));
  	this->panel2->Controls->Add(this->labRegistros);
  	this->panel2->Controls->Add(this->btnLimpar);
  	this->panel2->Controls->Add(this->btnFechar);
  	this->panel2->Location = System::Drawing::Point(0, 200);
  	this->panel2->Name = S"panel2";
  	this->panel2->Size = System::Drawing::Size(360, 40);
  	this->panel2->TabIndex = 2;
  	// 
  	// labRegistros
  	// 
  	this->labRegistros->Location = System::Drawing::Point(11, 12);
  	this->labRegistros->Name = S"labRegistros";
  	this->labRegistros->Size = System::Drawing::Size(136, 16);
  	this->labRegistros->TabIndex = 0;
  	this->labRegistros->Text = S"Registro 0 de 0";
  	// 
  	// btnLimpar
  	// 
	this->btnLimpar->Anchor = ((System::Windows::Forms::AnchorStyles)
			((System::Windows::Forms::AnchorStyles::Top | 
			System::Windows::Forms::AnchorStyles::Right)));
  	this->btnLimpar->Location = System::Drawing::Point(200, 8);
  	this->btnLimpar->Name = S"btnLimpar";
  	this->btnLimpar->TabIndex = 1;
  	this->btnLimpar->Text = S"&Limpar";
  	// 
  	// btnFechar
  	// 
	this->btnFechar->Anchor = ((System::Windows::Forms::AnchorStyles)
			((System::Windows::Forms::AnchorStyles::Top | 
			System::Windows::Forms::AnchorStyles::Right)));
  	this->btnFechar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
  	this->btnFechar->Location = System::Drawing::Point(280, 8);
  	this->btnFechar->Name = S"btnFechar";
  	this->btnFechar->TabIndex = 2;
  	this->btnFechar->Text = S"&Fechar";
  	this->btnFechar->Click += new System::EventHandler(this,btnFechar_Click);
  	// 
  	// frmConsultas
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->ClientSize = System::Drawing::Size(360, 237);
  	this->Controls->Add(this->panel2);
  	this->Controls->Add(this->gridConsulta);
  	this->Controls->Add(this->panel1);
  	this->Name = S"frmConsultas";
  	this->Text = S"Consulta de";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmConsultas_Closing);
  	this->panel1->ResumeLayout(false);
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->gridConsulta))->EndInit();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->dsConsulta))->EndInit();
  	this->panel2->ResumeLayout(false);
  	this->ResumeLayout(false);
  }
  
  Void frmConsultas::btnFechar_Click(Object* sender, System::EventArgs* e)
  {
  	Close();
  }
  
  Void frmConsultas::frmConsultas_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	if (dsConsulta->Tables->Item[0]->Rows->Count > 0) {
	   Campos = dynamic_cast<ArrayList*>(Registros->
			Item[gridConsulta->CurrentCell.RowNumber]);
  	   RotinasGlobais::Rotinas->sCodigoSelecionado=
				Campos->Item[0]->ToString();
	}
  	frmPrincipal::fPrincipal->statusBar1->Panels->Item[1]->Text=S"";
  }
  
  Void frmConsultas::LimparDados(String* sTextoSql)
  {
    labRegistros->Text=S"Registro 0 de 0";
    RotinasGlobais::Rotinas->ConsultaDados(dsConsulta, Registros, sTextoSql);
    btnPesquisar->Enabled=true;
    edtDescricao->Text=S"";
    edtDescricao->Focus();
  
  }
  
  Boolean frmConsultas::PesquisarDados(String* sTextoSql, String* sMensagemErro)
  {
    if (RotinasGlobais::Rotinas->ConsultaDados(dsConsulta, Registros, sTextoSql)) {
  	 gridConsulta->SetDataBinding(dsConsulta,S"Consulta");
  	 gridConsulta_CurrentCellChanged(this,System::EventArgs::Empty);
  	 btnPesquisar->Enabled=false;
  	 return true;
    } else {
  	 MessageBox::Show(sMensagemErro, frmPrincipal::fPrincipal->Text,
  	 MessageBoxButtons::OK, MessageBoxIcon::Error);
  	 return false;
    }
  }
  
  Void frmConsultas::gridConsulta_CurrentCellChanged(Object* sender, System::EventArgs* e)
  {
  	labRegistros->Text=String::Concat(S"Registro ",
  	Convert::ToString(gridConsulta->CurrentCell.RowNumber+1),
  	S" de ",Convert::ToString(dsConsulta->Tables->Item[S"Consulta"]->Rows->Count));
  }
  
  Void frmConsultas::gridConsulta_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e)
  {
  	frmPrincipal::fPrincipal->statusBar1->Panels->Item[1]->Text=Text;
  }
  

}
