#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[30];
    char region;
    int distance;
}Info;

int compare(Info person1,Info person2){
    if(person1.distance < person2.distance){
        return 1;
    }else if(person1.distance > person2.distance){
        return 2;
    }else{
        if(person1.region < person2.region){
            return 1;
        }else if(person1.region > person2.region){
            return 2;
        }else{
            if(strcmp(person1.name,person2.name) < 0){
                return 1;
            }else if(strcmp(person1.name,person2.name) > 0){
                return 2;
            }
        }
    }

    return 0;
}

void positionChanged(Info *arr, int *i, int *j){
    Info aux;

    aux = arr[*i];
    arr[*i] = arr[*j];
    arr[*j] = aux;
    *i += 1;
    *j -= 1;
}


void quicksort(Info *arr, int begin, int end){
    int i,j;
    Info pivot; 

    i = begin;
    j = end;
    pivot = arr[(begin + end) / 2];

    while (i <= j){
        while(compare(arr[i],pivot) == 1 && i < end){
            i++;
        }
        while(compare(arr[j],pivot) == 2 && j > begin){
            j--;
        }
        if(i <= j){
            positionChanged(arr,&i,&j);
        }
    }

    if(j > begin){
        quicksort(arr,begin,j);
    }

    if(i < end){
        quicksort(arr, i, end);
    }
}


 
int main(){
 
    Info *people;
    int cases;
    
    while(scanf("%d",&cases) != EOF){
        people = (Info*)malloc(cases * sizeof(Info));
        for(int i = 0; i < cases; i++){
            scanf("%s",people[i].name);

            getchar();
            scanf("%c",&people[i].region);

            getchar();
            scanf("%d",&people[i].distance);

            getchar();
        }

        quicksort(people,0,cases - 1);

        for(int j = 0; j < cases; j++){
            printf("%s\n",people[j].name);
        }

        free(people);
    }
 
    return 0;
}