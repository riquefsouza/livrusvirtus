#include "stdafx.h"
#include "ConAssuntos.h"
#include "Resource.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmConAssuntos::frmConAssuntos( wx::Window* parent )
  	: frmConsultas(parent) {

    Title = Resource::STR_CONASSUNTO;
    labDescricao->Label = "Assunto:  ";
    gridConsulta->SetColLabelValue(1, "Assunto");

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

  Void frmConAssuntos::OnClose( System::Object* sender, wx::Event* e ){
    Fecha(Resource::MNU_CON_ASSUNTOS);
  	e->Skip();
  }

  Void frmConAssuntos::OnBtnFechar( System::Object* sender, wx::Event* e ){
    Fecha(0);
    e->Skip();
  }
  
  Void frmConAssuntos::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    LimparDados();
    e->Skip();
  }
  
  Void frmConAssuntos::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Assunto('S',"", edtDescricao->Value),
      Resource::STR_ASSNENC, 2);
    e->Skip();
  }
  
  Void frmConAssuntos::OnGridSelectCell( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
  
  Void frmConAssuntos::OnGridLabelLeftClick( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
}
