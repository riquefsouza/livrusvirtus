// Principal.h : interface of the CFrmPrincipal class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRINCIPAL_H__636A5377_C3D4_4639_B778_9899ABFFC279__INCLUDED_)
#define AFX_PRINCIPAL_H__636A5377_C3D4_4639_B778_9899ABFFC279__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ConAssuntos.h"
#include "ConAutores.h"
#include "ConEditoras.h"
#include "ConEnderecos.h"
#include "ConIdiomas.h"
#include "ConPaises.h"
#include "ConProfissoes.h"
#include "ConClientes.h"
#include "ConLivros.h"

class CFrmPrincipal : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CFrmPrincipal)
public:
	CFrmPrincipal();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmPrincipal)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFrmPrincipal();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:  // control bar embedded members
	CStatusBar  m_hBarraStatus;
	CToolBar    m_hBarraFerram;
  CFrmConAssuntos* frmConAssuntos;
  CFrmConAutores* frmConAutores;
  CFrmConEditoras* frmConEditoras;
  CFrmConEnderecos* frmConEnderecos;
  CFrmConIdiomas* frmConIdiomas;
  CFrmConPaises* frmConPaises;
  CFrmConProfissoes* frmConProfissoes;
  CFrmConClientes* frmConClientes;
  CFrmConLivros* frmConLivros;

// Generated message map functions
protected:
	//{{AFX_MSG(CFrmPrincipal)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnCadAssuntos();
	afx_msg void OnCadAutores();
	afx_msg void OnOpSobre();
	afx_msg void OnOpSair();
	afx_msg void OnClose();
	afx_msg void OnConAssuntos();
	afx_msg void OnOpAlterarsenha();
	afx_msg void OnCadEditoras();
	afx_msg void OnCadEnderecos();
	afx_msg void OnCadIdiomas();
	afx_msg void OnCadPaises();
	afx_msg void OnCadProfissoes();
	afx_msg void OnCadClientes();
	afx_msg void OnConAutores();
	afx_msg void OnConClientes();
	afx_msg void OnConEditoras();
	afx_msg void OnConEnderecos();
	afx_msg void OnConIdiomas();
	afx_msg void OnConLivros();
	afx_msg void OnConPaises();
	afx_msg void OnConProfissoes();
	afx_msg void OnCadLivros();
	afx_msg void OnVenVenderlivros();
	afx_msg void OnVenVendasRealizadas();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//extern CFrmPrincipal frmPrincipal;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINCIPAL_H__636A5377_C3D4_4639_B778_9899ABFFC279__INCLUDED_)
