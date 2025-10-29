#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random array
void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

// Function to perform linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
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

    generateRandomArray(arr, n);

    clock_t start = clock();

    // Loop 1000 times to get a stable average time
    for (int i = 0; i < 1000; i++) {
        // Randomly choose an element from the array to search for
        int element_to_search = arr[rand() % n];
        linearSearch(arr, n, element_to_search);
    }

    clock_t end = clock();

    // Calculate the average time taken per search
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("TIME TAKEN TO SEARCH %d ELEMENTS (average of 1000 searches): %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}
