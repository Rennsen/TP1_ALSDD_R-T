#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QST4_Lib.h"



int main()
{
    int n;

    printf("Enter the upper bound (n): ");
    scanf("%d", &n);

    // Create and display initial list using linked list
    LinkedList *initialListLL = createLinkedList();
    createInitialListLinkedList(initialListLL, n);

    // Generate primes using linked list
    LinkedList *linkedListPrimes = createLinkedList();
    generatePrimesLinkedList(linkedListPrimes, n);

    // Factorization and storing as sublists
    cell *current = initialListLL->head;

    while (current != NULL)
    {
        int number = value(current);
        factorizeNumber(number, linkedListPrimes, initialListLL);
        current = next(current);
    }

    // Displaying factorization
    printf("Prime Factorization for each number:\n");
    printFactorisation(initialListLL->head);

    // Free memory
    destroyLinkedList(initialListLL);
    destroyLinkedList(linkedListPrimes);

    return 0;
}
