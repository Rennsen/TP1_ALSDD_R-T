#include "QST1_Lib.h"
#include <stdlib.h>
#include <stdio.h>

// function that checks whether a number is prime or not
int isPrime(int num, int divisor)
{
    if (divisor * divisor > num)
    {
        return 1; // It's a prime number
    }

    if (num % divisor == 0)
    {
        return 0; // It's not a prime number
    }

    return isPrime(num, divisor + 1);
}

// Function to search for prime numbers using recursion
void searchPrimesRecursive(int n, int current)
{
    if (current <= n)
    {
        if (isPrime(current, 2))
        {
            printf("| %d |", current);
        }

        searchPrimesRecursive(n, current + 1);
    }
}