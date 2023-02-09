#include "fila.h"
#include "pilha.h"

bool FilaInicia(Fila* pFila) {
    /* Preencher aqui */
    return ListaInicia(pFila);
}

bool FilaEnfileira(Fila* pFila, Item item) {
    /* Preencher aqui */
    return ListaInsereFinal(pFila,item);
}

bool FilaDesinfeleira(Fila* pFila, Item* pItem) {
    /* Preencher aqui */
    return ListaRetiraPrimeiro(pFila,pItem);
}

bool FilaEhVazia(Fila* pFila) {
    /* Preencher aqui */
    return ListaEhVazia(pFila);
}

void FilaLibera(Fila* pFila) {
    /* Preencher aqui */
    return ListaLibera(pFila);
}

bool FilaInverte(Fila* pFila) {
    /* Preencher aqui*/ 
    Pilha pilha;
    Celula *aux;
    Item x;

    PilhaInicia(&pilha);
    
    aux = pFila->cabeca->prox;
    while(aux != NULL){
        PilhaPush(&pilha,aux->item);
        FilaDesinfeleira(pFila,&x);
        aux = aux->prox;
    }

    pFila->ultimo = pFila->cabeca;

    aux = pilha.cabeca->prox;
    while(aux != NULL){
        FilaEnfileira(pFila,aux->item);
        aux = aux->prox;
    }

    PilhaLibera(&pilha);
    return true;
}
