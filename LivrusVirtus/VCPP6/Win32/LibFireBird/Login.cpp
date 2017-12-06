#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "resource.h"
#include "Login.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "Livrus.h"
#include "Principal.h"

LRESULT CALLBACK frmLoginProc( HWND hDlg, UINT uMsg, WPARAM wParam, 
    LPARAM lParam )
{
   BOOL bFecharOuTerminar;
   
   switch( uMsg ) {
      case WM_INITDIALOG:
      {
         SetClassLong(hDlg, GCL_HICON, (LONG) LoadIcon(g_hInstancia,
                    MAKEINTRESOURCE(ID_ICON_LIVRUS)) );
         bFecharOuTerminar = FALSE;   
         return TRUE;
      }
      break;       
      case WM_COMMAND:
         switch( wParam ) {
            case ID_FRMLOGIN_BTNLOGIN:
            {
             lstrcpy(Rotinas_sUsuarioLogin,
                          Rotinas_retTexto(hDlg, ID_FRMLOGIN_EDTLOGIN));
             lstrcpy(Rotinas_sUsuarioSenha,
                          Rotinas_retTexto(hDlg, ID_FRMLOGIN_EDTSENHA));

             if (Rotinas_ConsultaDados(gConexao, 
              	 ConsSQL_Usuario('S',Rotinas_sUsuarioLogin,
                                Rotinas_sUsuarioSenha)) ) {

                   TCHAR sTemp[TAM_MAX_STR];     
                     	 
              	   wsprintf(sTemp,"%s%s",Rotinas_lerStr(STR_USUARIO),
                                    Rotinas_sUsuarioLogin);  	 
                   SendMessage(g_hBarraStatus, SB_SETTEXT, 0, (LPARAM)sTemp);
                   EndDialog(hDlg, TRUE );
            
              } else
              	    MessageBox(hDlg, Rotinas_lerStr(STR_LOGSENINC), "Erro",
              	               MB_ICONERROR | MB_OK);  			   
            }   
            break;   
            case ID_FRMLOGIN_BTNCANCELAR:
            {
               SendMessage(hDlg, WM_CLOSE, 0, 0);
            }   
            break;   
         }
      break;
      /*
      case WM_PAINT:
      {     
        RECT rc; 
        rc.top = 8;
        rc.left = 16;
        rc.right = 96;
        rc.bottom = 96;
        Rotinas_copiaBitmap(hDlg,ID_BMP_LOGIN,rc);
      }  
      break;            
      */
      case WM_CLOSE:     
      {
         Rotinas_DisconectaBanco();
         EndDialog( hDlg, FALSE );
      }
      break;
   }
  
   return FALSE;
}

