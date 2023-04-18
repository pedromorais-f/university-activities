#include <stdio.h>
#include <stdlib.h>

void positionChanged(long int *arr, int *i, int *j){
    int aux;

    aux = arr[*i];
    arr[*i] = arr[*j];
    arr[*j] = aux;
    *i += 1;
    *j -= 1;
}


void quicksort(long int *arr, int begin, int end){
    int i,j;
    long int pivot; 

    i = begin;
    j = end;
    pivot = arr[(begin + end) / 2];

    while (i <= j){
        while(arr[i] > pivot && i < end){
            i++;
        }
        while(arr[j] < pivot && j > begin){
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


 
int main() {
 
    int s;
    scanf("%d",&s);

    long int *quadradonia = malloc(s * sizeof(long int));
    for(int i = 0; i < s; i++)
        scanf("%ld",&quadradonia[i]);
    
    long int *nlogonia = malloc(s * sizeof(long int));
    for(int j = 0; j < s; j++)
        scanf("%ld",&nlogonia[j]);


    quicksort(quadradonia, 0, s - 1);
    quicksort(nlogonia, 0, s - 1);

    int wins = 0, counter = 0;
    for(int k = 0; k < s; k++){
        if(nlogonia[counter] > quadradonia[k]){
            counter++;
            wins++;
        }
    }


    printf("%d\n",wins);

    free(nlogonia);
    free(quadradonia);
 
    return 0;
}