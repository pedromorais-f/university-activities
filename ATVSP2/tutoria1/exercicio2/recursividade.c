#include "recursividade.h"

void TLista_FazVazia ( TLista * pLista ) {
    pLista->ultimo = 0;
}

int TLista_Insere ( TLista * pLista , TItem x) {
    if(pLista->ultimo == MAXTAM){
        return 0;
    }
    pLista->lista[pLista->ultimo++] = x;
    return 1;
}

int recursividade(TLista* pLista, int posicao){
    int numeros = pLista->lista[posicao].n;
    
    if(posicao != pLista->ultimo){
        return numeros + recursividade(pLista,posicao + 1);
    }

    return numeros;
}