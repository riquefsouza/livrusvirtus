#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "Livrus.h"
#include "Consultas.h"
#include "resource.h"
#include "ConIdiomas.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinIdiomas;
HWND hLstIdiomas;
LPTSTR sSelIdiomas;
    
LRESULT CALLBACK frmConIdiomasProc(HWND hwnd, UINT Message, WPARAM wParam, 
    LPARAM lParam )
{ 
   switch( Message ) {
      case WM_INITDIALOG:
      {      
        hLstIdiomas = GetDlgItem(hwnd, ID_FRMCONIDIOMAS_LISTCONSULTA);
        
        //hLstIdiomas = Rotinas_criaVisaoLista(hwnd, 
        //ID_FRMCONIDIOMAS_LISTCONSULTA, 0, 0, 165);
            
        LISTASTR sColunas;
        UINT nLargura[] = { 80,250 };
        sColunas = ListaStr_inicia();
        ListaStr_insereFim(&sColunas, "Código");
        ListaStr_insereFim(&sColunas, "Idioma");
          
        Rotinas_VisaoListaInsereColunas(hLstIdiomas, nLargura, sColunas);                              
                                                              
        return TRUE;
      }
      break;       
      case WM_ACTIVATE:
      {
         frmConsultas_Ativar(hwnd, wParam, CM_CON_IDIOMAS);
         return FALSE;
      }
      break;      
      case WM_COMMAND:
      {
        switch( LOWORD(wParam) ) {
			    case ID_FRMCONIDIOMAS_BTNPESQUISAR: 
			    {                                   
            frmConsultas_PesquisarDados(hwnd, hLstIdiomas, 
            ID_FRMCONIDIOMAS_LABREGISTROS, &lstLinIdiomas, ConsSQL_Idioma('S',"", 
            Rotinas_retTexto(hwnd,ID_FRMCONIDIOMAS_EDTDESCRICAO)), 
              Rotinas_lerStr(STR_IDINENC));
            return TRUE;
			    }
			    break;
			    case ID_FRMCONIDIOMAS_BTNLIMPAR: 
			    {                
			      frmConsultas_LimparDados(hwnd, ID_FRMCONIDIOMAS_LABREGISTROS, 
			          ID_FRMCONIDIOMAS_EDTDESCRICAO, hLstIdiomas, lstLinIdiomas);
                  return TRUE;
			    }
			    break;
			    case ID_FRMCONIDIOMAS_BTNFECHAR: 
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
        if (frmConsultas_Notifica(hwnd, lParam, hLstIdiomas,
            ID_FRMCONIDIOMAS_LABREGISTROS, lstLinIdiomas, &sSelIdiomas))
             return 0;
      }      
      break;
      case WM_SIZE:
      {
        frmConsultas_arrumaTamanho(hwnd, ID_FRMCONIDIOMAS_LISTCONSULTA, 
        ID_FRMCONIDIOMAS_LABREGISTROS, ID_FRMCONIDIOMAS_BTNLIMPAR, 
        ID_FRMCONIDIOMAS_BTNFECHAR);
        return TRUE;
      }  
      break;      
      case WM_CLOSE:
      {
        frmConsultas_Fecha(hwnd, sSelIdiomas, CM_CON_IDIOMAS);
        return TRUE;
      }
      break;
   }
  
   return FALSE;
}

