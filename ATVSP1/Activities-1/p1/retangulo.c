#include <stdio.h>

//protótipos
float retangulo_qua(float,float);
void perimetro_ret(float,float,float*);
void area_ret(float,float,float*);

//funções auxiliares
float retangulo_qua(float a,float b){
	if(a==b){
		return 1;
	}
	else{
		return 2;
	}
}
void perimetro_ret(float a,float b,float*resultado){
	*resultado=(2.0*a)+(2.0*b);
}
void area_ret(float a,float b,float*resultado1){
	*resultado1=a*b;
}
int main(){
	//entrada de valores
	float a,b,resultado,resultado1;
	printf("Digite os valores dos lados do retângulo:");
	scanf("%f %f",&a,&b);
	
	//saída de dados
	if(retangulo_qua(a,b)==1){
		perimetro_ret(a,b,&resultado);
		area_ret(a,b,&resultado1);
		printf("É quadrado!\nPerímetro=%.2f\nÁrea=%.2f\n",resultado,resultado1);
	}
	else{
		perimetro_ret(a,b,&resultado);
		area_ret(a,b,&resultado1);
		printf("Não é quadrado!\nPerímetro=%.2f\nÁrea=%.2f\n",resultado,resultado1);
	}
	return 0;
}
