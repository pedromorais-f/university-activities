#include <stdio.h>

//estrutura
typedef struct{
    
    int numerador;
    int denominador;
}Racional;

//protótipo
int equal();
int simplificar();


//função principal
int main(){

    Racional conta1;
    Racional conta2;
    
    printf("Digite numerador e denominador de r1:");
    scanf("%d %d",&conta1.numerador,&conta1.denominador);

    printf("Digite numerador e denominador de r2:");
    scanf("%d %d",&conta2.numerador,&conta2.denominador);

    equal(conta1,conta2);

    return 0;
}

//função auxiliar
int equal(Racional conta1,Racional conta2){

    int mdc1 = simplificar(conta1);
    int mdc2 = simplificar(conta2);
    int num1,num2;
    int den1,den2;

    //cálculo
    num1 = conta1.numerador/mdc1;
    num2 = conta2.numerador/mdc2;

    den1 = conta1.denominador/mdc1;
    den2 = conta2.denominador/mdc2;


    if((num1 == num2) && (den1 == den2)){

        printf("r1 e r2 são iguais a (%d/%d)!\n",num1,den1);
        return 1;
    }

    else{

        printf("r1 e r2 são diferentes!\n");
        return 0;
    }

}

int simplificar(Racional conta){

    int resto = -1;
    
    while(resto != 0){

        resto = conta.numerador % conta.denominador;
        conta.numerador = conta.denominador;
        conta.denominador = resto;
    }
    return conta.numerador;
}

