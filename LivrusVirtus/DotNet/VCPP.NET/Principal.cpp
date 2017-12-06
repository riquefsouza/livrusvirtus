#include "StdAfx.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "Splash.h"
#include "Sobre.h"
#include "Login.h"
#include "AlterarSenha.h"
#include "Cadastros.h"
#include "Consultas.h"
#include "CadAssuntos.h"
#include "ConAssuntos.h"
#include "CadAutores.h"
#include "ConAutores.h"
#include "CadEditoras.h"
#include "ConEditoras.h"
#include "CadEnderecos.h"
#include "ConEnderecos.h"
#include "CadIdiomas.h"
#include "ConIdiomas.h"
#include "CadPaises.h"
#include "ConPaises.h"
#include "CadProfissoes.h"
#include "ConProfissoes.h"
#include "CadClientes.h"
#include "ConClientes.h"
#include "CadLivros.h"
#include "ConLivros.h"
#include "VenderLivros.h"
#include "ConVendas.h"

namespace Livrus
{

  frmPrincipal::frmPrincipal(void)
  {
  	InitializeComponent();
  }

  System::Void frmPrincipal::Dispose(System::Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);
  }

  System::Void frmPrincipal::InitializeComponent()
  {
  	this->components = new System::ComponentModel::Container();
  	System::Resources::ResourceManager* resources = new System::Resources::ResourceManager(__typeof(frmPrincipal));
  	//System::Resources::ResourceManager* resources = new System::Resources::ResourceManager(GetType());
  	this->mainMenu1 = new System::Windows::Forms::MainMenu();
  	this->mnuCadastros = new System::Windows::Forms::MenuItem();
  	this->mnuCadAssuntos = new System::Windows::Forms::MenuItem();
  	this->mnuCadAutores = new System::Windows::Forms::MenuItem();
  	this->mnuCadEditoras = new System::Windows::Forms::MenuItem();
  	this->mnuCadEnderecos = new System::Windows::Forms::MenuItem();
  	this->mnuCadIdiomas = new System::Windows::Forms::MenuItem();
  	this->mnuCadPaises = new System::Windows::Forms::MenuItem();
  	this->mnuCadProfissoes = new System::Windows::Forms::MenuItem();
  	this->menuItem1 = new System::Windows::Forms::MenuItem();
  	this->mnuCadClientes = new System::Windows::Forms::MenuItem();
  	this->mnuCadLivros = new System::Windows::Forms::MenuItem();
  	this->mnuPesquisas = new System::Windows::Forms::MenuItem();
  	this->mnuConAssuntos = new System::Windows::Forms::MenuItem();
  	this->mnuConAutores = new System::Windows::Forms::MenuItem();
  	this->mnuConEditoras = new System::Windows::Forms::MenuItem();
  	this->mnuConEnderecos = new System::Windows::Forms::MenuItem();
  	this->mnuConIdiomas = new System::Windows::Forms::MenuItem();
  	this->mnuConPaises = new System::Windows::Forms::MenuItem();
  	this->mnuConProfissoes = new System::Windows::Forms::MenuItem();
  	this->menuItem2 = new System::Windows::Forms::MenuItem();
  	this->mnuConClientes = new System::Windows::Forms::MenuItem();
  	this->mnuConLivros = new System::Windows::Forms::MenuItem();
  	this->mnuVendas = new System::Windows::Forms::MenuItem();
  	this->mnuVenderLivros = new System::Windows::Forms::MenuItem();
  	this->mnuVendasRealizadas = new System::Windows::Forms::MenuItem();
  	this->mnuJanelas = new System::Windows::Forms::MenuItem();
  	this->mnuLadoALadoHorizontal = new System::Windows::Forms::MenuItem();
  	this->mnuLadoALadoVertical = new System::Windows::Forms::MenuItem();
  	this->mnuEmCascata = new System::Windows::Forms::MenuItem();
  	this->mnuOrganizarIcones = new System::Windows::Forms::MenuItem();
  	this->mnuOpcoes = new System::Windows::Forms::MenuItem();
  	this->mnuAlterarSenha = new System::Windows::Forms::MenuItem();
  	this->menuItem3 = new System::Windows::Forms::MenuItem();
  	this->mnuSobre = new System::Windows::Forms::MenuItem();
  	this->mnuSair = new System::Windows::Forms::MenuItem();
  	this->statusBar1 = new System::Windows::Forms::StatusBar();
  	this->statusBarPanel1 = new System::Windows::Forms::StatusBarPanel();
  	this->statusBarPanel2 = new System::Windows::Forms::StatusBarPanel();
  	this->toolBar1 = new System::Windows::Forms::ToolBar();
  	this->tlbClientes = new System::Windows::Forms::ToolBarButton();
  	this->tlbLivros = new System::Windows::Forms::ToolBarButton();
  	this->tlbVender = new System::Windows::Forms::ToolBarButton();
  	this->toolBarButton4 = new System::Windows::Forms::ToolBarButton();
  	this->tlbSobre = new System::Windows::Forms::ToolBarButton();
  	this->tlbSair = new System::Windows::Forms::ToolBarButton();
  	this->imageList1 = new System::Windows::Forms::ImageList(this->components);
  	this->db = new System::Data::OleDb::OleDbConnection();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->statusBarPanel1))->BeginInit();
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->statusBarPanel2))->BeginInit();
  	this->SuspendLayout();
  	// 
  	// mainMenu1
  	// 
  	System::Windows::Forms::MenuItem* mainTemp[] = new System::Windows::Forms::MenuItem*[5];
  	mainTemp[0]= this->mnuCadastros; 
  	mainTemp[1]= this->mnuPesquisas; 
  	mainTemp[2]= this->mnuVendas; 
  	mainTemp[3]= this->mnuJanelas; 
  	mainTemp[4]= this->mnuOpcoes;
  	this->mainMenu1->MenuItems->AddRange(mainTemp);
  	// 
  	// mnuCadastros
  	// 
  	this->mnuCadastros->Index = 0;
  	System::Windows::Forms::MenuItem* cadastrosTemp[] = new System::Windows::Forms::MenuItem*[10];
  	cadastrosTemp[0]= this->mnuCadAssuntos;
  	cadastrosTemp[1]= this->mnuCadAutores;
  	cadastrosTemp[2]= this->mnuCadEditoras;
  	cadastrosTemp[3]= this->mnuCadEnderecos;
  	cadastrosTemp[4]= this->mnuCadIdiomas;
  	cadastrosTemp[5]= this->mnuCadPaises;
  	cadastrosTemp[6]= this->mnuCadProfissoes;
  	cadastrosTemp[7]= this->menuItem1;
  	cadastrosTemp[8]= this->mnuCadClientes;
  	cadastrosTemp[9]= this->mnuCadLivros;
  	this->mnuCadastros->MenuItems->AddRange(cadastrosTemp);
  	this->mnuCadastros->Text = S"&Cadastros";
  	// 
  	// mnuCadAssuntos
  	// 
  	this->mnuCadAssuntos->Index = 0;
  	this->mnuCadAssuntos->Text = S"&Assuntos";
  	this->mnuCadAssuntos->Click += new System::EventHandler(this,mnuCadAssuntos_Click);
  	// 
  	// mnuCadAutores
  	// 
  	this->mnuCadAutores->Index = 1;
  	this->mnuCadAutores->Text = S"Au&tores";
  	this->mnuCadAutores->Click += new System::EventHandler(this,mnuCadAutores_Click);
  	// 
  	// mnuCadEditoras
  	// 
  	this->mnuCadEditoras->Index = 2;
  	this->mnuCadEditoras->Text = S"&Editoras";
  	this->mnuCadEditoras->Click += new System::EventHandler(this,mnuCadEditoras_Click);
  	// 
  	// mnuCadEnderecos
  	// 
  	this->mnuCadEnderecos->Index = 3;
  	this->mnuCadEnderecos->Text = S"E&ndereços";
  	this->mnuCadEnderecos->Click += new System::EventHandler(this,mnuCadEnderecos_Click);
  	// 
  	// mnuCadIdiomas
  	// 
  	this->mnuCadIdiomas->Index = 4;
  	this->mnuCadIdiomas->Text = S"&Idiomas";
  	this->mnuCadIdiomas->Click += new System::EventHandler(this,mnuCadIdiomas_Click);
  	// 
  	// mnuCadPaises
  	// 
  	this->mnuCadPaises->Index = 5;
  	this->mnuCadPaises->Text = S"&Países";
  	this->mnuCadPaises->Click += new System::EventHandler(this,mnuCadPaises_Click);
  	// 
  	// mnuCadProfissoes
  	// 
  	this->mnuCadProfissoes->Index = 6;
  	this->mnuCadProfissoes->Text = S"P&rofissões";
  	this->mnuCadProfissoes->Click += new System::EventHandler(this,mnuCadProfissoes_Click);
  	// 
  	// menuItem1
  	// 
  	this->menuItem1->Index = 7;
  	this->menuItem1->Text = S"-";
  	// 
  	// mnuCadClientes
  	// 
  	this->mnuCadClientes->Index = 8;
  	this->mnuCadClientes->Text = S"&Clientes";
  	this->mnuCadClientes->Click += new System::EventHandler(this,mnuCadClientes_Click);
  	// 
  	// mnuCadLivros
  	// 
  	this->mnuCadLivros->Index = 9;
  	this->mnuCadLivros->Text = S"&Livros";
  	this->mnuCadLivros->Click += new System::EventHandler(this,mnuCadLivros_Click);
  	// 
  	// mnuPesquisas
  	// 
  	this->mnuPesquisas->Index = 1;
  	System::Windows::Forms::MenuItem* pesquisasTemp[] = new System::Windows::Forms::MenuItem*[10];
  	pesquisasTemp[0]= this->mnuConAssuntos;
  	pesquisasTemp[1]= this->mnuConAutores;
  	pesquisasTemp[2]= this->mnuConEditoras;
  	pesquisasTemp[3]= this->mnuConEnderecos;
  	pesquisasTemp[4]= this->mnuConIdiomas;
  	pesquisasTemp[5]= this->mnuConPaises;
  	pesquisasTemp[6]= this->mnuConProfissoes;
  	pesquisasTemp[7]= this->menuItem2;
  	pesquisasTemp[8]= this->mnuConClientes;
  	pesquisasTemp[9]= this->mnuConLivros;
  	this->mnuPesquisas->MenuItems->AddRange(pesquisasTemp);
  	this->mnuPesquisas->Text = S"&Pesquisas";
  	// 
  	// mnuConAssuntos
  	// 
  	this->mnuConAssuntos->Index = 0;
  	this->mnuConAssuntos->Text = S"&Assuntos";
  	this->mnuConAssuntos->Click += new System::EventHandler(this,mnuConAssuntos_Click);
  	// 
  	// mnuConAutores
  	// 
  	this->mnuConAutores->Index = 1;
  	this->mnuConAutores->Text = S"Au&tores";
  	this->mnuConAutores->Click += new System::EventHandler(this,mnuConAutores_Click);
  	// 
  	// mnuConEditoras
  	// 
  	this->mnuConEditoras->Index = 2;
  	this->mnuConEditoras->Text = S"&Editoras";
  	this->mnuConEditoras->Click += new System::EventHandler(this,mnuConEditoras_Click);
  	// 
  	// mnuConEnderecos
  	// 
  	this->mnuConEnderecos->Index = 3;
  	this->mnuConEnderecos->Text = S"E&ndereços";
  	this->mnuConEnderecos->Click += new System::EventHandler(this,mnuConEnderecos_Click);
  	// 
  	// mnuConIdiomas
  	// 
  	this->mnuConIdiomas->Index = 4;
  	this->mnuConIdiomas->Text = S"&Idiomas";
  	this->mnuConIdiomas->Click += new System::EventHandler(this,mnuConIdiomas_Click);
  	// 
  	// mnuConPaises
  	// 
  	this->mnuConPaises->Index = 5;
  	this->mnuConPaises->Text = S"&Países";
  	this->mnuConPaises->Click += new System::EventHandler(this,mnuConPaises_Click);
  	// 
  	// mnuConProfissoes
  	// 
  	this->mnuConProfissoes->Index = 6;
  	this->mnuConProfissoes->Text = S"P&rofissões";
  	this->mnuConProfissoes->Click += new System::EventHandler(this,mnuConProfissoes_Click);
  	// 
  	// menuItem2
  	// 
  	this->menuItem2->Index = 7;
  	this->menuItem2->Text = S"-";
  	// 
  	// mnuConClientes
  	// 
  	this->mnuConClientes->Index = 8;
  	this->mnuConClientes->Text = S"&Clientes";
  	this->mnuConClientes->Click += new System::EventHandler(this,mnuConClientes_Click);
  	// 
  	// mnuConLivros
  	// 
  	this->mnuConLivros->Index = 9;
  	this->mnuConLivros->Text = S"&Livros";
  	this->mnuConLivros->Click += new System::EventHandler(this,mnuConLivros_Click);
  	// 
  	// mnuVendas
  	// 
  	this->mnuVendas->Index = 2;
  	System::Windows::Forms::MenuItem* vendasTemp[] = new System::Windows::Forms::MenuItem*[2];
  	vendasTemp[0]= this->mnuVenderLivros;
  	vendasTemp[1]= this->mnuVendasRealizadas;
  	this->mnuVendas->MenuItems->AddRange(vendasTemp);
  	this->mnuVendas->Text = S"&Vendas";
  	// 
  	// mnuVenderLivros
  	// 
  	this->mnuVenderLivros->Index = 0;
  	this->mnuVenderLivros->Text = S"&Vender Livros";
  	this->mnuVenderLivros->Click += new System::EventHandler(this,mnuVenderLivros_Click);
  	// 
  	// mnuVendasRealizadas
  	// 
  	this->mnuVendasRealizadas->Index = 1;
  	this->mnuVendasRealizadas->Text = S"Vendas &Realizadas";
  	this->mnuVendasRealizadas->Click += new System::EventHandler(this,mnuVendasRealizadas_Click);
  	// 
  	// mnuJanelas
  	// 
  	this->mnuJanelas->Index = 3;
  	this->mnuJanelas->MdiList = true;
  	System::Windows::Forms::MenuItem* janelasTemp[] = new System::Windows::Forms::MenuItem*[4];
  	janelasTemp[0]= this->mnuLadoALadoHorizontal;
  	janelasTemp[1]= this->mnuLadoALadoVertical;
  	janelasTemp[2]= this->mnuEmCascata;
  	janelasTemp[3]= this->mnuOrganizarIcones;
  	this->mnuJanelas->MenuItems->AddRange(janelasTemp);
  	this->mnuJanelas->Text = S"&Janelas";
  	// 
  	// mnuLadoALadoHorizontal
  	// 
  	this->mnuLadoALadoHorizontal->Index = 0;
  	this->mnuLadoALadoHorizontal->Text = S"Lado a lado &horizontal";
  	this->mnuLadoALadoHorizontal->Click += new System::EventHandler(this,mnuLadoALadoHorizontal_Click);
  	// 
  	// mnuLadoALadoVertical
  	// 
  	this->mnuLadoALadoVertical->Index = 1;
  	this->mnuLadoALadoVertical->Text = S"Lado a lado &vertical";
  	this->mnuLadoALadoVertical->Click += new System::EventHandler(this,mnuLadoALadoVertical_Click);
  	// 
  	// mnuEmCascata
  	// 
  	this->mnuEmCascata->Index = 2;
  	this->mnuEmCascata->Text = S"Em &cascata";
  	this->mnuEmCascata->Click += new System::EventHandler(this,mnuEmCascata_Click);
  	// 
  	// mnuOrganizarIcones
  	// 
  	this->mnuOrganizarIcones->Index = 3;
  	this->mnuOrganizarIcones->Text = S"&Organizar ícones";
  	this->mnuOrganizarIcones->Click += new System::EventHandler(this,mnuOrganizarIcones_Click);
  	// 
  	// mnuOpcoes
  	// 
  	this->mnuOpcoes->Index = 4;
  	System::Windows::Forms::MenuItem* opcoesTemp[] = new System::Windows::Forms::MenuItem*[4];
  	opcoesTemp[0]= this->mnuAlterarSenha;
  	opcoesTemp[1]= this->menuItem3;
  	opcoesTemp[2]= this->mnuSobre;
  	opcoesTemp[3]= this->mnuSair;
  	this->mnuOpcoes->MenuItems->AddRange(opcoesTemp);
  	this->mnuOpcoes->Text = S"&Opções";
  	// 
  	// mnuAlterarSenha
  	// 
  	this->mnuAlterarSenha->Index = 0;
  	this->mnuAlterarSenha->Text = S"&Alterar Senha";
  	this->mnuAlterarSenha->Click += new System::EventHandler(this,mnuAlterarSenha_Click);
  	// 
  	// menuItem3
  	// 
  	this->menuItem3->Index = 1;
  	this->menuItem3->Text = S"-";
  	// 
  	// mnuSobre
  	// 
  	this->mnuSobre->Index = 2;
  	this->mnuSobre->Text = S"&Sobre";
  	this->mnuSobre->Click += new System::EventHandler(this,mnuSobre_Click);
  	// 
  	// mnuSair
  	// 
  	this->mnuSair->Index = 3;
  	this->mnuSair->Text = S"Sa&ir";
  	this->mnuSair->Click += new System::EventHandler(this,mnuSair_Click);
  	// 
  	// statusBar1
  	// 
  	this->statusBar1->Location = System::Drawing::Point(0, 348);
  	this->statusBar1->Name = S"statusBar1";
  	System::Windows::Forms::StatusBarPanel* spanelsTemp[] = new System::Windows::Forms::StatusBarPanel*[2];
  	spanelsTemp[0]=	this->statusBarPanel1;
  	spanelsTemp[1]=	this->statusBarPanel2;
  	this->statusBar1->Panels->AddRange(spanelsTemp);
  	this->statusBar1->ShowPanels = true;
  	this->statusBar1->Size = System::Drawing::Size(480, 22);
  	this->statusBar1->TabIndex = 1;
  	// 
  	// statusBarPanel1
  	// 
  	this->statusBarPanel1->AutoSize = System::Windows::Forms::StatusBarPanelAutoSize::Contents;
  	this->statusBarPanel1->Text = S"Usuário:";
  	this->statusBarPanel1->Width = 56;
  	// 
  	// statusBarPanel2
  	// 
  	this->statusBarPanel2->AutoSize = System::Windows::Forms::StatusBarPanelAutoSize::Spring;
  	this->statusBarPanel2->Width = 408;
  	// 
  	// toolBar1
  	// 
  	System::Windows::Forms::ToolBarButton* tbuttonsTemp[] = new System::Windows::Forms::ToolBarButton*[6];
  	tbuttonsTemp[0]= this->tlbClientes;
  	tbuttonsTemp[1]= this->tlbLivros;
  	tbuttonsTemp[2]= this->tlbVender;
  	tbuttonsTemp[3]= this->toolBarButton4;
  	tbuttonsTemp[4]= this->tlbSobre;
  	tbuttonsTemp[5]= this->tlbSair;
  	this->toolBar1->Buttons->AddRange(tbuttonsTemp);
  	this->toolBar1->DropDownArrows = true;
  	this->toolBar1->ImageList = this->imageList1;
  	this->toolBar1->Location = System::Drawing::Point(0, 0);
  	this->toolBar1->Name = S"toolBar1";
  	this->toolBar1->ShowToolTips = true;
  	this->toolBar1->Size = System::Drawing::Size(480, 28);
  	this->toolBar1->TabIndex = 2;
  	this->toolBar1->ButtonClick += new System::Windows::Forms::ToolBarButtonClickEventHandler(this,toolBar1_ButtonClick);
  	// 
  	// tlbClientes
  	// 
  	this->tlbClientes->ImageIndex = 0;
  	// 
  	// tlbLivros
  	// 
  	this->tlbLivros->ImageIndex = 1;
  	// 
  	// tlbVender
  	// 
  	this->tlbVender->ImageIndex = 2;
  	// 
  	// toolBarButton4
  	// 
  	this->toolBarButton4->Style = System::Windows::Forms::ToolBarButtonStyle::Separator;
  	// 
  	// tlbSobre
  	// 
  	this->tlbSobre->ImageIndex = 3;
  	// 
  	// tlbSair
  	// 
  	this->tlbSair->ImageIndex = 4;
  	// 
  	// imageList1
  	// 
  	this->imageList1->ImageSize = System::Drawing::Size(16, 16);
  	this->imageList1->ImageStream = dynamic_cast<System::Windows::Forms::ImageListStreamer*>(resources->GetObject(S"imageList1.ImageStream"));
  	this->imageList1->TransparentColor = System::Drawing::Color::Olive;
  	// 
  	// frmPrincipal
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->ClientSize = System::Drawing::Size(480, 370);
  	this->Controls->Add(this->toolBar1);
  	this->Controls->Add(this->statusBar1);
  	this->Icon = dynamic_cast<System::Drawing::Icon*>(resources->GetObject(S"$this.Icon"));
  	this->IsMdiContainer = true;
  	this->Menu = this->mainMenu1;
  	this->Name = S"frmPrincipal";
  	this->Text = S"Livrus Virtus";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmPrincipal_Closing);
  	this->Load += new System::EventHandler(this,frmPrincipal_Load);
  	this->MouseMove += new System::Windows::Forms::MouseEventHandler(this,frmPrincipal_MouseMove);
  	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->statusBarPanel1))->EndInit();
	(dynamic_cast<System::ComponentModel::ISupportInitialize*>(this->statusBarPanel2))->EndInit();
  	this->ResumeLayout(false);
  }
  
  System::Void frmPrincipal::frmPrincipal_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  
  	System::Windows::Forms::DialogResult res;			
  	res = System::Windows::Forms::MessageBox::Show(this, S"Deseja sair do sistema?",
  	frmPrincipal::fPrincipal->Text, MessageBoxButtons::YesNo,
  	MessageBoxIcon::Question,MessageBoxDefaultButton::Button2);
  
  	if (res == DialogResult::Yes) {
  		db->Close();
  		e->Cancel=false;
  	 } else
  		e->Cancel=true;
  
  }
  
  System::Void frmPrincipal::toolBar1_ButtonClick(Object* sender, System::Windows::Forms::ToolBarButtonClickEventArgs* e)
  {
     switch(toolBar1->Buttons->IndexOf(e->Button))
     {
  	  case 0:
  		 mnuCadClientes_Click(this,System::EventArgs::Empty);
  		 break;
  	  case 1:
  		 mnuCadLivros_Click(this,System::EventArgs::Empty);
  		 break;
  	  case 2:			  
  		 mnuVenderLivros_Click(this,System::EventArgs::Empty);
  		 break;
  	  case 4:			  
  		 mnuSobre_Click(this,System::EventArgs::Empty);
  		 break;
  	  case 5:
  		 mnuSair_Click(this,System::EventArgs::Empty);
  		 break;
  	}
  }
  
  System::Void frmPrincipal::frmPrincipal_Load(Object* sender, System::EventArgs* e)
  {
    db->Open();
  
    ConsultasSQL::ConsSQL = new ConsultasSQL();
    RotinasGlobais::Rotinas = new RotinasGlobais();
  
    frmSplash::fSplash = new frmSplash();
    frmSplash::fSplash->ShowDialog();
  
    frmLogin::fLogin = new frmLogin();
    frmLogin::fLogin->ShowDialog();
  
  }
  
  System::Void frmPrincipal::mnuSair_Click(Object* sender, System::EventArgs* e)
  {
  	Close();
  }
  
  System::Void frmPrincipal::mnuLadoALadoHorizontal_Click(Object* sender, System::EventArgs* e)
  {
  	this->LayoutMdi(MdiLayout::TileHorizontal);
  }
  
  System::Void frmPrincipal::mnuLadoALadoVertical_Click(Object* sender, System::EventArgs* e)
  {
  	this->LayoutMdi(MdiLayout::TileVertical);
  }
  
  System::Void frmPrincipal::mnuEmCascata_Click(Object* sender, System::EventArgs* e)
  {
  	this->LayoutMdi(MdiLayout::Cascade);
  }
  
  System::Void frmPrincipal::mnuOrganizarIcones_Click(Object* sender, System::EventArgs* e)
  {
  	this->LayoutMdi(MdiLayout::ArrangeIcons);
  }
  
  System::Void frmPrincipal::mnuSobre_Click(Object* sender, System::EventArgs* e)
  {
  	frmSobre::fSobre = new frmSobre();
  	frmSobre::fSobre->ShowDialog();
  }
  
  System::Void frmPrincipal::frmPrincipal_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e)
  {
  	fPrincipal->statusBar1->Panels->Item[1]->Text=S" ";
  }
  
  System::Void frmPrincipal::mnuAlterarSenha_Click(Object* sender, System::EventArgs* e)
  {
	mnuAlterarSenha->Enabled=false;
  	frmAlterarSenha::fAlterarSenha = new frmAlterarSenha();
  	frmAlterarSenha::fAlterarSenha->MdiParent=this;
  	frmAlterarSenha::fAlterarSenha->Show();
  }
  System::Void frmPrincipal::mnuCadAssuntos_Click(Object* sender, System::EventArgs* e) {
	mnuCadAssuntos->Enabled=false;
  	frmCadAssuntos::fCadAssuntos = new frmCadAssuntos();
  	frmCadAssuntos::fCadAssuntos->MdiParent=this;
  	frmCadAssuntos::fCadAssuntos->Show();
  } 
  System::Void frmPrincipal::mnuConAssuntos_Click(Object* sender, System::EventArgs* e) {
	mnuConAssuntos->Enabled=false;
  	frmConAssuntos::fConAssuntos = new frmConAssuntos();
  	frmConAssuntos::fConAssuntos->MdiParent=this;
  	frmConAssuntos::fConAssuntos->Show();
  }
  System::Void frmPrincipal::mnuCadAutores_Click(Object* sender, System::EventArgs* e) {
	mnuCadAutores->Enabled=false;
  	frmCadAutores::fCadAutores = new frmCadAutores();
  	frmCadAutores::fCadAutores->MdiParent=this;
  	frmCadAutores::fCadAutores->Show();
  } 
  System::Void frmPrincipal::mnuConAutores_Click(Object* sender, System::EventArgs* e) {
	mnuConAutores->Enabled=false;
  	frmConAutores::fConAutores = new frmConAutores();
  	frmConAutores::fConAutores->MdiParent=this;
  	frmConAutores::fConAutores->Show();
  }
  System::Void frmPrincipal::mnuCadEditoras_Click(Object* sender, System::EventArgs* e) {
	mnuCadEditoras->Enabled=false;
  	frmCadEditoras::fCadEditoras = new frmCadEditoras();
  	frmCadEditoras::fCadEditoras->MdiParent=this;
  	frmCadEditoras::fCadEditoras->Show();
  } 
  System::Void frmPrincipal::mnuConEditoras_Click(Object* sender, System::EventArgs* e) {
	mnuConEditoras->Enabled=false;
  	frmConEditoras::fConEditoras = new frmConEditoras();
  	frmConEditoras::fConEditoras->MdiParent=this;
  	frmConEditoras::fConEditoras->Show();
  }
  System::Void frmPrincipal::mnuCadEnderecos_Click(Object* sender, System::EventArgs* e) {
	mnuCadEnderecos->Enabled=false;
  	frmCadEnderecos::fCadEnderecos = new frmCadEnderecos();
  	frmCadEnderecos::fCadEnderecos->MdiParent=this;
  	frmCadEnderecos::fCadEnderecos->Show();
  } 
  System::Void frmPrincipal::mnuConEnderecos_Click(Object* sender, System::EventArgs* e) {
	mnuConEnderecos->Enabled=false;
  	frmConEnderecos::fConEnderecos = new frmConEnderecos();
  	frmConEnderecos::fConEnderecos->MdiParent=this;
  	frmConEnderecos::fConEnderecos->Show();
  }
  System::Void frmPrincipal::mnuCadIdiomas_Click(Object* sender, System::EventArgs* e) {
	mnuCadIdiomas->Enabled=false;
  	frmCadIdiomas::fCadIdiomas = new frmCadIdiomas();
  	frmCadIdiomas::fCadIdiomas->MdiParent=this;
  	frmCadIdiomas::fCadIdiomas->Show();
  } 
  System::Void frmPrincipal::mnuConIdiomas_Click(Object* sender, System::EventArgs* e) {
	mnuConIdiomas->Enabled=false;
  	frmConIdiomas::fConIdiomas = new frmConIdiomas();
  	frmConIdiomas::fConIdiomas->MdiParent=this;
  	frmConIdiomas::fConIdiomas->Show();
  }
  System::Void frmPrincipal::mnuCadPaises_Click(Object* sender, System::EventArgs* e) {
	mnuCadPaises->Enabled=false;
  	frmCadPaises::fCadPaises = new frmCadPaises();
  	frmCadPaises::fCadPaises->MdiParent=this;
  	frmCadPaises::fCadPaises->Show();
  } 
  System::Void frmPrincipal::mnuConPaises_Click(Object* sender, System::EventArgs* e) {
	mnuConPaises->Enabled=false;
  	frmConPaises::fConPaises = new frmConPaises();
  	frmConPaises::fConPaises->MdiParent=this;
  	frmConPaises::fConPaises->Show();
  }
  System::Void frmPrincipal::mnuCadProfissoes_Click(Object* sender, System::EventArgs* e) {
	mnuCadProfissoes->Enabled=false;
  	frmCadProfissoes::fCadProfissoes = new frmCadProfissoes();
  	frmCadProfissoes::fCadProfissoes->MdiParent=this;
  	frmCadProfissoes::fCadProfissoes->Show();
  } 
  System::Void frmPrincipal::mnuConProfissoes_Click(Object* sender, System::EventArgs* e) {
	mnuConProfissoes->Enabled=false;
  	frmConProfissoes::fConProfissoes = new frmConProfissoes();
  	frmConProfissoes::fConProfissoes->MdiParent=this;
  	frmConProfissoes::fConProfissoes->Show();
  }
  System::Void frmPrincipal::mnuCadClientes_Click(Object* sender, System::EventArgs* e) {
	mnuCadClientes->Enabled=false;
	tlbClientes->Enabled=false;
  	frmCadClientes::fCadClientes = new frmCadClientes();
  	frmCadClientes::fCadClientes->MdiParent=this;
  	frmCadClientes::fCadClientes->Show();
  } 
  System::Void frmPrincipal::mnuConClientes_Click(Object* sender, System::EventArgs* e) {
	mnuConClientes->Enabled=false;
  	frmConClientes::fConClientes = new frmConClientes();
  	frmConClientes::fConClientes->MdiParent=this;
  	frmConClientes::fConClientes->Show();
  }
  System::Void frmPrincipal::mnuCadLivros_Click(Object* sender, System::EventArgs* e) {
	mnuCadLivros->Enabled=false;
	tlbLivros->Enabled=false;
  	frmCadLivros::fCadLivros = new frmCadLivros();
  	frmCadLivros::fCadLivros->MdiParent=this;
  	frmCadLivros::fCadLivros->Show();
  } 
  System::Void frmPrincipal::mnuConLivros_Click(Object* sender, System::EventArgs* e) {
	mnuConLivros->Enabled=false;
  	frmConLivros::fConLivros = new frmConLivros();
  	frmConLivros::fConLivros->MdiParent=this;
  	frmConLivros::fConLivros->Show();
  }
  System::Void frmPrincipal::mnuVenderLivros_Click(Object* sender, System::EventArgs* e) {
	mnuVenderLivros->Enabled=false;
	tlbVender->Enabled=false;
  	frmVenderLivros::fVenderLivros = new frmVenderLivros();
  	frmVenderLivros::fVenderLivros->MdiParent=this;
  	frmVenderLivros::fVenderLivros->Show();
  } 
  System::Void frmPrincipal::mnuVendasRealizadas_Click(Object* sender, System::EventArgs* e) {
	mnuVendasRealizadas->Enabled=false;
  	frmConVendas::fConVendas = new frmConVendas();
  	frmConVendas::fConVendas->MdiParent=this;
  	frmConVendas::fConVendas->Show();
  }

}
