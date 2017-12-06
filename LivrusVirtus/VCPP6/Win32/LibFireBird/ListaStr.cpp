#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "ListaStr.h"

/* Lista de strings */

LISTASTR ListaStr_aloca()
{
	LISTASTR ls;
	ls = (LISTASTR) GlobalAlloc(GPTR, sizeof(struct nostr));
	
	return(ls);
}

LISTASTR ListaStr_inicia() 
{
  return NULL;
}

VOID ListaStr_libera(LISTASTR ls)
{
	GlobalFree(ls);
}

VOID ListaStr_insereFim(LISTASTR *ls, LPTSTR str)
{
	LISTASTR local, temp;

	local = ListaStr_aloca();
  local->ordem = 0;
	lstrcpy(local->str, str);
	local->proximo = NULL;
	if (*ls == NULL)
		*ls = local;
	else {
		/* procura o ulitmo no */
		for (temp = *ls; temp->proximo != NULL; temp = temp->proximo);
    local->ordem = temp->ordem;
    local->ordem++;
		temp->proximo = local;
	}	
}

BOOL ListaStr_remove(LISTASTR ls, LPTSTR *str)
{
	LISTASTR local;

	if ((ls == NULL) || (ls->proximo == NULL)) {
		// remoção nula
		return FALSE;
	}
	local = ls->proximo;
	*str = local->str;
	ls->proximo = local->proximo;
	ListaStr_libera(local);
	return TRUE;
}

VOID ListaStr_arrumaOrdem(LISTASTR ls)
{
LISTASTR local;
UINT nordem;

  nordem = 0;
  for (local = ls; local != NULL; local = local->proximo) {
    local->ordem = nordem;
 	  nordem++;
  }
}

VOID ListaStr_removeItem(LISTASTR *ls, LPTSTR str, BOOL bArrumaOrdem)
{
	LISTASTR local, temp;

	LPTSTR localstr;
	temp = NULL;
	local = *ls;
	while (local != NULL) {	
		if (local->str == str){
			local = local->proximo;
			if (temp == NULL){
				/* remove o primeiro no da lista */
				ListaStr_libera(*ls);
				*ls = local;
			} else
				ListaStr_remove(temp, &localstr);
		} else {
			temp = local;
			local = local->proximo;
		}
	}
	if (bArrumaOrdem)	
  	ListaStr_arrumaOrdem(*ls);
}

VOID ListaStr_removeItemOrd(LISTASTR *ls, UINT ordem, BOOL bArrumaOrdem)
{
	LISTASTR local, temp;

	LPTSTR localstr;
	temp = NULL;
	local = *ls;
	while (local != NULL) {	
		if (local->ordem == ordem){
			local = local->proximo;
			if (temp == NULL){
				/* remove o primeiro no da lista */
				ListaStr_libera(*ls);
				*ls = local;
			} else
				ListaStr_remove(temp, &localstr);
		} else {
			temp = local;
			local = local->proximo;
		}
	}
	if (bArrumaOrdem)
  	ListaStr_arrumaOrdem(*ls);
}

VOID ListaStr_removeTodos(LISTASTR ls)
{ INT ncont, ntotal;
  ntotal = ListaStr_conta(ls);  
  for (ncont=0; ncont < ntotal; ncont++)
    ListaStr_removeItemOrd(&ls, ncont, FALSE);
}

BOOL ListaStr_pesquisaItem(LISTASTR ls, LPTSTR str)
{
	LISTASTR local;

	for (local = ls; local != NULL; local = local->proximo) {
		if (lstrcmp(local->str, str)==0)
			return TRUE;
	}
	return FALSE;
}

LPTSTR ListaStr_pesquisaItemOrd(LISTASTR ls, UINT ordem)
{
	LISTASTR local;  
	for (local = ls; local != NULL; local = local->proximo) {
    if (local->ordem == ordem)
      return local->str;
	}
	return "";
}

INT ListaStr_conta(LISTASTR ls)
{
	LISTASTR local;
	INT ncont;
	ncont = 0;
	for (local = ls; local != NULL; local = local->proximo)
		ncont++;

	return ncont;
}

/* Lista de array de strings */

LISTAMSTR ListaStr_alocaM()
{
	LISTAMSTR ls;
	ls = (LISTAMSTR) GlobalAlloc(GPTR, sizeof(struct nomstr));
	
	return(ls);
}

