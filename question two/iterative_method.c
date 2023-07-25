#include <stdio.h>

// Function to calculate F(n) iteratively
int fibonacciIterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int f0 = 0;
    int f1 = 1;
    int f2 = 2;
    int fn;
    
    for (int i = 3; i <= n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = f2;
        f2 = fn;
    }
    
    return fn;
}

int main() {
    int n = 10; // Change this to the desired value of n
    int result = fibonacciIterative(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}
