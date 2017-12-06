#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "resource.h"
#include "Principal.h"
#include "Cadastros.h"
#include "CadProfissoes.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstRegProfissoes;
UINT nRegProfissoes;
BOOL bAtivaProfissoes;

LRESULT CALLBACK frmCadProfissoesProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {         
      case WM_CREATE:
      {
        if (!frmCadastros_Criar(hwnd, g_sFRMCadProfissoes, 
                (DLGPROC)frmCadProfissoesProc))
          return FALSE;          

        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO, 10);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADPROFISSOES_EDTDESCRICAO, 30);          
        nRegProfissoes = 0;
      }
      break;
      case WM_MDIACTIVATE:
      {
        bAtivaProfissoes = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMCADPROFISSOES_EDTCODIGO, 0, CM_CAD_PROFISSOES);
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
         frmCadastros_Fechar(hwnd, 0, CM_CAD_PROFISSOES);
      }  
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {  
            case ID_FRMCADPROFISSOES_BTNNOVO:
            {
              frmCadastros_btnNovoClick(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO, 
              ID_FRMCADPROFISSOES_EDTDESCRICAO, ID_FRMCADPROFISSOES_BTNNOVO,
              ID_FRMCADPROFISSOES_BTNPESQUISAR, ID_FRMCADPROFISSOES_BTNANTERIOR,
              ID_FRMCADPROFISSOES_BTNPROXIMO, ID_FRMCADPROFISSOES_BTNSALVAR,
              ID_FRMCADPROFISSOES_BTNEXCLUIR);

              frmCadastros_NovoDado(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO, 
              ID_FRMCADPROFISSOES_EDTDESCRICAO, ConsSQL_Profissao('N',
              Rotinas_retTexto(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO),""));
            }
            break;
            case ID_FRMCADPROFISSOES_BTNPESQUISAR:
            {
              frmCadastros_PesquisarDados(hwnd, &lstRegProfissoes, 
              ID_FRMCADPROFISSOES_EDTCODIGO, ID_FRMCADPROFISSOES_EDTDESCRICAO,
              ID_FRMCADPROFISSOES_BTNPESQUISAR, ID_FRMCADPROFISSOES_BTNANTERIOR,
              ID_FRMCADPROFISSOES_BTNPROXIMO, ID_FRMCADPROFISSOES_BTNSALVAR,
              ID_FRMCADPROFISSOES_BTNEXCLUIR, ConsSQL_Profissao('S',
              Rotinas_retTexto(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO),""),
              Rotinas_lerStr(STR_PROFNENC));
            }
            break;
            case ID_FRMCADPROFISSOES_BTNANTERIOR:
            {
              frmCadastros_registroAnterior(hwnd, lstRegProfissoes, 
              ID_FRMCADPROFISSOES_EDTCODIGO, ID_FRMCADPROFISSOES_EDTDESCRICAO,
              &nRegProfissoes);
            }
            break;
            case ID_FRMCADPROFISSOES_BTNPROXIMO:
            {
              frmCadastros_registroProximo(hwnd, lstRegProfissoes, 
              ID_FRMCADPROFISSOES_EDTCODIGO, ID_FRMCADPROFISSOES_EDTDESCRICAO,
              &nRegProfissoes);
            }
            break;
            case ID_FRMCADPROFISSOES_BTNSALVAR:
            {
              if (frmCadastros_SalvarDados(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO, 
              ID_FRMCADPROFISSOES_EDTDESCRICAO, ID_FRMCADPROFISSOES_BTNNOVO,
              ID_FRMCADPROFISSOES_BTNPESQUISAR, ID_FRMCADPROFISSOES_BTNANTERIOR,
              ID_FRMCADPROFISSOES_BTNPROXIMO, ID_FRMCADPROFISSOES_BTNSALVAR,
              ID_FRMCADPROFISSOES_BTNEXCLUIR, 
              frmCadProfissoes_ValidaDados(hwnd, TRUE),
              ConsSQL_Profissao('S',
                Rotinas_retTexto(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO),""),
              ConsSQL_Profissao('U',
                Rotinas_retTexto(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADPROFISSOES_EDTDESCRICAO)),
              ConsSQL_Profissao('I',
                Rotinas_retTexto(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADPROFISSOES_EDTDESCRICAO)), TRUE))
              nRegProfissoes = 0;
            }
            break;
            case ID_FRMCADPROFISSOES_BTNEXCLUIR:
            {
              if (frmCadastros_ExcluirDados(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO, 
              ID_FRMCADPROFISSOES_EDTDESCRICAO, ID_FRMCADPROFISSOES_BTNNOVO,
              ID_FRMCADPROFISSOES_BTNPESQUISAR, ID_FRMCADPROFISSOES_BTNANTERIOR,
              ID_FRMCADPROFISSOES_BTNPROXIMO, ID_FRMCADPROFISSOES_BTNSALVAR,
              ID_FRMCADPROFISSOES_BTNEXCLUIR, 
              frmCadProfissoes_ValidaDados(hwnd, FALSE),
              ConsSQL_Profissao('D',
                Rotinas_retTexto(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO),"")))
              nRegProfissoes = 0;
            }
            break;
            case ID_FRMCADPROFISSOES_BTNLIMPAR:
            {
              frmCadastros_btnLimparClick(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO, 
              ID_FRMCADPROFISSOES_EDTDESCRICAO, ID_FRMCADPROFISSOES_BTNNOVO,
              ID_FRMCADPROFISSOES_BTNPESQUISAR, ID_FRMCADPROFISSOES_BTNANTERIOR,
              ID_FRMCADPROFISSOES_BTNPROXIMO, ID_FRMCADPROFISSOES_BTNSALVAR,
              ID_FRMCADPROFISSOES_BTNEXCLUIR);
              nRegProfissoes = 0;
            }
            break;
            case ID_FRMCADPROFISSOES_BTNFECHAR: 
              if (bAtivaProfissoes)   
                DestroyWindow(g_hTelaAtiva);                
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

BOOL frmCadProfissoes_ValidaDados(HWND hwnd, BOOL bTodosDados)
{
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMCADPROFISSOES_EDTCODIGO), 
    Rotinas_lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADPROFISSOES_EDTDESCRICAO), 
           Rotinas_lerStr(STR_PROFNINF)))
  		return FALSE;
  	}
  	return TRUE;
}
