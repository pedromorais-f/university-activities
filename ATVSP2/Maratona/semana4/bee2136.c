#include <stdio.h>
#include <string.h>

#define MAX_TAM 200


typedef struct{
    char name[30];
    int counter;
    int id; 
}People;

void positionChanged(People *arr, int *i, int *j){
    People aux;

    aux = arr[*i];
    arr[*i] = arr[*j];
    arr[*j] = aux;
    *i += 1;
    *j -= 1;
}


void quicksort(People *arr, int begin, int end){
    int i,j;
    People pivot; 

    i = begin;
    j = end;
    pivot = arr[(begin + end) / 2];

    while (i <= j){
        while(strcmp(arr[i].name,pivot.name) < 0 && i < end){
            i++;
        }
        while(strcmp(arr[j].name,pivot.name) > 0 && j > begin){
            j--;
        }
        if(i <= j){
            positionChanged(arr,&i,&j);
        }
    }

    if(j > begin){
        quicksort(arr,begin,j);
    }

    if (i < end){
        quicksort(arr, i, end);
    }
}



 
int main(){
 
    char name[30];
    char answer[4];
    int id = 0;
    
    People yes[MAX_TAM];
    int counterYes = 0;

    People no[MAX_TAM];
    int counterNo = 0;

    scanf("%s",name);
    
    while(strcmp(name,"FIM") != 0){
        scanf("%s",answer);

        if(!strcmp(answer,"YES")){
            strcpy(yes[counterYes].name,name);
            yes[counterYes].counter = strlen(name);
            yes[counterYes].id = ++id;
            counterYes++;
        }else if(!strcmp(answer,"NO")){
            strcpy(no[counterNo].name,name);
            no[counterNo].counter = strlen(name);
            counterNo++;
        }
        scanf("%s",name);
    }

    quicksort(yes,0,counterYes - 1);
    quicksort(no,0,counterNo - 1);

    for(int i = 0; i < counterYes;i++){
        int j = i + 1;

        while(!strcmp(yes[i].name,yes[j].name)){
            j++;
        }
        printf("%s\n",yes[i].name);
        i = j - 1;
    }

    for(int i = 0; i < counterNo;i++){
        int j = i + 1;

        while(!strcmp(no[i].name,no[j].name)){
            j++;
        }
        printf("%s\n",no[i].name);
        i = j - 1;
    }

    printf("\n");

    printf("Amigo do Habay:\n");
    
    People friend;
    strcpy(friend.name,yes[0].name);
    friend.counter = yes[0].counter;
    friend.id = yes[0].id;
    
    for(int i = 0; i < counterYes;i++){
        if(yes[i].counter > friend.counter){
            strcpy(friend.name,yes[i].name);
            friend.counter = yes[i].counter;
            friend.id = yes[i].id;    
        }else if(yes[i].counter == friend.counter){
            if(yes[i].id < friend.id){
                strcpy(friend.name,yes[i].name);
                friend.counter = yes[i].counter;
                friend.id = yes[i].id;
            }
        }
    }
    printf("%s\n",friend.name);
    
    
    return 0;
}
