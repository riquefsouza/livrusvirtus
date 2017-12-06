#include "stdafx.h"
#include "ConAutores.h"
#include "Resource.h"
#include "ConsultasSQL.h"

namespace Livrus
{
  frmConAutores::frmConAutores( wx::Window* parent )
  	: frmConsultas(parent) {

    Title = Resource::STR_CONAUTOR;
    labDescricao->Label = "Autor:  ";
    gridConsulta->SetColLabelValue(1, "Autor");

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

  Void frmConAutores::OnClose( System::Object* sender, wx::Event* e ){
    Fecha(Resource::MNU_CON_AUTORES);
  	e->Skip();
  }

  Void frmConAutores::OnBtnFechar( System::Object* sender, wx::Event* e ){
    Fecha(0);
    e->Skip();
  }
  
  Void frmConAutores::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    LimparDados();
    e->Skip();
  }
  
  Void frmConAutores::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Autor('S',"", edtDescricao->Value),
      Resource::STR_AUTNENC, 2);
    e->Skip();
  }
  
  Void frmConAutores::OnGridSelectCell( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
  
  Void frmConAutores::OnGridLabelLeftClick( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
}
