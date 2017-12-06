// CadPaises.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "CadPaises.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmCadPaises dialog


CFrmCadPaises::CFrmCadPaises(CWnd* pParent /*=NULL*/)
	: CFrmCadastros()
{
	//{{AFX_DATA_INIT(CFrmCadPaises)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrmCadPaises::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmCadPaises)
	DDX_Control(pDX, ID_FRMCADPAISES_BTNSALVAR, m_BtnSalvar);
	DDX_Control(pDX, ID_FRMCADPAISES_BTNPROXIMO, m_BtnProximo);
	DDX_Control(pDX, ID_FRMCADPAISES_BTNPESQUISAR, m_BtnPesquisar);
	DDX_Control(pDX, ID_FRMCADPAISES_BTNNOVO, m_BtnNovo);
	DDX_Control(pDX, ID_FRMCADPAISES_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCADPAISES_BTNFECHAR, m_BtnFechar);
	DDX_Control(pDX, ID_FRMCADPAISES_BTNEXCLUIR, m_BtnExcluir);
	DDX_Control(pDX, ID_FRMCADPAISES_BTNANTERIOR, m_BtnAnterior);
	DDX_Control(pDX, ID_FRMCADPAISES_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCADPAISES_EDTCODIGO, m_EdtCodigo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmCadPaises, CDialog)
	//{{AFX_MSG_MAP(CFrmCadPaises)
	ON_BN_CLICKED(ID_FRMCADPAISES_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMCADPAISES_BTNNOVO, OnBtnNovo)
	ON_BN_CLICKED(ID_FRMCADPAISES_BTNPESQUISAR, OnBtnPesquisar)
	ON_BN_CLICKED(ID_FRMCADPAISES_BTNANTERIOR, OnBtnAnterior)
	ON_BN_CLICKED(ID_FRMCADPAISES_BTNPROXIMO, OnBtnProximo)
	ON_BN_CLICKED(ID_FRMCADPAISES_BTNSALVAR, OnBtnSalvar)
	ON_BN_CLICKED(ID_FRMCADPAISES_BTNEXCLUIR, OnBtnExcluir)
	ON_BN_CLICKED(ID_FRMCADPAISES_BTNLIMPAR, OnBtnLimpar)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmCadPaises message handlers

BOOL CFrmCadPaises::OnInitDialog() 
{
	CFrmCadastros::OnInitDialog();
	
	m_EdtCodigo.SetLimitText(3);
  m_EdtDescricao.SetLimitText(30);
  nRegistros = 0;
	return TRUE;  
}

BOOL CFrmCadPaises::ValidaDados(BOOL bTodosDados)
{
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCodigo), 
    Rotinas->lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtDescricao), 
           Rotinas->lerStr(STR_PAISNINF)))
  		return FALSE;
  	}
  	return TRUE;
}

void CFrmCadPaises::OnBtnNovo() 
{
  CFrmCadastros::btnNovoClick(&m_EdtCodigo, 
  &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
  &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);
}

void CFrmCadPaises::OnBtnPesquisar() 
{
  CFrmCadastros::PesquisarDados(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &m_BtnPesquisar, 
    &m_BtnAnterior, &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, 
    ConsSQL->Pais('S', Rotinas->retTexto(&m_EdtCodigo),""), 
      Rotinas->lerStr(STR_PAISNENC));
}

void CFrmCadPaises::OnBtnAnterior() 
{
  CFrmCadastros::registroAnterior(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);	
}

void CFrmCadPaises::OnBtnProximo() 
{
  CFrmCadastros::registroProximo(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);		
}

void CFrmCadPaises::OnBtnSalvar() 
{
  CFrmCadastros::SalvarDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(TRUE),
    ConsSQL->Pais('S', Rotinas->retTexto(&m_EdtCodigo),""),
    ConsSQL->Pais('U', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)),
    ConsSQL->Pais('I', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)), TRUE);
}

void CFrmCadPaises::OnBtnExcluir() 
{
  CFrmCadastros::ExcluirDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(FALSE),
    ConsSQL->Pais('D', Rotinas->retTexto(&m_EdtCodigo),""));
}

void CFrmCadPaises::OnBtnLimpar() 
{
  CFrmCadastros::btnLimparClick(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);	
}

void CFrmCadPaises::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);
}

void CFrmCadPaises::OnClose() 
{
  CFrmCadastros::Fechar(0, CM_CAD_PAISES);  
}
