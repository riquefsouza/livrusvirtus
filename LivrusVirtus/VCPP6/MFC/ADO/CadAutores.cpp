// CadAutores.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "Cadastros.h"
#include "CadAutores.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmCadAutores dialog


CFrmCadAutores::CFrmCadAutores(CWnd* pParent /*=NULL*/)
	: CFrmCadastros()
{
	//{{AFX_DATA_INIT(CFrmCadAutores)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrmCadAutores::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmCadAutores)
	DDX_Control(pDX, ID_FRMCADAUTORES_BTNSALVAR, m_BtnSalvar);
	DDX_Control(pDX, ID_FRMCADAUTORES_BTNPROXIMO, m_BtnProximo);
	DDX_Control(pDX, ID_FRMCADAUTORES_BTNPESQUISAR, m_BtnPesquisar);
	DDX_Control(pDX, ID_FRMCADAUTORES_BTNNOVO, m_BtnNovo);
	DDX_Control(pDX, ID_FRMCADAUTORES_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCADAUTORES_BTNFECHAR, m_BtnFechar);
	DDX_Control(pDX, ID_FRMCADAUTORES_BTNEXCLUIR, m_BtnExcluir);
	DDX_Control(pDX, ID_FRMCADAUTORES_BTNANTERIOR, m_BtnAnterior);
	DDX_Control(pDX, ID_FRMCADAUTORES_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCADAUTORES_EDTCODIGO, m_EdtCodigo);

	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmCadAutores, CDialog)
	//{{AFX_MSG_MAP(CFrmCadAutores)
	ON_BN_CLICKED(ID_FRMCADAUTORES_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMCADAUTORES_BTNNOVO, OnBtnNovo)
	ON_BN_CLICKED(ID_FRMCADAUTORES_BTNPESQUISAR, OnBtnPesquisar)
	ON_BN_CLICKED(ID_FRMCADAUTORES_BTNANTERIOR, OnBtnAnterior)
	ON_BN_CLICKED(ID_FRMCADAUTORES_BTNPROXIMO, OnBtnProximo)
	ON_BN_CLICKED(ID_FRMCADAUTORES_BTNSALVAR, OnBtnSalvar)
	ON_BN_CLICKED(ID_FRMCADAUTORES_BTNEXCLUIR, OnBtnExcluir)
	ON_BN_CLICKED(ID_FRMCADAUTORES_BTNLIMPAR, OnBtnLimpar)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmCadAutores message handlers

BOOL CFrmCadAutores::OnInitDialog() 
{
	CFrmCadastros::OnInitDialog();
	
	m_EdtCodigo.SetLimitText(10);
  m_EdtDescricao.SetLimitText(30);
  nRegistros = 0;
	return TRUE;  
}

BOOL CFrmCadAutores::ValidaDados(BOOL bTodosDados)
{
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCodigo), 
    Rotinas->lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtDescricao), 
           Rotinas->lerStr(STR_AUTNINF)))
  		return FALSE;
  	}
  	return TRUE;
}

void CFrmCadAutores::OnBtnNovo() 
{
  CFrmCadastros::btnNovoClick(&m_EdtCodigo, 
  &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
  &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);

  CFrmCadastros::NovoDado(&m_EdtCodigo, &m_EdtDescricao, 
    ConsSQL->Autor('N', Rotinas->retTexto(&m_EdtCodigo),""));	
}

void CFrmCadAutores::OnBtnPesquisar() 
{
  CFrmCadastros::PesquisarDados(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &m_BtnPesquisar, 
    &m_BtnAnterior, &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, 
    ConsSQL->Autor('S', Rotinas->retTexto(&m_EdtCodigo),""), 
      Rotinas->lerStr(STR_AUTNENC));
}

void CFrmCadAutores::OnBtnAnterior() 
{
  CFrmCadastros::registroAnterior(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);	
}

void CFrmCadAutores::OnBtnProximo() 
{
  CFrmCadastros::registroProximo(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);		
}

void CFrmCadAutores::OnBtnSalvar() 
{
  CFrmCadastros::SalvarDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(TRUE),
    ConsSQL->Autor('S', Rotinas->retTexto(&m_EdtCodigo),""),
    ConsSQL->Autor('U', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)),
    ConsSQL->Autor('I', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)), TRUE);
}

void CFrmCadAutores::OnBtnExcluir() 
{
  CFrmCadastros::ExcluirDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(FALSE),
    ConsSQL->Autor('D', Rotinas->retTexto(&m_EdtCodigo),""));
}

void CFrmCadAutores::OnBtnLimpar() 
{
  CFrmCadastros::btnLimparClick(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);	
}

void CFrmCadAutores::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);
}

void CFrmCadAutores::OnClose() 
{
  CFrmCadastros::Fechar(0, CM_CAD_AUTORES);
}
