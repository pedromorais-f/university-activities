#include <stdio.h>
#include <stdlib.h>

void quicksort(int*,int,int);
void positionChanged(int*,int*,int*);

 
int main(){
 
    int nc;
    scanf("%d",&nc);

    for(int i = 0; i < nc; i++){
        int n;
        scanf("%d",&n);

        int *h = malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            scanf("%d",&h[j]);
        }

        quicksort(h,0,n-1);

        printf("%d",h[0]);
        for(int k = 1; k < n; k++){
            printf(" %d",h[k]);
        }
        printf("\n");

        free(h);
    }
 
    return 0;
}

void positionChanged(int *arr, int *i, int *j){
    int aux;

    aux = arr[*i];
    arr[*i] = arr[*j];
    arr[*j] = aux;
    *i += 1;
    *j -= 1;
}


void quicksort(int *arr, int begin, int end){
    int i,j;
    int pivot; 

    i = begin;
    j = end;
    pivot = arr[(begin + end) / 2];

    while (i <= j){
        while(arr[i] < pivot && i < end){
            i++;
        }
        while(arr[j] > pivot && j > begin){
            j--;
        }
        if(i <= j){
            positionChanged(arr,&i,&j);
        }
    }

    if(j > begin){
        quicksort(arr,begin,j);
    }

    if (i < end){
        quicksort(arr, i, end);
    }
}


