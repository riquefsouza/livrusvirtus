#include "StdAfx.h"
#include "Cadastros.h"
#include "CadAutores.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmCadAutores::frmCadAutores()
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
  Void frmCadAutores::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmCadAutores::InitializeComponent()
  {
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
  	this->labDescricao->Text = S"Autor:";
  	// 
  	// edtDescricao
  	// 
  	this->edtDescricao->Name = S"edtDescricao";
  	// 
  	// btnNovo
  	// 
  	this->btnNovo->Name = S"btnNovo";
  	this->btnNovo->Click += new System::EventHandler(this,btnNovo_Click);
  	// 
  	// btnPesquisar
  	// 
  	this->btnPesquisar->Name = S"btnPesquisar";
  	this->btnPesquisar->Click += new System::EventHandler(this,btnPesquisar_Click);
  	// 
  	// btnAnterior
  	// 
  	this->btnAnterior->Name = S"btnAnterior";
  	// 
  	// btnProximo
  	// 
  	this->btnProximo->Name = S"btnProximo";
  	// 
  	// btnFechar
  	// 
  	this->btnFechar->Name = S"btnFechar";
  	// 
  	// btnLimpar
  	// 
  	this->btnLimpar->Name = S"btnLimpar";
  	// 
  	// btnExcluir
  	// 
  	this->btnExcluir->Name = S"btnExcluir";
  	this->btnExcluir->Click += new System::EventHandler(this,btnExcluir_Click);
  	// 
  	// btnSalvar
  	// 
  	this->btnSalvar->Name = S"btnSalvar";
  	this->btnSalvar->Click += new System::EventHandler(this,btnSalvar_Click);
  	// 
  	// frmCadAutores
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->ClientSize = System::Drawing::Size(336, 133);
  	this->Name = S"frmCadAutores";
  	this->Text = S"Cadastro de Autores";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmCadAutores_Closing);
  }
  
  Boolean frmCadAutores::ValidaDados(Boolean bTodosDados)
  {
	__super::ValidaDados(bTodosDados);
  	
	if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Text,
  		S"Código não informado!"))
  	  return false;
  	if (bTodosDados) {
  	  if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Text,
  		S"Autor não informado!"))
  		return false;
  	}
  	return true;
  }
  
  Void frmCadAutores::btnNovo_Click(Object* sender, System::EventArgs* e)
  {
  	NovoDado(ConsultasSQL::ConsSQL->Autor('N',edtCodigo->Text,S""));
  }
  
  Void frmCadAutores::btnExcluir_Click(Object* sender, System::EventArgs* e)
  {
  	ExcluirDados(ConsultasSQL::ConsSQL->Autor('D',edtCodigo->Text,S""));
  }
  
  Void frmCadAutores::btnPesquisar_Click(Object* sender, System::EventArgs* e)
  {
  	PesquisarDados(ConsultasSQL::ConsSQL->Autor('S',edtCodigo->Text,S""),
  	S"Autor não encontrado!");
  }
  
  Void frmCadAutores::btnSalvar_Click(Object* sender, System::EventArgs* e)
  {
  	SalvarDados(ConsultasSQL::ConsSQL->Autor('S',edtCodigo->Text,S""),
  	ConsultasSQL::ConsSQL->Autor('U',edtCodigo->Text,edtDescricao->Text),
  	ConsultasSQL::ConsSQL->Autor('I',edtCodigo->Text,edtDescricao->Text),
  	true);
  }

  Void frmCadAutores::edtCodigo_Leave(Object* sender, System::EventArgs* e)
  {
     edtCodigoLeave();
  }
  
  Void frmCadAutores::frmCadAutores_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	  frmPrincipal::fPrincipal->mnuCadAutores->Enabled=true;
  }

}
