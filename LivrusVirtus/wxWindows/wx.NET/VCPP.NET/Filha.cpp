#include "stdafx.h"
#include "Filha.h"
#include "Principal.h"
#include "Resource.h"

namespace Livrus
{
  frmFilha::frmFilha( wx::MDIParentFrame* parent, int nTelaAtiva )
  	: wx::MDIChildFrame( parent, -1, "Cadastro de ", System::Drawing::Point(0, 0), 
      System::Drawing::Size(342, 219), wxDEFAULT_FRAME_STYLE, ""){

    ClientSize = System::Drawing::Size(330, 136);
		Icon = new wx::Icon( "xpms/livrus.xpm" );
   	EVT_CLOSE( new wx::EventListener( this, OnClose ) );
    nLocalTelaAtiva = nTelaAtiva;

    if (nTelaAtiva == Resource::FRMCADASSUNTOS) {
      fCadAssuntos = new frmCadAssuntos(this);
      Title = Resource::STR_CADASSUNTO;
    } else if (nTelaAtiva == Resource::FRMCADAUTORES) {
      fCadAutores = new frmCadAutores(this);
      Title = Resource::STR_CADAUTOR;
    } else if (nTelaAtiva == Resource::FRMCADEDITORAS) {
      fCadEditoras = new frmCadEditoras(this);
      Title = Resource::STR_CADEDITORA;
    } else if (nTelaAtiva == Resource::FRMCADENDERECOS) {
      fCadEnderecos = new frmCadEnderecos(this);
      Title = Resource::STR_CADENDERECO;
      ClientSize = System::Drawing::Size(525, 170);
    } else if (nTelaAtiva == Resource::FRMCADIDIOMAS) {
      fCadIdiomas = new frmCadIdiomas(this);
      Title = Resource::STR_CADIDIOMA;
    } else if (nTelaAtiva == Resource::FRMCADPAISES) {
      fCadPaises = new frmCadPaises(this);
      Title = Resource::STR_CADPAIS;
    } else if (nTelaAtiva == Resource::FRMCADPROFISSOES) {
      fCadProfissoes = new frmCadProfissoes(this);
      Title = Resource::STR_CADPROFISS;
    } else if (nTelaAtiva == Resource::FRMCADCLIENTES) {
      fCadClientes = new frmCadClientes(this);
      Title = Resource::STR_CADCLIENTE;
      ClientSize = System::Drawing::Size(525, 440);
    } else if (nTelaAtiva == Resource::FRMCADLIVROS) {
      fCadLivros = new frmCadLivros(this);
      Title = Resource::STR_CADLIVRO;
      ClientSize = System::Drawing::Size(510, 385);
    } else if (nTelaAtiva == Resource::FRMVENDERLIVROS) {
      fVenderLivros = new frmVenderLivros(this);
      Title = Resource::STR_VENLIVRO;
      ClientSize = System::Drawing::Size(480, 310);
    } else if (nTelaAtiva == Resource::FRMCONVENDAS) {
      fConVendas = new frmConVendas(this);
      Title = Resource::STR_CONVENLIVRO;
      ClientSize = System::Drawing::Size(480, 330);
    } else if (nTelaAtiva == Resource::FRMALTERARSENHA) {
      fAlterarSenha = new frmAlterarSenha(this);
      Title = Resource::STR_ALTSENHA;
      ClientSize = System::Drawing::Size(255, 134);
    }		
  }

	System::Void frmFilha::OnActivate( System::Object* sender, wx::Event* e ) {
		wx::ActivateEvent* ae = dynamic_cast<wx::ActivateEvent*>(e);
		if ( ae->Active ) {      
      if (nLocalTelaAtiva == Resource::FRMCADASSUNTOS)
        fCadAssuntos->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMCADAUTORES) 
        fCadAutores->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMCADEDITORAS)
        fCadEditoras->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMCADENDERECOS)
        fCadEnderecos->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMCADIDIOMAS)
        fCadIdiomas->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMCADPAISES) 
        fCadPaises->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMCADPROFISSOES) 
        fCadProfissoes->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMCADCLIENTES)
        fCadClientes->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMCADLIVROS)
        fCadLivros->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMVENDERLIVROS)
        fVenderLivros->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMCONVENDAS) 
        fConVendas->SetFocus();
      else if (nLocalTelaAtiva == Resource::FRMALTERARSENHA)
        fAlterarSenha->SetFocus();
    }
	}
  
  System::Void frmFilha::OnClose( System::Object* sender, wx::Event* e ) {
    if (nLocalTelaAtiva == Resource::FRMCADASSUNTOS)
      frmPrincipal::fPrincipal->barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_ASSUNTOS, true);
    else if (nLocalTelaAtiva == Resource::FRMCADAUTORES) 
      frmPrincipal::fPrincipal->barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_AUTORES, true);
    else if (nLocalTelaAtiva == Resource::FRMCADEDITORAS)
      frmPrincipal::fPrincipal->barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_EDITORAS, true);    
    else if (nLocalTelaAtiva == Resource::FRMCADENDERECOS)
      frmPrincipal::fPrincipal->barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_ENDERECOS, true);    
    else if (nLocalTelaAtiva == Resource::FRMCADIDIOMAS)
      frmPrincipal::fPrincipal->barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_IDIOMAS, true);
    else if (nLocalTelaAtiva == Resource::FRMCADPAISES) 
      frmPrincipal::fPrincipal->barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_PAISES, true);    
    else if (nLocalTelaAtiva == Resource::FRMCADPROFISSOES) 
      frmPrincipal::fPrincipal->barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_PROFISSOES, true);
    else if (nLocalTelaAtiva == Resource::FRMCADCLIENTES) {
      frmPrincipal::fPrincipal->barraFerra->EnableTool(Resource::MNU_CAD_CLIENTES, true);
      frmPrincipal::fPrincipal->barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_CLIENTES, true);
    } else if (nLocalTelaAtiva == Resource::FRMCADLIVROS) {
      frmPrincipal::fPrincipal->barraFerra->EnableTool(Resource::MNU_CAD_LIVROS, true);
      frmPrincipal::fPrincipal->barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_LIVROS, true);
    } else if (nLocalTelaAtiva == Resource::FRMVENDERLIVROS) {
      frmPrincipal::fPrincipal->barraFerra->EnableTool(Resource::MNU_VEN_VENDERLIVROS, true);
      frmPrincipal::fPrincipal->barraMenu->GetMenu(2)->Enable(Resource::MNU_VEN_VENDERLIVROS, true);  
    } else if (nLocalTelaAtiva == Resource::FRMCONVENDAS) 
      frmPrincipal::fPrincipal->barraMenu->GetMenu(2)->Enable(Resource::MNU_VEN_VENDASREALIZADAS, true);
    else if (nLocalTelaAtiva == Resource::FRMALTERARSENHA) {
      frmPrincipal::fPrincipal->barraMenu->GetMenu(3)->Enable(Resource::MNU_OP_ALTERARSENHA, true);
    }
    e->Skip();
  }
}
