#include <stdio.h>

//protótipo
void intei_real (float,int*,float*);

//função auxiliar
void intei_real (float num,int*inteiro,float*dif)
{
	*inteiro=num;
	*dif=num - *inteiro;
}
int main()
{
	//entrada de dados
	float num,dif;
	int inteiro;
	printf("Digite um número real:");
	scanf("%f",&num);
	
	//saída de dados
	intei_real(num,&inteiro,&dif);
	printf("Parte inteira=%d\nParte decimal=%.3f\n",inteiro,dif);
	return 0;
}
