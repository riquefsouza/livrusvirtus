#include "stdafx.h"
#include "ConEditoras.h"
#include "Resource.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmConEditoras::frmConEditoras( wx::Window* parent )
  	: frmConsultas(parent) {

    Title = Resource::STR_CONEDITORA;
    labDescricao->Label = "Editora:  ";
    gridConsulta->SetColLabelValue(1, "Editora");

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

  Void frmConEditoras::OnClose( System::Object* sender, wx::Event* e ){
    Fecha(Resource::MNU_CON_EDITORAS);
  	e->Skip();
  }

  Void frmConEditoras::OnBtnFechar( System::Object* sender, wx::Event* e ){
    Fecha(0);
    e->Skip();
  }
  
  Void frmConEditoras::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    LimparDados();
    e->Skip();
  }
  
  Void frmConEditoras::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Editora('S',"", edtDescricao->Value),
      Resource::STR_EDTNENC, 2);
    e->Skip();
  }
  
  Void frmConEditoras::OnGridSelectCell( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
  
  Void frmConEditoras::OnGridLabelLeftClick( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
}
