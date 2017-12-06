#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "RotinasGlobais.h"
#include "Principal.h"
#include "Consultas.h"

VOID frmConsultas_Ativar(HWND hwnd, WPARAM wParam, INT idSubMenu)
{
TCHAR sTitulo[TAM_MAX_STR];

if (wParam == 0)
  g_hDlgAtual = NULL;
else                        
  g_hDlgAtual = hwnd;

Rotinas_habilitaSubMenu(g_hFRMPrincipal, 1, idSubMenu, FALSE);

GetWindowText(hwnd, sTitulo, TAM_MAX_STR);
SendMessage(g_hBarraStatus, SB_SETTEXT, 1, (LPARAM)sTitulo);
}

VOID frmConsultas_Fecha(HWND hwnd, LPTSTR sSelecionado, INT idSubMenu)
{
 if (lstrlen(sSelecionado) > 0)
   lstrcpy(Rotinas_sCodigoSelecionado, sSelecionado);
 else
   lstrcpy(Rotinas_sCodigoSelecionado, "");

 EndDialog(hwnd, TRUE);
 
 SendMessage(g_hBarraStatus, SB_SETTEXT, 1, (LPARAM)""); 
 Rotinas_habilitaSubMenu(g_hFRMPrincipal, 1, idSubMenu, TRUE);
}

VOID frmConsultas_setLabRegistros(HWND hwnd, INT idLabRegs, 
    LISTAMSTR sLinhas, INT nReg)
{
  TCHAR sRegs[TAM_MAX_STR];    
  UINT nTotal;
  
  if (nReg == 0) nTotal = 0;
  else nTotal = ListaStr_contaM(sLinhas);
  
  wsprintf(sRegs, "Registro %d de %d", nReg, nTotal);
  SetWindowText(GetDlgItem(hwnd, idLabRegs),sRegs);
}

VOID frmConsultas_arrumaTamanho(HWND hwnd, INT idListaCons, INT idLabRegs, 
    INT idBtnLimpar, INT idBtnFechar)
{
HWND hListaCons, hLabRegs, hBtnLimpar, hBtnFechar;
RECT rForm, rListCons, rRegs, rLimpar, rFechar;
INT hFrm, wFrm;

hListaCons = GetDlgItem(hwnd, idListaCons);
hLabRegs = GetDlgItem(hwnd, idLabRegs);
hBtnLimpar = GetDlgItem(hwnd, idBtnLimpar);
hBtnFechar = GetDlgItem(hwnd, idBtnFechar);
        
GetClientRect(hwnd, &rForm);
GetClientRect(hListaCons, &rListCons);
GetClientRect(hLabRegs, &rRegs);
GetClientRect(hBtnLimpar, &rLimpar);
GetClientRect(hBtnFechar, &rFechar);

hFrm = (rForm.bottom - rForm.top);
wFrm = (rForm.right - rForm.left);

MoveWindow(hListaCons, 0, 51, wFrm, hFrm - 90, TRUE);
MoveWindow(hLabRegs, 8, (hFrm - 30), 
  (rRegs.right - rRegs.left), (rRegs.bottom - rRegs.top), TRUE);
MoveWindow(hBtnLimpar, (wFrm - 155), (hFrm - 30), 
  (rLimpar.right - rLimpar.left), (rLimpar.bottom - rLimpar.top), TRUE);
MoveWindow(hBtnFechar, (wFrm - 80), (hFrm - 30), 
  (rFechar.right - rFechar.left), (rFechar.bottom - rFechar.top), TRUE);
}
   
BOOL frmConsultas_Notifica(HWND hwnd, LPARAM lParam, HWND hListaCons, 
    INT idLabRegs, LISTAMSTR sLinhas, LPTSTR *sSelecionado) 
{
INT nReg;      

 if (Rotinas_VisaoListaNotifica(hListaCons, sLinhas, lParam, &nReg,
    sSelecionado)) {               

   if (nReg > 0) {
     frmConsultas_setLabRegistros(hwnd, idLabRegs, sLinhas, nReg);                        
   }                  
   return TRUE;
 }
 return FALSE;
}

VOID frmConsultas_LimparDados(HWND hwnd, INT idLabRegs, INT idEdtDesc, 
    HWND hListaCons, LISTAMSTR sLinhas)
{
  frmConsultas_setLabRegistros(hwnd, idLabRegs, sLinhas, 0);
  ListView_DeleteAllItems(hListaCons);
  SetWindowText(GetDlgItem(hwnd, idEdtDesc),"");
  SetFocus(GetDlgItem(hwnd, idEdtDesc));
}

VOID frmConsultas_PesquisarDados(HWND hwnd, HWND hListaCons, INT idLabRegs,
                LISTAMSTR *sLinhas, LPTSTR sTextoSql, LPTSTR sMensagemErro)
{
    if (Rotinas_ConsultaDadosLista(gConexao, sLinhas, sTextoSql)) {
       Rotinas_VisaoListaInsereLinhas(hListaCons, *sLinhas);
       frmConsultas_setLabRegistros(hwnd, idLabRegs, *sLinhas, 1);
    } else {
       MessageBox(hwnd, sMensagemErro, "Erro", MB_ICONERROR | MB_OK);
    }
}


