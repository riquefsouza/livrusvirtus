#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "resource.h"
#include "Principal.h"
#include "Cadastros.h"
#include "CadEnderecos.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstRegEnderecos;
UINT nRegEnderecos;
BOOL bAtivaEnderecos;

LRESULT CALLBACK frmCadEnderecosProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {         
      case WM_CREATE:
      {
        if (!frmCadastros_Criar(hwnd, g_sFRMCadEnderecos, 
                (DLGPROC)frmCadEnderecosProc))
          return FALSE;          

        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADENDERECOS_EDTCODIGO, 10);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADENDERECOS_EDTLOGRADOURO, 40);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADENDERECOS_EDTBAIRRO, 15);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADENDERECOS_EDTCEP, 8);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADENDERECOS_EDTCIDADE, 30);
        frmCadEnderecos_AdicionaCombo(hwnd);
        nRegEnderecos = 0;
      }
      break;
      case WM_MDIACTIVATE:
      {
        bAtivaEnderecos = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMCADENDERECOS_EDTCODIGO, 0, CM_CAD_ENDERECOS);                          
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
         frmCadastros_Fechar(hwnd, 0, CM_CAD_ENDERECOS);
      }  
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {  
            case ID_FRMCADENDERECOS_BTNNOVO:
            {
              frmCadastros_btnNovoClick(hwnd, ID_FRMCADENDERECOS_EDTCODIGO, 
              ID_FRMCADENDERECOS_EDTLOGRADOURO, ID_FRMCADENDERECOS_BTNNOVO,
              ID_FRMCADENDERECOS_BTNPESQUISAR, ID_FRMCADENDERECOS_BTNANTERIOR,
              ID_FRMCADENDERECOS_BTNPROXIMO, ID_FRMCADENDERECOS_BTNSALVAR,
              ID_FRMCADENDERECOS_BTNEXCLUIR);

              frmCadEnderecos_InformaLimpaDados(hwnd, NULL, 0, FALSE);
              frmCadEnderecos_HabilitaDados(hwnd, TRUE);	

              frmCadastros_NovoDado(hwnd, ID_FRMCADENDERECOS_EDTCODIGO, 
              ID_FRMCADENDERECOS_EDTLOGRADOURO, ConsSQL_Endereco('N',
              Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCODIGO),
              "","","","",""));
            }
            break;
            case ID_FRMCADENDERECOS_BTNPESQUISAR:
            {
              if (frmCadastros_PesquisarDados(hwnd, &lstRegEnderecos, 
              ID_FRMCADENDERECOS_EDTCODIGO, ID_FRMCADENDERECOS_EDTLOGRADOURO,
              ID_FRMCADENDERECOS_BTNPESQUISAR, ID_FRMCADENDERECOS_BTNANTERIOR,
              ID_FRMCADENDERECOS_BTNPROXIMO, ID_FRMCADENDERECOS_BTNSALVAR,
              ID_FRMCADENDERECOS_BTNEXCLUIR, ConsSQL_Endereco('S',
              Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCODIGO),
              "","","","",""),Rotinas_lerStr(STR_ENDNENC))) {
                frmCadEnderecos_InformaLimpaDados(hwnd,lstRegEnderecos,0, TRUE);
                frmCadEnderecos_HabilitaDados(hwnd, TRUE);	
              }
            }
            break;
            case ID_FRMCADENDERECOS_BTNANTERIOR:
            {
              if (frmCadastros_registroAnterior(hwnd, lstRegEnderecos, 
              ID_FRMCADENDERECOS_EDTCODIGO, ID_FRMCADENDERECOS_EDTLOGRADOURO,
              &nRegEnderecos)) {
                frmCadEnderecos_InformaLimpaDados(hwnd,lstRegEnderecos,
                  nRegEnderecos, TRUE);              
              }  
            }
            break;
            case ID_FRMCADENDERECOS_BTNPROXIMO:
            {
              if (frmCadastros_registroProximo(hwnd, lstRegEnderecos, 
              ID_FRMCADENDERECOS_EDTCODIGO, ID_FRMCADENDERECOS_EDTLOGRADOURO,
              &nRegEnderecos)) {
                frmCadEnderecos_InformaLimpaDados(hwnd,lstRegEnderecos,
                  nRegEnderecos, TRUE);              
              }  
            }
            break;
            case ID_FRMCADENDERECOS_BTNSALVAR:
            {
              if (frmCadastros_SalvarDados(hwnd, ID_FRMCADENDERECOS_EDTCODIGO, 
              ID_FRMCADENDERECOS_EDTLOGRADOURO, ID_FRMCADENDERECOS_BTNNOVO,
              ID_FRMCADENDERECOS_BTNPESQUISAR, ID_FRMCADENDERECOS_BTNANTERIOR,
              ID_FRMCADENDERECOS_BTNPROXIMO, ID_FRMCADENDERECOS_BTNSALVAR,
              ID_FRMCADENDERECOS_BTNEXCLUIR, 
              frmCadEnderecos_ValidaDados(hwnd, TRUE),
              ConsSQL_Endereco('S',
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCODIGO),
                "","","","",""),
              ConsSQL_Endereco('U',
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTLOGRADOURO),
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTBAIRRO),
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCEP),
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCIDADE),
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_CMBESTADO)),
              ConsSQL_Endereco('I',
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCODIGO),
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTLOGRADOURO),
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTBAIRRO),
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCEP),
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCIDADE),
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_CMBESTADO)), TRUE)) {
                  frmCadEnderecos_InformaLimpaDados(hwnd, NULL, 0, FALSE);
                  frmCadEnderecos_HabilitaDados(hwnd, FALSE);	
              }  
            }
            break;
            case ID_FRMCADENDERECOS_BTNEXCLUIR:
            {
              if (frmCadastros_ExcluirDados(hwnd, ID_FRMCADENDERECOS_EDTCODIGO, 
              ID_FRMCADENDERECOS_EDTLOGRADOURO, ID_FRMCADENDERECOS_BTNNOVO,
              ID_FRMCADENDERECOS_BTNPESQUISAR, ID_FRMCADENDERECOS_BTNANTERIOR,
              ID_FRMCADENDERECOS_BTNPROXIMO, ID_FRMCADENDERECOS_BTNSALVAR,
              ID_FRMCADENDERECOS_BTNEXCLUIR, 
              frmCadEnderecos_ValidaDados(hwnd, FALSE),
              ConsSQL_Endereco('D',
                Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCODIGO),
                "","","","",""))) {
                frmCadEnderecos_InformaLimpaDados(hwnd, NULL, 0, FALSE);
                frmCadEnderecos_HabilitaDados(hwnd, FALSE);	
              }  
            }
            break;
            case ID_FRMCADENDERECOS_BTNLIMPAR:
            {
              frmCadastros_btnLimparClick(hwnd, ID_FRMCADENDERECOS_EDTCODIGO, 
              ID_FRMCADENDERECOS_EDTLOGRADOURO, ID_FRMCADENDERECOS_BTNNOVO,
              ID_FRMCADENDERECOS_BTNPESQUISAR, ID_FRMCADENDERECOS_BTNANTERIOR,
              ID_FRMCADENDERECOS_BTNPROXIMO, ID_FRMCADENDERECOS_BTNSALVAR,
              ID_FRMCADENDERECOS_BTNEXCLUIR);
              
              frmCadEnderecos_InformaLimpaDados(hwnd, NULL, 0, FALSE);
              frmCadEnderecos_HabilitaDados(hwnd, FALSE);	
            }
            break;
            case ID_FRMCADENDERECOS_BTNFECHAR: 
              if (bAtivaEnderecos)   
                DestroyWindow(g_hTelaAtiva);
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

