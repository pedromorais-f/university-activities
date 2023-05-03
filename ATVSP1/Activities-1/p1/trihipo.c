#include <stdio.h>
#include <math.h>

  int main()
  {
  	//entrada de valores para o cálculo
  	double h,a;
  	printf("Insira o valor da hipotenusa e do seno do ângulo entre 0 e 1:\n");
  	scanf("%lf %lf",&h,&a);
  	
  	//cálculo
  	double angulo=a;
  	double hipotenusa=h;
  	double c1=angulo*h;
  	//cateto 2 da equação
  	double c2=sqrt(pow(hipotenusa,2)-(pow(c1,2)));
  	//condições e saídas de resultados
  	if(a > 1)
  	{
  	printf("Não é possivel fazer a operação!\n");
  	return 0;
  	}
  	else if(a<0)
  	{
  	printf("Não é possível esta operação!\n");
  	return 0;
  	}
  	else if(h<0)
  	{
  	printf("Não é possível esta operação!\n");
  	return 0;
  	}
  	else
  	printf("c1=%lf\nc2=%lf\nh=%lf\n",c1,c2,h);
  	return 0;
  }
