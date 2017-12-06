#if !defined(AFX_SPLASH_H__1B558408_99AF_4EBE_92C5_57066919116C__INCLUDED_)
#define AFX_SPLASH_H__1B558408_99AF_4EBE_92C5_57066919116C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Splash.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFrmSplash dialog

class CFrmSplash : public CDialog
{
// Construction
public:
	CFrmSplash(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrmSplash)
	enum { IDD = FRMSPLASH };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmSplash)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
  UINT idTimer;
	// Generated message map functions
	//{{AFX_MSG(CFrmSplash)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLASH_H__1B558408_99AF_4EBE_92C5_57066919116C__INCLUDED_)
