//! COUNTING SORT
//* Time complexity: Theta(n + k)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // Array size
#define MAX 1000 // Max random integer

//* Support function
int maxSearch(int *array, int size);

int main() {
    int array[N];

    srand(time(NULL)); // Random int generation

    for(int i = 0; i<N; i++)
        array[i] = rand() % MAX;

    printf("Before:\n"); // Prints array in random order
    for(int i = 0; i<N; i++)
        printf("%d\t", array[i]);

    //! SORTING START

    int max = maxSearch(array, N);                  // The algorithm is better used when we know that
    int sorted[N], count[max + 1];                  // the input array contains only numbers 0 <= i <= max
                                                    // so this helper function finds the highest element in
    for(int i = 0; i < max + 1; i++)                // the array. Then we initialize the count array to 0.
        count[i] = 0;
    
    for(int i = 0; i < N; i++)                      // We add 1 to each element in count where the index
        count[array[i]]++;                          // is equal to the element in the input array.

    for(int i = 1; i <= max + 1; i++)               // We add each element in count to the next one
        count[i] = count[i] + count[i - 1];         // to find how many numbers <= i there are in array.
    
    for(int i = 0; i < N; i++) {                    // Since count[i] stores how many numbers <= i there
        sorted[count[array[i]] - 1] = array[i];     // are in array, count[array[i]] - 1 is the index in which
        count[array[i]]--;                          // array[i] needs to be placed. Each time we sort an element,
    }                                               // we decrease the corresponding cell in count by one.

    //! SORTING END

    for(int i = 0; i < N; i++)                      // Now we can copy the sorted array onto the original.
        array[i] = sorted[i];                       // We need the sorted array to keep the algorithm stable.
    
    printf("\nAfter:\n"); // Prints the ordered array
    for(int i = 0; i<N; i++)
        printf("%d\t", array[i]);

    return 0;
}

//* Support function
int maxSearch(int *array, int size) {
    int max = array[0];

    for(int i = 0; i < size; i++) {
        if(array[i] > max)
            max = array[i];
    }

    return max;
}