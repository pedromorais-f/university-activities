#include "ordenacao.h"

void heapRefaz(Student *students,int esq,int dir){
    int i = esq;
    int j = i * 2 + 1;
    Student aux = students[i];

    while(j <= dir){
        if(j < dir && compare(students[j],students[j + 1]) == 1){
            j++;
        }
        if(compare(aux,students[j]) == 2){
            break;
        }
        students[i] = students[j];
        i = j;
        j = i * 2 + 1;
    }
    students[i] = aux;
}

void heapConstroi(Student *students,int n){
    int esq = (n / 2) - 1;
    
    while(esq >= 0){
        heapRefaz(students,esq,n - 1);
        esq--;
    }
}

// implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(Student *vetor, int n) {
    heapConstroi(vetor,n);
    
    while(n > 1){
        Student aux = vetor[n - 1];
        vetor[n - 1] = vetor[0];
        vetor[0] = aux;
        n--;
        heapRefaz(vetor,0,n - 1);
    }
}

int compare(Student student1,Student student2){
    if(strcmp(student1.color,student2.color) < 0){
        return 1;
    }else if(strcmp(student1.color,student2.color) > 0){
        return 2;
    }else{
        if(student1.size > student2.size){
            return 1;
        }else if(student1.size < student2.size){
            return 2;
        }else{
            if(strcmp(student1.name,student2.name) < 0){
                return 1;
            }else if(strcmp(student1.name,student2.name) > 0){
                return 2;
            }
        }
    } 

    return 0;
}