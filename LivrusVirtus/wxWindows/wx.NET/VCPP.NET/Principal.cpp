#include "stdafx.h"
#include "Principal.h"
#include "Filha.h"
#include "Sobre.h"
#include "Resource.h"
#include "ConAssuntos.h"
#include "ConAutores.h"
#include "ConEditoras.h"
#include "ConEnderecos.h"
#include "ConIdiomas.h"
#include "ConPaises.h"
#include "ConProfissoes.h"
#include "ConClientes.h"
#include "ConLivros.h"

namespace Livrus
{
  frmPrincipal::frmPrincipal()
  	: wx::MDIParentFrame( 0, -1, Resource::STR_TITULO, 
    System::Drawing::Point( -1, -1 ), System::Drawing::Size(640, 480) ){

    Icon = new wx::Icon("xpms/livrus.xpm");

    //Barra de Menu
  	mnuCadastros = new wx::Menu();
  	mnuCadastros->Append((int)Resource::MNU_CAD_ASSUNTOS, "&Assuntos", Resource::STR_CADASSUNTO);
  	mnuCadastros->Append((int)Resource::MNU_CAD_AUTORES, "A&utores", Resource::STR_CADAUTOR);
  	mnuCadastros->Append((int)Resource::MNU_CAD_EDITORAS, "&Editoras", Resource::STR_CADEDITORA);
  	mnuCadastros->Append((int)Resource::MNU_CAD_ENDERECOS, "E&ndereços", Resource::STR_CADENDERECO);
  	mnuCadastros->Append((int)Resource::MNU_CAD_IDIOMAS, "&Idiomas", Resource::STR_CADIDIOMA);
  	mnuCadastros->Append((int)Resource::MNU_CAD_PAISES, "&Países", Resource::STR_CADPAIS);
  	mnuCadastros->Append((int)Resource::MNU_CAD_PROFISSOES, "P&rofissões", Resource::STR_CADPROFISS);
  	mnuCadastros->AppendSeparator();
  	mnuCadastros->Append((int)Resource::MNU_CAD_CLIENTES, "&Clientes", Resource::STR_CADCLIENTE);
  	mnuCadastros->Append((int)Resource::MNU_CAD_LIVROS, "&Livros", Resource::STR_CADLIVRO);

  	mnuPesquisas = new wx::Menu();
  	mnuPesquisas->Append((int)Resource::MNU_CON_ASSUNTOS, "&Assuntos", Resource::STR_CONASSUNTO);
  	mnuPesquisas->Append((int)Resource::MNU_CON_AUTORES, "A&utores", Resource::STR_CONAUTOR);
  	mnuPesquisas->Append((int)Resource::MNU_CON_EDITORAS, "&Editoras", Resource::STR_CONEDITORA);
  	mnuPesquisas->Append((int)Resource::MNU_CON_ENDERECOS, "E&ndereços", Resource::STR_CONENDERECO);
  	mnuPesquisas->Append((int)Resource::MNU_CON_IDIOMAS, "&Idiomas", Resource::STR_CONIDIOMA);
  	mnuPesquisas->Append((int)Resource::MNU_CON_PAISES, "&Países", Resource::STR_CONPAIS);
  	mnuPesquisas->Append((int)Resource::MNU_CON_PROFISSOES, "P&rofissões", Resource::STR_CONPROFISS);
  	mnuPesquisas->AppendSeparator();
  	mnuPesquisas->Append((int)Resource::MNU_CON_CLIENTES, "&Clientes", Resource::STR_CONCLIENTE);
  	mnuPesquisas->Append((int)Resource::MNU_CON_LIVROS, "&Livros", Resource::STR_CONLIVRO);
  
  	mnuVendas = new wx::Menu();
  	mnuVendas->Append((int)Resource::MNU_VEN_VENDERLIVROS, "&Vender Livros", Resource::STR_VENLIVRO);
  	mnuVendas->Append((int)Resource::MNU_VEN_VENDASREALIZADAS, "Vendas &Realizadas", Resource::STR_CONVENLIVRO);
  
  	mnuOpcoes = new wx::Menu();
  	mnuOpcoes->Append((int)Resource::MNU_OP_ALTERARSENHA, "&Alterar Senha", Resource::STR_ALTSENHA);
  	mnuOpcoes->AppendSeparator();
  	mnuOpcoes->Append((int)Resource::MNU_OP_SOBRE, "&Sobre", Resource::STR_OPSOBRE);
  	mnuOpcoes->Append((int)Resource::MNU_OP_SAIR, "Sa&ir\tCtrl-S", Resource::STR_OPSAIR);
  
  	barraMenu = new wx::MenuBar();
  	barraMenu->Append(mnuCadastros, "&Cadastros");
  	barraMenu->Append(mnuPesquisas, "&Pesquisas");
  	barraMenu->Append(mnuVendas, "&Vendas");
  	barraMenu->Append(mnuOpcoes, "&Opções");
  
  	MenuBar = barraMenu; 
  
    //Barra de ferramentas    
    barraFerra = new wx::ToolBar(this, -1, wxDefaultPosition, wxDefaultSize, 
      wx::ToolBar::wxTB_HORIZONTAL | wx::ToolBar::wxNO_BORDER);
    ToolBar = barraFerra;
    barraFerra->AddTool((int)Resource::MNU_CAD_CLIENTES, "", 
      new wx::Bitmap("xpms/cliente.xpm", wx::BitmapType::wxBITMAP_TYPE_XPM), 
      "", wx::ItemKind::wxITEM_NORMAL);
  	barraFerra->AddTool((int)Resource::MNU_CAD_LIVROS, "", 
      new wx::Bitmap("xpms/livro.xpm", wx::BitmapType::wxBITMAP_TYPE_XPM), 
      "", wx::ItemKind::wxITEM_NORMAL);
  	barraFerra->AddTool((int)Resource::MNU_VEN_VENDERLIVROS, "", 
      new wx::Bitmap("xpms/livros.xpm", wx::BitmapType::wxBITMAP_TYPE_XPM), 
      "", wx::ItemKind::wxITEM_NORMAL);
    barraFerra->AddSeparator();
  	barraFerra->AddTool((int)Resource::MNU_OP_SOBRE, "", 
      new wx::Bitmap("xpms/sobre.xpm", wx::BitmapType::wxBITMAP_TYPE_XPM), 
      "", wx::ItemKind::wxITEM_NORMAL);
  	barraFerra->AddTool((int)Resource::MNU_OP_SAIR, "", 
      new wx::Bitmap("xpms/sair.xpm", wx::BitmapType::wxBITMAP_TYPE_XPM), 
      "", wx::ItemKind::wxITEM_NORMAL);
    barraFerra->Realize();

    barraStatus = CreateStatusBar(2);
    StatusBarPane = 1;
    nLarguras = new int __gc[2];
    nLarguras[0] = 100;
    nLarguras[1] = -1;
    barraStatus->StatusWidths = nLarguras;
    barraStatus->SetStatusText(Resource::STR_USUARIO, 0);

  	FazLayout();

    EVT_MENU((int)Resource::MNU_CAD_ASSUNTOS, new wx::EventListener( this, OnMnuCadAssuntos ));
    EVT_MENU((int)Resource::MNU_CAD_AUTORES, new wx::EventListener( this, OnMnuCadAutores ));
    EVT_MENU((int)Resource::MNU_CAD_EDITORAS, new wx::EventListener( this, OnMnuCadEditoras ));
    EVT_MENU((int)Resource::MNU_CAD_ENDERECOS, new wx::EventListener( this, OnMnuCadEnderecos ));
    EVT_MENU((int)Resource::MNU_CAD_IDIOMAS, new wx::EventListener( this, OnMnuCadIdiomas ));
    EVT_MENU((int)Resource::MNU_CAD_PAISES, new wx::EventListener( this, OnMnuCadPaises ));
    EVT_MENU((int)Resource::MNU_CAD_PROFISSOES, new wx::EventListener( this, OnMnuCadProfissoes ));
    EVT_MENU((int)Resource::MNU_CAD_CLIENTES, new wx::EventListener( this, OnMnuCadClientes ));
    EVT_MENU((int)Resource::MNU_CAD_LIVROS, new wx::EventListener( this, OnMnuCadLivros ));

    EVT_MENU((int)Resource::MNU_CON_ASSUNTOS, new wx::EventListener( this, OnMnuConAssuntos ));
    EVT_MENU((int)Resource::MNU_CON_AUTORES, new wx::EventListener( this, OnMnuConAutores ));
    EVT_MENU((int)Resource::MNU_CON_EDITORAS, new wx::EventListener( this, OnMnuConEditoras ));
    EVT_MENU((int)Resource::MNU_CON_ENDERECOS, new wx::EventListener( this, OnMnuConEnderecos ));
    EVT_MENU((int)Resource::MNU_CON_IDIOMAS, new wx::EventListener( this, OnMnuConIdiomas ));
    EVT_MENU((int)Resource::MNU_CON_PAISES, new wx::EventListener( this, OnMnuConPaises ));
    EVT_MENU((int)Resource::MNU_CON_PROFISSOES, new wx::EventListener( this, OnMnuConProfissoes ));
    EVT_MENU((int)Resource::MNU_CON_CLIENTES, new wx::EventListener( this, OnMnuConClientes ));
    EVT_MENU((int)Resource::MNU_CON_LIVROS, new wx::EventListener( this, OnMnuConLivros ));

    EVT_MENU((int)Resource::MNU_VEN_VENDERLIVROS, new wx::EventListener( this, OnMnuVenderLivros ));
    EVT_MENU((int)Resource::MNU_VEN_VENDASREALIZADAS, new wx::EventListener( this, OnMnuVendasRealizadas ));

    EVT_MENU((int)Resource::MNU_OP_ALTERARSENHA, new wx::EventListener( this, OnMnuAlterarSenha ));
    EVT_MENU((int)Resource::MNU_OP_SOBRE, new wx::EventListener( this, OnMnuSobre ));
    EVT_MENU((int)Resource::MNU_OP_SAIR, new wx::EventListener( this, OnClose ));

  	EVT_CLOSE( new wx::EventListener( this, OnClose ) );
  }

