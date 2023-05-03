#include <stdio.h>
#include <math.h>

double distancia_pontos(double,double,double,double); //protótipo
//função da distância
double distancia_pontos(double x1,double x2,double y1,double y2)
{
	double d;
	d=sqrt(pow(x1-x2,2) + pow(y1-y2,2));
	return d;
}
//função principal
int main(void)
{
	//declaração de variáveis
	double x1,x2;
	double y1,y2;
	double d;
	printf("Digite as coordenadas de P1:\n");
	scanf("%lf %lf",&x1,&y1);
	printf("Digite as coordenadas de P2:\n");
	scanf("%lf %lf",&x2,&y2);
	//saída de dados
	d=distancia_pontos(x1,x2,y1,y2);
	printf("Distância=%lf\n",d);
	return 0;	
}

