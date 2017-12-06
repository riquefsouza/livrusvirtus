#include "stdafx.h"
#include "ConClientes.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

namespace Livrus
{
  frmConClientes::frmConClientes( wx::Window* parent )
  	: frmConsultas(parent) {

    Title = Resource::STR_CONCLIENTE;
    labDescricao->Label = "Cliente:  ";
    gridConsulta->SetColLabelValue(0, "CPF");
    gridConsulta->SetColSize(0, 90);
    gridConsulta->SetColLabelValue(1, "Nome");
    gridConsulta->SetColSize(1, 220);

    int nLargura __gc[] = { 180,80,40,80,120,80,220,150, 
      80,100,100,80,180,80,100 };
    String* sRotulos __gc[] = { "Email", "Identidade", "Sexo", 
     "Telefone", "DtNascimento", "CodEndereço", "Logradouro", 
     "Bairro", "CEP", "Cidade", "Estado", "CodPaís", "País", 
     "CodProfissão", "Profissão" };
    RotinasGlobais::Rotinas->AdicionaColunasGrid(gridConsulta, 2, 15, 
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

  Void frmConClientes::OnClose( System::Object* sender, wx::Event* e ){
    Fecha(Resource::MNU_CON_CLIENTES);
  	e->Skip();
  }

  Void frmConClientes::OnBtnFechar( System::Object* sender, wx::Event* e ){
    Fecha(0);
    e->Skip();
  }
  
  Void frmConClientes::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    LimparDados();
    e->Skip();
  }
  
  Void frmConClientes::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    PesquisarDados(ConsultasSQL::ConsSQL->Cliente('S',"", edtDescricao->Value,
      "","","","","","","",""),Resource::STR_CLINENC, 17);
    e->Skip();
  }
  
  Void frmConClientes::OnGridSelectCell( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
  
  Void frmConClientes::OnGridLabelLeftClick( System::Object* sender, 
    wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
}
