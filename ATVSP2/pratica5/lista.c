#include "lista.h"
#include <stdlib.h>

bool ListaInicia(Lista* pLista) {
    pLista->cabeca = (Celula*) malloc(sizeof(Celula));
    if (pLista->cabeca == NULL)
        return false;
    pLista->ultimo = pLista->cabeca;
    return true;
}

bool ListaEhVazia(Lista* pLista) {
    if(pLista->cabeca == pLista->ultimo)
        return true;
    return false;
}

bool ListaInsereFinal(Lista* pLista, Item item) {
    /* Preencher aqui */
    pLista->ultimo->prox = (Celula*) malloc(sizeof(Celula));
    pLista->ultimo = pLista->ultimo->prox;
    pLista->ultimo->item = item;
    pLista->ultimo->prox = NULL;
    return true;
}

bool ListaInsereInicio(Lista* pLista, Item item) {
    /* Preencher aqui */
    pLista->cabeca->prox = (Celula*) malloc(sizeof(Celula));
    pLista->cabeca = pLista->cabeca->prox;
    pLista->cabeca->item = item;
    return true;
}

bool ListaRetiraPrimeiro(Lista* pLista, Item* pItem) {
    /* Preencher aqui */
    if(ListaEhVazia(&pLista))
        return false;
    Celula *pAux;
    pAux = pLista->cabeca->prox;
    *pItem = pAux->item;
    pLista->cabeca->prox = pAux->prox;
    free(pAux);
    return true;    
}

void ListaLibera(Lista* pLista) {
    /* Preencher aqui */
    Celula *pAux,*aux;
    pAux = pLista->cabeca;
    while(pAux != NULL){
        aux = pAux;
        pAux = pAux->prox;
        free(aux);
    }
}