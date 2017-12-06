#ifndef LISTASTR_H
#define LISTASTR_H

#include "resource.h"

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

class CListaStr
{
public:
  CListaStr();

  LISTASTR aloca();
  LISTASTR inicia();
  void libera(LISTASTR ls);
  void insereFim(LISTASTR *ls, char *str);
  bool remove(LISTASTR ls, char **str);
  void arrumaOrdem(LISTASTR ls);
  void removeItem(LISTASTR *ls, char *str, bool bArrumaOrdem);
  void removeItemOrd(LISTASTR *ls, unsigned int ordem, 
    bool bArrumaOrdem);
  void removeTodos(LISTASTR ls);
  bool pesquisaItem(LISTASTR ls, char *str);
  char *pesquisaItemOrd(LISTASTR ls, unsigned int ordem);
  int conta(LISTASTR ls);
  
  LISTAMSTR alocaM();
  LISTAMSTR iniciaM();
  void liberaM(LISTAMSTR ls);
  void insereFimM(LISTAMSTR *ls, char *str[]);
  bool removeM(LISTAMSTR ls, char **str[]);
  void arrumaOrdemM(LISTAMSTR ls);
  void removeItemM(LISTAMSTR *ls, char *str[], bool bArrumaOrdem);
  void removeItemOrdM(LISTAMSTR *ls, unsigned int ordem, 
    bool bArrumaOrdem);
  void removeTodosM(LISTAMSTR ls);
  bool pesquisaItemM(LISTAMSTR ls, char *str);
  char *pesquisaItemOrdM(LISTAMSTR ls, unsigned int coluna, 
    unsigned int ordem);
  int contaM(LISTAMSTR ls);
};

extern CListaStr *ListaStr;

#endif


