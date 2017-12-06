// Splash.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmSplash dialog


CFrmSplash::CFrmSplash(CWnd* pParent /*=NULL*/)
	: CDialog(CFrmSplash::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmSplash)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  idTimer = 1;
}


void CFrmSplash::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmSplash)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmSplash, CDialog)
	//{{AFX_MSG_MAP(CFrmSplash)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmSplash message handlers

BOOL CFrmSplash::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetTimer(idTimer, 3000, (TIMERPROC) NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFrmSplash::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnTimer(nIDEvent);
  EndDialog(true);
}
