#if !defined(AFX_CONVENDAS_H__B2758EC6_9EDC_4034_82A6_8D15854744FC__INCLUDED_)
#define AFX_CONVENDAS_H__B2758EC6_9EDC_4034_82A6_8D15854744FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConVendas.h : header file
//
#include "Cadastros.h"
#include "Consultas.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmConVendas dialog

class CFrmConVendas : public CFrmConsultas
{
// Construction
public:
	CFrmConVendas(CWnd* pParent = NULL);   // standard constructor  
  VOID arrumaTamanho(RECT rForm);

// Dialog Data
	//{{AFX_DATA(CFrmConVendas)
	enum { IDD = FRMCONVENDAS };
	CButton	m_BtnLimpar;
	CButton	m_BtnFechar;
	CStatic	m_LabPrecoTotal;
	CStatic	m_LabRegistros;
	CListCtrl	m_ListVendas;
	CEdit	m_EdtPrecoTotal;
	CEdit	m_EdtLivro;
	CEdit	m_EdtCliente;
	CEdit	m_EdtISBN;
	CDateTimeCtrl	m_EdtHrVenda;
	CDateTimeCtrl	m_EdtDtVenda;
	CEdit	m_EdtCPF;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmConVendas)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
  CString ConsVenda(TCHAR sOpcao);

	// Generated message map functions
	//{{AFX_MSG(CFrmConVendas)
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBtnFechar();
	afx_msg void OnBtnLimpar();
	afx_msg void OnBtnPesquisar();
	afx_msg void OnEdtCPF_Killfocus();
	afx_msg void OnBtnPCliente();
	afx_msg void OnEdtISBN_Killfocus();
	afx_msg void OnBtnPLivro();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVENDAS_H__B2758EC6_9EDC_4034_82A6_8D15854744FC__INCLUDED_)
