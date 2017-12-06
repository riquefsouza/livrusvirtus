#if !defined(AFX_CONPROFISSOES_H__22BB58B0_AEDD_4DCF_8902_2958B7EF2E9A__INCLUDED_)
#define AFX_CONPROFISSOES_H__22BB58B0_AEDD_4DCF_8902_2958B7EF2E9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConProfissoes.h : header file
//
#include "Consultas.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmConProfissoes dialog

class CFrmConProfissoes : public CFrmConsultas
{
// Construction
public:
	CFrmConProfissoes(CWnd* pParent = NULL);   // standard constructor
	BOOL Create();

// Dialog Data
	//{{AFX_DATA(CFrmConProfissoes)
	enum { IDD = FRMCONPROFISSOES };
	CListCtrl	m_ListConsulta;
	CStatic	m_LabRegistros;
	CEdit	m_EdtDescricao;
	CButton	m_BtnLimpar;
	CButton	m_BtnFechar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmConProfissoes)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFrmConProfissoes)
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

#endif // !defined(AFX_CONPROFISSOES_H__22BB58B0_AEDD_4DCF_8902_2958B7EF2E9A__INCLUDED_)
