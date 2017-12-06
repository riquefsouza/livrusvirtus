// ConAutores.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "ConAutores.h"
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
// CFrmConAutores dialog
CFrmConAutores::CFrmConAutores(CWnd* pParent /*=NULL*/)
	: CFrmConsultas(CFrmConAutores::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmConAutores)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  m_nID = CFrmConAutores::IDD;
	m_pParent = pParent;
}


void CFrmConAutores::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmConAutores)
	DDX_Control(pDX, ID_FRMCONAUTORES_LISTCONSULTA, m_ListConsulta);
	DDX_Control(pDX, ID_FRMCONAUTORES_LABREGISTROS, m_LabRegistros);
	DDX_Control(pDX, ID_FRMCONAUTORES_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCONAUTORES_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCONAUTORES_BTNFECHAR, m_BtnFechar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmConAutores, CDialog)
	//{{AFX_MSG_MAP(CFrmConAutores)
	ON_BN_CLICKED(ID_FRMCONAUTORES_BTNFECHAR, OnBtnFechar)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_FRMCONAUTORES_BTNLIMPAR, OnBtnLimpar)
	ON_BN_CLICKED(ID_FRMCONAUTORES_BTNPESQUISAR, OnBtnPesquisar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmConAutores message handlers

void CFrmConAutores::OnBtnFechar() 
{
  SendMessage(WM_CLOSE,0,0);
}

BOOL CFrmConAutores::Create()
{
  bModal = FALSE;
	return CFrmConsultas::Create(m_nID, m_pParent);
}

void CFrmConAutores::PostNcDestroy() 
{
	delete this;
}

void CFrmConAutores::OnClose() 
{
  if (!bModal)
    ((CFrmPrincipal*)m_pParent)->frmConAutores = NULL;

  CFrmConsultas::Fecha(sSelecionados, CM_CON_AUTORES);
}

BOOL CFrmConAutores::OnInitDialog() 
{
	CFrmConsultas::OnInitDialog();
		
  LISTASTR sColunas;
  POSITION pos;
  UINT nLargura[] = { 80,250 };  
  pos = sColunas.col.GetHeadPosition();
  sColunas.col.InsertAfter(pos, "Código");
  sColunas.col.InsertAfter(pos, "Autor");
    
  Rotinas->VisaoListaInsereColunas(&m_ListConsulta, nLargura, &sColunas);

  CFrmConsultas::Ativar(CM_CON_AUTORES);

	return TRUE;
}

BOOL CFrmConAutores::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  if (CFrmConsultas::Notifica(lParam, &m_ListConsulta,
      &m_LabRegistros, &lstLinhas, &sSelecionados))
       return 0;

  return CFrmConsultas::OnNotify(wParam, lParam, pResult);
}

void CFrmConAutores::OnSize(UINT nType, int cx, int cy) 
{
  CFrmConsultas::arrumaTamanho(&m_ListConsulta, 
    &m_LabRegistros, &m_BtnLimpar, &m_BtnFechar);
}

void CFrmConAutores::OnBtnLimpar() 
{
  CFrmConsultas::LimparDados(&m_LabRegistros, 
		&m_EdtDescricao, &m_ListConsulta, &lstLinhas);
}

void CFrmConAutores::OnBtnPesquisar() 
{
  CFrmConsultas::PesquisarDados(&m_ListConsulta, 
    &m_LabRegistros, &lstLinhas, ConsSQL->Autor('S',"", 
    Rotinas->retTexto(&m_EdtDescricao)), Rotinas->lerStr(STR_AUTNENC));
}
