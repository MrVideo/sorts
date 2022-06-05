//! QUICK SORT
//* Best case time complexity: Theta(n*log(n))
//* Worst case time complexity: Theta(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // Array size
#define MAX 1000 // Max random integer

//* Support function
void swap(int *a, int *b);

void quickSort(int *array, int start, int end);
int partition(int *array, int start, int end);

int main() {
    int array[N];

    srand(time(NULL)); // Random int generation

    for(int i = 0; i<N; i++)
        array[i] = rand() % MAX;

    printf("Before:\n"); // Prints array in random order
    for(int i = 0; i<N; i++)
        printf("%d\t", array[i]);

    //! SORTING START

    quickSort(array, 0, N - 1);

    //! SORTING END
    
    printf("\nAfter:\n"); // Prints the ordered array
    for(int i = 0; i<N; i++)
        printf("%d\t", array[i]);

    return 0;
}

//* Support function
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
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