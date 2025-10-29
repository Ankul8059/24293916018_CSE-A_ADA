#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random sorted array
void generateRandomSortedArray(int arr[], int n) {
    srand(time(NULL));
    arr[0] = rand() % 10;   // start with a small number
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i-1] + (rand() % 10); // keep increasing to ensure sorted order
    }
}

// Function to perform binary search
int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            // Dummy loop to increase execution time
            for (volatile int j = 0; j < 1000; j++);
            return mid; // return index if found
        } else if (arr[mid] < x) {
            for (volatile int j = 0; j < 1000; j++);
            low = mid + 1;
        } else {
            for (volatile int j = 0; j < 1000; j++);
            high = mid - 1;
        }
    }
    return -1; // not found
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 5000) {
        printf("Please enter a value greater than or equal to 5000\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    generateRandomSortedArray(arr, n);

    clock_t start = clock();

    // Loop 1000 times to get a stable average time
    for (int i = 0; i < 1000; i++) {
        int element_to_search = arr[rand() % n]; // pick random element
        binarySearch(arr, n, element_to_search);
    }

    clock_t end = clock();

    // Calculate the average time taken per search
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("TIME TAKEN TO SEARCH %d ELEMENTS (average of 1000 searches): %f seconds\n",
           n, time_taken);

    free(arr);
    return 0;
}
