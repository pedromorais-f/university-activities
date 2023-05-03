#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
//semelhante ao visto em aula
    pLista->pPrimeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->prox = NULL;
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
//semelhante ao visto em aula
    return (pLista->pPrimeiro == pLista->pUltimo);
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
//semelhante ao visto em aula
    pLista->pUltimo->prox = (TCelula*) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pUltimo->prox;
    pLista->pUltimo->item = x;
    pLista->pUltimo->prox = NULL;
    return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
//semelhante ao visto em aula
    if(TLista_EhVazia(pLista)){
        return 0;
    }
    TCelula *pAux;
    pAux = pLista->pPrimeiro->prox;
    *pX = pAux->item;
    pLista->pPrimeiro->prox = pAux->prox;
    free(pAux);
    return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {
//semelhante ao visto em aula
    TCelula *pAux;
    pAux = pLista->pPrimeiro->prox; 
    while(pAux != NULL){
        printf("%s ",pAux->item.nome);
        pAux = pAux->prox;
    }
    printf("\n");
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
//preencher
    TCelula *pAux,*aux;
    pAux = pLista->pPrimeiro;
    while(pAux != NULL){
        aux = pAux;
        pAux = pAux->prox;
        free(aux);
    }
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
//preencher
    pLista1->pUltimo->prox = pLista2->pPrimeiro->prox;
    pLista1->pUltimo = pLista2->pUltimo;
    free(pLista2->pPrimeiro);  
}


// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
//preencher
    TCelula *pAux;
    pAux = pLista1->pPrimeiro;
    while(strcmp(pAux->prox->item.nome,str) != 0){
        pAux = pAux->prox;
    }
    pLista2->pUltimo->prox = pAux->prox;
    pAux->prox = pLista2->pPrimeiro->prox;
    free(pLista2->pPrimeiro);
}
