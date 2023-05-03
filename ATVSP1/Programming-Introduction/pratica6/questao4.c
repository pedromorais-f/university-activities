#include <stdio.h>
#include <math.h>

//protótipo
double valor_pi(double);

//função auxiliar
double valor_pi(double n){
	double pi;
	double soma;
	
	for(int i=1;i<=n;++i){
		soma+=((pow(-1,i+1))*(1/pow(((2.0*i)-1),3)));
	}
	pi=cbrt(soma * 32.0);
	return pi;
}
int main(){
	
	int termos;
	printf("Digite o número de termos:\n");
	scanf("%d",&termos);
	double resultado;
	
	resultado=valor_pi(termos);
	
	printf("pi=%.4lf\n",resultado);
	return 0;
}
