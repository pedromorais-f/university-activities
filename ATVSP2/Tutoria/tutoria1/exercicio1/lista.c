#include "lista.h"

void TLista_Inicia (TLista * pLista ) {
    pLista->pPrimeiro = (TCelula*) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->prox = NULL;
}

int TLista_EhVazia ( TLista * pLista ) {
    return (pLista->pPrimeiro == pLista->pUltimo);
}

int TLista_Insere_Fim ( TLista * pLista , char x) {
    pLista->pUltimo->prox = (TCelula*) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pUltimo->prox;
    pLista->pUltimo->item.c = x;
    pLista->pUltimo->prox = NULL;
    return 1;
}

int TLista_Insere_Inicio ( TLista * pLista , char x){
    TCelula *pAux;
    pAux = (TCelula*) malloc(sizeof(TCelula));
    pAux->prox = pLista->pPrimeiro->prox;
    pAux->item.c = x;
    pLista->pPrimeiro->prox = pAux;
    return 1;
}

void TLista_Esvazia (TLista * pLista){
    TCelula *pAux,*aux;
    pAux = pLista->pPrimeiro;
    while (pAux != NULL){
        aux = pAux;
        pAux = pAux->prox;
        free(aux);
    }   
}

void TLista_Imprime ( TLista * pLista ){
    TCelula *pAux;
    pAux = pLista->pPrimeiro->prox;
    while(pAux != NULL){
        printf("%c",pAux->item.c);
        pAux = pAux->prox;
    }
    printf("\n");
}
