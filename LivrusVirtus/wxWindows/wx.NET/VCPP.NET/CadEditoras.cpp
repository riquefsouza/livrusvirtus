#include "stdafx.h"
#include "CadEditoras.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

namespace Livrus
{
  frmCadEditoras::frmCadEditoras( wx::Window* parent )
  	: frmCadastros(parent, TextValidatorCtrl::FILTER_NUMERIC, true){

    labDescricao->Label = "Editora: ";

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

	Boolean frmCadEditoras::ValidaDados(Boolean bTodosDados){
    if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Value, 
      Resource::STR_CODNINF))
      return false;
    if (bTodosDados) {
      if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Value, 
        Resource::STR_EDTNINF))
      	return false;
    }
		return true;
	}

  Void frmCadEditoras::OnClose( System::Object* sender, wx::Event* e ){
   this->Parent->Close();
  	e->Skip();
  }
  
  Void frmCadEditoras::OnBtnNovo( System::Object* sender, wx::Event* e ){
    btnNovoClick();
    NovoDado(ConsultasSQL::ConsSQL->Editora('N', edtCodigo->Value,""));	
    e->Skip();
  }
  
  Void frmCadEditoras::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Editora('S', edtCodigo->Value,""), 
      Resource::STR_EDTNENC);
    e->Skip();
  }
  
  Void frmCadEditoras::OnBtnAnterior( System::Object* sender, wx::Event* e ){
    registroAnterior();	
    e->Skip();
  }
  
  Void frmCadEditoras::OnBtnProximo( System::Object* sender, wx::Event* e ){
    registroProximo();		
    e->Skip();
  }
  
  Void frmCadEditoras::OnBtnSalvar( System::Object* sender, wx::Event* e ){
    SalvarDados(ValidaDados(true),
      ConsultasSQL::ConsSQL->Editora('S', edtCodigo->Value,""),
      ConsultasSQL::ConsSQL->Editora('U', edtCodigo->Value, 
        edtDescricao->Value),
      ConsultasSQL::ConsSQL->Editora('I', edtCodigo->Value, 
        edtDescricao->Value), true);
    e->Skip();
  }
  
  Void frmCadEditoras::OnBtnExcluir( System::Object* sender, wx::Event* e ){
    ExcluirDados(ValidaDados(false),
      ConsultasSQL::ConsSQL->Editora('D', edtCodigo->Value,""));
    e->Skip();
  }
  
  Void frmCadEditoras::OnBtnFechar( System::Object* sender, wx::Event* e ){
    this->Close(true);
    e->Skip();
  }
  
  Void frmCadEditoras::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    btnLimparClick();
    e->Skip();
  }

}
