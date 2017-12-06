// CadEnderecos.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "CadEnderecos.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmCadEnderecos dialog


CFrmCadEnderecos::CFrmCadEnderecos(CWnd* pParent /*=NULL*/)
	: CFrmCadastros()
{
	//{{AFX_DATA_INIT(CFrmCadEnderecos)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrmCadEnderecos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmCadEnderecos)
	DDX_Control(pDX, ID_FRMCADENDERECOS_EDTCIDADE, m_EdtCidade);
	DDX_Control(pDX, ID_FRMCADENDERECOS_EDTCEP, m_EdtCEP);
	DDX_Control(pDX, ID_FRMCADENDERECOS_EDTBAIRRO, m_EdtBairro);
	DDX_Control(pDX, ID_FRMCADENDERECOS_CMBESTADO, m_CmbEstado);
	DDX_Control(pDX, ID_FRMCADENDERECOS_BTNSALVAR, m_BtnSalvar);
	DDX_Control(pDX, ID_FRMCADENDERECOS_BTNPROXIMO, m_BtnProximo);
	DDX_Control(pDX, ID_FRMCADENDERECOS_BTNPESQUISAR, m_BtnPesquisar);
	DDX_Control(pDX, ID_FRMCADENDERECOS_BTNNOVO, m_BtnNovo);
	DDX_Control(pDX, ID_FRMCADENDERECOS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCADENDERECOS_BTNFECHAR, m_BtnFechar);
	DDX_Control(pDX, ID_FRMCADENDERECOS_BTNEXCLUIR, m_BtnExcluir);
	DDX_Control(pDX, ID_FRMCADENDERECOS_BTNANTERIOR, m_BtnAnterior);
	DDX_Control(pDX, ID_FRMCADENDERECOS_EDTLOGRADOURO, m_EdtLogradouro);
	DDX_Control(pDX, ID_FRMCADENDERECOS_EDTCODIGO, m_EdtCodigo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmCadEnderecos, CDialog)
	//{{AFX_MSG_MAP(CFrmCadEnderecos)
	ON_BN_CLICKED(ID_FRMCADENDERECOS_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMCADENDERECOS_BTNNOVO, OnBtnNovo)
	ON_BN_CLICKED(ID_FRMCADENDERECOS_BTNPESQUISAR, OnBtnPesquisar)
	ON_BN_CLICKED(ID_FRMCADENDERECOS_BTNANTERIOR, OnBtnAnterior)
	ON_BN_CLICKED(ID_FRMCADENDERECOS_BTNPROXIMO, OnBtnProximo)
	ON_BN_CLICKED(ID_FRMCADENDERECOS_BTNSALVAR, OnBtnSalvar)
	ON_BN_CLICKED(ID_FRMCADENDERECOS_BTNEXCLUIR, OnBtnExcluir)
	ON_BN_CLICKED(ID_FRMCADENDERECOS_BTNLIMPAR, OnBtnLimpar)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmCadEnderecos message handlers

BOOL CFrmCadEnderecos::OnInitDialog() 
{
	CFrmCadastros::OnInitDialog();
	
	m_EdtCodigo.SetLimitText(10);
  m_EdtLogradouro.SetLimitText(40);
  m_EdtBairro.SetLimitText(15);
  m_EdtCEP.SetLimitText(8);
  m_EdtCidade.SetLimitText(30);
  AdicionaCombo();
  nRegistros = 0;
	return TRUE;  
}

BOOL CFrmCadEnderecos::ValidaDados(BOOL bTodosDados)
{
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCodigo), 
    Rotinas->lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtLogradouro), 
           Rotinas->lerStr(STR_ENDNINF)))
   		  return FALSE;
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtBairro), 
           Rotinas->lerStr(STR_BAIRRONINF)))
   		  return FALSE;
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCEP), 
           Rotinas->lerStr(STR_CEPNINF)))
   		  return FALSE;
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCidade), 
           Rotinas->lerStr(STR_CIDADENINF)))
   		  return FALSE;
  	}
  	return TRUE;
}

void CFrmCadEnderecos::OnBtnNovo() 
{
  CFrmCadastros::btnNovoClick(&m_EdtCodigo, 
  &m_EdtLogradouro, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
  &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);

  InformaLimpaDados(NULL, 0, FALSE);
  HabilitaDados(TRUE);	

  CFrmCadastros::NovoDado(&m_EdtCodigo, &m_EdtLogradouro, 
    ConsSQL->Endereco('N', Rotinas->retTexto(&m_EdtCodigo),"","","","",""));
}

void CFrmCadEnderecos::OnBtnPesquisar() 
{
  if (CFrmCadastros::PesquisarDados(&lstRegistros, 
    &m_EdtCodigo, &m_EdtLogradouro, &m_BtnPesquisar, 
    &m_BtnAnterior, &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, 
    ConsSQL->Endereco('S', Rotinas->retTexto(&m_EdtCodigo),"","","","",""), 
      Rotinas->lerStr(STR_ENDNENC))) {
      InformaLimpaDados(&lstRegistros,0, TRUE);
      HabilitaDados(TRUE);	
    }
}

