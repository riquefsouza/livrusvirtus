#include "StdAfx.h"
#include "Cadastros.h"
#include "CadEnderecos.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmCadEnderecos::frmCadEnderecos()
  {
  	//
  	// Required for Windows Form Designer support
  	//
  	InitializeComponent();
  
  	//
  	// TODO: Add any constructor code after InitializeComponent call
  	//
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmCadEnderecos::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmCadEnderecos::InitializeComponent()
  {
    this->labBairro = new System::Windows::Forms::Label();
    this->edtBairro = new System::Windows::Forms::TextBox();
    this->edtCEP = new System::Windows::Forms::TextBox();
    this->labCEP = new System::Windows::Forms::Label();
    this->edtCidade = new System::Windows::Forms::TextBox();
    this->labCidade = new System::Windows::Forms::Label();
    this->labEstado = new System::Windows::Forms::Label();
    this->cmbEstado = new System::Windows::Forms::ComboBox();
    this->SuspendLayout();
    // 
    // labCodigo
    // 
    this->labCodigo->Name = S"labCodigo";
    // 
    // edtCodigo
    // 
    this->edtCodigo->Name = S"edtCodigo";
    this->edtCodigo->Leave += new System::EventHandler(this,edtCodigo_Leave);
    // 
    // labDescricao
    // 
    this->labDescricao->Name = S"labDescricao";
    this->labDescricao->Text = S"Logradouro:";
    // 
    // edtDescricao
    // 
    this->edtDescricao->MaxLength = 40;
    this->edtDescricao->Name = S"edtDescricao";
    this->edtDescricao->Size = System::Drawing::Size(264, 20);
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
    this->btnPesquisar->TabIndex = 13;
    this->btnPesquisar->Click += new System::EventHandler(this,btnPesquisar_Click);
    // 
    // btnAnterior
    // 
    this->btnAnterior->Location = System::Drawing::Point(440, 40);
    this->btnAnterior->Name = S"btnAnterior";
    this->btnAnterior->TabIndex = 14;
    this->btnAnterior->Click += new System::EventHandler(this,btnAnterior_Click);
    // 
    // btnProximo
    // 
    this->btnProximo->Location = System::Drawing::Point(440, 72);
    this->btnProximo->Name = S"btnProximo";
    this->btnProximo->TabIndex = 15;
    this->btnProximo->Click += new System::EventHandler(this,btnProximo_Click);
    // 
    // btnFechar
    // 
    this->btnFechar->Location = System::Drawing::Point(440, 136);
    this->btnFechar->Name = S"btnFechar";
    this->btnFechar->TabIndex = 19;
    // 
    // btnLimpar
    // 
    this->btnLimpar->Location = System::Drawing::Point(360, 136);
    this->btnLimpar->Name = S"btnLimpar";
    this->btnLimpar->TabIndex = 18;
    this->btnLimpar->Click += new System::EventHandler(this,btnLimpar_Click);
    // 
    // btnExcluir
    // 
    this->btnExcluir->Location = System::Drawing::Point(280, 136);
    this->btnExcluir->Name = S"btnExcluir";
    this->btnExcluir->TabIndex = 17;
    this->btnExcluir->Click += new System::EventHandler(this,btnExcluir_Click);
    // 
    // btnSalvar
    // 
    this->btnSalvar->Location = System::Drawing::Point(200, 136);
    this->btnSalvar->Name = S"btnSalvar";
    this->btnSalvar->TabIndex = 16;
    this->btnSalvar->Click += new System::EventHandler(this,btnSalvar_Click);
    // 
    // labBairro
    // 
    this->labBairro->Location = System::Drawing::Point(280, 48);
    this->labBairro->Name = S"labBairro";
    this->labBairro->Size = System::Drawing::Size(64, 16);
    this->labBairro->TabIndex = 5;
    this->labBairro->Text = S"Bairro:";
    // 
    // edtBairro
    // 
    this->edtBairro->Enabled = false;
    this->edtBairro->Location = System::Drawing::Point(280, 64);
    this->edtBairro->MaxLength = 15;
    this->edtBairro->Name = S"edtBairro";
    this->edtBairro->Size = System::Drawing::Size(152, 20);
    this->edtBairro->TabIndex = 6;
    this->edtBairro->Text = S"";
    // 
    // edtCEP
    // 
    this->edtCEP->Enabled = false;
    this->edtCEP->Location = System::Drawing::Point(8, 104);
    this->edtCEP->MaxLength = 8;
    this->edtCEP->Name = S"edtCEP";
    this->edtCEP->Size = System::Drawing::Size(72, 20);
    this->edtCEP->TabIndex = 8;
    this->edtCEP->Text = S"";
    // 
    // labCEP
    // 
    this->labCEP->Location = System::Drawing::Point(8, 88);
    this->labCEP->Name = S"labCEP";
    this->labCEP->Size = System::Drawing::Size(64, 16);
    this->labCEP->TabIndex = 7;
    this->labCEP->Text = S"CEP:";
    // 
    // edtCidade
    // 
    this->edtCidade->Enabled = false;
    this->edtCidade->Location = System::Drawing::Point(88, 104);
    this->edtCidade->MaxLength = 30;
    this->edtCidade->Name = S"edtCidade";
    this->edtCidade->Size = System::Drawing::Size(184, 20);
    this->edtCidade->TabIndex = 10;
    this->edtCidade->Text = S"";
    // 
    // labCidade
    // 
    this->labCidade->Location = System::Drawing::Point(88, 88);
    this->labCidade->Name = S"labCidade";
    this->labCidade->Size = System::Drawing::Size(64, 16);
    this->labCidade->TabIndex = 9;
    this->labCidade->Text = S"Cidade:";
    // 
    // labEstado
    // 
    this->labEstado->Location = System::Drawing::Point(280, 88);
    this->labEstado->Name = S"labEstado";
    this->labEstado->Size = System::Drawing::Size(64, 16);
    this->labEstado->TabIndex = 11;
    this->labEstado->Text = S"Estado:";
    // 
    // cmbEstado
    // 
    this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->cmbEstado->Enabled = false;
    this->cmbEstado->Location = System::Drawing::Point(280, 104);
    this->cmbEstado->Name = S"cmbEstado";
    this->cmbEstado->Size = System::Drawing::Size(152, 21);
    this->cmbEstado->TabIndex = 12;
    // 
    // frmCadEnderecos
    // 
    this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
    this->ClientSize = System::Drawing::Size(520, 165);
    this->Controls->Add(this->cmbEstado);
    this->Controls->Add(this->labEstado);
    this->Controls->Add(this->edtCidade);
    this->Controls->Add(this->labCidade);
    this->Controls->Add(this->edtCEP);
    this->Controls->Add(this->labCEP);
    this->Controls->Add(this->edtBairro);
    this->Controls->Add(this->labBairro);
    this->Name = S"frmCadEnderecos";
    this->Text = S"Cadastro de Endereços";
    this->Closing += new System::ComponentModel::CancelEventHandler(this,frmCadEnderecos_Closing);
    this->Load += new System::EventHandler(this,frmCadEnderecos_Load);
    this->ResumeLayout(false);
  }
  
  Boolean frmCadEnderecos::ValidaDados(Boolean bTodosDados)
  {
	__super::ValidaDados(bTodosDados);
  	
	if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Text,
  		S"Código não informado!"))
  	  return false;
  	if (bTodosDados) {
  	  if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Text,
  		S"Logradouro não informado!"))
  		return false;
	  if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Text,
		S"Logradouro não informado!"))
		return false;
	  if (RotinasGlobais::Rotinas->ValidaCampo(edtBairro->Text,
		S"Bairro não informado!"))
		return false;
	  if (RotinasGlobais::Rotinas->ValidaCampo(edtCEP->Text,
		S"CEP não informado!"))
		return false;
	  if (RotinasGlobais::Rotinas->ValidaCampo(edtCidade->Text,
		S"Cidade não informada!"))
		return false;
  	}
  	return true;
  }
  Void frmCadEnderecos::InformaLimpaDados(Boolean bInformar)
  {        
  	if (bInformar) {
  	  edtBairro->Text=Campos->Item[2]->ToString();
  	  edtCEP->Text=Campos->Item[3]->ToString();
  	  edtCidade->Text=Campos->Item[4]->ToString();
  	  RecuperaEstado(Campos->Item[5]->ToString());
  	} else {
  	  edtBairro->Clear();
  	  edtCEP->Clear();
  	  edtCidade->Clear();
  	  cmbEstado->SelectedIndex=0;
  	}
  }
  
  Void frmCadEnderecos::HabilitaDados(Boolean bHabilita)
  { 
  	edtBairro->Enabled=bHabilita;
  	edtCEP->Enabled=bHabilita;
  	edtCidade->Enabled=bHabilita;
  	cmbEstado->Enabled=bHabilita;
  }  
  Void frmCadEnderecos::btnNovo_Click(Object* sender, System::EventArgs* e)
  {
  	InformaLimpaDados(false);
  	HabilitaDados(true);
  	NovoDado(ConsultasSQL::ConsSQL->Endereco('N',edtCodigo->Text,
	S"",S"",S"",S"",S""));
  }
  Void frmCadEnderecos::btnLimpar_Click(Object* sender, System::EventArgs* e)
  {
  	InformaLimpaDados(false);
  	HabilitaDados(false);
  }  
  Void frmCadEnderecos::btnExcluir_Click(Object* sender, System::EventArgs* e)
  {
  	if (ExcluirDados(ConsultasSQL::ConsSQL->Endereco('D',edtCodigo->Text,
	S"",S"",S"",S"",S""))) {
          InformaLimpaDados(false);
    	  HabilitaDados(false);
        }
  }
  
  Void frmCadEnderecos::btnPesquisar_Click(Object* sender, System::EventArgs* e)
  {
  	if (PesquisarDados(ConsultasSQL::ConsSQL->Endereco('S',edtCodigo->Text,
	S"",S"",S"",S"",S""), S"Endereço não encontrado!")) {
          InformaLimpaDados(true);
          HabilitaDados(true);
        }
  }
  
  Void frmCadEnderecos::btnAnterior_Click(Object* sender, System::EventArgs* e)
  {        
    InformaLimpaDados(true);
  }
  
  Void frmCadEnderecos::btnProximo_Click(Object* sender, System::EventArgs* e)
  {
    InformaLimpaDados(true);
  }

  Void frmCadEnderecos::btnSalvar_Click(Object* sender, System::EventArgs* e)
  {
  	if (SalvarDados(ConsultasSQL::ConsSQL->Endereco('S',edtCodigo->Text,
	S"",S"",S"",S"",S""),
  	ConsultasSQL::ConsSQL->Endereco('U',edtCodigo->Text,edtDescricao->Text,
	edtBairro->Text,edtCEP->Text,edtCidade->Text,cmbEstado->Text),
  	ConsultasSQL::ConsSQL->Endereco('I',edtCodigo->Text,edtDescricao->Text,
	edtBairro->Text,edtCEP->Text,edtCidade->Text,cmbEstado->Text),
  	true)) {
          InformaLimpaDados(false);
          HabilitaDados(false);
        }
  }
  Void frmCadEnderecos::edtCodigo_Leave(Object* sender, System::EventArgs* e)
  {
     edtCodigoLeave();
  }
  
  Void frmCadEnderecos::frmCadEnderecos_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	  frmPrincipal::fPrincipal->mnuCadEnderecos->Enabled=true;
  }
  Void frmCadEnderecos::AdicionaCombo()
  {
  	cmbEstado->Items->Add(S"Pernambuco");
  	cmbEstado->Items->Add(S"Acre");
  	cmbEstado->Items->Add(S"Alagoas");
  	cmbEstado->Items->Add(S"Amapá");
  	cmbEstado->Items->Add(S"Amazonas");
  	cmbEstado->Items->Add(S"Bahia");
  	cmbEstado->Items->Add(S"Brasília");
  	cmbEstado->Items->Add(S"Ceará");
  	cmbEstado->Items->Add(S"Distrito Federal");
  	cmbEstado->Items->Add(S"Espírito Santo");
  	cmbEstado->Items->Add(S"Goiás");
  	cmbEstado->Items->Add(S"Mato Grosso");
  	cmbEstado->Items->Add(S"Mato Grosso do Sul");
  	cmbEstado->Items->Add(S"Minas Gerais");
  	cmbEstado->Items->Add(S"Pará");
  	cmbEstado->Items->Add(S"Paraíba");
  	cmbEstado->Items->Add(S"Paraná");
  	cmbEstado->Items->Add(S"Santa Catarina");
  	cmbEstado->Items->Add(S"Rio Grande do Norte");
  	cmbEstado->Items->Add(S"Rio Grande do Sul");
  	cmbEstado->Items->Add(S"Rio de Janeiro");
  	cmbEstado->Items->Add(S"Rondônia");
  	cmbEstado->Items->Add(S"Roraima");
  	cmbEstado->Items->Add(S"São Paulo");
  	cmbEstado->Items->Add(S"Sergipe");
  	cmbEstado->Items->Add(S"Tocantins");
  }
  
  Void frmCadEnderecos::RecuperaEstado(String* sEstado)
  {
   for (int nCont=0; nCont <= cmbEstado->Items->Count-1; nCont++) {
  	if (cmbEstado->Items->Item[nCont]->Equals(sEstado)) {
  	   cmbEstado->SelectedIndex=nCont;
  	   break;
  	}
   }
  }
  
  Void frmCadEnderecos::frmCadEnderecos_Load(Object* sender, System::EventArgs* e)
  {
  	AdicionaCombo();
  	cmbEstado->SelectedIndex=0;
  }

}
