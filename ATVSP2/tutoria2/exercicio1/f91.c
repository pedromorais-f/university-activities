#include "f91.h"

int f91 (int n){
    if(n >= 101){
        return n - 10;
    }else{
        return f91(f91(n + 11));
    }
}