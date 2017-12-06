#if !defined(AFX_CONEDITORAS_H__71CC5EB6_66D9_44DE_90A2_676BFFEC8438__INCLUDED_)
#define AFX_CONEDITORAS_H__71CC5EB6_66D9_44DE_90A2_676BFFEC8438__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConEditoras.h : header file
//
#include "Consultas.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmConEditoras dialog

class CFrmConEditoras : public CFrmConsultas
{
// Construction
public:
	CFrmConEditoras(CWnd* pParent = NULL);   // standard constructor
	BOOL Create();

// Dialog Data
	//{{AFX_DATA(CFrmConEditoras)
	enum { IDD = FRMCONEDITORAS };
	CListCtrl	m_ListConsulta;
	CStatic	m_LabRegistros;
	CEdit	m_EdtDescricao;
	CButton	m_BtnLimpar;
	CButton	m_BtnFechar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmConEditoras)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFrmConEditoras)
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

#endif // !defined(AFX_CONEDITORAS_H__71CC5EB6_66D9_44DE_90A2_676BFFEC8438__INCLUDED_)
