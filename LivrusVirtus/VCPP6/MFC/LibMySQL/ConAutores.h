#if !defined(AFX_CONAUTORES_H__16C5813A_358D_48F1_90E5_E5A09BCC82CD__INCLUDED_)
#define AFX_CONAUTORES_H__16C5813A_358D_48F1_90E5_E5A09BCC82CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConAutores.h : header file
//
#include "Consultas.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmConAutores dialog

class CFrmConAutores : public CFrmConsultas
{
// Construction
public:
	CFrmConAutores(CWnd* pParent = NULL);   // standard constructor
  BOOL Create();

// Dialog Data
	//{{AFX_DATA(CFrmConAutores)
	enum { IDD = FRMCONAUTORES };
	CListCtrl	m_ListConsulta;
	CStatic	m_LabRegistros;
	CEdit	m_EdtDescricao;
	CButton	m_BtnLimpar;
	CButton	m_BtnFechar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmConAutores)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFrmConAutores)
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

#endif // !defined(AFX_CONAUTORES_H__16C5813A_358D_48F1_90E5_E5A09BCC82CD__INCLUDED_)
