#if !defined(AFX_CADLIVROS_H__CF810261_91F4_4A87_AFC2_58180D526FCF__INCLUDED_)
#define AFX_CADLIVROS_H__CF810261_91F4_4A87_AFC2_58180D526FCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CadLivros.h : header file
//
#include "RotinasGlobais.h"
#include "Cadastros.h"
/////////////////////////////////////////////////////////////////////////////
// CFrmCadLivros dialog

class CFrmCadLivros : public CFrmCadastros
{
// Construction
public:
	CFrmCadLivros(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFrmCadLivros)
	enum { IDD = FRMCADLIVROS };
	CSpinButtonCtrl	m_SpinVolume;
	CSpinButtonCtrl	m_SpinQtdEstoque;
	CSpinButtonCtrl	m_SpinNPaginas;
	CSpinButtonCtrl	m_SpinEdicao;
	CSpinButtonCtrl	m_SpinAnoPubli;
	CListBox	m_LstAutores;
	CListBox	m_LstAssuntos;
	CEdit	m_EdtVolume;
	CEdit	m_EdtQtdEstoque;
	CEdit	m_EdtPreco;
	CEdit	m_EdtNPaginas;
	CEdit	m_EdtEditora;
	CEdit	m_EdtEdicao;
	CEdit	m_EdtCodEditora;
	CEdit	m_EdtCodAutor;
	CEdit	m_EdtCodAssunto;
	CEdit	m_EdtAutor;
	CEdit	m_EdtAssunto;
	CEdit	m_EdtAnoPubli;
	CComboBox	m_CmbIdioma;
	CButton	m_BtnPEditora;
	CButton	m_BtnPAutor;
	CButton	m_BtnPAssunto;
	CButton	m_BtnAdAutores;
	CButton	m_BtnAdAssuntos;
	CButton	m_BtnSalvar;
	CButton	m_BtnProximo;
	CButton	m_BtnPesquisar;
	CButton	m_BtnNovo;
	CButton	m_BtnLimpar;
	CButton	m_BtnFechar;
	CButton	m_BtnExcluir;
	CButton	m_BtnAnterior;
	CEdit	m_EdtTitulo;
	CEdit	m_EdtISBN;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmCadLivros)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
  LISTASTR slAssuntos, slAutores, slIdiomas;
  BOOL ValidaDados(BOOL bTodosDados);
  void InformaLimpaDados(LISTAMSTR *lstRegistros, 
    UINT nLinhaRegistro, BOOL bInformar);
  void HabilitaDados(BOOL bHabilita);
  void AdicionaCombo();
  void SalvaLista(TCHAR sOpcao);

	// Generated message map functions
	//{{AFX_MSG(CFrmCadLivros)
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
	afx_msg void OnEdtISBN_Killfocus();
	afx_msg void OnEdtCodEditora_Killfocus();
	afx_msg void OnBtnPEditora();
	afx_msg void OnEdtPreco_Killfocus();
	afx_msg void OnEdtCodAssunto_Killfocus();
	afx_msg void OnBtnPAssunto();
	afx_msg void OnEdtCodAutor_Killfocus();
	afx_msg void OnBtnPAutor();
	afx_msg void OnBtnAdAssuntos();
	afx_msg void OnLstAssuntos_Dblclk();
	afx_msg void OnBtnAdAutores();
	afx_msg void OnLstAutores_Dblclk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CADLIVROS_H__CF810261_91F4_4A87_AFC2_58180D526FCF__INCLUDED_)
