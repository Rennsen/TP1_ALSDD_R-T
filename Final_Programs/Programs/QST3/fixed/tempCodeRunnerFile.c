#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QST3_Lib.h"

int main()
{
    int n, range;

    printf("Enter the upper bound (n): ");
    scanf("%d", &n);
    // printf("Enter the range: ");
    // scanf("%d", &range);
    // we can allow the 

    // Create and display initial list using linked list
    LinkedList *primesList = createLinkedList();
    // Generate primes using linked list
    generatePrimesLinkedList(primesList, n);
    printf("Prime numbers list: ");
    printListLogic(primesList->head);
    printf("\n");

    // Index by range
    // we can ask the user for a range but i fixed it for the value 10 
    indexByRange(primesList, 10);
    bool valid = true;
    // display by range 
    int min, max;
    printf("Please enter the lower bound: ");
    scanf("%d", &min);
    printf("Please enter the upper bound: ");
    scanf("%d", &max);

       if (min > max)
    {
        printf("Error: min value is larger than max value.\n");
         valid = false;
    }

    if (min < 0 || max < 0)
    {
        printf("Error: Values cannot be negative.\n");
        valid = false;
    }

    if(valid){
    printf("Prime Numbers between %d and %d : ", min, max);
    displaySublist(primesList, min , max);
    }

    destroyLinkedList(primesList);
    return 0;
}