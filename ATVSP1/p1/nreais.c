#include <stdio.h>
#include <math.h>

//protótipos
void soma_num(double,double,double*);
void prod_qua(double,double,double*);
void qua_um(double,double*);
void soma_raiz(double,double,double*);
void dif_seno(double,double,double*);
void modulo_um (double,double*);

//funções auxiliares
void soma_num(double a,double b,double*r)
{
	*r=a + b;
}
void prod_qua(double a,double b,double*r1)
{
	*r1= a * pow(b,2);
}
void qua_um(double a,double*r2)
{
	*r2= pow(a,2);
}
void soma_raiz(double a,double b,double*r3)
{
	*r3= sqrt(pow(a,2) + pow(b,2));
}
void dif_seno(double a,double b,double*r4)
{
	*r4= sin(a - b);
}
void modulo_um (double a,double*r5)
{
	*r5=fabs(a);
}
int main()
{
	//entrada de dados
	double a,b,r,r1,r2,r3,r4,r5;
	printf("Digite dois números:\n");
	scanf("%lf %lf",&a,&b);
	
	//saída de dados
	soma_num(a,b,&r);
	prod_qua(a,b,&r1);
	qua_um(a,&r2);
	soma_raiz(a,b,&r3);
	dif_seno(a,b,&r4);
	modulo_um(a,&r5);
	printf("Soma dos números:%.2lf\nProduto com o quadrado de B:%.2lf\nQuadrado do primeiro número:%.2lf\nRaiz da soma dos quadrados:%.2lf\nSeno da diferença:%.2lf\nMódulo do primeiro:%.2lf\n",r,r1,r2,r3,r4,r5);
	return 0;
}
