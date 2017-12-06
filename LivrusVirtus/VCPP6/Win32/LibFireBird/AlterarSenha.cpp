#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "resource.h"
#include "Principal.h"
#include "Cadastros.h"
#include "AlterarSenha.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
   
LRESULT CALLBACK frmAlterarSenhaProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {
      case WM_CREATE:
      {   
        if (!frmCadastros_Criar(hwnd, g_sFRMAlterarSenha, 
                (DLGPROC)frmAlterarSenhaProc))
          return FALSE;      
          
        SetWindowText(GetDlgItem(hwnd, ID_FRMALTERARSENHA_EDTLOGIN),
            Rotinas_sUsuarioLogin);          
      }
      break;
      case WM_MDIACTIVATE:
      { 
        frmCadastros_Ativar(hwnd, wParam, lParam, 
                ID_FRMALTERARSENHA_EDTSENHAATUAL, 4, CM_OP_ALTERARSENHA);
        return FALSE;         
      }
      break;      
      case WM_DESTROY:
         frmCadastros_Fechar(hwnd, 4, CM_OP_ALTERARSENHA);
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {
            case ID_FRMALTERARSENHA_BTNSALVAR:
            {
              	if (frmAlterarSenha_ValidaDados(hwnd)) {
              	  if (Rotinas_AtualizaDados(gConexao, 
              	    ConsSQL_Usuario('U', Rotinas_sUsuarioLogin, 
                  Rotinas_retTexto(hwnd, ID_FRMALTERARSENHA_EDTCONFIRMASENHA)) 
                  ))  {              
                    MessageBox(hwnd, Rotinas_lerStr(STR_SENALTSUC), 
                        Rotinas_lerStr(STR_TITULO), MB_ICONINFORMATION | MB_OK);
                  }         
              	}
            }
            break;
            case ID_FRMALTERARSENHA_BTNLIMPAR:
            {
              SetWindowText(GetDlgItem(hwnd, 
                            ID_FRMALTERARSENHA_EDTSENHAATUAL),"");
              SetWindowText(GetDlgItem(hwnd, 
                            ID_FRMALTERARSENHA_EDTNOVASENHA),"");
              SetWindowText(GetDlgItem(hwnd, 
                            ID_FRMALTERARSENHA_EDTCONFIRMASENHA),"");
              SetFocus(GetDlgItem(hwnd, ID_FRMALTERARSENHA_EDTSENHAATUAL));
            }
            break;
            case ID_FRMALTERARSENHA_BTNFECHAR:
              DestroyWindow(g_hTelaAtiva);
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}
/*  
BOOL frmAlterarSenha_Criar(HWND hwnd)
{ 
Rotinas_criaRotulo(hwnd, "Login:", ID_FRMALTERARSENHA_LABLOGIN, 8, 8, 64);
Rotinas_criaEdit(hwnd, ID_FRMALTERARSENHA_EDTLOGIN, 
    8, 24, 96, FALSE, 10, FALSE, FALSE);
Rotinas_criaRotulo(hwnd, "Senha atual:", ID_FRMALTERARSENHA_LABSENHAATUAL, 
    120, 8, 80);
Rotinas_criaEdit(hwnd, ID_FRMALTERARSENHA_EDTSENHAATUAL, 
    120, 24, 96, TRUE, 10, TRUE, FALSE);
Rotinas_criaRotulo(hwnd, "Nova Senha:", ID_FRMALTERARSENHA_LABNOVASENHA, 
    8, 56, 80);
Rotinas_criaEdit(hwnd, ID_FRMALTERARSENHA_EDTNOVASENHA, 
    8, 72, 96, TRUE, 10, TRUE, FALSE);				 
Rotinas_criaRotulo(hwnd, "Confirmar senha:", 
    ID_FRMALTERARSENHA_LABCONFIRMASENHA, 120, 56, 96);
Rotinas_criaEdit(hwnd, ID_FRMALTERARSENHA_EDTCONFIRMASENHA, 
    120, 72, 96, TRUE, 50, TRUE, FALSE);         
Rotinas_criaBotao(hwnd, "&Salvar", ID_FRMALTERARSENHA_BTNSALVAR, 8, 104, TRUE);
Rotinas_criaBotao(hwnd, "&Limpar", ID_FRMALTERARSENHA_BTNLIMPAR, 
          88, 104, TRUE);
Rotinas_criaBotao(hwnd, "&Fechar", ID_FRMALTERARSENHA_BTNFECHAR, 
          168, 104, TRUE);

 return TRUE;
}
*/

BOOL frmAlterarSenha_ValidaDados(HWND hwnd)
{
if (lstrcmp(Rotinas_retTexto(hwnd, ID_FRMALTERARSENHA_EDTSENHAATUAL),
                    Rotinas_sUsuarioSenha)!=0) {
   MessageBox(hwnd, Rotinas_lerStr(STR_SENNCSU), "Erro", MB_ICONERROR | MB_OK);   
   return FALSE;
}
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMALTERARSENHA_EDTNOVASENHA),
  		Rotinas_lerStr(STR_NSENNINF))) {
  	return FALSE;
}
if (lstrcmp(Rotinas_retTexto(hwnd, ID_FRMALTERARSENHA_EDTNOVASENHA),
            Rotinas_retTexto(hwnd, ID_FRMALTERARSENHA_EDTCONFIRMASENHA))!=0) {
 MessageBox(hwnd, Rotinas_lerStr(STR_NSENNCCON), "Erro", MB_ICONERROR | MB_OK);   
 return FALSE;
} 
return TRUE;
}

