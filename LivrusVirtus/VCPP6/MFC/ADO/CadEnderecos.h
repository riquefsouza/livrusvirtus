#if !defined(AFX_CADENDERECOS_H__DF4BF013_C467_488D_9117_94AB69662B2C__INCLUDED_)
#define AFX_CADENDERECOS_H__DF4BF013_C467_488D_9117_94AB69662B2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CadEnderecos.h : header file
//
#include "RotinasGlobais.h"
#include "Cadastros.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmCadEnderecos dialog

class CFrmCadEnderecos : public CFrmCadastros
{
// Construction
public:
	CFrmCadEnderecos(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrmCadEnderecos)
	enum { IDD = FRMCADENDERECOS };
	CEdit	m_EdtCidade;
	CEdit	m_EdtCEP;
	CEdit	m_EdtBairro;
	CComboBox	m_CmbEstado;
	CButton	m_BtnSalvar;
	CButton	m_BtnProximo;
	CButton	m_BtnPesquisar;
	CButton	m_BtnNovo;
	CButton	m_BtnLimpar;
	CButton	m_BtnFechar;
	CButton	m_BtnExcluir;
	CButton	m_BtnAnterior;
	CEdit	m_EdtLogradouro;
	CEdit	m_EdtCodigo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmCadEnderecos)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
  BOOL ValidaDados(BOOL bTodosDados);
  void InformaLimpaDados(LISTAMSTR *lstRegistros, 
    UINT nLinhaRegistro, BOOL bInformar);
  void HabilitaDados(BOOL bHabilita);
  void AdicionaCombo();

	// Generated message map functions
	//{{AFX_MSG(CFrmCadEnderecos)
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

#endif // !defined(AFX_CADENDERECOS_H__DF4BF013_C467_488D_9117_94AB69662B2C__INCLUDED_)
