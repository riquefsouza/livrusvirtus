#if !defined(AFX_CADCLIENTES_H__EB50CEAE_D4DA_4915_909F_C459E2CE9DC6__INCLUDED_)
#define AFX_CADCLIENTES_H__EB50CEAE_D4DA_4915_909F_C459E2CE9DC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CadClientes.h : header file
//
#include "RotinasGlobais.h"
#include "Cadastros.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmCadClientes dialog

class CFrmCadClientes : public CFrmCadastros
{
// Construction
public:
	CFrmCadClientes(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrmCadClientes)
	enum { IDD = FRMCADCLIENTES };
	CButton	m_RbMasculino;
	CButton	m_RbFeminino;
	CDateTimeCtrl	m_EdtDtNasc;
	CButton	m_BtnPEndereco;
	CButton	m_BtnPProfissao;
	CButton	m_BtnPPais;
	CEdit	m_EdtTelefone;
	CEdit	m_EdtProfissao;
	CEdit	m_EdtPais;
	CEdit	m_EdtLogradouro;
	CEdit	m_EdtIdentidade;
	CEdit	m_EdtEstado;
	CEdit	m_EdtEmail;
	CEdit	m_EdtCidade;
	CEdit	m_EdtCodEndereco;
	CEdit	m_EdtCodPais;
	CEdit	m_EdtCodProfissao;
	CEdit	m_EdtCep;
	CEdit	m_EdtBairro;
	CButton	m_BtnSalvar;
	CButton	m_BtnProximo;
	CButton	m_BtnPesquisar;
	CButton	m_BtnNovo;
	CButton	m_BtnLimpar;
	CButton	m_BtnFechar;
	CButton	m_BtnExcluir;
	CButton	m_BtnAnterior;
	CEdit	m_EdtNome;
	CEdit	m_EdtCPF;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmCadClientes)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
  BOOL ValidaDados(BOOL bTodosDados);
  void InformaLimpaDados(LISTAMSTR *lstRegistros, 
    UINT nLinhaRegistro, BOOL bInformar);
  void HabilitaDados(BOOL bHabilita);

	// Generated message map functions
	//{{AFX_MSG(CFrmCadClientes)
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
	afx_msg void OnEdtCpf_Killfocus();
	afx_msg void OnEdtCodEndereco_Killfocus();
	afx_msg void OnEdtCodPais_Killfocus();
	afx_msg void OnEdtCodProfissao_Killfocus();
	afx_msg void OnBtnPEndereco();
	afx_msg void OnBtnPPais();
	afx_msg void OnBtnPProfissao();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CADCLIENTES_H__EB50CEAE_D4DA_4915_909F_C459E2CE9DC6__INCLUDED_)
