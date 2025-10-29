#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random matrix
void generateRandomMatrix(int matrix[][1000], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;  // Random values 0–99
        }
    }
}

// Standard matrix multiplication
void multiplyMatrices(int a[][1000], int b[][1000], int result[][1000], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter size of square matrix (n): ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Please enter n >= 2\n");
        return 1;
    }

    // Large static allocation with max size (safe upper bound)
    static int a[1000][1000], b[1000][1000], result[1000][1000];

    // Generate random matrices
    generateRandomMatrix(a, n);
    generateRandomMatrix(b, n);

    clock_t start = clock();

    // Run multiplication 1000 times
    for (int i = 0; i < 1000; i++) {
        multiplyMatrices(a, b, result, n);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
    printf("TIME TAKEN TO MULTIPLY %d x %d MATRICES (average over 1000 runs): %f seconds\n", 
            n, n, time_taken);

    printf("Time Complexity: O(n^3)\n");

    return 0;
}
