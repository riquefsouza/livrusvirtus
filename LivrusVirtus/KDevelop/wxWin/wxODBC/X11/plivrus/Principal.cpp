#include "resource.h"
#include "Principal.h"
#include "RotinasGlobais.h"

#include "xpms/livrus.xpm"

#include "xpms/cliente.xpm"
#include "xpms/livro.xpm"
#include "xpms/livros.xpm"
#include "xpms/sobre.xpm"
#include "xpms/sair.xpm"

CfrmPrincipal *frmPrincipal = (CfrmPrincipal *) NULL;

BEGIN_EVENT_TABLE(CfrmPrincipal, wxMDIParentFrame)
  EVT_MENU(MNU_CAD_ASSUNTOS, CfrmPrincipal::OnCadAssuntos)
  EVT_MENU(MNU_CAD_AUTORES, CfrmPrincipal::OnCadAutores)
  EVT_MENU(MNU_CAD_EDITORAS, CfrmPrincipal::OnCadEditoras)
  EVT_MENU(MNU_CAD_ENDERECOS, CfrmPrincipal::OnCadEnderecos)
  EVT_MENU(MNU_CAD_IDIOMAS, CfrmPrincipal::OnCadIdiomas)
  EVT_MENU(MNU_CAD_PAISES, CfrmPrincipal::OnCadPaises)
  EVT_MENU(MNU_CAD_PROFISSOES, CfrmPrincipal::OnCadProfissoes)
  EVT_MENU(MNU_CAD_CLIENTES, CfrmPrincipal::OnCadClientes)
  EVT_MENU(MNU_CAD_LIVROS, CfrmPrincipal::OnCadLivros)
  EVT_MENU(MNU_CON_ASSUNTOS, CfrmPrincipal::OnConAssuntos)
  EVT_MENU(MNU_CON_AUTORES, CfrmPrincipal::OnConAutores)
  EVT_MENU(MNU_CON_EDITORAS, CfrmPrincipal::OnConEditoras)
  EVT_MENU(MNU_CON_ENDERECOS, CfrmPrincipal::OnConEnderecos)
  EVT_MENU(MNU_CON_IDIOMAS, CfrmPrincipal::OnConIdiomas)
  EVT_MENU(MNU_CON_PAISES, CfrmPrincipal::OnConPaises)
  EVT_MENU(MNU_CON_PROFISSOES, CfrmPrincipal::OnConProfissoes)
  EVT_MENU(MNU_CON_CLIENTES, CfrmPrincipal::OnConClientes)
  EVT_MENU(MNU_CON_LIVROS, CfrmPrincipal::OnConLivros)
  EVT_MENU(MNU_VEN_VENDERLIVROS, CfrmPrincipal::OnVenderLivros)
  EVT_MENU(MNU_VEN_VENDASREALIZADAS, CfrmPrincipal::OnVendasRealizadas)
  EVT_MENU(MNU_OP_ALTERARSENHA, CfrmPrincipal::OnAlterarSenha)
  EVT_MENU(MNU_OP_SOBRE, CfrmPrincipal::OnSobre)
  EVT_MENU(MNU_OP_SAIR, CfrmPrincipal::OnSair)

  EVT_CLOSE(CfrmPrincipal::OnClose)
  EVT_SIZE(CfrmPrincipal::OnSize)
END_EVENT_TABLE()

CfrmPrincipal::CfrmPrincipal(wxWindow *parent)
	 : wxMDIParentFrame(parent, -1, wxT("Livrus Virtus"),
 		 wxPoint(-1, -1), wxSize(620, 440),
		 wxNO_FULL_REPAINT_ON_RESIZE | wxDEFAULT_FRAME_STYLE | 
     wxHSCROLL | wxVSCROLL) { 
     //| wxFRAME_NO_WINDOW_MENU) {
	IniciaControles();
}

