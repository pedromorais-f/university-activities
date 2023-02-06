#include <stdio.h>

//funções auxiliares
void calc_soma(float a,float b,float*resultado)
{
	*resultado= a + b;
}
void calc_sub(float a,float b,float*resultado)
{
	*resultado= a - b;
}
void calc_div(float a,float b,float*resultado)
{
	*resultado=a / b;
}
void calc_mult(float a,float b,float*resultado)
{
	*resultado=a * b;
}

//função principal
int main(){

    char caracter;
    float a,b,resultado;

    int controlador = 0;

    while(controlador == 0){

        printf("Digite os números escolhidos e o caracter:");
        scanf("%f %f %c",&a,&b,&caracter);
        
        switch(caracter){

            case '+':
                
                calc_soma(a,b,&resultado);
                printf("Resultado = %.2f\n",resultado);
                break;

            case '-':
               
                calc_sub(a,b,&resultado);
                printf("Resultado = %.2f\n",resultado);
                break;

            case '*':
               
                calc_mult(a,b,&resultado);
                printf("Resultado = %.2f\n",resultado);
                break;

            case '/':
                
                calc_div(a,b,&resultado);
                printf("Resultado = %.2f\n",resultado);
                break;

            default:

                printf("Até mais!!!!\n");
                controlador = 1;
                break;
        }
    }
    return 0;
}