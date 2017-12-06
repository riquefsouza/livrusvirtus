#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "Livrus.h"
#include "Consultas.h"
#include "resource.h"
#include "ConProfissoes.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinProfissoes;
HWND hLstProfissoes;
LPTSTR sSelProfissoes;
    
LRESULT CALLBACK frmConProfissoesProc(HWND hwnd, UINT Message, WPARAM wParam, 
    LPARAM lParam )
{ 
   switch( Message ) {
      case WM_INITDIALOG:
      {      
        hLstProfissoes = GetDlgItem(hwnd, ID_FRMCONPROFISSOES_LISTCONSULTA);
        
        //hLstProfissoes = Rotinas_criaVisaoLista(hwnd, 
        //ID_FRMCONPROFISSOES_LISTCONSULTA, 0, 0, 165);
            
        LISTASTR sColunas;
        UINT nLargura[] = { 80,250 };
        sColunas = ListaStr_inicia();
        ListaStr_insereFim(&sColunas, "Código");
        ListaStr_insereFim(&sColunas, "Profissão");
         
        Rotinas_VisaoListaInsereColunas(hLstProfissoes, nLargura, sColunas);                              
                                                              
        return TRUE;
      }
      break;       
      case WM_ACTIVATE:
      {
         frmConsultas_Ativar(hwnd, wParam, CM_CON_PROFISSOES);
         return FALSE;
      }
      break;      
      case WM_COMMAND:
      {
        switch( LOWORD(wParam) ) {
			    case ID_FRMCONPROFISSOES_BTNPESQUISAR: 
			    {                                   
            frmConsultas_PesquisarDados(hwnd, hLstProfissoes, 
            ID_FRMCONPROFISSOES_LABREGISTROS, &lstLinProfissoes, 
            ConsSQL_Profissao('S',"", 
            Rotinas_retTexto(hwnd,ID_FRMCONPROFISSOES_EDTDESCRICAO)), 
              "Profissão não encontrada!");
            return TRUE;
			    }
			    break;
			    case ID_FRMCONPROFISSOES_BTNLIMPAR: 
			    {                
			      frmConsultas_LimparDados(hwnd, ID_FRMCONPROFISSOES_LABREGISTROS, 
			          ID_FRMCONPROFISSOES_EDTDESCRICAO, hLstProfissoes, lstLinProfissoes);
                  return TRUE;
			    }
			    break;
			    case ID_FRMCONPROFISSOES_BTNFECHAR: 
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
        if (frmConsultas_Notifica(hwnd, lParam, hLstProfissoes,
            ID_FRMCONPROFISSOES_LABREGISTROS, lstLinProfissoes, &sSelProfissoes))
             return 0;
      }      
      break;
      case WM_SIZE:
      {
        frmConsultas_arrumaTamanho(hwnd, ID_FRMCONPROFISSOES_LISTCONSULTA, 
        ID_FRMCONPROFISSOES_LABREGISTROS, ID_FRMCONPROFISSOES_BTNLIMPAR, 
        ID_FRMCONPROFISSOES_BTNFECHAR);
        return TRUE;
      }  
      break;      
      case WM_CLOSE:
      {
        frmConsultas_Fecha(hwnd, sSelProfissoes, CM_CON_PROFISSOES);
        return TRUE;
      }
      break;
   }
  
   return FALSE;
}

