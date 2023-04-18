#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int numero;
}Item;

typedef struct cel{
    Item item;
    struct cel *prox;
}Celula;

typedef struct{
    Celula *cabeca;
}Pilha;

int pilhaInicia(Pilha *pilha);
int pilhaEhVazia(Pilha *pilha);
int pilhaPush(Pilha *pilha, Item item);
int pilhaPop(Pilha *pilha,Item *item);
void pilhaLibera(Pilha *pilha);
int procuraMenorValor(Pilha *pilha);
 
int main() {

    Pilha pilha;
    int n;
    Item item;

    scanf("%d",&n);
    getchar();

    pilhaInicia(&pilha);

    for(int i = 0;i < n;i++){
        char comando[6];
        scanf("%s",comando);

        getchar();

        int num;

        if(!strcmp(comando,"PUSH")){
            scanf("%d",&num);
            item.numero = num;
            pilhaPush(&pilha,item);
        }else if(!strcmp(comando,"POP")){
            if(pilhaEhVazia(&pilha)){
                printf("EMPTY\n");
            }else{
                pilhaPop(&pilha,&item);
            }
        }else if(!strcmp(comando,"MIN")){
            if(pilhaEhVazia(&pilha)){
                printf("EMPTY\n");
            }else{
                printf("%d\n",procuraMenorValor(&pilha));
            }
        }
    }

    pilhaLibera(&pilha);
    
 
    return 0;
}

int pilhaInicia(Pilha *pilha){
    pilha->cabeca = (Celula *)malloc(sizeof(Celula));
    pilha->cabeca->prox = NULL;
    return 1;
}

int pilhaEhVazia(Pilha *pilha){
    if (pilha->cabeca->prox == NULL){
        return 1;
    }
    return 0;
}

int pilhaPush(Pilha *pilha,Item item){
    Celula *aux = (Celula*)malloc(sizeof(Celula));
    aux->item = item;
    aux->prox = pilha->cabeca->prox;
    pilha->cabeca->prox = aux;
    return 1;
}

int pilhaPop(Pilha *pilha,Item *item){
    if (pilhaEhVazia(pilha)){
        return 0;
    }    
    Celula *aux;
    aux = pilha->cabeca->prox;
    *item = aux->item;
    pilha->cabeca->prox = aux->prox;
    free(aux);
    return 1;
}
void pilhaLibera(Pilha *pilha){
    Celula *aux, *aux1;
    aux = pilha->cabeca;
    while (aux != NULL){
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    }
}

int procuraMenorValor(Pilha *pilha){
    Celula *aux = pilha->cabeca->prox;
    int menor = 1000000000;
    while(aux != NULL){
        if(aux->item.numero < menor){
            menor = aux->item.numero;
        }
        aux = aux->prox;
    }

    return menor;
}

