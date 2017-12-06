#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "resource.h"
#include "Principal.h"
#include "Cadastros.h"
#include "CadAutores.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstRegAutores;
UINT nRegAutores;
BOOL bAtivaAutores;

LRESULT CALLBACK frmCadAutoresProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {         
      case WM_CREATE:
      {
        if (!frmCadastros_Criar(hwnd, g_sFRMCadAutores, 
                (DLGPROC)frmCadAutoresProc))
          return FALSE;          

        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADAUTORES_EDTCODIGO, 10);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADAUTORES_EDTDESCRICAO, 30);          
        nRegAutores = 0;
      }
      break;
      case WM_MDIACTIVATE:
      {
        bAtivaAutores = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMCADAUTORES_EDTCODIGO, 0, CM_CAD_AUTORES);
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
         frmCadastros_Fechar(hwnd, 0, CM_CAD_AUTORES);
      }  
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {  
            case ID_FRMCADAUTORES_BTNNOVO:
            {
              frmCadastros_btnNovoClick(hwnd, ID_FRMCADAUTORES_EDTCODIGO, 
              ID_FRMCADAUTORES_EDTDESCRICAO, ID_FRMCADAUTORES_BTNNOVO,
              ID_FRMCADAUTORES_BTNPESQUISAR, ID_FRMCADAUTORES_BTNANTERIOR,
              ID_FRMCADAUTORES_BTNPROXIMO, ID_FRMCADAUTORES_BTNSALVAR,
              ID_FRMCADAUTORES_BTNEXCLUIR);

              frmCadastros_NovoDado(hwnd, ID_FRMCADAUTORES_EDTCODIGO, 
              ID_FRMCADAUTORES_EDTDESCRICAO, ConsSQL_Autor('N',
              Rotinas_retTexto(hwnd, ID_FRMCADAUTORES_EDTCODIGO),""));
            }
            break;
            case ID_FRMCADAUTORES_BTNPESQUISAR:
            {
              frmCadastros_PesquisarDados(hwnd, &lstRegAutores, 
              ID_FRMCADAUTORES_EDTCODIGO, ID_FRMCADAUTORES_EDTDESCRICAO,
              ID_FRMCADAUTORES_BTNPESQUISAR, ID_FRMCADAUTORES_BTNANTERIOR,
              ID_FRMCADAUTORES_BTNPROXIMO, ID_FRMCADAUTORES_BTNSALVAR,
              ID_FRMCADAUTORES_BTNEXCLUIR, ConsSQL_Autor('S',
              Rotinas_retTexto(hwnd, ID_FRMCADAUTORES_EDTCODIGO),""),
              Rotinas_lerStr(STR_AUTNENC));
            }
            break;
            case ID_FRMCADAUTORES_BTNANTERIOR:
            {
              frmCadastros_registroAnterior(hwnd, lstRegAutores, 
              ID_FRMCADAUTORES_EDTCODIGO, ID_FRMCADAUTORES_EDTDESCRICAO,
              &nRegAutores);
            }
            break;
            case ID_FRMCADAUTORES_BTNPROXIMO:
            {
              frmCadastros_registroProximo(hwnd, lstRegAutores, 
              ID_FRMCADAUTORES_EDTCODIGO, ID_FRMCADAUTORES_EDTDESCRICAO,
              &nRegAutores);
            }
            break;
            case ID_FRMCADAUTORES_BTNSALVAR:
            {
              if (frmCadastros_SalvarDados(hwnd, ID_FRMCADAUTORES_EDTCODIGO, 
              ID_FRMCADAUTORES_EDTDESCRICAO, ID_FRMCADAUTORES_BTNNOVO,
              ID_FRMCADAUTORES_BTNPESQUISAR, ID_FRMCADAUTORES_BTNANTERIOR,
              ID_FRMCADAUTORES_BTNPROXIMO, ID_FRMCADAUTORES_BTNSALVAR,
              ID_FRMCADAUTORES_BTNEXCLUIR, 
              frmCadAutores_ValidaDados(hwnd, TRUE),
              ConsSQL_Autor('S',
                Rotinas_retTexto(hwnd, ID_FRMCADAUTORES_EDTCODIGO),""),
              ConsSQL_Autor('U',
                Rotinas_retTexto(hwnd, ID_FRMCADAUTORES_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADAUTORES_EDTDESCRICAO)),
              ConsSQL_Autor('I',
                Rotinas_retTexto(hwnd, ID_FRMCADAUTORES_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADAUTORES_EDTDESCRICAO)), TRUE))
              nRegAutores = 0;
            }
            break;
            case ID_FRMCADAUTORES_BTNEXCLUIR:
            {
              if (frmCadastros_ExcluirDados(hwnd, ID_FRMCADAUTORES_EDTCODIGO, 
              ID_FRMCADAUTORES_EDTDESCRICAO, ID_FRMCADAUTORES_BTNNOVO,
              ID_FRMCADAUTORES_BTNPESQUISAR, ID_FRMCADAUTORES_BTNANTERIOR,
              ID_FRMCADAUTORES_BTNPROXIMO, ID_FRMCADAUTORES_BTNSALVAR,
              ID_FRMCADAUTORES_BTNEXCLUIR, 
              frmCadAutores_ValidaDados(hwnd, FALSE),
              ConsSQL_Autor('D',
                Rotinas_retTexto(hwnd, ID_FRMCADAUTORES_EDTCODIGO),"")))
              nRegAutores = 0;
            }
            break;
            case ID_FRMCADAUTORES_BTNLIMPAR:
            {
              frmCadastros_btnLimparClick(hwnd, ID_FRMCADAUTORES_EDTCODIGO, 
              ID_FRMCADAUTORES_EDTDESCRICAO, ID_FRMCADAUTORES_BTNNOVO,
              ID_FRMCADAUTORES_BTNPESQUISAR, ID_FRMCADAUTORES_BTNANTERIOR,
              ID_FRMCADAUTORES_BTNPROXIMO, ID_FRMCADAUTORES_BTNSALVAR,
              ID_FRMCADAUTORES_BTNEXCLUIR);
              nRegAutores = 0;
            }
            break;
            case ID_FRMCADAUTORES_BTNFECHAR: 
              if (bAtivaAutores)
                DestroyWindow(g_hTelaAtiva);
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

BOOL frmCadAutores_ValidaDados(HWND hwnd, BOOL bTodosDados)
{
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMCADAUTORES_EDTCODIGO), 
    Rotinas_lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADAUTORES_EDTDESCRICAO), 
           Rotinas_lerStr(STR_AUTNINF)))
  		return FALSE;
  	}
  	return TRUE;
}
