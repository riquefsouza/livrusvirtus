#if !defined(AFX_CADPAISES_H__7E5E1B89_5A0F_4B31_BD2C_E61A6EF8B50D__INCLUDED_)
#define AFX_CADPAISES_H__7E5E1B89_5A0F_4B31_BD2C_E61A6EF8B50D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CadPaises.h : header file
//
#include "Cadastros.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmCadPaises dialog

class CFrmCadPaises : public CFrmCadastros
{
// Construction
public:
	CFrmCadPaises(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrmCadPaises)
	enum { IDD = FRMCADPAISES };
	CButton	m_BtnSalvar;
	CButton	m_BtnProximo;
	CButton	m_BtnPesquisar;
	CButton	m_BtnNovo;
	CButton	m_BtnLimpar;
	CButton	m_BtnFechar;
	CButton	m_BtnExcluir;
	CButton	m_BtnAnterior;
	CEdit	m_EdtDescricao;
	CEdit	m_EdtCodigo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmCadPaises)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
  BOOL ValidaDados(BOOL bTodosDados);

	// Generated message map functions
	//{{AFX_MSG(CFrmCadPaises)
	afx_msg void OnBtnFechar();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnNovo();
	afx_msg void OnBtnPesquisar();
	afx_msg void OnBtnAnterior();
	afx_msg void OnBtnProximo();
	afx_msg void OnBtnSalvar();
	afx_msg void OnBtnExcluir();
	afx_msg void OnBtnLimpar();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CADPAISES_H__7E5E1B89_5A0F_4B31_BD2C_E61A6EF8B50D__INCLUDED_)
