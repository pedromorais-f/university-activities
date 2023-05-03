#include <stdio.h>
int main(){
   // declaração de variáveis
   int a,b,c,d,x;
   //entrada de dados
   printf("Entre com os valores de a, b, c, d:");
   scanf("%d %d %d %d" , &a,&b,&c,&d);
   
   //cálculo
   x=a*a*a*((b+c)/d);
   //saída de dados
   printf ("x=%d",x);
   return 0;
}
