// Sobre.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "Sobre.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmSobre dialog


CFrmSobre::CFrmSobre(CWnd* pParent /*=NULL*/)
	: CDialog(CFrmSobre::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmSobre)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrmSobre::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmSobre)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmSobre, CDialog)
	//{{AFX_MSG_MAP(CFrmSobre)
	ON_BN_CLICKED(ID_FRMSOBRE_BTNOK, OnBtnOk)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmSobre message handlers

void CFrmSobre::OnBtnOk() 
{
	// TODO: Add your control notification handler code here
  EndDialog(true);	
}

void CFrmSobre::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}