void CFrmCadEnderecos::OnBtnAnterior() 
{
  if (CFrmCadastros::registroAnterior(&lstRegistros, 
    &m_EdtCodigo, &m_EdtLogradouro, &nRegistros)) {
    InformaLimpaDados(&lstRegistros, nRegistros, TRUE);
  }  	
}

void CFrmCadEnderecos::OnBtnProximo() 
{
  if (CFrmCadastros::registroProximo(&lstRegistros, 
    &m_EdtCodigo, &m_EdtLogradouro, &nRegistros)) {
    InformaLimpaDados(&lstRegistros, nRegistros, TRUE);
  }  			
}

void CFrmCadEnderecos::OnBtnSalvar() 
{ CString sEstado;

  sEstado = Rotinas->retTexto(&m_CmbEstado);
  if (CFrmCadastros::SalvarDados(&m_EdtCodigo, 
    &m_EdtLogradouro, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(TRUE),
    ConsSQL->Endereco('S', Rotinas->retTexto(&m_EdtCodigo),"","","","",""),
    ConsSQL->Endereco('U', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtLogradouro), Rotinas->retTexto(&m_EdtBairro),
      Rotinas->retTexto(&m_EdtCEP), Rotinas->retTexto(&m_EdtCidade), sEstado),
    ConsSQL->Endereco('I', Rotinas->retTexto(&m_EdtCodigo), 
      Rotinas->retTexto(&m_EdtLogradouro), Rotinas->retTexto(&m_EdtBairro),
      Rotinas->retTexto(&m_EdtCEP), Rotinas->retTexto(&m_EdtCidade),
      sEstado), TRUE)) {
    InformaLimpaDados(NULL, 0, FALSE);
    HabilitaDados(FALSE);	
  }  
}

void CFrmCadEnderecos::OnBtnExcluir() 
{
  if (CFrmCadastros::ExcluirDados(&m_EdtCodigo, 
    &m_EdtLogradouro, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(FALSE),
    ConsSQL->Endereco('D', Rotinas->retTexto(&m_EdtCodigo),"","","","",""))) {
    InformaLimpaDados(NULL, 0, FALSE);
    HabilitaDados(FALSE);	
  }  
}

void CFrmCadEnderecos::OnBtnLimpar() 
{
  CFrmCadastros::btnLimparClick(&m_EdtCodigo, 
    &m_EdtLogradouro, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);	
  InformaLimpaDados(NULL, 0, FALSE);
  HabilitaDados(FALSE);	
}

void CFrmCadEnderecos::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);
}

void CFrmCadEnderecos::OnClose() 
{
  CFrmCadastros::Fechar(0, CM_CAD_ENDERECOS);  
}

void CFrmCadEnderecos::InformaLimpaDados(LISTAMSTR *lstRegistros, 
  UINT nLinhaRegistro, BOOL bInformar)
{ POSITION pos;
  if (bInformar) {
    pos = lstRegistros->col[2].FindIndex(nLinhaRegistro);
    m_EdtBairro.SetWindowText(lstRegistros->col[2].GetAt(pos));
    pos = lstRegistros->col[3].FindIndex(nLinhaRegistro);
    m_EdtCEP.SetWindowText(lstRegistros->col[3].GetAt(pos));
    pos = lstRegistros->col[4].FindIndex(nLinhaRegistro);
    m_EdtCidade.SetWindowText(lstRegistros->col[4].GetAt(pos));
    pos = lstRegistros->col[5].FindIndex(nLinhaRegistro);
    m_CmbEstado.SelectString(0,lstRegistros->col[5].GetAt(pos));
  } else {
    m_EdtBairro.SetWindowText("");
    m_EdtCEP.SetWindowText("");
    m_EdtCidade.SetWindowText("");    
    m_CmbEstado.SetCurSel(0);
  }
} 

void CFrmCadEnderecos::HabilitaDados(BOOL bHabilita)
{
  m_EdtBairro.EnableWindow(bHabilita);
  m_EdtCEP.EnableWindow(bHabilita);  
  m_EdtCidade.EnableWindow(bHabilita);
  m_CmbEstado.EnableWindow(bHabilita);  
}

void CFrmCadEnderecos::AdicionaCombo()
{ 
  m_CmbEstado.AddString(Rotinas->lerStr(STR_PE));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_AC));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_AL));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_AP));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_AM));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_BA));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_BR));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_CE));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_DF));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_ES));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_GO));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_MT));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_MS));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_MG));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_PA));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_PB));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_PR));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_SC));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_RN));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_RS));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_RJ));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_RO));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_RR));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_SP));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_SE));
  m_CmbEstado.AddString(Rotinas->lerStr(STR_TO));
}

