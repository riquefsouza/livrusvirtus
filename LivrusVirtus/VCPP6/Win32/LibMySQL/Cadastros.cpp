#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <stdlib.h>
#include <commctrl.h>

#include "RotinasGlobais.h"
#include "Cadastros.h"
#include "Principal.h"
#include "resource.h"

BOOL frmCadastros_Criar(HWND hwnd, LPTSTR sNomeTela, DLGPROC sDlgProc)
{ 
  HWND hwndLocal;

  g_hTelaAtiva = hwnd;  
  hwndLocal = CreateDialog((HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
    sNomeTela, g_hTelaAtiva, sDlgProc); 
  
  if (!hwndLocal) {
    MessageBox(0, Rotinas_lerStr(STR_NCCRIADLG), "Erro", MB_ICONERROR | MB_OK);
    return FALSE;    
  }
  SetWindowLong(hwnd, HWNDMDIFILHA, (LONG)hwndLocal);    
  return TRUE;
}

BOOL frmCadastros_Ativar(HWND hwnd, WPARAM wParam, LPARAM lParam, 
    INT idEdtCodigo, INT nPosMenu, INT idSubMenu)
{
TCHAR sTitulo[TAM_MAX_STR];

if (GET_WM_MDIACTIVATE_FACTIVATE(hwnd, wParam, lParam) &&
    (g_hTelaAtiva != hwnd))
  g_hTelaAtiva = hwnd;

Rotinas_habilitaSubMenu(g_hFRMPrincipal, nPosMenu, idSubMenu, FALSE);

GetWindowText(hwnd, sTitulo, TAM_MAX_STR);
SendMessage(g_hBarraStatus, SB_SETTEXT, 1, (LPARAM)sTitulo);
SetFocus(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), idEdtCodigo));

return (hwnd == (HWND)lParam);
}

VOID frmCadastros_Fechar(HWND hwnd, INT nPosMenu, INT idSubMenu)
{
  DLGPROC lpDlgProc;
  
  lpDlgProc = (DLGPROC)GetWindowLong(
    (HWND)GetWindowLong(hwnd, HWNDMDIFILHA), DWL_DLGPROC);
  DestroyWindow((HWND)GetWindowLong(hwnd, HWNDMDIFILHA));
  FreeProcInstance(lpDlgProc);
  if (hwnd == g_hTelaAtiva)
   g_hTelaAtiva = (HWND)NULL;  

  SendMessage(g_hBarraStatus, SB_SETTEXT, 1, (LPARAM)"");      
  Rotinas_habilitaSubMenu(g_hFRMPrincipal, nPosMenu, idSubMenu, TRUE);       
}

VOID frmCadastros_TamMaxEdit(HWND hwnd, INT idEdit, INT nTamMax)
{
SendMessage(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), idEdit), 
    EM_SETLIMITTEXT,(WPARAM) nTamMax, 0);        
}        

VOID frmCadastros_InformaLimpaDados(HWND hwnd, LISTAMSTR lstRegistros, 
  UINT nLinhaRegistro, INT idEdtCodigo, INT idEdtDesc, BOOL bInformar)
{
  if (bInformar) {
    SetWindowText(GetDlgItem(hwnd, idEdtCodigo), 
      ListaStr_pesquisaItemOrdM(lstRegistros, 0, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, idEdtDesc),
      ListaStr_pesquisaItemOrdM(lstRegistros, 1, nLinhaRegistro));    
  } else {
    SetWindowText(GetDlgItem(hwnd, idEdtCodigo),"");
    SetWindowText(GetDlgItem(hwnd, idEdtDesc),"");
    EnableWindow(GetDlgItem(hwnd, idEdtCodigo),TRUE);
    SetFocus(GetDlgItem(hwnd, idEdtCodigo));
  }
} 

VOID frmCadastros_HabilitaDados(HWND hwnd, INT idEdtDesc, BOOL bHabilita)
{
  EnableWindow(GetDlgItem(hwnd, idEdtDesc),bHabilita);
}

VOID frmCadastros_btnNovoClick(HWND hwnd, INT idEdtCodigo, INT idEdtDesc, 
  INT idBtnNovo, INT idBtnPesquisar, INT idBtnAnterior,  
  INT idBtnProximo, INT idBtnSalvar, INT idBtnExcluir) 
{
  EnableWindow(GetDlgItem(hwnd, idBtnSalvar),TRUE);
  EnableWindow(GetDlgItem(hwnd, idBtnExcluir),FALSE);
  EnableWindow(GetDlgItem(hwnd, idBtnPesquisar),FALSE);
  EnableWindow(GetDlgItem(hwnd, idBtnAnterior),FALSE);
  EnableWindow(GetDlgItem(hwnd, idBtnProximo),FALSE);
  EnableWindow(GetDlgItem(hwnd, idBtnNovo),FALSE);

  frmCadastros_InformaLimpaDados(hwnd, NULL,  
    0, idEdtCodigo, idEdtDesc, FALSE);
  frmCadastros_HabilitaDados(hwnd, idEdtDesc, TRUE);	
}

VOID frmCadastros_NovoDado(HWND hwnd, INT idEdtCodigo, INT idEdtDesc, 
  LPTSTR sTextoSql)
{
LISTAMSTR lstRegistros;
  if (Rotinas_ConsultaDadosLista(gConexao, &lstRegistros, sTextoSql)) {
    SetWindowText(GetDlgItem(hwnd, idEdtCodigo), 
      ListaStr_pesquisaItemOrdM(lstRegistros, 0, 0));
    EnableWindow(GetDlgItem(hwnd, idEdtCodigo),FALSE);
    SetFocus(GetDlgItem(hwnd, idEdtDesc));
  }
}

