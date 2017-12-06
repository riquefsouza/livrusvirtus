#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "Livrus.h"
#include "Consultas.h"
#include "resource.h"
#include "ConEnderecos.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinEnderecos;
HWND hLstEnderecos;
LPTSTR sSelEnderecos;
    
LRESULT CALLBACK frmConEnderecosProc(HWND hwnd, UINT Message, WPARAM wParam, 
    LPARAM lParam )
{ 
   switch( Message ) {
      case WM_INITDIALOG:
      {      
        hLstEnderecos = GetDlgItem(hwnd, ID_FRMCONENDERECOS_LISTCONSULTA);
        
        //hLstEnderecos = Rotinas_criaVisaoLista(hwnd, 
        //ID_FRMCONENDERECOS_LISTCONSULTA, 0, 0, 165);
            
        LISTASTR sColunas;
        UINT nLargura[] = { 80,200,150,80,100,80 };
        sColunas = ListaStr_inicia();
        ListaStr_insereFim(&sColunas, "Código");
        ListaStr_insereFim(&sColunas, "Logradouro");
        ListaStr_insereFim(&sColunas, "Bairro");
        ListaStr_insereFim(&sColunas, "CEP");
        ListaStr_insereFim(&sColunas, "Cidade");
        ListaStr_insereFim(&sColunas, "Estado");
          
        Rotinas_VisaoListaInsereColunas(hLstEnderecos, nLargura, sColunas);                              
                                                              
        return TRUE;
      }
      break;       
      case WM_ACTIVATE:
      {
         frmConsultas_Ativar(hwnd, wParam, CM_CON_ENDERECOS);
         return FALSE;
      }
      break;      
      case WM_COMMAND:
      {
        switch( LOWORD(wParam) ) {
			    case ID_FRMCONENDERECOS_BTNPESQUISAR: 
			    {                                   
            frmConsultas_PesquisarDados(hwnd, hLstEnderecos, 
            ID_FRMCONENDERECOS_LABREGISTROS, &lstLinEnderecos, 
            ConsSQL_Endereco('S',"", 
            Rotinas_retTexto(hwnd,ID_FRMCONENDERECOS_EDTDESCRICAO),
            "","","",""), Rotinas_lerStr(STR_ENDNENC));
            return TRUE;
			    }
			    break;
			    case ID_FRMCONENDERECOS_BTNLIMPAR: 
			    {                
			      frmConsultas_LimparDados(hwnd, ID_FRMCONENDERECOS_LABREGISTROS, 
  	          ID_FRMCONENDERECOS_EDTDESCRICAO, hLstEnderecos, lstLinEnderecos);
                  return TRUE;
			    }
			    break;
			    case ID_FRMCONENDERECOS_BTNFECHAR: 
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
        if (frmConsultas_Notifica(hwnd, lParam, hLstEnderecos,
            ID_FRMCONENDERECOS_LABREGISTROS, lstLinEnderecos, &sSelEnderecos))
             return 0;
      }      
      break;
      case WM_SIZE:
      {
        frmConsultas_arrumaTamanho(hwnd, ID_FRMCONENDERECOS_LISTCONSULTA, 
        ID_FRMCONENDERECOS_LABREGISTROS, ID_FRMCONENDERECOS_BTNLIMPAR, 
        ID_FRMCONENDERECOS_BTNFECHAR);
        return TRUE;
      }  
      break;      
      case WM_CLOSE:
      {
        frmConsultas_Fecha(hwnd, sSelEnderecos, CM_CON_ENDERECOS);
        return TRUE;
      }
      break;
   }
  
   return FALSE;
}

