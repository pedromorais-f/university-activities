#include "ordenacao.h"

int main(){
    int cases;

    scanf("%d",&cases);

    while (cases != 0){
        
        getchar();
        getchar();

        Student *students;
        students = (Student*) malloc(cases * sizeof(Student));

        for(int i = 0; i < cases; i++){
            char name[64];
            fgets(name,64,stdin);
            name[strcspn(name, "\n")] = 0;
            strcpy(students[i].name,name);
            
            scanf("%s %c\n",students[i].color,&students[i].size);
        }

        ordenacao(students,cases);

        for(int j = 0; j < cases; j++){
            printf("%s %c %s\n",students[j].color,students[j].size,students[j].name);
        }

        
        free(students);
        scanf("%d",&cases); 

        if(cases != 0)
            printf("\n"); 
    }
    

    return 0;
    
}