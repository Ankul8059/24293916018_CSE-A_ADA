#include <stdio.h>
#include <time.h>

long long fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    clock_t start, end;
    double time_taken;

    start = clock();
    printf("Recursive Fibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib_recursive(i));
    }
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken: %f sec\n", time_taken);

    return 0;
}
