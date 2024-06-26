#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./Library/DynamicArrayLib.h"

// Main
int main()
{
    int n;

    printf("Enter the upper bound (n): ");
    scanf("%d", &n);

    // Create and display initial list using dynamic array
    DynArrMachine *initialList;
    initDynArray(&initialList, n - 1);
    createInitialListDynamicArray(initialList, n);
    printf("Initial List (Dynamic Array): ");
    printDynamicArray(initialList);
    printf("\n");

    // Generate primes using dynamic array
    DynArrMachine *dynamicPrimes;
    initDynArray(&dynamicPrimes, 10);
    generatePrimesDynamicArray(dynamicPrimes, n);
    printf("Primes using Dynamic Array: ");
    printDynamicArray(dynamicPrimes);
    printf("\n");
    freeDynArray(dynamicPrimes);
    return 0;
}