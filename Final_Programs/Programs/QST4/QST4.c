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
    current = initialListLL->head;
    while (current != NULL)
    {
        printf("%d: ", value(current));
        LinkedList *sublist = current->sublist;
        cell *sublist_current = sublist->head;
        while (sublist_current != NULL)
        {
            int count = 0;
            int prime = value(sublist_current);
            while (sublist_current != NULL && value(sublist_current) == prime)
            {
                count++;
                sublist_current = next(sublist_current);
            }
            printf("%d", prime);
            if (count > 1)
            {
                printf("^(%d)", count);
            }
            if (sublist_current != NULL)
            {
                printf(" * ");
            }
        }
        printf("\n");
        current = next(current);
    }

    // Free memory
    destroyLinkedList(initialListLL);
    destroyLinkedList(linkedListPrimes);

    return 0;
}
