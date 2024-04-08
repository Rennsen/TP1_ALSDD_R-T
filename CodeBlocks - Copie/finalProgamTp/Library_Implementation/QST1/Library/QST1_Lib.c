#include "QST1_Lib.h"  // Include the header file for the library
#include <stdlib.h>     // Include standard library for malloc and free functions
#include <stdio.h>      // Include standard I/O functions

// Function that checks whether a number is prime or not
int isPrime(int num, int divisor)
{
    // Base case: if the square of the divisor is greater than the number, it's a prime number
    if (divisor * divisor > num)
    {
        return 1; // It's a prime number
    }

    // If the number is divisible by the current divisor, it's not a prime number
    if (num % divisor == 0)
    {
        return 0; // It's not a prime number
    }

    // Recursively check for divisibility with the next divisor
    return isPrime(num, divisor + 1);
}

// Function to search for prime numbers using recursion
void searchPrimesRecursive(int n, int current)
{
    // Base case: if the current number exceeds the upper limit, stop recursion
    if (current <= n)
    {
        // Check if the current number is prime
        if (isPrime(current, 2))
        {
            printf("| %d |", current); // Print the prime number
        }

        // Continue the recursion with the next number
        searchPrimesRecursive(n, current + 1);
    }
}
