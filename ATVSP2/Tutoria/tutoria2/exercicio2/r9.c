#include "r9.h"

int soma_r9(int n){
    int digito = n % 10;
    if(n > 0){
        return digito + soma_r9(n / 10);
    }
    return n;   
}