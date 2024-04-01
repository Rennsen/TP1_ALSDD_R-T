#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedListLib.h"



int main()
{
    int n;

    printf("Enter the upper bound (n): ");
    scanf("%d", &n);

    // Create and display initial list using linked list
    LinkedList *initialListLL = createLinkedList();
    createInitialListLinkedList(initialListLL, n);
    printf("Initial List (Linked List): ");
    cell *current = initialListLL->head;
    printList(initialListLL->head);
    // while (current != NULL)
    // {
    //     printf("%d ", value(current));
    //     current = next(current);
    // }
    printf("\n");

    // Generate primes using linked list
    LinkedList *linkedListPrimes = createLinkedList();
    generatePrimesLinkedList(linkedListPrimes, n);
    printf("Primes using Linked List: ");
    current = linkedListPrimes->head;
    printListLogic(linkedListPrimes->head);
    // while (current != NULL)
    // {
    //     if (!current->deleted)
    //     {
    //         printf("%d ", value(current));
    //     }
    //     current = next(current);
    // }
    printf("\n");

    destroyLinkedList(linkedListPrimes);
    return 0;
}