#include <stdio.h>
#include <time.h>

void fib_bottom_up(int n) {
    long long fib_array[1000]; // Array to store Fibonacci numbers

    // Base cases
    if (n >= 1) fib_array[0] = 0;
    if (n >= 2) fib_array[1] = 1;

    // Fill the array iteratively
    for (int i = 2; i < n; i++) {
        fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
    }

    // Print the sequence
    printf("Bottom-Up Fibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib_array[i]);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    clock_t start, end;
    double time_taken;

    start = clock();
    fib_bottom_up(n);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken: %f sec\n", time_taken);

    return 0;
}
