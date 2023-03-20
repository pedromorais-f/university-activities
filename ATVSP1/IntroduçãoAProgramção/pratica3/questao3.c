#include <stdio.h>
  int main()
  {
  	//declaração de variáveis
  	float imc,peso,altura;
  	printf("Entre com o peso:\n");
  	scanf("%f",&peso);
  	printf("Entre com a altura:\n");
  	scanf("%f",&altura);
  	
  	//cálculo
  	imc=peso/(altura*altura);
  	
  	//saída de dados com as condições
  	if(imc<18.5)
  	{
  	printf("Abaixo do peso\n");
  	}
  	else if(imc>=18.5 && imc<25)
  	{
  	printf("Peso Normal\n");
  	}
  	else if(imc>=25 && imc<30)
  	{
  	printf("Acima do peso\n");
  	}
  	else
  	{
  	printf("Obeso\n");
  	}
  	return 0;
  }	
  	
  	
  
  
