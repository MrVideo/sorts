// Include guard
#ifndef sorts_h
    #define sorts_h

// Support functions
void swap(int *a, int *b);
void printArray(int *array, int len);
void fillArray(int *array, int len, int max);
int maxSearch(int *array, int len);

// Counting sort
void countingSort(int *array, int len);

// Heap sort
void heapify(int *array, int n, int len);
void buildMaxHeap(int *array, int len);
void heapSort(int *array, int len);

// Insertion sort
void insertionSort(int *array, int len);

// Merge sort
void mergeSort(int *array, int start, int end);
void merge(int *array, int start, int mid, int end);

// Quick sort
void quickSort(int *array, int start, int end);
int partition(int *array, int start, int end);

#endif