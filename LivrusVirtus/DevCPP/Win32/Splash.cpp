#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "resource.h"
#include "Splash.h"
#include "RotinasGlobais.h"

LRESULT CALLBACK frmSplashProc(HWND hDlg, UINT uMsg, WPARAM wParam, 
    LPARAM lParam )
{
   UINT idTimer = 1;
   switch( uMsg ) {
      case WM_INITDIALOG:
      {      
        SetTimer(hDlg, idTimer, 3000, (TIMERPROC) NULL); 
        return TRUE;
      }  
      break;       
      case WM_PAINT:
      {     
        RECT rc;    
        GetClientRect(hDlg, &rc);
        Rotinas_copiaBitmap(hDlg,ID_BMP_LIVRUSVIRTUS,rc);
      }  
      break;
      case WM_TIMER:       
         EndDialog( hDlg, TRUE );
      break;      
      case WM_CLOSE:
         EndDialog( hDlg, TRUE );
      break;
   }
  
   return FALSE;
}

