#ifndef CADIDIOMAS_H
#define CADIDIOMAS_H

static char g_sFRMCadIdiomas[] = "FRMCADIDIOMAS";

LRESULT CALLBACK frmCadIdiomasProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
BOOL frmCadIdiomas_ValidaDados(HWND hwnd, BOOL bTodosDados);

#endif
