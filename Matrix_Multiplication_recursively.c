#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

// Function to add two matrices
void addMatrix(int n, int A[][MAX], int B[][MAX], int C[][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Recursive matrix multiplication (classic divide & conquer)
void multiplyRecursive(int n, int A[][MAX], int B[][MAX], int C[][MAX]) {
    if (n == 1) { // Base case
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;

    // Temporary submatrices
    static int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    static int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    static int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    static int temp1[MAX][MAX], temp2[MAX][MAX];

    // Initialize results to 0
    for (int i = 0; i < half; i++)
        for (int j = 0; j < half; j++) {
            C11[i][j] = C12[i][j] = C21[i][j] = C22[i][j] = 0;
        }

    // Split matrices A and B
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // C11 = A11*B11 + A12*B21
    multiplyRecursive(half, A11, B11, temp1);
    multiplyRecursive(half, A12, B21, temp2);
    addMatrix(half, temp1, temp2, C11);

    // C12 = A11*B12 + A12*B22
    multiplyRecursive(half, A11, B12, temp1);
    multiplyRecursive(half, A12, B22, temp2);
    addMatrix(half, temp1, temp2, C12);

    // C21 = A21*B11 + A22*B21
    multiplyRecursive(half, A21, B11, temp1);
    multiplyRecursive(half, A22, B21, temp2);
    addMatrix(half, temp1, temp2, C21);

    // C22 = A21*B12 + A22*B22
    multiplyRecursive(half, A21, B12, temp1);
    multiplyRecursive(half, A22, B22, temp2);
    addMatrix(half, temp1, temp2, C22);

    // Combine into final matrix C
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

// Function to generate a random matrix
void generateRandomMatrix(int matrix[][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = rand() % 100;  // Random values 0–99
}

int main() {
    int n;
    printf("Enter size of square matrix (power of 2): ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Please enter n >= 2\n");
        return 1;
    }

    static int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];

    generateRandomMatrix(a, n);
    generateRandomMatrix(b, n);

    clock_t start = clock();

    // Run recursive multiplication 100 times (less than 1000 to avoid slow runtime)
    for (int i = 0; i < 100; i++) {
        multiplyRecursive(n, a, b, result);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 100.0;
    printf("TIME TAKEN TO MULTIPLY %d x %d MATRICES (average over 100 runs): %f seconds\n",
           n, n, time_taken);

    printf("Time Complexity Recurrence: T(n) = 8T(n/2) + O(n^2) = O(n^3)\n");

    return 0;
}
