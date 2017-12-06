#if !defined(AFX_CADASTROS_H__AA224606_62B2_4035_BA44_0E39DDF0A28A__INCLUDED_)
#define AFX_CADASTROS_H__AA224606_62B2_4035_BA44_0E39DDF0A28A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Cadastros.h : header file
//
#include "RotinasGlobais.h"

/////////////////////////////////////////////////////////////////////////////
// CFrmCadastros window

class CFrmCadastros : public CDialog
{
// Construction
public:
	CFrmCadastros();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrmCadastros)
	//}}AFX_VIRTUAL

// Implementation
public:

	// Generated message map functions
protected:
  LISTAMSTR lstRegistros;
  UINT nRegistros;

  VOID Fechar(INT nPosMenu, INT idSubMenu);  
  VOID Ativar(INT nPosMenu, INT idSubMenu);
  VOID InformaLimpaDados(LISTAMSTR *lstRegistros, 
    UINT nLinhaRegistro, CEdit *idEdtCodigo, CEdit *idEdtDesc, BOOL bInformar);
  VOID HabilitaDados(CEdit *idEdtDesc, BOOL bHabilita);
  VOID btnNovoClick(CEdit *idEdtCodigo, CEdit *idEdtDesc, 
    CButton *idBtnNovo, CButton *idBtnPesquisar, CButton *idBtnAnterior,  
    CButton *idBtnProximo, CButton *idBtnSalvar, CButton *idBtnExcluir);
  VOID NovoDado(CEdit *idEdtCodigo, CEdit *idEdtDesc, 
    CString sTextoSql);
  VOID btnLimparClick(CEdit *idEdtCodigo, CEdit *idEdtDesc, 
    CButton *idBtnNovo, CButton *idBtnPesquisar, CButton *idBtnAnterior,  
    CButton *idBtnProximo, CButton *idBtnSalvar, CButton *idBtnExcluir);
  BOOL ExcluirDados(CEdit *idEdtCodigo, CEdit *idEdtDesc, 
    CButton *idBtnNovo, CButton *idBtnPesquisar, CButton *idBtnAnterior,  
    CButton *idBtnProximo, CButton *idBtnSalvar, CButton *idBtnExcluir,  
    BOOL bValidaDados, CString sTextoSql);
  BOOL PesquisarDados(LISTAMSTR *lstRegistros, 
    CEdit *idEdtCodigo, CEdit *idEdtDesc, 
    CButton *idBtnPesquisar, CButton *idBtnAnterior,  
    CButton *idBtnProximo, CButton *idBtnSalvar, CButton *idBtnExcluir,
    CString sTextoSql, CString sMensagemErro);
  BOOL registroAnterior(LISTAMSTR *lstRegistros, 
    CEdit *idEdtCodigo, CEdit *idEdtDesc, UINT *nLinhaRegistro);
  BOOL registroProximo(LISTAMSTR *lstRegistros, 
    CEdit *idEdtCodigo, CEdit *idEdtDesc, UINT *nLinhaRegistro);
  BOOL CFrmCadastros::SalvarDados(CEdit *idEdtCodigo, CEdit *idEdtDesc, 
    CButton *idBtnNovo, CButton *idBtnPesquisar, CButton *idBtnAnterior,  
    CButton *idBtnProximo, CButton *idBtnSalvar, CButton *idBtnExcluir,  
    BOOL bValidaDados, CString sTextoSql, CString sTextoUpdate,
	  CString sTextoInsert, BOOL bLimparDados);

	//{{AFX_MSG(CFrmCadastros)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CADASTROS_H__AA224606_62B2_4035_BA44_0E39DDF0A28A__INCLUDED_)
