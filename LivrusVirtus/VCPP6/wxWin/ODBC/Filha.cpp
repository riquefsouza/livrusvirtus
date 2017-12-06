#include "resource.h"
#include "Filha.h"
#include "Principal.h"

#ifndef __WXMOTIF__
  #include "xpms/livrus.xpm"
#endif  

BEGIN_EVENT_TABLE(CfrmFilha, wxMDIChildFrame)
    EVT_CLOSE(CfrmFilha::OnClose)
END_EVENT_TABLE()

CfrmFilha::CfrmFilha(wxMDIParentFrame *parent, int nTelaAtiva)
       : wxMDIChildFrame(parent, -1, wxT("Cadastro de"), 
       wxPoint(0, 0), wxSize(335, 140),
       wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE) {
  nLocalTelaAtiva = nTelaAtiva;
	IniciaControles();
}

void CfrmFilha::IniciaControles() {

#ifdef __WXMSW__
    this->SetIcon(wxIcon(wxT("LIVRUS_ICO")));
#else
  #ifndef __WXMOTIF__
    this->SetIcon(wxIcon( Livrus_xpm ));
  #endif
#endif
  this->SetClientSize(wxSize(335, 140));

  switch (nLocalTelaAtiva) {
    case FRMCADASSUNTOS: {
      frmCadAssuntos = new CfrmCadAssuntos( this );
      this->SetTitle(STR_CADASSUNTO);
    }
    break;    
    case FRMCADAUTORES: {
      frmCadAutores = new CfrmCadAutores( this );
      this->SetTitle(STR_CADAUTOR);
    }
    break;
    case FRMCADEDITORAS: {
      frmCadEditoras = new CfrmCadEditoras( this );
      this->SetTitle(STR_CADEDITORA);
    }
    break;
    case FRMCADENDERECOS: {
      frmCadEnderecos = new CfrmCadEnderecos( this );
      this->SetTitle(STR_CADENDERECO);
      this->SetClientSize(wxSize(525, 170));
    }
    break;
    case FRMCADIDIOMAS: {
      frmCadIdiomas = new CfrmCadIdiomas( this );
      this->SetTitle(STR_CADIDIOMA);
    }
    break;
    case FRMCADPAISES: {
      frmCadPaises = new CfrmCadPaises( this );
      this->SetTitle(STR_CADPAIS);
    }
    break;
    case FRMCADPROFISSOES: {
      frmCadProfissoes = new CfrmCadProfissoes( this );
      this->SetTitle(STR_CADPROFISS);
    }
    break;
    case FRMCADCLIENTES: {
      frmCadClientes = new CfrmCadClientes( this );
      this->SetTitle(STR_CADCLIENTE);
      this->SetClientSize(wxSize(525, 440));
    }
    break;
    case FRMCADLIVROS: {
      frmCadLivros = new CfrmCadLivros( this );
      this->SetTitle(STR_CADLIVRO);
      this->SetClientSize(wxSize(510, 425));
    }
    break;
    case FRMVENDERLIVROS: {
      frmVenderLivros = new CfrmVenderLivros( this );
      this->SetTitle(STR_VENLIVRO);
      this->SetClientSize(wxSize(480, 310));
    }
    break;
    case FRMCONVENDAS: {
      frmConVendas = new CfrmConVendas( this );
      this->SetTitle(STR_CONVENLIVRO);
      this->SetClientSize(wxSize(480, 330));
    }
    break;
    case FRMALTERARSENHA: {
      frmAlterarSenha = new CfrmAlterarSenha( this );
      this->SetTitle(STR_ALTSENHA);
      this->SetClientSize(wxSize(255, 134));
    }
    break;
  }

}

CfrmFilha::~CfrmFilha() { }


void CfrmFilha::OnClose(wxCloseEvent& event) { 

  switch (nLocalTelaAtiva) {
    case FRMCADASSUNTOS:
      frmPrincipal->barraMenu->GetMenu(0)->Enable(MNU_CAD_ASSUNTOS, true);
    break;    
    case FRMCADAUTORES: 
      frmPrincipal->barraMenu->GetMenu(0)->Enable(MNU_CAD_AUTORES, true);
    break;
    case FRMCADEDITORAS:
      frmPrincipal->barraMenu->GetMenu(0)->Enable(MNU_CAD_EDITORAS, true);
    break;
    case FRMCADENDERECOS:
      frmPrincipal->barraMenu->GetMenu(0)->Enable(MNU_CAD_ENDERECOS, true);
    break;
    case FRMCADIDIOMAS:
      frmPrincipal->barraMenu->GetMenu(0)->Enable(MNU_CAD_IDIOMAS, true);
    break;
    case FRMCADPAISES: 
      frmPrincipal->barraMenu->GetMenu(0)->Enable(MNU_CAD_PAISES, true);
    break;
    case FRMCADPROFISSOES: 
      frmPrincipal->barraMenu->GetMenu(0)->Enable(MNU_CAD_PROFISSOES, true);
    break;
    case FRMCADCLIENTES: {
      frmPrincipal->barraFerra->EnableTool(MNU_CAD_CLIENTES, true);
      frmPrincipal->barraMenu->GetMenu(0)->Enable(MNU_CAD_CLIENTES, true);
    }
    break;
    case FRMCADLIVROS: {
      frmPrincipal->barraFerra->EnableTool(MNU_CAD_LIVROS, true);
      frmPrincipal->barraMenu->GetMenu(0)->Enable(MNU_CAD_LIVROS, true);
    }
    break;
    case FRMVENDERLIVROS: {
      frmPrincipal->barraFerra->EnableTool(MNU_VEN_VENDERLIVROS, true);
      frmPrincipal->barraMenu->GetMenu(2)->Enable(MNU_VEN_VENDERLIVROS, true);
    }                      
    break;
    case FRMCONVENDAS: 
      frmPrincipal->barraMenu->GetMenu(2)->Enable(
        MNU_VEN_VENDASREALIZADAS, true);
    break;
    case FRMALTERARSENHA:
      frmPrincipal->barraMenu->GetMenu(3)->Enable(MNU_OP_ALTERARSENHA, true);
    break;
  }

  event.Skip();
}


