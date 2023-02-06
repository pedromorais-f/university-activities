#include <stdio.h>

//protótipo da função
void conversor_temp(float,float*,float*);

//função auxiliar
void conversor_temp(float celsius,float*fahrenheit,float*kelvin)
{
	*fahrenheit=(1.8*celsius)+32;*kelvin=celsius+273.15;
}

//função principal
int main()
{
	//declaração de variáveis
	float celsius,fahrenheit,kelvin;
	printf("Digite o valor em Celsius:\n");
	scanf("%f",&celsius);
	
	//saída de dados
	conversor_temp(celsius,&fahrenheit,&kelvin);
	conversor_temp(celsius,&fahrenheit,&kelvin);
	printf("Celsius=%.2f\nFahrenheit=%.2f\nKelvin=%.2f\n",celsius,fahrenheit,kelvin);
	return 0;
	
}
