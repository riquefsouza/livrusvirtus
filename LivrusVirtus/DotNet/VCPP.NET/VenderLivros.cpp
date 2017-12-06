#include "StdAfx.h"
#include "VenderLivros.h"
#include "Consultas.h"
#include "ConClientes.h"
#include "ConLivros.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmVenderLivros::frmVenderLivros()
  {
  	//
  	// Required for Windows Form Designer support
  	//
  	InitializeComponent();
  
  	//
  	// TODO: Add any constructor code after InitializeComponent call
  	//
	slISBNs = new ArrayList();
	slPrecos = new ArrayList();
	slQtdEstoque = new ArrayList();
	ConsCampo = new ArrayList();
	Arquiva = new System::Data::OleDb::OleDbCommand();
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmVenderLivros::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmVenderLivros::InitializeComponent()
  {
    this->labDtHrVenda = new System::Windows::Forms::Label();
    this->edtDtHrVenda = new System::Windows::Forms::TextBox();
    this->labLivrosVender = new System::Windows::Forms::Label();
    this->lstLivros = new System::Windows::Forms::ListBox();
    this->labLivro = new System::Windows::Forms::Label();
    this->btnPCliente = new System::Windows::Forms::Button();
    this->edtCliente = new System::Windows::Forms::TextBox();
    this->btnPLivro = new System::Windows::Forms::Button();
    this->edtLivro = new System::Windows::Forms::TextBox();
    this->edtISBN = new System::Windows::Forms::TextBox();
    this->labISBN = new System::Windows::Forms::Label();
    this->labCLiente = new System::Windows::Forms::Label();
    this->edtCPF = new System::Windows::Forms::TextBox();
    this->labCPF = new System::Windows::Forms::Label();
    this->btnAdLivros = new System::Windows::Forms::Button();
    this->edtPrecoTotal = new System::Windows::Forms::TextBox();
    this->labPrecoTotal = new System::Windows::Forms::Label();
    this->btnVender = new System::Windows::Forms::Button();
    this->btnLimpar = new System::Windows::Forms::Button();
    this->btnFechar = new System::Windows::Forms::Button();
    this->SuspendLayout();
    // 
    // labDtHrVenda
    // 
    this->labDtHrVenda->Location = System::Drawing::Point(8, 8);
    this->labDtHrVenda->Name = S"labDtHrVenda";
    this->labDtHrVenda->Size = System::Drawing::Size(100, 16);
    this->labDtHrVenda->TabIndex = 0;
    this->labDtHrVenda->Text = S"Data/Hora Venda:";
    // 
    // edtDtHrVenda
    // 
    this->edtDtHrVenda->Enabled = false;
    this->edtDtHrVenda->Location = System::Drawing::Point(8, 24);
    this->edtDtHrVenda->Name = S"edtDtHrVenda";
    this->edtDtHrVenda->Size = System::Drawing::Size(120, 20);
    this->edtDtHrVenda->TabIndex = 1;
    this->edtDtHrVenda->Text = S"";
    // 
    // labLivrosVender
    // 
    this->labLivrosVender->Location = System::Drawing::Point(8, 128);
    this->labLivrosVender->Name = S"labLivrosVender";
    this->labLivrosVender->Size = System::Drawing::Size(112, 16);
    this->labLivrosVender->TabIndex = 13;
    this->labLivrosVender->Text = S"Livros para vender:";
    // 
    // lstLivros
    // 
    this->lstLivros->Location = System::Drawing::Point(8, 144);
    this->lstLivros->Name = S"lstLivros";
    this->lstLivros->Size = System::Drawing::Size(464, 108);
    this->lstLivros->TabIndex = 14;
    this->lstLivros->DoubleClick += new System::EventHandler(this,lstLivros_DoubleClick);
    // 
    // labLivro
    // 
    this->labLivro->Location = System::Drawing::Point(144, 88);
    this->labLivro->Name = S"labLivro";
    this->labLivro->Size = System::Drawing::Size(52, 16);
    this->labLivro->TabIndex = 9;
    this->labLivro->Text = S"Livro:";
    // 
    // btnPCliente
    // 
    this->btnPCliente->Location = System::Drawing::Point(448, 64);
    this->btnPCliente->Name = S"btnPCliente";
    this->btnPCliente->Size = System::Drawing::Size(22, 20);
    this->btnPCliente->TabIndex = 6;
    this->btnPCliente->Text = S"...";
    this->btnPCliente->Click += new System::EventHandler(this,btnPCliente_Click);
    // 
    // edtCliente
    // 
    this->edtCliente->Enabled = false;
    this->edtCliente->Location = System::Drawing::Point(144, 64);
    this->edtCliente->MaxLength = 30;
    this->edtCliente->Name = S"edtCliente";
    this->edtCliente->Size = System::Drawing::Size(304, 20);
    this->edtCliente->TabIndex = 5;
    this->edtCliente->Text = S"";
    // 
    // btnPLivro
    // 
    this->btnPLivro->Location = System::Drawing::Point(448, 104);
    this->btnPLivro->Name = S"btnPLivro";
    this->btnPLivro->Size = System::Drawing::Size(22, 20);
    this->btnPLivro->TabIndex = 12;
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
    this->edtLivro->TabIndex = 10;
    this->edtLivro->Text = S"";
    // 
    // edtISBN
    // 
    this->edtISBN->Location = System::Drawing::Point(8, 104);
    this->edtISBN->MaxLength = 13;
    this->edtISBN->Name = S"edtISBN";
    this->edtISBN->Size = System::Drawing::Size(128, 20);
    this->edtISBN->TabIndex = 8;
    this->edtISBN->Text = S"";
    this->edtISBN->Leave += new System::EventHandler(this,edtISBN_Leave);
    // 
    // labISBN
    // 
    this->labISBN->Location = System::Drawing::Point(8, 88);
    this->labISBN->Name = S"labISBN";
    this->labISBN->Size = System::Drawing::Size(52, 16);
    this->labISBN->TabIndex = 7;
    this->labISBN->Text = S"ISBN:";
    // 
    // labCLiente
    // 
    this->labCLiente->Location = System::Drawing::Point(144, 48);
    this->labCLiente->Name = S"labCLiente";
    this->labCLiente->Size = System::Drawing::Size(52, 16);
    this->labCLiente->TabIndex = 4;
    this->labCLiente->Text = S"Cliente:";
    // 
    // edtCPF
    // 
    this->edtCPF->Location = System::Drawing::Point(8, 64);
    this->edtCPF->MaxLength = 14;
    this->edtCPF->Name = S"edtCPF";
    this->edtCPF->Size = System::Drawing::Size(128, 20);
    this->edtCPF->TabIndex = 3;
    this->edtCPF->Text = S"";
    this->edtCPF->Leave += new System::EventHandler(this,edtCPF_Leave);
    // 
    // labCPF
    // 
    this->labCPF->Location = System::Drawing::Point(8, 48);
    this->labCPF->Name = S"lbCPF";
    this->labCPF->Size = System::Drawing::Size(52, 16);
    this->labCPF->TabIndex = 2;
    this->labCPF->Text = S"CPF:";
    // 
    // btnAdLivros
    // 
    this->btnAdLivros->Location = System::Drawing::Point(424, 104);
    this->btnAdLivros->Name = S"btnAdLivros";
    this->btnAdLivros->Size = System::Drawing::Size(22, 20);
    this->btnAdLivros->TabIndex = 11;
    this->btnAdLivros->Text = S"+";
    this->btnAdLivros->Click += new System::EventHandler(this,btnAdLivros_Click);
    // 
    // edtPrecoTotal
    // 
    this->edtPrecoTotal->Enabled = false;
    this->edtPrecoTotal->Location = System::Drawing::Point(344, 256);
    this->edtPrecoTotal->MaxLength = 10;
    this->edtPrecoTotal->Name = S"edtPrecoTotal";
    this->edtPrecoTotal->Size = System::Drawing::Size(128, 20);
    this->edtPrecoTotal->TabIndex = 16;
    this->edtPrecoTotal->Text = S"";
    // 
    // labPrecoTotal
    // 
    this->labPrecoTotal->Location = System::Drawing::Point(272, 256);
    this->labPrecoTotal->Name = S"labPrecoTotal";
    this->labPrecoTotal->Size = System::Drawing::Size(64, 16);
    this->labPrecoTotal->TabIndex = 15;
    this->labPrecoTotal->Text = S"Preço total:";
    // 
    // btnVender
    // 
    this->btnVender->Location = System::Drawing::Point(240, 288);
    this->btnVender->Name = S"btnVender";
    this->btnVender->TabIndex = 17;
    this->btnVender->Text = S"&Vender";
    this->btnVender->Click += new System::EventHandler(this,btnVender_Click);
    // 
    // btnLimpar
    // 
    this->btnLimpar->Location = System::Drawing::Point(320, 288);
    this->btnLimpar->Name = S"btnLimpar";
    this->btnLimpar->TabIndex = 18;
    this->btnLimpar->Text = S"&Limpar";
    this->btnLimpar->Click += new System::EventHandler(this,btnLimpar_Click);
    // 
    // btnFechar
    // 
    this->btnFechar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
    this->btnFechar->Location = System::Drawing::Point(400, 288);
    this->btnFechar->Name = S"btnFechar";
    this->btnFechar->TabIndex = 19;
    this->btnFechar->Text = S"&Fechar";
    this->btnFechar->Click += new System::EventHandler(this,btnFechar_Click);
    // 
    // frmVenderLivros
    // 
    this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
    this->ClientSize = System::Drawing::Size(480, 317);
    this->Controls->Add(this->btnVender);
    this->Controls->Add(this->btnLimpar);
    this->Controls->Add(this->btnFechar);
    this->Controls->Add(this->edtPrecoTotal);
    this->Controls->Add(this->edtCPF);
    this->Controls->Add(this->edtCliente);
    this->Controls->Add(this->edtLivro);
    this->Controls->Add(this->edtISBN);
    this->Controls->Add(this->edtDtHrVenda);
    this->Controls->Add(this->labPrecoTotal);
    this->Controls->Add(this->btnAdLivros);
    this->Controls->Add(this->labCPF);
    this->Controls->Add(this->labLivro);
    this->Controls->Add(this->btnPCliente);
    this->Controls->Add(this->btnPLivro);
    this->Controls->Add(this->labISBN);
    this->Controls->Add(this->labCLiente);
    this->Controls->Add(this->lstLivros);
    this->Controls->Add(this->labLivrosVender);
    this->Controls->Add(this->labDtHrVenda);
    this->Name = S"frmVenderLivros";
    this->Text = S"Vender Livros";
    this->Closing += new System::ComponentModel::CancelEventHandler(this,frmVenderLivros_Closing);
    this->Load += new System::EventHandler(this,frmVenderLivros_Load);
    this->MouseMove += new System::Windows::Forms::MouseEventHandler(this,frmVenderLivros_MouseMove);
    this->ResumeLayout(false);
  }
  
  Void frmVenderLivros::LimpaDados() {
  	edtDtHrVenda->Text=DateTime::Now.ToString(S"dd/MM/yyyy hh:mm:ss");
  	edtCPF->Clear();
  	edtCliente->Clear();
  	edtISBN->Clear();
  	edtLivro->Clear();
  	lstLivros->Items->Clear();
  	slPrecos->Clear();
  	nPrecoTotal=0;
  	edtPrecoTotal->Text=S"R$ 0,00";
  	edtCPF->Focus();
  }

  Boolean frmVenderLivros::ValidaDados()
  {
  	if (RotinasGlobais::Rotinas->ValidaCampo(edtCPF->Text,
  			S"CPF não informado!"))
  	  return false;
  	if (lstLivros->Items->Count == 0){
  	  MessageBox::Show(this,S"Livro(s) para vender não informado(s)!",
  	  frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  	  MessageBoxIcon::Error);
  	  return false;
  	}
  	return true;
  }

  Boolean frmVenderLivros::SalvaLista() {
    int nCont, nQtdEstoque;
    try {  
  	for (nCont=0; nCont <= lstLivros->Items->Count-1; nCont++) {
  	 RotinasGlobais::Rotinas->ConsultaDados(Arquiva,
  	 ConsultasSQL::ConsSQL->Venda('I',slISBNs->Item[nCont]->ToString(),
  	 edtCPF->Text,RotinasGlobais::Rotinas->FormataDataStr(
  	 edtDtHrVenda->Text,S"MM/dd/yyyy hh:mm:ss"),RotinasGlobais::Rotinas->
  	 VirgulaParaPonto(Convert::ToString(nPrecoTotal),false),S""));
  
  	 nQtdEstoque=Int32::Parse(slQtdEstoque->Item[nCont]->ToString());
  	 nQtdEstoque=nQtdEstoque-1;
  	 RotinasGlobais::Rotinas->ConsultaDados(Arquiva,
  	 ConsultasSQL::ConsSQL->Venda('U',slISBNs->Item[nCont]->ToString(),
  	 S"",S"",S"", Convert::ToString(nQtdEstoque)));
  	}
      return true;
    } catch(Exception* e) {
      MessageBox::Show(this,e->Message,frmPrincipal::fPrincipal->Text, 
      MessageBoxButtons::OK, MessageBoxIcon::Error);
      return false;
    }
  }

  Void frmVenderLivros::edtCPF_Leave(Object* sender, System::EventArgs* e)
  {
  	if (edtCPF->Text->Equals(S"")==false) {
  	  if (RotinasGlobais::Rotinas->ValidaCPF(edtCPF->Text)) {
    		  edtCliente->Text =
  		  RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo,
  		  ConsultasSQL::ConsSQL->Cliente('S',edtCPF->Text,
  		  S"",S"",S"",S"",S"",S"",S"",S"",S""),S"Cliente não encontrado!");
  		  if (edtCliente->Text->Equals(S"")) {
  			edtCPF->Clear();
  			edtCPF->Focus();
  		  }
  	  } else {
  		  MessageBox::Show(this,S"CPF inválido!",
  		  frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  		  MessageBoxIcon::Error);
  		  edtCPF->Clear();
  		  edtCliente->Clear();
  	  }
  	}
  }
  
  Void frmVenderLivros::btnPCliente_Click(Object* sender, System::EventArgs* e)
  {
  	frmConClientes* pfConClientes = new frmConClientes();
  	pfConClientes->ShowDialog();
  	edtCPF->Text=RotinasGlobais::Rotinas->sCodigoSelecionado;
  	edtCPF_Leave(this,System::EventArgs::Empty);
  }

  Void frmVenderLivros::edtISBN_Leave(Object* sender, System::EventArgs* e)
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
  
  Void frmVenderLivros::btnPLivro_Click(Object* sender, System::EventArgs* e)
  {
  	frmConLivros* pfConLivros = new frmConLivros();
  	pfConLivros->ShowDialog();
  	edtISBN->Text=RotinasGlobais::Rotinas->sCodigoSelecionado;
  	edtISBN_Leave(this,System::EventArgs::Empty);
  }
  
  Void frmVenderLivros::btnAdLivros_Click(Object* sender, System::EventArgs* e)
  {
     String* sLivros;
  
     if (edtISBN->Text->Equals(S"")==false) {
  	 sLivros=String::Concat(edtISBN->Text,S" - ",edtLivro->Text,S" - R$ ",
  		 RotinasGlobais::Rotinas->sPreco);
  	 if (lstLivros->Items->IndexOf(sLivros)==-1) {
  	   slISBNs->Add(edtISBN->Text);
  	   slPrecos->Add(RotinasGlobais->Rotinas->sPreco);
  	   slQtdEstoque->Add(RotinasGlobais::Rotinas->sQtdEstoque);
  	   lstLivros->Items->Add(sLivros);
  	   nPrecoTotal=nPrecoTotal+
  				Single::Parse(RotinasGlobais::Rotinas->sPreco);
  	 }
  	 edtISBN->Clear();
  	 edtLivro->Clear();
  	 edtPrecoTotal->Text=String::Concat(S"R$ ",RotinasGlobais::Rotinas->VirgulaParaPonto(
  						   Convert::ToString(nPrecoTotal),true));
    }
  }
  
  Void frmVenderLivros::lstLivros_DoubleClick(Object* sender, System::EventArgs* e)
  {
  	float nPreco;
  
  	if (lstLivros->Items->Count > 0) {
  
  	  nPreco=Single::Parse(slPrecos->Item[lstLivros->SelectedIndex]->ToString());
  	  nPrecoTotal=nPrecoTotal-nPreco;
  	  edtPrecoTotal->Text=String::Concat(S"R$ ",Convert::ToString(nPrecoTotal));
  
  	  slISBNs->RemoveAt(lstLivros->SelectedIndex);
  	  slPrecos->RemoveAt(lstLivros->SelectedIndex);
  	  slQtdEstoque->RemoveAt(lstLivros->SelectedIndex);
  	  lstLivros->Items->RemoveAt(lstLivros->SelectedIndex);
  	}
  }
  
  Void frmVenderLivros::btnVender_Click(Object* sender, System::EventArgs* e)
  {
     if (ValidaDados()) {
        if (SalvaLista()) {
	  MessageBox::Show(this,S"Venda realizada com sucesso!",
	  frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
	  MessageBoxIcon::Information);
          LimpaDados();
        }
     }
  }
  
  Void frmVenderLivros::btnLimpar_Click(Object* sender, System::EventArgs* e)
  {
  	 LimpaDados();
  }
  
  Void frmVenderLivros::btnFechar_Click(Object* sender, System::EventArgs* e)
  {	
  	frmVenderLivros_Closing(this,new CancelEventArgs());
  	Close();
  }
  
  Void frmVenderLivros::frmVenderLivros_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	frmPrincipal::fPrincipal->tlbVender->Enabled=true;
  	frmPrincipal::fPrincipal->mnuVenderLivros->Enabled=true;
  	frmPrincipal::fPrincipal->statusBar1->Panels->Item[1]->Text=S"";
  }
  
  Void frmVenderLivros::frmVenderLivros_Load(Object* sender, System::EventArgs* e)
  {
  	nPrecoTotal=0;
  	edtDtHrVenda->Text=DateTime::Now.ToString(S"dd/MM/yyyy hh:mm:ss");
  }
  
  Void frmVenderLivros::frmVenderLivros_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e)
  {
  	frmPrincipal::fPrincipal->statusBar1->Panels->Item[1]->Text=Text;
  }
  

}
