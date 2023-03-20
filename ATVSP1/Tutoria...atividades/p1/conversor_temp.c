#include <stdio.h>
   int main()
   {
  	// declaração de variáveis
    	float f,k,c;
    	printf("Declare a temperatura para a conversão:");
    	scanf("%f",&c);
    
  	//cálculo para as variáveis
    	f=(1.8*c)+32;k=c+273.15;
  
 	//condições e saída de dados
 	if(c<-273)
 	{
 	printf("Cálculo inexistente para a situação\n");
 	}
 	else
    	printf("Celsius: c=%.2f\nFahrenheit: f=%.2f\nKelvin: k=%.2f  \n",c,f,k); 
    	return 0; 
    
    }
