#include "ListaStr.h"

/* Lista de strings */

CListaStr *ListaStr;

CListaStr::CListaStr() {
}

LISTASTR CListaStr::aloca()
{
	LISTASTR ls;
	ls = (LISTASTR) malloc(sizeof(struct nostr));
	
	return(ls);
}

LISTASTR CListaStr::inicia() 
{
  return NULL;
}

void CListaStr::libera(LISTASTR ls)
{
	free(ls);
}

void CListaStr::insereFim(LISTASTR *ls, char *str)
{
	LISTASTR local, temp;

	local = CListaStr::aloca();
  local->ordem = 0;
	strcpy(local->str, str);
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

bool CListaStr::remove(LISTASTR ls, char **str)
{
	LISTASTR local;

	if ((ls == NULL) || (ls->proximo == NULL)) {
		// remoção nula
		return false;
	}
	local = ls->proximo;
	*str = local->str;
	ls->proximo = local->proximo;
	CListaStr::libera(local);
	return true;
}

void CListaStr::arrumaOrdem(LISTASTR ls)
{
LISTASTR local;
unsigned int nordem;

  nordem = 0;
  for (local = ls; local != NULL; local = local->proximo) {
    local->ordem = nordem;
 	  nordem++;
  }
}

void CListaStr::removeItem(LISTASTR *ls, char *str, bool bArrumaOrdem)
{
	LISTASTR local, temp;

	char *localstr;
	temp = NULL;
	local = *ls;
	while (local != NULL) {	
		if (local->str == str){
			local = local->proximo;
			if (temp == NULL){
				/* remove o primeiro no da lista */
				CListaStr::libera(*ls);
				*ls = local;
			} else
				CListaStr::remove(temp, &localstr);
		} else {
			temp = local;
			local = local->proximo;
		}
	}
	if (bArrumaOrdem)	
  	CListaStr::arrumaOrdem(*ls);
}

void CListaStr::removeItemOrd(LISTASTR *ls, unsigned int ordem, 
  bool bArrumaOrdem)
{
	LISTASTR local, temp;

	char *localstr;
	temp = NULL;
	local = *ls;
	while (local != NULL) {	
		if (local->ordem == ordem){
			local = local->proximo;
			if (temp == NULL){
				/* remove o primeiro no da lista */
				CListaStr::libera(*ls);
				*ls = local;
			} else
				CListaStr::remove(temp, &localstr);
		} else {
			temp = local;
			local = local->proximo;
		}
	}
	if (bArrumaOrdem)
  	CListaStr::arrumaOrdem(*ls);
}

void CListaStr::removeTodos(LISTASTR ls)
{ int ncont, ntotal;
  ntotal = CListaStr::conta(ls);  
  for (ncont=0; ncont < ntotal; ncont++)
    CListaStr::removeItemOrd(&ls, ncont, false);
}

bool CListaStr::pesquisaItem(LISTASTR ls, char *str)
{
	LISTASTR local;

	for (local = ls; local != NULL; local = local->proximo) {
		if (strcmp(local->str, str)==0)
			return true;
	}
	return false;
}

char *CListaStr::pesquisaItemOrd(LISTASTR ls, unsigned int ordem)
{
	LISTASTR local;  
	for (local = ls; local != NULL; local = local->proximo) {
    if (local->ordem == ordem)
      return local->str;
	}
	return "";
}

int CListaStr::conta(LISTASTR ls)
{
	LISTASTR local;
	int ncont;
	ncont = 0;
	for (local = ls; local != NULL; local = local->proximo)
		ncont++;

	return ncont;
}

/* Lista de array de strings */

LISTAMSTR CListaStr::alocaM()
{
	LISTAMSTR ls;
	ls = (LISTAMSTR) malloc(sizeof(struct nomstr));
	
	return(ls);
}

LISTAMSTR CListaStr::iniciaM()
{
  return NULL;
}

void CListaStr::liberaM(LISTAMSTR ls)
{
	free(ls);
}

void CListaStr::insereFimM(LISTAMSTR *ls, char *str[])
{
	LISTAMSTR local, temp;
	unsigned int ncont;

	local = CListaStr::alocaM();
	local->ordem = 0;
  for (ncont = 0; ncont < QTD_MAX_COL; ncont++)
		strcpy(local->str[ncont], str[ncont]); 
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

bool CListaStr::removeM(LISTAMSTR ls, char **str[])
{
	LISTAMSTR local;
	unsigned int ncont;
	if ((ls == NULL) || (ls->proximo == NULL)) {
		// remoção nula
		return false;
	}
	local = ls->proximo;
	for (ncont = 0; ncont < QTD_MAX_COL; ncont++)
		*str[ncont] = local->str[ncont];
	ls->proximo = local->proximo;
	CListaStr::liberaM(local);
	return true;
}

void CListaStr::arrumaOrdemM(LISTAMSTR ls)
{
LISTAMSTR local;
unsigned int nordem;

  nordem = 0;
  for (local = ls; local != NULL; local = local->proximo) {
    local->ordem = nordem;
 	  nordem++;
  }
}

void CListaStr::removeItemM(LISTAMSTR *ls, char *str[], bool bArrumaOrdem)
{
	LISTAMSTR local, temp;
	unsigned int ncont;
	char **localstr;

	temp = NULL;
	local = *ls;
	while (local != NULL) {	
		for (ncont = 0; ncont < QTD_MAX_COL; ncont++)
		{
			if (local->str[ncont] == str[ncont]){
				local = local->proximo;
				if (temp == NULL){
					/* remove o primeiro no da lista */
					CListaStr::liberaM(*ls);
					*ls = local;
				} else
					CListaStr::removeM(temp, &localstr);
			} else {
				temp = local;
				local = local->proximo;
			}
		}
	}
	if (bArrumaOrdem)
  	CListaStr::arrumaOrdemM(*ls);
}

void CListaStr::removeItemOrdM(LISTAMSTR *ls, unsigned int ordem, 
  bool bArrumaOrdem)
{
	LISTAMSTR local, temp;

	char **localstr;
	temp = NULL;
	local = *ls;
	while (local != NULL) {	
		if (local->ordem == ordem){
			local = local->proximo;
			if (temp == NULL){
				/* remove o primeiro no da lista */
				CListaStr::liberaM(*ls);
				*ls = local;
			} else
			  	CListaStr::removeM(temp, &localstr);
		} else {
			temp = local;
			local = local->proximo;
		}
	}
	if (bArrumaOrdem)
  	CListaStr::arrumaOrdemM(*ls);
}

void CListaStr::removeTodosM(LISTAMSTR ls)
{ int ncont, ntotal;
  ntotal = CListaStr::contaM(ls);
  for (ncont=0; ncont < ntotal; ncont++)
    CListaStr::removeItemOrdM(&ls, ncont, false);
}

bool CListaStr::pesquisaItemM(LISTAMSTR ls, char *str)
{
	LISTAMSTR local;
	unsigned int ncont;
	for (local = ls; local != NULL; local = local->proximo) {
		for (ncont = 0; ncont < QTD_MAX_COL; ncont++) {
			if (strcmp(local->str[ncont], str)==0)
				return true;
		}
	}
	return false;
}

char *CListaStr::pesquisaItemOrdM(LISTAMSTR ls, unsigned int coluna, 
  unsigned int ordem)
{
	LISTAMSTR local;

	for (local = ls; local != NULL; local = local->proximo) {
		if (local->ordem == ordem)
			return local->str[coluna];
	}
	return "";
}

int CListaStr::contaM(LISTAMSTR ls)
{
	LISTAMSTR local;
	int ncont;
	ncont = 0;
	for (local = ls; local != NULL; local = local->proximo)
		ncont++;

	return ncont;
}

