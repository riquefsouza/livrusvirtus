#include "stdafx.h"
#include "CadProfissoes.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

namespace Livrus
{
  frmCadProfissoes::frmCadProfissoes( wx::Window* parent )
  	: frmCadastros(parent, TextValidatorCtrl::FILTER_NUMERIC, true){

    labDescricao->Label = "Profissão: ";

    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNNOVO, 
      new wx::EventListener( this, OnBtnNovo ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNPESQUISAR, 
      new wx::EventListener( this, OnBtnPesquisar ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNANTERIOR, 
      new wx::EventListener( this, OnBtnAnterior ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNPROXIMO, 
      new wx::EventListener( this, OnBtnProximo ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNSALVAR, 
      new wx::EventListener( this, OnBtnSalvar ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNEXCLUIR, 
      new wx::EventListener( this, OnBtnExcluir ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNLIMPAR, 
      new wx::EventListener( this, OnBtnLimpar ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNFECHAR, 
      new wx::EventListener( this, OnBtnFechar ));
  	EVT_CLOSE( new wx::EventListener( this, OnClose ) );
  }

	Boolean frmCadProfissoes::ValidaDados(Boolean bTodosDados){
    if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Value, 
      Resource::STR_CODNINF))
      return false;
    if (bTodosDados) {
      if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Value, 
        Resource::STR_PROFNINF))
      	return false;
    }
		return true;
	}

  Void frmCadProfissoes::OnClose( System::Object* sender, wx::Event* e ){
   this->Parent->Close();
  	e->Skip();
  }
  
  Void frmCadProfissoes::OnBtnNovo( System::Object* sender, wx::Event* e ){
    btnNovoClick();
    NovoDado(ConsultasSQL::ConsSQL->Profissao('N', edtCodigo->Value,""));	
    e->Skip();
  }
  
  Void frmCadProfissoes::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Profissao('S', edtCodigo->Value,""), 
      Resource::STR_PROFNENC);
    e->Skip();
  }
  
  Void frmCadProfissoes::OnBtnAnterior( System::Object* sender, wx::Event* e ){
    registroAnterior();	
    e->Skip();
  }
  
  Void frmCadProfissoes::OnBtnProximo( System::Object* sender, wx::Event* e ){
    registroProximo();		
    e->Skip();
  }
  
  Void frmCadProfissoes::OnBtnSalvar( System::Object* sender, wx::Event* e ){
    SalvarDados(ValidaDados(true),
      ConsultasSQL::ConsSQL->Profissao('S', edtCodigo->Value,""),
      ConsultasSQL::ConsSQL->Profissao('U', edtCodigo->Value, 
        edtDescricao->Value),
      ConsultasSQL::ConsSQL->Profissao('I', edtCodigo->Value, 
        edtDescricao->Value), true);
    e->Skip();
  }
  
  Void frmCadProfissoes::OnBtnExcluir( System::Object* sender, wx::Event* e ){
    ExcluirDados(ValidaDados(false),
      ConsultasSQL::ConsSQL->Profissao('D', edtCodigo->Value,""));
    e->Skip();
  }
  
  Void frmCadProfissoes::OnBtnFechar( System::Object* sender, wx::Event* e ){
    this->Close(true);
    e->Skip();
  }
  
  Void frmCadProfissoes::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    btnLimparClick();
    e->Skip();
  }

}
