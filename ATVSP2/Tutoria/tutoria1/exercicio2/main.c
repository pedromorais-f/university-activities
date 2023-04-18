#include "recursividade.h"

int main(){
    
    TItem num;
    TLista *lista;

    lista = (TLista *)malloc(sizeof(TLista));
    TLista_FazVazia(lista);

    while (scanf("%d",&num.n) != EOF){
        TLista_Insere(lista,num);
    }

    printf("%d\n",recursividade(lista,0));

    free(lista);

    return 0;
}