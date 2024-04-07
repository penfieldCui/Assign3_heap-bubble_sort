// Sorting
// 
// DS&A assignment 3 - Zongping Cui
#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARRAYSIZE 20000
#define DISPLAYSIZE 63

#define DEBUG

static int heapSize = ARRAYSIZE;

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

    int size = 0;

#ifdef DEBUG

    int* arr = NewArrayWithRandom(DISPLAYSIZE);
    int arr1[DISPLAYSIZE];
    int arr2[DISPLAYSIZE];

    size = DISPLAYSIZE;

    for (int i = 0; i < size; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];  //identical value 
    }
    heapSize = DISPLAYSIZE;

#else
    int* arr1 = NewArrayWithRandom(ARRAYSIZE);
    int* arr2 = NewArrayWithRandom(ARRAYSIZE);

    size = ARRAYSIZE;

    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];  //identical value 
    }

#endif // DEBUG


    

    /** bubble **/
    // N^2
    clock_t startTime = clock();
    bubbleSort(arr1, size);

    clock_t endTime = clock();


    double sortTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("Bubble sort: %lf sec\n", sortTime);


    /** heap sort **/
    startTime = clock();

    //to heap   - N*logN
    for (int i = size - 1; i >= 0; i--) {
        arrToHeap(arr2, i); // start at root
    }

#ifdef DEBUG
    display(arr2, DISPLAYSIZE);
#endif // DEBUG

    //N*logN
    for (int i = size - 1; i > 0; i--) {
        swap(&arr2[0], &arr2[i]); // move current root to last
        heapSize--; // the last element was sorted, size of heap minus 1
        
        arrToHeap(arr2, 0);
    }

    //debugArr(arr2, ARRAYSIZE);

    endTime = clock();
    sortTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Heap sort: %lf sec\n", sortTime);

   

    /* the end */
#ifdef DEBUG
    display(arr2, DISPLAYSIZE);
    destroyArr(arr);
#else
    destroyArr(arr1);
    destroyArr(arr2);
    
#endif

	return 0;
}


