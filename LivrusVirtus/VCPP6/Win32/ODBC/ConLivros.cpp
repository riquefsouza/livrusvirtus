#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "Livrus.h"
#include "Consultas.h"
#include "resource.h"
#include "ConLivros.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinLivros;
HWND hLstLivros;
LPTSTR sSelLivros;
    
LRESULT CALLBACK frmConLivrosProc(HWND hwnd, UINT Message, WPARAM wParam, 
    LPARAM lParam )
{ 
   switch( Message ) {
      case WM_INITDIALOG:
      {      
        hLstLivros = GetDlgItem(hwnd, ID_FRMCONLIVROS_LISTCONSULTA);
        
        //hLstLivros = Rotinas_criaVisaoLista(hwnd, 
        //ID_FRMCONLIVROS_LISTCONSULTA, 0, 0, 165);
            
        LISTASTR sColunas;
        UINT nLargura[] = { 80,180,80,80,80,80,100,80,100,80,80,80 };
        sColunas = ListaStr_inicia();
        ListaStr_insereFim(&sColunas, "ISBN");
        ListaStr_insereFim(&sColunas, "Título");
        ListaStr_insereFim(&sColunas, "Edição");
        ListaStr_insereFim(&sColunas, "AnoPublicação");
        ListaStr_insereFim(&sColunas, "Volume");
        ListaStr_insereFim(&sColunas, "CodEditora");
        ListaStr_insereFim(&sColunas, "Editora");
        ListaStr_insereFim(&sColunas, "CodIdioma");
        ListaStr_insereFim(&sColunas, "Idioma");
        ListaStr_insereFim(&sColunas, "NumPáginas");
        ListaStr_insereFim(&sColunas, "Preço");
        ListaStr_insereFim(&sColunas, "Estoque");          
          
        Rotinas_VisaoListaInsereColunas(hLstLivros, nLargura, sColunas);                              
                                                              
        return TRUE;
      }
      break;       
      case WM_ACTIVATE:
      {
         frmConsultas_Ativar(hwnd, wParam, CM_CON_LIVROS);
         return FALSE;
      }
      break;      
      case WM_COMMAND:
      {
        switch( LOWORD(wParam) ) {
			    case ID_FRMCONLIVROS_BTNPESQUISAR: 
			    {                                     
            frmConsultas_PesquisarDados(hwnd, hLstLivros, 
            ID_FRMCONLIVROS_LABREGISTROS, &lstLinLivros, ConsSQL_Livro('S',"", 
            Rotinas_retTexto(hwnd,ID_FRMCONLIVROS_EDTDESCRICAO),
            "","","","","","","",""), Rotinas_lerStr(STR_LIVNENC));
            return TRUE;
			    }
			    break;
			    case ID_FRMCONLIVROS_BTNLIMPAR: 
			    {                
			      frmConsultas_LimparDados(hwnd, ID_FRMCONLIVROS_LABREGISTROS, 
			          ID_FRMCONLIVROS_EDTDESCRICAO, hLstLivros, lstLinLivros);
                  return TRUE;
			    }
			    break;
			    case ID_FRMCONLIVROS_BTNFECHAR: 
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
        if (frmConsultas_Notifica(hwnd, lParam, hLstLivros,
            ID_FRMCONLIVROS_LABREGISTROS, lstLinLivros, &sSelLivros))
             return 0;
      }      
      break;
      case WM_SIZE:
      {
        frmConsultas_arrumaTamanho(hwnd, ID_FRMCONLIVROS_LISTCONSULTA, 
        ID_FRMCONLIVROS_LABREGISTROS, ID_FRMCONLIVROS_BTNLIMPAR, 
        ID_FRMCONLIVROS_BTNFECHAR);
        return TRUE;
      }  
      break;      
      case WM_CLOSE:
      {
        frmConsultas_Fecha(hwnd, sSelLivros, CM_CON_LIVROS);
        return TRUE;
      }
      break;
   }
  
   return FALSE;
}

