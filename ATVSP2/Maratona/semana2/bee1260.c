#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[32];
    int equalTrees;
}Tree;

void quicksort(Tree*,int,int);
void positionChanged(Tree*,int*,int*);
 
int main() {
 
    int n;
    scanf("%d",&n);
    int counter;


    getchar();
    getchar();

    Tree *trees;
    for(int i = 0;i < n;i++){
        
        trees = (Tree*) malloc(1000000 * sizeof(Tree));
        char name[32];
        counter = -1;

        do{
            name[0] = '\0'; 
            fgets(name,32, stdin);
            name[strcspn(name, "\n")] = 0;
            counter++;
            strcpy(trees[counter].name,name);
            trees[counter].equalTrees = 1;
        } while(name[0] != '\0');
        
        quicksort(trees,0,counter-1);

        for(int k = 0;k < counter;k++){
            int l = k + 1;
            while(strcmp(trees[k].name,trees[l].name) == 0){
                trees[k].equalTrees = trees[k].equalTrees + trees[l].equalTrees;
                l++;
            }
            printf("%s %.4lf\n",trees[k].name,((double)trees[k].equalTrees / counter) * 100.0000);
            k = l - 1;
        }


        
        if(i != n-1){
            printf("\n");
        }

        free(trees);

    }
 
    return 0;
}



void positionChanged(Tree *trees, int *i, int *j){
    Tree aux;

    aux = trees[*i];
    trees[*i] = trees[*j];
    trees[*j] = aux;
    *i += 1;
    *j -= 1;
}


void quicksort(Tree *trees, int begin, int end){
    int i,j;
    Tree pivot; 

    i = begin;
    j = end;
    pivot = trees[(begin + end) / 2];

    while (i <= j){
        while(strcmp(trees[i].name,pivot.name) < 0 && i < end){
            i++;
        }
        while(strcmp(trees[j].name,pivot.name) > 0 && j > begin){
            j--;
        }
        if(i <= j){
            positionChanged(trees,&i,&j);
        }
    }

    if(j > begin){
        quicksort(trees,begin,j);
    }

    if (i < end){
        quicksort(trees, i, end);
    }
}

