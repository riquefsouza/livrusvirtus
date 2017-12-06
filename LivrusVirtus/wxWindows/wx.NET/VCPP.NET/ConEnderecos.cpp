#include "stdafx.h"
#include "ConEnderecos.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

namespace Livrus
{
  frmConEnderecos::frmConEnderecos( wx::Window* parent )
  	: frmConsultas(parent) {

    Title = Resource::STR_CONENDERECO;
    labDescricao->Label = "Endereco:  ";
    gridConsulta->SetColLabelValue(1, "Logradouro");
    gridConsulta->SetColSize(1, 200);

    int nLargura __gc[] = { 150,80,100,80 };
    String* sRotulos __gc[] = { "Bairro", "CEP", "Cidade", "Estado" };
    RotinasGlobais::Rotinas->AdicionaColunasGrid(gridConsulta, 2, 4, 
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

  Void frmConEnderecos::OnClose( System::Object* sender, wx::Event* e ){
    Fecha(Resource::MNU_CON_ENDERECOS);
  	e->Skip();
  }

  Void frmConEnderecos::OnBtnFechar( System::Object* sender, wx::Event* e ){
    Fecha(0);
    e->Skip();
  }
  
  Void frmConEnderecos::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    LimparDados();
    e->Skip();
  }
  
  Void frmConEnderecos::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Endereco('S',"", edtDescricao->Value,
      "","","",""),Resource::STR_ENDNENC, 6);
    e->Skip();
  }
  
  Void frmConEnderecos::OnGridSelectCell( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
  
  Void frmConEnderecos::OnGridLabelLeftClick( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
}
