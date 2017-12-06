#ifndef VENDERLIVROS_H
#define VENDERLIVROS_H

static char g_sFRMVenderLivros[] = "FRMVENDERLIVROS";

LRESULT CALLBACK frmVenderLivrosProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
VOID frmVenderLivros_LimpaDados(HWND hwnd);
BOOL frmVenderLivros_ValidaDados(HWND hwnd, BOOL bTodosDados);
BOOL frmVenderLivros_SalvaLista(HWND hwnd); 
VOID frmVenderLivros_edtCPFKillFocus(HWND hwnd);
VOID frmVenderLivros_btnPClienteClick(HWND hwnd);
VOID frmVenderLivros_edtISBNKillFocus(HWND hwnd);
VOID frmVenderLivros_btnPLivroClick(HWND hwnd);
VOID frmVenderLivros_btnAdLivrosClick(HWND hwnd);
VOID frmVenderLivros_lstLivrosDoubleClick(HWND hwnd);
VOID frmVenderLivros_btnVenderClick(HWND hwnd);

#endif
