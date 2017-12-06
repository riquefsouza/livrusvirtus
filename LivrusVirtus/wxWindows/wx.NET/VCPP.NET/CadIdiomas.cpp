#include "stdafx.h"
#include "CadIdiomas.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

namespace Livrus
{
  frmCadIdiomas::frmCadIdiomas( wx::Window* parent )
  	: frmCadastros(parent, TextValidatorCtrl::FILTER_NUMERIC, true){

    labDescricao->Label = "Idioma: ";

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

	Boolean frmCadIdiomas::ValidaDados(Boolean bTodosDados){
    if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Value, 
      Resource::STR_CODNINF))
      return false;
    if (bTodosDados) {
      if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Value, 
        Resource::STR_IDININF))
      	return false;
    }
		return true;
	}

  Void frmCadIdiomas::OnClose( System::Object* sender, wx::Event* e ){
   this->Parent->Close();
  	e->Skip();
  }
  
  Void frmCadIdiomas::OnBtnNovo( System::Object* sender, wx::Event* e ){
    btnNovoClick();
    NovoDado(ConsultasSQL::ConsSQL->Idioma('N', edtCodigo->Value,""));	
    e->Skip();
  }
  
  Void frmCadIdiomas::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Idioma('S', edtCodigo->Value,""), 
      Resource::STR_IDINENC);
    e->Skip();
  }
  
  Void frmCadIdiomas::OnBtnAnterior( System::Object* sender, wx::Event* e ){
    registroAnterior();	
    e->Skip();
  }
  
  Void frmCadIdiomas::OnBtnProximo( System::Object* sender, wx::Event* e ){
    registroProximo();		
    e->Skip();
  }
  
  Void frmCadIdiomas::OnBtnSalvar( System::Object* sender, wx::Event* e ){
    SalvarDados(ValidaDados(true),
      ConsultasSQL::ConsSQL->Idioma('S', edtCodigo->Value,""),
      ConsultasSQL::ConsSQL->Idioma('U', edtCodigo->Value, 
        edtDescricao->Value),
      ConsultasSQL::ConsSQL->Idioma('I', edtCodigo->Value, 
        edtDescricao->Value), true);
    e->Skip();
  }
  
  Void frmCadIdiomas::OnBtnExcluir( System::Object* sender, wx::Event* e ){
    ExcluirDados(ValidaDados(false),
      ConsultasSQL::ConsSQL->Idioma('D', edtCodigo->Value,""));
    e->Skip();
  }
  
  Void frmCadIdiomas::OnBtnFechar( System::Object* sender, wx::Event* e ){
    this->Close(true);
    e->Skip();
  }
  
  Void frmCadIdiomas::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    btnLimparClick();
    e->Skip();
  }

}
