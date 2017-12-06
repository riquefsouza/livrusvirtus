#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "resource.h"
#include "Principal.h"
#include "Cadastros.h"
#include "CadEditoras.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstRegEditoras;
UINT nRegEditoras;
BOOL bAtivaEditoras;

LRESULT CALLBACK frmCadEditorasProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {         
      case WM_CREATE:
      {
        if (!frmCadastros_Criar(hwnd, g_sFRMCadEditoras, 
                (DLGPROC)frmCadEditorasProc))
          return FALSE;          

        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADEDITORAS_EDTCODIGO, 10);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADEDITORAS_EDTDESCRICAO, 50);          
        nRegEditoras = 0;
      }
      break;
      case WM_MDIACTIVATE:
      {
        bAtivaEditoras = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMCADEDITORAS_EDTCODIGO, 0, CM_CAD_EDITORAS);
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
         frmCadastros_Fechar(hwnd, 0, CM_CAD_EDITORAS);
      }  
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {  
            case ID_FRMCADEDITORAS_BTNNOVO:
            {
              frmCadastros_btnNovoClick(hwnd, ID_FRMCADEDITORAS_EDTCODIGO, 
              ID_FRMCADEDITORAS_EDTDESCRICAO, ID_FRMCADEDITORAS_BTNNOVO,
              ID_FRMCADEDITORAS_BTNPESQUISAR, ID_FRMCADEDITORAS_BTNANTERIOR,
              ID_FRMCADEDITORAS_BTNPROXIMO, ID_FRMCADEDITORAS_BTNSALVAR,
              ID_FRMCADEDITORAS_BTNEXCLUIR);

              frmCadastros_NovoDado(hwnd, ID_FRMCADEDITORAS_EDTCODIGO, 
              ID_FRMCADEDITORAS_EDTDESCRICAO, ConsSQL_Editora('N',
              Rotinas_retTexto(hwnd, ID_FRMCADEDITORAS_EDTCODIGO),""));
            }
            break;
            case ID_FRMCADEDITORAS_BTNPESQUISAR:
            {
              frmCadastros_PesquisarDados(hwnd, &lstRegEditoras, 
              ID_FRMCADEDITORAS_EDTCODIGO, ID_FRMCADEDITORAS_EDTDESCRICAO,
              ID_FRMCADEDITORAS_BTNPESQUISAR, ID_FRMCADEDITORAS_BTNANTERIOR,
              ID_FRMCADEDITORAS_BTNPROXIMO, ID_FRMCADEDITORAS_BTNSALVAR,
              ID_FRMCADEDITORAS_BTNEXCLUIR, ConsSQL_Editora('S',
              Rotinas_retTexto(hwnd, ID_FRMCADEDITORAS_EDTCODIGO),""),
              Rotinas_lerStr(STR_EDTNENC));
            }
            break;
            case ID_FRMCADEDITORAS_BTNANTERIOR:
            {
              frmCadastros_registroAnterior(hwnd, lstRegEditoras, 
              ID_FRMCADEDITORAS_EDTCODIGO, ID_FRMCADEDITORAS_EDTDESCRICAO,
              &nRegEditoras);
            }
            break;
            case ID_FRMCADEDITORAS_BTNPROXIMO:
            {
              frmCadastros_registroProximo(hwnd, lstRegEditoras, 
              ID_FRMCADEDITORAS_EDTCODIGO, ID_FRMCADEDITORAS_EDTDESCRICAO,
              &nRegEditoras);
            }
            break;
            case ID_FRMCADEDITORAS_BTNSALVAR:
            {
              if (frmCadastros_SalvarDados(hwnd, ID_FRMCADEDITORAS_EDTCODIGO, 
              ID_FRMCADEDITORAS_EDTDESCRICAO, ID_FRMCADEDITORAS_BTNNOVO,
              ID_FRMCADEDITORAS_BTNPESQUISAR, ID_FRMCADEDITORAS_BTNANTERIOR,
              ID_FRMCADEDITORAS_BTNPROXIMO, ID_FRMCADEDITORAS_BTNSALVAR,
              ID_FRMCADEDITORAS_BTNEXCLUIR, 
              frmCadEditoras_ValidaDados(hwnd, TRUE),
              ConsSQL_Editora('S',
                Rotinas_retTexto(hwnd, ID_FRMCADEDITORAS_EDTCODIGO),""),
              ConsSQL_Editora('U',
                Rotinas_retTexto(hwnd, ID_FRMCADEDITORAS_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADEDITORAS_EDTDESCRICAO)),
              ConsSQL_Editora('I',
                Rotinas_retTexto(hwnd, ID_FRMCADEDITORAS_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADEDITORAS_EDTDESCRICAO)), TRUE))
              nRegEditoras = 0;
            }
            break;
            case ID_FRMCADEDITORAS_BTNEXCLUIR:
            {
              if (frmCadastros_ExcluirDados(hwnd, ID_FRMCADEDITORAS_EDTCODIGO, 
              ID_FRMCADEDITORAS_EDTDESCRICAO, ID_FRMCADEDITORAS_BTNNOVO,
              ID_FRMCADEDITORAS_BTNPESQUISAR, ID_FRMCADEDITORAS_BTNANTERIOR,
              ID_FRMCADEDITORAS_BTNPROXIMO, ID_FRMCADEDITORAS_BTNSALVAR,
              ID_FRMCADEDITORAS_BTNEXCLUIR, 
              frmCadEditoras_ValidaDados(hwnd, FALSE),
              ConsSQL_Editora('D',
                Rotinas_retTexto(hwnd, ID_FRMCADEDITORAS_EDTCODIGO),"")))
              nRegEditoras = 0;
            }
            break;
            case ID_FRMCADEDITORAS_BTNLIMPAR:
            {
              frmCadastros_btnLimparClick(hwnd, ID_FRMCADEDITORAS_EDTCODIGO, 
              ID_FRMCADEDITORAS_EDTDESCRICAO, ID_FRMCADEDITORAS_BTNNOVO,
              ID_FRMCADEDITORAS_BTNPESQUISAR, ID_FRMCADEDITORAS_BTNANTERIOR,
              ID_FRMCADEDITORAS_BTNPROXIMO, ID_FRMCADEDITORAS_BTNSALVAR,
              ID_FRMCADEDITORAS_BTNEXCLUIR);
              nRegEditoras = 0;
            }
            break;
            case ID_FRMCADEDITORAS_BTNFECHAR: 
              if (bAtivaEditoras)   
                DestroyWindow(g_hTelaAtiva);                
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

BOOL frmCadEditoras_ValidaDados(HWND hwnd, BOOL bTodosDados)
{
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMCADEDITORAS_EDTCODIGO), 
    Rotinas_lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADEDITORAS_EDTDESCRICAO), 
           Rotinas_lerStr(STR_EDTNINF)))
  		return FALSE;
  	}
  	return TRUE;
}
