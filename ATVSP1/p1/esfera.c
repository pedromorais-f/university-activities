#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

  int main(){
	//declaração das variáveis
	double r;  
  	printf("Declare o valor do raio:");
  	scanf("%lf",&r);
  	
  	//cálculo
  	double raio=r;
  	double volume=(4.0/3.0)*PI*pow(raio,3);
  	
  	//saída dos dados fornecidos
  	printf("volume=%lf \n",volume);
  	return 0;
  	
  }
