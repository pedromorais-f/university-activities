#include <stdio.h>
int main()
{
	//declaração das variáveis
	char caracter;
	printf("Entre com o caractere escolhido:\n");
	scanf("%c",&caracter); 
	
	//saída de dados com as condições
	if(caracter>=65 && caracter<=90)
	{
		printf("Letra Maiúscula.\n");
	}
	else if(caracter>=97 && caracter<=122)
	{
		printf("Letra minúscula.\n");
	}
	else
	{
		printf("Não é letra\n");
	}
	return 0;
}
