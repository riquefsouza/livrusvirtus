#if !defined(AFX_CADPROFISSOES_H__C9A6CB70_085B_4B88_82E9_DBE426574AAF__INCLUDED_)
#define AFX_CADPROFISSOES_H__C9A6CB70_085B_4B88_82E9_DBE426574AAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CadProfissoes.h : header file
//
#include "Cadastros.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmCadProfissoes dialog

class CFrmCadProfissoes : public CFrmCadastros
{
// Construction
public:
	CFrmCadProfissoes(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrmCadProfissoes)
	enum { IDD = FRMCADPROFISSOES };
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
	//{{AFX_VIRTUAL(CFrmCadProfissoes)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
  BOOL ValidaDados(BOOL bTodosDados);

	// Generated message map functions
	//{{AFX_MSG(CFrmCadProfissoes)
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

#endif // !defined(AFX_CADPROFISSOES_H__C9A6CB70_085B_4B88_82E9_DBE426574AAF__INCLUDED_)
