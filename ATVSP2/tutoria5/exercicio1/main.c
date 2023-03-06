#include "ordenacao.h"

int main(){
    int cases;

    scanf("%d",&cases);

    while (cases != 0){
        Student *students;
        students = (Student*) malloc(cases * sizeof(Student));

        for(int i = 0; i < cases; i++){
            fgets(students[i].name,64,stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;
            
            scanf("%s",students[i].color);
            getchar();
            scanf("%c",&students[i].size);
        }

        ordenacao(students,cases);

        for(int j = 0; j < cases; j++){
            printf("%s %c %s\n",students[j].color,students[j].size,students[j].name);
        }
        
        free(students);
        scanf("%d",&cases);  
    }
    

    return 0;
    
}