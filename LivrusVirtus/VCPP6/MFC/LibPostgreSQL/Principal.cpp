// Principal.cpp : implementation of the CFrmPrincipal class
//

#include "stdafx.h"
#include "Livrus.h"

#include "Principal.h"
#include "RotinasGlobais.h"
#include "Filha.h"
#include "Sobre.h"
#include "ConAssuntos.h"
#include "ConAutores.h"
#include "ConEditoras.h"
#include "ConEnderecos.h"
#include "ConIdiomas.h"
#include "ConPaises.h"
#include "ConProfissoes.h"
#include "ConClientes.h"
#include "ConLivros.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmPrincipal

IMPLEMENT_DYNAMIC(CFrmPrincipal, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CFrmPrincipal, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CFrmPrincipal)
	ON_WM_CREATE()
	ON_COMMAND(CM_CAD_ASSUNTOS, OnCadAssuntos)
	ON_COMMAND(CM_CAD_AUTORES, OnCadAutores)
	ON_COMMAND(CM_OP_SOBRE, OnOpSobre)
	ON_COMMAND(CM_OP_SAIR, OnOpSair)
	ON_WM_CLOSE()
	ON_COMMAND(CM_CON_ASSUNTOS, OnConAssuntos)
	ON_COMMAND(CM_OP_ALTERARSENHA, OnOpAlterarsenha)
	ON_COMMAND(CM_CAD_EDITORAS, OnCadEditoras)
	ON_COMMAND(CM_CAD_ENDERECOS, OnCadEnderecos)
	ON_COMMAND(CM_CAD_IDIOMAS, OnCadIdiomas)
	ON_COMMAND(CM_CAD_PAISES, OnCadPaises)
	ON_COMMAND(CM_CAD_PROFISSOES, OnCadProfissoes)
	ON_COMMAND(CM_CAD_CLIENTES, OnCadClientes)
	ON_COMMAND(CM_CON_AUTORES, OnConAutores)
	ON_COMMAND(CM_CON_CLIENTES, OnConClientes)
	ON_COMMAND(CM_CON_EDITORAS, OnConEditoras)
	ON_COMMAND(CM_CON_ENDERECOS, OnConEnderecos)
	ON_COMMAND(CM_CON_IDIOMAS, OnConIdiomas)
	ON_COMMAND(CM_CON_LIVROS, OnConLivros)
	ON_COMMAND(CM_CON_PAISES, OnConPaises)
	ON_COMMAND(CM_CON_PROFISSOES, OnConProfissoes)
	ON_COMMAND(CM_CAD_LIVROS, OnCadLivros)
	ON_COMMAND(CM_VEN_VENDERLIVROS, OnVenVenderlivros)
	ON_COMMAND(CM_VEN_VENDASREALIZADAS, OnVenVendasRealizadas)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicadores[] =
{ 
  STR_USUARIO,
  ID_SEPARATOR,           // indicador da linha de status    
	ID_INDICADOR_CAPS,
	ID_INDICADOR_NUM,
	ID_INDICADOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CFrmPrincipal construction/destruction

CFrmPrincipal::CFrmPrincipal()
{
  frmConAssuntos = NULL;
  frmConAutores = NULL;
  frmConEditoras = NULL;
  frmConEnderecos = NULL;
  frmConIdiomas = NULL;
  frmConPaises = NULL;
  frmConProfissoes = NULL;
  frmConClientes = NULL;
  frmConLivros = NULL;
}

CFrmPrincipal::~CFrmPrincipal()
{
}

int CFrmPrincipal::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	//TBSTYLE_FLAT | WS_CHILD | WS_VISIBLE | CBRS_TOP
//		 | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC
	if (!m_hBarraFerram.CreateEx(this, WS_CHILD | WS_VISIBLE) ||
		!m_hBarraFerram.LoadToolBar(ID_FRMPRINCIPAL))
	{
		TRACE0("Falhou ao criar a barra de ferramentas\n");
		return -1;      
	}

	if (!m_hBarraStatus.Create(this) ||
		!m_hBarraStatus.SetIndicators(indicadores,
		  sizeof(indicadores)/sizeof(UINT)))
	{
		TRACE0("Falhou ao criar a barra de status\n");
		return -1;      
	}

  //int iStatusWidths[] = {100, -1};
  //m_hBarraStatus.GetStatusBarCtrl().SetParts(1, iStatusWidths);
  //m_hBarraStatus.GetStatusBarCtrl().SetText(Rotinas_sBarraLogin, 0, 0);

  m_hBarraStatus.SetPaneInfo(0, STR_USUARIO, SBPS_NORMAL, 100);
  m_hBarraStatus.SetPaneText(0, Rotinas_sBarraLogin);
  m_hBarraStatus.SetPaneInfo(1, ID_SEPARATOR, SBPS_STRETCH, 0);

	m_hBarraFerram.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_hBarraFerram);

  CenterWindow();
	return 0;
}

BOOL CFrmPrincipal::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CFrmPrincipal diagnostics

#ifdef _DEBUG
void CFrmPrincipal::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CFrmPrincipal::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFrmPrincipal message handlers


