#include <stdio.h>

//protótipos
int val1_cpf(long);
int val2_cpf(long);

//funções auxiliares
int val1_cpf(long cpf){

	long digitos= cpf / 100;
	long d1= cpf / 10 % 10;
	long digito;
	long soma1 = 0;
	long valor1;
	for(int i=2;i<=10;i++){
	
		digito = digitos % 10;
		soma1 += digito * i;
		digitos /= 10;
	}
	valor1 = (soma1 * 10) % 11;
	if(valor1 == d1){
	
		val2_cpf(cpf);
		return 1;
	}
	else if(valor1 == 10 && d1 == 0){
	
		return 1;
	}
	else{
	
		return 0;
	}
	return 0;
}

int val2_cpf(long cpf){


	long digitos= cpf / 10;
	long d2= cpf % 10;
	long digito;
	long soma2 = 0;
	long valor2;
	for(int i=2;i<=11;i++){
	
		digito= digitos % 10;
		soma2 += digito * i;
		digitos /= 10;
	}
	valor2= (soma2 * 10) % 11;
	if(valor2 == d2){
	
		return 1;
	}
	else if(valor2 == 10 && d2 == 0){
	
		return 1;
	}
	else{
	
		return 0;
	}
	return 0;
}

//função principal
int main(){

	long cpf;
	printf("Digite o CPF:");
	scanf("%ld",&cpf);
	
	if(val1_cpf(cpf) && val2_cpf(cpf)){
	
		printf("Válido!\n");
	}
	else{
	
		printf("Inválido!\n");
	}
	return 0;
}