void CfrmPrincipal::IniciaControles()
{
  barraFerra = new wxToolBar(this, -1); 
  IniciaBarraFerramentas(barraFerra);
  SetToolBar(barraFerra);

	this->CreateStatusBar(2);   
	int larguras[2] = {100,-1};
  this->SetStatusWidths(2, larguras);  
  this->SetStatusText(wxT(""), 1);
  this->SetStatusBarPane(1);

  // Teclas de atalho
  wxAcceleratorEntry entradas[1];
  entradas[0].Set(wxACCEL_CTRL, (int) 'S', MNU_OP_SAIR);
  wxAcceleratorTable accel(1, entradas);
  SetAcceleratorTable(accel);

  mnuCadastros = new wxMenu;
  mnuCadastros->Append(MNU_CAD_ASSUNTOS, wxT("&Assuntos"), STR_CADASSUNTO);
  mnuCadastros->Append(MNU_CAD_AUTORES, wxT("A&utores"), STR_CADAUTOR);
  mnuCadastros->Append(MNU_CAD_EDITORAS, wxT("&Editoras"), STR_CADEDITORA);
  mnuCadastros->Append(MNU_CAD_ENDERECOS, wxT("E&ndereços"), STR_CADENDERECO);
  mnuCadastros->Append(MNU_CAD_IDIOMAS, wxT("&Idiomas"), STR_CADIDIOMA);
  mnuCadastros->Append(MNU_CAD_PAISES, wxT("&Países"), STR_CADPAIS);
  mnuCadastros->Append(MNU_CAD_PROFISSOES, wxT("P&rofissões"), STR_CADPROFISS);
  mnuCadastros->AppendSeparator();
  mnuCadastros->Append(MNU_CAD_CLIENTES, wxT("&Clientes"), STR_CADCLIENTE);
  mnuCadastros->Append(MNU_CAD_LIVROS, wxT("&Livros"), STR_CADLIVRO);

  mnuPesquisas = new wxMenu;
  mnuPesquisas->Append(MNU_CON_ASSUNTOS, wxT("&Assuntos"), STR_CONASSUNTO);
  mnuPesquisas->Append(MNU_CON_AUTORES, wxT("A&utores"), STR_CONAUTOR);
  mnuPesquisas->Append(MNU_CON_EDITORAS, wxT("&Editoras"), STR_CONEDITORA);
  mnuPesquisas->Append(MNU_CON_ENDERECOS, wxT("E&ndereços"), STR_CONENDERECO);
  mnuPesquisas->Append(MNU_CON_IDIOMAS, wxT("&Idiomas"), STR_CONIDIOMA);
  mnuPesquisas->Append(MNU_CON_PAISES, wxT("&Países"), STR_CONPAIS);
  mnuPesquisas->Append(MNU_CON_PROFISSOES, wxT("P&rofissões"), STR_CONPROFISS);
  mnuPesquisas->AppendSeparator();
  mnuPesquisas->Append(MNU_CON_CLIENTES, wxT("&Clientes"), STR_CONCLIENTE);
  mnuPesquisas->Append(MNU_CON_LIVROS, wxT("&Livros"), STR_CONLIVRO);

  mnuVendas = new wxMenu;
  mnuVendas->Append(MNU_VEN_VENDERLIVROS, wxT("&Vender Livros"), STR_VENLIVRO);
  mnuVendas->Append(MNU_VEN_VENDASREALIZADAS, wxT("Vendas &Realizadas"), STR_CONVENLIVRO);
  
  mnuOpcoes = new wxMenu;
  mnuOpcoes->Append(MNU_OP_ALTERARSENHA, wxT("&Alterar Senha"), STR_ALTSENHA);
  mnuOpcoes->AppendSeparator();    
  mnuOpcoes->Append(MNU_OP_SOBRE, wxT("&Sobre"), STR_OPSOBRE);
  mnuOpcoes->Append(MNU_OP_SAIR, wxT("Sa&ir\tCtrl-S"), STR_OPSAIR);
/*
  mnuJanelas = new wxMenu;
  mnuJanelas->Append(MNU_JAN_LADOALADO_HORZ, wxT("Lado a lado &horizontal"));
  mnuJanelas->Append(MNU_JAN_LADOALADO_VERT, wxT("Lado a lado &vertical"));
  mnuJanelas->Append(MNU_JAN_EM_CASCATA, wxT("Em &cascata"));
  mnuJanelas->Append(MNU_JAN_ORGANIZAR_ICONES, wxT("&Organizar ícones"));
  this->SetWindowMenu(mnuJanelas);
*/
  barraMenu = new wxMenuBar;
  barraMenu->Append(mnuCadastros, wxT("&Cadastros"));
  barraMenu->Append(mnuPesquisas, wxT("&Pesquisas"));
  barraMenu->Append(mnuVendas, wxT("&Vendas"));
  barraMenu->Append(mnuOpcoes, wxT("&Opções"));

  this->SetMenuBar(barraMenu);
  this->Centre(wxBOTH);

#ifdef __WXMSW__
  this->SetIcon(wxIcon(wxT("LIVRUS_ICO")));
#else
  this->SetIcon(wxIcon( Livrus_xpm ));
#endif

}

