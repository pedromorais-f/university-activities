#include <stdio.h>
#include "lista.h"

int main(){
    TLista lista;
    TLista_Inicia(&lista);

    char str[MAX_TAM],beiju[MAX_TAM];
    
    int length,lengthBeiju = 0;

    char c;
   
    while(fgets(str,MAX_TAM,stdin) != NULL){

        length = strlen(str);
        
        str[strcspn(str, "\n")] = 0;
        
        int i = 0;
        if(str[0] == '['){
            i = 1;
        }
        for(;i < length;i++){
            
            c = str[i];

            if(c == '['){
                int j;
                for(j = i + 1;j < length && str[j] != '[' && str[j] != ']';j++){
                    beiju[lengthBeiju++] = str[j];
                }
                beiju[lengthBeiju + 1] = '\0';
                
                for(int k = lengthBeiju;k >= 0;k--){
                    TLista_Insere_Inicio(&lista,beiju[k]);
                }
                
                lengthBeiju = 0;
                i = j - 1;
            }else if(str[i] != ']'){
                TLista_Insere_Fim(&lista,str[i]);
            }
        }
        TLista_Imprime(&lista);
        TLista_Esvazia(&lista);
        TLista_Inicia(&lista);
    }

    TLista_Esvazia(&lista);
    return 0;
}
