//! MERGE SORT
//* Best case time complexity: Omega(n*log(n))
//* Worst case time complexity: O(n*log(n))

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_functions.h"

#define N 100 // Array size
#define MAX 1000 // Max random integer

void mergeSort(int *array, int start, int end);
void merge(int *array, int start, int mid, int end);

int main() {
    int array[N];
    fillArray(array, N, MAX);

    printf("Before:\n"); // Prints array in random order
    printArray(array, N);

    //! SORTING START

    mergeSort(array, 0, N - 1);

    //! SORTING END
    
    printf("\nAfter:\n"); // Prints the ordered array
    printArray(array, N);

    return 0;
}

//! SORTING START

void mergeSort(int *array, int start, int end) {            // Divides the array in half until each array contains just one
    if(start < end) {                                       // element, then starts merging the halves in order
        int mid = (start + end) / 2;

        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);

        merge(array, start, mid, end);
    }
}

void merge(int *array, int start, int mid, int end) {
    int i, j, k;
    int left = mid - start + 1;
    int right = end - mid;
    int L[left], R[right];

    for(i = 0; i < left; i++)           // Copies the first half of the elements into the left array
        L[i] = array[start + i];
    for(j = 0; j < right; j++)          // Copies the second half of the elements into the right array
        R[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;

    while(i < left && j < right) {      // Merges the two arrays in order
        if(L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < left) {                   // Copies the rest of the left array into the array
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < right) {                  // Copies the rest of the right array into the array
        array[k] = R[j];
        j++;
        k++;
    }
}

//! SORTING END