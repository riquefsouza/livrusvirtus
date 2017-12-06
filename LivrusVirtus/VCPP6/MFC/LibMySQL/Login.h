#if !defined(AFX_LOGIN_H__6C10DF47_520D_4D9F_AFDF_981446057BCC__INCLUDED_)
#define AFX_LOGIN_H__6C10DF47_520D_4D9F_AFDF_981446057BCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFrmLogin dialog

class CFrmLogin : public CDialog
{
// Construction
public:
	CFrmLogin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrmLogin)
	enum { IDD = FRMLOGIN };
	CEdit	m_edtSenha;
	CEdit	m_edtLogin;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmLogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFrmLogin)
	afx_msg void OnBtnlogin();
	afx_msg void OnBtnCancelar();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__6C10DF47_520D_4D9F_AFDF_981446057BCC__INCLUDED_)
