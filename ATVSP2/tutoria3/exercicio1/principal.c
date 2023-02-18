#include <stdio.h>
#include "ordenacao.h"

int main(){
    
    int n;
    scanf("%d",&n);

    TADupa *upas;

    alocarUpa(&upas,n);

    preencheVetor(upas,n);

    ordenaUpas(upas,n);

    imprimeUpas(upas,n);

    desalocaUpas(&upas);

    return 0;
}