  System::Void frmPrincipal::FazLayout(){
    this->Layout();
    this->Centre();
  }
  
  System::Void frmPrincipal::OnClose( System::Object* sender, wx::Event* e ){
    wx::MessageDialog* mens;
    mens = new wx::MessageDialog(this, Resource::STR_SAIRSIS, "Confirma",
     wx::Dialog::wxNO_DEFAULT | wx::Dialog::wxYES_NO | wx::Dialog::wxICON_QUESTION);
    if (mens->ShowModal() == wx::Dialog::wxID_YES)
      Destroy();      
  }

  System::Void frmPrincipal::OnMnuCadAssuntos( System::Object* sender, wx::Event* e ){
    barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_ASSUNTOS, false);
    frmFilha* fCadAssuntos = new frmFilha(this, Resource::FRMCADASSUNTOS);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuCadAutores( System::Object* sender, wx::Event* e ){
    barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_AUTORES, false);
    frmFilha* fCadAutores = new frmFilha(this, Resource::FRMCADAUTORES);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuCadEditoras( System::Object* sender, wx::Event* e ){
    barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_EDITORAS, false);
    frmFilha* fCadEditoras = new frmFilha(this, Resource::FRMCADEDITORAS);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuCadEnderecos( System::Object* sender, wx::Event* e ){
    barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_ENDERECOS, false);
    frmFilha* fCadEnderecos = new frmFilha(this, Resource::FRMCADENDERECOS);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuCadIdiomas( System::Object* sender, wx::Event* e ){
    barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_IDIOMAS, false);
    frmFilha* fCadIdiomas = new frmFilha(this, Resource::FRMCADIDIOMAS);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuCadPaises( System::Object* sender, wx::Event* e ){
    barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_PAISES, false);
    frmFilha* fCadPaises = new frmFilha(this, Resource::FRMCADPAISES);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuCadProfissoes( System::Object* sender, wx::Event* e ){
    barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_PROFISSOES, false);
    frmFilha* fCadProfissoes = new frmFilha(this, Resource::FRMCADPROFISSOES);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuCadClientes( System::Object* sender, wx::Event* e ){
    barraFerra->EnableTool(Resource::MNU_CAD_CLIENTES, false);
    barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_CLIENTES, false);
    frmFilha* fCadClientes = new frmFilha(this, Resource::FRMCADCLIENTES);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuCadLivros( System::Object* sender, wx::Event* e ){
    barraFerra->EnableTool(Resource::MNU_CAD_LIVROS, false);
    barraMenu->GetMenu(0)->Enable(Resource::MNU_CAD_LIVROS, false);
    frmFilha* fCadLivros = new frmFilha(this, Resource::FRMCADLIVROS);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuConAssuntos( System::Object* sender, wx::Event* e ){
    this->StatusBar->SetStatusText(Resource::STR_CONASSUNTO,1);
    barraMenu->GetMenu(1)->Enable(Resource::MNU_CON_ASSUNTOS, false);
    frmConAssuntos::fConAssuntos = new frmConAssuntos(this);
    frmConAssuntos::fConAssuntos->Show(true);
  	e->Skip();
  }

  System::Void frmPrincipal::OnMnuConAutores( System::Object* sender, wx::Event* e ){
    this->StatusBar->SetStatusText(Resource::STR_CONAUTOR,1);
    barraMenu->GetMenu(1)->Enable(Resource::MNU_CON_AUTORES, false);
    frmConAutores::fConAutores = new frmConAutores(this);
    frmConAutores::fConAutores->Show(true);
  	e->Skip();
  }

  System::Void frmPrincipal::OnMnuConEditoras( System::Object* sender, wx::Event* e ){
    this->StatusBar->SetStatusText(Resource::STR_CONEDITORA,1);
    barraMenu->GetMenu(1)->Enable(Resource::MNU_CON_EDITORAS, false);
    frmConEditoras::fConEditoras = new frmConEditoras(this);
    frmConEditoras::fConEditoras->Show(true);
  	e->Skip();
  }

  System::Void frmPrincipal::OnMnuConEnderecos( System::Object* sender, wx::Event* e ){
    this->StatusBar->SetStatusText(Resource::STR_CONENDERECO,1);
    barraMenu->GetMenu(1)->Enable(Resource::MNU_CON_ENDERECOS, false);
    frmConEnderecos::fConEnderecos = new frmConEnderecos(this);
    frmConEnderecos::fConEnderecos->Show(true);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuConIdiomas( System::Object* sender, wx::Event* e ){
    this->StatusBar->SetStatusText(Resource::STR_CONIDIOMA,1);
    barraMenu->GetMenu(1)->Enable(Resource::MNU_CON_IDIOMAS, false);
    frmConIdiomas::fConIdiomas = new frmConIdiomas(this);
    frmConIdiomas::fConIdiomas->Show(true);
  	e->Skip();
  }

  System::Void frmPrincipal::OnMnuConPaises( System::Object* sender, wx::Event* e ){
    this->StatusBar->SetStatusText(Resource::STR_CONPAIS,1);
    barraMenu->GetMenu(1)->Enable(Resource::MNU_CON_PAISES, false);
    frmConPaises::fConPaises = new frmConPaises(this);
    frmConPaises::fConPaises->Show(true);
  	e->Skip();
  }

  System::Void frmPrincipal::OnMnuConProfissoes( System::Object* sender, wx::Event* e ){
    this->StatusBar->SetStatusText(Resource::STR_CONPROFISS,1);
    barraMenu->GetMenu(1)->Enable(Resource::MNU_CON_PROFISSOES, false);
    frmConProfissoes::fConProfissoes = new frmConProfissoes(this);
    frmConProfissoes::fConProfissoes->Show(true);
  	e->Skip();
  }

  System::Void frmPrincipal::OnMnuConClientes( System::Object* sender, wx::Event* e ){
    this->StatusBar->SetStatusText(Resource::STR_CONCLIENTE,1);
    barraMenu->GetMenu(1)->Enable(Resource::MNU_CON_CLIENTES, false);
    frmConClientes::fConClientes = new frmConClientes(this);
    frmConClientes::fConClientes->Show(true);
  	e->Skip();
  }

  System::Void frmPrincipal::OnMnuConLivros( System::Object* sender, wx::Event* e ){
    this->StatusBar->SetStatusText(Resource::STR_CONLIVRO,1);
    barraMenu->GetMenu(1)->Enable(Resource::MNU_CON_LIVROS, false);
    frmConLivros::fConLivros = new frmConLivros(this);
    frmConLivros::fConLivros->Show(true);
  	e->Skip();
  }

  System::Void frmPrincipal::OnMnuVenderLivros( System::Object* sender, wx::Event* e ){
    barraFerra->EnableTool(Resource::MNU_VEN_VENDERLIVROS, false);
    barraMenu->GetMenu(2)->Enable(Resource::MNU_VEN_VENDERLIVROS, false);
    frmFilha* fVenderLivros = new frmFilha(this, Resource::FRMVENDERLIVROS);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuVendasRealizadas( System::Object* sender, wx::Event* e ){
    barraMenu->GetMenu(2)->Enable(Resource::MNU_VEN_VENDASREALIZADAS, false);
    frmFilha* fVendasRealizadas = new frmFilha(this, Resource::FRMCONVENDAS);
    e->Skip();
  }

  System::Void frmPrincipal::OnMnuAlterarSenha( System::Object* sender, wx::Event* e ){
    barraMenu->GetMenu(3)->Enable(Resource::MNU_OP_ALTERARSENHA, false);
    frmFilha* fAlterarSenha = new frmFilha(this, Resource::FRMALTERARSENHA);
    e->Skip();
  }
 
  System::Void frmPrincipal::OnMnuSobre( System::Object* sender, wx::Event* e ){
    frmSobre::fSobre = new frmSobre(this);
    frmSobre::fSobre->ShowModal();
    e->Skip();
	}	 
}
