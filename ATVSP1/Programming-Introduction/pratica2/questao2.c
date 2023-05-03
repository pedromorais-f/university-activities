#include <stdio.h>
int main(){
   // declaração de variáveis
   float x1,x2,x3,y;
   //entrada de dados
   printf("Entre com os valores de x1, x2 e x3:");
   scanf("%f %f %f" , &x1,&x2,&x3);
   
   //cálculo
   y=(x1+(x2*x2)+(x3*x3))*(x1+(x2*x2)+(x3*x3))-(x1*x2*x3)*(x1*x2*x3);
   //saída de dados
   printf ("y=%.2f",y);
   return 0;
}
