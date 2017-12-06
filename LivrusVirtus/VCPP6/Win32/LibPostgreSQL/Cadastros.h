#ifndef CADASTROS_H
#define CADASTROS_H

#include "ListaStr.h"

BOOL frmCadastros_Criar(HWND hwnd, LPTSTR sNomeTela, DLGPROC sDlgProc);
BOOL frmCadastros_Ativar(HWND hwnd, WPARAM wParam, LPARAM lParam, 
    INT idEdtCodigo, INT nPosMenu, INT idSubMenu);
VOID frmCadastros_Fechar(HWND hwnd, INT nPosMenu, INT idSubMenu);
VOID frmCadastros_TamMaxEdit(HWND hwnd, INT idEdit, INT nTamMax);
VOID frmCadastros_InformaLimpaDados(HWND hwnd, LISTAMSTR lstRegistros, 
  UINT nLinhaRegistro, INT idEdtCodigo, INT idEdtDesc, BOOL bInformar);
VOID frmCadastros_HabilitaDados(HWND hwnd, INT idEdtDesc, BOOL bHabilita);
VOID frmCadastros_btnNovoClick(HWND hwnd, INT idEdtCodigo, INT idEdtDesc, 
  INT idBtnNovo, INT idBtnPesquisar, INT idBtnAnterior,  
  INT idBtnProximo, INT idBtnSalvar, INT idBtnExcluir);
VOID frmCadastros_NovoDado(HWND hwnd, INT idEdtCodigo, INT idEdtDesc, 
  LPTSTR sTextoSql);
VOID frmCadastros_btnLimparClick(HWND hwnd, INT idEdtCodigo, INT idEdtDesc, 
  INT idBtnNovo, INT idBtnPesquisar, INT idBtnAnterior,  
  INT idBtnProximo, INT idBtnSalvar, INT idBtnExcluir);
BOOL frmCadastros_ExcluirDados(HWND hwnd, INT idEdtCodigo, INT idEdtDesc, 
  INT idBtnNovo, INT idBtnPesquisar, INT idBtnAnterior,  
  INT idBtnProximo, INT idBtnSalvar, INT idBtnExcluir, 
  BOOL bValidaDados, LPTSTR sTextoSql);
BOOL frmCadastros_PesquisarDados(HWND hwnd,  LISTAMSTR *lstRegistros, 
  INT idEdtCodigo, INT idEdtDesc, INT idBtnPesquisar, 
  INT idBtnAnterior, INT idBtnProximo, INT idBtnSalvar, 
  INT idBtnExcluir, LPTSTR sTextoSql, LPTSTR sMensagemErro);
BOOL frmCadastros_registroAnterior(HWND hwnd, LISTAMSTR lstRegistros, 
  INT idEdtCodigo, INT idEdtDesc, UINT *nLinhaRegistro);
BOOL frmCadastros_registroProximo(HWND hwnd, LISTAMSTR lstRegistros, 
  INT idEdtCodigo, INT idEdtDesc, UINT *nLinhaRegistro);
BOOL frmCadastros_SalvarDados(HWND hwnd, INT idEdtCodigo, INT idEdtDesc, 
  INT idBtnNovo, INT idBtnPesquisar, INT idBtnAnterior,  
  INT idBtnProximo, INT idBtnSalvar, INT idBtnExcluir, 
  BOOL bValidaDados, LPTSTR sTextoSql,LPTSTR sTextoUpdate,
	LPTSTR sTextoInsert, BOOL bLimparDados);

#endif