void CfrmPrincipal::IniciaBarraFerramentas(wxToolBar* toolBar)
{
int i;
wxBitmap* bitmaps[5];
/*
#ifdef __WXMSW__
    bitmaps[0] = new wxBitmap( BMP_CLIENTE, wxBITMAP_TYPE_BMP );
    bitmaps[1] = new wxBitmap( BMP_LIVRO, wxBITMAP_TYPE_BMP );
    bitmaps[2] = new wxBitmap( BMP_LIVROS, wxBITMAP_TYPE_BMP );
    bitmaps[3] = new wxBitmap( BMP_SOBRE, wxBITMAP_TYPE_BMP );
    bitmaps[4] = new wxBitmap( BMP_SAIR, wxBITMAP_TYPE_BMP );
#else*/
    bitmaps[0] = new wxBitmap( cliente_xpm );
    bitmaps[1] = new wxBitmap( livro_xpm );
    bitmaps[2] = new wxBitmap( livros_xpm );
    bitmaps[3] = new wxBitmap( sobre_xpm );
    bitmaps[4] = new wxBitmap( sair_xpm );
//#endif

    int largura = 24;
    int atualX = 5;

    toolBar->AddTool( MNU_CAD_CLIENTES, *(bitmaps[0]), wxNullBitmap, FALSE, 
  		atualX, -1, (wxObject *) NULL, STR_CADCLIENTE);
    atualX += largura + 5;
    toolBar->AddTool( MNU_CAD_LIVROS, *(bitmaps[1]), wxNullBitmap, FALSE, 
	  	atualX, -1, (wxObject *) NULL, STR_CADLIVRO);
    atualX += largura + 5;
    toolBar->AddTool( MNU_VEN_VENDERLIVROS, *bitmaps[2], wxNullBitmap, FALSE, 
		  atualX, -1, (wxObject *) NULL, STR_VENLIVRO);
    atualX += largura + 5;
    toolBar->AddSeparator();
    toolBar->AddTool( MNU_OP_SOBRE, *bitmaps[3], wxNullBitmap, FALSE, 
  		atualX, -1, (wxObject *) NULL, STR_OPSOBRE);
    atualX += largura + 5;
    toolBar->AddTool( MNU_OP_SAIR, *bitmaps[4], wxNullBitmap, FALSE, 
	  	atualX, -1, (wxObject *) NULL, STR_OPSAIR);

    toolBar->Realize();

    for (i = 0; i < 5; i++)
      delete bitmaps[i];
}

void CfrmPrincipal::OnSize(wxSizeEvent& event)
{
  int w, h;
  GetClientSize(&w, &h);
	GetClientWindow()->SetSize(0, 0, w, h);

#ifdef __WXUNIVERSAL__   
    event.Skip();
#endif
}

void CfrmPrincipal::OnClose(wxCloseEvent& event)
{
  if ( event.CanVeto() ) {
    if ( wxMessageBox(wxT(STR_SAIRSIS), wxT("Confirme"),
                      wxICON_QUESTION | wxYES_NO) != wxYES ) {
      	event.Veto();
        return;
    }
  }
  event.Skip();
}

