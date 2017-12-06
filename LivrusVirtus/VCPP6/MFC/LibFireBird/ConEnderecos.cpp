// ConEnderecos.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "ConEnderecos.h"
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
// CFrmConEnderecos dialog


CFrmConEnderecos::CFrmConEnderecos(CWnd* pParent /*=NULL*/)
  : CFrmConsultas(CFrmConEnderecos::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmConEnderecos)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  m_nID = CFrmConEnderecos::IDD;
	m_pParent = pParent;
}


void CFrmConEnderecos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmConEnderecos)
	DDX_Control(pDX, ID_FRMCONENDERECOS_LISTCONSULTA, m_ListConsulta);
	DDX_Control(pDX, ID_FRMCONENDERECOS_LABREGISTROS, m_LabRegistros);
	DDX_Control(pDX, ID_FRMCONENDERECOS_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCONENDERECOS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCONENDERECOS_BTNFECHAR, m_BtnFechar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmConEnderecos, CDialog)
	//{{AFX_MSG_MAP(CFrmConEnderecos)
	ON_BN_CLICKED(ID_FRMCONENDERECOS_BTNFECHAR, OnBtnFechar)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_FRMCONENDERECOS_BTNLIMPAR, OnBtnLimpar)
	ON_BN_CLICKED(ID_FRMCONENDERECOS_BTNPESQUISAR, OnBtnPesquisar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmConEnderecos message handlers

void CFrmConEnderecos::OnBtnFechar() 
{
  SendMessage(WM_CLOSE,0,0);
}

BOOL CFrmConEnderecos::Create()
{
  bModal = FALSE;
	return CFrmConsultas::Create(m_nID, m_pParent);
}

void CFrmConEnderecos::PostNcDestroy() 
{
	delete this;
}

void CFrmConEnderecos::OnClose() 
{
  if (!bModal) 
    ((CFrmPrincipal*)m_pParent)->frmConEnderecos = NULL;

  CFrmConsultas::Fecha(sSelecionados, CM_CON_ENDERECOS);
}

BOOL CFrmConEnderecos::OnInitDialog() 
{
	CFrmConsultas::OnInitDialog();
		
  LISTASTR sColunas;
  POSITION pos;
  UINT nLargura[] = { 80,200,150,80,100,80 };
  pos = sColunas.col.GetHeadPosition();
  sColunas.col.InsertAfter(pos, "Código");
  sColunas.col.InsertAfter(pos, "Logradouro");
  sColunas.col.InsertAfter(pos, "Bairro");
  sColunas.col.InsertAfter(pos, "CEP");
  sColunas.col.InsertAfter(pos, "Cidade");
  sColunas.col.InsertAfter(pos, "Estado");
    
  Rotinas->VisaoListaInsereColunas(&m_ListConsulta, nLargura, &sColunas);

  CFrmConsultas::Ativar(CM_CON_ENDERECOS);

	return TRUE;
}

BOOL CFrmConEnderecos::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  if (CFrmConsultas::Notifica(lParam, &m_ListConsulta,
      &m_LabRegistros, &lstLinhas, &sSelecionados))
       return 0;

  return CFrmConsultas::OnNotify(wParam, lParam, pResult);  
}

void CFrmConEnderecos::OnSize(UINT nType, int cx, int cy) 
{
  CFrmConsultas::arrumaTamanho(&m_ListConsulta, 
    &m_LabRegistros, &m_BtnLimpar, &m_BtnFechar);
}

void CFrmConEnderecos::OnBtnLimpar() 
{
  CFrmConsultas::LimparDados(&m_LabRegistros, 
		&m_EdtDescricao, &m_ListConsulta, &lstLinhas);
}

void CFrmConEnderecos::OnBtnPesquisar() 
{
  CFrmConsultas::PesquisarDados(&m_ListConsulta, 
    &m_LabRegistros, &lstLinhas, ConsSQL->Endereco('S',"", 
    Rotinas->retTexto(&m_EdtDescricao),"","","",""), 
    Rotinas->lerStr(STR_ENDNENC));
}
