// Sorting
// 
// DS&A assignment 3 - Zongping Cui
#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <math.h>

#define ARRAYSIZE 20000

static heapSize = ARRAYSIZE;

// Swap values of 2 variables
void swap(int* a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 2 nested loop
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                //swap
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


// Swap from top to bottom, keep the top as max number
void arrToHeap(int* arr, int current) {
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    
    int bigger = current;
    if (right < heapSize && arr[left] > arr[right]) // 2 child, left is bigger
        bigger = left;
    else if (right < heapSize) // 2 child, right is bigger
        bigger = right;
    else if (left < heapSize && arr[left] > arr[current]) { // only one left child
        bigger = left;
    }
    

    if (arr[current] < arr[bigger]){ //some child is bigger
        swap(&arr[bigger], &arr[current]);
        arrToHeap(arr, bigger);
    }
    // else return, subtree sorted
}



int main() {
    srand(time(NULL));
	int* arr1 = NewArrayWithRandom(ARRAYSIZE);
	int* arr2 = NewArrayWithRandom(ARRAYSIZE);
	
	for (int i = 0; i < ARRAYSIZE; i ++) {
		arr2[i] = arr1[i];  //identical value 
    }

    /** bubble **/
    // N^2
    clock_t startTime = clock();
    bubbleSort(arr1, ARRAYSIZE);

    clock_t endTime = clock();


    double sortTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("Bubble sort: %lf sec\n", sortTime);


    /** heap sort **/
    //to heap   - N*logN
    startTime = clock();

    for (int i = ARRAYSIZE - 1; i >= 0; i--) {
        arrToHeap(arr2, i); // start at root
    }
    
    //N*logN
    for (int i = ARRAYSIZE - 1; i > 0; i--) {
        swap(&arr2[0], &arr2[i]); // move current root to last
        heapSize--; // the last element was sorted, size of heap minus 1
        int x = heapSize;
        
        arrToHeap(arr2, 0);
    }

    //debugArr(arr2, ARRAYSIZE);

    endTime = clock();
    sortTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Heap sort: %lf sec\n", sortTime);

    /* the end */
    destroyArr(arr1);
    destroyArr(arr2);

	return 0;
}


