#include <stdio.h>
#include <math.h>

//protótipos
double quadrado_menor(double);
double raiz_maior(double);

//funções auxiliares
double quadrado_menor(double a)
{
	double resultado;
	resultado=pow(a,2);
	return resultado;
}
double raiz_maior(double b)
{
	double resultado2;
	resultado2=sqrt(b);
	return resultado2;
}

//função principal
int main()
{
	//entrada de dados
	double a,b,resultado,resultado2;
	printf("Digite os números desejados:\n");
	scanf("%lf %lf",&a,&b);
	
	//saída de dados
	if(a<b)
	{
		resultado=quadrado_menor (a);
		resultado2=raiz_maior (b);
		printf("Quadrado do menor=%.2lf\nRaiz do Maior=%.2lf\n",resultado,resultado2);
	}
	else if(a>b)
	{
		resultado=quadrado_menor(a);
		resultado2=raiz_maior(b);
		printf("Quadrado do menor=%.2lf\nRaiz do Maior=%.2lf\n",resultado,resultado2);
	}
	else
	{
		printf("Esses números são iguais!\n");
	}
	return 0;	
}
