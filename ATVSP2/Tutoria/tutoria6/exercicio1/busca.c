#include "busca.h"

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

    if(i < end){
        quicksort(arr, i, end);
    }
}

int binarySearch(int *arr, int key){
    int i, begin, end;

    begin = 0;
    end = MAX_TAM - 1;

    do{
        i = (begin + end) / 2;
        
        if(key > arr[i])
            begin = i + 1;
        else
            end = i - 1;

    } while (key != arr[i] && begin <= end);   
    
    if(key == arr[i])
        return i;
    else
        return -1;    
}