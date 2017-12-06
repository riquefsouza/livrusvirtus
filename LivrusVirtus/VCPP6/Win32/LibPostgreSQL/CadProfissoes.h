#ifndef CADPROFISSOES_H
#define CADPROFISSOES_H

static char g_sFRMCadProfissoes[] = "FRMCADPROFISSOES";

LRESULT CALLBACK frmCadProfissoesProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
BOOL frmCadProfissoes_ValidaDados(HWND hwnd, BOOL bTodosDados);

#endif
