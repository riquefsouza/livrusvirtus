#ifndef LISTASTR_H
#define LISTASTR_H

#define TAM_MAX_STR 256
#define QTD_MAX_COL 20

struct nostr {
	unsigned int ordem;
	char str[TAM_MAX_STR];
	struct nostr *proximo;
};
typedef struct nostr *LISTASTR;

struct nomstr {
	unsigned int ordem;
	char str[QTD_MAX_COL][TAM_MAX_STR];
	struct nomstr *proximo;
};
typedef struct nomstr *LISTAMSTR;

LISTASTR ListaStr_aloca();
LISTASTR ListaStr_inicia();
VOID ListaStr_libera(LISTASTR ls);
VOID ListaStr_insereFim(LISTASTR *ls, LPTSTR str);
BOOL ListaStr_remove(LISTASTR ls, LPTSTR *str);
VOID ListaStr_arrumaOrdem(LISTASTR ls);
VOID ListaStr_removeItem(LISTASTR *ls, LPTSTR str, BOOL bArrumaOrdem);
VOID ListaStr_removeItemOrd(LISTASTR *ls, UINT ordem, BOOL bArrumaOrdem);
VOID ListaStr_removeTodos(LISTASTR ls);
BOOL ListaStr_pesquisaItem(LISTASTR ls, LPTSTR str);
LPTSTR ListaStr_pesquisaItemOrd(LISTASTR ls, UINT ordem);
INT ListaStr_conta(LISTASTR ls);

LISTAMSTR ListaStr_alocaM();
LISTAMSTR ListaStr_iniciaM();
VOID ListaStr_liberaM(LISTAMSTR ls);
VOID ListaStr_insereFimM(LISTAMSTR *ls, LPTSTR str[]);
BOOL ListaStr_removeM(LISTAMSTR ls, LPTSTR *str[]);
VOID ListaStr_arrumaOrdemM(LISTAMSTR ls);
VOID ListaStr_removeItemM(LISTAMSTR *ls, LPTSTR str[], BOOL bArrumaOrdem);
VOID ListaStr_removeItemOrdM(LISTAMSTR *ls, UINT ordem, BOOL bArrumaOrdem);
VOID ListaStr_removeTodosM(LISTAMSTR ls);
BOOL ListaStr_pesquisaItemM(LISTAMSTR ls, LPTSTR str);
LPTSTR ListaStr_pesquisaItemOrdM(LISTAMSTR ls, UINT coluna, UINT ordem);
INT ListaStr_contaM(LISTAMSTR ls);

#endif


