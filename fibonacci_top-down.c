#include <stdio.h>
#include <time.h>

long long fib_array[1000]; // Memoization array

long long fib_dp(int n) {
    if (n <= 1)
        return n;
    if (fib_array[n] != -1)
        return fib_array[n];
    fib_array[n] = fib_dp(n - 1) + fib_dp(n - 2);
    return fib_array[n];
}

void fib_dp_print(int n) {
    printf("DP Top-Down Fibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib_dp(i));
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    // Initialize memoization array with -1
    for (int i = 0; i <= n; i++)
        fib_array[i] = -1;

    clock_t start, end;
    double time_taken;

    start = clock();
    fib_dp_print(n);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken: %f sec\n", time_taken);

    return 0;
}
