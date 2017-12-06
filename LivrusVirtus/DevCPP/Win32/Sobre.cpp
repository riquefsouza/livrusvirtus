#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "resource.h"
#include "Sobre.h"
#include "RotinasGlobais.h"

LRESULT CALLBACK frmSobreProc( HWND hDlg, UINT uMsg, WPARAM wParam, 
    LPARAM lParam )
{
   switch( uMsg ) {
      case WM_INITDIALOG:
      {
         return TRUE;
      }
      break;       
      case WM_COMMAND:
      {
         switch( wParam ) {
            case ID_FRMSOBRE_BTNOK:
               EndDialog( hDlg, TRUE );
               return TRUE;
         }
      }   
      break;
      case WM_PAINT:
      {     
        RECT rc; 
        rc.top = 15;
        rc.left = 25;
        rc.right = 264;
        rc.bottom = 72;
        Rotinas_copiaBitmap(hDlg,ID_BMP_LIVRUSVIRTUS,rc);
      }  
      break;      
      case WM_CLOSE:
      {
         EndDialog( hDlg, FALSE );
      }   
      break;
   }
  
   return FALSE;
}

