#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QST5_Lib.h"

int main()
{
    int n;

    printf("Enter an upper bound: ");
    scanf("%d", &n);

    // Create and display initial list using linked list
    LinkedList *primesList = createLinkedList();
    // Generate primes using linked list
    generatePrimesLinkedList(primesList, n);

    LinkedList *initialListLL = createLinkedList();
    createInitialListLinkedList(initialListLL, n);

    // Check co-prime numbers in the list
    printf("Co-prime numbers in the list:\n");
    cell *current = initialListLL->head;
    while (current != NULL)
    {
        cell *other = current->next;
        while (other != NULL)
        {
            if (areCoPrime(current->value, other->value))
            {
                printf("| (%d,%d) |", current->value, other->value);
            }
            other = other->next;
        }
        current = current->next;
    }
}
