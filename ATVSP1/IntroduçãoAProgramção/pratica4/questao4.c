#include <stdio.h>
#include <math.h>
#define PI 3.141593

//protótipos 
void ang_graus (float angulo,float*);
void ang_radianos(float radiano,float*);
void temp_cel(float celsius,float*,float*);
void temp_fahr(float fahrenheit,float*,float*);
void temp_kel(float kelvin,float*,float*);
void angulo(int);
void temperatura(int);
void conversor();
//funções auxiliares
void ang_graus(float angulo,float*resultado)
{
	*resultado=angulo * (PI/180);
}
void ang_radianos(float radiano,float*resultado)
{
	*resultado=((180*radiano)/PI);
}
void temp_cel(float celsius,float*fahrenheit,float*kelvin)
{
	*fahrenheit=(1.8*celsius)+32;*kelvin=celsius+273.15;
}
void temp_fahr(float fahrenheit,float*celsius,float*kelvin)
{
	*celsius=(fahrenheit-32)/1.8;*kelvin=(fahrenheit+459.67)*(5.0/9.0);
}
void temp_kel(float kelvin,float*celsius,float*fahrenheit)
{
	*fahrenheit=(1.8*(kelvin-273.15))+32;*celsius=kelvin-273.15;
}
void angulo(int escolhaum)
{
	float angulo,radiano,resultado;
	printf("Qual a unidade de origem?\n1) Graus\n2) Radianos\nSelecione uma opção:");
	scanf("%d",&escolhaum);
	switch(escolhaum)
	{
	case 1:
		printf("Digite o valor em Graus:");
		scanf("%f",&angulo);
		ang_graus(angulo,&resultado);
		printf("Valor em Radianos: %.2f\n",resultado);
	break;
	case 2:
		printf("Digite o valor em Radianos:");
		scanf("%f",&radiano);
		ang_radianos(radiano,&resultado);
		printf("Valor em Graus: %.2f\n",resultado);
	break;	
	default:
		printf("Operação Inválida.\n");
	}
}
void temperatura(int escolhadois)
{
	float celsius,fahrenheit,kelvin;
	printf("Qual a unidade de origem?\n1) Celsius\n2) Fahrenheit\n3) Kelvin\nSelecione uma opção:");
	scanf("%d",&escolhadois);
	switch(escolhadois)
	{
	case 1:
		printf("Digite o valor em Celsius:");
		scanf("%f",&celsius);
		temp_cel(celsius,&fahrenheit,&kelvin);
		printf("Valor em Fahrenheit:%.2f\nValor em Kelvin:%.2f\n",fahrenheit,kelvin);
	break;
	case 2:
		printf("Digite o valor em Farenheit:");
		scanf("%f",&fahrenheit);
		temp_fahr(fahrenheit,&celsius,&kelvin);
		printf("Valor em Celsius:%.2f\nValor em Kelvin:%.2f\n",celsius,kelvin);
	break;
	case 3:
		printf("Digite o valor em Kelvin:");
		scanf("%f",&kelvin);
		temp_kel(kelvin,&celsius,&fahrenheit);
		printf("Valor em Celsius:%.2f\nValor em Fahrenheit:%.2f\n",celsius,fahrenheit);
	break;	
	default:
		printf("Operação inválida.\n");				
	}
}
void conversor()
{
	int escolha;
	printf("### CONVERSOR DE UNIDADES ###\n1) Angulo\n2) Temperatura\nDigite uma opção:");
	scanf("%d",&escolha);
	switch(escolha)
	{
	case 1:
		angulo(escolha);
	break;
	case 2:
		temperatura(escolha);
	break;	
	default:
		printf("Operação inválida.\n");	
	}
}
//função principal
int main()
{
	conversor();
return 0;
}




