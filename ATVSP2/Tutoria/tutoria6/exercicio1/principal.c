#include "busca.h"


int main(){


    int *arr = malloc(MAX_TAM * sizeof(int));

    for(int i = 0; i < MAX_TAM; i++)
        scanf("%d",&arr[i]);


    quicksort(arr, 0, MAX_TAM - 1);

    int key;
    scanf("%d",&key);

    printf("chave %d na posicao %d\n", key, binarySearch(arr, key));


    free(arr);

    return 0;
}