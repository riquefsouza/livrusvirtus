#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "Livrus.h"
#include "Consultas.h"
#include "resource.h"
#include "ConAssuntos.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinAssuntos;
HWND hLstAssuntos;
LPTSTR sSelAssuntos;
    
LRESULT CALLBACK frmConAssuntosProc(HWND hwnd, UINT Message, WPARAM wParam, 
    LPARAM lParam )
{ 
   switch( Message ) {
      case WM_INITDIALOG:
      {      
        hLstAssuntos = GetDlgItem(hwnd, ID_FRMCONASSUNTOS_LISTCONSULTA);
        
        //hLstAssuntos = Rotinas_criaVisaoLista(hwnd, 
        //ID_FRMCONASSUNTOS_LISTCONSULTA, 0, 0, 165);
            
        LISTASTR sColunas;
        UINT nLargura[] = { 80,250 };
        sColunas = ListaStr_inicia();         
        ListaStr_insereFim(&sColunas, "Código");
        ListaStr_insereFim(&sColunas, "Assunto");
          
        Rotinas_VisaoListaInsereColunas(hLstAssuntos, nLargura, sColunas);                              
                                                              
        return TRUE;
      }
      break;       
      case WM_ACTIVATE:
      {
         frmConsultas_Ativar(hwnd, wParam, CM_CON_ASSUNTOS);
         return FALSE;
      }
      break;      
      case WM_COMMAND:
      {
        switch( LOWORD(wParam) ) {
          case ID_FRMCONASSUNTOS_BTNPESQUISAR: 
          {                                   
                  frmConsultas_PesquisarDados(hwnd, hLstAssuntos, 
                  ID_FRMCONASSUNTOS_LABREGISTROS, &lstLinAssuntos, ConsSQL_Assunto('S',"", 
                  Rotinas_retTexto(hwnd,ID_FRMCONASSUNTOS_EDTDESCRICAO)), 
                    Rotinas_lerStr(STR_ASSNENC));
                  return TRUE;
          }
          break;
          case ID_FRMCONASSUNTOS_BTNLIMPAR: 
          {                
	          frmConsultas_LimparDados(hwnd, ID_FRMCONASSUNTOS_LABREGISTROS, 
			          ID_FRMCONASSUNTOS_EDTDESCRICAO, hLstAssuntos, lstLinAssuntos);
                  return TRUE;
          }
          break;
          case ID_FRMCONASSUNTOS_BTNFECHAR: 
          {
                   SendMessage(hwnd, WM_CLOSE, 0, 0);
                   return TRUE;
          }
          break;
        }
      }   
      break;
      case WM_NOTIFY:
      { 
        if (frmConsultas_Notifica(hwnd, lParam, hLstAssuntos,
            ID_FRMCONASSUNTOS_LABREGISTROS, lstLinAssuntos, &sSelAssuntos))
             return 0;
      }      
      break;
      case WM_SIZE:
      {
        frmConsultas_arrumaTamanho(hwnd, ID_FRMCONASSUNTOS_LISTCONSULTA, 
        ID_FRMCONASSUNTOS_LABREGISTROS, ID_FRMCONASSUNTOS_BTNLIMPAR, 
        ID_FRMCONASSUNTOS_BTNFECHAR);
        return TRUE;
      }  
      break;      
      case WM_CLOSE:
      {
        frmConsultas_Fecha(hwnd, sSelAssuntos, CM_CON_ASSUNTOS);
        return TRUE;
      }
      break;
   }
  
   return FALSE;
}

