#include <stdio.h>
int main(){
   // declaração de variáveis
   float f,k,c;
   //entrada de dados
   printf("Entre com o valor em graus Celsius: ");
   scanf("%f",&c);
   
   //cálculo
   f=(1.8*c) +32;k=c+ 273.15;
   //saída de dados
   printf ("Celsius: c= %.2f \n Fahrenheit: f= %.2f \n Kelvin: k= %.2f \n" ,c,f,k);
   return 0;
}
