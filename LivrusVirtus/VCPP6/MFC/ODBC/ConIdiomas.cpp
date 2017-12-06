// ConIdiomas.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "ConIdiomas.h"
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
// CFrmConIdiomas dialog


CFrmConIdiomas::CFrmConIdiomas(CWnd* pParent /*=NULL*/)
	: CFrmConsultas(CFrmConIdiomas::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmConIdiomas)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  m_nID = CFrmConIdiomas::IDD;
	m_pParent = pParent;
}


void CFrmConIdiomas::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmConIdiomas)
	DDX_Control(pDX, ID_FRMCONIDIOMAS_LISTCONSULTA, m_ListConsulta);
	DDX_Control(pDX, ID_FRMCONIDIOMAS_LABREGISTROS, m_LabRegistros);
	DDX_Control(pDX, ID_FRMCONIDIOMAS_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCONIDIOMAS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCONIDIOMAS_BTNFECHAR, m_BtnFechar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmConIdiomas, CDialog)
	//{{AFX_MSG_MAP(CFrmConIdiomas)
	ON_BN_CLICKED(ID_FRMCONIDIOMAS_BTNFECHAR, OnBtnFechar)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_FRMCONIDIOMAS_BTNLIMPAR, OnBtnLimpar)
	ON_BN_CLICKED(ID_FRMCONIDIOMAS_BTNPESQUISAR, OnBtnPesquisar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmConIdiomas message handlers

void CFrmConIdiomas::OnBtnFechar() 
{
  SendMessage(WM_CLOSE,0,0);
}

BOOL CFrmConIdiomas::Create()
{
  bModal = FALSE;
	return CFrmConsultas::Create(m_nID, m_pParent);
}

void CFrmConIdiomas::PostNcDestroy() 
{
	delete this;
}

void CFrmConIdiomas::OnClose() 
{
  if (!bModal)
    ((CFrmPrincipal*)m_pParent)->frmConIdiomas = NULL;

  CFrmConsultas::Fecha(sSelecionados, CM_CON_IDIOMAS);
}

BOOL CFrmConIdiomas::OnInitDialog() 
{
	CFrmConsultas::OnInitDialog();
		
  LISTASTR sColunas;
  POSITION pos;
  UINT nLargura[] = { 80,250 };  
  pos = sColunas.col.GetHeadPosition();
  sColunas.col.InsertAfter(pos, "Código");
  sColunas.col.InsertAfter(pos, "Idioma");
    
  Rotinas->VisaoListaInsereColunas(&m_ListConsulta, nLargura, &sColunas);

  CFrmConsultas::Ativar(CM_CON_IDIOMAS);

	return TRUE;
}

BOOL CFrmConIdiomas::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  if (CFrmConsultas::Notifica(lParam, &m_ListConsulta,
      &m_LabRegistros, &lstLinhas, &sSelecionados))
       return 0;

  return CFrmConsultas::OnNotify(wParam, lParam, pResult);
}

void CFrmConIdiomas::OnSize(UINT nType, int cx, int cy) 
{
  CFrmConsultas::arrumaTamanho(&m_ListConsulta, 
    &m_LabRegistros, &m_BtnLimpar, &m_BtnFechar);
}

void CFrmConIdiomas::OnBtnLimpar() 
{
  CFrmConsultas::LimparDados(&m_LabRegistros, 
		&m_EdtDescricao, &m_ListConsulta, &lstLinhas);
}

void CFrmConIdiomas::OnBtnPesquisar() 
{
  CFrmConsultas::PesquisarDados(&m_ListConsulta, 
    &m_LabRegistros, &lstLinhas, ConsSQL->Idioma('S',"", 
    Rotinas->retTexto(&m_EdtDescricao)), Rotinas->lerStr(STR_IDINENC));
}
