#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "Livrus.h"
#include "Consultas.h"
#include "resource.h"
#include "ConPaises.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinPaises;
HWND hLstPaises;
LPTSTR sSelPaises;
    
LRESULT CALLBACK frmConPaisesProc(HWND hwnd, UINT Message, WPARAM wParam, 
    LPARAM lParam )
{ 
   switch( Message ) {
      case WM_INITDIALOG:
      {      
        hLstPaises = GetDlgItem(hwnd, ID_FRMCONPAISES_LISTCONSULTA);
        
        //hLstPaises = Rotinas_criaVisaoLista(hwnd, 
        //ID_FRMCONPAISES_LISTCONSULTA, 0, 0, 165);
            
        LISTASTR sColunas;
        UINT nLargura[] = { 80,250 };
        sColunas = ListaStr_inicia();
        ListaStr_insereFim(&sColunas, "Código");
        ListaStr_insereFim(&sColunas, "País");
          
        Rotinas_VisaoListaInsereColunas(hLstPaises, nLargura, sColunas);                              
                                                              
        return TRUE;
      }
      break;       
      case WM_ACTIVATE:
      {
         frmConsultas_Ativar(hwnd, wParam, CM_CON_PAISES);
         return FALSE;
      }
      break;      
      case WM_COMMAND:
      {
        switch( LOWORD(wParam) ) {
			    case ID_FRMCONPAISES_BTNPESQUISAR: 
			    {                                   
            frmConsultas_PesquisarDados(hwnd, hLstPaises, 
            ID_FRMCONPAISES_LABREGISTROS, &lstLinPaises, ConsSQL_Pais('S',"", 
            Rotinas_retTexto(hwnd,ID_FRMCONPAISES_EDTDESCRICAO)), 
              Rotinas_lerStr(STR_PAISNENC));
            return TRUE;
			    }
			    break;
			    case ID_FRMCONPAISES_BTNLIMPAR: 
			    {                
			      frmConsultas_LimparDados(hwnd, ID_FRMCONPAISES_LABREGISTROS, 
			          ID_FRMCONPAISES_EDTDESCRICAO, hLstPaises, lstLinPaises);
                  return TRUE;
			    }
			    break;
			    case ID_FRMCONPAISES_BTNFECHAR: 
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
        if (frmConsultas_Notifica(hwnd, lParam, hLstPaises,
            ID_FRMCONPAISES_LABREGISTROS, lstLinPaises, &sSelPaises))
             return 0;
      }      
      break;
      case WM_SIZE:
      {
        frmConsultas_arrumaTamanho(hwnd, ID_FRMCONPAISES_LISTCONSULTA, 
        ID_FRMCONPAISES_LABREGISTROS, ID_FRMCONPAISES_BTNLIMPAR, 
        ID_FRMCONPAISES_BTNFECHAR);
        return TRUE;
      }  
      break;      
      case WM_CLOSE:
      {
        frmConsultas_Fecha(hwnd, sSelPaises, CM_CON_PAISES);
        return TRUE;
      }
      break;
   }
  
   return FALSE;
}

