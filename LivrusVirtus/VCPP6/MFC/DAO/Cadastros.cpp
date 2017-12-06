// Cadastros.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "Cadastros.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmCadastros

CFrmCadastros::CFrmCadastros()
{
}

BEGIN_MESSAGE_MAP(CFrmCadastros, CDialog)
	//{{AFX_MSG_MAP(CFrmCadastros)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CFrmCadastros message handlers

VOID CFrmCadastros::Fechar(INT nPosMenu, INT idSubMenu)
{  
  Rotinas->habilitaSubMenu(nPosMenu, idSubMenu, TRUE);
  GetParent()->DestroyWindow();
}

VOID CFrmCadastros::Ativar(INT nPosMenu, INT idSubMenu)
{
  Rotinas->habilitaSubMenu(nPosMenu, idSubMenu, FALSE);
}

VOID CFrmCadastros::InformaLimpaDados(LISTAMSTR *lstRegistros, 
  UINT nLinhaRegistro, CEdit *idEdtCodigo, CEdit *idEdtDesc, BOOL bInformar)
{
  POSITION pos;
  if (bInformar) {
    pos = lstRegistros->col[0].FindIndex(nLinhaRegistro);
    idEdtCodigo->SetWindowText(lstRegistros->col[0].GetAt(pos));
    pos = lstRegistros->col[1].FindIndex(nLinhaRegistro);
    idEdtDesc->SetWindowText(lstRegistros->col[1].GetAt(pos));
  } else {
    idEdtCodigo->SetWindowText("");
    idEdtDesc->SetWindowText("");
    idEdtCodigo->EnableWindow(TRUE);
    idEdtCodigo->SetFocus();
  }
} 

VOID CFrmCadastros::HabilitaDados(CEdit *idEdtDesc, BOOL bHabilita)
{
  idEdtDesc->EnableWindow(bHabilita);
}

VOID CFrmCadastros::btnNovoClick(CEdit *idEdtCodigo, CEdit *idEdtDesc, 
  CButton *idBtnNovo, CButton *idBtnPesquisar, CButton *idBtnAnterior,  
  CButton *idBtnProximo, CButton *idBtnSalvar, CButton *idBtnExcluir) 
{ 
  idBtnSalvar->EnableWindow(TRUE);
  idBtnExcluir->EnableWindow(FALSE);
  idBtnPesquisar->EnableWindow(FALSE);
  idBtnAnterior->EnableWindow(FALSE);
  idBtnProximo->EnableWindow(FALSE);
  idBtnNovo->EnableWindow(FALSE);

  InformaLimpaDados(NULL, 0, idEdtCodigo, idEdtDesc, FALSE);
  HabilitaDados(idEdtDesc, TRUE);	
}

VOID CFrmCadastros::NovoDado(CEdit *idEdtCodigo, CEdit *idEdtDesc, 
  CString sTextoSql)
{ POSITION pos;
  LISTAMSTR lstRegistros;

  if (Rotinas->ConsultaDadosLista(gConexao, &lstRegistros, sTextoSql)) {
    pos = lstRegistros.col[0].FindIndex(0);
    idEdtCodigo->SetWindowText(lstRegistros.col[0].GetAt(pos));

    idEdtCodigo->EnableWindow(FALSE);
    idEdtDesc->SetFocus();
  }
}

VOID CFrmCadastros::btnLimparClick(CEdit *idEdtCodigo, CEdit *idEdtDesc, 
  CButton *idBtnNovo, CButton *idBtnPesquisar, CButton *idBtnAnterior,  
  CButton *idBtnProximo, CButton *idBtnSalvar, CButton *idBtnExcluir) 
{
  nRegistros = 0;
  idBtnSalvar->EnableWindow(FALSE);
  idBtnExcluir->EnableWindow(FALSE);
  idBtnPesquisar->EnableWindow(TRUE);
  idBtnAnterior->EnableWindow(FALSE);
  idBtnProximo->EnableWindow(FALSE);
  idBtnNovo->EnableWindow(TRUE);

  InformaLimpaDados(NULL, 0, idEdtCodigo, idEdtDesc, FALSE);
  HabilitaDados(idEdtDesc, FALSE);	
}

