#include <stdio.h>

//Função principal

int main()
{
	//entrada de dados
	float a,b,c;
	printf("Digite os números desejados:\n");
	scanf("%f %f %f",&a,&b,&c);
	
	//saída de dados com as condições
	if (a<b && a<c && c>b)
	{
		printf("Menor=%.2f\nIntermediário=%.2f\nMaior=%.2f\n",a,b,c);
	}
	else if (a<b && a<c && b>c)
	{
		printf("Menor=%.2f\nIntermediário=%.2f\nMaior=%.2f\n",a,c,b);
	}
	else if (b<a && b<c && c>a)
	{
		printf("Menor=%.2f\nIntermediário=%.2f\nMaior=%.2f\n",b,a,c);
	}
	else if (b<a && b<c && a>c)
	{
		printf("Menor=%.2f\nIntermediário=%.2f\nMaior=%.2f\n",b,c,a);
	}
	else if (c<a && c<b && b>a)
	{
		printf("Menor=%.2f\nIntermediário=%.2f\nMaior=%.2f\n",c,a,b);
	}
	else if (c<a && c<a && a>b)
	{
		printf("Menor=%.2f\nIntermediário=%.2f\nMaior=%.2f\n",b,c,a);
	}
	else
	{
		printf("Todos os números são iguais!\n");
	}
	return 0;						
}
	

