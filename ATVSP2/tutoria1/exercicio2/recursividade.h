#ifndef RECURSIVIDADE
#define RECURSIVIDADE

# define MAXTAM 1000
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
} TItem ;

typedef struct {
    TItem lista[MAXTAM];
    int ultimo;
} TLista ;

void TLista_FazVazia ( TLista * pLista );
int recursividade(TLista *plista, int posicao);
int TLista_Insere ( TLista * pLista , TItem x);

#endif