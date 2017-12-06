#ifndef ROTINASGLOBAIS_H
#define ROTINASGLOBAIS_H

#define MAXLINHAS_VISAOLISTA 100000

#import "C:\Arquivos de programas\Arquivos comuns\System\ado\msado15.dll" \
no_namespace rename("EOF", "adoEOF")

#include "ListaStr.h"

extern TCHAR Rotinas_sUsuarioLogin[TAM_MAX_STR];
extern TCHAR Rotinas_sUsuarioSenha[TAM_MAX_STR];
extern TCHAR Rotinas_sCodigoSelecionado[TAM_MAX_STR];
extern TCHAR Rotinas_sPreco[TAM_MAX_STR];
extern TCHAR Rotinas_sQtdEstoque[TAM_MAX_STR];
extern TCHAR Rotinas_sepDTHR[2];

typedef _ConnectionPtr CONEXAO;
extern CONEXAO gConexao;

INT Rotinas_RegistrarClasseForm(WNDCLASSEX WndClassEx, WNDPROC WndFrmProc, 
  LPCTSTR sNomeClasse);
HWND Rotinas_ChamarForm(HWND hwnd, LPCTSTR sTituloForm, LPCTSTR sNomeClasse, 
    HWND hMDICliente, INT largura, INT altura);
HWND Rotinas_ChamarDlgNaoModal(HWND hwnd, LPCTSTR sNomeDialog, 
    DLGPROC lpDlgProc);    
VOID Rotinas_CentralizaTela(HWND hWnd);
VOID Rotinas_habilitaSubMenu(HWND hwnd, INT nPosSubMenu, INT idSubMenu, 
    BOOL bHabilita);

LPTSTR Rotinas_alocaString(INT ntam);
LPTSTR Rotinas_subString(LPTSTR string, INT nini, INT ntam);
BOOL Rotinas_ValidaFloat(LPTSTR sNum);
LPTSTR Rotinas_VirgulaParaPonto(LPTSTR sNum, BOOL bRevertido);
INT Rotinas_modulo11(LPTSTR svalor, INT ndig);
BOOL Rotinas_validaCPF(LPTSTR cpf);
BOOL Rotinas_validaISBN(LPTSTR isbn);
BOOL Rotinas_validaDataHora(LPTSTR sDataHora, BOOL bSoData);
LPTSTR Rotinas_FormataDataHoraStr(SYSTEMTIME sTempo, LPTSTR sFrmtData, 
    LPTSTR sFrmtHora);
LPTSTR Rotinas_retDataHoraStr(BOOL bData, BOOL bHora);
LPTSTR Rotinas_ConverteDataHoraStr(LPTSTR sDTHR, BOOL DMY_ou_YMD, 
  LPTSTR sFrmtData, LPTSTR sFrmtHora);
LPTSTR Rotinas_retTexto(HWND hwnd, INT nItem);
LPTSTR Rotinas_lerStr(UINT nId);

HWND Rotinas_criaBotao(HWND hwnd, LPTSTR sTexto, INT id, INT x, INT y, BOOL bHabilitado);
HWND Rotinas_criaEdit(HWND hwnd, INT id, INT x, INT y, INT largura, BOOL bHabilitado, 
    INT nMaxTam, BOOL bComSenha, BOOL bSoNumero);
HWND Rotinas_criaRotulo(HWND hwnd, LPTSTR sTexto, INT id, INT x, INT y, INT largura);
HWND Rotinas_criaVisaoLista(HWND hwnd, INT id, INT x, INT y, INT altura);

BOOL Rotinas_ConectaBanco(LPTSTR sStrConexao);
VOID Rotinas_DisconectaBanco();
BOOL Rotinas_ConsultaDados(CONEXAO pConexao, LPTSTR sSql);
BOOL Rotinas_ConsultaDadosLista(CONEXAO pConexao, 
                                LISTAMSTR *lstLocal, LPTSTR sSql);
BOOL Rotinas_AtualizaDados(CONEXAO pConexao, LPTSTR sSql);

BOOL Rotinas_ValidaCampo(LPTSTR sCampo, LPTSTR sMensagemErro);
LPTSTR Rotinas_ConsultaCampoDesc(LISTAMSTR *Campos, 
                      LPTSTR sTextoSql, LPTSTR sMensagemErro);
VOID Rotinas_AdicionaItemLista(HWND lstLista,
     LISTASTR *slCodLista, HWND sCampoCodigo, HWND sCampoDesc);
VOID Rotinas_RemoveItemLista(HWND lstLista, LISTASTR *slCodLista);
VOID Rotinas_AdicionaValoresLista(LPTSTR sTextoSql, HWND lstLista, 
                                  LISTASTR *slCodLista);

BOOL Rotinas_VisaoListaInsereColunas(HWND hwndVisaoLista, UINT largura[], 
    LISTASTR sColunas);
BOOL Rotinas_VisaoListaInsereLinhas(HWND hwndVisaoLista, LISTAMSTR sLinhas);
BOOL  Rotinas_VisaoListaNotifica(HWND hwndVisaoLista, LISTAMSTR sLinhas, 
    LPARAM lParam, INT *nLinha, LPTSTR *sSelecionado); 

VOID Rotinas_copiaBitmap(HWND hwnd, INT idBMP, RECT rc);
    	 
#endif
