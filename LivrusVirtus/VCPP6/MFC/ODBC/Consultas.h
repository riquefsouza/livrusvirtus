#if !defined(AFX_CONSULTAS_H__FA9CD2AE_A0DA_4D44_A1DA_BC756894A53B__INCLUDED_)
#define AFX_CONSULTAS_H__FA9CD2AE_A0DA_4D44_A1DA_BC756894A53B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Consultas.h : header file
//

#include "RotinasGlobais.h"

/////////////////////////////////////////////////////////////////////////////
// CFrmConsultas window

class CFrmConsultas : public CDialog
{
// Construction
public:
  CFrmConsultas(UINT nIDTemplate, CWnd* pParent = NULL);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmConsultas)
	//}}AFX_VIRTUAL

// Implementation
public:
	//virtual ~CFrmConsultas();

	// Generated message map functions
protected:
	CWnd* m_pParent;
	int m_nID;
  LISTAMSTR lstLinhas;
  CString sSelecionados;
  BOOL bModal;

  VOID Ativar(INT idSubMenu);
  VOID Fecha(CString sSelecionado, INT idSubMenu);
  VOID setLabRegistros(CStatic *idLabRegs, 
    LISTAMSTR *sLinhas, INT nReg);
  VOID arrumaTamanho(CListCtrl *idListaCons, 
    CStatic *idLabRegs, CButton *idBtnLimpar, CButton *idBtnFechar);
  BOOL Notifica(LPARAM lParam, 
    CListCtrl *idListaCons, CStatic *idLabRegs, LISTAMSTR *sLinhas, 
    CString *sSelecionado);
  VOID LimparDados(CStatic *idLabRegs, 
    CEdit *idEdtDesc, CListCtrl *idListaCons, LISTAMSTR *sLinhas);
  VOID PesquisarDados(CListCtrl *idListaCons, 
    CStatic *idLabRegs, LISTAMSTR *sLinhas, CString sTextoSql, 
    CString sMensagemErro);

  //{{AFX_MSG(CFrmConsultas)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONSULTAS_H__FA9CD2AE_A0DA_4D44_A1DA_BC756894A53B__INCLUDED_)
