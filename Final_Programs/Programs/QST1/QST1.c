#include <stdlib.h>
#include <stdio.h>
#include "./Library/QST1_Lib.h"

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