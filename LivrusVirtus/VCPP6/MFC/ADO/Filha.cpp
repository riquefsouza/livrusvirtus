// Filha.cpp : implementation of the CFrmFilha class
//

#include "stdafx.h"
#include "Livrus.h"
#include "RotinasGlobais.h"
#include "Principal.h"
#include "Filha.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

UINT nTelaAtiva;
BOOL bTelaAtiva[12];

/////////////////////////////////////////////////////////////////////////////
// CFrmFilha

IMPLEMENT_DYNCREATE(CFrmFilha, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CFrmFilha, CMDIChildWnd)
	//{{AFX_MSG_MAP(CFrmFilha)
		ON_WM_SETFOCUS()
		ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmFilha construction/destruction

CFrmFilha::CFrmFilha()
{
}

CFrmFilha::~CFrmFilha()
{
}

BOOL CFrmFilha::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CFrmFilha diagnostics

#ifdef _DEBUG
void CFrmFilha::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CFrmFilha::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFrmFilha message handlers

int CFrmFilha::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{ BOOL bCriou;

	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

  SetIcon(LoadIcon(AfxGetApp()->m_hInstance, 
    MAKEINTRESOURCE(ID_FRMPRINCIPAL)),FALSE);
  MoveWindow(0, 0, 340, 165, TRUE);	

  switch (nTelaAtiva) {
    case FRMCADASSUNTOS: {
	    bCriou = m_frmCadAssuntos.Create(FRMCADASSUNTOS,this);
      bTelaAtiva[0] = TRUE;
      nLocalTelaAtiva = FRMCADASSUNTOS;
    }
    break;    
    case FRMCADAUTORES: {
	    bCriou = m_frmCadAutores.Create(FRMCADAUTORES,this);
      bTelaAtiva[1] = TRUE;
      nLocalTelaAtiva = FRMCADAUTORES;
    }
    break;
    case FRMCADEDITORAS: {
	    bCriou = m_frmCadEditoras.Create(FRMCADEDITORAS,this);
      bTelaAtiva[2] = TRUE;
      nLocalTelaAtiva = FRMCADEDITORAS;
    }
    break;
    case FRMCADENDERECOS: {
	    bCriou = m_frmCadEnderecos.Create(FRMCADENDERECOS,this);
      bTelaAtiva[3] = TRUE;
      nLocalTelaAtiva = FRMCADENDERECOS;
      MoveWindow(0, 0, 530, 195, TRUE);
    }
    break;
    case FRMCADIDIOMAS: {
	    bCriou = m_frmCadIdiomas.Create(FRMCADIDIOMAS,this);
      bTelaAtiva[4] = TRUE;
      nLocalTelaAtiva = FRMCADIDIOMAS;
    }
    break;
    case FRMCADPAISES: {
	    bCriou = m_frmCadPaises.Create(FRMCADPAISES,this);
      bTelaAtiva[5] = TRUE;
      nLocalTelaAtiva = FRMCADPAISES;
    }
    break;
    case FRMCADPROFISSOES: {
	    bCriou = m_frmCadProfissoes.Create(FRMCADPROFISSOES,this);
      bTelaAtiva[6] = TRUE;
      nLocalTelaAtiva = FRMCADPROFISSOES;
    }
    break;
    case FRMCADCLIENTES: {
	    bCriou = m_frmCadClientes.Create(FRMCADCLIENTES,this);
      bTelaAtiva[7] = TRUE;
      nLocalTelaAtiva = FRMCADCLIENTES;
      MoveWindow(0, 0, 530, 468, TRUE);
    }
    break;
    case FRMCADLIVROS: {
	    bCriou = m_frmCadLivros.Create(FRMCADLIVROS,this);
      bTelaAtiva[8] = TRUE;
      nLocalTelaAtiva = FRMCADLIVROS;
      MoveWindow(0, 0, 520, 411, TRUE);
    }
    break;
    case FRMVENDERLIVROS: {
	    bCriou = m_frmVenderLivros.Create(FRMVENDERLIVROS,this);
      bTelaAtiva[9] = TRUE;
      nLocalTelaAtiva = FRMVENDERLIVROS;
      MoveWindow(0, 0, 490, 340, TRUE);
    }
    break;
    case FRMCONVENDAS: {
	    bCriou = m_frmConVendas.Create(FRMCONVENDAS,this);
      bTelaAtiva[10] = TRUE;
      nLocalTelaAtiva = FRMCONVENDAS;
      MoveWindow(0, 0, 470, 330, TRUE);
    }
    break;
    case FRMALTERARSENHA: {
	    bCriou = m_frmAlterarSenha.Create(FRMALTERARSENHA,this);
      bTelaAtiva[11] = TRUE;
      nLocalTelaAtiva = FRMALTERARSENHA;
      MoveWindow(0, 0, 255, 160, TRUE);
    }
    break;
  }
	if (!bCriou) {
		TRACE0(Rotinas->lerStr(STR_NCCRIADLG));
		return -1;
  }     

	return 0;
}

