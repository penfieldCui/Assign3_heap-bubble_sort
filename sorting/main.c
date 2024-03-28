// Sorting
// 
// DS&A assignment 3 - Zongping Cui
#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubbleSort(int* arr, int size) {
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                //swap
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}


int main() {
    srand(time(NULL));
	int* arr1 = NewArrayWithRandom();
	int* arr2 = NewArrayWithRandom();
	
	for (int i = 0; i < ARRAYSIZE; i ++) {
		arr2[i] = arr1[i];  //identical value 
	}


	return 0;
}


