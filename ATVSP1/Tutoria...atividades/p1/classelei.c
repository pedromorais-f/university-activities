#include <stdio.h>
int main()
{
	//declaração de variáveis
	int idade;
	printf("Entre com sua idade:");
	scanf("%d",&idade);
	
	//saída de dados com as condições
	if(idade>0 && idade<16)
	{
	printf("Não-Eleitor\n");
	}
	else if(idade>=16 && idade<18 && idade>65)
	{
	printf("Eleitor facultativo\n");
	}
	else if(idade>=18 && idade<=65)
	{
	printf("Eleitor Obrigatório\n");
	}
	else if(idade<0)
	{
	printf("Idade inválida\n");
	}
	return 0;
}

