#ifndef ALTERARSENHA_H
#define ALTERARSENHA_H

static char g_sFRMAlterarSenha[] = "FRMALTERARSENHA";

LRESULT CALLBACK frmAlterarSenhaProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
BOOL frmAlterarSenha_ValidaDados(HWND hwnd);

#endif


