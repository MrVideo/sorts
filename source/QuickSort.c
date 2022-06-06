//! QUICK SORT
//* Best case time complexity: Theta(n*log(n))
//* Worst case time complexity: Theta(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_functions.h"

#define N 100 // Array size
#define MAX 1000 // Max random integer

void quickSort(int *array, int start, int end);
int partition(int *array, int start, int end);

int main() {
    int array[N];
    fillArray(array, N, MAX);

    printf("Before:\n"); // Prints array in random order
    printArray(array, N);


    //! SORTING START

    quickSort(array, 0, N - 1);

    //! SORTING END
    
    printf("\nAfter:\n"); // Prints the ordered array
    printArray(array, N);

    return 0;
}

//! SORTING START

int partition(int *array, int start, int end) {         // This function essentially divides the array
    int pivot = array[end];                             // in half, putting all elements <= pivot to the
    int left = start - 1;                               // left of the array and all the elements >= pivot
                                                        // to the right of the array.
    for(int i = start; i < end; i++) {
        if(array[i] <= pivot) {
            left++;
            swap(&array[left], &array[i]);
        }
    }

    swap(&array[left + 1], &array[end]);                // Once the process is done, the pivot is swapped
                                                        // in its middle place and is returned to the main
    return left + 1;                                    // quickSort function
}

void quickSort(int *array, int start, int end) {        // The quickSort function uses the partition function
    if(start < end) {                                   // to get the pivot in the array and sort as explained
        int pivot = partition(array, start, end);       // above the two halves of the array.
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

//! SORTING END