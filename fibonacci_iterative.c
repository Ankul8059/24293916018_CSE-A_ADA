#include <stdio.h>
#include <time.h>

void fib_iterative(int n) {
    long long a = 0, b = 1, next;

    printf("Iterative Fibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", a);
        next = a + b;
        a = b;
        b = next;
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    clock_t start, end;
    double time_taken;

    start = clock();
    fib_iterative(n);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken: %f sec\n", time_taken);

    return 0;
}
