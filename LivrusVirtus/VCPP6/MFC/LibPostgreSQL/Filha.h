// Filha.h : interface of the CFrmFilha class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILHA_H__7D9E6DC7_F8CC_475E_8F14_99079EBF9A3F__INCLUDED_)
#define AFX_FILHA_H__7D9E6DC7_F8CC_475E_8F14_99079EBF9A3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CadAssuntos.h"
#include "CadAutores.h"
#include "CadEditoras.h"
#include "CadEnderecos.h"
#include "CadIdiomas.h"
#include "CadPaises.h"
#include "CadProfissoes.h"
#include "CadClientes.h"
#include "CadLivros.h"
#include "VenderLivros.h"
#include "ConVendas.h"
#include "AlterarSenha.h"

extern UINT nTelaAtiva;
extern BOOL bTelaAtiva[12];

class CFrmFilha : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CFrmFilha)
public:
	CFrmFilha();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmFilha)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	// view for the client area of the frame.
  virtual ~CFrmFilha();
  UINT nLocalTelaAtiva;
	CFrmCadAssuntos m_frmCadAssuntos;
  CFrmCadAutores m_frmCadAutores;
  CFrmCadEditoras m_frmCadEditoras;
  CFrmCadEnderecos m_frmCadEnderecos;
  CFrmCadIdiomas m_frmCadIdiomas;
  CFrmCadPaises m_frmCadPaises;
  CFrmCadProfissoes m_frmCadProfissoes;
  CFrmCadClientes m_frmCadClientes;
  CFrmCadLivros m_frmCadLivros;
  CFrmVenderLivros m_frmVenderLivros;
  CFrmConVendas m_frmConVendas;
  CFrmAlterarSenha m_frmAlterarSenha;
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(CFrmFilha)
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILHA_H__7D9E6DC7_F8CC_475E_8F14_99079EBF9A3F__INCLUDED_)
