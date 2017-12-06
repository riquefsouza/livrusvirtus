#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "ListaStr.h"

VOID frmConsultas_Ativar(HWND hwnd, WPARAM wParam, INT idSubMenu);
VOID frmConsultas_Fecha(HWND hwnd, LPTSTR sSelecionado, INT idSubMenu);
VOID frmConsultas_setLabRegistros(HWND hwnd, INT idLabRegs, 
    LISTAMSTR sLinhas, INT nReg);
VOID frmConsultas_arrumaTamanho(HWND hwnd, INT idListaCons, INT idLabRegs, 
    INT idBtnLimpar, INT idBtnFechar);
BOOL frmConsultas_Notifica(HWND hwnd, LPARAM lParam, HWND hListaCons, 
    INT idLabRegs, LISTAMSTR sLinhas, LPTSTR *sSelecionado);     
VOID frmConsultas_LimparDados(HWND hwnd, INT idLabRegs, INT idEdtDesc, 
    HWND hListaCons, LISTAMSTR sLinhas);
VOID frmConsultas_PesquisarDados(HWND hwnd, HWND hListaCons, INT idLabRegs,
                LISTAMSTR *sLinhas, LPTSTR sTextoSql, LPTSTR sMensagemErro);

#endif


