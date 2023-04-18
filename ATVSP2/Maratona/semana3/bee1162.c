#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *length;
    int swaps;
    int cases;
}Train;

void bubbleSort(Train *arr, int trainLength);
 
int main(){
 
    Train train;
    scanf("%d",&train.cases);

    for(int i = 0;i < train.cases;i++){
        int trainLength;
        scanf("%d",&trainLength);

        int numbers;

        train.length = (int*)malloc(trainLength * sizeof(Train));

        for(int j = 0;j < trainLength;j++){
            scanf("%d",&numbers);
            train.length[j] = numbers;
        }

        bubbleSort(&train,trainLength);

        printf("Optimal train swapping takes %d swaps.\n",train.swaps);

        free(train.length);
    }
 
    return 0;
}

void bubbleSort(Train *arr, int trainLength){
    int aux;
    arr->swaps = 0;
    
    for(int i = 0; i < trainLength; i++){
        for (int j = 1; j < trainLength-i; j++){
            if(arr->length[j] < arr->length[j-1]){
                aux = arr->length[j];
                arr->length[j] = arr->length[j-1];
                arr->length[j - 1] = aux;
                arr->swaps+=1;   
            }
        }   
    }
}