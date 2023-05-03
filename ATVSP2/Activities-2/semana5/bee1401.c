#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char str[12];
}Permutation;


int fatorial(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * fatorial(n - 1);
    }
}


void changeCharacter(char *str,int i,int k){
    char temp;

    temp = str[i];
    str[i] = str[k];
    str[k] = temp;
}

void permutation(char *str,int length,Permutation *permutations,int *counter){
    int i,len;

    len = strlen(str);
    if(len == length){
        strcpy(permutations[*counter].str,str);
        (*counter)++;
    }else{
        for(i = length; i < len; i++){
            changeCharacter(str,length,i);
            permutation(str,length + 1,permutations,counter);
            changeCharacter(str,i,length);
        }
    }


}

void positionChanged(Permutation *permutations, int *i, int *j){
    Permutation aux;

    aux = permutations[*i];
    permutations[*i] = permutations[*j];
    permutations[*j] = aux;
    *i += 1;
    *j -= 1;
}


void quicksort(Permutation *permutations, int begin, int end){
    int i,j;
    Permutation pivot; 

    i = begin;
    j = end;
    pivot = permutations[(begin + end) / 2];

    while (i <= j){
        while(strcmp(permutations[i].str,pivot.str) < 0 && i < end){
            i++;
        }
        while(strcmp(permutations[j].str,pivot.str) > 0 && j > begin){
            j--;
        }
        if(i <= j){
            positionChanged(permutations,&i,&j);
        }
    }

    if(j > begin){
        quicksort(permutations,begin,j);
    }

    if (i < end){
        quicksort(permutations,i, end);
    }
}

int main() {
 
    int n;
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++){
        char str[12];
        scanf("%s",str);

        int length = strlen(str);

        int position = 0;

        int permutation_length = fatorial(length);
        Permutation *permutations = malloc(permutation_length * sizeof(Permutation));

        
        permutation(str,0,permutations,&position);
        quicksort(permutations,0,permutation_length - 1);
        printf("%s\n",permutations[0].str);
        for(int j = 1; j < permutation_length; j++){
            if(!strcmp(permutations[j].str,permutations[j - 1].str)){
                continue;
            }else{
                printf("%s\n",permutations[j].str);
            }
        }

        if(i != n)
            printf("\n");
    
        free(permutations);        
    }
 
    return 0;
}