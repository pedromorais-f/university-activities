#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int carta;
} Item;

typedef struct cel {
    Item item;
    struct cel *prox;
 }Celula;

typedef struct {
    Celula *cabeca;
    Celula *fim;
 }Fila;

int filaDesinfileira(Fila *f,Item *item);
int filaInicia(Fila *f);
void filaEnfileira(Fila *f,Item x);
void filaLibera(Fila *f);
void porNoFinal(Fila *f,int *cartaRemovida);
int qtdElementos(Fila *f);


int main() {
 
    Item t;
    Fila fila;
    int contador,descarte,tam;

    int n;
    scanf("%d",&n);

    while(n != 0){
        filaInicia(&fila);

        for(int i = 1;i <= n;i++){
            t.carta = i;
            filaEnfileira(&fila,t);
        }
        tam = qtdElementos(&fila);
        contador = 0;
        int cartasretiradas[n];
        while(tam >= 2){
            porNoFinal(&fila,&descarte);
            cartasretiradas[contador++] = descarte;
            tam--;
        }
        printf("Discarded cards: %d",cartasretiradas[0]);
        for(int j = 1;j < contador;j++){
            printf(", %d",cartasretiradas[j]);
        }
        printf("\n");

        printf("Remaining card: %d\n",fila.fim->item.carta);
        filaLibera(&fila);
        scanf("%d",&n);
    }
 
    return 0;
}

int filaInicia(Fila *f){
    f->cabeca = (Celula*) malloc(sizeof(Celula));
    f->fim = f->cabeca;
    return 1;
}

void filaEnfileira(Fila *f,Item x){
    Celula *aux;
    aux = (Celula*) malloc(sizeof(Celula));
    aux->item = x;
    aux->prox = NULL;
    f->fim->prox = aux;
    f->fim = aux;
}

void filaLibera(Fila *f){
    Celula *aux,*aux1;
    aux = f->cabeca;
    while(aux != NULL){
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    }
}

void porNoFinal(Fila *f,int *cartaRemovida){
    Celula *aux = f->cabeca->prox;
    f->cabeca->prox = f->cabeca->prox->prox;
    *cartaRemovida = aux->item.carta;
    free(aux);
    Celula *aux1;
    aux1 = f->cabeca->prox;
    f->cabeca->prox = f->cabeca->prox->prox;
    filaEnfileira(f,aux1->item);
    free(aux1);
}

int filaDesinfileira(Fila *f,Item *item){
    Celula *aux = f->cabeca->prox;
    *item = aux->item;
    f->cabeca->prox = f->cabeca->prox->prox;
    free(aux);
    return 1;
}

int qtdElementos(Fila *f){
    int tam = 0;
    Celula *aux;
    aux = f->cabeca->prox;
    while(aux != NULL){
        tam++;
        aux = aux->prox;
    }

    return tam;
}


