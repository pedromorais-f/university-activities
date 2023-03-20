#include <stdio.h>
  int main() {
 	
     	// declaração das variáveis do problemas
     	float metros,kilometros;
     	printf("Declare a velocidade para a conversão:");
     	scanf("%f",&metros);
     
  	// cálculo
     	kilometros=metros*3.6;
     
  	//saída de dados
    	printf("kilometros=%.1f \n",kilometros);
    	return 0;   
  }
