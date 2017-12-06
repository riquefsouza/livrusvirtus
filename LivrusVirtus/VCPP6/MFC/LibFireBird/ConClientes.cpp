// ConClientes.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "ConClientes.h"
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
// CFrmConClientes dialog


CFrmConClientes::CFrmConClientes(CWnd* pParent /*=NULL*/)
	: CFrmConsultas(CFrmConClientes::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmConClientes)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  m_nID = CFrmConClientes::IDD;
	m_pParent = pParent;
}


void CFrmConClientes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmConClientes)
	DDX_Control(pDX, ID_FRMCONCLIENTES_LISTCONSULTA, m_ListConsulta);
	DDX_Control(pDX, ID_FRMCONCLIENTES_LABREGISTROS, m_LabRegistros);
	DDX_Control(pDX, ID_FRMCONCLIENTES_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCONCLIENTES_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCONCLIENTES_BTNFECHAR, m_BtnFechar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmConClientes, CDialog)
	//{{AFX_MSG_MAP(CFrmConClientes)
	ON_BN_CLICKED(ID_FRMCONCLIENTES_BTNFECHAR, OnBtnFechar)
	ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_FRMCONCLIENTES_BTNLIMPAR, OnBtnLimpar)
	ON_BN_CLICKED(ID_FRMCONCLIENTES_BTNPESQUISAR, OnBtnPesquisar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmConClientes message handlers

void CFrmConClientes::OnBtnFechar() 
{
  SendMessage(WM_CLOSE,0,0);
}

BOOL CFrmConClientes::Create()
{
  bModal = FALSE;
	return CFrmConsultas::Create(m_nID, m_pParent);
}

void CFrmConClientes::PostNcDestroy() 
{
	delete this;
}

void CFrmConClientes::OnClose() 
{
  if (!bModal)
    ((CFrmPrincipal*)m_pParent)->frmConClientes = NULL;

  CFrmConsultas::Fecha(sSelecionados, CM_CON_CLIENTES);
}

BOOL CFrmConClientes::OnInitDialog() 
{
	CFrmConsultas::OnInitDialog();
		
  LISTASTR sColunas;
  POSITION pos;
  UINT nLargura[] = { 90,220,180,80,40,80,120,80,220,150,
          80,100,100,80,180,80,100 };
  pos = sColunas.col.GetHeadPosition();
  sColunas.col.InsertAfter(pos, "CPF");
  sColunas.col.InsertAfter(pos, "Nome");
  sColunas.col.InsertAfter(pos, "Email");
  sColunas.col.InsertAfter(pos, "Identidade");
  sColunas.col.InsertAfter(pos, "Sexo");
  sColunas.col.InsertAfter(pos, "Telefone");
  sColunas.col.InsertAfter(pos, "DtNascimento");
  sColunas.col.InsertAfter(pos, "CodEndereço");
  sColunas.col.InsertAfter(pos, "Logradouro");
  sColunas.col.InsertAfter(pos, "Bairro");
  sColunas.col.InsertAfter(pos, "CEP");
  sColunas.col.InsertAfter(pos, "Cidade");
  sColunas.col.InsertAfter(pos, "Estado");
  sColunas.col.InsertAfter(pos, "CodPaís");
  sColunas.col.InsertAfter(pos, "País");
  sColunas.col.InsertAfter(pos, "CodProfissão");
  sColunas.col.InsertAfter(pos, "Profissão");
    
  Rotinas->VisaoListaInsereColunas(&m_ListConsulta, nLargura, &sColunas);

  CFrmConsultas::Ativar(CM_CON_CLIENTES);

	return TRUE;
}

BOOL CFrmConClientes::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  if (CFrmConsultas::Notifica(lParam, &m_ListConsulta,
      &m_LabRegistros, &lstLinhas, &sSelecionados))
       return 0;

  return CFrmConsultas::OnNotify(wParam, lParam, pResult);
}

void CFrmConClientes::OnSize(UINT nType, int cx, int cy) 
{
  CFrmConsultas::arrumaTamanho(&m_ListConsulta, 
    &m_LabRegistros, &m_BtnLimpar, &m_BtnFechar);
}

void CFrmConClientes::OnBtnLimpar() 
{
  CFrmConsultas::LimparDados(&m_LabRegistros, 
		&m_EdtDescricao, &m_ListConsulta, &lstLinhas);
}

void CFrmConClientes::OnBtnPesquisar() 
{
  CFrmConsultas::PesquisarDados(&m_ListConsulta, 
    &m_LabRegistros, &lstLinhas, ConsSQL->Cliente('S',"",
    Rotinas->retTexto(&m_EdtDescricao),"","","","","","","",""), 
    Rotinas->lerStr(STR_CLINENC));
}
