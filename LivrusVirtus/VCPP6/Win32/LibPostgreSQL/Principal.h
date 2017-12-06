#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#define ID_BARRADESTATUS        50001
#define ID_BARRADEFERRAMENTAS   50002

#define ID_MDI_CLIENTE          50003
#define ID_MDI_PRIMEIROFORM     50004

#define HWNDMDIFILHA            0

/*#define WM_OPCAO (WM_USER)  */
   
static char g_sNomeApp[] = "AppLivrus";

extern HWND g_hMDICliente, g_hBarraStatus, g_hBarraFerram;
extern HWND g_hFRMPrincipal;
extern HWND g_hDlgAtual;
extern HWND g_hTelaAtiva;

LRESULT CALLBACK frmPrincipalProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);

#endif
