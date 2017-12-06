#ifndef CADLIVROS_H
#define CADLIVROS_H

static char g_sFRMCadLivros[] = "FRMCADLIVROS";

LRESULT CALLBACK frmCadLivrosProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam);
BOOL frmCadLivros_ValidaDados(HWND hwnd, BOOL bTodosDados);
VOID frmCadLivros_InformaLimpaDados(HWND hwnd, LISTAMSTR lstRegistros, 
  UINT nLinhaRegistro, BOOL bInformar);
VOID frmCadLivros_HabilitaDados(HWND hwnd, BOOL bHabilita);
VOID frmCadLivros_edtISBNKillFocus(HWND hwnd);
VOID frmCadLivros_AdicionaCombo(HWND hwnd);
VOID frmCadLivros_SalvaLista(HWND hwnd, CHAR sOpcao);
VOID frmCadLivros_edtCodEditoraKillFocus(HWND hwnd);
VOID frmCadLivros_btnPEditoraClick(HWND hwnd);
VOID frmCadLivros_edtPrecoKillFocus(HWND hwnd);
VOID frmCadLivros_edtCodAssuntoKillFocus(HWND hwnd);
VOID frmCadLivros_btnPAssuntoClick(HWND hwnd);
VOID frmCadLivros_edtCodAutorKillFocus(HWND hwnd);
VOID frmCadLivros_btnPAutorClick(HWND hwnd);

#endif
