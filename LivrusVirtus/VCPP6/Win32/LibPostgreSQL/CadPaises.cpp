#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "resource.h"
#include "Principal.h"
#include "Cadastros.h"
#include "CadPaises.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstRegPaises;
UINT nRegPaises;
BOOL bAtivaPaises;

LRESULT CALLBACK frmCadPaisesProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {         
      case WM_CREATE:
      {
        if (!frmCadastros_Criar(hwnd, g_sFRMCadPaises, 
                (DLGPROC)frmCadPaisesProc))
          return FALSE;          

        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADPAISES_EDTCODIGO, 3);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADPAISES_EDTDESCRICAO, 50);          
        nRegPaises = 0;
      }
      break;
      case WM_MDIACTIVATE:
      {
        bAtivaPaises = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMCADPAISES_EDTCODIGO, 0, CM_CAD_PAISES);
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
         frmCadastros_Fechar(hwnd, 0, CM_CAD_PAISES);
      }  
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {  
            case ID_FRMCADPAISES_BTNNOVO:
            {
              frmCadastros_btnNovoClick(hwnd, ID_FRMCADPAISES_EDTCODIGO, 
              ID_FRMCADPAISES_EDTDESCRICAO, ID_FRMCADPAISES_BTNNOVO,
              ID_FRMCADPAISES_BTNPESQUISAR, ID_FRMCADPAISES_BTNANTERIOR,
              ID_FRMCADPAISES_BTNPROXIMO, ID_FRMCADPAISES_BTNSALVAR,
              ID_FRMCADPAISES_BTNEXCLUIR);
            }
            break;
            case ID_FRMCADPAISES_BTNPESQUISAR:
            {
              frmCadastros_PesquisarDados(hwnd, &lstRegPaises, 
              ID_FRMCADPAISES_EDTCODIGO, ID_FRMCADPAISES_EDTDESCRICAO,
              ID_FRMCADPAISES_BTNPESQUISAR, ID_FRMCADPAISES_BTNANTERIOR,
              ID_FRMCADPAISES_BTNPROXIMO, ID_FRMCADPAISES_BTNSALVAR,
              ID_FRMCADPAISES_BTNEXCLUIR, ConsSQL_Pais('S',
              Rotinas_retTexto(hwnd, ID_FRMCADPAISES_EDTCODIGO),""),
              Rotinas_lerStr(STR_PAISNENC));
            }
            break;
            case ID_FRMCADPAISES_BTNANTERIOR:
            {
              frmCadastros_registroAnterior(hwnd, lstRegPaises, 
              ID_FRMCADPAISES_EDTCODIGO, ID_FRMCADPAISES_EDTDESCRICAO,
              &nRegPaises);
            }
            break;
            case ID_FRMCADPAISES_BTNPROXIMO:
            {
              frmCadastros_registroProximo(hwnd, lstRegPaises, 
              ID_FRMCADPAISES_EDTCODIGO, ID_FRMCADPAISES_EDTDESCRICAO,
              &nRegPaises);
            }
            break;
            case ID_FRMCADPAISES_BTNSALVAR:
            {
              if (frmCadastros_SalvarDados(hwnd, ID_FRMCADPAISES_EDTCODIGO, 
              ID_FRMCADPAISES_EDTDESCRICAO, ID_FRMCADPAISES_BTNNOVO,
              ID_FRMCADPAISES_BTNPESQUISAR, ID_FRMCADPAISES_BTNANTERIOR,
              ID_FRMCADPAISES_BTNPROXIMO, ID_FRMCADPAISES_BTNSALVAR,
              ID_FRMCADPAISES_BTNEXCLUIR, 
              frmCadPaises_ValidaDados(hwnd, TRUE),
              ConsSQL_Pais('S',
                Rotinas_retTexto(hwnd, ID_FRMCADPAISES_EDTCODIGO),""),
              ConsSQL_Pais('U',
                Rotinas_retTexto(hwnd, ID_FRMCADPAISES_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADPAISES_EDTDESCRICAO)),
              ConsSQL_Pais('I',
                Rotinas_retTexto(hwnd, ID_FRMCADPAISES_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADPAISES_EDTDESCRICAO)), TRUE))
              nRegPaises = 0;
            }
            break;
            case ID_FRMCADPAISES_BTNEXCLUIR:
            {
              if (frmCadastros_ExcluirDados(hwnd, ID_FRMCADPAISES_EDTCODIGO, 
              ID_FRMCADPAISES_EDTDESCRICAO, ID_FRMCADPAISES_BTNNOVO,
              ID_FRMCADPAISES_BTNPESQUISAR, ID_FRMCADPAISES_BTNANTERIOR,
              ID_FRMCADPAISES_BTNPROXIMO, ID_FRMCADPAISES_BTNSALVAR,
              ID_FRMCADPAISES_BTNEXCLUIR, 
              frmCadPaises_ValidaDados(hwnd, FALSE),
              ConsSQL_Pais('D',
                Rotinas_retTexto(hwnd, ID_FRMCADPAISES_EDTCODIGO),"")))
              nRegPaises = 0;
            }
            break;
            case ID_FRMCADPAISES_BTNLIMPAR:
            {
              frmCadastros_btnLimparClick(hwnd, ID_FRMCADPAISES_EDTCODIGO, 
              ID_FRMCADPAISES_EDTDESCRICAO, ID_FRMCADPAISES_BTNNOVO,
              ID_FRMCADPAISES_BTNPESQUISAR, ID_FRMCADPAISES_BTNANTERIOR,
              ID_FRMCADPAISES_BTNPROXIMO, ID_FRMCADPAISES_BTNSALVAR,
              ID_FRMCADPAISES_BTNEXCLUIR);
              nRegPaises = 0;
            }
            break;
            case ID_FRMCADPAISES_BTNFECHAR: 
              if (bAtivaPaises)   
                DestroyWindow(g_hTelaAtiva);                
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

BOOL frmCadPaises_ValidaDados(HWND hwnd, BOOL bTodosDados)
{
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMCADPAISES_EDTCODIGO), 
    Rotinas_lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADPAISES_EDTDESCRICAO), 
           Rotinas_lerStr(STR_PAISNINF)))
  		return FALSE;
  	}
  	return TRUE;
}
