// impl of library
// 
// DS&A assignment 3 - Zongping Cui

#include "library.h"
#include <stdlib.h>


int* NewArrayWithRandom() {
    int* arr = (int*)malloc(sizeof(int)* ARRAYSIZE);
    if (arr == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < ARRAYSIZE; i++) {
        arr[i] = rand() % ARRAYSIZE; // Random numbers between 0 and 9999
    }
    return arr;
}


void destroyArr(int* arr) {
    if (arr != NULL)
        free(arr);
}