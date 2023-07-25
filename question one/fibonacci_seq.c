#include <stdio.h>
#include <stdlib.h>

// Define arithmetic operations enum
typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV
} TypeTag;

// Define the Node structure
typedef struct Node {
    TypeTag type;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new Node with the given operator and operands
Node* makeFunc(TypeTag type, int left_value, int right_value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->value = 0;
    newNode->left = NULL;
    newNode->right = NULL;

    if (type == ADD || type == SUB || type == MUL || type == DIV) {
        newNode->left = makeFunc(0, left_value, 0);
        newNode->right = makeFunc(0, right_value, 0);
    } else {
        newNode->value = left_value;
    }

    return newNode;
}

// Function to calculate the result of the expression represented by the given Node
int calc(Node* node) {
    if (node->type == ADD) {
        return calc(node->left) + calc(node->right);
    } else if (node->type == SUB) {
        return calc(node->left) - calc(node->right);
    } else if (node->type == MUL) {
        return calc(node->left) * calc(node->right);
    } else if (node->type == DIV) {
        return calc(node->left) / calc(node->right);
    } else {
        return node->value;
    }
}

// Function to calculate the nth Fibonacci number using dynamic programming
int fibonacci(int n) {
    int* fib = (int*)malloc((n + 1) * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int result = fib[n];
    free(fib);
    return result;
}

int main() {
    // Example usage
    Node* add = makeFunc(ADD, 10, 6);
    Node* mul = makeFunc(MUL, 5, 4);
    Node* sub = makeFunc(SUB, calc(mul), calc(add)); 
    Node* fibo = makeFunc(MUL, fibonacci(calc(sub)), 1); 

    printf("add: %d\n", calc(add));  // Output: add: 16
    printf("mul: %d\n", calc(mul));  // Output: mul: 20
    printf("sub: %d\n", calc(sub));  // Output: sub: 4
    printf("fibo: %d\n", calc(fibo)); // Output: fibo: 3

    // Free allocated memory
    free(add->left);
    free(add->right);
    free(add);
    free(mul->left);
    free(mul->right);
    free(mul);
    free(sub->left);
    free(sub->right);
    free(sub);
    free(fibo->left); // Free the nodes created for the expression tree
    free(fibo->right);
    free(fibo);

    return 0;
}
