#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[64];
    char color[20];
    char size;
}Student;

void heapRefaz(Student *students,int esq,int dir);

void heapConstroi(Student *students,int n);

void ordenacao(Student *vetor, int n);

int compare(Student student1,Student student2);


#endif