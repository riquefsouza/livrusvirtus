#ifndef FRMCONVENDAS_H
#define FRMCONVENDAS_H

static char g_sFRMConVendas[] = "FRMCONVENDAS";

LRESULT CALLBACK frmConVendasProc( HWND hDlg, UINT uMsg, WPARAM wParam, 
    LPARAM lParam );
VOID frmConVendas_edtDtHrVendaKillFocus(HWND hwnd);
VOID frmConVendas_btnLimparClick(HWND hwnd);
LPTSTR frmConVendas_ConsVenda(HWND hwnd, TCHAR sOpcao);
VOID frmConVendas_PesquisarDados(HWND hwnd);
VOID frmConVendas_edtCPFKillFocus(HWND hwnd);
VOID frmConVendas_btnPClienteClick(HWND hwnd);
VOID frmConVendas_edtISBNKillFocus(HWND hwnd);
VOID frmConVendas_btnPLivroClick(HWND hwnd);
VOID frmConVendas_arrumaTamanho(HWND hwnd);

#endif