BOOL frmCadEnderecos_ValidaDados(HWND hwnd, BOOL bTodosDados)
{
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCODIGO), 
    Rotinas_lerStr(STR_CODNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTLOGRADOURO), 
           Rotinas_lerStr(STR_ENDNINF)))
  		return FALSE;
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTBAIRRO), 
           Rotinas_lerStr(STR_BAIRRONINF)))
   		  return FALSE;
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCEP), 
           Rotinas_lerStr(STR_CEPNINF)))
   		  return FALSE;
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADENDERECOS_EDTCIDADE), 
           Rotinas_lerStr(STR_CIDADENINF)))
   		  return FALSE;
  	}
  	return TRUE;
}

VOID frmCadEnderecos_InformaLimpaDados(HWND hwnd, LISTAMSTR lstRegistros, 
  UINT nLinhaRegistro, BOOL bInformar)
{
  if (bInformar) {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADENDERECOS_EDTBAIRRO), 
      ListaStr_pesquisaItemOrdM(lstRegistros, 2, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADENDERECOS_EDTCEP),
      ListaStr_pesquisaItemOrdM(lstRegistros, 3, nLinhaRegistro));    
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADENDERECOS_EDTCIDADE),
      ListaStr_pesquisaItemOrdM(lstRegistros, 4, nLinhaRegistro));    
    SendMessage(GetDlgItem(hwnd, ID_FRMCADENDERECOS_CMBESTADO), CB_SELECTSTRING,
      0, (LPARAM) ListaStr_pesquisaItemOrdM(lstRegistros, 5, nLinhaRegistro));
  } else {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADENDERECOS_EDTBAIRRO),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADENDERECOS_EDTCEP),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADENDERECOS_EDTCIDADE),"");    
    SendMessage(GetDlgItem(hwnd, ID_FRMCADENDERECOS_CMBESTADO), CB_SETCURSEL,
      (WPARAM) 0, 0);    
    nRegEnderecos = 0;
  }
} 

VOID frmCadEnderecos_HabilitaDados(HWND hwnd, BOOL bHabilita)
{
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADENDERECOS_EDTBAIRRO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADENDERECOS_EDTCEP),bHabilita);  
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADENDERECOS_EDTCIDADE),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADENDERECOS_CMBESTADO),bHabilita);  
}

VOID frmCadEnderecos_AdicionaCombo(HWND hwnd)
{ HWND hCmb;

  hCmb = GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), 
    ID_FRMCADENDERECOS_CMBESTADO);

  //SendMessage(hCmb, CB_SETITEMHEIGHT, (WPARAM) 0, (LPARAM) 500);               

  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_PE));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_AC));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_AL));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_AP));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_AM));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_BA));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_BR));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_CE));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_DF));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_ES));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_GO));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_MT));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_MS));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_MG));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_PA));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_PB));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_PR));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_SC));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_RN));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_RS));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_RJ));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_RO));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_RR));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_SP));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_SE));
  SendMessage(hCmb, CB_ADDSTRING, 0, (LPARAM) Rotinas_lerStr(STR_TO));
}

