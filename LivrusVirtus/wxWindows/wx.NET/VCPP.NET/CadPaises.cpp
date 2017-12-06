#include "stdafx.h"
#include "CadPaises.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

namespace Livrus
{
  frmCadPaises::frmCadPaises( wx::Window* parent )
  	: frmCadastros(parent, TextValidatorCtrl::FILTER_ALPHA, true){

    labDescricao->Label = "País: ";
    edtCodigo->MaxLength = 3;

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

	Boolean frmCadPaises::ValidaDados(Boolean bTodosDados){
    if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Value, 
      Resource::STR_CODNINF))
      return false;
    if (bTodosDados) {
      if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Value, 
        Resource::STR_PAISNINF))
      	return false;
    }
		return true;
	}

  Void frmCadPaises::OnClose( System::Object* sender, wx::Event* e ){
   this->Parent->Close();
  	e->Skip();
  }
  
  Void frmCadPaises::OnBtnNovo( System::Object* sender, wx::Event* e ){
    btnNovoClick();
    e->Skip();
  }
  
  Void frmCadPaises::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Pais('S', edtCodigo->Value,""), 
      Resource::STR_PAISNENC);
    e->Skip();
  }
  
  Void frmCadPaises::OnBtnAnterior( System::Object* sender, wx::Event* e ){
    registroAnterior();	
    e->Skip();
  }
  
  Void frmCadPaises::OnBtnProximo( System::Object* sender, wx::Event* e ){
    registroProximo();		
    e->Skip();
  }
  
  Void frmCadPaises::OnBtnSalvar( System::Object* sender, wx::Event* e ){
    SalvarDados(ValidaDados(true),
      ConsultasSQL::ConsSQL->Pais('S', edtCodigo->Value,""),
      ConsultasSQL::ConsSQL->Pais('U', edtCodigo->Value, 
        edtDescricao->Value),
      ConsultasSQL::ConsSQL->Pais('I', edtCodigo->Value, 
        edtDescricao->Value), true);
    e->Skip();
  }
  
  Void frmCadPaises::OnBtnExcluir( System::Object* sender, wx::Event* e ){
    ExcluirDados(ValidaDados(false),
      ConsultasSQL::ConsSQL->Pais('D', edtCodigo->Value,""));
    e->Skip();
  }
  
  Void frmCadPaises::OnBtnFechar( System::Object* sender, wx::Event* e ){
    this->Close(true);
    e->Skip();
  }
  
  Void frmCadPaises::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    btnLimparClick();
    e->Skip();
  }

}
