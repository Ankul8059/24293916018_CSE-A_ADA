#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1024  // Ensure large enough for splitting

// Function to add two matrices
void addMatrix(int n, int A[][MAX], int B[][MAX], int C[][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtractMatrix(int n, int A[][MAX], int B[][MAX], int C[][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen's recursive multiplication
void multiplyStrassen(int n, int A[][MAX], int B[][MAX], int C[][MAX]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;

    static int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    static int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    static int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    static int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX], 
               M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    static int temp1[MAX][MAX], temp2[MAX][MAX];

    // Split matrices
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

    // M1 = (A11 + A22)*(B11 + B22)
    addMatrix(half, A11, A22, temp1);
    addMatrix(half, B11, B22, temp2);
    multiplyStrassen(half, temp1, temp2, M1);

    // M2 = (A21 + A22)*B11
    addMatrix(half, A21, A22, temp1);
    multiplyStrassen(half, temp1, B11, M2);

    // M3 = A11*(B12 - B22)
    subtractMatrix(half, B12, B22, temp1);
    multiplyStrassen(half, A11, temp1, M3);

    // M4 = A22*(B21 - B11)
    subtractMatrix(half, B21, B11, temp1);
    multiplyStrassen(half, A22, temp1, M4);

    // M5 = (A11 + A12)*B22
    addMatrix(half, A11, A12, temp1);
    multiplyStrassen(half, temp1, B22, M5);

    // M6 = (A21 - A11)*(B11 + B12)
    subtractMatrix(half, A21, A11, temp1);
    addMatrix(half, B11, B12, temp2);
    multiplyStrassen(half, temp1, temp2, M6);

    // M7 = (A12 - A22)*(B21 + B22)
    subtractMatrix(half, A12, A22, temp1);
    addMatrix(half, B21, B22, temp2);
    multiplyStrassen(half, temp1, temp2, M7);

    // C11 = M1 + M4 - M5 + M7
    addMatrix(half, M1, M4, temp1);
    subtractMatrix(half, temp1, M5, temp2);
    addMatrix(half, temp2, M7, C11);

    // C12 = M3 + M5
    addMatrix(half, M3, M5, C12);

    // C21 = M2 + M4
    addMatrix(half, M2, M4, C21);

    // C22 = M1 - M2 + M3 + M6
    subtractMatrix(half, M1, M2, temp1);
    addMatrix(half, temp1, M3, temp2);
    addMatrix(half, temp2, M6, C22);

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

// Function to generate random matrix
void generateRandomMatrix(int M[][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = rand() % 100;
}

int main() {
    int n;
    printf("Enter size of square matrix (power of 2): ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Please enter n >= 2\n");
        return 1;
    }

    static int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    generateRandomMatrix(A, n);
    generateRandomMatrix(B, n);

    clock_t start = clock();
    for (int i = 0; i < 100; i++)
        multiplyStrassen(n, A, B, C);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 100.0;
    printf("TIME TAKEN TO MULTIPLY %d x %d MATRICES (Strassen, avg over 100 runs): %f seconds\n", n, n, time_taken);
    printf("Time Complexity Recurrence: T(n) = 7T(n/2) + O(n^2) = O(n^2.81)\n");

    return 0;
}
