#include "stdafx.h"
#include "ConProfissoes.h"
#include "Resource.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmConProfissoes::frmConProfissoes( wx::Window* parent )
  	: frmConsultas(parent) {

    Title = Resource::STR_CONPROFISS;
    labDescricao->Label = "Profissão: ";
    gridConsulta->SetColLabelValue(1, "Profissão");

    EVT_BUTTON((int)idt::ID_FRMCONSULTAS_BTNPESQUISAR, 
      new wx::EventListener( this, OnBtnPesquisar ));
    EVT_BUTTON((int)idt::ID_FRMCONSULTAS_BTNLIMPAR, 
      new wx::EventListener( this, OnBtnLimpar ));
    EVT_BUTTON((int)idt::ID_FRMCONSULTAS_BTNFECHAR, 
      new wx::EventListener( this, OnBtnFechar ));
  	EVT_CLOSE( new wx::EventListener( this, OnClose ) );
    EVT_GRID_SELECT_CELL(new wx::EventListener( this, OnGridSelectCell ));
    EVT_GRID_LABEL_LEFT_CLICK(new wx::EventListener( this, 
      OnGridLabelLeftClick ));
  }

  Void frmConProfissoes::OnClose( System::Object* sender, wx::Event* e ){
    Fecha(Resource::MNU_CON_PROFISSOES);
  	e->Skip();
  }

  Void frmConProfissoes::OnBtnFechar( System::Object* sender, wx::Event* e ){
    Fecha(0);
    e->Skip();
  }
  
  Void frmConProfissoes::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    LimparDados();
    e->Skip();
  }
  
  Void frmConProfissoes::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Profissao('S',"", edtDescricao->Value),
      Resource::STR_PROFNENC, 2);
    e->Skip();
  }
  
  Void frmConProfissoes::OnGridSelectCell( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
  
  Void frmConProfissoes::OnGridLabelLeftClick( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
}
