#include <stdio.h>
#include <string.h>

#define TAM 100


//função principal
int main(){

    char texto[TAM];
    printf("Digite o texto para censurar:");
    fgets(texto,TAM,stdin);

    int tamanho = strlen(texto);

    for(int i = 0;i < tamanho;i++){

        if(texto[i] == 'a'){

            texto[i] = '@';
        }
        else if(texto[i] == 'e'){

            texto[i] = '_';
        }
        else if(texto[i] == 'i'){

            texto[i] = '|';
        }
        else if(texto[i] == 'o'){

            texto[i] = '0';
        }
        else if(texto[i] == 'u'){

            texto[i] = '#';
        }
        else if(texto[i] == 's'){

            texto[i] = '$';
        }
    }
    
    printf("%s",texto);

    return 0;
}