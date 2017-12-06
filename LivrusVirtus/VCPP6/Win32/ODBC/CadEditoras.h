#ifndef CADEDITORAS_H
#define CADEDITORAS_H

static char g_sFRMCadEditoras[] = "FRMCADEDITORAS";

LRESULT CALLBACK frmCadEditorasProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
BOOL frmCadEditoras_ValidaDados(HWND hwnd, BOOL bTodosDados);

#endif