LISTAMSTR ListaStr_iniciaM()
{
  return NULL;
}

VOID ListaStr_liberaM(LISTAMSTR ls)
{
	GlobalFree(ls);
}

VOID ListaStr_insereFimM(LISTAMSTR *ls, LPTSTR str[])
{
	LISTAMSTR local, temp;
	UINT ncont;

	local = ListaStr_alocaM();
	local->ordem = 0;
	for (ncont = 0; ncont < QTD_MAX_COL; ncont++)
		lstrcpy(local->str[ncont], str[ncont]);
	local->proximo = NULL;
	if (*ls == NULL)
		*ls = local;
	else {
		/* procura o ulitmo no */
		for (temp = *ls; temp->proximo != NULL; temp = temp->proximo);
    local->ordem = temp->ordem;
    local->ordem++;
		temp->proximo = local;
	}	
}

BOOL ListaStr_removeM(LISTAMSTR ls, LPTSTR *str[])
{
	LISTAMSTR local;
	UINT ncont;
	if ((ls == NULL) || (ls->proximo == NULL)) {
		// remoção nula
		return FALSE;
	}
	local = ls->proximo;
	for (ncont = 0; ncont < QTD_MAX_COL; ncont++)
		*str[ncont] = local->str[ncont];
	ls->proximo = local->proximo;
	ListaStr_liberaM(local);
	return TRUE;
}

VOID ListaStr_arrumaOrdemM(LISTAMSTR ls)
{
LISTAMSTR local;
UINT nordem;

  nordem = 0;
  for (local = ls; local != NULL; local = local->proximo) {
    local->ordem = nordem;
 	  nordem++;
  }
}

VOID ListaStr_removeItemM(LISTAMSTR *ls, LPTSTR str[], BOOL bArrumaOrdem)
{
	LISTAMSTR local, temp;
	UINT ncont;
	LPTSTR *localstr;
	temp = NULL;
	local = *ls;
	while (local != NULL) {	
		for (ncont = 0; ncont < QTD_MAX_COL; ncont++)
		{
			if (local->str[ncont] == str[ncont]){
				local = local->proximo;
				if (temp == NULL){
					/* remove o primeiro no da lista */
					ListaStr_liberaM(*ls);
					*ls = local;
				} else
					ListaStr_removeM(temp, &localstr);
			} else {
				temp = local;
				local = local->proximo;
			}
		}
	}
	if (bArrumaOrdem)
  	ListaStr_arrumaOrdemM(*ls);
}

VOID ListaStr_removeItemOrdM(LISTAMSTR *ls, UINT ordem, BOOL bArrumaOrdem)
{
	LISTAMSTR local, temp;

	LPTSTR *localstr;
	temp = NULL;
	local = *ls;
	while (local != NULL) {	
		if (local->ordem == ordem){
			local = local->proximo;
			if (temp == NULL){
				/* remove o primeiro no da lista */
				ListaStr_liberaM(*ls);
				*ls = local;
			} else
			  	ListaStr_removeM(temp, &localstr);
		} else {
			temp = local;
			local = local->proximo;
		}
	}
	if (bArrumaOrdem)
  	ListaStr_arrumaOrdemM(*ls);
}

VOID ListaStr_removeTodosM(LISTAMSTR ls)
{ INT ncont, ntotal;
  ntotal = ListaStr_contaM(ls);
  for (ncont=0; ncont < ntotal; ncont++)
    ListaStr_removeItemOrdM(&ls, ncont, FALSE);
}

BOOL ListaStr_pesquisaItemM(LISTAMSTR ls, LPTSTR str)
{
	LISTAMSTR local;
	UINT ncont;
	for (local = ls; local != NULL; local = local->proximo) {
		for (ncont = 0; ncont < QTD_MAX_COL; ncont++) {
			if (lstrcmp(local->str[ncont], str)==0)
				return TRUE;
		}
	}
	return FALSE;
}

LPTSTR ListaStr_pesquisaItemOrdM(LISTAMSTR ls, UINT coluna, UINT ordem)
{
	LISTAMSTR local;

	for (local = ls; local != NULL; local = local->proximo) {
		if (local->ordem == ordem)
			return local->str[coluna];
	}
	return "";
}

INT ListaStr_contaM(LISTAMSTR ls)
{
	LISTAMSTR local;
	INT ncont;
	ncont = 0;
	for (local = ls; local != NULL; local = local->proximo)
		ncont++;

	return ncont;
}

