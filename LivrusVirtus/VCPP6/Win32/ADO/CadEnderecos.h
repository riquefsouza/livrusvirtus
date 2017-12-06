#ifndef CADENDERECOS_H
#define CADENDERECOS_H

static char g_sFRMCadEnderecos[] = "FRMCADENDERECOS";

LRESULT CALLBACK frmCadEnderecosProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
BOOL frmCadEnderecos_ValidaDados(HWND hwnd, BOOL bTodosDados);
VOID frmCadEnderecos_InformaLimpaDados(HWND hwnd, LISTAMSTR lstRegistros, 
  UINT nLinhaRegistro, BOOL bInformar);
VOID frmCadEnderecos_HabilitaDados(HWND hwnd, BOOL bHabilita);
VOID frmCadEnderecos_AdicionaCombo(HWND hwnd);  

#endif
