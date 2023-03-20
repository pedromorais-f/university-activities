#include <stdio.h>
#include "f91.h"

int main (){
    int n,resultado;
    scanf("%d",&n);

    while(n != 0){
        resultado = f91(n);
        printf("f91(%d) = %d\n",n,resultado);
        scanf("%d",&n);
    }

    return 0;
}