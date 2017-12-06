// Login.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "Principal.h"
#include "Login.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmLogin dialog


CFrmLogin::CFrmLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CFrmLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmLogin)
	//}}AFX_DATA_INIT
}


void CFrmLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmLogin)
	DDX_Control(pDX, ID_FRMLOGIN_EDTSENHA, m_edtSenha);
	DDX_Control(pDX, ID_FRMLOGIN_EDTLOGIN, m_edtLogin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmLogin, CDialog)
	//{{AFX_MSG_MAP(CFrmLogin)
	ON_BN_CLICKED(ID_FRMLOGIN_BTNLOGIN, OnBtnlogin)
	ON_BN_CLICKED(ID_FRMLOGIN_BTNCANCELAR, OnBtnCancelar)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmLogin message handlers

void CFrmLogin::OnBtnlogin() 
{
  CString sTemp;
  
  Rotinas_sUsuarioLogin = Rotinas->retTexto(&m_edtLogin);
  Rotinas_sUsuarioSenha = Rotinas->retTexto(&m_edtSenha);

  if (Rotinas->ConsultaDados(gConexao, 
     ConsSQL->Usuario('S',Rotinas_sUsuarioLogin, Rotinas_sUsuarioSenha)) ) {
                
     Rotinas_sBarraLogin = 
       Rotinas->lerStr(STR_USUARIO) + Rotinas_sUsuarioLogin;
     EndDialog(TRUE);
  } else
     AfxMessageBox(Rotinas->lerStr(STR_LOGSENINC), MB_ICONERROR | MB_OK, 0);

}

void CFrmLogin::OnBtnCancelar() 
{
	SendMessage(WM_CLOSE, 0, 0);
}

void CFrmLogin::OnClose() 
{
  Rotinas->DisconectaBanco();
  EndDialog(FALSE);
}

BOOL CFrmLogin::OnInitDialog() 
{
	CDialog::OnInitDialog();

  SetClassLong(m_hWnd, GCL_HICON, (LONG) 
    LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(ID_FRMPRINCIPAL)));   
	
	return TRUE;
}
