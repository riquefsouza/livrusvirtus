// CadProfissoes.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "CadProfissoes.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmCadProfissoes dialog


CFrmCadProfissoes::CFrmCadProfissoes(CWnd* pParent /*=NULL*/)
	: CFrmCadastros()
{
	//{{AFX_DATA_INIT(CFrmCadProfissoes)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrmCadProfissoes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmCadProfissoes)
	DDX_Control(pDX, ID_FRMCADPROFISSOES_BTNSALVAR, m_BtnSalvar);
	DDX_Control(pDX, ID_FRMCADPROFISSOES_BTNPROXIMO, m_BtnProximo);
	DDX_Control(pDX, ID_FRMCADPROFISSOES_BTNPESQUISAR, m_BtnPesquisar);
	DDX_Control(pDX, ID_FRMCADPROFISSOES_BTNNOVO, m_BtnNovo);
	DDX_Control(pDX, ID_FRMCADPROFISSOES_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCADPROFISSOES_BTNFECHAR, m_BtnFechar);
	DDX_Control(pDX, ID_FRMCADPROFISSOES_BTNEXCLUIR, m_BtnExcluir);
	DDX_Control(pDX, ID_FRMCADPROFISSOES_BTNANTERIOR, m_BtnAnterior);
	DDX_Control(pDX, ID_FRMCADPROFISSOES_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCADPROFISSOES_EDTCODIGO, m_EdtCodigo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmCadProfissoes, CDialog)
	//{{AFX_MSG_MAP(CFrmCadProfissoes)
	ON_BN_CLICKED(ID_FRMCADPROFISSOES_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMCADPROFISSOES_BTNNOVO, OnBtnNovo)
	ON_BN_CLICKED(ID_FRMCADPROFISSOES_BTNPESQUISAR, OnBtnPesquisar)
	ON_BN_CLICKED(ID_FRMCADPROFISSOES_BTNANTERIOR, OnBtnAnterior)
	ON_BN_CLICKED(ID_FRMCADPROFISSOES_BTNPROXIMO, OnBtnProximo)
	ON_BN_CLICKED(ID_FRMCADPROFISSOES_BTNSALVAR, OnBtnSalvar)
	ON_BN_CLICKED(ID_FRMCADPROFISSOES_BTNEXCLUIR, OnBtnExcluir)
	ON_BN_CLICKED(ID_FRMCADPROFISSOES_BTNLIMPAR, OnBtnLimpar)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmCadProfissoes message handlers

BOOL CFrmCadProfissoes::OnInitDialog() 
{
	CFrmCadastros::OnInitDialog();
	
	m_EdtCodigo.SetLimitText(10);
  m_EdtDescricao.SetLimitText(30);
  nRegistros = 0;
	return TRUE;  
}

BOOL CFrmCadProfissoes::ValidaDados(BOOL bTodosDados)
{
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCodigo), 
    Rotinas->lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtDescricao), 
           Rotinas->lerStr(STR_PROFNINF)))
  		return FALSE;
  	}
  	return TRUE;
}

void CFrmCadProfissoes::OnBtnNovo() 
{
  CFrmCadastros::btnNovoClick(&m_EdtCodigo, 
  &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
  &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);

  CFrmCadastros::NovoDado(&m_EdtCodigo, &m_EdtDescricao, 
    ConsSQL->Profissao('N', Rotinas->retTexto(&m_EdtCodigo),""));	
}

void CFrmCadProfissoes::OnBtnPesquisar() 
{
  CFrmCadastros::PesquisarDados(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &m_BtnPesquisar, 
    &m_BtnAnterior, &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, 
    ConsSQL->Profissao('S', Rotinas->retTexto(&m_EdtCodigo),""), 
      Rotinas->lerStr(STR_PROFNENC));
}

void CFrmCadProfissoes::OnBtnAnterior() 
{
  CFrmCadastros::registroAnterior(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);	
}

void CFrmCadProfissoes::OnBtnProximo() 
{
  CFrmCadastros::registroProximo(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);		
}

void CFrmCadProfissoes::OnBtnSalvar() 
{
  CFrmCadastros::SalvarDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(TRUE),
    ConsSQL->Profissao('S', Rotinas->retTexto(&m_EdtCodigo),""),
    ConsSQL->Profissao('U', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)),
    ConsSQL->Profissao('I', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)), TRUE);
}

void CFrmCadProfissoes::OnBtnExcluir() 
{
  CFrmCadastros::ExcluirDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(FALSE),
    ConsSQL->Profissao('D', Rotinas->retTexto(&m_EdtCodigo),""));
}

void CFrmCadProfissoes::OnBtnLimpar() 
{
  CFrmCadastros::btnLimparClick(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);	
}

void CFrmCadProfissoes::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);
}

void CFrmCadProfissoes::OnClose() 
{
  CFrmCadastros::Fechar(0, CM_CAD_PROFISSOES);  
}
