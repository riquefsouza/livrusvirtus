#include "StdAfx.h"
#include "Cadastros.h"
#include "CadIdiomas.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmCadIdiomas::frmCadIdiomas()
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
  Void frmCadIdiomas::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmCadIdiomas::InitializeComponent()
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
  	this->labDescricao->Text = S"Idioma:";
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
  	// frmCadIdiomas
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->ClientSize = System::Drawing::Size(336, 133);
  	this->Name = S"frmCadIdiomas";
  	this->Text = S"Cadastro de Idiomas";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmCadIdiomas_Closing);
  }
  
  Boolean frmCadIdiomas::ValidaDados(Boolean bTodosDados)
  {
	__super::ValidaDados(bTodosDados);
  	
	if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Text,
  		S"Código não informado!"))
  	  return false;
  	if (bTodosDados) {
  	  if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Text,
  		S"Idioma não informado!"))
  		return false;
  	}
  	return true;
  }
  
  Void frmCadIdiomas::btnNovo_Click(Object* sender, System::EventArgs* e)
  {
  	NovoDado(ConsultasSQL::ConsSQL->Idioma('N',edtCodigo->Text,S""));
  }
  
  Void frmCadIdiomas::btnExcluir_Click(Object* sender, System::EventArgs* e)
  {
  	ExcluirDados(ConsultasSQL::ConsSQL->Idioma('D',edtCodigo->Text,S""));
  }
  
  Void frmCadIdiomas::btnPesquisar_Click(Object* sender, System::EventArgs* e)
  {
  	PesquisarDados(ConsultasSQL::ConsSQL->Idioma('S',edtCodigo->Text,S""),
  	S"Idioma não encontrado!");
  }
  
  Void frmCadIdiomas::btnSalvar_Click(Object* sender, System::EventArgs* e)
  {
  	SalvarDados(ConsultasSQL::ConsSQL->Idioma('S',edtCodigo->Text,S""),
  	ConsultasSQL::ConsSQL->Idioma('U',edtCodigo->Text,edtDescricao->Text),
  	ConsultasSQL::ConsSQL->Idioma('I',edtCodigo->Text,edtDescricao->Text),
  	true);
  }

  Void frmCadIdiomas::edtCodigo_Leave(Object* sender, System::EventArgs* e)
  {
     edtCodigoLeave();
  }
  
  Void frmCadIdiomas::frmCadIdiomas_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	  frmPrincipal::fPrincipal->mnuCadIdiomas->Enabled=true;
  }

}
