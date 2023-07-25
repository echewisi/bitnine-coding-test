#include <stdio.h>

#define MAX_N 100 // Maximum value of n for memoization
int memo[MAX_N + 1] = {0}; // Array to store memoized values

// Function to calculate F(n) using memoization
int fibonacciMemoization(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    if (memo[n] == 0) {
        memo[n] = fibonacciMemoization(n - 3) + fibonacciMemoization(n - 2);
    }
    
    return memo[n];
}

int main() {
    int n = 10; // Change this to the desired value of n
    int result = fibonacciMemoization(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}
