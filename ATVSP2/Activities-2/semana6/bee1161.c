#include <stdio.h>

long long int factorial(int n){
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);    
}
 
int main() {
 
    long long int n,m;

    while (scanf("%lld %lld",&n,&m) != EOF){
        long long int sum = 0;
        sum = factorial(n) + factorial(m);

        printf("%lld\n",sum);
    }
    
 
    return 0;
}