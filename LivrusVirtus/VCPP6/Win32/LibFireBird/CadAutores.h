#ifndef CADAUTORES_H
#define CADAUTORES_H

static char g_sFRMCadAutores[] = "FRMCADAUTORES";

LRESULT CALLBACK frmCadAutoresProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
BOOL frmCadAutores_ValidaDados(HWND hwnd, BOOL bTodosDados);

#endif
