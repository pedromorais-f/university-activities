#include <stdio.h>
#include <string.h>

int check(char a, char b){
    if(a == 'C' && b == 'F')
        return 1;
    if(a == 'F' && b == 'C')
        return 1;
    if(a == 'B' && b == 'S')
        return 1;
    if(a == 'S' && b == 'B')
        return 1;

    return 0;
}
 
int main() {
 
    
    char rna[300];

    while(scanf("%s",rna) != EOF){
        int length = strlen(rna);
        int counter = 0;

        for(int i = 0; i < length; i++){
            if(check(rna[i],rna[i + 1])){
                counter++;
                for(int j = i; j < length; j++){
                    rna[j] = rna[j + 2];
                }
                i-= 2;
                length -= 2;
            }
        }

        printf("%d\n",counter);
    }
    
 
    return 0;
}