#include "StdAfx.h"
#include "Cadastros.h"
#include "CadLivros.h"
#include "Consultas.h"
#include "ConEditoras.h"
#include "ConIdiomas.h"
#include "ConAutores.h"
#include "ConAssuntos.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmCadLivros::frmCadLivros()
  {
  	//
  	// Required for Windows Form Designer support
  	//
  	InitializeComponent();
  
  	//
  	// TODO: Add any constructor code after InitializeComponent call
  	//
	slIdiomas = new ArrayList();
	slAssuntos = new ArrayList();
	slAutores = new ArrayList();
	ConsCampo = new ArrayList();
	ConsLista = new ArrayList();
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmCadLivros::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmCadLivros::InitializeComponent()
  {
    this->labEdicao = new System::Windows::Forms::Label();
    this->edtEdicao = new System::Windows::Forms::NumericUpDown();
    this->edtAnoPubli = new System::Windows::Forms::NumericUpDown();
    this->labAnoPubli = new System::Windows::Forms::Label();
    this->btnPAssunto = new System::Windows::Forms::Button();
    this->edtAssunto = new System::Windows::Forms::TextBox();
    this->edtCodAssunto = new System::Windows::Forms::TextBox();
    this->labAssunto = new System::Windows::Forms::Label();
    this->btnPEditora = new System::Windows::Forms::Button();
    this->edtEditora = new System::Windows::Forms::TextBox();
    this->edtCodEditora = new System::Windows::Forms::TextBox();
    this->labEditora = new System::Windows::Forms::Label();
    this->btnAdAssuntos = new System::Windows::Forms::Button();
    this->edtVolume = new System::Windows::Forms::NumericUpDown();
    this->labVolume = new System::Windows::Forms::Label();
    this->edtNPaginas = new System::Windows::Forms::NumericUpDown();
    this->labNPaginas = new System::Windows::Forms::Label();
    this->labIdioma = new System::Windows::Forms::Label();
    this->cmbIdioma = new System::Windows::Forms::ComboBox();
    this->lstAssuntos = new System::Windows::Forms::ListBox();
    this->labPreco = new System::Windows::Forms::Label();
    this->edtPreco = new System::Windows::Forms::TextBox();
    this->edtQtdEstoque = new System::Windows::Forms::NumericUpDown();
    this->labQtdEstoque = new System::Windows::Forms::Label();
    this->lstAutores = new System::Windows::Forms::ListBox();
    this->btnAdAutores = new System::Windows::Forms::Button();
    this->btnPAutor = new System::Windows::Forms::Button();
    this->edtAutor = new System::Windows::Forms::TextBox();
    this->edtCodAutor = new System::Windows::Forms::TextBox();
    this->labAutor = new System::Windows::Forms::Label();
    (dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->edtEdicao))->BeginInit();
    (dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->edtAnoPubli))->BeginInit();
    (dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->edtVolume))->BeginInit();
    (dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->edtNPaginas))->BeginInit();
    (dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->edtQtdEstoque))->BeginInit();
    this->SuspendLayout();
    // 
    // labCodigo
    // 
    this->labCodigo->Name = S"labCodigo";
    this->labCodigo->Text = S"ISBN:";
    // 
    // edtCodigo
    // 
    this->edtCodigo->Name = S"edtCodigo";
    this->edtCodigo->MaxLength = 13;
    this->edtCodigo->Leave += new System::EventHandler(this,edtCodigo_Leave);
    // 
    // labDescricao
    // 
    this->labDescricao->Name = S"labDescricao";
    this->labDescricao->Text = S"Título:";
    // 
    // edtDescricao
    // 
    this->edtDescricao->Name = S"edtDescricao";
    this->edtDescricao->Size = System::Drawing::Size(304, 20);
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
    this->btnPesquisar->TabIndex = 35;
    this->btnPesquisar->Click += new System::EventHandler(this,btnPesquisar_Click);
    // 
    // btnAnterior
    // 
    this->btnAnterior->Location = System::Drawing::Point(440, 40);
    this->btnAnterior->Name = S"btnAnterior";
    this->btnAnterior->TabIndex = 36;
    this->btnAnterior->Click += new System::EventHandler(this,btnAnterior_Click);
    // 
    // btnProximo
    // 
    this->btnProximo->Location = System::Drawing::Point(440, 72);
    this->btnProximo->Name = S"btnProximo";
    this->btnProximo->TabIndex = 37;
    this->btnProximo->Click += new System::EventHandler(this,btnProximo_Click);
    // 
    // btnFechar
    // 
    this->btnFechar->Location = System::Drawing::Point(440, 352);
    this->btnFechar->Name = S"btnFechar";
    this->btnFechar->TabIndex = 41;
    this->btnFechar->Click += new System::EventHandler(this,btnFechar_Click);
    // 
    // btnLimpar
    // 
    this->btnLimpar->Location = System::Drawing::Point(360, 352);
    this->btnLimpar->Name = S"btnLimpar";
    this->btnLimpar->TabIndex = 40;
    this->btnLimpar->Click += new System::EventHandler(this,btnLimpar_Click);
    // 
    // btnExcluir
    // 
    this->btnExcluir->Location = System::Drawing::Point(280, 352);
    this->btnExcluir->Name = S"btnExcluir";
    this->btnExcluir->TabIndex = 39;
    this->btnExcluir->Click += new System::EventHandler(this,btnExcluir_Click);
    // 
    // btnSalvar
    // 
    this->btnSalvar->Location = System::Drawing::Point(200, 352);
    this->btnSalvar->Name = S"btnSalvar";
    this->btnSalvar->TabIndex = 38;
    this->btnSalvar->Click += new System::EventHandler(this,btnSalvar_Click);
    // 
    // labEdicao
    // 
    this->labEdicao->Location = System::Drawing::Point(320, 48);
    this->labEdicao->Name = S"labEdicao";
    this->labEdicao->Size = System::Drawing::Size(48, 16);
    this->labEdicao->TabIndex = 5;
    this->labEdicao->Text = S"Edição";
    // 
    // edtEdicao
    // 
    this->edtEdicao->Enabled = false;
    this->edtEdicao->Location = System::Drawing::Point(320, 64);
    Int32 nEd1[] = new Int32[4];
    nEd1[0] = 9999;
    nEd1[1] = 0;
    nEd1[2] = 0;
    nEd1[3] = 0;
    this->edtEdicao->Maximum = Decimal(nEd1);
    Int32 nEd2[] = new Int32[4];
    nEd2[0] = 1;
    nEd2[1] = 0;
    nEd2[2] = 0;
    nEd2[3] = 0;
    this->edtEdicao->Minimum = Decimal(nEd2);
    this->edtEdicao->Name = S"edtEdicao";
    this->edtEdicao->Size = System::Drawing::Size(104, 20);
    this->edtEdicao->TabIndex = 6;
    Int32 nEd3[] = new Int32[4];
    nEd3[0] = 1;
    nEd3[1] = 0;
    nEd3[2] = 0;
    nEd3[3] = 0;
    this->edtEdicao->Value = Decimal(nEd3);
    // 
    // edtAnoPubli
    // 
    this->edtAnoPubli->Enabled = false;
    this->edtAnoPubli->Location = System::Drawing::Point(8, 104);
    Int32 nAno1[] = new Int32[4];
    nAno1[0] = 9999;
    nAno1[1] = 0;
    nAno1[2] = 0;
    nAno1[3] = 0;
    this->edtAnoPubli->Maximum = Decimal(nAno1);
    Int32 nAno2[] = new Int32[4];
    nAno2[0] = 1;
    nAno2[1] = 0;
    nAno2[2] = 0;
    nAno2[3] = 0;
    this->edtAnoPubli->Minimum = Decimal(nAno2);
    this->edtAnoPubli->Name = S"edtAnoPubli";
    this->edtAnoPubli->Size = System::Drawing::Size(88, 20);
    this->edtAnoPubli->TabIndex = 8;
    Int32 nAno3[] = new Int32[4];
    nAno3[0] = 2004;
    nAno3[1] = 0;
    nAno3[2] = 0;
    nAno3[3] = 0;
    this->edtAnoPubli->Value = Decimal(nAno3);
    // 
    // labAnoPubli
    // 
    this->labAnoPubli->Location = System::Drawing::Point(8, 88);
    this->labAnoPubli->Name = S"labAnoPubli";
    this->labAnoPubli->Size = System::Drawing::Size(88, 16);
    this->labAnoPubli->TabIndex = 7;
    this->labAnoPubli->Text = S"Ano Publicação:";
    // 
    // btnPAssunto
    // 
    this->btnPAssunto->Enabled = false;
    this->btnPAssunto->Location = System::Drawing::Point(408, 184);
    this->btnPAssunto->Name = S"btnPAssunto";
    this->btnPAssunto->Size = System::Drawing::Size(22, 20);
    this->btnPAssunto->TabIndex = 23;
    this->btnPAssunto->Text = S"...";
    this->btnPAssunto->Click += new System::EventHandler(this,btnPAssunto_Click);
    // 
    // edtAssunto
    // 
    this->edtAssunto->Enabled = false;
    this->edtAssunto->Location = System::Drawing::Point(184, 184);
    this->edtAssunto->MaxLength = 30;
    this->edtAssunto->Name = S"edtAssunto";
    this->edtAssunto->Size = System::Drawing::Size(200, 20);
    this->edtAssunto->TabIndex = 21;
    this->edtAssunto->Text = S"";
    // 
    // edtCodAssunto
    // 
    this->edtCodAssunto->Enabled = false;
    this->edtCodAssunto->Location = System::Drawing::Point(100, 184);
    this->edtCodAssunto->MaxLength = 10;
    this->edtCodAssunto->Name = S"edtCodAssunto";
    this->edtCodAssunto->Size = System::Drawing::Size(80, 20);
    this->edtCodAssunto->TabIndex = 20;
    this->edtCodAssunto->Text = S"";
    this->edtCodAssunto->Leave += new System::EventHandler(this,edtCodAssunto_Leave);
    // 
    // labAssunto
    // 
    this->labAssunto->Location = System::Drawing::Point(100, 168);
    this->labAssunto->Name = S"labAssunto";
    this->labAssunto->Size = System::Drawing::Size(68, 16);
    this->labAssunto->TabIndex = 19;
    this->labAssunto->Text = S"Assunto:";
    // 
    // btnPEditora
    // 
    this->btnPEditora->Enabled = false;
    this->btnPEditora->Location = System::Drawing::Point(400, 104);
    this->btnPEditora->Name = S"btnPEditora";
    this->btnPEditora->Size = System::Drawing::Size(22, 20);
    this->btnPEditora->TabIndex = 12;
    this->btnPEditora->Text = S"...";
    this->btnPEditora->Click += new System::EventHandler(this,btnPEditora_Click);
    // 
    // edtEditora
    // 
    this->edtEditora->Enabled = false;
    this->edtEditora->Location = System::Drawing::Point(184, 104);
    this->edtEditora->MaxLength = 30;
    this->edtEditora->Name = S"edtEditora";
    this->edtEditora->Size = System::Drawing::Size(216, 20);
    this->edtEditora->TabIndex = 11;
    this->edtEditora->Text = S"";
    // 
    // edtCodEditora
    // 
    this->edtCodEditora->Enabled = false;
    this->edtCodEditora->Location = System::Drawing::Point(100, 104);
    this->edtCodEditora->MaxLength = 10;
    this->edtCodEditora->Name = S"edtCodEditora";
    this->edtCodEditora->Size = System::Drawing::Size(80, 20);
    this->edtCodEditora->TabIndex = 10;
    this->edtCodEditora->Text = S"";
    this->edtCodEditora->Leave += new System::EventHandler(this,edtCodEditora_Leave);
    // 
    // labEditora
    // 
    this->labEditora->Location = System::Drawing::Point(100, 88);
    this->labEditora->Name = S"labEditora";
    this->labEditora->Size = System::Drawing::Size(52, 16);
    this->labEditora->TabIndex = 9;
    this->labEditora->Text = S"Editora:";
    // 
    // btnAdAssuntos
    // 
    this->btnAdAssuntos->Enabled = false;
    this->btnAdAssuntos->Location = System::Drawing::Point(384, 184);
    this->btnAdAssuntos->Name = S"btnAdAssuntos";
    this->btnAdAssuntos->Size = System::Drawing::Size(22, 20);
    this->btnAdAssuntos->TabIndex = 22;
    this->btnAdAssuntos->Text = S"+";
    this->btnAdAssuntos->Click += new System::EventHandler(this,btnAdAssuntos_Click);
    // 
    // edtVolume
    // 
    this->edtVolume->Enabled = false;
    this->edtVolume->Location = System::Drawing::Point(8, 144);
    Int32 nVol1[] = new Int32[4];
    nVol1[0] = 9999;
    nVol1[1] = 0;
    nVol1[2] = 0;
    nVol1[3] = 0;
    this->edtVolume->Maximum = Decimal(nVol1);
    Int32 nVol2[] = new Int32[4];
    nVol2[0] = 1;
    nVol2[1] = 0;
    nVol2[2] = 0;
    nVol2[3] = 0;
    this->edtVolume->Minimum = Decimal(nVol2);
    this->edtVolume->Name = S"edtVolume";
    this->edtVolume->Size = System::Drawing::Size(88, 20);
    this->edtVolume->TabIndex = 14;
    Int32 nVol3[] = new Int32[4];
    nVol3[0] = 1;
    nVol3[1] = 0;
    nVol3[2] = 0;
    nVol3[3] = 0;
    this->edtVolume->Value = Decimal(nVol3);
    // 
    // labVolume
    // 
    this->labVolume->Location = System::Drawing::Point(8, 128);
    this->labVolume->Name = S"labVolume";
    this->labVolume->Size = System::Drawing::Size(56, 16);
    this->labVolume->TabIndex = 13;
    this->labVolume->Text = S"Volume:";
    // 
    // edtNPaginas
    // 
    this->edtNPaginas->Enabled = false;
    this->edtNPaginas->Location = System::Drawing::Point(8, 184);
    Int32 nPg1[] = new Int32[4];
    nPg1[0] = 9999;
    nPg1[1] = 0;
    nPg1[2] = 0;
    nPg1[3] = 0;
    this->edtNPaginas->Maximum = Decimal(nPg1);
    Int32 nPg2[] = new Int32[4];
    nPg2[0] = 1;
    nPg2[1] = 0;
    nPg2[2] = 0;
    nPg2[3] = 0;
    this->edtNPaginas->Minimum = Decimal(nPg2);
    this->edtNPaginas->Name = S"edtNPaginas";
    this->edtNPaginas->Size = System::Drawing::Size(88, 20);
    this->edtNPaginas->TabIndex = 18;
    Int32 nPg3[] = new Int32[4];
    nPg3[0] = 1;
    nPg3[1] = 0;
    nPg3[2] = 0;
    nPg3[3] = 0;
    this->edtNPaginas->Value = Decimal(nPg3);
    // 
    // labNPaginas
    // 
    this->labNPaginas->Location = System::Drawing::Point(8, 168);
    this->labNPaginas->Name = S"labNPaginas";
    this->labNPaginas->Size = System::Drawing::Size(64, 16);
    this->labNPaginas->TabIndex = 17;
    this->labNPaginas->Text = S"Nº Páginas:";
    // 
    // labIdioma
    // 
    this->labIdioma->Location = System::Drawing::Point(100, 128);
    this->labIdioma->Name = S"labIdioma";
    this->labIdioma->Size = System::Drawing::Size(60, 16);
    this->labIdioma->TabIndex = 15;
    this->labIdioma->Text = S"Idioma:";
    // 
    // cmbIdioma
    // 
    this->cmbIdioma->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->cmbIdioma->Enabled = false;
    this->cmbIdioma->Location = System::Drawing::Point(100, 144);
    this->cmbIdioma->Name = S"cmbIdioma";
    this->cmbIdioma->Size = System::Drawing::Size(328, 21);
    this->cmbIdioma->TabIndex = 16;
    // 
    // lstAssuntos
    // 
    this->lstAssuntos->Enabled = false;
    this->lstAssuntos->Location = System::Drawing::Point(100, 208);
    this->lstAssuntos->Name = S"lstAssuntos";
    this->lstAssuntos->Size = System::Drawing::Size(332, 43);
    this->lstAssuntos->TabIndex = 24;
    this->lstAssuntos->DoubleClick += new System::EventHandler(this,lstAssuntos_DoubleClick);
    // 
    // labPreco
    // 
    this->labPreco->Location = System::Drawing::Point(8, 212);
    this->labPreco->Name = S"labPreco";
    this->labPreco->Size = System::Drawing::Size(64, 16);
    this->labPreco->TabIndex = 25;
    this->labPreco->Text = S"Preço:";
    // 
    // edtPreco
    // 
    this->edtPreco->Enabled = false;
    this->edtPreco->Location = System::Drawing::Point(8, 231);
    this->edtPreco->Name = S"edtPreco";
    this->edtPreco->Size = System::Drawing::Size(88, 20);
    this->edtPreco->TabIndex = 26;
    this->edtPreco->Text = S"";
    this->edtPreco->Leave += new System::EventHandler(this,edtPreco_Leave);
    // 
    // edtQtdEstoque
    // 
    this->edtQtdEstoque->Enabled = false;
    this->edtQtdEstoque->Location = System::Drawing::Point(8, 272);
    Int32 nQe1[] = new Int32[4];
    nQe1[0] = 9999;
    nQe1[1] = 0;
    nQe1[2] = 0;
    nQe1[3] = 0;
    this->edtQtdEstoque->Maximum = Decimal(nQe1);
    this->edtQtdEstoque->Name = S"edtQtdEstoque";
    this->edtQtdEstoque->Size = System::Drawing::Size(88, 20);
    this->edtQtdEstoque->TabIndex = 28;
    // 
    // labQtdEstoque
    // 
    this->labQtdEstoque->Location = System::Drawing::Point(8, 256);
    this->labQtdEstoque->Name = S"labQtdEstoque";
    this->labQtdEstoque->Size = System::Drawing::Size(80, 16);
    this->labQtdEstoque->TabIndex = 27;
    this->labQtdEstoque->Text = S"Qtd. Estoque:";
    // 
    // lstAutores
    // 
    this->lstAutores->Enabled = false;
    this->lstAutores->Location = System::Drawing::Point(100, 296);
    this->lstAutores->Name = S"lstAutores";
    this->lstAutores->Size = System::Drawing::Size(332, 43);
    this->lstAutores->TabIndex = 34;
    this->lstAutores->DoubleClick += new System::EventHandler(this,lstAutores_DoubleClick);
    // 
    // btnAdAutores
    // 
    this->btnAdAutores->Enabled = false;
    this->btnAdAutores->Location = System::Drawing::Point(384, 272);
    this->btnAdAutores->Name = S"btnAdAutores";
    this->btnAdAutores->Size = System::Drawing::Size(22, 20);
    this->btnAdAutores->TabIndex = 32;
    this->btnAdAutores->Text = S"+";
    this->btnAdAutores->Click += new System::EventHandler(this,btnAdAutores_Click);
    // 
    // btnPAutor
    // 
    this->btnPAutor->Enabled = false;
    this->btnPAutor->Location = System::Drawing::Point(408, 272);
    this->btnPAutor->Name = S"btnPAutor";
    this->btnPAutor->Size = System::Drawing::Size(22, 20);
    this->btnPAutor->TabIndex = 33;
    this->btnPAutor->Text = S"...";
    this->btnPAutor->Click += new System::EventHandler(this,btnPAutor_Click);
    // 
    // edtAutor
    // 
    this->edtAutor->Enabled = false;
    this->edtAutor->Location = System::Drawing::Point(184, 272);
    this->edtAutor->MaxLength = 30;
    this->edtAutor->Name = S"edtAutor";
    this->edtAutor->Size = System::Drawing::Size(200, 20);
    this->edtAutor->TabIndex = 31;
    this->edtAutor->Text = S"";
    // 
    // edtCodAutor
    // 
    this->edtCodAutor->Enabled = false;
    this->edtCodAutor->Location = System::Drawing::Point(100, 272);
    this->edtCodAutor->MaxLength = 10;
    this->edtCodAutor->Name = S"edtCodAutor";
    this->edtCodAutor->Size = System::Drawing::Size(80, 20);
    this->edtCodAutor->TabIndex = 30;
    this->edtCodAutor->Text = S"";
    this->edtCodAutor->Leave += new System::EventHandler(this,edtCodAutor_Leave);
    // 
    // labAutor
    // 
    this->labAutor->Location = System::Drawing::Point(100, 256);
    this->labAutor->Name = S"labAutor";
    this->labAutor->Size = System::Drawing::Size(68, 16);
    this->labAutor->TabIndex = 29;
    this->labAutor->Text = S"Autor:";
    // 
    // frmCadLivros
    // 
    this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
    this->ClientSize = System::Drawing::Size(520, 381);
    this->Controls->Add(this->lstAutores);
    this->Controls->Add(this->btnAdAutores);
    this->Controls->Add(this->btnPAutor);
    this->Controls->Add(this->edtAutor);
    this->Controls->Add(this->edtCodAutor);
    this->Controls->Add(this->labAutor);
    this->Controls->Add(this->edtQtdEstoque);
    this->Controls->Add(this->labQtdEstoque);
    this->Controls->Add(this->edtPreco);
    this->Controls->Add(this->labPreco);
    this->Controls->Add(this->lstAssuntos);
    this->Controls->Add(this->cmbIdioma);
    this->Controls->Add(this->labIdioma);
    this->Controls->Add(this->edtNPaginas);
    this->Controls->Add(this->labNPaginas);
    this->Controls->Add(this->edtVolume);
    this->Controls->Add(this->labVolume);
    this->Controls->Add(this->btnAdAssuntos);
    this->Controls->Add(this->btnPAssunto);
    this->Controls->Add(this->edtAssunto);
    this->Controls->Add(this->edtCodAssunto);
    this->Controls->Add(this->labAssunto);
    this->Controls->Add(this->btnPEditora);
    this->Controls->Add(this->edtEditora);
    this->Controls->Add(this->edtCodEditora);
    this->Controls->Add(this->labEditora);
    this->Controls->Add(this->edtAnoPubli);
    this->Controls->Add(this->labAnoPubli);
    this->Controls->Add(this->edtEdicao);
    this->Controls->Add(this->labEdicao);
    this->Name = S"frmCadLivros";
    this->Text = S"Cadastro de Livros";
    this->Closing += new System::ComponentModel::CancelEventHandler(this,frmCadLivros_Closing);
    this->Load += new System::EventHandler(this,frmCadLivros_Load);
    (dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->edtEdicao))->EndInit();
    (dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->edtAnoPubli))->EndInit();
    (dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->edtVolume))->EndInit();
    (dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->edtNPaginas))->EndInit();
    (dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->edtQtdEstoque))->EndInit();
    this->ResumeLayout(false);
  }
  
  Boolean frmCadLivros::ValidaDados(Boolean bTodosDados)
  {
	__super::ValidaDados(bTodosDados);
  	
	if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Text,
  		S"ISBN não informado!"))
  	  return false;
  	if (bTodosDados) {
  	  if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Text,
  		S"Título não informado!"))
  		return false;
	  if (RotinasGlobais::Rotinas->ValidaCampo(edtEditora->Text,
		S"Editora não informada!"))
		return false;
	  if (lstAssuntos->Items->Count == 0){
            MessageBox::Show(this,S"Assunto(s) não informado(s)!",
            frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
            MessageBoxIcon::Error);
            return false;
	  }
	  if (lstAutores->Items->Count == 0){
            MessageBox::Show(this,S"Autor(es) não informado(s)!",
            frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
            MessageBoxIcon::Error);
            return false;
	  }

  	}
  	return true;
  }

  Void frmCadLivros::InformaLimpaDados(Boolean bInformar)
  { 
    if (bInformar) {
        edtEdicao->Text=Campos->Item[2]->ToString();
        edtAnoPubli->Text=Campos->Item[3]->ToString();
        edtVolume->Text=Campos->Item[4]->ToString();
        edtCodEditora->Text=Campos->Item[5]->ToString();
        edtEditora->Text=Campos->Item[6]->ToString();
        cmbIdioma->SelectedIndex=slIdiomas->IndexOf(Campos->Item[7]->ToString());
        edtNPaginas->Text=Campos->Item[9]->ToString();
        edtPreco->Text=RotinasGlobais::Rotinas->
        				 VirgulaParaPonto(Campos->Item[10]->ToString(),true);
        edtQtdEstoque->Text=Campos->Item[11]->ToString();
        RotinasGlobais::Rotinas->AdicionaValoresLista(ConsLista,ConsultasSQL::
        ConsSQL->LivroAss('S',edtCodigo->Text,""),lstAssuntos,slAssuntos);
        RotinasGlobais::Rotinas->AdicionaValoresLista(ConsLista,ConsultasSQL::
        ConsSQL->LivroAut('S',edtCodigo->Text,""),lstAutores,slAutores);
    } else {
        edtEdicao->Value=1;
        edtAnoPubli->Text=DateTime::Now.ToString("yyyy");
        edtVolume->Value=1;
        edtCodEditora->Clear();
        edtEditora->Clear();
        edtNPaginas->Value=1;
        edtPreco->Text="0,00";
        edtQtdEstoque->Value=1;
        edtCodAssunto->Clear();
        lstAssuntos->Items->Clear();
        edtCodAutor->Clear();
        lstAutores->Items->Clear();
        slAssuntos->Clear();
        slAutores->Clear();
    }
  
  }
  
  Void frmCadLivros::HabilitaDados(Boolean bHabilita)
  { 
      edtEdicao->Enabled=bHabilita;
      edtAnoPubli->Enabled=bHabilita;
      edtVolume->Enabled=bHabilita;
      edtCodEditora->Enabled=bHabilita;
      btnPEditora->Enabled=bHabilita;
      cmbIdioma->Enabled=bHabilita;
      edtNPaginas->Enabled=bHabilita;
      edtPreco->Enabled=bHabilita;
      edtQtdEstoque->Enabled=bHabilita;
      edtCodAssunto->Enabled=bHabilita;
      btnPAssunto->Enabled=bHabilita;
      btnAdAssuntos->Enabled=bHabilita;
      lstAssuntos->Enabled=bHabilita;
      edtCodAutor->Enabled=bHabilita;
      btnPAutor->Enabled=bHabilita;
      btnAdAutores->Enabled=bHabilita;
      lstAutores->Enabled=bHabilita;
  }

  Void frmCadLivros::btnNovo_Click(Object* sender, System::EventArgs* e)
  {
  	InformaLimpaDados(false);
  	HabilitaDados(true);
  }
  Void frmCadLivros::btnLimpar_Click(Object* sender, System::EventArgs* e)
  {
  	InformaLimpaDados(false);
  	HabilitaDados(false);
  }  
  Void frmCadLivros::btnExcluir_Click(Object* sender, System::EventArgs* e)
  {
  	if (ExcluirDados(ConsultasSQL::ConsSQL->Livro('D',edtCodigo->Text,
	S"",S"",S"",S"",S"",S"",S"",S"",S""))) {
          InformaLimpaDados(false);
    	  HabilitaDados(false);
        }
  }
  
  Void frmCadLivros::btnPesquisar_Click(Object* sender, System::EventArgs* e)
  {
  	if (PesquisarDados(ConsultasSQL::ConsSQL->Livro('S',edtCodigo->Text,
	S"",S"",S"",S"",S"",S"",S"",S"",S""),S"Livro não encontrado!")) {
          InformaLimpaDados(true);
    	  HabilitaDados(true);
        }
  }
  
  Void frmCadLivros::btnAnterior_Click(Object* sender, System::EventArgs* e)
  {        
    InformaLimpaDados(true);
  }
  
  Void frmCadLivros::btnProximo_Click(Object* sender, System::EventArgs* e)
  {
    InformaLimpaDados(true);
  }

  Void frmCadLivros::btnSalvar_Click(Object* sender, System::EventArgs* e)
  {
  	if (SalvarDados(ConsultasSQL::ConsSQL->Livro('S',edtCodigo->Text,
	S"",S"",S"",S"",S"",S"",S"",S"",S""),
  	ConsultasSQL::ConsSQL->Livro('U',edtCodigo->Text,edtDescricao->Text,
	edtEdicao->Text,edtAnoPubli->Text,edtVolume->Text,edtCodEditora->Text,
	slIdiomas->Item[cmbIdioma->SelectedIndex]->ToString(),edtNPaginas->Text,
	RotinasGlobais::Rotinas->VirgulaParaPonto(edtPreco->Text,false),
	edtQtdEstoque->Text),
  	ConsultasSQL::ConsSQL->Livro('I',edtCodigo->Text,edtDescricao->Text,
	edtEdicao->Text,edtAnoPubli->Text,edtVolume->Text,edtCodEditora->Text,
	slIdiomas->Item[cmbIdioma->SelectedIndex]->ToString(),edtNPaginas->Text,
	RotinasGlobais::Rotinas->VirgulaParaPonto(edtPreco->Text,false),
	edtQtdEstoque->Text), false)) {
  	  SalvaLista('A');
	  SalvaLista('B');
  	  btnLimpar_Click(this,System::EventArgs::Empty);
          InformaLimpaDados(false);
    	  HabilitaDados(false);
        }
  }
  
  Void frmCadLivros::frmCadLivros_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
	frmPrincipal::fPrincipal->tlbLivros->Enabled=true;
  	frmPrincipal::fPrincipal->mnuCadLivros->Enabled=true;
  }

  Void frmCadLivros::btnFechar_Click(Object* sender, System::EventArgs* e)
  {
  	frmCadLivros_Closing(this,new CancelEventArgs());
  }
  
  Void frmCadLivros::frmCadLivros_Load(Object* sender, System::EventArgs* e)
  {
    edtAnoPubli->Text=DateTime::Now.ToString(S"yyyy");
    AdicionaCombo();
    cmbIdioma->SelectedIndex=0;
  }
  
  Void frmCadLivros::AdicionaCombo() {
  	ArrayList* linhas = new ArrayList();
  	ArrayList* regs = new ArrayList();
  
  	RotinasGlobais::Rotinas->ConsultaDados(regs,
  		ConsultasSQL::ConsSQL->Idioma('S',S"",S""));
  
  	for(int cont=0; cont < regs->Count; cont++) {
  	  linhas = dynamic_cast<ArrayList*>(regs->Item[cont]);
  	  slIdiomas->Add(linhas->Item[0]->ToString());
  	  cmbIdioma->Items->Add(linhas->Item[1]->ToString());
  	}
  }

  Void frmCadLivros::SalvaLista(char sOpcao) {
  	if (sOpcao=='A') {
  	 RotinasGlobais::Rotinas->ConsultaDados(Arquiva,
  	 ConsultasSQL::ConsSQL->LivroAss('D',edtCodigo->Text,S""));
  
  	 for (int nCont=0; nCont < slAssuntos->Count; nCont++)  {
  	  RotinasGlobais::Rotinas->ConsultaDados(Arquiva,
  	  ConsultasSQL::ConsSQL->LivroAss('I',
  			edtCodigo->Text,slAssuntos->Item[nCont]->ToString()));
  	 }
  	} else if (sOpcao=='B') {
  	  RotinasGlobais::Rotinas->ConsultaDados(Arquiva,
  	  ConsultasSQL::ConsSQL->LivroAut('D',edtCodigo->Text,S""));
  
  	  for (int nCont=0; nCont < slAutores->Count; nCont++)  {
  	   RotinasGlobais::Rotinas->ConsultaDados(Arquiva,
  	   ConsultasSQL::ConsSQL->LivroAut('I',
  			 edtCodigo->Text,slAssuntos->Item[nCont]->ToString()));
  	  }
  	}
  }
  
  Void frmCadLivros::edtCodigo_Leave(Object* sender, System::EventArgs* e)
  {
  	if (edtCodigo->Text->Equals(S"")==false) {
  	  if (RotinasGlobais::Rotinas->ValidaISBN(edtCodigo->Text)==false) {
  		  MessageBox::Show(this,S"ISBN inválido!",
  		  frmPrincipal::fPrincipal->Text, MessageBoxButtons::OK,
  		  MessageBoxIcon::Error);
  		  edtCodigo->Clear();
  		  edtCodigo->Focus();
  	  }
  	}
  }
  
  Void frmCadLivros::edtCodEditora_Leave(Object* sender, System::EventArgs* e)
  {
    if (edtCodEditora->Text->Equals(S"")==false) {
     edtEditora->Text=RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo,
     edtCodEditora->Text,ConsultasSQL::ConsSQL->Editora('S',
     edtCodEditora->Text,S""),S"Editora não encontrada!");
     if (edtEditora->Text->Equals(S""))
  	 edtCodEditora->Focus();
    } else
  	edtEditora->Clear();
  }
  
  Void frmCadLivros::btnPEditora_Click(Object* sender, System::EventArgs* e)
  {
  	frmConEditoras* pfConEditoras = new frmConEditoras();
  	pfConEditoras->ShowDialog();
  	edtCodEditora->Text=RotinasGlobais::Rotinas->sCodigoSelecionado;
  	edtCodEditora_Leave(this,System::EventArgs::Empty);
  }
  
  Void frmCadLivros::edtPreco_Leave(Object* sender, System::EventArgs* e)
  {
  	if (RotinasGlobais::Rotinas->ValidaFloat(edtPreco->Text))
  	  edtPreco->Text=RotinasGlobais::Rotinas->VirgulaParaPonto(
  		  edtPreco->Text,true);
  	else
  	  edtPreco->Text=S"0,00";
  }
  
  Void frmCadLivros::edtCodAssunto_Leave(Object* sender, System::EventArgs* e)
  {
    if (edtCodAssunto->Text->Equals(S"")==false) {
     edtAssunto->Text=RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo,
     edtCodAssunto->Text,ConsultasSQL::ConsSQL->Assunto('S',
     edtCodAssunto->Text,S""),S"Assunto não encontrado!");
     if (edtAssunto->Text->Equals(S""))
  	 edtCodAssunto->Focus();
    } else
  	edtAssunto->Clear();
  }
  
  Void frmCadLivros::edtCodAutor_Leave(Object* sender, System::EventArgs* e)
  {
    if (edtCodAutor->Text->Equals(S"")==false) {
     edtAutor->Text=RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo,
     edtCodAutor->Text,ConsultasSQL::ConsSQL->Autor('S',
     edtCodAutor->Text,S""),S"Autor não encontrado!");
     if (edtAutor->Text->Equals(S""))
  	 edtCodAutor->Focus();
    } else
  	edtAutor->Clear();
  }
  
  Void frmCadLivros::btnPAssunto_Click(Object* sender, System::EventArgs* e)
  {
  	frmConAssuntos* pfConAssuntos = new frmConAssuntos();
  	pfConAssuntos->ShowDialog();
  	edtCodAssunto->Text=RotinasGlobais::Rotinas->sCodigoSelecionado;
  	edtCodAssunto_Leave(this,System::EventArgs::Empty);
  }
  
  Void frmCadLivros::btnPAutor_Click(Object* sender, System::EventArgs* e)
  {
  	frmConAutores* pfConAutores = new frmConAutores();
  	pfConAutores->ShowDialog();
  	edtCodAutor->Text=RotinasGlobais::Rotinas->sCodigoSelecionado;
  	edtCodAutor_Leave(this,System::EventArgs::Empty);
  }
  
  Void frmCadLivros::btnAdAssuntos_Click(Object* sender, System::EventArgs* e)
  {
  	RotinasGlobais::Rotinas->AdicionaItemLista(
  	lstAssuntos,slAssuntos,edtCodAssunto,edtAssunto);
  }
  
  Void frmCadLivros::lstAssuntos_DoubleClick(Object* sender, System::EventArgs* e)
  {
  	RotinasGlobais::Rotinas->RemoveItemLista(lstAssuntos,slAssuntos);
  }
  
  Void frmCadLivros::btnAdAutores_Click(Object* sender, System::EventArgs* e)
  {
  	RotinasGlobais::Rotinas->AdicionaItemLista(
  	lstAutores,slAutores,edtCodAutor,edtAutor);
  }
  
  Void frmCadLivros::lstAutores_DoubleClick(Object* sender, System::EventArgs* e)
  {
          RotinasGlobais::Rotinas->RemoveItemLista(lstAutores,slAutores);
  }

}
