#include "StdAfx.h"
#include "Cadastros.h"
#include "CadClientes.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "Consultas.h"
#include "ConEnderecos.h"
#include "ConPaises.h"
#include "ConProfissoes.h"

namespace Livrus
{
  frmCadClientes::frmCadClientes()
  {
  	//
  	// Required for Windows Form Designer support
  	//
  	InitializeComponent();
  
  	//
  	// TODO: Add any constructor code after InitializeComponent call
  	//
        ConsCampo = new ArrayList();
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmCadClientes::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmCadClientes::InitializeComponent()
  {
    this->labEmail = new System::Windows::Forms::Label();
    this->edtEmail = new System::Windows::Forms::TextBox();
    this->edtIdentidade = new System::Windows::Forms::TextBox();
    this->labIdentidade = new System::Windows::Forms::Label();
    this->rdgSexo = new System::Windows::Forms::GroupBox();
    this->rbFeminino = new System::Windows::Forms::RadioButton();
    this->rbMasculino = new System::Windows::Forms::RadioButton();
    this->edtTelefone = new System::Windows::Forms::TextBox();
    this->labTelefone = new System::Windows::Forms::Label();
    this->edtDtNascimento = new System::Windows::Forms::DateTimePicker();
    this->labDtNascimento = new System::Windows::Forms::Label();
    this->grpEndereco = new System::Windows::Forms::GroupBox();
    this->edtEstado = new System::Windows::Forms::TextBox();
    this->labEstado = new System::Windows::Forms::Label();
    this->edtCidade = new System::Windows::Forms::TextBox();
    this->labCidade = new System::Windows::Forms::Label();
    this->edtCEP = new System::Windows::Forms::TextBox();
    this->labCEP = new System::Windows::Forms::Label();
    this->edtBairro = new System::Windows::Forms::TextBox();
    this->labBairro = new System::Windows::Forms::Label();
    this->edtLogradouro = new System::Windows::Forms::TextBox();
    this->labLogradouro = new System::Windows::Forms::Label();
    this->btnPEndereco = new System::Windows::Forms::Button();
    this->edtCodEndereco = new System::Windows::Forms::TextBox();
    this->edtPais = new System::Windows::Forms::TextBox();
    this->edtCodPais = new System::Windows::Forms::TextBox();
    this->labPais = new System::Windows::Forms::Label();
    this->btnPPais = new System::Windows::Forms::Button();
    this->btnPProfissao = new System::Windows::Forms::Button();
    this->edtProfissao = new System::Windows::Forms::TextBox();
    this->edtCodProfissao = new System::Windows::Forms::TextBox();
    this->labProfissao = new System::Windows::Forms::Label();
    this->rdgSexo->SuspendLayout();
    this->grpEndereco->SuspendLayout();
    this->SuspendLayout();
    // 
    // labCodigo
    // 
    this->labCodigo->Name = S"labCodigo";
    this->labCodigo->Text = S"CPF:";
    // 
    // edtCodigo
    // 
    this->edtCodigo->Name = S"edtCodigo";
    this->edtCodigo->MaxLength = 14;
    this->edtCodigo->Leave += new System::EventHandler(this,edtCodigo_Leave);
    // 
    // labDescricao
    // 
    this->labDescricao->Name = S"labDescricao";
    this->labDescricao->Text = S"Nome:";
    // 
    // edtDescricao
    // 
    this->edtDescricao->Name = S"edtDescricao";
    this->edtDescricao->Size = System::Drawing::Size(320, 20);
    // 
    // btnNovo
    // 
    this->btnNovo->Name = S"btnNovo";
    this->btnNovo->Click += new System::EventHandler(this,btnNovo_Click);
    // 
    // btnPesquisar
    // 
    this->btnPesquisar->Location = System::Drawing::Point(440, 8);
    this->btnPesquisar->Name = S"btnPesquisar";
    this->btnPesquisar->TabIndex = 23;
    this->btnPesquisar->Click += new System::EventHandler(this,btnPesquisar_Click);
    // 
    // btnAnterior
    // 
    this->btnAnterior->Location = System::Drawing::Point(440, 40);
    this->btnAnterior->Name = S"btnAnterior";
    this->btnAnterior->TabIndex = 24;
    this->btnAnterior->Click += new System::EventHandler(this,btnAnterior_Click);
    // 
    // btnProximo
    // 
    this->btnProximo->Location = System::Drawing::Point(440, 72);
    this->btnProximo->Name = S"btnProximo";
    this->btnProximo->TabIndex = 25;
    this->btnProximo->Click += new System::EventHandler(this,btnProximo_Click);
    // 
    // btnFechar
    // 
    this->btnFechar->Location = System::Drawing::Point(440, 424);
    this->btnFechar->Name = S"btnFechar";
    this->btnFechar->TabIndex = 29;
    // 
    // btnLimpar
    // 
    this->btnLimpar->Location = System::Drawing::Point(360, 424);
    this->btnLimpar->Name = S"btnLimpar";
    this->btnLimpar->TabIndex = 28;
    this->btnLimpar->Click += new System::EventHandler(this,btnLimpar_Click);
    // 
    // btnExcluir
    // 
    this->btnExcluir->Location = System::Drawing::Point(280, 424);
    this->btnExcluir->Name = S"btnExcluir";
    this->btnExcluir->TabIndex = 27;
    this->btnExcluir->Click += new System::EventHandler(this,btnExcluir_Click);
    // 
    // btnSalvar
    // 
    this->btnSalvar->Location = System::Drawing::Point(200, 424);
    this->btnSalvar->Name = S"btnSalvar";
    this->btnSalvar->TabIndex = 26;
    this->btnSalvar->Click += new System::EventHandler(this,btnSalvar_Click);
    // 
    // labEmail
    // 
    this->labEmail->Location = System::Drawing::Point(8, 88);
    this->labEmail->Name = S"labEmail";
    this->labEmail->Size = System::Drawing::Size(100, 16);
    this->labEmail->TabIndex = 5;
    this->labEmail->Text = S"E-mail:";
    // 
    // edtEmail
    // 
    this->edtEmail->Enabled = false;
    this->edtEmail->Location = System::Drawing::Point(8, 104);
    this->edtEmail->MaxLength = 30;
    this->edtEmail->Name = S"edtEmail";
    this->edtEmail->Size = System::Drawing::Size(320, 20);
    this->edtEmail->TabIndex = 6;
    this->edtEmail->Text = S"";
    // 
    // edtIdentidade
    // 
    this->edtIdentidade->Enabled = false;
    this->edtIdentidade->Location = System::Drawing::Point(336, 104);
    this->edtIdentidade->MaxLength = 10;
    this->edtIdentidade->Name = S"edtIdentidade";
    this->edtIdentidade->Size = System::Drawing::Size(92, 20);
    this->edtIdentidade->TabIndex = 8;
    this->edtIdentidade->Text = S"";
    // 
    // labIdentidade
    // 
    this->labIdentidade->Location = System::Drawing::Point(336, 88);
    this->labIdentidade->Name = S"labIdentidade";
    this->labIdentidade->Size = System::Drawing::Size(68, 16);
    this->labIdentidade->TabIndex = 7;
    this->labIdentidade->Text = S"Identidade:";
    // 
    // rdgSexo
    // 
    this->rdgSexo->Controls->Add(this->rbFeminino);
    this->rdgSexo->Controls->Add(this->rbMasculino);
    this->rdgSexo->Location = System::Drawing::Point(8, 128);
    this->rdgSexo->Name = S"rdgSexo";
    this->rdgSexo->Size = System::Drawing::Size(184, 40);
    this->rdgSexo->TabIndex = 9;
    this->rdgSexo->TabStop = false;
    this->rdgSexo->Text = S"Sexo";
    // 
    // rbFeminino
    // 
    this->rbFeminino->Location = System::Drawing::Point(104, 16);
    this->rbFeminino->Name = S"rbFeminino";
    this->rbFeminino->Size = System::Drawing::Size(72, 16);
    this->rbFeminino->TabIndex = 1;
    this->rbFeminino->Text = S"Feminino";
    // 
    // rbMasculino
    // 
    this->rbMasculino->Enabled = false;
    this->rbMasculino->Location = System::Drawing::Point(16, 16);
    this->rbMasculino->Name = S"rbMasculino";
    this->rbMasculino->Size = System::Drawing::Size(80, 16);
    this->rbMasculino->TabIndex = 0;
    this->rbMasculino->Text = S"Masculino";
    // 
    // edtTelefone
    // 
    this->edtTelefone->Enabled = false;
    this->edtTelefone->Location = System::Drawing::Point(200, 144);
    this->edtTelefone->MaxLength = 17;
    this->edtTelefone->Name = S"edtTelefone";
    this->edtTelefone->Size = System::Drawing::Size(128, 20);
    this->edtTelefone->TabIndex = 11;
    this->edtTelefone->Text = S"";
    // 
    // labTelefone
    // 
    this->labTelefone->Location = System::Drawing::Point(200, 128);
    this->labTelefone->Name = S"labTelefone";
    this->labTelefone->Size = System::Drawing::Size(68, 16);
    this->labTelefone->TabIndex = 10;
    this->labTelefone->Text = S"Telefone:";
    // 
    // edtDtNascimento
    // 
    this->edtDtNascimento->Enabled = false;
    this->edtDtNascimento->Format = System::Windows::Forms::DateTimePickerFormat::Short;
    this->edtDtNascimento->Location = System::Drawing::Point(336, 144);
    this->edtDtNascimento->Name = S"edtDtNascimento";
    this->edtDtNascimento->Size = System::Drawing::Size(96, 20);
    this->edtDtNascimento->TabIndex = 13;
    // 
    // labDtNascimento
    // 
    this->labDtNascimento->Location = System::Drawing::Point(336, 128);
    this->labDtNascimento->Name = S"labDtNascimento";
    this->labDtNascimento->Size = System::Drawing::Size(96, 16);
    this->labDtNascimento->TabIndex = 12;
    this->labDtNascimento->Text = S"Dt. Nascimento:";
    // 
    // grpEndereco
    // 
    this->grpEndereco->Controls->Add(this->edtEstado);
    this->grpEndereco->Controls->Add(this->labEstado);
    this->grpEndereco->Controls->Add(this->edtCidade);
    this->grpEndereco->Controls->Add(this->labCidade);
    this->grpEndereco->Controls->Add(this->edtCEP);
    this->grpEndereco->Controls->Add(this->labCEP);
    this->grpEndereco->Controls->Add(this->edtBairro);
    this->grpEndereco->Controls->Add(this->labBairro);
    this->grpEndereco->Controls->Add(this->edtLogradouro);
    this->grpEndereco->Controls->Add(this->labLogradouro);
    this->grpEndereco->Controls->Add(this->btnPEndereco);
    this->grpEndereco->Controls->Add(this->edtCodEndereco);
    this->grpEndereco->Location = System::Drawing::Point(8, 176);
    this->grpEndereco->Name = S"grpEndereco";
    this->grpEndereco->Size = System::Drawing::Size(424, 152);
    this->grpEndereco->TabIndex = 14;
    this->grpEndereco->TabStop = false;
    this->grpEndereco->Text = S"Endereço";
    // 
    // edtEstado
    // 
    this->edtEstado->Enabled = false;
    this->edtEstado->Location = System::Drawing::Point(280, 120);
    this->edtEstado->MaxLength = 10;
    this->edtEstado->Name = S"edtEstado";
    this->edtEstado->Size = System::Drawing::Size(128, 20);
    this->edtEstado->TabIndex = 11;
    this->edtEstado->Text = S"";
    // 
    // labEstado
    // 
    this->labEstado->Location = System::Drawing::Point(280, 104);
    this->labEstado->Name = S"labEstado";
    this->labEstado->Size = System::Drawing::Size(64, 16);
    this->labEstado->TabIndex = 10;
    this->labEstado->Text = S"Estado:";
    // 
    // edtCidade
    // 
    this->edtCidade->Enabled = false;
    this->edtCidade->Location = System::Drawing::Point(88, 120);
    this->edtCidade->MaxLength = 30;
    this->edtCidade->Name = S"edtCidade";
    this->edtCidade->Size = System::Drawing::Size(184, 20);
    this->edtCidade->TabIndex = 9;
    this->edtCidade->Text = S"";
    // 
    // labCidade
    // 
    this->labCidade->Location = System::Drawing::Point(88, 104);
    this->labCidade->Name = S"labCidade";
    this->labCidade->Size = System::Drawing::Size(64, 16);
    this->labCidade->TabIndex = 8;
    this->labCidade->Text = S"Cidade:";
    // 
    // edtCEP
    // 
    this->edtCEP->Enabled = false;
    this->edtCEP->Location = System::Drawing::Point(8, 120);
    this->edtCEP->MaxLength = 8;
    this->edtCEP->Name = S"edtCEP";
    this->edtCEP->Size = System::Drawing::Size(72, 20);
    this->edtCEP->TabIndex = 7;
    this->edtCEP->Text = S"";
    // 
    // labCEP
    // 
    this->labCEP->Location = System::Drawing::Point(8, 104);
    this->labCEP->Name = S"labCEP";
    this->labCEP->Size = System::Drawing::Size(64, 16);
    this->labCEP->TabIndex = 6;
    this->labCEP->Text = S"CEP:";
    // 
    // edtBairro
    // 
    this->edtBairro->Enabled = false;
    this->edtBairro->Location = System::Drawing::Point(280, 74);
    this->edtBairro->MaxLength = 10;
    this->edtBairro->Name = S"edtBairro";
    this->edtBairro->Size = System::Drawing::Size(128, 20);
    this->edtBairro->TabIndex = 5;
    this->edtBairro->Text = S"";
    // 
    // labBairro
    // 
    this->labBairro->Location = System::Drawing::Point(280, 58);
    this->labBairro->Name = S"labBairro";
    this->labBairro->Size = System::Drawing::Size(68, 16);
    this->labBairro->TabIndex = 4;
    this->labBairro->Text = S"Bairro:";
    // 
    // edtLogradouro
    // 
    this->edtLogradouro->Enabled = false;
    this->edtLogradouro->Location = System::Drawing::Point(8, 74);
    this->edtLogradouro->MaxLength = 30;
    this->edtLogradouro->Name = S"edtLogradouro";
    this->edtLogradouro->Size = System::Drawing::Size(264, 20);
    this->edtLogradouro->TabIndex = 3;
    this->edtLogradouro->Text = S"";
    // 
    // labLogradouro
    // 
    this->labLogradouro->Location = System::Drawing::Point(8, 58);
    this->labLogradouro->Name = S"labLogradouro";
    this->labLogradouro->Size = System::Drawing::Size(78, 16);
    this->labLogradouro->TabIndex = 2;
    this->labLogradouro->Text = S"Logradouro:";
    // 
    // btnPEndereco
    // 
    this->btnPEndereco->Enabled = false;
    this->btnPEndereco->Location = System::Drawing::Point(104, 24);
    this->btnPEndereco->Name = S"btnPEndereco";
    this->btnPEndereco->Size = System::Drawing::Size(22, 20);
    this->btnPEndereco->TabIndex = 1;
    this->btnPEndereco->Text = S"...";
    this->btnPEndereco->Click += new System::EventHandler(this,btnPEndereco_Click);
    // 
    // edtCodEndereco
    // 
    this->edtCodEndereco->Enabled = false;
    this->edtCodEndereco->Location = System::Drawing::Point(8, 24);
    this->edtCodEndereco->MaxLength = 10;
    this->edtCodEndereco->Name = S"edtCodEndereco";
    this->edtCodEndereco->Size = System::Drawing::Size(92, 20);
    this->edtCodEndereco->TabIndex = 0;
    this->edtCodEndereco->Text = S"";
    this->edtCodEndereco->Leave += new System::EventHandler(this,edtCodEndereco_Leave);
    // 
    // edtPais
    // 
    this->edtPais->Enabled = false;
    this->edtPais->Location = System::Drawing::Point(92, 352);
    this->edtPais->MaxLength = 30;
    this->edtPais->Name = S"edtPais";
    this->edtPais->Size = System::Drawing::Size(224, 20);
    this->edtPais->TabIndex = 17;
    this->edtPais->Text = S"";
    // 
    // edtCodPais
    // 
    this->edtCodPais->Enabled = false;
    this->edtCodPais->Location = System::Drawing::Point(8, 352);
    this->edtCodPais->MaxLength = 10;
    this->edtCodPais->Name = S"edtCodPais";
    this->edtCodPais->Size = System::Drawing::Size(80, 20);
    this->edtCodPais->TabIndex = 16;
    this->edtCodPais->Text = S"";
    this->edtCodPais->Leave += new System::EventHandler(this,edtCodPais_Leave);
    // 
    // labPais
    // 
    this->labPais->Location = System::Drawing::Point(8, 336);
    this->labPais->Name = S"labPais";
    this->labPais->Size = System::Drawing::Size(88, 16);
    this->labPais->TabIndex = 15;
    this->labPais->Text = S"País de origem:";
    // 
    // btnPPais
    // 
    this->btnPPais->Enabled = false;
    this->btnPPais->Location = System::Drawing::Point(320, 352);
    this->btnPPais->Name = S"btnPPais";
    this->btnPPais->Size = System::Drawing::Size(22, 20);
    this->btnPPais->TabIndex = 18;
    this->btnPPais->Text = S"...";
    this->btnPPais->Click += new System::EventHandler(this,btnPPais_Click);
    // 
    // btnPProfissao
    // 
    this->btnPProfissao->Enabled = false;
    this->btnPProfissao->Location = System::Drawing::Point(320, 392);
    this->btnPProfissao->Name = S"btnPProfissao";
    this->btnPProfissao->Size = System::Drawing::Size(22, 20);
    this->btnPProfissao->TabIndex = 22;
    this->btnPProfissao->Text = S"...";
    this->btnPProfissao->Click += new System::EventHandler(this,btnPProfissao_Click);
    // 
    // edtProfissao
    // 
    this->edtProfissao->Enabled = false;
    this->edtProfissao->Location = System::Drawing::Point(96, 392);
    this->edtProfissao->MaxLength = 30;
    this->edtProfissao->Name = S"edtProfissao";
    this->edtProfissao->Size = System::Drawing::Size(224, 20);
    this->edtProfissao->TabIndex = 21;
    this->edtProfissao->Text = S"";
    // 
    // edtCodProfissao
    // 
    this->edtCodProfissao->Enabled = false;
    this->edtCodProfissao->Location = System::Drawing::Point(8, 392);
    this->edtCodProfissao->MaxLength = 10;
    this->edtCodProfissao->Name = S"edtCodProfissao";
    this->edtCodProfissao->Size = System::Drawing::Size(80, 20);
    this->edtCodProfissao->TabIndex = 20;
    this->edtCodProfissao->Text = S"";
    this->edtCodProfissao->Leave += new System::EventHandler(this,edtCodProfissao_Leave);
    // 
    // labProfissao
    // 
    this->labProfissao->Location = System::Drawing::Point(8, 376);
    this->labProfissao->Name = S"labProfissao";
    this->labProfissao->Size = System::Drawing::Size(88, 16);
    this->labProfissao->TabIndex = 19;
    this->labProfissao->Text = S"Profissão:";
    // 
    // frmCadClientes
    // 
    this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
    this->ClientSize = System::Drawing::Size(520, 453);
    this->Controls->Add(this->btnPProfissao);
    this->Controls->Add(this->edtProfissao);
    this->Controls->Add(this->edtCodProfissao);
    this->Controls->Add(this->labProfissao);
    this->Controls->Add(this->btnPPais);
    this->Controls->Add(this->edtPais);
    this->Controls->Add(this->edtCodPais);
    this->Controls->Add(this->labPais);
    this->Controls->Add(this->grpEndereco);
    this->Controls->Add(this->labDtNascimento);
    this->Controls->Add(this->edtDtNascimento);
    this->Controls->Add(this->edtTelefone);
    this->Controls->Add(this->labTelefone);
    this->Controls->Add(this->rdgSexo);
    this->Controls->Add(this->edtIdentidade);
    this->Controls->Add(this->labIdentidade);
    this->Controls->Add(this->edtEmail);
    this->Controls->Add(this->labEmail);
    this->Name = S"frmCadClientes";
    this->Text = S"Cadastro de Clientes";
    this->Closing += new System::ComponentModel::CancelEventHandler(this,frmCadClientes_Closing);
    this->rdgSexo->ResumeLayout(false);
    this->grpEndereco->ResumeLayout(false);
    this->ResumeLayout(false);
  }
  
  Boolean frmCadClientes::ValidaDados(Boolean bTodosDados)
  {
	__super::ValidaDados(bTodosDados);
  	
	if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Text,
  		S"CPF não informado!"))
  	  return false;
  	if (bTodosDados) {
  	  if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Text,
  		S"Cliente não informado!"))
  		return false;
          if (RotinasGlobais::Rotinas->ValidaCampo(edtEmail->Text,
          	S"E-mail não informado!"))
          	return false;
          if (rbMasculino->Checked==false && rbFeminino->Checked==false){
            MessageBox::Show(this,S"Sexo não informado!",
            frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
            MessageBoxIcon::Error);
            return false;
          }
          if (RotinasGlobais::Rotinas->ValidaCampo(edtTelefone->Text,
          	S"Telefone não informado!"))
          	return false;
          if (RotinasGlobais::Rotinas->ValidaCampo(edtCodEndereco->Text,
          	S"Endereço não informado!"))
          	return false;
          if (RotinasGlobais::Rotinas->ValidaCampo(edtCodPais->Text,
          	S"País não informado!"))
          	return false;
          if (RotinasGlobais::Rotinas->ValidaCampo(edtCodProfissao->Text,
          	S"Profissão não informada!"))
          	return false;
  	}
  	return true;
  }

  Void frmCadClientes::InformaLimpaDados(Boolean bInformar)
  { 
    if (bInformar) {
  	edtEmail->Text=Campos->Item[2]->ToString();
  	edtIdentidade->Text=Campos->Item[3]->ToString();
  	if (Campos->Item[4]->ToString()->Equals("M")) {
  	   rbMasculino->Checked=true;
  	   rbFeminino->Checked=false;
  	} else {
  	  rbMasculino->Checked=false;
  	  rbFeminino->Checked=true;
  	}
  	edtTelefone->Text=Campos->Item[5]->ToString();
  	edtDtNascimento->Text=RotinasGlobais::Rotinas->FormataDataStr(
  						 Campos->Item[6]->ToString(),"dd/MM/yyyy");
  	edtCodEndereco->Text=Campos->Item[7]->ToString();
  	edtLogradouro->Text=Campos->Item[8]->ToString();
  	edtBairro->Text=Campos->Item[9]->ToString();
  	edtCEP->Text=Campos->Item[10]->ToString();
  	edtCidade->Text=Campos->Item[11]->ToString();
  	edtEstado->Text=Campos->Item[12]->ToString();
  	edtCodPais->Text=Campos->Item[13]->ToString();
  	edtPais->Text=Campos->Item[14]->ToString();
  	edtCodProfissao->Text=Campos->Item[15]->ToString();
  	edtProfissao->Text=Campos->Item[16]->ToString();
    } else {
  	edtEmail->Clear();
  	edtIdentidade->Clear();
  	rbMasculino->Checked=false;
  	rbFeminino->Checked=false;
  	edtTelefone->Clear();
  	edtDtNascimento->Value=DateTime::Now;
  	edtCodEndereco->Clear();
  	edtLogradouro->Clear();
  	edtBairro->Clear();
  	edtCEP->Clear();
  	edtCidade->Clear();
  	edtEstado->Clear();
  	edtCodPais->Clear();
  	edtPais->Clear();
  	edtCodProfissao->Clear();
  	edtProfissao->Clear();
    }
  
  }
  
  Void frmCadClientes::HabilitaDados(Boolean bHabilita)
  { 
  	 edtEmail->Enabled=bHabilita;
  	 edtIdentidade->Enabled=bHabilita;
  	 rbMasculino->Enabled=bHabilita;
  	 rbFeminino->Enabled=bHabilita;
  	 edtTelefone->Enabled=bHabilita;
  	 edtDtNascimento->Enabled=bHabilita;
  	 edtCodEndereco->Enabled=bHabilita;
  	 btnPEndereco->Enabled=bHabilita;
  	 edtCodPais->Enabled=bHabilita;
  	 btnPPais->Enabled=bHabilita;
  	 edtCodProfissao->Enabled=bHabilita;
  	 btnPProfissao->Enabled=bHabilita;
  }
   
  Void frmCadClientes::btnNovo_Click(Object* sender, System::EventArgs* e)
  {
  	InformaLimpaDados(false);
  	HabilitaDados(true);
  }
  Void frmCadClientes::btnLimpar_Click(Object* sender, System::EventArgs* e)
  {
  	InformaLimpaDados(false);
  	HabilitaDados(false);
  }  
  Void frmCadClientes::btnExcluir_Click(Object* sender, System::EventArgs* e)
  {
  	if (ExcluirDados(ConsultasSQL::ConsSQL->Cliente('D',edtCodigo->Text,
	S"",S"",S"",S"",S"",S"",S"",S"",S""))) {
          InformaLimpaDados(false);
    	  HabilitaDados(false);
        }
  }
  
  Void frmCadClientes::btnPesquisar_Click(Object* sender, System::EventArgs* e)
  {
  	if (PesquisarDados(ConsultasSQL::ConsSQL->Cliente('S',edtCodigo->Text,
	S"",S"",S"",S"",S"",S"",S"",S"",S""),
  	S"Cliente não encontrado!")) {
          InformaLimpaDados(true);
          HabilitaDados(true);
        }
  }

  Void frmCadClientes::btnAnterior_Click(Object* sender, System::EventArgs* e)
  {        
    InformaLimpaDados(true);
  }
  
  Void frmCadClientes::btnProximo_Click(Object* sender, System::EventArgs* e)
  {
    InformaLimpaDados(true);
  }
  
  Void frmCadClientes::btnSalvar_Click(Object* sender, System::EventArgs* e)
  {
        if (rbMasculino->Checked)
            sSexo=S"M";
        else
            sSexo=S"F";
  
	if (SalvarDados(ConsultasSQL::ConsSQL->Cliente('S',edtCodigo->Text,
	S"",S"",S"",S"",S"",S"",S"",S"",S""),
	ConsultasSQL::ConsSQL->Cliente('U',edtCodigo->Text,edtDescricao->Text,
	edtEmail->Text,edtIdentidade->Text,sSexo,edtTelefone->Text,
	edtDtNascimento->Value.ToString(S"MM/dd/yyyy"),
	edtCodEndereco->Text,edtCodPais->Text,edtCodProfissao->Text),
	ConsultasSQL::ConsSQL->Cliente('I',edtCodigo->Text,edtDescricao->Text,
	edtEmail->Text,edtIdentidade->Text,sSexo,edtTelefone->Text,
	edtDtNascimento->Value.ToString(S"MM/dd/yyyy"),
	edtCodEndereco->Text,edtCodPais->Text,edtCodProfissao->Text),
  	true)) {
          InformaLimpaDados(false);
          HabilitaDados(false);
        }
  }
  
  Void frmCadClientes::frmCadClientes_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	frmPrincipal::fPrincipal->mnuCadClientes->Enabled=true;
 	frmPrincipal::fPrincipal->tlbClientes->Enabled=true;
  }

  Void frmCadClientes::edtCodigo_Leave(Object* sender, System::EventArgs* e)
  {
  	if (edtCodigo->Text->Equals(S"")==false) {
  	  if (RotinasGlobais::Rotinas->ValidaCPF(edtCodigo->Text)==false) {
  		  MessageBox::Show(this,S"CPF inválido!",
  		  frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  		  MessageBoxIcon::Error);
  		  edtCodigo->Clear();
  		  edtCodigo->Focus();
  	  }
  	}
  }
  
  Void frmCadClientes::edtCodEndereco_Leave(Object* sender, System::EventArgs* e)
  {
    if (edtCodEndereco->Text->Equals(S"")==false) {
  	edtLogradouro->Text=
  	RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo,
  	edtCodEndereco->Text,ConsultasSQL::ConsSQL->Endereco('S',
  	edtCodEndereco->Text,S"",S"",S"",S"",S""),S"Endereço não encontrado!");
  	if (edtLogradouro->Text->Equals(S"")==false) {
  	  edtBairro->Text=ConsCampo->Item[2]->ToString();
  	  edtCEP->Text=ConsCampo->Item[3]->ToString();
  	  edtCidade->Text=ConsCampo->Item[4]->ToString();
  	  edtEstado->Text=ConsCampo->Item[5]->ToString();
  	} else {
  	  edtCodEndereco->Focus();
  	  edtLogradouro->Clear();
  	  edtBairro->Clear();
  	  edtCEP->Clear();
  	  edtCidade->Clear();
  	  edtEstado->Clear();
  	}
    } else {
  	  edtLogradouro->Clear();
  	  edtBairro->Clear();
  	  edtCEP->Clear();
  	  edtCidade->Clear();
  	  edtEstado->Clear();
    }
  }
  
  Void frmCadClientes::edtCodPais_Leave(Object* sender, System::EventArgs* e)
  {
  	if (edtCodPais->Text->Equals(S"")==false) {
  	   edtPais->Text=RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo,
  	   ConsultasSQL::ConsSQL->Pais('S',edtCodPais->Text,S""),
  	   S"País não encontrado!");
  	   if (edtPais->Text->Equals(S"")) {
  		 edtCodPais->Clear();
  		 edtCodPais->Focus();
  	   }
  	 } else
  		edtPais->Clear();
  
  }
  
  Void frmCadClientes::edtCodProfissao_Leave(Object* sender, System::EventArgs* e)
  {
    if (edtCodProfissao->Text->Equals(S"")==false) {
     edtProfissao->Text=RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo,
     edtCodProfissao->Text,ConsultasSQL::ConsSQL->Profissao('S',
     edtCodProfissao->Text,S""),S"Profissão não encontrado!");
     if (edtProfissao->Text->Equals(S""))
  	 edtCodProfissao->Focus();
    } else
  	edtProfissao->Clear();
  }
  
  Void frmCadClientes::btnPEndereco_Click(Object* sender, System::EventArgs* e)
  {
  	frmConEnderecos* pfConEnderecos = new frmConEnderecos();
  	pfConEnderecos->ShowDialog();
  	edtCodEndereco->Text=RotinasGlobais::Rotinas->sCodigoSelecionado;
  	edtCodEndereco_Leave(this, System::EventArgs::Empty);
  }
  
  Void frmCadClientes::btnPPais_Click(Object* sender, System::EventArgs* e)
  {
  	frmConPaises* pfConPaises = new frmConPaises();
  	pfConPaises->ShowDialog();
  	edtCodPais->Text=RotinasGlobais::Rotinas->sCodigoSelecionado;
  	edtCodPais_Leave(this,System::EventArgs::Empty);
  }
  
  Void frmCadClientes::btnPProfissao_Click(Object* sender, System::EventArgs* e)
  {
  	frmConProfissoes* pfConProfissoes = new frmConProfissoes();
  	pfConProfissoes->ShowDialog();
  	edtCodProfissao->Text=RotinasGlobais::Rotinas->sCodigoSelecionado;
  	edtCodProfissao_Leave(this,System::EventArgs::Empty);
  }

}
