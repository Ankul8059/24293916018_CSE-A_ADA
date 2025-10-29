#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 10) {
        printf("Please enter a value greater than 10\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    generateRandomArray(arr, n);

    clock_t start = clock();

    for (int i = 0; i < 1000; i++) {
        bubbleSort(arr, n);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
    printf("TIME TAKEN TO SORT %d ELEMENTS (average over 1000 runs): %f seconds\n", n, time_taken);

    free(arr);

    return 0;
}
