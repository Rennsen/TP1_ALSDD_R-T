#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QST3_Lib.h"




int main()
{
    int n, range;

    printf("Enter the upper bound (n): ");
    scanf("%d", &n);
    printf("Enter the range: ");
    scanf("%d", &range);

    // Create and display initial list using linked list
    LinkedList *primesList = createLinkedList();
    // Generate primes using linked list
    generatePrimesLinkedList(primesList, n);
    printf("Prime numbers list: ");
    printListLogic(primesList->head);
    // while (current != NULL)
    // {
    //     if (!current->deleted)
    //     {
    //         printf("%d ", value(current));
    //     }
    //     current = next(current);
    // }
    printf("\n");
    // Index by range
    indexByRange(primesList, range);

    // Display by range
    printf("Prime Numbers by Range (%d): |", range);
    displayByRange(primesList, range);

    destroyLinkedList(primesList);
    return 0;
}