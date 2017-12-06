#include "StdAfx.h"
#include "Consultas.h"
#include "ConVendas.h"
#include "Consultas.h"
#include "ConLivros.h"
#include "ConClientes.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmConVendas::frmConVendas()
  {
  	InitializeComponent();

	ConsTotal = new ArrayList();
	ConsCampo = new ArrayList();
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmConVendas::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmConVendas::InitializeComponent()
  {
        this->btnPLivro = new System::Windows::Forms::Button();
        this->edtLivro = new System::Windows::Forms::TextBox();
        this->edtISBN = new System::Windows::Forms::TextBox();
        this->labISBN = new System::Windows::Forms::Label();
        this->labDtHrVenda = new System::Windows::Forms::Label();
        this->edtDtVenda = new System::Windows::Forms::DateTimePicker();
        this->edtHrVenda = new System::Windows::Forms::DateTimePicker();
        this->btnPCliente = new System::Windows::Forms::Button();
        this->edtCliente = new System::Windows::Forms::TextBox();
        this->labCLiente = new System::Windows::Forms::Label();
        this->labLivro = new System::Windows::Forms::Label();
        this->edtPrecoTotal = new System::Windows::Forms::TextBox();
        this->labPrecoTotal = new System::Windows::Forms::Label();
        this->panel1->SuspendLayout();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->gridConsulta))->BeginInit();
        this->panel2->SuspendLayout();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->dsConsulta))->BeginInit();
        this->SuspendLayout();
	//
	// panel1
	// 
	this->panel1->Anchor = ((System::Windows::Forms::AnchorStyles)(
				((System::Windows::Forms::AnchorStyles::Top | 
				System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right)));
	this->panel1->Controls->Add(this->labLivro);
	this->panel1->Controls->Add(this->btnPCliente);
	this->panel1->Controls->Add(this->edtCliente);
	this->panel1->Controls->Add(this->edtHrVenda);
	this->panel1->Controls->Add(this->labDtHrVenda);
	this->panel1->Controls->Add(this->edtDtVenda);
	this->panel1->Controls->Add(this->btnPLivro);
	this->panel1->Controls->Add(this->edtLivro);
	this->panel1->Controls->Add(this->edtISBN);
	this->panel1->Controls->Add(this->labISBN);
	this->panel1->Controls->Add(this->labCLiente);
	this->panel1->Dock = System::Windows::Forms::DockStyle::None;
	this->panel1->Name = S"panel1";
	this->panel1->Size = System::Drawing::Size(1128, 136);
	//
	// btnPesquisar
	//
	this->btnPesquisar->Location = System::Drawing::Point(232, 24);
	this->btnPesquisar->Name = S"btnPesquisar";
	this->btnPesquisar->TabIndex = 3;
	this->btnPesquisar->Click += new System::EventHandler(this,btnPesquisar_Click);
	//
	// edtDescricao
	//
	this->edtDescricao->Location = System::Drawing::Point(8, 64);
	this->edtDescricao->Name = S"edtDescricao";
	this->edtDescricao->Size = System::Drawing::Size(128, 20);
	this->edtDescricao->TabIndex = 5;
	this->edtDescricao->MaxLength = 14;
	this->edtDescricao->Leave += new System::EventHandler(this,edtDescricao_Leave);
	// 
	// labDescricao
	// 
	this->labDescricao->Location = System::Drawing::Point(8, 48);
	this->labDescricao->Name = S"labDescricao";
	this->labDescricao->TabIndex = 4;
	this->labDescricao->Text = S"CPF:";
	//
	// gridConsulta
	//
	this->gridConsulta->Location = System::Drawing::Point(0, 136);
	this->gridConsulta->Name = S"gridConsulta";
	this->gridConsulta->Size = System::Drawing::Size(456, 136);
	//
	// panel2
	//
	this->panel2->Controls->Add(this->edtPrecoTotal);
	this->panel2->Controls->Add(this->labPrecoTotal);
	this->panel2->Location = System::Drawing::Point(0, 272);
	this->panel2->Name = S"panel2";
	this->panel2->Size = System::Drawing::Size(464, 72);
	//
	// btnLimpar
	//
	this->btnLimpar->Location = System::Drawing::Point(296, 40);
	this->btnLimpar->Name = S"btnLimpar";
	this->btnLimpar->TabIndex = 3;
	this->btnLimpar->Click += new System::EventHandler(this,btnLimpar_Click);
	//
	// btnFechar
	//
	this->btnFechar->Location = System::Drawing::Point(376, 40);
	this->btnFechar->Name = S"btnFechar";
	this->btnFechar->TabIndex = 4;
	//
	// labRegistros
	//
	this->labRegistros->Location = System::Drawing::Point(11, 40);
	this->labRegistros->Name = S"labRegistros";
	this->labRegistros->TabIndex = 2;
	//
	// dsConsulta
	//
	this->dsConsulta->DataSetName = S"Consulta";
	this->dsConsulta->Locale = new System::Globalization::CultureInfo("pt-BR");
	//
	// btnPLivro
	//
	this->btnPLivro->Location = System::Drawing::Point(424, 104);
	this->btnPLivro->Name = S"btnPLivro";
	this->btnPLivro->Size = System::Drawing::Size(22, 20);
	this->btnPLivro->TabIndex = 13;
	this->btnPLivro->Text = S"...";
	this->btnPLivro->Click += new System::EventHandler(this,btnPLivro_Click);
	//
	// edtLivro
	//
	this->edtLivro->Enabled = false;
	this->edtLivro->Location = System::Drawing::Point(144, 104);
	this->edtLivro->MaxLength = 30;
	this->edtLivro->Name = S"edtLivro";
	this->edtLivro->Size = System::Drawing::Size(280, 20);
	this->edtLivro->TabIndex = 12;
	this->edtLivro->Text = S"";
	//
	// edtISBN
	//
	this->edtISBN->Location = System::Drawing::Point(8, 104);
	this->edtISBN->MaxLength = 13;
	this->edtISBN->Name = S"edtISBN";
	this->edtISBN->Size = System::Drawing::Size(128, 20);
	this->edtISBN->TabIndex = 10;
	this->edtISBN->Text = S"";
	this->edtISBN->Leave += new System::EventHandler(this,edtISBN_Leave);
	// 
	// labISBN
	// 
	this->labISBN->Location = System::Drawing::Point(8, 88);
	this->labISBN->Name = S"labISBN";
	this->labISBN->Size = System::Drawing::Size(52, 16);
	this->labISBN->TabIndex = 9;
	this->labISBN->Text = S"ISBN:";
	// 
	// labDtHrVenda
	// 
	this->labDtHrVenda->Location = System::Drawing::Point(8, 8);
	this->labDtHrVenda->Name = S"labDtHrVenda";
	this->labDtHrVenda->Size = System::Drawing::Size(96, 16);
	this->labDtHrVenda->TabIndex = 0;
	this->labDtHrVenda->Text = S"Data/Hora Venda:";
	//
	// edtDtVenda
	// 
	this->edtDtVenda->Checked = false;
	this->edtDtVenda->Format = System::Windows::Forms::DateTimePickerFormat::Short;
	this->edtDtVenda->Location = System::Drawing::Point(8, 24);
	this->edtDtVenda->Name = S"edtDtVenda";
	this->edtDtVenda->ShowCheckBox = true;
	this->edtDtVenda->Size = System::Drawing::Size(104, 20);
	this->edtDtVenda->TabIndex = 1;
	// 
	// edtHrVenda
	// 
	this->edtHrVenda->Checked = false;
	this->edtHrVenda->Format = System::Windows::Forms::DateTimePickerFormat::Time;
	this->edtHrVenda->Location = System::Drawing::Point(120, 24);
	this->edtHrVenda->Name = S"edtHrVenda";
	this->edtHrVenda->ShowCheckBox = true;
	this->edtHrVenda->ShowUpDown = true;
	this->edtHrVenda->Size = System::Drawing::Size(104, 20);
	this->edtHrVenda->TabIndex = 2;
	// 
	// btnPCliente
	//
	this->btnPCliente->Location = System::Drawing::Point(424, 62);
	this->btnPCliente->Name = S"btnPCliente";
	this->btnPCliente->Size = System::Drawing::Size(22, 20);
	this->btnPCliente->TabIndex = 8;
	this->btnPCliente->Text = S"...";
	this->btnPCliente->Click += new System::EventHandler(this,btnPCliente_Click);
	// 
	// edtCliente
	// 
	this->edtCliente->Enabled = false;
	this->edtCliente->Location = System::Drawing::Point(144, 62);
	this->edtCliente->MaxLength = 30;
	this->edtCliente->Name = S"edtCliente";
	this->edtCliente->Size = System::Drawing::Size(280, 20);
	this->edtCliente->TabIndex = 7;
	this->edtCliente->Text = S"";
	// 
	// labCLiente
	// 
	this->labCLiente->Location = System::Drawing::Point(144, 48);
	this->labCLiente->Name = S"labCLiente";
	this->labCLiente->Size = System::Drawing::Size(52, 16);
	this->labCLiente->TabIndex = 6;
	this->labCLiente->Text = S"Cliente:";
	// 
	// labLivro
	// 
	this->labLivro->Location = System::Drawing::Point(144, 88);
	this->labLivro->Name = S"labLivro";
	this->labLivro->Size = System::Drawing::Size(52, 16);
	this->labLivro->TabIndex = 11;
	this->labLivro->Text = S"Livro:";
	//
	// edtPrecoTotal
	// 
	this->edtPrecoTotal->Anchor = ((System::Windows::Forms::AnchorStyles)(
				(System::Windows::Forms::AnchorStyles::Top | 
				System::Windows::Forms::AnchorStyles::Right)));
	this->edtPrecoTotal->Enabled = false;
	this->edtPrecoTotal->Location = System::Drawing::Point(320, 8);
	this->edtPrecoTotal->MaxLength = 10;
	this->edtPrecoTotal->Name = S"edtPrecoTotal";
	this->edtPrecoTotal->Size = System::Drawing::Size(128, 20);
	this->edtPrecoTotal->TabIndex = 1;
	this->edtPrecoTotal->Text = S"";
	// 
	// labPrecoTotal
	// 
	this->labPrecoTotal->Anchor = ((System::Windows::Forms::AnchorStyles)(
				(System::Windows::Forms::AnchorStyles::Top | 
				System::Windows::Forms::AnchorStyles::Right)));
	this->labPrecoTotal->Location = System::Drawing::Point(248, 8);
	this->labPrecoTotal->Name = S"labPrecoTotal";
	this->labPrecoTotal->Size = System::Drawing::Size(64, 16);
	this->labPrecoTotal->TabIndex = 0;
	this->labPrecoTotal->Text = S"Preço total:";
	// 
	// frmConVendas
	// 
	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
	this->ClientSize = System::Drawing::Size(456, 341);
	this->Name = S"frmConVendas";
	this->Text = S"Consulta de Vendas Realizadas";
	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmConVendas_Closing);
	this->Load += new System::EventHandler(this,frmConVendas_Load);
	this->panel1->ResumeLayout(false);
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->gridConsulta))->EndInit();
	this->panel2->ResumeLayout(false);
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->dsConsulta))->EndInit();
	this->ResumeLayout(false);
  }
  
  Void frmConVendas::btnLimpar_Click(Object* sender, System::EventArgs* e)
  {
  	edtDtVenda->Value=System::DateTime::Now;
  	edtHrVenda->Value=System::DateTime::Now;
  	edtDtVenda->Checked=false;
  	edtHrVenda->Checked=false;
  	edtCliente->Clear();
  	edtISBN->Clear();
  	edtLivro->Clear();
  	edtPrecoTotal->Text=S"R$ 0,00";
  	edtDtVenda->Focus();
  
  	LimparDados(ConsVenda('L'));
  
  }
  
  String* frmConVendas::ConsVenda(char sOpcao)  {
    String* sDataVenda;
    String* sHoraVenda;
    String* sDtHrVenda;
  
    if (edtDtVenda->Checked)
  	sDataVenda=edtDtVenda->Value.ToString(S"dd/MM/yyyy");
    else
  	 sDataVenda=S"";
    if (edtHrVenda->Checked)
  	sHoraVenda=edtHrVenda->Value.ToString(S"hh:mm:ss");
    else
  	 sHoraVenda=S"";
    sDtHrVenda=String::Concat(sDataVenda->Trim(),S" ",sHoraVenda->Trim());
    if (sOpcao=='L')
     return ConsultasSQL::ConsSQL->Venda('S',S"ZERO",S"",S"",S"",S"");
    else
     return ConsultasSQL::ConsSQL->Venda(sOpcao,edtISBN->Text,
     edtDescricao->Text, sDtHrVenda->Trim(),S"",S"");
    
  }
  
  Void frmConVendas::btnPesquisar_Click(Object* sender, System::EventArgs* e)
  {
    ArrayList* linhas = new ArrayList();
    if (PesquisarDados(ConsVenda('S'),S"Venda não encontrada!")) {
  	 RotinasGlobais::Rotinas->ConsultaDados(ConsTotal,ConsVenda('P'));
  	 if (ConsTotal->Count > 0) {
  		linhas = dynamic_cast<ArrayList*>(ConsTotal->Item[0]);
  		edtPrecoTotal->Text=String::Concat(S"R$ ",linhas->Item[0]->ToString());
  	 }
  	}
  
  }
  
  Void frmConVendas::frmConVendas_Load(Object* sender, System::EventArgs* e)
  {
    btnLimpar_Click(this,System::EventArgs::Empty);
  }
  
  Void frmConVendas::edtDescricao_Leave(Object* sender, System::EventArgs* e)
  {
  	if (edtDescricao->Text->Equals(S"")==false) {
  	  if (RotinasGlobais::Rotinas->ValidaCPF(edtDescricao->Text)) {
  
  		  edtCliente->Text =
  		  RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo,
  		  ConsultasSQL::ConsSQL->Cliente('S',edtDescricao->Text,
  		  S"",S"",S"",S"",S"",S"",S"",S"",S""),S"Cliente não encontrado!");
  		  if (edtCliente->Text->Equals(S"")) {
  			edtDescricao->Clear();
  			edtDescricao->Focus();
  		  }
  	  } else {
  		  MessageBox::Show(this,S"CPF inválido!",
  		  frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  		  MessageBoxIcon::Error);
  		  edtDescricao->Clear();
  		  edtCliente->Clear();
  	  }
  	}
  }
  
  Void frmConVendas::edtISBN_Leave(Object* sender, System::EventArgs* e)
  {
  	if (edtISBN->Text->Equals(S"")==false) {
  	  if (RotinasGlobais::Rotinas->ValidaISBN(edtISBN->Text)) {
  		  edtLivro->Text=
  		  RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo,
  		  ConsultasSQL::ConsSQL->Livro('Q',edtISBN->Text,
  		  S"",S"",S"",S"",S"",S"",S"",S"",S""),S"Livro não encontrado!");
  		  if (edtLivro->Text->Equals(S"")==false) {
  		   if (Int32::Parse(ConsCampo->Item[3]->ToString()) > 0) {
  			 RotinasGlobais::Rotinas->sPreco=ConsCampo->Item[2]->ToString();
  		   } else
  			  MessageBox::Show(this,S"Livro não existe no estoque!",
  			  frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  			  MessageBoxIcon::Error);
  		  } else {
  			edtISBN->Clear();
  			edtISBN->Focus();
  		  }
  	  } else {
  		  MessageBox::Show(this,S"ISBN inválido!",
  		  frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  		  MessageBoxIcon::Error);
  		  edtISBN->Clear();
  		  edtLivro->Clear();
  	  }
  	}
  }
  
  Void frmConVendas::btnPCliente_Click(Object* sender, System::EventArgs* e)
  {
  	frmConClientes* pfConClientes = new frmConClientes();
  	pfConClientes->ShowDialog();
  	edtDescricao->Text=RotinasGlobais::Rotinas->sCodigoSelecionado;
  	edtDescricao_Leave(this,System::EventArgs::Empty);
  }
  
  Void frmConVendas::btnPLivro_Click(Object* sender, System::EventArgs* e)
  {
  	frmConLivros* pfConLivros = new frmConLivros();
  	pfConLivros->ShowDialog();
  	edtISBN->Text=RotinasGlobais::Rotinas->sCodigoSelecionado;
  	edtISBN_Leave(this,System::EventArgs::Empty);
  }
  
  Void frmConVendas::frmConVendas_Closing(Object* sender,
					System::ComponentModel::CancelEventArgs* e)
  {
     frmPrincipal::fPrincipal->mnuVendasRealizadas->Enabled=true;
  }


}
