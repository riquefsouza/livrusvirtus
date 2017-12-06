// ConProfissoes.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "ConProfissoes.h"
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
// CFrmConProfissoes dialog


CFrmConProfissoes::CFrmConProfissoes(CWnd* pParent /*=NULL*/)
	: CFrmConsultas(CFrmConProfissoes::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmConProfissoes)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  m_nID = CFrmConProfissoes::IDD;
	m_pParent = pParent;
}


void CFrmConProfissoes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmConProfissoes)
	DDX_Control(pDX, ID_FRMCONPROFISSOES_LISTCONSULTA, m_ListConsulta);
	DDX_Control(pDX, ID_FRMCONPROFISSOES_LABREGISTROS, m_LabRegistros);
	DDX_Control(pDX, ID_FRMCONPROFISSOES_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCONPROFISSOES_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCONPROFISSOES_BTNFECHAR, m_BtnFechar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmConProfissoes, CDialog)
	//{{AFX_MSG_MAP(CFrmConProfissoes)
	ON_BN_CLICKED(ID_FRMCONPROFISSOES_BTNFECHAR, OnBtnFechar)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_FRMCONPROFISSOES_BTNLIMPAR, OnBtnLimpar)
	ON_BN_CLICKED(ID_FRMCONPROFISSOES_BTNPESQUISAR, OnBtnPesquisar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmConProfissoes message handlers

void CFrmConProfissoes::OnBtnFechar() 
{
  SendMessage(WM_CLOSE,0,0);
}

BOOL CFrmConProfissoes::Create()
{
  bModal = FALSE;
	return CFrmConsultas::Create(m_nID, m_pParent);
}

void CFrmConProfissoes::PostNcDestroy() 
{
	delete this;
}

void CFrmConProfissoes::OnClose() 
{
  if (!bModal)
    ((CFrmPrincipal*)m_pParent)->frmConProfissoes = NULL;

  CFrmConsultas::Fecha(sSelecionados, CM_CON_PROFISSOES);
}

BOOL CFrmConProfissoes::OnInitDialog() 
{
	CFrmConsultas::OnInitDialog();
		
  LISTASTR sColunas;
  POSITION pos;
  UINT nLargura[] = { 80,250 };  
  pos = sColunas.col.GetHeadPosition();
  sColunas.col.InsertAfter(pos, "Código");
  sColunas.col.InsertAfter(pos, "Profissão");
    
  Rotinas->VisaoListaInsereColunas(&m_ListConsulta, nLargura, &sColunas);

  CFrmConsultas::Ativar(CM_CON_PROFISSOES);

	return TRUE;
}

BOOL CFrmConProfissoes::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  if (CFrmConsultas::Notifica(lParam, &m_ListConsulta,
      &m_LabRegistros, &lstLinhas, &sSelecionados))
       return 0;

  return CFrmConsultas::OnNotify(wParam, lParam, pResult);
}

void CFrmConProfissoes::OnSize(UINT nType, int cx, int cy) 
{
  CFrmConsultas::arrumaTamanho(&m_ListConsulta, 
    &m_LabRegistros, &m_BtnLimpar, &m_BtnFechar);
}

void CFrmConProfissoes::OnBtnLimpar() 
{
  CFrmConsultas::LimparDados(&m_LabRegistros, 
		&m_EdtDescricao, &m_ListConsulta, &lstLinhas);
}

void CFrmConProfissoes::OnBtnPesquisar() 
{
  CFrmConsultas::PesquisarDados(&m_ListConsulta, 
    &m_LabRegistros, &lstLinhas, ConsSQL->Profissao('S',"", 
    Rotinas->retTexto(&m_EdtDescricao)), Rotinas->lerStr(STR_PROFNENC));
}
