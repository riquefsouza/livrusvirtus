// CadEditoras.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "CadEditoras.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmCadEditoras dialog


CFrmCadEditoras::CFrmCadEditoras(CWnd* pParent /*=NULL*/)
	: CFrmCadastros()
{
	//{{AFX_DATA_INIT(CFrmCadEditoras)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrmCadEditoras::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmCadEditoras)
	DDX_Control(pDX, ID_FRMCADEDITORAS_BTNSALVAR, m_BtnSalvar);
	DDX_Control(pDX, ID_FRMCADEDITORAS_BTNPROXIMO, m_BtnProximo);
	DDX_Control(pDX, ID_FRMCADEDITORAS_BTNPESQUISAR, m_BtnPesquisar);
	DDX_Control(pDX, ID_FRMCADEDITORAS_BTNNOVO, m_BtnNovo);
	DDX_Control(pDX, ID_FRMCADEDITORAS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCADEDITORAS_BTNFECHAR, m_BtnFechar);
	DDX_Control(pDX, ID_FRMCADEDITORAS_BTNEXCLUIR, m_BtnExcluir);
	DDX_Control(pDX, ID_FRMCADEDITORAS_BTNANTERIOR, m_BtnAnterior);
	DDX_Control(pDX, ID_FRMCADEDITORAS_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCADEDITORAS_EDTCODIGO, m_EdtCodigo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmCadEditoras, CDialog)
	//{{AFX_MSG_MAP(CFrmCadEditoras)
	ON_BN_CLICKED(ID_FRMCADEDITORAS_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMCADEDITORAS_BTNNOVO, OnBtnNovo)
	ON_BN_CLICKED(ID_FRMCADEDITORAS_BTNPESQUISAR, OnBtnPesquisar)
	ON_BN_CLICKED(ID_FRMCADEDITORAS_BTNANTERIOR, OnBtnAnterior)
	ON_BN_CLICKED(ID_FRMCADEDITORAS_BTNPROXIMO, OnBtnProximo)
	ON_BN_CLICKED(ID_FRMCADEDITORAS_BTNSALVAR, OnBtnSalvar)
	ON_BN_CLICKED(ID_FRMCADEDITORAS_BTNEXCLUIR, OnBtnExcluir)
	ON_BN_CLICKED(ID_FRMCADEDITORAS_BTNLIMPAR, OnBtnLimpar)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmCadEditoras message handlers

BOOL CFrmCadEditoras::OnInitDialog() 
{
	CFrmCadastros::OnInitDialog();
	
	m_EdtCodigo.SetLimitText(10);
  m_EdtDescricao.SetLimitText(30);
  nRegistros = 0;
	return TRUE;  
}

BOOL CFrmCadEditoras::ValidaDados(BOOL bTodosDados)
{
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCodigo), 
    Rotinas->lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtDescricao), 
           Rotinas->lerStr(STR_EDTNINF)))
  		return FALSE;
  	}
  	return TRUE;
}

void CFrmCadEditoras::OnBtnNovo() 
{
  CFrmCadastros::btnNovoClick(&m_EdtCodigo, 
  &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
  &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);

  CFrmCadastros::NovoDado(&m_EdtCodigo, &m_EdtDescricao, 
    ConsSQL->Editora('N', Rotinas->retTexto(&m_EdtCodigo),""));	
}

void CFrmCadEditoras::OnBtnPesquisar() 
{
  CFrmCadastros::PesquisarDados(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &m_BtnPesquisar, 
    &m_BtnAnterior, &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, 
    ConsSQL->Editora('S', Rotinas->retTexto(&m_EdtCodigo),""), 
      Rotinas->lerStr(STR_EDTNENC));
}

void CFrmCadEditoras::OnBtnAnterior() 
{
  CFrmCadastros::registroAnterior(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);	
}

void CFrmCadEditoras::OnBtnProximo() 
{
  CFrmCadastros::registroProximo(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);		
}

void CFrmCadEditoras::OnBtnSalvar() 
{
  CFrmCadastros::SalvarDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(TRUE),
    ConsSQL->Editora('S', Rotinas->retTexto(&m_EdtCodigo),""),
    ConsSQL->Editora('U', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)),
    ConsSQL->Editora('I', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)), TRUE);
}

void CFrmCadEditoras::OnBtnExcluir() 
{
  CFrmCadastros::ExcluirDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(FALSE),
    ConsSQL->Editora('D', Rotinas->retTexto(&m_EdtCodigo),""));
}

void CFrmCadEditoras::OnBtnLimpar() 
{
  CFrmCadastros::btnLimparClick(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);	
}

void CFrmCadEditoras::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);
}

void CFrmCadEditoras::OnClose() 
{
  CFrmCadastros::Fechar(0, CM_CAD_EDITORAS);  
}
