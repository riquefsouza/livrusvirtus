// CadIdiomas.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "CadIdiomas.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmCadIdiomas dialog


CFrmCadIdiomas::CFrmCadIdiomas(CWnd* pParent /*=NULL*/)
	: CFrmCadastros()
{
	//{{AFX_DATA_INIT(CFrmCadIdiomas)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrmCadIdiomas::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmCadIdiomas)
	DDX_Control(pDX, ID_FRMCADIDIOMAS_BTNSALVAR, m_BtnSalvar);
	DDX_Control(pDX, ID_FRMCADIDIOMAS_BTNPROXIMO, m_BtnProximo);
	DDX_Control(pDX, ID_FRMCADIDIOMAS_BTNPESQUISAR, m_BtnPesquisar);
	DDX_Control(pDX, ID_FRMCADIDIOMAS_BTNNOVO, m_BtnNovo);
	DDX_Control(pDX, ID_FRMCADIDIOMAS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCADIDIOMAS_BTNFECHAR, m_BtnFechar);
	DDX_Control(pDX, ID_FRMCADIDIOMAS_BTNEXCLUIR, m_BtnExcluir);
	DDX_Control(pDX, ID_FRMCADIDIOMAS_BTNANTERIOR, m_BtnAnterior);
	DDX_Control(pDX, ID_FRMCADIDIOMAS_EDTDESCRICAO, m_EdtDescricao);
	DDX_Control(pDX, ID_FRMCADIDIOMAS_EDTCODIGO, m_EdtCodigo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmCadIdiomas, CDialog)
	//{{AFX_MSG_MAP(CFrmCadIdiomas)
	ON_BN_CLICKED(ID_FRMCADIDIOMAS_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMCADIDIOMAS_BTNNOVO, OnBtnNovo)
	ON_BN_CLICKED(ID_FRMCADIDIOMAS_BTNPESQUISAR, OnBtnPesquisar)
	ON_BN_CLICKED(ID_FRMCADIDIOMAS_BTNANTERIOR, OnBtnAnterior)
	ON_BN_CLICKED(ID_FRMCADIDIOMAS_BTNPROXIMO, OnBtnProximo)
	ON_BN_CLICKED(ID_FRMCADIDIOMAS_BTNSALVAR, OnBtnSalvar)
	ON_BN_CLICKED(ID_FRMCADIDIOMAS_BTNEXCLUIR, OnBtnExcluir)
	ON_BN_CLICKED(ID_FRMCADIDIOMAS_BTNLIMPAR, OnBtnLimpar)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmCadIdiomas message handlers

BOOL CFrmCadIdiomas::OnInitDialog() 
{
	CFrmCadastros::OnInitDialog();
	
	m_EdtCodigo.SetLimitText(10);
  m_EdtDescricao.SetLimitText(30);
  nRegistros = 0;
	return TRUE;  
}

BOOL CFrmCadIdiomas::ValidaDados(BOOL bTodosDados)
{
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCodigo), 
    Rotinas->lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtDescricao), 
           Rotinas->lerStr(STR_IDININF)))
  		return FALSE;
  	}
  	return TRUE;
}

void CFrmCadIdiomas::OnBtnNovo() 
{
  CFrmCadastros::btnNovoClick(&m_EdtCodigo, 
  &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
  &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);

  CFrmCadastros::NovoDado(&m_EdtCodigo, &m_EdtDescricao, 
    ConsSQL->Idioma('N', Rotinas->retTexto(&m_EdtCodigo),""));	
}

void CFrmCadIdiomas::OnBtnPesquisar() 
{
  CFrmCadastros::PesquisarDados(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &m_BtnPesquisar, 
    &m_BtnAnterior, &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, 
    ConsSQL->Idioma('S', Rotinas->retTexto(&m_EdtCodigo),""), 
      Rotinas->lerStr(STR_IDINENC));
}

void CFrmCadIdiomas::OnBtnAnterior() 
{
  CFrmCadastros::registroAnterior(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);	
}

void CFrmCadIdiomas::OnBtnProximo() 
{
  CFrmCadastros::registroProximo(&lstRegistros, 
    &m_EdtCodigo, &m_EdtDescricao, &nRegistros);		
}

void CFrmCadIdiomas::OnBtnSalvar() 
{
  CFrmCadastros::SalvarDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(TRUE),
    ConsSQL->Idioma('S', Rotinas->retTexto(&m_EdtCodigo),""),
    ConsSQL->Idioma('U', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)),
    ConsSQL->Idioma('I', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtDescricao)), TRUE);
}

void CFrmCadIdiomas::OnBtnExcluir() 
{
  CFrmCadastros::ExcluirDados(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(FALSE),
    ConsSQL->Idioma('D', Rotinas->retTexto(&m_EdtCodigo),""));
}

void CFrmCadIdiomas::OnBtnLimpar() 
{
  CFrmCadastros::btnLimparClick(&m_EdtCodigo, 
    &m_EdtDescricao, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);	
}

void CFrmCadIdiomas::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);
}

void CFrmCadIdiomas::OnClose() 
{
  CFrmCadastros::Fechar(0, CM_CAD_IDIOMAS);  
}
