#if !defined(AFX_SOBRE_H__79B3617A_9A74_4FEC_A9B8_BEBCEA756C3E__INCLUDED_)
#define AFX_SOBRE_H__79B3617A_9A74_4FEC_A9B8_BEBCEA756C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Sobre.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFrmSobre dialog

class CFrmSobre : public CDialog
{
// Construction
public:
	CFrmSobre(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrmSobre)
	enum { IDD = FRMSOBRE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmSobre)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFrmSobre)
	afx_msg void OnBtnOk();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOBRE_H__79B3617A_9A74_4FEC_A9B8_BEBCEA756C3E__INCLUDED_)
