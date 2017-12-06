#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "resource.h"
#include "Principal.h"
#include "Cadastros.h"
#include "CadAssuntos.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstRegAssuntos;
UINT nRegAssuntos;
BOOL bAtivaAssuntos;

LRESULT CALLBACK frmCadAssuntosProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {         
      case WM_CREATE:
      {
        if (!frmCadastros_Criar(hwnd, g_sFRMCadAssuntos, 
                (DLGPROC)frmCadAssuntosProc))
          return FALSE;          

        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO, 10);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADASSUNTOS_EDTDESCRICAO, 30);          
        nRegAssuntos = 0;
      }
      break;
      case WM_MDIACTIVATE:
      {
        bAtivaAssuntos = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMCADASSUNTOS_EDTCODIGO, 0, CM_CAD_ASSUNTOS);
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
         frmCadastros_Fechar(hwnd, 0, CM_CAD_ASSUNTOS);
      }  
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {  /*
            case ID_FRMCADASSUNTOS_EDTCODIGO:
            {            
               if (HIWORD(wParam) == WM_CHAR)
               {
                 //SetWindowText((HWND)lParam, "olca");
                 //SendMessage(hwnd, WM_MDIACTIVATE, 0, 0);
                 SetFocus(hwnd);
               } 
            }
            break;*/
            case ID_FRMCADASSUNTOS_BTNNOVO:
            {
              frmCadastros_btnNovoClick(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO, 
              ID_FRMCADASSUNTOS_EDTDESCRICAO, ID_FRMCADASSUNTOS_BTNNOVO,
              ID_FRMCADASSUNTOS_BTNPESQUISAR, ID_FRMCADASSUNTOS_BTNANTERIOR,
              ID_FRMCADASSUNTOS_BTNPROXIMO, ID_FRMCADASSUNTOS_BTNSALVAR,
              ID_FRMCADASSUNTOS_BTNEXCLUIR);

              frmCadastros_NovoDado(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO, 
              ID_FRMCADASSUNTOS_EDTDESCRICAO, ConsSQL_Assunto('N',
              Rotinas_retTexto(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO),""));
            }
            break;
            case ID_FRMCADASSUNTOS_BTNPESQUISAR:
            {
              frmCadastros_PesquisarDados(hwnd, &lstRegAssuntos, 
              ID_FRMCADASSUNTOS_EDTCODIGO, ID_FRMCADASSUNTOS_EDTDESCRICAO,
              ID_FRMCADASSUNTOS_BTNPESQUISAR, ID_FRMCADASSUNTOS_BTNANTERIOR,
              ID_FRMCADASSUNTOS_BTNPROXIMO, ID_FRMCADASSUNTOS_BTNSALVAR,
              ID_FRMCADASSUNTOS_BTNEXCLUIR, ConsSQL_Assunto('S',
              Rotinas_retTexto(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO),""),
              Rotinas_lerStr(STR_ASSNENC));
            }
            break;
            case ID_FRMCADASSUNTOS_BTNANTERIOR:
            {
              frmCadastros_registroAnterior(hwnd, lstRegAssuntos, 
              ID_FRMCADASSUNTOS_EDTCODIGO, ID_FRMCADASSUNTOS_EDTDESCRICAO,
              &nRegAssuntos);
            }
            break;
            case ID_FRMCADASSUNTOS_BTNPROXIMO:
            {
              frmCadastros_registroProximo(hwnd, lstRegAssuntos, 
              ID_FRMCADASSUNTOS_EDTCODIGO, ID_FRMCADASSUNTOS_EDTDESCRICAO,
              &nRegAssuntos);
            }
            break;
            case ID_FRMCADASSUNTOS_BTNSALVAR:
            {
              if (frmCadastros_SalvarDados(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO, 
              ID_FRMCADASSUNTOS_EDTDESCRICAO, ID_FRMCADASSUNTOS_BTNNOVO,
              ID_FRMCADASSUNTOS_BTNPESQUISAR, ID_FRMCADASSUNTOS_BTNANTERIOR,
              ID_FRMCADASSUNTOS_BTNPROXIMO, ID_FRMCADASSUNTOS_BTNSALVAR,
              ID_FRMCADASSUNTOS_BTNEXCLUIR, 
              frmCadAssuntos_ValidaDados(hwnd, TRUE),
              ConsSQL_Assunto('S',
                Rotinas_retTexto(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO),""),
              ConsSQL_Assunto('U',
                Rotinas_retTexto(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADASSUNTOS_EDTDESCRICAO)),
              ConsSQL_Assunto('I',
                Rotinas_retTexto(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADASSUNTOS_EDTDESCRICAO)), TRUE))
              nRegAssuntos = 0;
            }
            break;
            case ID_FRMCADASSUNTOS_BTNEXCLUIR:
            {
              if (frmCadastros_ExcluirDados(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO, 
              ID_FRMCADASSUNTOS_EDTDESCRICAO, ID_FRMCADASSUNTOS_BTNNOVO,
              ID_FRMCADASSUNTOS_BTNPESQUISAR, ID_FRMCADASSUNTOS_BTNANTERIOR,
              ID_FRMCADASSUNTOS_BTNPROXIMO, ID_FRMCADASSUNTOS_BTNSALVAR,
              ID_FRMCADASSUNTOS_BTNEXCLUIR, 
              frmCadAssuntos_ValidaDados(hwnd, FALSE),
              ConsSQL_Assunto('D',
                Rotinas_retTexto(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO),"")))
              nRegAssuntos = 0;
            }
            break;
            case ID_FRMCADASSUNTOS_BTNLIMPAR:
            {
              frmCadastros_btnLimparClick(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO, 
              ID_FRMCADASSUNTOS_EDTDESCRICAO, ID_FRMCADASSUNTOS_BTNNOVO,
              ID_FRMCADASSUNTOS_BTNPESQUISAR, ID_FRMCADASSUNTOS_BTNANTERIOR,
              ID_FRMCADASSUNTOS_BTNPROXIMO, ID_FRMCADASSUNTOS_BTNSALVAR,
              ID_FRMCADASSUNTOS_BTNEXCLUIR);
              nRegAssuntos = 0;
            }
            break;
            case ID_FRMCADASSUNTOS_BTNFECHAR: 
              if (bAtivaAssuntos)
                DestroyWindow(g_hTelaAtiva);                
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

/*
BOOL frmCadAssuntos_Criar(HWND hwnd)
{ 
Rotinas_criaRotulo(hwnd, "Código:", ID_FRMCADASSUNTOS_LABCODIGO, 8, 8, 56);
Rotinas_criaEdit(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO, 
    8, 24, 128, TRUE, 10, FALSE, TRUE);				 
Rotinas_criaRotulo(hwnd, "Assunto:", ID_FRMCADASSUNTOS_LABDESCRICAO, 8, 48, 64);
Rotinas_criaEdit(hwnd, ID_FRMCADASSUNTOS_EDTDESCRICAO, 
    8, 64, 232, FALSE, 50, FALSE, FALSE);         
Rotinas_criaBotao(hwnd, "&Novo", ID_FRMCADASSUNTOS_BTNNOVO, 152, 24, TRUE);
Rotinas_criaBotao(hwnd, "&Pesquisar", ID_FRMCADASSUNTOS_BTNPESQUISAR, 
    256, 8, TRUE);
Rotinas_criaBotao(hwnd, "&Anterior", ID_FRMCADASSUNTOS_BTNANTERIOR, 
    256, 40, FALSE);
Rotinas_criaBotao(hwnd, "Próxi&mo", ID_FRMCADASSUNTOS_BTNPROXIMO,
    256, 72, FALSE);
Rotinas_criaBotao(hwnd, "&Salvar", ID_FRMCADASSUNTOS_BTNSALVAR, 16, 104, FALSE);
Rotinas_criaBotao(hwnd, "&Excluir", ID_FRMCADASSUNTOS_BTNEXCLUIR, 
    96, 104, FALSE);
Rotinas_criaBotao(hwnd, "&Limpar", ID_FRMCADASSUNTOS_BTNLIMPAR, 176, 104, TRUE);
Rotinas_criaBotao(hwnd, "&Fechar", ID_FRMCADASSUNTOS_BTNFECHAR, 256, 104, TRUE);

return TRUE;
}
*/

BOOL frmCadAssuntos_ValidaDados(HWND hwnd, BOOL bTodosDados)
{
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMCADASSUNTOS_EDTCODIGO), 
    Rotinas_lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADASSUNTOS_EDTDESCRICAO), 
           Rotinas_lerStr(STR_ASSNINF)))
  		return FALSE;
  	}
  	return TRUE;
}

