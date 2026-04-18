#include <stdio.h>

// Function to calculate Fibonacci using recursion
int fib(int n)
{
    // Base case: fib(0) = 0
    if (n == 0)
        return 0;

    // Base case: fib(1) = 1
    if (n == 1)
        return 1;

    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    // Ask user for input
    printf("Enter the value of n: ");

    // Read input value
    scanf("%d", &n);

    // Check for invalid input (negative numbers)
    if (n < 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    // Print the nth Fibonacci number
    printf("Fibonacci term is: %d\n", fib(n));

    return 0; // End of program
}