#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TAM 100000

typedef struct {
    char c;
} TItem ;

typedef struct celula {
    struct celula *prox;
    TItem item;
} TCelula ;

typedef struct {
    TCelula *pPrimeiro,*pUltimo;
} TLista ;

void TLista_Inicia ( TLista * pLista );
int TLista_EhVazia ( TLista * pLista );
int TLista_Insere_Fim ( TLista * pLista , char x);
int TLista_Insere_Inicio ( TLista * pLista , char x);
void TLista_Imprime ( TLista * pLista );
void TLista_Esvazia (TLista * pLista);

#endif