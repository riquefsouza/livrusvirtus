#if !defined(AFX_ALTERARSENHA_H__A797529D_6705_4580_86D9_9988BDDB96A5__INCLUDED_)
#define AFX_ALTERARSENHA_H__A797529D_6705_4580_86D9_9988BDDB96A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AlterarSenha.h : header file
//
#include "Cadastros.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmAlterarSenha dialog

class CFrmAlterarSenha : public CFrmCadastros
{
// Construction
public:
	CFrmAlterarSenha(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrmAlterarSenha)
	enum { IDD = FRMALTERARSENHA };
	CEdit	m_EdtConfirmaSenha;
	CEdit	m_EdtSenhaAtual;
	CEdit	m_EdtNovaSenha;
	CEdit	m_EdtLogin;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmAlterarSenha)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
  BOOL ValidaDados();

	// Generated message map functions
	//{{AFX_MSG(CFrmAlterarSenha)
	afx_msg void OnClose();
	afx_msg void OnBtnFechar();
	afx_msg void OnBtnSalvar();
	afx_msg void OnBtnLimpar();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALTERARSENHA_H__A797529D_6705_4580_86D9_9988BDDB96A5__INCLUDED_)
