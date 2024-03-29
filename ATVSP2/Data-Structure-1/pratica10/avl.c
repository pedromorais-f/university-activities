#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Manter como especificado */
void inicia(No** ppRaiz) {
    // PREENCHER AQUI
    *ppRaiz = NULL;
}

/* Manter como especificado */
void libera(No** ppRaiz) {
    // PREENCHER AQUI
    if(*ppRaiz == NULL)
        return;
    libera(&(*ppRaiz)->pDir);
    libera(&(*ppRaiz)->pEsq);
    free(*ppRaiz);
}

/* Manter como especificado */
bool insere(No** ppRaiz, Item x) {
    // PREENCHER AQUI
    if(*ppRaiz == NULL){
        *ppRaiz = criaNo(x);
        return true;
    }else if(compara((*ppRaiz)->item,x) == MAIOR){
        if(insere(&(*ppRaiz)->pEsq,x)){
            if(Balanceamento(ppRaiz))
                return 0;
            else
                return 1;
        }
    }else if(compara((*ppRaiz)->item,x) == MENOR){
        if(insere(&(*ppRaiz)->pDir,x)){
            if(Balanceamento(ppRaiz))
                return 0;
            else
                return 1;
        }else
            return 0;
    }else
        (*ppRaiz)->cont++;
        return 0;
}

/* Manter como especificado */
No *criaNo(Item x) {
    // PREENCHER AQUI
    No *ppRaiz;
    ppRaiz = (No*)malloc(sizeof(No));
    ppRaiz->item = x;
    ppRaiz->pDir = NULL;
    ppRaiz->pEsq = NULL;
    ppRaiz->cont = 1;

    return ppRaiz;
}

/* Manter como especificado */
void caminhamento(No *pNo) {
    // PREENCHER AQUI
    if(pNo == NULL)
        return;
    caminhamento(pNo->pEsq);
    printf("%s %d\n",pNo->item.chave,pNo->cont);
    caminhamento(pNo->pDir);
}

/* Manter como especificado */
RELACAO compara(const Item item1, const Item item2) {
    int response = strcmp(item1.chave, item2.chave);
    if (response < 0)
        return MENOR;
    else if (response > 0)
        return MAIOR;
    return IGUAL;
}

/* Manter como especificado */
int FB(No *pRaiz) {
    // PREENCHER AQUI
    if(pRaiz == NULL)
        return 0;
    
    return altura(pRaiz->pEsq) - altura(pRaiz->pDir);
}

/* Manter como especificado */
int altura(No *pRaiz) {
    // PREENCHER AQUI
    int esq,dir;

    if(pRaiz == NULL)
        return 0;

    esq = altura(pRaiz->pEsq);
    dir = altura(pRaiz->pDir);

    if(esq > dir)
        return esq + 1;
    else
        return dir + 1;
}

/* Manter como especificado */
void RSE(No **ppRaiz) {
    // PREENCHER AQUI
    No *aux;
    aux = (*ppRaiz)->pDir;
    (*ppRaiz)->pDir = aux->pEsq;
    aux->pEsq = *ppRaiz;
    *ppRaiz = aux;
}

/* Manter como especificado */
void RSD(No **ppRaiz) {
    // PREENCHER AQUI
    No *aux;
    aux = (*ppRaiz)->pEsq;
    (*ppRaiz)->pEsq = aux->pDir;
    aux->pDir = (*ppRaiz);
    (*ppRaiz) = aux;
}

/* Manter como especificado */
int BalancaEsquerda(No **ppRaiz) {
    // PREENCHER AQUI
    int fbe = FB((*ppRaiz)->pEsq);
    
    if(fbe >= 0){
        RSD(ppRaiz);
        return 1;
    }else{
        RSE(&((*ppRaiz)->pEsq));
        RSD(ppRaiz);
        return 1;
    }
}

/* Manter como especificado */
int BalancaDireita(No **ppRaiz) {
    // PREENCHER AQUI
    int fbd = FB((*ppRaiz)->pDir);

    if(fbd <= 0){
        RSE(ppRaiz);
        return 1;
    }else{
        RSD(&((*ppRaiz)->pDir));
        RSE(ppRaiz);
        return 1;
    }

    return 0;
}

/* Manter como especificado */
int Balanceamento(No **ppRaiz) {
    // PREENCHER AQUI
    int fb = FB(*ppRaiz);   

    if(fb > 1)
        return BalancaEsquerda(ppRaiz);
    else if(fb < -1)
        return BalancaDireita(ppRaiz);
    else
        return 0;
}
