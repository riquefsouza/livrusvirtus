#include "stdafx.h"
#include "ConIdiomas.h"
#include "Resource.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmConIdiomas::frmConIdiomas( wx::Window* parent )
  	: frmConsultas(parent) {

    Title = Resource::STR_CONIDIOMA;
    labDescricao->Label = "Idioma:  ";
    gridConsulta->SetColLabelValue(1, "Idioma");

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

  Void frmConIdiomas::OnClose( System::Object* sender, wx::Event* e ){
    Fecha(Resource::MNU_CON_IDIOMAS);
  	e->Skip();
  }

  Void frmConIdiomas::OnBtnFechar( System::Object* sender, wx::Event* e ){
    Fecha(0);
    e->Skip();
  }
  
  Void frmConIdiomas::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    LimparDados();
    e->Skip();
  }
  
  Void frmConIdiomas::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Idioma('S',"", edtDescricao->Value),
      Resource::STR_IDINENC, 2);
    e->Skip();
  }
  
  Void frmConIdiomas::OnGridSelectCell( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
  
  Void frmConIdiomas::OnGridLabelLeftClick( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
}