void CFrmPrincipal::OnCadAssuntos() 
{  
  if (!bTelaAtiva[0]) {
    nTelaAtiva = FRMCADASSUNTOS;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_CADASSUNTO, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnCadAutores() 
{
  if (!bTelaAtiva[1]) {
    nTelaAtiva = FRMCADAUTORES;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_CADAUTOR, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnCadEditoras() 
{
  if (!bTelaAtiva[2]) {
    nTelaAtiva = FRMCADEDITORAS;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_CADEDITORA, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnCadEnderecos() 
{
  if (!bTelaAtiva[3]) {
    nTelaAtiva = FRMCADENDERECOS;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_CADENDERECO, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnCadIdiomas() 
{
  if (!bTelaAtiva[4]) {
    nTelaAtiva = FRMCADIDIOMAS;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_CADIDIOMA, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnCadPaises() 
{
  if (!bTelaAtiva[5]) {
    nTelaAtiva = FRMCADPAISES;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_CADPAIS, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnCadProfissoes() 
{
  if (!bTelaAtiva[6]) {
    nTelaAtiva = FRMCADPROFISSOES;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_CADPROFISS, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnCadClientes() 
{
  if (!bTelaAtiva[7]) {
    nTelaAtiva = FRMCADCLIENTES;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_CADCLIENTE, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnCadLivros() 
{
  if (!bTelaAtiva[8]) {
    nTelaAtiva = FRMCADLIVROS;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_CADLIVRO, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnConAssuntos() 
{
	if (frmConAssuntos == NULL)	{
		frmConAssuntos = new CFrmConAssuntos(this);
    if (frmConAssuntos->Create() == FALSE)
      AfxMessageBox(Rotinas->lerStr(STR_NCCRIATELA), MB_ICONERROR | MB_OK, 0);
  } else
		frmConAssuntos->SetActiveWindow();
}

void CFrmPrincipal::OnConAutores() 
{
	if (frmConAutores == NULL)	{
		frmConAutores = new CFrmConAutores(this);
    if (frmConAutores->Create() == FALSE)
      AfxMessageBox(Rotinas->lerStr(STR_NCCRIATELA), MB_ICONERROR | MB_OK, 0);
  } else
		frmConAutores->SetActiveWindow();
}

void CFrmPrincipal::OnConClientes() 
{
	if (frmConClientes == NULL)	{
		frmConClientes = new CFrmConClientes(this);
    if (frmConClientes->Create() == FALSE)
      AfxMessageBox(Rotinas->lerStr(STR_NCCRIATELA), MB_ICONERROR | MB_OK, 0);
  } else
		frmConClientes->SetActiveWindow();
}

void CFrmPrincipal::OnConEditoras() 
{
	if (frmConEditoras == NULL)	{
		frmConEditoras = new CFrmConEditoras(this);
    if (frmConEditoras->Create() == FALSE)
      AfxMessageBox(Rotinas->lerStr(STR_NCCRIATELA), MB_ICONERROR | MB_OK, 0);
  } else
		frmConEditoras->SetActiveWindow();
}

void CFrmPrincipal::OnConEnderecos() 
{
  if (frmConEnderecos == NULL)	{
		frmConEnderecos = new CFrmConEnderecos(this);
    if (frmConEnderecos->Create() == FALSE)
      AfxMessageBox(Rotinas->lerStr(STR_NCCRIATELA), MB_ICONERROR | MB_OK, 0);
  } else
		frmConEnderecos->SetActiveWindow();    
}

void CFrmPrincipal::OnConIdiomas() 
{
	if (frmConIdiomas == NULL)	{
		frmConIdiomas = new CFrmConIdiomas(this);
    if (frmConIdiomas->Create() == FALSE)
      AfxMessageBox(Rotinas->lerStr(STR_NCCRIATELA), MB_ICONERROR | MB_OK, 0);
  } else
		frmConIdiomas->SetActiveWindow();
}

void CFrmPrincipal::OnConLivros() 
{
	if (frmConLivros == NULL)	{
		frmConLivros = new CFrmConLivros(this);
    if (frmConLivros->Create() == FALSE)
      AfxMessageBox(Rotinas->lerStr(STR_NCCRIATELA), MB_ICONERROR | MB_OK, 0);
  } else
		frmConLivros->SetActiveWindow();
}

void CFrmPrincipal::OnConPaises() 
{
	if (frmConPaises == NULL)	{
		frmConPaises = new CFrmConPaises(this);
    if (frmConPaises->Create() == FALSE)
      AfxMessageBox(Rotinas->lerStr(STR_NCCRIATELA), MB_ICONERROR | MB_OK, 0);
  } else
		frmConPaises->SetActiveWindow();
}

void CFrmPrincipal::OnConProfissoes() 
{
	if (frmConProfissoes == NULL)	{
		frmConProfissoes = new CFrmConProfissoes(this);
    if (frmConProfissoes->Create() == FALSE)
      AfxMessageBox(Rotinas->lerStr(STR_NCCRIATELA), MB_ICONERROR | MB_OK, 0);
  } else
		frmConProfissoes->SetActiveWindow();
}

void CFrmPrincipal::OnVenVenderlivros() 
{
  if (!bTelaAtiva[9]) {
    nTelaAtiva = FRMVENDERLIVROS;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_VENLIVRO, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnVenVendasRealizadas() 
{
  if (!bTelaAtiva[10]) {
    nTelaAtiva = FRMCONVENDAS;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_CONVENLIVRO, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnOpAlterarsenha() 
{
  if (!bTelaAtiva[11]) {
    nTelaAtiva = FRMALTERARSENHA;
	  this->CreateNewChild(RUNTIME_CLASS(CFrmFilha), STR_ALTSENHA, 
                          g_hMDIMenu, g_hMDIAccel);
  }
}

void CFrmPrincipal::OnOpSobre() 
{
	CFrmSobre *fSobre = new CFrmSobre();
  fSobre->DoModal();
}

void CFrmPrincipal::OnOpSair() 
{
	PostMessage(WM_CLOSE, 0, 0);
}

void CFrmPrincipal::OnClose() 
{
  if (AfxMessageBox(Rotinas->lerStr(STR_SAIRSIS), 
        MB_ICONQUESTION | MB_YESNO) == IDYES) {
     Rotinas->DisconectaBanco();
     DestroyWindow();
  }

}
