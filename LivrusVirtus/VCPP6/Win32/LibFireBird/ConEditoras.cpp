#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "Livrus.h"
#include "Consultas.h"
#include "resource.h"
#include "ConEditoras.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinEditoras;
HWND hLstEditoras;
LPTSTR sSelEditoras;
    
LRESULT CALLBACK frmConEditorasProc(HWND hwnd, UINT Message, WPARAM wParam, 
    LPARAM lParam )
{ 
   switch( Message ) {
      case WM_INITDIALOG:
      {      
        hLstEditoras = GetDlgItem(hwnd, ID_FRMCONEDITORAS_LISTCONSULTA);
        
        //hLstEditoras = Rotinas_criaVisaoLista(hwnd, 
        //ID_FRMCONEDITORAS_LISTCONSULTA, 0, 0, 165);
            
        LISTASTR sColunas;
        UINT nLargura[] = { 80,250 };
        sColunas = ListaStr_inicia();
        ListaStr_insereFim(&sColunas, "Código");
        ListaStr_insereFim(&sColunas, "Editora");
          
        Rotinas_VisaoListaInsereColunas(hLstEditoras, nLargura, sColunas);                              
                                                              
        return TRUE;
      }
      break;       
      case WM_ACTIVATE:
      {
         frmConsultas_Ativar(hwnd, wParam, CM_CON_EDITORAS);
         return FALSE;
      }
      break;      
      case WM_COMMAND:
      {
        switch( LOWORD(wParam) ) {
			    case ID_FRMCONEDITORAS_BTNPESQUISAR: 
			    {                                   
            frmConsultas_PesquisarDados(hwnd, hLstEditoras, 
            ID_FRMCONEDITORAS_LABREGISTROS, &lstLinEditoras, ConsSQL_Editora('S',"", 
            Rotinas_retTexto(hwnd,ID_FRMCONEDITORAS_EDTDESCRICAO)), 
              "Editora não encontrada!");
            return TRUE;
			    }
			    break;
			    case ID_FRMCONEDITORAS_BTNLIMPAR: 
			    {                
			      frmConsultas_LimparDados(hwnd, ID_FRMCONEDITORAS_LABREGISTROS, 
			          ID_FRMCONEDITORAS_EDTDESCRICAO, hLstEditoras, lstLinEditoras);
                  return TRUE;
			    }
			    break;
			    case ID_FRMCONEDITORAS_BTNFECHAR: 
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
        if (frmConsultas_Notifica(hwnd, lParam, hLstEditoras,
            ID_FRMCONEDITORAS_LABREGISTROS, lstLinEditoras, &sSelEditoras))
             return 0;
      }      
      break;
      case WM_SIZE:
      {
        frmConsultas_arrumaTamanho(hwnd, ID_FRMCONEDITORAS_LISTCONSULTA, 
        ID_FRMCONEDITORAS_LABREGISTROS, ID_FRMCONEDITORAS_BTNLIMPAR, 
        ID_FRMCONEDITORAS_BTNFECHAR);
        return TRUE;
      }  
      break;      
      case WM_CLOSE:
      {
        frmConsultas_Fecha(hwnd, sSelEditoras, CM_CON_EDITORAS);
        return TRUE;
      }
      break;
   }
  
   return FALSE;
}

