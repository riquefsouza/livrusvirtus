// CadAssuntos.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "CadAssuntos.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmCadAssuntos dialog

CFrmCadAssuntos::CFrmCadAssuntos(CWnd* pParent /*=NULL*/)
  : CFrmCadastros()
{
	//{{AFX_DATA_INIT(CFrmCadAssuntos)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrmCadAssuntos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmCadAssuntos)
	DDX_Control(pDX, ID_FRMCADASSUNTOS_BTNSALVAR, m_BtnSalvar);
	DDX_Control(pDX, ID_FRMCADASSUNTOS_BTNPROXIMO, m_BtnProximo);
	DDX_Control(pDX, ID_FRMCADASSUNTOS_BTNPESQUISAR, m_BtnPesquisar);
	DDX_Control(pDX, ID_FRMCADASSUNTOS_BTNNOVO, m_BtnNovo);
	DDX_Control(pDX, ID_FRMCADASSUNTOS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCADASSUNTOS_BTNFECHAR, m_BtnFechar);
	DDX_Control(pDX, ID_FRMCADASSUNTOS_BTNEXCLUIR, m_BtnExcluir);
	DDX_Control(pDX, ID_FRMCADASSUNTOS_BTNANTERIOR, m_BtnAnterior);
	DDX_Control(pDX, ID_FRMCADASSUNTOS_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCADASSUNTOS_EDTCODIGO, m_EdtCodigo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmCadAssuntos, CDialog)
	//{{AFX_MSG_MAP(CFrmCadAssuntos)
	ON_BN_CLICKED(ID_FRMCADASSUNTOS_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMCADASSUNTOS_BTNNOVO, OnBtnNovo)
	ON_BN_CLICKED(ID_FRMCADASSUNTOS_BTNPESQUISAR, OnBtnPesquisar)
	ON_BN_CLICKED(ID_FRMCADASSUNTOS_BTNANTERIOR, OnBtnAnterior)
	ON_BN_CLICKED(ID_FRMCADASSUNTOS_BTNPROXIMO, OnBtnProximo)
	ON_BN_CLICKED(ID_FRMCADASSUNTOS_BTNSALVAR, OnBtnSalvar)
	ON_BN_CLICKED(ID_FRMCADASSUNTOS_BTNEXCLUIR, OnBtnExcluir)
	ON_BN_CLICKED(ID_FRMCADASSUNTOS_BTNLIMPAR, OnBtnLimpar)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmCadAssuntos message handlers

BOOL CFrmCadAssuntos::OnInitDialog() 
{
	CFrmCadastros::OnInitDialog();
	
	m_EdtCodigo.SetLimitText(10);
  m_EdtDescricao.SetLimitText(30);
  nRegistros = 0;
	return TRUE;  
}

BOOL CFrmCadAssuntos::ValidaDados(BOOL bTodosDados)
{
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCodigo), 
    Rotinas->lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtDescricao), 
           Rotinas->lerStr(STR_ASSNINF)))
  		return FALSE;
  	}
  	return TRUE;
}

void CFrmCadAssuntos::OnBtnNovo() 
{
  CFrmCadastros::btnNovoClick(&m_EdtCodigo, 
  &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
  &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);

  CFrmCadastros::NovoDado(&m_EdtCodigo, &m_EdtDescricao, 
    ConsSQL->Assunto('N', Rotinas->retTexto(&m_EdtCodigo),""));	
}

void CFrmCadAssuntos::OnBtnPesquisar() 
{
  CFrmCadastros::PesquisarDados(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &m_BtnPesquisar, 
    &m_BtnAnterior, &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, 
    ConsSQL->Assunto('S', Rotinas->retTexto(&m_EdtCodigo),""), 
      Rotinas->lerStr(STR_ASSNENC));
}

void CFrmCadAssuntos::OnBtnAnterior() 
{
  CFrmCadastros::registroAnterior(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);	
}

void CFrmCadAssuntos::OnBtnProximo() 
{
  CFrmCadastros::registroProximo(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);		
}

void CFrmCadAssuntos::OnBtnSalvar() 
{
  CFrmCadastros::SalvarDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(TRUE),
    ConsSQL->Assunto('S', Rotinas->retTexto(&m_EdtCodigo),""),
    ConsSQL->Assunto('U', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)),
    ConsSQL->Assunto('I', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)), TRUE);
}

void CFrmCadAssuntos::OnBtnExcluir() 
{
  CFrmCadastros::ExcluirDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(FALSE),
    ConsSQL->Assunto('D', Rotinas->retTexto(&m_EdtCodigo),""));
}

void CFrmCadAssuntos::OnBtnLimpar() 
{
  CFrmCadastros::btnLimparClick(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);	  
}

void CFrmCadAssuntos::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);
}

void CFrmCadAssuntos::OnClose() 
{
 CFrmCadastros::Fechar(0, CM_CAD_ASSUNTOS);
}

