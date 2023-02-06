#include <stdio.h>
#include <math.h>

//protótipo
int calculaRaizes(float,float,float,float*,float*);

//função auxiliar
int calculaRaizes( float a,float b,float c,float*x1,float*x2){

	float delta;
	delta=(pow(b,2)-(4*a*c));
	
	if(delta<0)
	{
	return 0;
	}
	else
	{
		*x1=(-b+sqrt(delta))/(2.0*a);
		*x2=(-b-sqrt(delta))/(2.0*a);
	return 1;
	}
}

//função principal
int main(){

	//declaração de variáveis
	float a,b,c,x1,x2;
	printf("Digite os valores de a,b,c:\n");
	scanf("%f %f %f",&a,&b,&c);
	
	//saída de dados
	if(calculaRaizes(a,b,c,&x1,&x2)==1)
	{
		printf("x1=%.2f\nx2=%.2f\n",x1,x2);
	}
	else
	{
		printf("Não foi possível calcular as raízes!\n");
	}
	return 0;
}
