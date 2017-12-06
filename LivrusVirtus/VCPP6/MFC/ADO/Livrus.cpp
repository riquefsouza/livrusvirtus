// Livrus.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Livrus.h"

#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "Splash.h"
#include "Login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLivrusApp

BEGIN_MESSAGE_MAP(CLivrusApp, CWinApp)
	//{{AFX_MSG_MAP(CLivrusApp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLivrusApp construction

CLivrusApp::CLivrusApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLivrusApp object

CLivrusApp LivrusApp;
HMENU g_hMDIMenu;
HACCEL g_hMDIAccel;

/////////////////////////////////////////////////////////////////////////////
// CLivrusApp initialization

BOOL CLivrusApp::InitInstance()
{
  HINSTANCE hInstancia;
  CMDIFrameWnd* fPrincipal;

  AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

  if (!Rotinas->VerificaInstancia(NULL,"Livrus Virtus"))
    return FALSE; 

  fPrincipal = new CFrmPrincipal();
  m_pMainWnd = fPrincipal;

  if (!Rotinas->ConectaBanco(
    "FILE NAME=C:\\LivrusVirtus\\Bancos\\access\\Access2k_Livrus.udl")) {
     AfxMessageBox(Rotinas->lerStr(STR_NCONBANCO), MB_ICONERROR | MB_OK, 0);   
	 return FALSE;
  }

  CFrmSplash* fSplash = new CFrmSplash();
  fSplash->DoModal();

  CFrmLogin* fLogin = new CFrmLogin();
  if (fLogin->DoModal()==FALSE)
     return FALSE;    

  /*
  CRect rect;
  rect.top = 0;
  rect.left = 0;
  rect.bottom = 400;
  rect.right = 600;
  if (!fPrincipal->Create(NULL, "Livrus Virtus", FWS_ADDTOTITLE | 
    WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_VSCROLL | WS_HSCROLL,
    rect, NULL, MAKEINTRESOURCE(ID_FRMPRINCIPAL), NULL, NULL))
   */

  if (!fPrincipal->LoadFrame(ID_FRMPRINCIPAL))
	  return FALSE;

  //fPrincipal->SetIcon(LoadIcon(MAKEINTRESOURCE(ID_FRMPRINCIPAL)),FALSE);

  hInstancia = AfxGetResourceHandle();
  g_hMDIMenu  = ::LoadMenu(hInstancia, MAKEINTRESOURCE(ID_FRMPRINCIPAL));
  g_hMDIAccel = ::LoadAccelerators(hInstancia, MAKEINTRESOURCE(ID_FRMPRINCIPAL));

  fPrincipal->ShowWindow(m_nCmdShow);
  fPrincipal->UpdateWindow(); 

  return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CLivrusApp message handlers

int CLivrusApp::ExitInstance() 
{
	if (g_hMDIMenu != NULL)
		FreeResource(g_hMDIMenu);
	if (g_hMDIAccel != NULL)
		FreeResource(g_hMDIAccel);

	return CWinApp::ExitInstance();
}

