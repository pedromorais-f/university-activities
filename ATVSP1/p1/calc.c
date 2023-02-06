#include <stdio.h>

//protótipos
void calc_soma(float,float,float*);
void calc_sub(float,float,float*);
void calc_div(float,float,float*);
void calc_mult(float,float,float*);

//funções auxiliares
void calc_soma(float a,float b,float*resultado)
{
	*resultado= a + b;
}
void calc_sub(float a,float b,float*resultado)
{
	*resultado= a - b;
}
void calc_div(float a,float b,float*resultado)
{
	*resultado=a / b;
}
void calc_mult(float a,float b,float*resultado)
{
	*resultado=a * b;
}
//função principal
int main()
{
	//declaração das variáveis
	float a,b,resultado;
	char c;
	scanf("%f %f %c",&a,&b,&c);
	
	//saída dos dados
	switch(c)
	{
	case '+':
		calc_soma(a,b,&resultado);
		printf("%f",resultado);
	return 0;
	case'-':
		calc_sub(a,b,&resultado);
		printf("%f",resultado);
	break;
	case'*':
		calc_mult(a,b,&resultado);
		printf("%f",resultado);
	break;
	case'/':
		calc_div(a,b,&resultado);
		printf("%f",resultado);
	break;
	default:
		printf("Não é possível!");
	}
	return 0;
}
