//! HEAP SORT
//* Best case time complexity: O(n*log(n))
//* Worst case time complexity: O(n*log(n))

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_functions.h"

#define N 100 // Array size
#define MAX 1000 // Max random integer

void heapify(int *array, int n, int size);
void buildMaxHeap(int *array, int size);
void heapSort(int *array, int size);

int main() {
    int a[N];
    fillArray(a, N, MAX);
    
    printf("Before:\n");
    printArray(a, N);

    heapSort(a, N);

    printf("\nAfter:\n");
    printArray(a, N);

    return 0;
}

void heapify(int *array, int n, int size) {         // Check if the node passed is bigger
    int left = 2 * n;                               // than its child nodes. If not, swap
    int right = 2 * n + 1;                          // the biggest node with the node
    int max = n;                                    // passed to the function and recheck

    if(left < size && array[left] > array[max])
        max = left;
    if(right < size && array[right] > array[max])
        max = right;

    if(max != n) {
        swap(&array[max], &array[n]);
        heapify(array, max, size);
    }
}

void buildMaxHeap(int *array, int size) {           // Builds the max heap
    for(int i = size / 2; i >= 0; i--)              //* Only runs once
        heapify(array, i, size);
}

void heapSort(int *array, int size) {               // This function builds the max heap and
    buildMaxHeap(array, size);                      // then swaps the biggest item, which is
    for (int i = size - 1; i >= 0; i--) {           // the root of the tree, with the last item,
        swap(&array[0], &array[i]);                 // sorting it, to then pass the array to heapify
        heapify(array, 0, i);                       // again, ignoring the last item, which is
    }                                               // in the correct spot.
}