VOID frmCadastros_btnLimparClick(HWND hwnd, INT idEdtCodigo, INT idEdtDesc, 
  INT idBtnNovo, INT idBtnPesquisar, INT idBtnAnterior,  
  INT idBtnProximo, INT idBtnSalvar, INT idBtnExcluir) 
{
  EnableWindow(GetDlgItem(hwnd, idBtnSalvar),FALSE);
  EnableWindow(GetDlgItem(hwnd, idBtnExcluir),FALSE);
  EnableWindow(GetDlgItem(hwnd, idBtnPesquisar),TRUE);
  EnableWindow(GetDlgItem(hwnd, idBtnAnterior),FALSE);
  EnableWindow(GetDlgItem(hwnd, idBtnProximo),FALSE);
  EnableWindow(GetDlgItem(hwnd, idBtnNovo),TRUE);

  frmCadastros_InformaLimpaDados(hwnd, NULL,  
    0, idEdtCodigo, idEdtDesc, FALSE);
  frmCadastros_HabilitaDados(hwnd, idEdtDesc, FALSE);	

}

BOOL frmCadastros_ExcluirDados(HWND hwnd, INT idEdtCodigo, INT idEdtDesc, 
  INT idBtnNovo, INT idBtnPesquisar, INT idBtnAnterior,  
  INT idBtnProximo, INT idBtnSalvar, INT idBtnExcluir, 
  BOOL bValidaDados, LPTSTR sTextoSql)
{
   if (bValidaDados) {

     if (MessageBox(hwnd, Rotinas_lerStr(STR_CERTEXCL), 
          Rotinas_lerStr(STR_TITULO),
         MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2) == IDYES) { 

        if (Rotinas_AtualizaDados(gConexao, sTextoSql)) {
           frmCadastros_btnLimparClick(hwnd, idEdtCodigo, idEdtDesc, 
           idBtnNovo, idBtnPesquisar, idBtnAnterior, idBtnProximo, 
           idBtnSalvar, idBtnExcluir);
           return TRUE;
        }

  	 }
   }
  return FALSE;
}

BOOL frmCadastros_PesquisarDados(HWND hwnd,  LISTAMSTR *lstRegistros, 
  INT idEdtCodigo, INT idEdtDesc, INT idBtnPesquisar, 
  INT idBtnAnterior, INT idBtnProximo, INT idBtnSalvar, 
  INT idBtnExcluir, LPTSTR sTextoSql, LPTSTR sMensagemErro)
{
	if (lstrlen(Rotinas_retTexto(hwnd, idEdtCodigo)) == 0) {
    EnableWindow(GetDlgItem(hwnd, idBtnAnterior),TRUE);
    EnableWindow(GetDlgItem(hwnd, idBtnProximo),TRUE);
	}

  if (Rotinas_ConsultaDadosLista(gConexao, lstRegistros, sTextoSql)) {
     frmCadastros_InformaLimpaDados(hwnd, *lstRegistros, 0, 
      idEdtCodigo, idEdtDesc, TRUE);
     frmCadastros_HabilitaDados(hwnd, idEdtDesc, TRUE);	

     EnableWindow(GetDlgItem(hwnd, idBtnSalvar),TRUE);
     EnableWindow(GetDlgItem(hwnd, idBtnExcluir),TRUE);
     EnableWindow(GetDlgItem(hwnd, idBtnPesquisar),FALSE);
     return TRUE;
	} else
    MessageBox(hwnd, sMensagemErro, "Erro", MB_ICONERROR | MB_OK);

  return FALSE;
}

BOOL frmCadastros_registroAnterior(HWND hwnd, LISTAMSTR lstRegistros, 
  INT idEdtCodigo, INT idEdtDesc, UINT *nLinhaRegistro)
{
	if (*nLinhaRegistro > 0) {
        (*nLinhaRegistro)--;
        frmCadastros_InformaLimpaDados(hwnd, lstRegistros, 
          *nLinhaRegistro, idEdtCodigo, idEdtDesc, TRUE);
        return TRUE;
	} else
        return FALSE;
}

BOOL frmCadastros_registroProximo(HWND hwnd, LISTAMSTR lstRegistros, 
  INT idEdtCodigo, INT idEdtDesc, UINT *nLinhaRegistro)
{
	if (abs(*nLinhaRegistro) < (ListaStr_contaM(lstRegistros)-1)) {
        (*nLinhaRegistro)++;
        frmCadastros_InformaLimpaDados(hwnd, lstRegistros, 
          *nLinhaRegistro, idEdtCodigo, idEdtDesc, TRUE);
        return TRUE;
	} else
        return FALSE;
}

BOOL frmCadastros_SalvarDados(HWND hwnd, INT idEdtCodigo, INT idEdtDesc, 
  INT idBtnNovo, INT idBtnPesquisar, INT idBtnAnterior,  
  INT idBtnProximo, INT idBtnSalvar, INT idBtnExcluir, 
  BOOL bValidaDados, LPTSTR sTextoSql,LPTSTR sTextoUpdate,
	LPTSTR sTextoInsert, BOOL bLimparDados)
{
LPTSTR sArquiva;

	if (bValidaDados) {
	   if (Rotinas_ConsultaDados(gConexao,sTextoSql))
         sArquiva = sTextoUpdate;
	   else
  	     sArquiva = sTextoInsert;	  	     
    
     if (Rotinas_AtualizaDados(gConexao, sArquiva)) {
  	   if (bLimparDados)
         frmCadastros_btnLimparClick(hwnd, idEdtCodigo, idEdtDesc, 
         idBtnNovo, idBtnPesquisar, idBtnAnterior, idBtnProximo, 
         idBtnSalvar, idBtnExcluir);
       return TRUE;
     }
	}
  return FALSE;
}

