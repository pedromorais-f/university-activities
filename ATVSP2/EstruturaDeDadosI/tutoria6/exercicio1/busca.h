#ifndef BUSCA_H
#define BUSCA_H

#define MAX_TAM 1000

#include <stdio.h>
#include <stdlib.h>

void positionChanged(int *arr, int *i, int *j);

void quicksort(int *arr, int begin, int end);

int binarySearch(int *arr, int key);



#endif