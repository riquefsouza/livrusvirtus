#if !defined(AFX_VENDERLIVROS_H__F7834B12_735C_4C95_BC15_A13D03C07177__INCLUDED_)
#define AFX_VENDERLIVROS_H__F7834B12_735C_4C95_BC15_A13D03C07177__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VenderLivros.h : header file
//
#include "Cadastros.h"
#include "RotinasGlobais.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmVenderLivros dialog

class CFrmVenderLivros : public CFrmCadastros
{
// Construction
public:
	CFrmVenderLivros(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrmVenderLivros)
	enum { IDD = FRMVENDERLIVROS };
	CListBox	m_LstLivros;
	CEdit	m_EdtPrecoTotal;
	CEdit	m_EdtLivro;
	CEdit	m_EdtISBN;
	CEdit	m_EdtDtHrVenda;
	CEdit	m_EdtCPF;
	CEdit	m_EdtCliente;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmVenderLivros)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
  LISTASTR slPrecos, slISBNs, slQtdEstoque;
  FLOAT nPrecoTotal;
  void LimpaDados();
  BOOL ValidaDados();
  BOOL SalvaLista();

	// Generated message map functions
	//{{AFX_MSG(CFrmVenderLivros)
	afx_msg void OnBtnFechar();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnEdtCPF_Killfocus();
	afx_msg void OnBtnPCliente();
	afx_msg void OnEdtISBN_Killfocus();
	afx_msg void OnBtnPLivro();
	afx_msg void OnBtnAdLivros();
	afx_msg void OnLstLivros_Dblclk();
	afx_msg void OnBtnVender();
	afx_msg void OnBtnLimpar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VENDERLIVROS_H__F7834B12_735C_4C95_BC15_A13D03C07177__INCLUDED_)
