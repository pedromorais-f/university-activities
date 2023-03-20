#include <stdio.h>
#include <math.h>

int main()
{
	//declaração de variáveis ao código
	double so,vo,a,t;
	printf("Entre com os valores de So,Vo,A,T:\n");
	scanf("%lf %lf %lf %lf",&so,&vo,&a,&t);
	
	//cálculo
	double s=so+(vo*t)+(a*pow(t,2)/2.0);
	double v=vo+(a*t);
	
	//saída de dados com as condições
	if(t<0)
	{
	printf("Não é possivel esta operação,ja que não existe tempo negativo.\n");
	}
	else
	{
	printf("posição final=%.2lf\nvelocidade final=%.2lf\n",s,v);
	}
	return 0;
}
