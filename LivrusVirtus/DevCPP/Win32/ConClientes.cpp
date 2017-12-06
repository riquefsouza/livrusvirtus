#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "Livrus.h"
#include "Consultas.h"
#include "resource.h"
#include "ConClientes.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinClientes;
HWND hLstClientes;
LPTSTR sSelClientes;
    
LRESULT CALLBACK frmConClientesProc(HWND hwnd, UINT Message, WPARAM wParam, 
    LPARAM lParam )
{ 
   switch( Message ) {
      case WM_INITDIALOG:
      {      
        hLstClientes = GetDlgItem(hwnd, ID_FRMCONCLIENTES_LISTCONSULTA);
        
        //hLstClientes = Rotinas_criaVisaoLista(hwnd, 
        //ID_FRMCONCLIENTES_LISTCONSULTA, 0, 0, 165);
            
        LISTASTR sColunas;
        UINT nLargura[] = { 90,220,180,80,40,80,120,80,220,150,
                80,100,100,80,180,80,100 };
        sColunas = ListaStr_inicia();
        ListaStr_insereFim(&sColunas, "CPF");
        ListaStr_insereFim(&sColunas, "Nome");
        ListaStr_insereFim(&sColunas, "Email");
        ListaStr_insereFim(&sColunas, "Identidade");
        ListaStr_insereFim(&sColunas, "Sexo");
        ListaStr_insereFim(&sColunas, "Telefone");
        ListaStr_insereFim(&sColunas, "DtNascimento");
        ListaStr_insereFim(&sColunas, "CodEndereço");
        ListaStr_insereFim(&sColunas, "Logradouro");
        ListaStr_insereFim(&sColunas, "Bairro");
        ListaStr_insereFim(&sColunas, "CEP");
        ListaStr_insereFim(&sColunas, "Cidade");
        ListaStr_insereFim(&sColunas, "Estado");
        ListaStr_insereFim(&sColunas, "CodPaís");
        ListaStr_insereFim(&sColunas, "País");
        ListaStr_insereFim(&sColunas, "CodProfissão");
        ListaStr_insereFim(&sColunas, "Profissão");
          
        Rotinas_VisaoListaInsereColunas(hLstClientes, nLargura, sColunas);                              
                                                              
        return TRUE;
      }
      break;       
      case WM_ACTIVATE:
      {
         frmConsultas_Ativar(hwnd, wParam, CM_CON_CLIENTES);
         return FALSE;
      }
      break;      
      case WM_COMMAND:
      {
        switch( LOWORD(wParam) ) {
			    case ID_FRMCONCLIENTES_BTNPESQUISAR: 
			    {                                   
            frmConsultas_PesquisarDados(hwnd, hLstClientes, 
            ID_FRMCONCLIENTES_LABREGISTROS, &lstLinClientes, 
            ConsSQL_Cliente('S',"", 
            Rotinas_retTexto(hwnd,ID_FRMCONCLIENTES_EDTDESCRICAO),
            "","","","","","","",""),Rotinas_lerStr(STR_CLINENC));
            return TRUE;
			    }
			    break;
			    case ID_FRMCONCLIENTES_BTNLIMPAR: 
			    {                
			      frmConsultas_LimparDados(hwnd, ID_FRMCONCLIENTES_LABREGISTROS, 
			          ID_FRMCONCLIENTES_EDTDESCRICAO, hLstClientes, lstLinClientes);
                  return TRUE;
			    }
			    break;
			    case ID_FRMCONCLIENTES_BTNFECHAR: 
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
        if (frmConsultas_Notifica(hwnd, lParam, hLstClientes,
            ID_FRMCONCLIENTES_LABREGISTROS, lstLinClientes, &sSelClientes))
             return 0;
      }      
      break;
      case WM_SIZE:
      {
        frmConsultas_arrumaTamanho(hwnd, ID_FRMCONCLIENTES_LISTCONSULTA, 
        ID_FRMCONCLIENTES_LABREGISTROS, ID_FRMCONCLIENTES_BTNLIMPAR, 
        ID_FRMCONCLIENTES_BTNFECHAR);
        return TRUE;
      }  
      break;      
      case WM_CLOSE:
      {
        frmConsultas_Fecha(hwnd, sSelClientes, CM_CON_CLIENTES);
        return TRUE;
      }
      break;
   }
  
   return FALSE;
}
