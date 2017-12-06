// AlterarSenha.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "Cadastros.h"
#include "AlterarSenha.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmAlterarSenha dialog


CFrmAlterarSenha::CFrmAlterarSenha(CWnd* pParent /*=NULL*/)
	: CFrmCadastros() //CDialog(CFrmAlterarSenha::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmAlterarSenha)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrmAlterarSenha::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmAlterarSenha)
	DDX_Control(pDX, ID_FRMALTERARSENHA_EDTCONFIRMASENHA, m_EdtConfirmaSenha);
	DDX_Control(pDX, ID_FRMALTERARSENHA_EDTSENHAATUAL, m_EdtSenhaAtual);
	DDX_Control(pDX, ID_FRMALTERARSENHA_EDTNOVASENHA, m_EdtNovaSenha);
	DDX_Control(pDX, ID_FRMALTERARSENHA_EDTLOGIN, m_EdtLogin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmAlterarSenha, CDialog)
	//{{AFX_MSG_MAP(CFrmAlterarSenha)
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_FRMALTERARSENHA_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMALTERARSENHA_BTNSALVAR, OnBtnSalvar)
	ON_BN_CLICKED(ID_FRMALTERARSENHA_BTNLIMPAR, OnBtnLimpar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmAlterarSenha message handlers

BOOL CFrmAlterarSenha::OnInitDialog() 
{
	CFrmCadastros::OnInitDialog();
	
  m_EdtLogin.SetWindowText(Rotinas_sUsuarioLogin.operator LPCTSTR());
   
	return TRUE;
}

void CFrmAlterarSenha::OnClose() 
{
  CFrmCadastros::Fechar(4, CM_OP_ALTERARSENHA);
}

void CFrmAlterarSenha::OnBtnFechar() 
{
	SendMessage(WM_CLOSE, 0, 0);	
}

void CFrmAlterarSenha::OnBtnSalvar() 
{
  if (ValidaDados()) {
    if (Rotinas->AtualizaDados(gConexao, 
      ConsSQL->Usuario('U', Rotinas->retTexto(&m_EdtLogin), 
      Rotinas->retTexto(&m_EdtConfirmaSenha)) 
    ))  {              
      AfxMessageBox(Rotinas->lerStr(STR_SENALTSUC), 
        MB_ICONINFORMATION | MB_OK, 0);
    }         
  }	
}

void CFrmAlterarSenha::OnBtnLimpar() 
{
  m_EdtSenhaAtual.SetWindowText("");
  m_EdtNovaSenha.SetWindowText("");
  m_EdtConfirmaSenha.SetWindowText("");
  m_EdtSenhaAtual.SetFocus();
}

BOOL CFrmAlterarSenha::ValidaDados()
{
if (Rotinas->retTexto(&m_EdtSenhaAtual).Compare(Rotinas_sUsuarioSenha)!=0) {
   AfxMessageBox(Rotinas->lerStr(STR_SENNCSU), MB_ICONERROR | MB_OK, 0);
   return FALSE;
}
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtNovaSenha),
  		Rotinas->lerStr(STR_NSENNINF))) {
  	return FALSE;
}
if (Rotinas->retTexto(&m_EdtNovaSenha).Compare(
            Rotinas->retTexto(&m_EdtConfirmaSenha))!=0) {
 AfxMessageBox(Rotinas->lerStr(STR_NSENNCCON), MB_ICONERROR | MB_OK, 0);   
 return FALSE;
} 
return TRUE;
}

