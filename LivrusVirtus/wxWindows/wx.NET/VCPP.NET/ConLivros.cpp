#include "stdafx.h"
#include "ConLivros.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

namespace Livrus
{
  frmConLivros::frmConLivros( wx::Window* parent )
  	: frmConsultas(parent) {

    Title = Resource::STR_CONLIVRO;
    labDescricao->Label = "Livro:  ";
    gridConsulta->SetColLabelValue(0, "ISBN");
    gridConsulta->SetColSize(0, 80);
    gridConsulta->SetColLabelValue(1, "Título");
    gridConsulta->SetColSize(1, 180);

    int nLargura __gc[] = { 80,90,80,80,100,80,100,80,80,80 };
    String* sRotulos __gc[] = { "Edição", "AnoPublicação", 
      "Volume", "CodEditora", "Editora", "CodIdioma", "Idioma",
      "NumPáginas", "Preço", "Estoque" };
    RotinasGlobais::Rotinas->AdicionaColunasGrid(gridConsulta, 2, 10, 
      nLargura, sRotulos);

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

  Void frmConLivros::OnClose( System::Object* sender, wx::Event* e ){
    Fecha(Resource::MNU_CON_LIVROS);
  	e->Skip();
  }

  Void frmConLivros::OnBtnFechar( System::Object* sender, wx::Event* e ){
    Fecha(0);
    e->Skip();
  }
  
  Void frmConLivros::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    LimparDados();
    e->Skip();
  }
  
  Void frmConLivros::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Livro('S',"", edtDescricao->Value,
      "","","","","","","",""), Resource::STR_LIVNENC, 12);
    e->Skip();
  }
  
  Void frmConLivros::OnGridSelectCell( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
  
  Void frmConLivros::OnGridLabelLeftClick( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
}
