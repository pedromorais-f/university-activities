#include <stdio.h>
	int main(){
	
	//declaração de variáveis da equação
	float a,b,c,x;
	printf("Declare os valores das variáveis à seguir:");
	scanf("%f %f %f",&a,&b,&c);
	
	//equação para a resolução
	x=((b*b)-2*a*c)*((b*b)-2*a*c)+(5*a*b*c)-3;
	
	//resultado da equação
	printf("x=%.1f \n",x);
	return 0;
	}
