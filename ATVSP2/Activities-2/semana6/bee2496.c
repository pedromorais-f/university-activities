#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
  
void selectionSort(char *arr, int n,int *swaps)
{
    int i, j, pos;
  
    for (i = 0; i < n - 1; i++){
        pos = i;
        for (j = i + 1; j < n; j++)
          if (arr[j] < arr[pos])
            pos = j;
  
           if(pos != i){
                swap(&arr[pos],&arr[i]);
                *swaps += 1;
           }
    }
}
  
 
int main() {
 
    int n;
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d",&m);

        getchar();

        char *letters = malloc(m * sizeof(char));
        for(int j = 0; j < m; j++){
            scanf("%c",&letters[j]);
        }

        int swaps = 0;
        selectionSort(letters,m,&swaps);

        if(swaps == 1)
            printf("There are the chance.\n");
        else
            printf("There aren't the chance.\n");

        free(letters);    
    }
 
    return 0;
}