#include "stdafx.h"
#include "CadAutores.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

namespace Livrus
{
  frmCadAutores::frmCadAutores( wx::Window* parent )
  	: frmCadastros(parent, TextValidatorCtrl::FILTER_NUMERIC, true){

    labDescricao->Label = "Autor: ";

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

	Boolean frmCadAutores::ValidaDados(Boolean bTodosDados){
    if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Value, 
      Resource::STR_CODNINF))
      return false;
    if (bTodosDados) {
      if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Value, 
        Resource::STR_AUTNINF))
      	return false;
    }
		return true;
	}

  Void frmCadAutores::OnClose( System::Object* sender, wx::Event* e ){
   this->Parent->Close();
  	e->Skip();
  }
  
  Void frmCadAutores::OnBtnNovo( System::Object* sender, wx::Event* e ){
    btnNovoClick();
    NovoDado(ConsultasSQL::ConsSQL->Autor('N', edtCodigo->Value,""));	
    e->Skip();
  }
  
  Void frmCadAutores::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Autor('S', edtCodigo->Value,""), 
      Resource::STR_AUTNENC);
    e->Skip();
  }
  
  Void frmCadAutores::OnBtnAnterior( System::Object* sender, wx::Event* e ){
    registroAnterior();	
    e->Skip();
  }
  
  Void frmCadAutores::OnBtnProximo( System::Object* sender, wx::Event* e ){
    registroProximo();		
    e->Skip();
  }
  
  Void frmCadAutores::OnBtnSalvar( System::Object* sender, wx::Event* e ){
    SalvarDados(ValidaDados(true),
      ConsultasSQL::ConsSQL->Autor('S', edtCodigo->Value,""),
      ConsultasSQL::ConsSQL->Autor('U', edtCodigo->Value, 
        edtDescricao->Value),
      ConsultasSQL::ConsSQL->Autor('I', edtCodigo->Value, 
        edtDescricao->Value), true);
    e->Skip();
  }
  
  Void frmCadAutores::OnBtnExcluir( System::Object* sender, wx::Event* e ){
    ExcluirDados(ValidaDados(false),
      ConsultasSQL::ConsSQL->Autor('D', edtCodigo->Value,""));
    e->Skip();
  }
  
  Void frmCadAutores::OnBtnFechar( System::Object* sender, wx::Event* e ){
    this->Close(true);
    e->Skip();
  }
  
  Void frmCadAutores::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    btnLimparClick();
    e->Skip();
  }

}
