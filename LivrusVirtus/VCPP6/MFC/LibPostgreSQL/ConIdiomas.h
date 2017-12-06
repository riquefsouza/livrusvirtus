#if !defined(AFX_CONIDIOMAS_H__AFA4118F_E838_40A1_865A_28ECC4CE4C25__INCLUDED_)
#define AFX_CONIDIOMAS_H__AFA4118F_E838_40A1_865A_28ECC4CE4C25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConIdiomas.h : header file
//
#include "Consultas.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmConIdiomas dialog

class CFrmConIdiomas : public CFrmConsultas
{
// Construction
public:
	CFrmConIdiomas(CWnd* pParent = NULL);   // standard constructor
	BOOL Create();

// Dialog Data
	//{{AFX_DATA(CFrmConIdiomas)
	enum { IDD = FRMCONIDIOMAS };
	CListCtrl	m_ListConsulta;
	CStatic	m_LabRegistros;
	CEdit	m_EdtDescricao;
	CButton	m_BtnLimpar;
	CButton	m_BtnFechar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmConIdiomas)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFrmConIdiomas)
	afx_msg void OnBtnFechar();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBtnLimpar();
	afx_msg void OnBtnPesquisar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONIDIOMAS_H__AFA4118F_E838_40A1_865A_28ECC4CE4C25__INCLUDED_)
