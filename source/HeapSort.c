//! HEAP SORT
//* Best case time complexity: O(n*log(n))
//* Worst case time complexity: O(n*log(n))

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Array size
#define MAX 20 // Max random integer

void heapify(int *array, int node, int size);
void heapSort(int *array, int size);
void swap(int *a, int *b); //* Support function

int main() {
    int array[N];

    srand(time(NULL)); // Random int generation

    for(int i = 0; i<N; i++)
        array[i] = rand() % MAX;

    printf("Before:\n"); // Prints array in random order
    for(int i = 0; i<N; i++)
        printf("%d\t", array[i]);

    //! SORTING START

    heapSort(array, N);

    //! SORTING END
    
    printf("\nAfter:\n"); // Prints the ordered array
    for(int i = 0; i<N; i++)
        printf("%d\t", array[i]);

    return 0;
}

//* Support function
void swap(int *a, int *b) { // Swaps the values of *a* and *b*
    int temp = *a;
    *a = *b;
    *b = temp;
}

//! SORTING START
void heapify(int *array, int node, int size) {      // This function takes a node index and the tree size
    int max = node;                                 // to create a max heap, where the parent element is
    int l = 2 * node + 1;                           // larger than all of its child elements.
    int r = 2 * node + 2;

    if(l < size && array[l] > array[max])
        max = l;
    if(r < size && array[r] > array[max])
        max = r;

    if(max != node) {                               // If the tree is not a max heap already, the node
        swap(&array[max], &array[node]);            // passed to the function gets swapped for the 
        heapify(array, max, size);                  // largest one and the process restarts.
    }
}

void heapSort(int *array, int size) {               // This functions builds a max heap for each node
    for(int i = size / 2 - 1; i >= 0; i--)          // in the tree and then sorts the array passed to
        heapify(array, i, size);                    // it 

    for(int i = size - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, 0, i);
    }
}

//! SORTING END