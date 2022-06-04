//! INSERTION SORT
//* Best case time complexity: Theta(n)
//* Worst case time complexity: Theta(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // Array size
#define MAX 1000 // Max random integer

int main() {
    int array[N];

    srand(time(NULL)); // Random int generation

    for(int i = 0; i<N; i++)
        array[i] = rand() % MAX;

    printf("Before:\n"); // Prints array in random order
    for(int i = 0; i<100; i++)
        printf("%d\t", array[i]);

    //! SORTING START

    for(int i = 1; i < N; i++) { 
        int j = i - 1;
        if(array[j] > array[i]) {                       // Check if the item to the left is greater than
            while(j >= 0 && array[j] > array[j+1]) {    // the one on the right. If it is, then
                int tmp = array[j];                     // move the item to the right one position to
                array[j] = array[j+1];                  // the left. Check for every item in the array
                array[j+1] = tmp;                       // and then move on.
                j--;
            }
        }
    }

    //! SORTING END
    
    printf("\nAfter:\n"); // Prints the ordered array
    for(int i = 0; i<N; i++)
        printf("%d\t", array[i]);

    return 0;
}