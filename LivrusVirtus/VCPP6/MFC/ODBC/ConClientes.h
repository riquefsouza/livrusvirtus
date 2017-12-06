#if !defined(AFX_CONCLIENTES_H__EAF73B5A_57BF_4E2A_A705_8866A5BECA6E__INCLUDED_)
#define AFX_CONCLIENTES_H__EAF73B5A_57BF_4E2A_A705_8866A5BECA6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConClientes.h : header file
//
#include "Consultas.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmConClientes dialog

class CFrmConClientes : public CFrmConsultas
{
// Construction
public:
	CFrmConClientes(CWnd* pParent = NULL);   // standard constructor
	BOOL Create();

// Dialog Data
	//{{AFX_DATA(CFrmConClientes)
	enum { IDD = FRMCONCLIENTES };
	CListCtrl	m_ListConsulta;
	CStatic	m_LabRegistros;
	CEdit	m_EdtDescricao;
	CButton	m_BtnLimpar;
	CButton	m_BtnFechar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmConClientes)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFrmConClientes)
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

#endif // !defined(AFX_CONCLIENTES_H__EAF73B5A_57BF_4E2A_A705_8866A5BECA6E__INCLUDED_)
