#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "Livrus.h"
#include "Consultas.h"
#include "resource.h"
#include "ConAutores.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinAutores;
HWND hLstAutores;
LPTSTR sSelAutores;
    
LRESULT CALLBACK frmConAutoresProc(HWND hwnd, UINT Message, WPARAM wParam, 
    LPARAM lParam )
{ 
   switch( Message ) {
      case WM_INITDIALOG:
      {      
        hLstAutores = GetDlgItem(hwnd, ID_FRMCONAUTORES_LISTCONSULTA);
        
        //hLstAutores = Rotinas_criaVisaoLista(hwnd, 
        //ID_FRMCONAUTORES_LISTCONSULTA, 0, 0, 165);
            
        LISTASTR sColunas;
        UINT nLargura[] = { 80,250 };
        sColunas = ListaStr_inicia();
        ListaStr_insereFim(&sColunas, "Código");
        ListaStr_insereFim(&sColunas, "Autor");
          
        Rotinas_VisaoListaInsereColunas(hLstAutores, nLargura, sColunas);                              
                                                              
        return TRUE;
      }
      break;       
      case WM_ACTIVATE:
      {
         frmConsultas_Ativar(hwnd, wParam, CM_CON_AUTORES);
         return FALSE;
      }
      break;      
      case WM_COMMAND:
      {
        switch( LOWORD(wParam) ) {
			    case ID_FRMCONAUTORES_BTNPESQUISAR: 
			    {                                   
            frmConsultas_PesquisarDados(hwnd, hLstAutores, 
            ID_FRMCONAUTORES_LABREGISTROS, &lstLinAutores, ConsSQL_Autor('S',"", 
            Rotinas_retTexto(hwnd,ID_FRMCONAUTORES_EDTDESCRICAO)), 
              Rotinas_lerStr(STR_AUTNENC));
            return TRUE;
			    }
			    break;
			    case ID_FRMCONAUTORES_BTNLIMPAR: 
			    {                
			      frmConsultas_LimparDados(hwnd, ID_FRMCONAUTORES_LABREGISTROS, 
			          ID_FRMCONAUTORES_EDTDESCRICAO, hLstAutores, lstLinAutores);
                  return TRUE;
			    }
			    break;
			    case ID_FRMCONAUTORES_BTNFECHAR: 
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
        if (frmConsultas_Notifica(hwnd, lParam, hLstAutores,
            ID_FRMCONAUTORES_LABREGISTROS, lstLinAutores, &sSelAutores))
             return 0;
      }      
      break;
      case WM_SIZE:
      {
        frmConsultas_arrumaTamanho(hwnd, ID_FRMCONAUTORES_LISTCONSULTA, 
        ID_FRMCONAUTORES_LABREGISTROS, ID_FRMCONAUTORES_BTNLIMPAR, 
        ID_FRMCONAUTORES_BTNFECHAR);
        return TRUE;
      }  
      break;      
      case WM_CLOSE:
      {
        frmConsultas_Fecha(hwnd, sSelAutores, CM_CON_AUTORES);
        return TRUE;
      }
      break;
   }
  
   return FALSE;
}