void CFrmFilha::OnSetFocus(CWnd* pOldWnd) 
{
	CMDIChildWnd::OnSetFocus(pOldWnd);

  switch (nLocalTelaAtiva) {
    case FRMCADASSUNTOS:
      m_frmCadAssuntos.SetFocus();
    break;
    case FRMCADAUTORES:
      m_frmCadAutores.SetFocus();
    break;
    case FRMCADEDITORAS:
      m_frmCadEditoras.SetFocus();
    break;
    case FRMCADENDERECOS:
      m_frmCadEnderecos.SetFocus();
    break;
    case FRMCADIDIOMAS:
      m_frmCadIdiomas.SetFocus();
    break;
    case FRMCADPAISES:
      m_frmCadPaises.SetFocus();
    break;
    case FRMCADPROFISSOES:
      m_frmCadProfissoes.SetFocus();
    break;
    case FRMCADCLIENTES:
      m_frmCadClientes.SetFocus();
    break;
    case FRMCADLIVROS:
      m_frmCadLivros.SetFocus();
    break;
    case FRMVENDERLIVROS:
      m_frmVenderLivros.SetFocus();
    break;
    case FRMCONVENDAS:
      m_frmConVendas.SetFocus();
    break;
    case FRMALTERARSENHA:
      m_frmAlterarSenha.SetFocus();
    break;
  }

}

BOOL CFrmFilha::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	//return CMDIChildWnd::OnEraseBkgnd(pDC);
  
	DWORD dw = GetSysColor(COLOR_3DFACE);
	CBrush bkBrush(dw);

	CRect rect;
	GetClientRect(&rect);

	pDC->FillRect(rect, &bkBrush);
	return TRUE;
  
}

void CFrmFilha::OnSize(UINT nType, int cx, int cy) 
{
  RECT rForm;

  CMDIChildWnd::OnSize(nType, cx, cy);

  if (nLocalTelaAtiva == FRMCONVENDAS) {  
    GetClientRect(&rForm);  
    m_frmConVendas.arrumaTamanho(rForm);
  }
}

void CFrmFilha::OnDestroy() 
{
	CMDIChildWnd::OnDestroy();
	
  switch (nLocalTelaAtiva) {
    case FRMCADASSUNTOS:
      bTelaAtiva[0]=FALSE;
    break;
    case FRMCADAUTORES:
      bTelaAtiva[1]=FALSE;
    break;
    case FRMCADEDITORAS:
      bTelaAtiva[2]=FALSE;
    break;
    case FRMCADENDERECOS:
      bTelaAtiva[3]=FALSE;
    break;
    case FRMCADIDIOMAS:
      bTelaAtiva[4]=FALSE;
    break;
    case FRMCADPAISES:
      bTelaAtiva[5]=FALSE;
    break;
    case FRMCADPROFISSOES:
      bTelaAtiva[6]=FALSE;
    break;
    case FRMCADCLIENTES:
      bTelaAtiva[7]=FALSE;
    break;
    case FRMCADLIVROS:
      bTelaAtiva[8]=FALSE;
    break;
    case FRMVENDERLIVROS:
      bTelaAtiva[9]=FALSE;
    break;
    case FRMCONVENDAS:
      bTelaAtiva[10]=FALSE;
    break;
    case FRMALTERARSENHA:
      bTelaAtiva[11]=FALSE;
    break;
  }
}
