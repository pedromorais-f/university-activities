#include "r9.h"
#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    while(n != 0){
        if(soma_r9(n) % 9 == 0){
            printf("%d is a multiple of 9\n",n);
        }else{
            printf("%d is not a multiple of 9\n",n);
        }

        scanf("%d",&n);
    }

    return 0;
}