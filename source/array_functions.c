#include "array_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *array, int len) {
    for(int i = 0; i < len; i++)
        printf("%d\t", array[i]);
}

void fillArray(int*array, int len, int max) {
    srand(time(NULL));
    for(int i = 0; i < len; i++)
        array[i] = rand() % max;
}