// impl of library
// 
// DS&A assignment 3 - Zongping Cui

#include "library.h"
#include <stdlib.h>
#include <math.h>


static void printfSpaces(int spaces) {
    for (int j = 0; j < spaces; j++) {
        printf(" ");
    }
}


int* NewArrayWithRandom(int size) {
    int* arr = (int*)malloc(sizeof(int)* size);
    if (arr == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size; // random numbers
    }
    return arr;
}


void destroyArr(int* arr) {
    if (arr != NULL)
        free(arr);
}

void display(int* arr, int size) {
    printf("\n");
    int power = 1;
    int h = 0;
    int spaces = 0;
    double h_d = (int)log2(size + 1);
    if (floor(h_d) == h_d)  // its a integer, lucky, full tree
        h = h_d;
    else
        h = (int)h_d + 1;

    for (int i = 0; i < size;i++) {
        spaces = pow(2, h - 1) - 1;

        if (i == pow(2, power - 1) - 1)  //first left
            printfSpaces(spaces);

        printf("%1d", arr[i]);

        if ((i + 2) == pow(2, power)) { //last one of line
            printf("\n");
            h--;
            power++;
        }
        else if (i % 2 == 1) { // a left child

            printfSpaces(spaces * 2 + 1);
        }
        else { // a right child
            printfSpaces(spaces * 2 + 1);
            //printf("|");
        }

    }
    printf("\n\n");
}


void debugArr(int* arr, int size) {
    int displayNum = 32;
    for (int i = 0; i < displayNum; i++) {
        printf("%d ", arr[i]);
    }
    printf(" ... ");
    for (int i = size - displayNum; i < size; i++) {
        printf("%d ", arr[i]);
    }
}