#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Support functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *array, int len) {
    for(int i = 0; i < len; i++)
        printf("%d\t", array[i]);
}

void fillArray(int*array, int len, int max) {
    srand(time(NULL));
    for(int i = 0; i < len; i++)
        array[i] = rand() % max;
}

int maxSearch(int *array, int len) {
    int max = array[0];

    for(int i = 0; i < len; i++) {
        if(array[i] > max)
            max = array[i];
    }

    return max;
}

// Counting sort
void countingSort(int *array, int len) {
    int max = maxSearch(array, len);
    int sorted[len], count[max + 1];

    for(int i = 0; i < max + 1; i++)
        count[i] = 0;
    
    for(int i = 0; i < len; i++)
        count[array[i]]++;

    for(int i = 1; i <= max + 1; i++)
        count[i] = count[i] + count[i - 1];
    
    for(int i = 0; i < len; i++) {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for(int i = 0; i < len; i++)
        array[i] = sorted[i];
}

// Heap sort
void heapify(int *array, int n, int len) {
    int left = 2 * n;
    int right = 2 * n + 1;
    int max = n;

    if(left < len && array[left] > array[max])
        max = left;
    if(right < len && array[right] > array[max])
        max = right;

    if(max != n) {
        swap(&array[max], &array[n]);
        heapify(array, max, len);
    }
}

void buildMaxHeap(int *array, int len) {
    for(int i = len / 2; i >= 0; i--)
        heapify(array, i, len);
}

void heapSort(int *array, int len) {
    buildMaxHeap(array, len);
    for (int i = len - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, 0, i);
    }
}

// Insertion sort
void insertionSort(int *array, int len) {
    for(int i = 1; i < len; i++) { 
        int j = i - 1;
        if(array[j] > array[i]) {
            while(j >= 0 && array[j] > array[j+1]) {
                swap(&array[j], &array[j + 1]);
                j--;
            }
        }
    }
}

// Merge sort
void mergeSort(int *array, int start, int end) {
    if(start < end) {
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

    for(i = 0; i < left; i++)
        L[i] = array[start + i];
    for(j = 0; j < right; j++)
        R[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;

    while(i < left && j < right) {
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

    while(i < left) {
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < right) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Quick sort
int partition(int *array, int start, int end) {
    int pivot = array[end];
    int left = start - 1;

    for(int i = start; i < end; i++) {
        if(array[i] <= pivot) {
            left++;
            swap(&array[left], &array[i]);
        }
    }

    swap(&array[left + 1], &array[end]);

    return left + 1;
}

void quickSort(int *array, int start, int end) {
    if(start < end) {
        int pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}