BOOL CFrmCadastros::ExcluirDados(CEdit *idEdtCodigo, CEdit *idEdtDesc, 
  CButton *idBtnNovo, CButton *idBtnPesquisar, CButton *idBtnAnterior,  
  CButton *idBtnProximo, CButton *idBtnSalvar, CButton *idBtnExcluir,  
  BOOL bValidaDados, CString sTextoSql)
{
   if (bValidaDados) {

     if (AfxMessageBox(Rotinas->lerStr(STR_CERTEXCL), 
         MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2, 0) == IDYES) { 

        if (Rotinas->AtualizaDados(gConexao, sTextoSql)) {
           btnLimparClick(idEdtCodigo, idEdtDesc, 
             idBtnNovo, idBtnPesquisar, idBtnAnterior, idBtnProximo, 
             idBtnSalvar, idBtnExcluir);
           return TRUE;
        }

  	 }
   }
  return FALSE;
}

BOOL CFrmCadastros::PesquisarDados(LISTAMSTR *lstRegistros, 
  CEdit *idEdtCodigo, CEdit *idEdtDesc, 
  CButton *idBtnPesquisar, CButton *idBtnAnterior,  
  CButton *idBtnProximo, CButton *idBtnSalvar, CButton *idBtnExcluir,
  CString sTextoSql, CString sMensagemErro)
{  
	if (idEdtCodigo->GetWindowTextLength() == 0) {
    idBtnAnterior->EnableWindow(TRUE);
    idBtnProximo->EnableWindow(TRUE);
	}

  if (Rotinas->ConsultaDadosLista(gConexao, lstRegistros, sTextoSql)) {
     InformaLimpaDados(lstRegistros, 0, idEdtCodigo, idEdtDesc, TRUE);
     HabilitaDados(idEdtDesc, TRUE);	

     idBtnSalvar->EnableWindow(TRUE);
     idBtnExcluir->EnableWindow(TRUE);
     idBtnPesquisar->EnableWindow(FALSE);
     return TRUE;
	} else
    AfxMessageBox(sMensagemErro, MB_ICONERROR | MB_OK, 0);

  return FALSE;
}

BOOL CFrmCadastros::registroAnterior(LISTAMSTR *lstRegistros, 
  CEdit *idEdtCodigo, CEdit *idEdtDesc, UINT *nLinhaRegistro)
{
	if (*nLinhaRegistro > 0) {
    (*nLinhaRegistro)--;
    InformaLimpaDados(lstRegistros, 
      *nLinhaRegistro, idEdtCodigo, idEdtDesc, TRUE);
    return TRUE;
	} else
    return FALSE;
}

BOOL CFrmCadastros::registroProximo(LISTAMSTR *lstRegistros, 
  CEdit *idEdtCodigo, CEdit *idEdtDesc, UINT *nLinhaRegistro)
{
	if (abs(*nLinhaRegistro) < (lstRegistros->col[0].GetCount()-1)) {
    (*nLinhaRegistro)++;
    InformaLimpaDados(lstRegistros, 
      *nLinhaRegistro, idEdtCodigo, idEdtDesc, TRUE);
    return TRUE;
	} else
    return FALSE;
}

BOOL CFrmCadastros::SalvarDados(CEdit *idEdtCodigo, CEdit *idEdtDesc, 
  CButton *idBtnNovo, CButton *idBtnPesquisar, CButton *idBtnAnterior,  
  CButton *idBtnProximo, CButton *idBtnSalvar, CButton *idBtnExcluir,  
  BOOL bValidaDados, CString sTextoSql, CString sTextoUpdate,
	CString sTextoInsert, BOOL bLimparDados)
{
CString sArquiva;

	if (bValidaDados) {    
	   if (Rotinas->ConsultaDados(gConexao,sTextoSql))
         sArquiva = sTextoUpdate;
     else
  	     sArquiva = sTextoInsert;	  	     

     if (Rotinas->AtualizaDados(gConexao, sArquiva)) {
  	   if (bLimparDados)
         btnLimparClick(idEdtCodigo, idEdtDesc, 
         idBtnNovo, idBtnPesquisar, idBtnAnterior, idBtnProximo, 
         idBtnSalvar, idBtnExcluir);
       return TRUE;
     }
	}
  return FALSE;
}
