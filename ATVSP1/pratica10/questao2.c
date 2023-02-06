#include <stdio.h>

//estrutura
typedef struct {
    double real;
    double imaginario;
} Complexo;

//protótipos
Complexo somaComplexo();
Complexo subComplexo();
Complexo multComplexo();

//função principal
int main(){

    char opcao;
    Complexo x;
    Complexo y;
    Complexo r;

    
    printf("Calculadora de números complexos!\n");

    printf("\n");

    printf("Digite os valores de a e b (x = a + bi):");
    scanf("%lf %lf",&x.real,&x.imaginario);

    printf("\n");

    printf("Digite os valores de c e d (y = c + di):");
    scanf("%lf %lf",&y.real,&y.imaginario);
    getchar();

    printf("\n");

    printf("Digite a operação (+, - ou *):");
    scanf("%c",&opcao);

    switch (opcao){
    
    case '+':
        r = somaComplexo(x,y);
        printf("\nResultado: %.1lf + %.1lfi\n",r.real,r.imaginario);
        break;

    case '-':
        r = subComplexo(x,y);
        printf("\nResultado: %.1lf + %.1lfi\n",r.real,r.imaginario);
        break;

    case '*':
        r = multComplexo(x,y);
        printf("\nResultado: %.1lf + %.1lfi\n",r.real,r.imaginario);
        break;                
    
    default:
        printf("\nCaracter inválido\n");
        break;
    }

    return 0;
}

//funções auxiliares
Complexo somaComplexo(Complexo x,Complexo y){

    Complexo r;

    r.real = x.real + y.real;
    r.imaginario = x.imaginario + y.imaginario;
    
    return r;
}

Complexo subComplexo(Complexo x,Complexo y){

    Complexo r;

    r.real = x.real - y.real;
    r.imaginario = x.imaginario - y.imaginario;
    
    return r;
}

Complexo multComplexo(Complexo x,Complexo y){

    Complexo r;

    r.real = (x.real * y.real) - (x.imaginario * y.imaginario);
    r.imaginario = (x.real * y.imaginario) + (x.imaginario * y.real);
    
    return r;
}