void CfrmPrincipal::OnCadAssuntos(wxCommandEvent& event ) {  
  barraMenu->GetMenu(0)->Enable(MNU_CAD_ASSUNTOS, false);
  frmFilha = new CfrmFilha(this, FRMCADASSUNTOS);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnCadAutores(wxCommandEvent& event ) {  
  barraMenu->GetMenu(0)->Enable(MNU_CAD_AUTORES, false);
  frmFilha = new CfrmFilha(this, FRMCADAUTORES);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnCadEditoras(wxCommandEvent& event ) {  
  barraMenu->GetMenu(0)->Enable(MNU_CAD_EDITORAS, false);
  frmFilha = new CfrmFilha(this, FRMCADEDITORAS);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnCadEnderecos(wxCommandEvent& event ) {  
  barraMenu->GetMenu(0)->Enable(MNU_CAD_ENDERECOS, false);
  frmFilha = new CfrmFilha(this, FRMCADENDERECOS);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnCadIdiomas(wxCommandEvent& event ) {  
  barraMenu->GetMenu(0)->Enable(MNU_CAD_IDIOMAS, false);
  frmFilha = new CfrmFilha(this, FRMCADIDIOMAS);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnCadPaises(wxCommandEvent& event ) {  
  barraMenu->GetMenu(0)->Enable(MNU_CAD_PAISES, false);
  frmFilha = new CfrmFilha(this, FRMCADPAISES);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnCadProfissoes(wxCommandEvent& event ) {  
  barraMenu->GetMenu(0)->Enable(MNU_CAD_PROFISSOES, false);
  frmFilha = new CfrmFilha(this, FRMCADPROFISSOES);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnCadClientes(wxCommandEvent& event ) {  
  barraFerra->EnableTool(MNU_CAD_CLIENTES, false);
  barraMenu->GetMenu(0)->Enable(MNU_CAD_CLIENTES, false);
  frmFilha = new CfrmFilha(this, FRMCADCLIENTES);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnCadLivros(wxCommandEvent& event ) {  
  barraFerra->EnableTool(MNU_CAD_LIVROS, false);
  barraMenu->GetMenu(0)->Enable(MNU_CAD_LIVROS, false);
  frmFilha = new CfrmFilha(this, FRMCADLIVROS);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnConAssuntos(wxCommandEvent& event ) {
  barraMenu->GetMenu(1)->Enable(MNU_CON_ASSUNTOS, false);
  frmConAssuntos = new CfrmConAssuntos(this);
  frmConAssuntos->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnConAutores(wxCommandEvent& event ) {
  barraMenu->GetMenu(1)->Enable(MNU_CON_AUTORES, false);
  frmConAutores = new CfrmConAutores(this);
  frmConAutores->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnConEditoras(wxCommandEvent& event ) {
  barraMenu->GetMenu(1)->Enable(MNU_CON_EDITORAS, false);
  frmConEditoras = new CfrmConEditoras(this);
  frmConEditoras->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnConEnderecos(wxCommandEvent& event ) {
  barraMenu->GetMenu(1)->Enable(MNU_CON_ENDERECOS, false);
  frmConEnderecos = new CfrmConEnderecos(this);
  frmConEnderecos->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnConIdiomas(wxCommandEvent& event ) {
  barraMenu->GetMenu(1)->Enable(MNU_CON_IDIOMAS, false);
  frmConIdiomas = new CfrmConIdiomas(this);
  frmConIdiomas->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnConPaises(wxCommandEvent& event ) {
  barraMenu->GetMenu(1)->Enable(MNU_CON_PAISES, false);
  frmConPaises = new CfrmConPaises(this);
  frmConPaises->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnConProfissoes(wxCommandEvent& event ) {
  barraMenu->GetMenu(1)->Enable(MNU_CON_PROFISSOES, false);
  frmConProfissoes = new CfrmConProfissoes(this);
  frmConProfissoes->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnConClientes(wxCommandEvent& event ) {
  barraMenu->GetMenu(1)->Enable(MNU_CON_CLIENTES, false);
  frmConClientes = new CfrmConClientes(this);
  frmConClientes->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnConLivros(wxCommandEvent& event ) {
  barraMenu->GetMenu(1)->Enable(MNU_CON_LIVROS, false);
  frmConLivros = new CfrmConLivros(this);
  frmConLivros->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnVenderLivros(wxCommandEvent& event ) {
  barraFerra->EnableTool(MNU_VEN_VENDERLIVROS, false);
  barraMenu->GetMenu(2)->Enable(MNU_VEN_VENDERLIVROS, false);
  frmFilha = new CfrmFilha(this, FRMVENDERLIVROS);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnVendasRealizadas(wxCommandEvent& event ) {
  barraMenu->GetMenu(2)->Enable(MNU_VEN_VENDASREALIZADAS, false);
  frmFilha = new CfrmFilha(this, FRMCONVENDAS);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnAlterarSenha(wxCommandEvent& event ) {
  barraMenu->GetMenu(3)->Enable(MNU_OP_ALTERARSENHA, false);
  frmFilha = new CfrmFilha(this, FRMALTERARSENHA);
  frmFilha->Show(true);
	event.Skip();
}

void CfrmPrincipal::OnSobre(wxCommandEvent& event )
{
  frmSobre = new CfrmSobre(this);
  frmSobre->ShowModal();
	event.Skip();
}

void CfrmPrincipal::OnSair(wxCommandEvent& event)
{
  this->Close();  
	event.Skip();
}
