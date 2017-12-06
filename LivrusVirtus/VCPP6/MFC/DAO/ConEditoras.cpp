// ConEditoras.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "ConEditoras.h"
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
// CFrmConEditoras dialog


CFrmConEditoras::CFrmConEditoras(CWnd* pParent /*=NULL*/)
	: CFrmConsultas(CFrmConEditoras::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmConEditoras)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  m_nID = CFrmConEditoras::IDD;
	m_pParent = pParent;
}


void CFrmConEditoras::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmConEditoras)
	DDX_Control(pDX, ID_FRMCONEDITORAS_LISTCONSULTA, m_ListConsulta);
	DDX_Control(pDX, ID_FRMCONEDITORAS_LABREGISTROS, m_LabRegistros);
	DDX_Control(pDX, ID_FRMCONEDITORAS_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCONEDITORAS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCONEDITORAS_BTNFECHAR, m_BtnFechar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmConEditoras, CDialog)
	//{{AFX_MSG_MAP(CFrmConEditoras)
	ON_BN_CLICKED(ID_FRMCONEDITORAS_BTNFECHAR, OnBtnFechar)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_FRMCONEDITORAS_BTNLIMPAR, OnBtnLimpar)
	ON_BN_CLICKED(ID_FRMCONEDITORAS_BTNPESQUISAR, OnBtnPesquisar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmConEditoras message handlers

void CFrmConEditoras::OnBtnFechar() 
{
  SendMessage(WM_CLOSE,0,0);
}

BOOL CFrmConEditoras::Create()
{
  bModal = FALSE;
	return CFrmConsultas::Create(m_nID, m_pParent);
}

void CFrmConEditoras::PostNcDestroy() 
{
	delete this;
}

void CFrmConEditoras::OnClose() 
{
  if (!bModal)
    ((CFrmPrincipal*)m_pParent)->frmConEditoras = NULL;

  CFrmConsultas::Fecha(sSelecionados, CM_CON_EDITORAS);
}

BOOL CFrmConEditoras::OnInitDialog() 
{
	CFrmConsultas::OnInitDialog();
		
  LISTASTR sColunas;
  POSITION pos;
  UINT nLargura[] = { 80,250 };  
  pos = sColunas.col.GetHeadPosition();
  sColunas.col.InsertAfter(pos, "Código");
  sColunas.col.InsertAfter(pos, "Editora");
    
  Rotinas->VisaoListaInsereColunas(&m_ListConsulta, nLargura, &sColunas);

  CFrmConsultas::Ativar(CM_CON_EDITORAS);

	return TRUE;
}

BOOL CFrmConEditoras::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  if (CFrmConsultas::Notifica(lParam, &m_ListConsulta,
      &m_LabRegistros, &lstLinhas, &sSelecionados))
       return 0;

  return CFrmConsultas::OnNotify(wParam, lParam, pResult);
}

void CFrmConEditoras::OnSize(UINT nType, int cx, int cy) 
{
  CFrmConsultas::arrumaTamanho(&m_ListConsulta, 
    &m_LabRegistros, &m_BtnLimpar, &m_BtnFechar);
}

void CFrmConEditoras::OnBtnLimpar() 
{
  CFrmConsultas::LimparDados(&m_LabRegistros, 
		&m_EdtDescricao, &m_ListConsulta, &lstLinhas);
}

void CFrmConEditoras::OnBtnPesquisar() 
{
  CFrmConsultas::PesquisarDados(&m_ListConsulta, 
    &m_LabRegistros, &lstLinhas, ConsSQL->Editora('S',"", 
    Rotinas->retTexto(&m_EdtDescricao)), Rotinas->lerStr(STR_EDTNENC));
}
