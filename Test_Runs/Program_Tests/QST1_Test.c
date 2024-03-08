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

int main()
{
    int n;

    // Get user input for the upper limit
    printf("Enter the upper limit (n): ");
    scanf("%d", &n);

    // Call the searchPrimesRecursive function
    printf("Prime numbers up to %d: ", n);
    searchPrimesRecursive(n, 2);

    printf("\n");

    return 0;
}