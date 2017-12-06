// ConAssuntos.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "ConAssuntos.h"
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
// CFrmConAssuntos dialog
CFrmConAssuntos::CFrmConAssuntos(CWnd* pParent /*=NULL*/)
	: CFrmConsultas(CFrmConAssuntos::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmConAssuntos)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  m_nID = CFrmConAssuntos::IDD;
	m_pParent = pParent;
}


void CFrmConAssuntos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmConAssuntos)
	DDX_Control(pDX, ID_FRMCONASSUNTOS_LISTCONSULTA, m_ListConsulta);
	DDX_Control(pDX, ID_FRMCONASSUNTOS_LABREGISTROS, m_LabRegistros);
	DDX_Control(pDX, ID_FRMCONASSUNTOS_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCONASSUNTOS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCONASSUNTOS_BTNFECHAR, m_BtnFechar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmConAssuntos, CDialog)
	//{{AFX_MSG_MAP(CFrmConAssuntos)
	ON_BN_CLICKED(ID_FRMCONASSUNTOS_BTNFECHAR, OnBtnFechar)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_FRMCONASSUNTOS_BTNLIMPAR, OnBtnLimpar)
	ON_BN_CLICKED(ID_FRMCONASSUNTOS_BTNPESQUISAR, OnBtnPesquisar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmConAssuntos message handlers

void CFrmConAssuntos::OnBtnFechar() 
{
  SendMessage(WM_CLOSE,0,0);
}

BOOL CFrmConAssuntos::Create()
{
  bModal = FALSE;
	return CFrmConsultas::Create(m_nID, m_pParent);
}

void CFrmConAssuntos::PostNcDestroy() 
{
	delete this;
}

void CFrmConAssuntos::OnClose() 
{
  if (!bModal)
    ((CFrmPrincipal*)m_pParent)->frmConAssuntos = NULL;

  CFrmConsultas::Fecha(sSelecionados, CM_CON_ASSUNTOS);
}

BOOL CFrmConAssuntos::OnInitDialog() 
{
	CFrmConsultas::OnInitDialog();
		
  LISTASTR sColunas;
  POSITION pos;
  UINT nLargura[] = { 80,250 };  
  pos = sColunas.col.GetHeadPosition();
  sColunas.col.InsertAfter(pos, "Código");
  sColunas.col.InsertAfter(pos, "Assunto");
    
  Rotinas->VisaoListaInsereColunas(&m_ListConsulta, nLargura, &sColunas);

  CFrmConsultas::Ativar(CM_CON_ASSUNTOS);

	return TRUE;
}

BOOL CFrmConAssuntos::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  if (CFrmConsultas::Notifica(lParam, &m_ListConsulta,
      &m_LabRegistros, &lstLinhas, &sSelecionados))
       return 0;

  return CFrmConsultas::OnNotify(wParam, lParam, pResult);
}

void CFrmConAssuntos::OnSize(UINT nType, int cx, int cy) 
{
  CFrmConsultas::arrumaTamanho(&m_ListConsulta, 
    &m_LabRegistros, &m_BtnLimpar, &m_BtnFechar);
}

void CFrmConAssuntos::OnBtnLimpar() 
{
  CFrmConsultas::LimparDados(&m_LabRegistros, 
		&m_EdtDescricao, &m_ListConsulta, &lstLinhas);
}

void CFrmConAssuntos::OnBtnPesquisar() 
{
  CFrmConsultas::PesquisarDados(&m_ListConsulta, 
    &m_LabRegistros, &lstLinhas, ConsSQL->Assunto('S',"", 
    Rotinas->retTexto(&m_EdtDescricao)), Rotinas->lerStr(STR_ASSNENC));
}
