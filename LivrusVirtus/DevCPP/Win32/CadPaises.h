#ifndef CADPAISES_H
#define CADPAISES_H

static char g_sFRMCadPaises[] = "FRMCADPAISES";

LRESULT CALLBACK frmCadPaisesProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
BOOL frmCadPaises_ValidaDados(HWND hwnd, BOOL bTodosDados);

#endif
