#ifndef CADCLIENTES_H
#define CADCLIENTES_H

static char g_sFRMCadClientes[] = "FRMCADCLIENTES";

LRESULT CALLBACK frmCadClientesProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
BOOL frmCadClientes_ValidaDados(HWND hwnd, BOOL bTodosDados);
VOID frmCadClientes_InformaLimpaDados(HWND hwnd, LISTAMSTR lstRegistros, 
  UINT nLinhaRegistro, BOOL bInformar);
VOID frmCadClientes_HabilitaDados(HWND hwnd, BOOL bHabilita);
VOID frmCadClientes_edtCPFKillFocus(HWND hwnd);
VOID frmCadClientes_edtCodEnderecoKillFocus(HWND hwnd);
VOID frmCadClientes_edtCodPaisKillFocus(HWND hwnd);
VOID frmCadClientes_edtCodProfissaoKillFocus(HWND hwnd);
VOID frmCadClientes_edtDtNascKillFocus(HWND hwnd);
VOID frmCadClientes_btnPEnderecoClick(HWND hwnd);
VOID frmCadClientes_btnPPaisClick(HWND hwnd);
VOID frmCadClientes_btnPProfissaoClick(HWND hwnd);

#endif
