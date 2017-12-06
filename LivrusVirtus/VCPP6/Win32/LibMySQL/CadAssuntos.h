#ifndef CADASSUNTOS_H
#define CADASSUNTOS_H

static char g_sFRMCadAssuntos[] = "FRMCADASSUNTOS";

LRESULT CALLBACK frmCadAssuntosProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
BOOL frmCadAssuntos_ValidaDados(HWND hwnd, BOOL bTodosDados);

#endif
