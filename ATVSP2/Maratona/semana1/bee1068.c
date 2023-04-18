#include <stdio.h>
#include <string.h>

#define MAX_TAM 1000
 
int main() {
 
    int parentheseClose;
    int parentheseOpen;
    int sum;
    int length;

    char str[MAX_TAM];

    while(scanf("%s",str) != EOF){
        parentheseClose = 0;
        parentheseOpen = 0;
        sum = 0;
        
        
        length = strlen(str);
        
        for(int i = 0;i < length;i++){
            if(str[i] == '('){
                parentheseOpen++;
            }else if(str[i] == ')'){
                parentheseClose--;
            }

            if((parentheseClose + parentheseOpen) < 0){
                break;
            }
        }
        sum = parentheseClose + parentheseOpen;

        if(sum != 0){
            printf("incorrect\n");
        }else{
            printf("correct\n");
        } 
    }
 
    return 0;
}