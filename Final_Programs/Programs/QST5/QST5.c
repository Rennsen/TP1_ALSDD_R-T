#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./Library/QST5_Lib.h"

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
        factorizeNumber(number, initialListLL);
        current = next(current);
    }

    printf("this is the first integer list :");
    printList(initialListLL);
    printf("The co-prime numbers pairs :  ");
    printCoprimePairs(initialListLL, n);

    // Destroy linked lists to free memory
    destroyLinkedList(initialListLL);
    destroyLinkedList(linkedListPrimes);

    return 0;
}
