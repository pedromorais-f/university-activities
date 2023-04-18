#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*,int);
void merge(int*,int,int,int);
 
int main(){

    int lines;
    scanf("%d",&lines);

    int *even;
    int *odd;
    int a = 0,b = 0;

    int n;
    even = malloc(lines * sizeof(int));
    odd = malloc(lines * sizeof(int));

    for(int i = 0;i < lines;i++){
        scanf("%d",&n);
        if(n % 2 == 0){
            even[a++] = n;
        }else{
            odd[b++] = n;
        }
    }
    
    mergeSort(even,a);
    mergeSort(odd,b);

    for(int i = 0;i < a;i++){
        printf("%d\n",even[i]);
    }
    for(int j = b - 1;j >= 0;j--){
        printf("%d\n",odd[j]);
    }

    free(even);
    free(odd);
 
    return 0;
}

void mergeSort(int *arr,int length){
    int left,right;
    int aux = 1;
    while(aux < length){
        left = 0;
        while(left + aux < length){
            right = left + 2 * aux;
            if(right > length){
                right = length;
            }
            merge(arr,left,left + aux - 1,right - 1);
            left = left + 2 * aux;
        }
        aux = 2 * aux;
    }
}

void merge(int *arr,int left,int mid,int right){
    int i,j,k;

    int length1 = mid - left + 1;
    int length2 = right - mid;

    int leftArr[length1];
    int rightArr[length2];

    for(i = 0;i < length1;i++){
        leftArr[i] = arr[i + left];
    }
    for(i = 0;i < length2;i++){
        rightArr[i] = arr[i + mid + 1];
    }

    for(i = 0,j = 0,k = left;k <= right;k++){
        if(i == length1){
            arr[k] = rightArr[j++];
        }else if(j == length2){
            arr[k] = leftArr[i++];
        }else if(leftArr[i] < rightArr[j]){
            arr[k] = leftArr[i++];
        }else{
            arr[k] = rightArr[j++];
        }
    }
}