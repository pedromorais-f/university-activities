#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[21];
    int d;
}Barbecue;


void positionChanged(Barbecue *arr, int *i, int *j){
    Barbecue aux;

    aux = arr[*i];
    arr[*i] = arr[*j];
    arr[*j] = aux;
    *i += 1;
    *j -= 1;
}


void quicksort(Barbecue *arr, int begin, int end){
    int i,j;
    Barbecue pivot; 

    i = begin;
    j = end;
    pivot = arr[(begin + end) / 2];

    while (i <= j){
        while(arr[i].d < pivot.d && i < end){
            i++;
        }
        while(arr[j].d > pivot.d && j > begin){
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
 
    int cases;

    while(scanf("%d",&cases) != EOF){
        Barbecue *meat;
        
        meat = (Barbecue*) malloc(cases * sizeof(Barbecue));
        for(int i = 0; i < cases; i++){
            scanf("%s %d",meat[i].name,&meat[i].d);
        }

        quicksort(meat,0,cases - 1);

        printf("%s",meat[0].name);
        for(int j = 1; j < cases; j++){
            printf(" %s",meat[j].name);
        }
        printf("\n");

        free(meat);
    }
 
    return 0;
}