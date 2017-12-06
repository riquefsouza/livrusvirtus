// ConLivros.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "ConLivros.h"
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
// CFrmConLivros dialog


CFrmConLivros::CFrmConLivros(CWnd* pParent /*=NULL*/)
	: CFrmConsultas(CFrmConLivros::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmConLivros)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  m_nID = CFrmConLivros::IDD;
	m_pParent = pParent;
}


void CFrmConLivros::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmConLivros)
	DDX_Control(pDX, ID_FRMCONLIVROS_LISTCONSULTA, m_ListConsulta);
	DDX_Control(pDX, ID_FRMCONLIVROS_LABREGISTROS, m_LabRegistros);
	DDX_Control(pDX, ID_FRMCONLIVROS_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCONLIVROS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCONLIVROS_BTNFECHAR, m_BtnFechar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmConLivros, CDialog)
	//{{AFX_MSG_MAP(CFrmConLivros)
	ON_BN_CLICKED(ID_FRMCONLIVROS_BTNFECHAR, OnBtnFechar)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_FRMCONLIVROS_BTNLIMPAR, OnBtnLimpar)
	ON_BN_CLICKED(ID_FRMCONLIVROS_BTNPESQUISAR, OnBtnPesquisar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmConLivros message handlers

void CFrmConLivros::OnBtnFechar() 
{
  SendMessage(WM_CLOSE,0,0);
}

BOOL CFrmConLivros::Create()
{
  bModal = FALSE;
	return CFrmConsultas::Create(m_nID, m_pParent);
}

void CFrmConLivros::PostNcDestroy() 
{
	delete this;
}

void CFrmConLivros::OnClose() 
{
  if (!bModal)
    ((CFrmPrincipal*)m_pParent)->frmConLivros = NULL;

  CFrmConsultas::Fecha(sSelecionados, CM_CON_LIVROS);
}

BOOL CFrmConLivros::OnInitDialog() 
{
	CFrmConsultas::OnInitDialog();
		
  LISTASTR sColunas;
  POSITION pos;
  UINT nLargura[] = { 80,180,80,80,80,80,100,80,100,80,80,80 };
  pos = sColunas.col.GetHeadPosition();
  sColunas.col.InsertAfter(pos, "ISBN");
  sColunas.col.InsertAfter(pos, "Título");
  sColunas.col.InsertAfter(pos, "Edição");
  sColunas.col.InsertAfter(pos, "AnoPublicação");
  sColunas.col.InsertAfter(pos, "Volume");
  sColunas.col.InsertAfter(pos, "CodEditora");
  sColunas.col.InsertAfter(pos, "Editora");
  sColunas.col.InsertAfter(pos, "CodIdioma");
  sColunas.col.InsertAfter(pos, "Idioma");
  sColunas.col.InsertAfter(pos, "NumPáginas");
  sColunas.col.InsertAfter(pos, "Preço");
  sColunas.col.InsertAfter(pos, "Estoque");          
   
  Rotinas->VisaoListaInsereColunas(&m_ListConsulta, nLargura, &sColunas);

  CFrmConsultas::Ativar(CM_CON_LIVROS);

	return TRUE;
}

BOOL CFrmConLivros::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  if (CFrmConsultas::Notifica(lParam, &m_ListConsulta,
      &m_LabRegistros, &lstLinhas, &sSelecionados))
       return 0;

  return CFrmConsultas::OnNotify(wParam, lParam, pResult);
}

void CFrmConLivros::OnSize(UINT nType, int cx, int cy) 
{
  CFrmConsultas::arrumaTamanho(&m_ListConsulta, 
    &m_LabRegistros, &m_BtnLimpar, &m_BtnFechar);
}

void CFrmConLivros::OnBtnLimpar() 
{
  CFrmConsultas::LimparDados(&m_LabRegistros, 
		&m_EdtDescricao, &m_ListConsulta, &lstLinhas);
}

void CFrmConLivros::OnBtnPesquisar() 
{
  CFrmConsultas::PesquisarDados(&m_ListConsulta, 
    &m_LabRegistros, &lstLinhas, ConsSQL->Livro('S',"", 
    Rotinas->retTexto(&m_EdtDescricao),"","","","","","","",""), 
    Rotinas->lerStr(STR_LIVNENC));
}
