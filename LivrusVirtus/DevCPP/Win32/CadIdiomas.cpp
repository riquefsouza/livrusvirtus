#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "resource.h"
#include "Principal.h"
#include "Cadastros.h"
#include "CadIdiomas.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstRegIdiomas;
UINT nRegIdiomas;
BOOL bAtivaIdiomas;

LRESULT CALLBACK frmCadIdiomasProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {         
      case WM_CREATE:
      {
        if (!frmCadastros_Criar(hwnd, g_sFRMCadIdiomas, 
                (DLGPROC)frmCadIdiomasProc))
          return FALSE;          

        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO, 10);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADIDIOMAS_EDTDESCRICAO, 30);          
        nRegIdiomas = 0;
      }
      break;
      case WM_MDIACTIVATE:
      {
        bAtivaIdiomas = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMCADIDIOMAS_EDTCODIGO, 0, CM_CAD_IDIOMAS);
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
         frmCadastros_Fechar(hwnd, 0, CM_CAD_IDIOMAS);
      }  
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {  
            case ID_FRMCADIDIOMAS_BTNNOVO:
            {
              frmCadastros_btnNovoClick(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO, 
              ID_FRMCADIDIOMAS_EDTDESCRICAO, ID_FRMCADIDIOMAS_BTNNOVO,
              ID_FRMCADIDIOMAS_BTNPESQUISAR, ID_FRMCADIDIOMAS_BTNANTERIOR,
              ID_FRMCADIDIOMAS_BTNPROXIMO, ID_FRMCADIDIOMAS_BTNSALVAR,
              ID_FRMCADIDIOMAS_BTNEXCLUIR);

              frmCadastros_NovoDado(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO, 
              ID_FRMCADIDIOMAS_EDTDESCRICAO, ConsSQL_Idioma('N',
              Rotinas_retTexto(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO),""));
            }
            break;
            case ID_FRMCADIDIOMAS_BTNPESQUISAR:
            {
              frmCadastros_PesquisarDados(hwnd, &lstRegIdiomas, 
              ID_FRMCADIDIOMAS_EDTCODIGO, ID_FRMCADIDIOMAS_EDTDESCRICAO,
              ID_FRMCADIDIOMAS_BTNPESQUISAR, ID_FRMCADIDIOMAS_BTNANTERIOR,
              ID_FRMCADIDIOMAS_BTNPROXIMO, ID_FRMCADIDIOMAS_BTNSALVAR,
              ID_FRMCADIDIOMAS_BTNEXCLUIR, ConsSQL_Idioma('S',
              Rotinas_retTexto(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO),""),
              Rotinas_lerStr(STR_IDINENC));
            }
            break;
            case ID_FRMCADIDIOMAS_BTNANTERIOR:
            {
              frmCadastros_registroAnterior(hwnd, lstRegIdiomas, 
              ID_FRMCADIDIOMAS_EDTCODIGO, ID_FRMCADIDIOMAS_EDTDESCRICAO,
              &nRegIdiomas);
            }
            break;
            case ID_FRMCADIDIOMAS_BTNPROXIMO:
            {
              frmCadastros_registroProximo(hwnd, lstRegIdiomas, 
              ID_FRMCADIDIOMAS_EDTCODIGO, ID_FRMCADIDIOMAS_EDTDESCRICAO,
              &nRegIdiomas);
            }
            break;
            case ID_FRMCADIDIOMAS_BTNSALVAR:
            {
              if (frmCadastros_SalvarDados(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO, 
              ID_FRMCADIDIOMAS_EDTDESCRICAO, ID_FRMCADIDIOMAS_BTNNOVO,
              ID_FRMCADIDIOMAS_BTNPESQUISAR, ID_FRMCADIDIOMAS_BTNANTERIOR,
              ID_FRMCADIDIOMAS_BTNPROXIMO, ID_FRMCADIDIOMAS_BTNSALVAR,
              ID_FRMCADIDIOMAS_BTNEXCLUIR, 
              frmCadIdiomas_ValidaDados(hwnd, TRUE),
              ConsSQL_Idioma('S',
                Rotinas_retTexto(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO),""),
              ConsSQL_Idioma('U',
                Rotinas_retTexto(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADIDIOMAS_EDTDESCRICAO)),
              ConsSQL_Idioma('I',
                Rotinas_retTexto(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADIDIOMAS_EDTDESCRICAO)), TRUE))
              nRegIdiomas = 0;
            }
            break;
            case ID_FRMCADIDIOMAS_BTNEXCLUIR:
            {
              if (frmCadastros_ExcluirDados(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO, 
              ID_FRMCADIDIOMAS_EDTDESCRICAO, ID_FRMCADIDIOMAS_BTNNOVO,
              ID_FRMCADIDIOMAS_BTNPESQUISAR, ID_FRMCADIDIOMAS_BTNANTERIOR,
              ID_FRMCADIDIOMAS_BTNPROXIMO, ID_FRMCADIDIOMAS_BTNSALVAR,
              ID_FRMCADIDIOMAS_BTNEXCLUIR, 
              frmCadIdiomas_ValidaDados(hwnd, FALSE),
              ConsSQL_Idioma('D',
                Rotinas_retTexto(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO),"")))
              nRegIdiomas = 0;
            }
            break;
            case ID_FRMCADIDIOMAS_BTNLIMPAR:
            {
              frmCadastros_btnLimparClick(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO, 
              ID_FRMCADIDIOMAS_EDTDESCRICAO, ID_FRMCADIDIOMAS_BTNNOVO,
              ID_FRMCADIDIOMAS_BTNPESQUISAR, ID_FRMCADIDIOMAS_BTNANTERIOR,
              ID_FRMCADIDIOMAS_BTNPROXIMO, ID_FRMCADIDIOMAS_BTNSALVAR,
              ID_FRMCADIDIOMAS_BTNEXCLUIR);
              nRegIdiomas = 0;
            }
            break;
            case ID_FRMCADIDIOMAS_BTNFECHAR: 
              if (bAtivaIdiomas)   
                DestroyWindow(g_hTelaAtiva);                
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

BOOL frmCadIdiomas_ValidaDados(HWND hwnd, BOOL bTodosDados)
{
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMCADIDIOMAS_EDTCODIGO), 
    Rotinas_lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADIDIOMAS_EDTDESCRICAO), 
           Rotinas_lerStr(STR_IDININF)))
  		return FALSE;
  	}
  	return TRUE;
}
