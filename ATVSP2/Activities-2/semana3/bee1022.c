#include <stdio.h>
 
typedef struct{
    int n1,n2,d1,d2;
    char operation;
    int cases;
}Operation;

typedef struct{
    int numerator;
    int denominator;
}Fraction;

void sumOperation(Operation*,Fraction*);
void subOperation(Operation*,Fraction*);
void multOperation(Operation*,Fraction*);
void divOperation(Operation*,Fraction*);
void simplifiedFranction(Fraction*);

int main(){

    Operation operations;
    
    scanf("%d",&operations.cases);

    for(int i = 0;i < operations.cases;i++){
        Fraction fraction;
        
        scanf("%d",&operations.n1);

        getchar();
        getchar();

        scanf("%d",&operations.d1);

        getchar();

        scanf("%c",&operations.operation);

        scanf("%d",&operations.n2);

        getchar();
        getchar();

        scanf("%d",&operations.d2);

        switch(operations.operation){
            case '+':
                sumOperation(&operations,&fraction);
                break;
            case '-':
                subOperation(&operations,&fraction);
                break;
            case '*':
                multOperation(&operations,&fraction);
                break;
            case '/':
                divOperation(&operations,&fraction);
                break;        
        }

        printf("%d/%d =",fraction.numerator,fraction.denominator);
        simplifiedFranction(&fraction);
        printf(" %d/%d\n",fraction.numerator,fraction.denominator);

    }

    return 0; 
}

void sumOperation(Operation *operation,Fraction *fraction){
    fraction->numerator = (operation->n1 * operation->d2) + (operation->n2 * operation->d1);
    fraction->denominator = operation->d1 * operation->d2;
}

void subOperation(Operation *operation,Fraction *fraction){
    fraction->numerator = (operation->n1 * operation->d2) - (operation->n2 * operation->d1);
    fraction->denominator = operation->d1 * operation->d2;
}

void multOperation(Operation *operation,Fraction *fraction){
    fraction->numerator = operation->n1 * operation->n2;
    fraction->denominator = operation->d1 * operation->d2;
}

void divOperation(Operation *operation,Fraction *fraction){
    fraction->numerator = operation->n1 * operation->d2;
    fraction->denominator = operation->n2 * operation->d1;
}

void simplifiedFranction(Fraction *fraction){
    int num = fraction->numerator;
    int aux = 0;
    
    if(num < 0){
        num = num * -1;
    }
    if(fraction->numerator > fraction->denominator){
        num = fraction->denominator;
    }

    for(int i = 2;i <= num;i++){
        if(fraction->numerator % i == 0 && fraction->denominator % i == 0){
            aux = i;
        }
    }
    if(aux){
        fraction->numerator /= aux;
        fraction->denominator /= aux;
    }
}