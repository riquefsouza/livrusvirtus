#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>
#include <commdlg.h>

#include "resource.h"
#include "Livrus.h"
#include "Principal.h"
#include "RotinasGlobais.h"

#include "Splash.h"
#include "Login.h"
#include "AlterarSenha.h"
#include "CadAssuntos.h"
#include "CadAutores.h"
#include "CadEditoras.h"
#include "CadEnderecos.h"
#include "CadIdiomas.h"
#include "CadPaises.h"
#include "CadProfissoes.h"
#include "CadClientes.h"
#include "CadLivros.h"
#include "VenderLivros.h"
#include "ConVendas.h"

HINSTANCE g_hInstancia;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
   LPSTR lpszCmdParam, int nCmdShow)
{
   MSG  Msg;
   WNDCLASSEX WndClassEx;
   HACCEL  hAccel;
   HWND  hMDIFilha, hTemp;
   BOOL  bDialogMessage = FALSE;
   
   InitCommonControls();

   g_hInstancia = hInstance;
   
   /* Checa se a aplicação já está rodando,
      se estiver então ativa e então atribui o foco */

   if (g_hFRMPrincipal = FindWindow(g_sNomeApp, NULL)) {
      g_hFRMPrincipal = GetLastActivePopup(g_hFRMPrincipal);
      
      MessageBox(0, Rotinas_lerStr(STR_APPEXEC), 
            "Erro", MB_ICONEXCLAMATION | MB_OK);      
      
      if (IsIconic(g_hFRMPrincipal))
         OpenIcon(g_hFRMPrincipal);
      else
         BringWindowToTop(g_hFRMPrincipal);
         
      SetForegroundWindow(g_hFRMPrincipal);
      return FALSE;
   }   

   /* Registrar janela principal */

   WndClassEx.cbSize          = sizeof(WNDCLASSEX);
   WndClassEx.style           = CS_HREDRAW | CS_VREDRAW;
   WndClassEx.lpfnWndProc     = frmPrincipalProc;
   WndClassEx.cbClsExtra      = 0;
   WndClassEx.cbWndExtra      = 0;
   WndClassEx.hInstance       = hInstance;
   WndClassEx.hIcon           = LoadIcon(hInstance, 
      MAKEINTRESOURCE(ID_ICON_LIVRUS));
   WndClassEx.hCursor         = LoadCursor(NULL, IDC_ARROW);
   WndClassEx.hbrBackground   = (HBRUSH)(COLOR_3DSHADOW+1);
   WndClassEx.lpszMenuName    = "PRINCIPAL";
   WndClassEx.lpszClassName   = g_sNomeApp;
   WndClassEx.hIconSm         = LoadIcon(hInstance, 
      MAKEINTRESOURCE(ID_ICON_LIVRUS));

   if(!RegisterClassEx(&WndClassEx))
   {
      MessageBox(0, Rotinas_lerStr(STR_NREGJAN), "Erro", MB_ICONERROR | MB_OK);
      return -1;
   }

   /* Registrar as outras janelas */
   Rotinas_RegistrarClasseForm(WndClassEx, frmCadAssuntosProc, 
      g_sFRMCadAssuntos);
   Rotinas_RegistrarClasseForm(WndClassEx, frmCadAutoresProc, 
      g_sFRMCadAutores);
   Rotinas_RegistrarClasseForm(WndClassEx, frmCadEditorasProc, 
      g_sFRMCadEditoras);
   Rotinas_RegistrarClasseForm(WndClassEx, frmCadEnderecosProc, 
      g_sFRMCadEnderecos);
   Rotinas_RegistrarClasseForm(WndClassEx, frmCadIdiomasProc, 
      g_sFRMCadIdiomas);
   Rotinas_RegistrarClasseForm(WndClassEx, frmCadPaisesProc, 
      g_sFRMCadPaises);
   Rotinas_RegistrarClasseForm(WndClassEx, frmCadProfissoesProc, 
      g_sFRMCadProfissoes);
   Rotinas_RegistrarClasseForm(WndClassEx, frmCadClientesProc, 
      g_sFRMCadClientes);
   Rotinas_RegistrarClasseForm(WndClassEx, frmCadLivrosProc, 
      g_sFRMCadLivros);
   Rotinas_RegistrarClasseForm(WndClassEx, frmVenderLivrosProc, 
      g_sFRMVenderLivros);
   Rotinas_RegistrarClasseForm(WndClassEx, frmConVendasProc, 
      g_sFRMConVendas);
   Rotinas_RegistrarClasseForm(WndClassEx, frmAlterarSenhaProc, 
      g_sFRMAlterarSenha);

    g_hFRMPrincipal = CreateWindowEx(WS_EX_APPWINDOW, g_sNomeApp,
      Rotinas_lerStr(STR_TITULO), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
      0, 0, hInstance, NULL);

   if (g_hFRMPrincipal == NULL){
      MessageBox(0, Rotinas_lerStr(STR_SEMJAN), "Erro", MB_ICONERROR | MB_OK);
      return -1;
   }

   /* chamar a tela de splash */  
   DialogBox(g_hInstancia, g_sFRMSplash, NULL, (DLGPROC)frmSplashProc);

   /* chamar a tela de login */  
   if (DialogBox(g_hInstancia, g_sFRMLogin, NULL, 
                     (DLGPROC)frmLoginProc)==FALSE)                        
      return -1;                             
     
   /* Mostrar tela principal */   
   ShowWindow(g_hFRMPrincipal, nCmdShow);
   UpdateWindow(g_hFRMPrincipal);

   hAccel = LoadAccelerators(g_hInstancia, MAKEINTRESOURCE(ID_ACELERADORES));
   
   while(GetMessage(&Msg, NULL, 0, 0))
   {
      /* Processa as teclas de atalho rápidas */
      if (TranslateAccelerator(g_hFRMPrincipal, hAccel, &Msg))
         continue;
      /* Processa as tabulações da tela principal */
      if (TranslateMDISysAccel(g_hMDICliente, &Msg))
         continue;
      /* Processa as tabulações das dialogs não modais */   
      if (g_hDlgAtual != NULL && IsDialogMessage(g_hDlgAtual, &Msg)) 
         continue;
         
      /* Cada Tela da MDI tem uma dialog não modal na sua área cliente
         para prover o controle da tabulação. Checa as mensagens das dialogs. */
      for (hMDIFilha = GetWindow(g_hMDICliente, GW_CHILD); 
            hMDIFilha; hMDIFilha = GetWindow(hMDIFilha, GW_HWNDNEXT)) {
         hTemp = (HWND)GetWindowLong(hMDIFilha, HWNDMDIFILHA);
         if (hTemp != NULL && IsDialogMessage(hTemp, &Msg)) {
            bDialogMessage = TRUE;
            break;
         }
      }

      if (bDialogMessage) {
         bDialogMessage = FALSE;
         continue;
      }

	 TranslateMessage(&Msg);
	 DispatchMessage(&Msg);
      
   }
   return Msg.wParam;
}

