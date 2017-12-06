// ConPaises.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "ConPaises.h"
#include "Principal.h"
#include "Consultas.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmConPaises dialog


CFrmConPaises::CFrmConPaises(CWnd* pParent /*=NULL*/)
	: CFrmConsultas(CFrmConPaises::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmConPaises)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  m_nID = CFrmConPaises::IDD;
	m_pParent = pParent;
}


void CFrmConPaises::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmConPaises)
	DDX_Control(pDX, ID_FRMCONPAISES_LISTCONSULTA, m_ListConsulta);
	DDX_Control(pDX, ID_FRMCONPAISES_LABREGISTROS, m_LabRegistros);
	DDX_Control(pDX, ID_FRMCONPAISES_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCONPAISES_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCONPAISES_BTNFECHAR, m_BtnFechar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmConPaises, CDialog)
	//{{AFX_MSG_MAP(CFrmConPaises)
	ON_BN_CLICKED(ID_FRMCONPAISES_BTNFECHAR, OnBtnFechar)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_FRMCONPAISES_BTNLIMPAR, OnBtnLimpar)
	ON_BN_CLICKED(ID_FRMCONPAISES_BTNPESQUISAR, OnBtnPesquisar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmConPaises message handlers

void CFrmConPaises::OnBtnFechar() 
{
  SendMessage(WM_CLOSE,0,0);
}

BOOL CFrmConPaises::Create()
{
  bModal = FALSE;
	return CFrmConsultas::Create(m_nID, m_pParent);
}

void CFrmConPaises::PostNcDestroy() 
{
	delete this;
}

void CFrmConPaises::OnClose() 
{
  if (!bModal)
    ((CFrmPrincipal*)m_pParent)->frmConPaises = NULL;

  CFrmConsultas::Fecha(sSelecionados, CM_CON_PAISES);
}

BOOL CFrmConPaises::OnInitDialog() 
{
	CFrmConsultas::OnInitDialog();
		
  LISTASTR sColunas;
  POSITION pos;
  UINT nLargura[] = { 80,250 };  
  pos = sColunas.col.GetHeadPosition();
  sColunas.col.InsertAfter(pos, "Código");
  sColunas.col.InsertAfter(pos, "País");
    
  Rotinas->VisaoListaInsereColunas(&m_ListConsulta, nLargura, &sColunas);

  CFrmConsultas::Ativar(CM_CON_PAISES);

	return TRUE;
}

BOOL CFrmConPaises::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  if (CFrmConsultas::Notifica(lParam, &m_ListConsulta,
      &m_LabRegistros, &lstLinhas, &sSelecionados))
       return 0;

  return CFrmConsultas::OnNotify(wParam, lParam, pResult);
}

void CFrmConPaises::OnSize(UINT nType, int cx, int cy) 
{
  CFrmConsultas::arrumaTamanho(&m_ListConsulta, 
    &m_LabRegistros, &m_BtnLimpar, &m_BtnFechar);
}

void CFrmConPaises::OnBtnLimpar() 
{
  CFrmConsultas::LimparDados(&m_LabRegistros, 
		&m_EdtDescricao, &m_ListConsulta, &lstLinhas);
}

void CFrmConPaises::OnBtnPesquisar() 
{
  CFrmConsultas::PesquisarDados(&m_ListConsulta, 
    &m_LabRegistros, &lstLinhas, ConsSQL->Pais('S',"", 
    Rotinas->retTexto(&m_EdtDescricao)), Rotinas->lerStr(STR_PAISNENC));
}
